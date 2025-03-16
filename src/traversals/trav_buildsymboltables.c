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

// ANSI color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m"  // Resets color formatting

void printVariableAlreadyDeclared(node_st *node);
param_entry_st *create_params(node_st *node);

param_entry_st *create_params(node_st *node) {
  param_entry_st *params = NULL;
  param_entry_st **tail = &params;

  node_st *param_node;

  //get params based on the supplied node
  switch NODE_TYPE(node){
    case NT_FUNDEC:
      param_node = FUNDEC_PARAMS(node);
      break;
    case NT_FUNDEF:
      param_node = FUNDEF_PARAMS(node);
      break;
    default: return NULL;
  }

  while (param_node) {
      printf("Creating param with type: %s\n", typeToString(PARAM_TYPE(param_node)));
      param_entry_st *p = malloc(sizeof(param_entry_st));
      p->type = PARAM_TYPE(param_node);
      p->next = NULL;

      *tail = p;
      tail = &(p->next);

      param_node = PARAM_NEXT(param_node);
  }

  return params;
}

//print already declared error.
void printVariableAlreadyDeclared(node_st *node)
{
  printf(RED "\nError: variable already declared.\n" RESET);
  switch NODE_TYPE(node){
    case NT_VARDECL:
      printf(YELLOW " Variable: " RESET "'%s'" YELLOW  " of type %s has already been declared on line: %d and column: %d \n" RESET, VARDECL_NAME(node), typeToString(VARDECL_TYPE(node)), NODE_BLINE(node), NODE_BCOL(node));
      break;
    case NT_PARAM:
      printf(YELLOW " Variable: " RESET "'%s'" YELLOW  " of type %s has already been declared on line: %d and column: %d\n" RESET, PARAM_NAME(node), typeToString(PARAM_TYPE(node)), NODE_BLINE(node), NODE_BCOL(node));
      break;
    default:
    printf(YELLOW " No additional information provided.\n\n" RESET);
  }
  exit(EXIT_FAILURE);
}

//print function already declare.
void printFunctionSignatureDeclared(node_st *node)
{
  printf(RED "\nError: function signature already exist.\n" RESET);
  printf(YELLOW " Function: " RESET "'%s'" YELLOW  " of type %s has already been declared\n" RESET, FUNDEF_NAME(node), typeToString(FUNDEF_TYPE(node)));
  // printf(YELLOW " Exising signature: " RESET "%s %s", typeToString(FUNDEF_TYPE(node)), FUNDEF_NAME(node));
  exit(EXIT_FAILURE);
}

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
    
    Stackfree(data->symbol_table_stack_ptr, false);

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

    // printSymbolTableContent(t, false);

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

    if (!STinsertVar(t, GLOBDECL_NAME(node), GLOBDECL_TYPE(node)))
    {
      printVariableAlreadyDeclared(node);
    }

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

    if (!STinsertVar(t, GLOBDEF_NAME(node), GLOBDEF_TYPE(node)))
    {
      printVariableAlreadyDeclared(node);
    }

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

    if (!STinsertFunc(t, FUNDEF_NAME(node), FUNDEF_TYPE(node), create_params(node)))
    {
      printFunctionSignatureDeclared(node);
    }

    //create symbol table for own function and push onto stack
    stable_st *new_table = STnew(t);
    Stackpush(data->symbol_table_stack_ptr, new_table);

    //trav children will loop over params first and then the fun body
    TRAVchildren(node);

    //attaching as attribute
    FUNDEF_TABLE(node) = new_table;
    printf("Attached symbol table to fun def\n");

    // printSymbolTableContent(new_table, true);

    //pop current fun def scope from stack
    new_table = Stackpop(data->symbol_table_stack_ptr);

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

    if (!STinsertFunc(t, FUNDEC_NAME(node), FUNDEC_TYPE(node), create_params(node)))
    {
      printFunctionSignatureDeclared(node);
    }

    //create symbol table for own function and push onto stack
    stable_st *new_table = STnew(t);
	  Stackpush(data->symbol_table_stack_ptr, new_table);

	  TRAVchildren(node);

    //attaching as attribute
    FUNDEC_TABLE(node) = new_table;
    printf("Attached symbol table to fun def\n");

	  new_table = Stackpop(data->symbol_table_stack_ptr);
    
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

    if (!STinsertVar(t, PARAM_NAME(node), PARAM_TYPE(node)))
    {
      printVariableAlreadyDeclared(node);
    }

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

  if (!STinsertVar(t, VARDECL_NAME(node), VARDECL_TYPE(node)))
  {
    printVariableAlreadyDeclared(node);
  }

	TRAVchildren(node);
	return node;
}

/**
 * @fn BSTdowhile
 */
node_st *BSTdowhile(node_st *node)
{
//create empty symbol table that links to parent scope
  printf("\nTraversing do while\n");

  //get traversal data
  struct data_bst *data = DATA_BST_GET();

  //peek the current scope
  stable_st *t = StackPeek(data->symbol_table_stack_ptr);

  //create symbol table for own function and push onto stack
  stable_st *new_table = STnew(t);
  
	// Stackpush(data->symbol_table_stack_ptr, new_table);
  // printSymbolTableContent(new_table, true);

  //attaching as attribute
  DOWHILE_TABLE(node) = new_table;

  printf("Attached empty symbol table to do while\n");

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

  if (!STinsertVar(new_table, FOR_VAR(node), CT_int))
  {
    printVariableAlreadyDeclared(node);
  }

	//stack push new table
	Stackpush(data->symbol_table_stack_ptr, new_table);

  TRAVchildren(node);

	new_table = Stackpop(data->symbol_table_stack_ptr);

  //attaching as attribute
  FOR_TABLE(node) = new_table;

  printf("Attached symbol table to for loop\n");

  return node;
}

/**
 * @fn BSTifelse
 */
node_st *BSTifelse(node_st *node)
{
  //create empty symbol table that links to parent scope
  printf("\nTraversing if else\n");

  //get traversal data
  struct data_bst *data = DATA_BST_GET();

  //peek the current scope
  stable_st *t = StackPeek(data->symbol_table_stack_ptr);

  //create symbol table for own function and push onto stack
  stable_st *new_table = STnew(t);
  
	// Stackpush(data->symbol_table_stack_ptr, new_table);
//   printSymbolTableContent(new_table, true);

  //attaching as attribute
  IFELSE_TABLE(node) = new_table;

  printf("Attached empty symbol table to if else\n");

  TRAVchildren(node);

  return node;
}

/**
 * @fn BSTwhile
 */
node_st *BSTwhile(node_st *node)
{
  //create empty symbol table that links to parent scope
  printf("\nTraversing while\n");

  //get traversal data
  struct data_bst *data = DATA_BST_GET();

  //peek the current scope
  stable_st *t = StackPeek(data->symbol_table_stack_ptr);

  //create symbol table for own function and push onto stack
  stable_st *new_table = STnew(t);
  
	// Stackpush(data->symbol_table_stack_ptr, new_table);
  // printSymbolTableContent(new_table, true);

  //attaching as attribute
  WHILE_TABLE(node) = new_table;

  printf("Attached empty symbol table to while\n");

  TRAVchildren(node);
  return node;
}