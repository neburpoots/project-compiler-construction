/**
 * @file
 *
 * Traversal: TransformBooleanCasts
 * UID      : TBC
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include "ccngen/enum.h"

const char *type_to_str(enum Type type);
void print_cast_debug(enum Type src, enum Type target, const char *transformation);

void TBCinit()
{
  printf("\n\nStart boolean transformation traversal\n\n");
  return;
}

//used for cleanup
void TBCfini()
{
  printf("\n\finished boolean transformation traversal\n\n");
  return;
}

const char *type_to_str(enum Type type) {
  switch (type) {
      case CT_int: return "int";
      case CT_float: return "float";
      case CT_bool: return "bool";
      case CT_void: return "void";
      case CT_array: return "array";
      default: return "unknown";
  }
}

void print_cast_debug(enum Type src, enum Type target, const char *transformation) {
  printf("Transforming cast: (%s -> %s) ➔ %s\n", type_to_str(src), type_to_str(target), transformation);
}

/**
 * @fn TBCcast
 */
node_st *TBCcast(node_st *node) {
  printf("\n\nCAST\n\n");
  TRAVchildren(node);

  //get the source and target type
  enum Type target_type = CAST_TYPE(node);
  node_st *expr = CAST_EXPR(node);
  enum Type source_type = TYPED_TYPE(expr);

  printf("%s -> %s", type_to_str(source_type), type_to_str(target_type));

  //bool to int or flaot
  if (source_type == CT_bool && (target_type == CT_int || target_type == CT_float)) {
      print_cast_debug(source_type, target_type, "Conditional expression");
      node_st *true_val = (target_type == CT_int) ? ASTnum(1) : ASTfloat(1.0);
      node_st *false_val = (target_type == CT_int) ? ASTnum(0) : ASTfloat(0.0);
      node_st *cond_expr = ASTcondexpr(expr, true_val, false_val, target_type);

      printf("  Created CondExpr: ");
      printf("if %s then %s else %s\n",
             type_to_str(source_type),
             type_to_str(TYPED_TYPE(true_val)),
             type_to_str(TYPED_TYPE(false_val)));

      CCNfree(node);
      return cond_expr;
  }

  //int or float to bool
  if ((source_type == CT_int || source_type == CT_float) && target_type == CT_bool) {
      print_cast_debug(source_type, target_type, "Inequality comparison");
      node_st *zero = (source_type == CT_int) ? ASTnum(0) : ASTfloat(0.0);
      node_st *comparison = ASTbinop(expr, zero, BO_ne);
      BINOP_TYPE(comparison) = CT_bool;

      printf("  Created Binop: %s != %s\n",
        type_to_str(source_type),
        type_to_str(TYPED_TYPE(zero)));

      CCNfree(node);
      return comparison;
  }

  return node;
}