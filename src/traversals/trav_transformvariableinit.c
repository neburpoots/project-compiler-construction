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

void CCNfreeWrapper(void *ptr)
{
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

static char *create_vardecl(struct data_tvi *data)
{

    char *idx_var = create_temp_var_name(data);
    node_st *idx_vardecl = ASTvardecl(NULL, NULL, idx_var, CT_int);

    GStackPush(data->assignments, idx_vardecl);

    STinsertVar(data->current_symbol_table_stack_ptr, idx_var, CT_int);

    return idx_var;
}

static void create_and_push_assignment(char *var_name, node_st *value, generic_stack_st *assignments)
{
    struct data_tvi *data = DATA_TVI_GET();

    node_st *idx = ASTvarlet(NULL, strdup(var_name)); // Create varlet with a copy of var_name
    node_st *assignment = ASTassign(idx, value);      // Create assignment
    GStackPush(assignments, assignment);              // Push to assignments stack
    ASSIGN_TABLE(assignment) = data->current_symbol_table_stack_ptr; // Set symbol table
}

static char *create_temp_save_array(struct data_tvi *data, generic_stack_st *assignments, node_st *init_value)
{
    char *idx_var = create_temp_var_name(data);
    node_st *idx_vardecl = ASTvardecl(NULL, NULL, idx_var, CT_int);
    STinsertVar(data->current_symbol_table_stack_ptr, idx_var, CT_int);

    GStackPush(assignments, idx_vardecl);
    node_st *assignment_idx_3 = ASTassign(ASTvarlet(NULL, strdup(idx_var)), init_value);
    GStackPush(assignments, assignment_idx_3);

    ASSIGN_TABLE(assignment_idx_3) = data->current_symbol_table_stack_ptr;

    return idx_var;
}

// Very static code but done for easy readability.
// Everything is used by everything.
static node_st *refactor_2d_array_loops(char *array_name, node_st *dims, node_st *init_value, generic_stack_st *assignments)
{
    struct data_tvi *data = DATA_TVI_GET();

    node_st *dim_1 = EXPRS_EXPR(dims);
    node_st *dim_2 = EXPRS_EXPR(EXPRS_NEXT(dims));

    // Create copies of dimensions instead of using the originals
    node_st *dim_1_copy = CCNcopy(dim_1);
    node_st *dim_2_copy = CCNcopy(dim_2);

    char *idx_var_1 = create_vardecl(data);
    char *idx_var_2 = create_vardecl(data);

    EXPRS_EXPR(dims) = ASTvar(NULL, strdup(idx_var_1));
    CCNfree(dim_1);
    EXPRS_EXPR(EXPRS_NEXT(dims)) = ASTvar(NULL, strdup(idx_var_2));
    CCNfree(dim_2);

    // int tmp_1;
    // int tmp_2;
    // tmp_1 = 2;
    // tmp_2 = test();
    create_and_push_assignment(idx_var_1, dim_1_copy, assignments);
    create_and_push_assignment(idx_var_2, dim_2_copy, assignments);

    // Temp variable for the array assignment
    // int tmp_3;
    // tmp_3 = [[1, 2][1, 0], [3, 4][1, 0]];
    char *idx_var_3 = create_temp_save_array(data, assignments, init_value);

    // Allocate pseudo function assignment
    node_st *start = ASTassign(
        ASTvarlet(NULL, strdup(array_name)),
        ASTfuncall(
            ASTexprs(
                ASTvar(
                    NULL,
                    strdup(idx_var_1)),
                ASTexprs(
                    ASTvar(NULL, strdup(idx_var_2)),
                    NULL)),
            strdup("__allocate")));
    GStackPush(assignments, start);

    ASSIGN_TABLE(start) = data->current_symbol_table_stack_ptr;

    // create two temp variables for the two loops
    char *idx_var_4 = create_temp_var_name(data);
    char *idx_var_5 = create_temp_var_name(data);
    node_st *idx_4_vardecl = ASTvardecl(NULL, NULL, idx_var_4, CT_int);
    node_st *idx_5_vardecl = ASTvardecl(NULL, NULL, idx_var_5, CT_int);
    GStackPush(assignments, idx_4_vardecl);
    GStackPush(assignments, idx_5_vardecl);
    create_and_push_assignment(idx_var_4, ASTnum(0), assignments);
    create_and_push_assignment(idx_var_5, ASTnum(0), assignments);

    // create symbol table for own function and push onto stack
    // stable_st *new_table = STnew(data->current_symbol_table_stack_ptr);

    // insert into symbol table
    STinsertVar(data->current_symbol_table_stack_ptr, idx_var_1, CT_int);
    STinsertVar(data->current_symbol_table_stack_ptr, idx_var_2, CT_int);
    STinsertVar(data->current_symbol_table_stack_ptr, idx_var_3, CT_int);
    STinsertVar(data->current_symbol_table_stack_ptr, idx_var_4, CT_int);
    STinsertVar(data->current_symbol_table_stack_ptr, idx_var_5, CT_int);

    // Assignment inside the inner loop
    node_st *assignment_inner_loop = ASTassign(
        ASTvarlet(ASTexprs(ASTvar(NULL, strdup(idx_var_4)), ASTexprs(ASTvar(NULL, strdup(idx_var_5)), NULL)), strdup(array_name)),
        ASTvar(NULL, strdup(idx_var_3)));

    ASSIGN_TABLE(assignment_inner_loop) = data->current_symbol_table_stack_ptr;

    // Inner for loop
    // i < 10
    node_st *inner_condition = ASTbinop(
        ASTvar(NULL, strdup(idx_var_5)),
        CCNcopy(dim_2_copy),
        BO_lt);

    // create for loop
    node_st *inner_for_loop = ASTfor(
        ASTvar(NULL, strdup(idx_var_5)),
        inner_condition,
        ASTnum(1),
        ASTstmts(assignment_inner_loop, NULL),
        strdup(idx_var_5));

    // Outer for loop
    // i < 10
    node_st *outer_condition = ASTbinop(
        ASTvar(NULL, strdup(idx_var_4)),
        CCNcopy(dim_1_copy),
        BO_lt);

    // create for loop
    node_st *outer_for_loop = ASTfor(
        ASTvar(NULL, strdup(idx_var_4)),
        outer_condition,
        ASTnum(1),
        ASTstmts(inner_for_loop, NULL),
        strdup(idx_var_4));

    FOR_TABLE(outer_for_loop) = STnew(data->current_symbol_table_stack_ptr);
    FOR_TABLE(inner_for_loop) = STnew(FOR_TABLE(outer_for_loop));

    GStackPush(data->stmts, outer_for_loop);

    return NULL;
}

static refactor_array_loops_assignment(node_st *assignment, node_st *dims, generic_stack_st *assignments)
{
    struct data_tvi *data = DATA_TVI_GET();

    node_st *dim_1 = EXPRS_EXPR(dims);

    char *array_name = VARLET_NAME(ASSIGN_LET(assignment));

    char *idx_var_1 = create_vardecl(data);

    EXPRS_EXPR(dims) = ASTvar(NULL, strdup(idx_var_1));

    create_and_push_assignment(idx_var_1, dim_1, assignments);

    char *idx_var_2 = create_vardecl(data);

    create_and_push_assignment(idx_var_2, ASSIGN_EXPR(assignment), assignments);

    ASSIGN_EXPR(assignment) =
        ASTfuncall(
            ASTexprs(
                ASTvar(
                    NULL,
                    strdup(idx_var_1)),
                NULL),
            strdup("__allocate"));
    
    // For loop variable
    char *idx_var_3 = create_temp_var_name(data);
    node_st *idx_3_vardecl = ASTvardecl(NULL, NULL, idx_var_3, CT_int);
    GStackPush(assignments, idx_3_vardecl);
    create_and_push_assignment(idx_var_3, ASTnum(0), assignments);

    STinsertVar(data->current_symbol_table_stack_ptr, idx_var_1, CT_int);
    STinsertVar(data->current_symbol_table_stack_ptr, idx_var_2, CT_int);
    STinsertVar(data->current_symbol_table_stack_ptr, idx_var_3, CT_int);


    // Assignment inside the loop
    node_st *assignment_loop = ASTassign(
        ASTvarlet(ASTexprs(ASTvar(NULL, strdup(idx_var_3)), NULL), strdup(array_name)),
        ASTvar(NULL, strdup(idx_var_2)));

    ASSIGN_TABLE(assignment_loop) = data->current_symbol_table_stack_ptr;

    node_st *condition = ASTbinop(
        ASTvar(NULL, strdup(idx_var_3)),
        CCNcopy(dim_1),
        BO_lt);

    // Inner for loop
    node_st *for_loop = ASTfor(
        ASTvar(NULL, strdup(idx_var_3)),
        condition,
        ASTnum(1),
        ASTstmts(assignment_loop, NULL),
        strdup(idx_var_3));
    GStackPush(data->stmts, for_loop);

    // create new symbol table for loop
    FOR_TABLE(for_loop) = STnew(data->current_symbol_table_stack_ptr);
}

static refactor_array_loops(char *array_name, node_st *dims, node_st *init_value, generic_stack_st *assignments)
{

    struct data_tvi *data = DATA_TVI_GET();

    node_st *dim_1 = EXPRS_EXPR(dims);

    char *idx_var_1 = create_vardecl(data);

    EXPRS_EXPR(dims) = ASTvar(NULL, strdup(idx_var_1));

    create_and_push_assignment(idx_var_1, dim_1, assignments);

    // int tmp_3;
    // tmp_3 = [[1, 2][1, 0], [3, 4][1, 0]];
    char *idx_var_2 = create_temp_save_array(data, assignments, init_value);

    // For loop variable
    char *idx_var_3 = create_temp_var_name(data);
    node_st *idx_3_vardecl = ASTvardecl(NULL, NULL, idx_var_3, CT_int);
    GStackPush(assignments, idx_3_vardecl);
    create_and_push_assignment(idx_var_3, ASTnum(0), assignments);


    STinsertVar(data->current_symbol_table_stack_ptr, idx_var_1, CT_int);
    STinsertVar(data->current_symbol_table_stack_ptr, idx_var_2, CT_int);
    STinsertVar(data->current_symbol_table_stack_ptr, idx_var_3, CT_int);

    // Allocate pseudo function assignment
    node_st *start = ASTassign(
        ASTvarlet(NULL, strdup(array_name)),
        ASTfuncall(
            ASTexprs(
                ASTvar(
                    NULL,
                    strdup(idx_var_1)),
                NULL),
            strdup("__allocate")));
    GStackPush(assignments, start);

    ASSIGN_TABLE(start) = data->current_symbol_table_stack_ptr;

    // Assignment inside the loop
    node_st *assignment_loop = ASTassign(
        ASTvarlet(ASTexprs(ASTvar(NULL, strdup(idx_var_3)), NULL), strdup(array_name)),
        ASTvar(NULL, strdup(idx_var_2)));
    
    ASSIGN_TABLE(assignment_loop) = data->current_symbol_table_stack_ptr;

    node_st *condition = ASTbinop(
        ASTvar(NULL, strdup(idx_var_3)),
        CCNcopy(dim_1),
        BO_lt);

    // Inner for loop
    node_st *for_loop = ASTfor(
        ASTvar(NULL, strdup(idx_var_3)),
        condition,
        ASTnum(1),
        ASTstmts(assignment_loop, NULL),
        strdup(idx_var_3));
    GStackPush(data->stmts, for_loop);

    // create new symbol table for loop
    FOR_TABLE(for_loop) = STnew(data->current_symbol_table_stack_ptr);
}

static void refactor_2d_array(char *array_name, node_st *dims, node_st *init_value, generic_stack_st *assignments)
{
    struct data_tvi *data = DATA_TVI_GET();

    node_st *dim_1 = EXPRS_EXPR(dims);
    node_st *dim_2 = EXPRS_EXPR(EXPRS_NEXT(dims));

    // Create copies of dimensions instead of using the originals
    node_st *dim_1_copy = CCNcopy(dim_1);
    node_st *dim_2_copy = CCNcopy(dim_2);

    char *idx_var_1 = create_vardecl(data);
    char *idx_var_2 = create_vardecl(data);

    EXPRS_EXPR(dims) = ASTvar(NULL, strdup(idx_var_1));
    CCNfree(dim_1);
    EXPRS_EXPR(EXPRS_NEXT(dims)) = ASTvar(NULL, strdup(idx_var_2));
    CCNfree(dim_2);

    // int tmp_1;
    // int tmp_2;
    // tmp_1 = 2;
    // tmp_2 = test();
    create_and_push_assignment(idx_var_1, dim_1_copy, assignments);
    create_and_push_assignment(idx_var_2, dim_2_copy, assignments);

    // Allocate pseudo function assignment
    node_st *start = ASTassign(
        ASTvarlet(NULL, strdup(array_name)),
        ASTfuncall(
            ASTexprs(
                ASTvar(
                    NULL,
                    strdup(idx_var_1)),
                ASTexprs(
                    ASTvar(NULL, strdup(idx_var_2)),
                    NULL)),
            strdup("__allocate")));
    GStackPush(assignments, start);

    ASSIGN_TABLE(start) = data->current_symbol_table_stack_ptr;

    node_st *arrExpr = ARREXPR_EXPRS(init_value);

    int counter = 0;
    while (arrExpr)
    {
        node_st *innerArrayExprs = ARREXPR_EXPRS(EXPRS_EXPR(arrExpr));

        int innerCounter = 0;

        while (innerArrayExprs)
        {
            node_st *numberExpression = EXPRS_EXPR(innerArrayExprs);

            // char *idx_var = create_temp_var_name(data);
            node_st *idx_assign = ASTassign(ASTvarlet(ASTexprs(ASTnum(counter), ASTexprs(ASTnum(innerCounter), NULL)), strdup(array_name)), CCNcopy(numberExpression));

            ASSIGN_TABLE(idx_assign) = data->current_symbol_table_stack_ptr;

            GStackPush(data->assignments, idx_assign);

            innerArrayExprs = EXPRS_NEXT(innerArrayExprs);
            innerCounter++;
        }
        arrExpr = EXPRS_NEXT(arrExpr);
        counter++;
    }

    CCNfree(init_value);
}

static void refactor_array(char *array_name, node_st *dims, node_st *init_value, generic_stack_st *assignments)
{
    struct data_tvi *data = DATA_TVI_GET();

    node_st *dim_1 = EXPRS_EXPR(dims);

    node_st *dim_1_copy = CCNcopy(dim_1);

    char *idx_var_1 = create_vardecl(data);

    EXPRS_EXPR(dims) = ASTvar(NULL, strdup(idx_var_1));
    CCNfree(dim_1);

    create_and_push_assignment(idx_var_1, dim_1_copy, assignments);

    node_st *start = ASTassign(
        ASTvarlet(NULL, strdup(array_name)),
        ASTfuncall(
            ASTexprs(
                ASTvar(
                    NULL,
                    strdup(idx_var_1)),
                NULL),
            strdup("__allocate")));
    GStackPush(assignments, start);

    ASSIGN_TABLE(start) = data->current_symbol_table_stack_ptr;

    node_st *arrExpr = ARREXPR_EXPRS(init_value);

    int counter = 0;
    while (arrExpr)
    {
        node_st *expr = EXPRS_EXPR(arrExpr);

        // char *idx_var = create_temp_var_name(data);
        node_st *idx_assign = ASTassign(ASTvarlet(ASTexprs(ASTnum(counter), NULL), strdup(array_name)), CCNcopy(expr));

        ASSIGN_TABLE(idx_assign) = data->current_symbol_table_stack_ptr;
        
        GStackPush(data->assignments, idx_assign);

        arrExpr = EXPRS_NEXT(arrExpr);
        counter++;
    }

    // CCNfree(init_value);
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
            if (NODE_TYPE(decl) == NT_FUNDEF && strcmp(FUNDEF_NAME(decl), "__init") == 0)
            {
                return decl;
            }
            decls = DECLS_NEXT(decls);
        }
    }

    // Create new init function
    node_st *empty_body = ASTfunbody(NULL);
    node_st *init_func = ASTfundef(NULL, empty_body, strdup("__init"), CT_void, false);
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
        FUNBODY_FUNCONTENTS(func_body) = ASTfuncontents(stmt, FUNBODY_FUNCONTENTS(func_body));
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

    if (data->stmts != NULL)
    {
        while (!GStackIsEmpty(data->stmts))
        {
            node_st *node = GStackPop(data->stmts);
            CCNfree(node);
        }

        GStackFree(data->stmts, NULL);
        data->stmts = NULL;
    }

    if (data->global_assignments != NULL)
    {
        while (!GStackIsEmpty(data->global_assignments))
        {
            node_st *node = GStackPop(data->global_assignments);
            CCNfree(node);
        }

        GStackFree(data->global_assignments, NULL);
        data->global_assignments = NULL;
    }

    if (data->execute_statement_order != NULL)
    {
        while (!GStackIsEmpty(data->execute_statement_order))
        {
            node_st *node = GStackPop(data->execute_statement_order);
            CCNfree(node);
        }

        GStackFree(data->execute_statement_order, NULL);
        data->execute_statement_order = NULL;
    }
}

