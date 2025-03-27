/**
 * @file
 *
 * Traversal: TransformBooleanCasts
 * UID      : TBC
 */

 #include "ccn/ccn.h"
 #include "ccngen/ast.h"
 #include "ccngen/trav.h"
 #include <stdio.h>
 #include "ccngen/enum.h"

 //create a numeric zero value based on type
 node_st *create_zero(enum Type type) {
     switch (type) {
         case CT_int: return ASTnum(0);
         case CT_float: return ASTfloat(0.0);
         default: return NULL;
     }
 }

 //create a numeric one value based on type
 node_st *create_one(enum Type type) {
     switch (type) {
         case CT_int: return ASTnum(1);
         case CT_float: return ASTfloat(1.0);
         default: return NULL;
     }
 }

 /**
  * @fn TBCcast
  */
 /**
 * @fn TBCcast
 */
node_st *TBCcast(node_st *node) {
  TRAVchildren(node);

  enum Type target_type = CAST_TYPE(node);
  node_st *expr = CAST_EXPR(node);
  enum Type source_type = EXPR_TYPE(expr);

  printf("Target type %s and source %s\n", typeToString(target_type), typeToString(source_type));

  //check if bool casst
  if (source_type != CT_bool && target_type != CT_bool) {
    return node;
  }

  //bool to number
  if (source_type == CT_bool && (target_type == CT_int || target_type == CT_float)) {
    node_st *true_val = create_one(target_type);
    node_st *false_val = create_zero(target_type);

    //set node to null so no double free used
    CAST_EXPR(node) = NULL;

    node_st *cond_expr = ASTcondexpr(expr, true_val, false_val, target_type);
    CCNfree(node);
    return cond_expr;
  }

  //num to bool
  if (target_type == CT_bool && (source_type == CT_int || source_type == CT_float)) {
    node_st *zero = create_zero(source_type);
    node_st *neq = ASTbinop(expr, zero, BO_ne);

    CAST_EXPR(node) = NULL;

    node_st *true_val = ASTbool(true);
    node_st *false_val = ASTbool(false);
    node_st *cond_expr = ASTcondexpr(neq, true_val, false_val, CT_bool);
    CCNfree(node);
    return cond_expr;

  }

  return node;
}