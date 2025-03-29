/**
 * @file
 *
 * Traversal: TransformGlobdefAndCreateInitFunc
 * UID      : TG
 *
 *
 */

#include "user/genericstack/generic_stack.h"

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include <stdlib.h>

#include <palm/str.h>

#include <string.h>

void TGinit()
{
    struct data_tg *data = DATA_TG_GET();

    data->global_assignments = GStackNew(100);
    data->init_func_created = false;
    data->removals = GStackNew(100);
}
void TGfini()
{
    struct data_tg *data = DATA_TG_GET();

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

    if (data->removals != NULL)
    {
        while (!GStackIsEmpty(data->removals))
        {
            node_st *node = GStackPop(data->removals);
            CCNfree(node);
        }

        GStackFree(data->removals, NULL);
        data->removals = NULL;
    }
}

// Helper to find or create the init function
static node_st *find_or_create_init_function(node_st *program)
{
    struct data_tg *data = DATA_TG_GET();

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


    // Create new symbol table
    stable_st *new_table = STnew(data->current_symbol_table_stack_ptr);

    FUNDEF_TABLE(init_func) = new_table;

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

/**
 * @fn TGprogram
 */
node_st *TGprogram(node_st *node)
{
    struct data_tg *data = DATA_TG_GET();

    data->current_symbol_table_stack_ptr = PROGRAM_TABLE(node);

    TRAVchildren(node);

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

    // Remove the global assignments from the program
    // In TGprogram's removal loop:
    while (!GStackIsEmpty(data->removals))
    {
        node_st *next = GStackPopTail(data->removals);
        node_st *decls = PROGRAM_DECLS(node);
        node_st *prev = NULL;

        char *name = GLOBDEF_NAME(next);
        node_st *current_decls;
        printf("Removing global assignment: %s\n", name);

        while (decls)
        {
            current_decls = decls;
            node_st *decl = DECLS_DECL(current_decls);
            if (NODE_TYPE(decl) == NT_GLOBDEF && strcmp(GLOBDEF_NAME(decl), name) == 0)
            {
                // Adjust links to remove current_decls from the list
                if (prev)
                {
                    DECLS_NEXT(prev) = DECLS_NEXT(current_decls);
                }
                else
                {
                    PROGRAM_DECLS(node) = DECLS_NEXT(current_decls);
                }
                // Free the GLOBDEF node and the DECLS node
                DECLS_NEXT(current_decls) = NULL;

                CCNfree(current_decls);
                break;
            }
            prev = current_decls;
            decls = DECLS_NEXT(current_decls);
        }
        // CCNfree(current_decls);

    }

    return node;
}

/**
 * @fn TGglobdef
 */
node_st *TGglobdef(node_st *node)
{
    struct data_tg *data = DATA_TG_GET();

    node_st *init_value = GLOBDEF_INIT(node);

    if (init_value)
    {
        node_st *vardecl = ASTvardecl(CCNcopy(GLOBDEF_DIMS(node)), init_value, strdup(GLOBDEF_NAME(node)), GLOBDEF_TYPE(node));

        VARDECL_EXPORT(vardecl) = GLOBDEF_EXPORT(node);

        GStackPush(data->global_assignments, vardecl);
        GStackPush(data->removals, node);
    }

    GLOBDEF_INIT(node) = NULL; // Detach from original declaration

    TRAVchildren(node);
    return node;
}