void TVIinit()
{
    struct data_tvi *data = DATA_TVI_GET();

    data->assignments = GStackNew(200);
    data->stmts = GStackNew(200);
    data->global_assignments = GStackNew(100);
    data->execute_statement_order = GStackNew(100);
    data->temp_counter = 1;
    data->in_global_scope = true;
    data->in_array_dim = false;
    data->init_func_created = true;
}

//method to convert the decls back to globdefs in the init function
static void convert_init_decls_to_globdefs(node_st *init_func, node_st *program)
{
    struct data_tvi *data = DATA_TVI_GET();

    node_st *decls = FUNBODY_FUNCONTENTS(FUNDEF_BODY(init_func));
    node_st *prev = NULL;
    node_st *new_decls_head = NULL; // Temporary list for ordered GLOBDEFs
    node_st *new_decls_tail = NULL;

    while (decls)
    {
        node_st *decl = FUNCONTENTS_FUNCONTENT(decls);
        if (NODE_TYPE(decl) == NT_VARDECL)
        {
            // Convert to GLOBDEF
            node_st *globdef = ASTglobdef(
                CCNcopy(VARDECL_DIMS(decl)), 
                NULL, 
                strdup(VARDECL_NAME(decl)), 
                VARDECL_TYPE(decl), 
                VARDECL_EXPORT(decl)
            );

            // Add to temporary list (maintaining order)
            node_st *new_decl_node = ASTdecls(globdef, NULL);
            if (!new_decls_head) {
                new_decls_head = new_decl_node;
                new_decls_tail = new_decl_node;
            } else {
                DECLS_NEXT(new_decls_tail) = new_decl_node;
                new_decls_tail = new_decl_node;
            }

            // Remove from init function
            node_st *next = FUNCONTENTS_NEXT(decls);
            if (prev) {
                FUNCONTENTS_NEXT(prev) = next;
            } else {
                FUNBODY_FUNCONTENTS(FUNDEF_BODY(init_func)) = next;
            }
            FUNCONTENTS_NEXT(decls) = NULL;
            CCNfree(decls);
            decls = next;
        }
        else
        {
            prev = decls;
            decls = FUNCONTENTS_NEXT(decls);
        }
    }

    // Prepend the new declarations (in original order) to PROGRAM_DECLS
    if (new_decls_head) {
        DECLS_NEXT(new_decls_tail) = PROGRAM_DECLS(program);
        PROGRAM_DECLS(program) = new_decls_head;
    }
}
/**
 * @fn TVIprogram
 */
