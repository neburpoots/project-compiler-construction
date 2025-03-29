/**
 * @file
 *
 * Traversal: MoveInitLoopVariable
 * UID      : ML
 *
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"

void MLinit() {
  struct data_ml *data = DATA_ML_GET();

  data->vardecls = GStackNew(100);
}

void MLfini() {
  struct data_ml *data = DATA_ML_GET();

  if (data->vardecls != NULL) {
    while (!GStackIsEmpty(data->vardecls)) {
      node_st *node = GStackPop(data->vardecls);
      CCNfree(node);
    }

    GStackFree(data->vardecls, NULL);
    data->vardecls = NULL;
  }
}

const char *node_to_type_string(node_st *node) {
  switch (NODE_TYPE(node)) {
  case NT_NULL:
    return "NT_NULL";
  case NT_BOOL:
    return "NT_BOOL";
  case NT_FLOAT:
    return "NT_FLOAT";
  case NT_NUM:
    return "NT_NUM";
  case NT_VAR:
    return "NT_VAR";
  case NT_VARLET:
    return "NT_VARLET";
  case NT_MONOP:
    return "NT_MONOP";
  case NT_BINOP:
    return "NT_BINOP";
  case NT_ASSIGN:
    return "NT_ASSIGN";
  case NT_FUNCONTENTS:
    return "NT_FUNCONTENTS";
  case NT_STMTS:
    return "NT_STMTS";
  case NT_VARDECL:
    return "NT_VARDECL";
  case NT_VARDECLS:
    return "NT_VARDECLS";
  case NT_PARAM:
    return "NT_PARAM";
  case NT_GLOBDEF:
    return "NT_GLOBDEF";
  case NT_FUNDEC:
    return "NT_FUNDEC";
  case NT_GLOBDECL:
    return "NT_GLOBDECL";
  case NT_FOR:
    return "NT_FOR";
  case NT_DOWHILE:
    return "NT_DOWHILE";
  case NT_WHILE:
    return "NT_WHILE";
  case NT_IFELSE:
    return "NT_IFELSE";
  case NT_FUNBODY:
    return "NT_FUNBODY";
  case NT_FUNDEF:
    return "NT_FUNDEF";
  case NT_FUNDEFS:
    return "NT_FUNDEFS";
  case NT_CAST:
    return "NT_CAST";
  case NT_FUNCALL:
    return "NT_FUNCALL";
  case NT_RETURN:
    return "NT_RETURN";
  case NT_EXPRSTMT:
    return "NT_EXPRSTMT";
  case NT_IDS:
    return "NT_IDS";
  case NT_ARREXPR:
    return "NT_ARREXPR";
  case NT_EXPRS:
    return "NT_EXPRS";
  case NT_DECLS:
    return "NT_DECLS";
  case NT_PROGRAM:
    return "NT_PROGRAM";
  case _NT_SIZE:
    return "_NT_SIZE";
  default:
    return "UNKNOWN_NODETYPE";
  }
}

/**
 * @fn MLfor
 */
node_st *MLfor(node_st *node) {
  struct data_ml *data = DATA_ML_GET();

    // Convert the start expression of the for loop to an assignment
    // if the start expression is a variable declaration
  node_st *start_expr = FOR_START_EXPR(node);

    // Create vardecl
  node_st *var_decl = ASTvardecl(NULL, NULL, strdup(FOR_VAR(node)), CT_int);


  GStackPush(data->vardecls, var_decl);


  TRAVchildren(node);
  return node;
}

/**
 * @fn MLfundef
 */
node_st *MLfundef(node_st *node) {
  struct data_ml *data = DATA_ML_GET();

  stack_stptr *parent = data->current_symbol_table_stack_ptr;

  data->current_symbol_table_stack_ptr = FUNDEF_TABLE(node);

  TRAVchildren(node);

  node_st *fun_body = FUNDEF_BODY(node);

  while (!GStackIsEmpty(data->vardecls)) {
    node_st *decl = GStackPopTail(data->vardecls);
    node_st *decls = FUNBODY_FUNCONTENTS(fun_body);
        // Add the variable declaration to the function body
    FUNBODY_FUNCONTENTS(fun_body) = ASTfuncontents(decl, decls);
  }

  data->current_symbol_table_stack_ptr = parent;

  return node;
}
