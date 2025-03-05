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

    //results in traversal of GlobDef, GlobDecl, FunDef, FunDec (basically same as travchildren)
    TRAVdecls(node);

    //Pop scope/symbol table from stack. free is now needed but in the future deeper nested scope does this
    // free(Stackpop(data->symbol_table_stack_ptr));

    return node;
}

/**
 * @fn BSTglobdecl
 */
node_st *BSTglobdecl(node_st *node)
{
    printf("\nTraversing glob decl\n");

    //get traversal data
    struct data_bst *data = DATA_BST_GET();

    //peek the current scope
    stable_st *t = StackPeek(data->symbol_table_stack_ptr);

    //insert the funcname into the symbol table
    printf("inserting '%s' into symbol table\n", GLOBDECL_NAME(node));
    STinsertVar(t, GLOBDECL_NAME(node));

    //attaching as attribute
    GLOBDECL_TABLE(node) = t;
    printf("Attached symbol table to glob decl\n");

    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTglobdef
 */
node_st *BSTglobdef(node_st *node)
{
    printf("\nTraversing glob def\n");

    //get traversal data
    struct data_bst *data = DATA_BST_GET();

    //peek the current scope
    stable_st *t = StackPeek(data->symbol_table_stack_ptr);

    //insert the funcname into the symbol table
    printf("inserting '%s' into symbol table\n", GLOBDEF_NAME(node));
    STinsertVar(t, GLOBDEF_NAME(node));

    //attaching as attribute
    GLOBDEF_TABLE(node) = t;
    printf("Attached symbol table to glob def\n");

    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTfundef
 */
node_st *BSTfundef(node_st *node)
{
    printf("\nTraversing func def\n");

    //get traversal data
    struct data_bst *data = DATA_BST_GET();

    //peek the current scope
    stable_st *t = StackPeek(data->symbol_table_stack_ptr);

    //insert the funcname into the symbol table
    printf("inserting '%s' into symbol table\n", FUNDEF_NAME(node));
    STinsertFunc(t, FUNDEF_NAME(node));

    //attaching as attribute
    FUNDEF_TABLE(node) = t;
    printf("Attached symbol table to fun def\n");

    TRAVchildren(node);

    return node;
}

/**
 * @fn BSTfundec
 */
node_st *BSTfundec(node_st *node)
{
    printf("\nTraversing func dec\n");

    //get traversal data
    struct data_bst *data = DATA_BST_GET();

    //peek the current scope
    stable_st *t = StackPeek(data->symbol_table_stack_ptr);

    //insert the funcname into the symbol table
    printf("inserting '%s' into symbol table\n", FUNDEC_NAME(node));
    STinsertFunc(t, FUNDEC_NAME(node));

    //attaching as attribute
    FUNDEC_TABLE(node) = t;
    printf("Attached symbol table to fun dec\n");

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