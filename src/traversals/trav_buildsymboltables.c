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
    data->symbol_table_stack_ptr = Stacknew(10);
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
    // Stackfree(data->symbol_table_stack_ptr);

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
    PROGRAM_SYMBOLTABLESTACKPTR(node) = data->symbol_table_stack_ptr;

    //results in traversal of GlobDef, GlobDecl, FunDef, FunDec (basically same as travchildren)
    TRAVdecls(node);

    //Pop scope/symbol table from stack. free is now needed but in the future deeper nested scope does this
    // free(Stackpop(data->symbol_table_stack_ptr));

    printSymbolTableContent(t, false);

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
    printf("inserting '%s' (%s) into symbol table\n", GLOBDECL_NAME(node), typeToString(GLOBDECL_TYPE(node)));
    STinsertVar(t, GLOBDECL_NAME(node), GLOBDECL_TYPE(node));

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
    printf("inserting '%s' (%s) into symbol table\n", GLOBDEF_NAME(node), typeToString(GLOBDEF_TYPE(node)));
    STinsertVar(t, GLOBDEF_NAME(node), GLOBDEF_TYPE(node));

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

    //insert the funcname into the parent symbol table
    printf("inserting '%s' (%s) into symbol table\n", FUNDEF_NAME(node), typeToString(FUNDEF_TYPE(node)));
    STinsertFunc(t, FUNDEF_NAME(node), FUNDEF_TYPE(node));

    //create symbol table for own function and push onto stack
    stable_st *new_table = STnew(t);
    Stackpush(data->symbol_table_stack_ptr, new_table);

    //trav children will loop over params first and then the fun body
    TRAVchildren(node);

    //attaching as attribute
    FUNDEF_TABLE(node) = new_table;
    printf("Attached symbol table to fun def\n");

    printSymbolTableContent(new_table, false);

    //pop current fun def scope from stack
    new_table = Stackpop(data->symbol_table_stack_ptr);  
    STfree(new_table);
    
    return node;
}

/**
 * @fn BSTfundec
 */
node_st *BSTfundec(node_st *node)
{
    printf("\nTraversing func dec\n");

    // get traversal data
    struct data_bst *data = DATA_BST_GET();

    //peek the current scope
    stable_st *t = StackPeek(data->symbol_table_stack_ptr);

    //insert the funcname into the symbol table
    printf("inserting '%s' (%s) into symbol table\n", FUNDEC_NAME(node), typeToString(FUNDEC_TYPE(node)));
    STinsertFunc(t, FUNDEC_NAME(node), FUNDEC_TYPE(node));

    //create symbol table for own function and push onto stack
    stable_st *new_table = STnew(t);
	Stackpush(data->symbol_table_stack_ptr, new_table);

	TRAVchildren(node);

    //attaching as attribute
    FUNDEC_TABLE(node) = new_table;
    printf("Attached symbol table to fun def\n");

	new_table = Stackpop(data->symbol_table_stack_ptr);
	STfree(new_table);
    return node;
}


/**
 * @fn BSTfunbody
 */
node_st *BSTfunbody(node_st *node)
{
    printf("\nTraversing fun body\n");
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTparam
 */
node_st *BSTparam(node_st *node)
{
    printf("\nTraversing param\n");

    //get traversal data
    struct data_bst *data = DATA_BST_GET();

    //peek the current scope
    stable_st *t = StackPeek(data->symbol_table_stack_ptr);
 
    //insert the funcname into the symbol table
    printf("inserting '%s' (%s) into symbol table\n", PARAM_NAME(node), typeToString(PARAM_TYPE(node)));
    STinsertVar(t, PARAM_NAME(node), PARAM_TYPE(node));

    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTvardecl
 */
node_st *BSTvardecl(node_st *node)
{
	printf("\nTraversing vardecl\n");

	//get traversal data
	struct data_bst *data = DATA_BST_GET();

	//peek the current scope
	stable_st *t = StackPeek(data->symbol_table_stack_ptr);
  
	//insert the funcname into the symbol table
	printf("inserting '%s' (%s) into symbol table\n", VARDECL_NAME(node), typeToString(VARDECL_TYPE(node)));
	STinsertVar(t, VARDECL_NAME(node), VARDECL_TYPE(node));

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
	printf("\nTraversing for\n");

	//get traversal data
	struct data_bst *data = DATA_BST_GET();

	//peek the current scope
	stable_st *t = StackPeek(data->symbol_table_stack_ptr);

	//create symbol table for own function and push onto stack
	stable_st *new_table = STnew(t);

	printf("\n %s \n", FOR_VAR(node));
	
	//insert relevant data from the for loop
	printf("inserting '%s' (%s) into symbol table\n", FOR_VAR(node), typeToString(CT_int));
	STinsertVar(new_table, FOR_VAR(node), CT_int);

	//stack push new table
	Stackpush(data->symbol_table_stack_ptr, new_table);

    TRAVchildren(node);

	new_table = Stackpop(data->symbol_table_stack_ptr);

	printSymbolTableContent(new_table, false);

	STfree(new_table);

    return node;
}

/**
 * @fn BSTreturn
 */
node_st *BSTreturn(node_st *node)
{
	printf("\nTraversing return\n");

	//get traversal data
	struct data_bst *data = DATA_BST_GET();

	//peek the current scope
	stable_st *t = StackPeek(data->symbol_table_stack_ptr);
	
	//insert relevant data from the for loop
	printf("inserting '%s' (%s) into symbol table\n", "RETURN", typeToString(RETURN_TYPE(node)));
	STinsertVar(t, "RETURN", RETURN_TYPE(node));

	printSymbolTableContent(t, false);
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