node_st *TVIprogram(node_st *node)
{
    struct data_tvi *data = DATA_TVI_GET();
    data->in_global_scope = true;

    data->current_symbol_table_stack_ptr = PROGRAM_TABLE(node);

    TRAVchildren(node);

    // init_function = ASTfundef(NULL, ASTfunbody(NULL), "init", CT_void, false);
    node_st *init_func = find_or_create_init_function(node);

    if (!StackisEmpty(data->global_assignments))
    {
        node_st *init_func = find_or_create_init_function(node);

        while (!StackisEmpty(data->global_assignments))
        {
            node_st *next = GStackPopTail(data->global_assignments);
            add_to_init_function(init_func, next);
        }
    }

    //Remove decls from init function and move these back to global scope
    convert_init_decls_to_globdefs(init_func, node);

    return node;
}

/**
 * @fn TVIfuncontents
 */
node_st *TVIfuncontents(node_st *node)
{
    struct data_tvi *data = DATA_TVI_GET();

    //find inner functions first and do those first.
    if(NODE_TYPE(FUNCONTENTS_FUNCONTENT(node)) == NT_FUNDEF)
    {
        TRAVdo(FUNCONTENTS_FUNCONTENT(node));
    } else {
        GStackPush(data->execute_statement_order, FUNCONTENTS_FUNCONTENT(node));
    }

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
    data->in_global_scope = false;

    stack_stptr *global = data->current_symbol_table_stack_ptr;

    data->current_symbol_table_stack_ptr = FUNDEF_TABLE(node);

    TRAVbody(node);

    //Makes sure that the inner functions are done first.
    
    while(!GStackIsEmpty(data->execute_statement_order))
    {
        node_st *next = GStackPopTail(data->execute_statement_order);
        TRAVdo(next);
    }

    TRAVparams(node);

    node_st *func_body = FUNDEF_BODY(node);
    node_st *last_var_decl = NULL;

    // loop over al function contents and print the node type.
    node_st *iterator = FUNBODY_FUNCONTENTS(func_body);

    while (iterator)
    {
        if (NODE_TYPE(FUNCONTENTS_FUNCONTENT(iterator)) == NT_VARDECL)
        {
            last_var_decl = iterator;
        }
        iterator = FUNCONTENTS_NEXT(iterator);
    }

    // printf("last var decl: %s\n", node_to_type_string(FUNCONTENTS_FUNCONTENT(last_var_decl)));

    while (!GStackIsEmpty(data->assignments))
    {
        node_st *next = GStackPopTail(data->assignments);
        // node_st *func_body = FUNDEF_BODY(node);

        if (NODE_TYPE(next) == NT_VARDECL)
        {
            // insert at the top.
            FUNBODY_FUNCONTENTS(func_body) = ASTfuncontents(next, FUNBODY_FUNCONTENTS(func_body));
        }
        else if (NODE_TYPE(next) == NT_ASSIGN && last_var_decl)
        {
            FUNCONTENTS_NEXT(last_var_decl) = ASTfuncontents(next, FUNCONTENTS_NEXT(last_var_decl));
        } else {
            // Add it to the end of the function body
            node_st *search_last = FUNBODY_FUNCONTENTS(func_body);
            while (FUNCONTENTS_NEXT(search_last))
            {
                search_last = FUNCONTENTS_NEXT(search_last);
            }
            FUNCONTENTS_NEXT(search_last) = ASTfuncontents(next, NULL);
        }
    }

    // For loop insert part for arrays and 2d arrays -------------

    // get the last item before the first statement
    node_st *last_before_stmt = NULL;
    node_st *curr = FUNBODY_FUNCONTENTS(func_body);
    while (curr)
    {
        node_st *funcontents_next = FUNCONTENTS_NEXT(curr);

        if (funcontents_next == NULL)
        {
            break;
        }

        node_st *funcontent_next = FUNCONTENTS_FUNCONTENT(funcontents_next);

        if (funcontents_next && funcontent_next &&
            (NODE_TYPE(funcontent_next) == NT_IFELSE ||
             NODE_TYPE(funcontent_next) == NT_WHILE ||
             NODE_TYPE(funcontent_next) == NT_FOR ||
             NODE_TYPE(funcontent_next) == NT_DOWHILE ||
             NODE_TYPE(funcontent_next) == NT_EXPRSTMT ||
             NODE_TYPE(funcontent_next) == NT_RETURN))
        {
            last_before_stmt = curr;
            break;
        }
        curr = FUNCONTENTS_NEXT(curr);
    }

    // Add the for loops before the first statement
    while (!GStackIsEmpty(data->stmts))
    {
        node_st *next = GStackPopTail(data->stmts);

        // Add it before the first stmt
        if (last_before_stmt)
        {
            FUNCONTENTS_NEXT(last_before_stmt) = ASTfuncontents(next, FUNCONTENTS_NEXT(last_before_stmt));
        }
        else
        {
            // Add it last
            node_st *search_last = FUNBODY_FUNCONTENTS(func_body);
            while (FUNCONTENTS_NEXT(search_last))
            {
                search_last = FUNCONTENTS_NEXT(search_last);
            }
            FUNCONTENTS_NEXT(search_last) = ASTfuncontents(next, NULL);
        }
    }

    // Reset global scope
    data->in_global_scope = true;
    data->current_symbol_table_stack_ptr = global;

    return node;
}

