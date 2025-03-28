/**
 * @file
 *
 * Traversal: ClearSymbolTables
 * UID      : CST
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>

void clear_node(node_st *node);

void clear_node(node_st *node){
	// printf("Freeing up table for node\n");
  switch NODE_TYPE(node){
    case NT_PROGRAM:
			// printf("Program\n");
			STfree(PROGRAM_TABLE(node));
      break;
		case NT_IFELSE:
			// printf("If else\n");
			STfree(IFELSE_TABLE(node));
			break;
		case NT_WHILE:
			// printf("While\n");
			STfree(WHILE_TABLE(node));
			break;
		case NT_DOWHILE:
			// printf("Do While\n");
			STfree(DOWHILE_TABLE(node));
			break;
		case NT_FOR:
			// printf("For\n");
			STfree(FOR_TABLE(node));
			break;
    case NT_GLOBDEF:
			// GLOBDEF_TABLE(node) = NULL;
			// printf("Globdef\n");
			// STfree(GLOBDEF_TABLE(node));
      break;
    case NT_GLOBDECL:
			// printf("Globdecl\n");
			STfree(GLOBDECL_TABLE(node));
      break;
		case NT_FUNDEF:
			// printf("Fundef\n");
			STfree(FUNDEF_TABLE(node));
			break;
		case NT_FUNDEC:
			// printf("Fundec\n");
			STfree(FUNDEC_TABLE(node));
			break;
    default:
			// printf("Unsupported\n");
			return;
  }
}

//used to create the stack
void CSTinit()
{
  // printf("\n\nCleaning symbol table traversal data\n");
  return;
}

//used for cleanup
void CSTfini()
{
  // printf("\n\nCleared symbol table traversal data\n");
  return;
}

/**
 * @fn CSTprogram
 */
node_st *CSTprogram(node_st *node)
{
  clear_node(node);
	TRAVchildren(node);
  return node;
}

/**
 * @fn CSTfundef
 */
node_st *CSTfundef(node_st *node)
{
  clear_node(node);
	TRAVchildren(node);
  return node;
}

/**
 * @fn CSTdowhile
 */
node_st *CSTdowhile(node_st *node)
{
  clear_node(node);
	TRAVchildren(node);
  return node;
}

/**
 * @fn CSTfor
 */
node_st *CSTfor(node_st *node)
{
  clear_node(node);
	TRAVchildren(node);
  return node;
}

/**
 * @fn CSTfundec
 */
node_st *CSTfundec(node_st *node)
{
  clear_node(node);
	TRAVchildren(node);
  return node;
}

/**
 * @fn CSTifelse
 */
node_st *CSTifelse(node_st *node)
{
  clear_node(node);
	TRAVchildren(node);
  return node;
}

/**
 * @fn CSTglobdecl
 */
node_st *CSTglobdecl(node_st *node)
{
  	clear_node(node);
	TRAVchildren(node);
  return node;
}

/**
 * @fn CSTglobdef
 */
node_st *CSTglobdef(node_st *node)
{
	clear_node(node);
	TRAVchildren(node);
  return node;
}

/**
 * @fn CSTwhile
 */
node_st *CSTwhile(node_st *node)
{
  clear_node(node);
	TRAVchildren(node);
  return node;
}

