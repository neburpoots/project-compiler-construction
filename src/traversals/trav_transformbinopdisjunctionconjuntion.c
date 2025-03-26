/**
 * @file
 *
 * Traversal: TransformBinopDisjunctionConjuntion
 * UID      : TBDC
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include "ccngen/enum.h"

const char *binop_to_str(enum BinOpType op);
void print_indent(int level);

void TBDCinit()
{
  printf("\n\nStart conjunction/disjunction traversal\n\n");
  return;
}

//used for cleanup
void TBDCfini()
{
  printf("\n\finished conjunction/disjunction traversal\n\n");
  return;
}

const char *binop_to_str(enum BinOpType op) {
  switch (op) {
      case BO_and: return "&&";
      case BO_or: return "||";
      case BO_eq: return "==";
      case BO_ne: return "!=";
      case BO_lt: return "<";
      case BO_le: return "<=";
      case BO_gt: return ">";
      case BO_ge: return ">=";
      case BO_add: return "+";
      case BO_sub: return "-";
      case BO_mul: return "*";
      case BO_div: return "/";
      case BO_mod: return "%";
      default: return "?";
  }
}

void print_indent(int level) {
  for (int i = 0; i < level; i++) {
      printf("    ");
  }
}

void print_expr(node_st *node, int indent_level) {
  if (!node) return;

  switch (NODE_TYPE(node)) {
      case NT_BINOP: {
          enum BinOpType op = BINOP_OP(node);
          printf("Binop(");
          print_expr(BINOP_LEFT(node), indent_level);
          printf(" %s ", binop_to_str(op));
          print_expr(BINOP_RIGHT(node), indent_level);
          printf(")");
          break;
      }
      case NT_CONDEXPR: {
          printf("CondExpr(\n");
          print_indent(indent_level + 1);
          printf("cond: ");
          print_expr(CONDEXPR_COND(node), indent_level + 1);
          printf(",\n");
          print_indent(indent_level + 1);
          printf("then: ");
          print_expr(CONDEXPR_THEN_EXPR(node), indent_level + 1);
          printf(",\n");
          print_indent(indent_level + 1);
          printf("else: ");
          print_expr(CONDEXPR_ELSE_EXPR(node), indent_level + 1);
          printf("\n");
          print_indent(indent_level);
          printf(")");
          break;
      }
      case NT_VAR:
          printf("%s", VAR_NAME(node));
          break;
      case NT_NUM:
          printf("%d", NUM_VAL(node));
          break;
      case NT_BOOL:
          printf("Bool(%s)", BOOL_VAL(node) ? "true" : "false");
          break;
      default:
          printf("<UnhandledNode>");
          break;
  }
}


/**
 * @fn TBDCbinop
 */
node_st *TBDCbinop(node_st *node) {
  TRAVchildren(node);
  enum BinOpType op = BINOP_OP(node);

  //act if the operator is a and, or or
  if (op == BO_and || op == BO_or) {
      node_st *left = BINOP_LEFT(node);
      node_st *right = BINOP_RIGHT(node);
      enum Type original_type = BINOP_TYPE(node);

      //create new expression
      node_st *then_expr = (op == BO_and) ? right : ASTbool(true);
      node_st *else_expr = (op == BO_and) ? ASTbool(false) : right;
      node_st *cond_expr = ASTcondexpr(left, then_expr, else_expr, original_type);

      //test print the new CondExpr
      printf("\nTransformed Binop to CondExpr:\n");
      print_expr(cond_expr, 0);
      printf("\n\n");

      //detach children to prevetn double free
      BINOP_LEFT(node) = NULL;
      BINOP_RIGHT(node) = NULL;

      //free the original Binop node
      CCNfree(node);

      return cond_expr;
  }
  return node;
}
