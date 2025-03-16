/**
 * @file
 *
 * Traversal: TransformVariableInit
 * UID      : TVI
 *
 * This traversal transforms variable initializations into regular assignments.
 * - For local variables, initializations are turned into assignments placed after the declaration
 * - For global variables, initializations are collected in a top-level 'init' function
 * - Array initializations are handled by creating appropriate loops
 */

#include "user/genericstack/generic_stack.h"

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include <stdlib.h>

#include <palm/str.h>

#include <string.h>

// Helper function to create a temporary variable name
static char *create_temp_var_name(struct data_tvi *data)
{
    char temp_name[32];
    snprintf(temp_name, sizeof(temp_name), "tmp_%d", data->temp_counter++);
    return strdup(temp_name);
}

void CCNfreeWrapper(void *ptr) {
    CCNfree((struct ccn_node *)ptr);
}

// Helper function to create a variable declaration for a temporary
static node_st *create_temp_var_decl(char *name, enum Type type)
{
    return ASTvardecl(NULL, NULL, name, type);
}

// Helper function to create assignment node
static node_st *create_assignment(char *var_name, node_st *expr)
{
    node_st *varlet = ASTvarlet(NULL, strdup(var_name));
    return ASTassign(varlet, expr);
}

// Helper function to check if an expression is complex (needs temporary)
static bool is_complex_expr(node_st *expr)
{
    if (!expr)
        return false;

    switch (NODE_TYPE(expr))
    {
    case NT_FUNCALL:
    case NT_BINOP:
    case NT_MONOP:
        return true;
    default:
        return false;
    }
}

// Helper function to create a variable reference node
static node_st *create_var_ref(char *name)
{
    return ASTvar(NULL, strdup(name));
}

static node_st *create_array_init_loops(char *array_name, node_st *dims, node_st *init_value, generic_stack_st *assignments)
{
    struct data_tvi *data = DATA_TVI_GET();

    node_st *dim_1 = EXPRS_EXPR(dims);
    node_st *dim_2 = EXPRS_EXPR(EXPRS_NEXT(dims));

    // Create copies of dimensions instead of using the originals
    node_st *dim_1_copy = CCNcopy(dim_1);
    node_st *dim_2_copy = CCNcopy(dim_2);

    char *idx_var_1 = STRfmt("tmp_%d", data->temp_counter++);
    char *idx_var_2 = STRfmt("tmp_%d", data->temp_counter++);

    node_st *idx_1_vardecl = ASTvardecl(NULL, NULL, idx_var_1, CT_int);
    node_st *idx_2_vardecl = ASTvardecl(NULL, NULL, idx_var_2, CT_int);

    GStackPush(assignments, idx_1_vardecl);
    GStackPush(assignments, idx_2_vardecl);

    node_st *idx_1 = ASTvarlet(NULL, strdup(idx_var_1));  // Use strdup
    node_st *idx_2 = ASTvarlet(NULL, strdup(idx_var_2));  // Use strdup


    node_st *assignment_idx_1 = ASTassign(idx_1, dim_1_copy);
    node_st *assignment_idx_2 = ASTassign(idx_2, dim_2_copy);

    GStackPush(assignments, assignment_idx_1);
    GStackPush(assignments, assignment_idx_2);

    // Don't free init_value here - it's either used elsewhere or should be freed
    // by the caller if no longer needed
    CCNfree(init_value);
    
    return NULL;
}

// Helper to find or create the init function
static node_st *find_or_create_init_function(node_st *program)
{
    struct data_tvi *data = DATA_TVI_GET();

    // Check if init function already exists
    if (data->init_func_created)
    {
        // Find it in the program
        node_st *decls = PROGRAM_DECLS(program);
        while (decls)
        {
            node_st *decl = DECLS_DECL(decls);
            if (NODE_TYPE(decl) == NT_FUNDEF && strcmp(FUNDEF_NAME(decl), "init") == 0)
            {
                return decl;
            }
            decls = DECLS_NEXT(decls);
        }
    }

    // Create new init function
    node_st *empty_body = ASTfunbody(NULL);
    node_st *init_func = ASTfundef(NULL, empty_body, "init", CT_void, false);
    data->init_func_created = true;

    // Add to program
    node_st *new_decls = ASTdecls(init_func, PROGRAM_DECLS(program));
    PROGRAM_DECLS(program) = new_decls;

    return init_func;
}