/**
 * @fn TVIglobdef
 */
node_st *TVIglobdef(node_st *node)
{
    struct data_tvi *data = DATA_TVI_GET();

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
            // 2d array initialized with int[2, 2] test = 2
            if (EXPRS_NEXT(VARDECL_DIMS(node)) && EXPR_TYPE(init_value) == CT_int)
            {
                // printf("refactor 2d array loops\n");
                refactor_2d_array_loops(VARDECL_NAME(node), VARDECL_DIMS(node), init_value, data->assignments);
            }
            // 2d array initialized with int[2, 2] test = 2
            else if (!EXPRS_NEXT(VARDECL_DIMS(node)) && EXPR_TYPE(init_value) == CT_int)
            {
                // printf("refactor array loops\n");
                // printf()
                refactor_array_loops(VARDECL_NAME(node), VARDECL_DIMS(node), init_value, data->assignments);
            }
            else if (EXPRS_NEXT(VARDECL_DIMS(node)))
            {
                refactor_2d_array(VARDECL_NAME(node), VARDECL_DIMS(node), init_value, data->assignments);
            }
            else
            {
                refactor_array(VARDECL_NAME(node), VARDECL_DIMS(node), init_value, data->assignments);
                CCNfree(init_value);
            }
        }
        else
        {
            // Create assignment and add to stack
            node_st *varlet = ASTvarlet(NULL, strdup(VARDECL_NAME(node)));
            node_st *assignment = ASTassign(varlet, init_value);
            GStackPush(data->assignments, assignment);
            ASSIGN_TABLE(assignment) = data->current_symbol_table_stack_ptr;
        }

        VARDECL_INIT(node) = NULL; // Detach from original declaration
    }

    return node;
}

/**
 * @fn TVIassign
 */
node_st *TVIassign(node_st *node)
{
    struct data_tvi *data = DATA_TVI_GET();

    char *var_name = VARLET_NAME(ASSIGN_LET(node));

    var_entry_st *result = STlookupVar(ASSIGN_TABLE(node), var_name, true);

    node_st *dims = result->dimensions;

    node_st *init_value = ASSIGN_EXPR(node);

    if (dims)
    {

        // 2d array initialized with int[2, 2] test = 2
        if (EXPRS_NEXT(dims) && EXPR_TYPE(init_value) == CT_int)
        {
            // printf("refactor 2d array loops\n");
            refactor_2d_array_loops(var_name, dims, init_value, data->assignments);
        }
        // 2d array initialized with int[2, 2] test = 2
        else if (!EXPRS_NEXT(dims) && EXPR_TYPE(init_value) == CT_int)
        {
            // printf("refactor array loops\n");
            // printf()
            refactor_array_loops_assignment(node, result->dimensions, data->assignments);
        }
        else if (EXPRS_NEXT(dims))
        {
            refactor_2d_array(var_name, dims, init_value, data->assignments);
        }
        else
        {
            refactor_array(var_name, dims, init_value, data->assignments);
        }
    }

    return node;
}