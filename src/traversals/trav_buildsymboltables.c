/**
 * @file
 *
 * Traversal: BuildSymbolTables
 * UID      : BST
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "user/symbolTable/symbol_table.h"
#include "user/stack/stack.h"

//used to create the stack
void BSTinit() 
{
    printf("\nINITIALIZING SYMBOL TABLE TRAVERSAL\n");
    printf("Creating traversal stack\n");
    struct data_bst *data = DATA_BST_GET();
    data->symbol_table_stack_ptr = Stacknew(10);;
    printf("Created traversal stack, entering traversals\n\n");

    return;
}

//used for cleanup
void BSTfini() 
{
    printf("\nFINISHING SYMBOL TABLE TRAVERSAL\n");

    printf("Getting symbol table stack\n");
    struct data_bst *data = DATA_BST_GET();

    printf("Freeing up symbol table stack\n");
    Stackfree(data->symbol_table_stack_ptr);

    return;
}

/**
 * @fn BSTprogram
 */
node_st *BSTprogram(node_st *node)
{
    printf("Started traversal\n");
    //create initial symbol table

    printf("Creating symbol table\n");
    stable_st *t = STnew(0);

    //get traversal data
    struct data_bst *data = DATA_BST_GET();

    //add new symbol table to the stack
    Stackpush(data->symbol_table_stack_ptr, t);

    //attaching as child
    //PROGRAM_SYMBOLTABLE(node) = t;

    //attaching as attribute
    PROGRAM_TABLE(node) = t;

    TRAVchildren(node);

    //Pop scope/symbol table from stack. free is now needed but in the future deeper nested scope does this
    free(Stackpop(data->symbol_table_stack_ptr));

    return node;
}

/**
 * @fn BSTfundef
 */
node_st *BSTfundef(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTglobdef
 */
node_st *BSTglobdef(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTfundec
 */
node_st *BSTfundec(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTglobdecl
 */
node_st *BSTglobdecl(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTfunbody
 */
node_st *BSTfunbody(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTdowhile
 */
node_st *BSTdowhile(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTfor
 */
node_st *BSTfor(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTifelse
 */
node_st *BSTifelse(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTwhile
 */
node_st *BSTwhile(node_st *node)
{
    TRAVchildren(node);
    return node;
}