// Helper to append to init function
static void add_to_init_function(node_st *init_func, node_st *stmt)
{

    node_st *func_body = FUNDEF_BODY(init_func);

    // Add to function body
    if (FUNBODY_FUNCONTENTS(func_body) == NULL)
    {
        FUNBODY_FUNCONTENTS(func_body) = ASTfuncontents(stmt, NULL);
    }
    else
    {
        // Find end of function contents
        node_st *curr = FUNBODY_FUNCONTENTS(func_body);
        printf("curr: %d\n", NODE_TYPE(curr));
        while (FUNCONTENTS_NEXT(curr))
        {
            curr = FUNCONTENTS_NEXT(curr);
        }
        FUNCONTENTS_NEXT(curr) = ASTfuncontents(stmt, NULL);
    }
}

void TVIfini()
{
    struct data_tvi *data = DATA_TVI_GET();

    if (data->assignments != NULL)
    {
        // Free any remaining contents
        while (!GStackIsEmpty(data->assignments))
        {
            node_st *node = GStackPop(data->assignments);
            CCNfree(node);
        }
        
        // Free the stack itself
        GStackFree(data->assignments, NULL);
        data->assignments = NULL;
    }


}
void TVIinit()
{
    struct data_tvi *data = DATA_TVI_GET();

    data->assignments = GStackNew(200);
    data->temp_counter = 1;
    data->in_global_scope = true;
    data->in_array_dim = false;
    data->init_func_created = false;
}

/**
 * @fn TVIprogram
 */
node_st *TVIprogram(node_st *node)
{
    struct data_tvi *data = DATA_TVI_GET();
    data->in_global_scope = true;

    TRAVchildren(node);

    return node;
}

/**
 * @fn TVIfuncontents
 */
node_st *TVIfuncontents(node_st *node)
{
    // Traverse function content
    // if (FUNCONTENTS_FUNCONTENT(node))
    // {
    //     FUNCONTENTS_FUNCONTENT(node) = TRAVdo(FUNCONTENTS_FUNCONTENT(node));
    // }

    printf("reached funcontents \n");
    switch(NODE_TYPE(FUNCONTENTS_FUNCONTENT(node))) {
        case NT_VARDECL:
            printf("%s\n", VARDECL_NAME(FUNCONTENTS_FUNCONTENT(node)));
            printf("vardecl\n");
            break;
        case NT_STMTS:
            printf("stmts\n");
            break;
        case NT_FUNDEF:
            printf("fundef\n");
            break;
            
    }
    TRAVdo(FUNCONTENTS_FUNCONTENT(node));


    TRAVopt(FUNCONTENTS_NEXT(node));

    // // Check if function content is a variable declaration
    // if (FUNCONTENTS_FUNCONTENT(node) && NODE_TYPE(FUNCONTENTS_FUNCONTENT(node)) == NT_VARDECL)
    // {
    //     struct data_tvi *data = DATA_TVI_GET();

    //     // If we have assignments from this vardecl, insert them after current node
    //     while(!GStackIsEmpty(data->assignments))
    //     {
    //         node_st *next = GStackPopTail(data->assignments);
    //         FUNCONTENTS_NEXT(node) = ASTfuncontents(next, FUNCONTENTS_NEXT(node));

           
    //         // Clean up
    //         // GStackFree(temp_stack, CCNfreeWrapper);
    //     }
    // }

    // // Continue with next node
    // if (FUNCONTENTS_NEXT(node))
    // {
    //     FUNCONTENTS_NEXT(node) = TRAVdo(FUNCONTENTS_NEXT(node));
    // }

    return node;
}

/**
 * @fn TVIfundef
 */
node_st *TVIfundef(node_st *node)
{
    struct data_tvi *data = DATA_TVI_GET();
    // bool prev_scope = data->in_global_scope;

    // // Mark that we're entering a function
    // data->in_global_scope = false;

    // // Skip "init" function if we created it
    // if (strcmp(FUNDEF_NAME(node), "init") == 0 && data->init_func_created)
    // {
    //     // Don't traverse the init function we created to avoid recursion
    //     data->in_global_scope = prev_scope;
    //     return node;
    // }
    // // Traverse children
    TRAVchildren(node);

    while(!GStackIsEmpty(data->assignments))
    {
        node_st *next = GStackPopTail(data->assignments);
        node_st *func_body = FUNDEF_BODY(node);

        if(NODE_TYPE(next) == NT_VARDECL) {
            //insert at the top.
            FUNBODY_FUNCONTENTS(func_body) = ASTfuncontents(next, FUNBODY_FUNCONTENTS(func_body));
        } else if(NODE_TYPE(next) == NT_ASSIGN) {
            //find the last var_decl and insert after it.
            node_st *curr = FUNBODY_FUNCONTENTS(func_body);
            while(FUNCONTENTS_NEXT(curr) && NODE_TYPE(FUNCONTENTS_FUNCONTENT(curr)) == NT_VARDECL) {
                curr = FUNCONTENTS_NEXT(curr);
            }
            FUNCONTENTS_NEXT(curr) = ASTfuncontents(next, FUNCONTENTS_NEXT(curr));
        }
    }
    // printf("test \n\n\n\n\n\n\n\n\n");
    // while(!GStackIsEmpty(data->assignments))
    // {
        
    // }
    // node_st *func_body = FUNDEF_BODY(node);

    // node_st *funcontents = FUNBODY_FUNCONTENTS(func_body);
    // //get all the assignments from the current stack and add them to the function body
    // if (!GStackIsEmpty(data->assignments))
    // {

    //     // Now add them in correct order
    //     while (!GStackIsEmpty(data->assignments))
    //     {
    //         node_st *assign = GStackPopTail(data->assignments);
    //         node_st *new_stmt = ASTstmts(assign, NULL);
    //         if (FUNBODY_FUNCONTENTS(func_body) == NULL)
    //         {
    //             FUNBODY_FUNCONTENTS(func_body) = ASTfuncontents(new_stmt, NULL);
    //         }
    //         else
    //         {
    //             // Find the end of the function contents list
    //             // They have to be inserted after the var_decl but before the first statement

    //             node_st *curr = FUNBODY_FUNCONTENTS(func_body);

    //             node_st *prev = NULL;
    //             while (FUNCONTENTS_NEXT(curr) && NODE_TYPE(FUNCONTENTS_NEXT(curr)) == NT_VARDECL)
    //             {
    //                 prev = curr;
    //                 curr = FUNCONTENTS_NEXT(curr);
    //             }

    //             // Insert after the var_decl
    //             // The prev next needs to be the new statement
    //             FUNCONTENTS_NEXT(prev) = ASTfuncontents(new_stmt, curr);
    //             // // The new statement next needs to be the current next
    //             // FUNCONTENTS_NEXT(new_stmt) = FUNCONTENTS_NEXT(curr);
    //         }
    //     }
    // }

    // Restore previous scope
    // data->in_global_scope = prev_scope;

    return node;
}

/**
 * @fn TVIglobdef
 */
node_st *TVIglobdef(node_st *node)
{
    // struct data_tvi *data = DATA_TVI_GET();

    // // Process only if there's initialization
    // if (GLOBDEF_INIT(node))
    // {
    //     node_st *init_value = GLOBDEF_INIT(node);
    //     node_st *assignment = NULL;

    //     // Handle array vs scalar initialization
    //     if (GLOBDEF_DIMS(node))
    //     {
    //         // Array initialization needs loops
    //         node_st *varlet = ASTvarlet(NULL, strdup(GLOBDEF_NAME(node)));
    //         assignment = ASTassign(varlet, init_value);
    //     }
    //     else
    //     {
    //         // Scalar initialization is simple assignment
    //         node_st *varlet = ASTvarlet(NULL, strdup(GLOBDEF_NAME(node)));
    //         assignment = ASTassign(varlet, init_value);
    //     }

    //     // Add to global assignments stack
    //     GStackPush(data->global_assignments, assignment);

    //     // Clear initialization
    //     GLOBDEF_INIT(node) = NULL;
    // }

    return node;
}

node_st *TVIvardecl(node_st *node)
{
    struct data_tvi *data = DATA_TVI_GET();

    if (VARDECL_INIT(node))
    {
        node_st *init_value = VARDECL_INIT(node);
        
        if (VARDECL_DIMS(node))
        {
            create_array_init_loops(VARDECL_NAME(node), VARDECL_DIMS(node), init_value, data->assignments);
        }
        else
        {
            // Create assignment and add to stack
            node_st *varlet = ASTvarlet(NULL, strdup(VARDECL_NAME(node)));
            node_st *assignment = ASTassign(varlet, init_value);
            GStackPush(data->assignments, assignment);
        }

        VARDECL_INIT(node) = NULL; // Detach from original declaration
    }

    return node;
}