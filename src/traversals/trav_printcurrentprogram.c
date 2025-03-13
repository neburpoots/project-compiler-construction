/**
 * @file
 *
 * Traversal: PrintCurrentProgram
 * UID      : PCP
 *
 *
 */

 #include "ccn/ccn.h"
 #include "ccngen/ast.h"
 #include "ccngen/trav.h"
 
 #include <stdio.h>
 #include <string.h>
 
 // Helper function to print indentation
 static int indent_level = 0;
 
 static void print_indent() {
     for (int i = 0; i < indent_level; i++) {
         printf("    ");
     }
 }
 
//  static const char* typeToString(Type type) {
//      switch (type) {
//          case CT_int: return "int";
//          case CT_float: return "float";
//          case CT_bool: return "bool";
//          case CT_void: return "void";
//          case CT_array: return "array";
//          default: return "unknown_type";
//      }
//  }
 
 /**
  * @fn PCPprogram
  */
 node_st *PCPprogram(node_st *node)
 {
     printf("\n");
     printf("Printing current Program ----------------------\n\n");
 
     if (PROGRAM_DECLS(node)) {
         TRAVdecls(node);
     }
 
     printf("End of program ----------------------\n\n");
 
     return node;
 }
 
 /**
  * @fn PCPfundef
  */
 node_st *PCPfundef(node_st *node)
 {
     printf("\n");
     if (FUNDEF_EXPORT(node)) {
         printf("export ");
     }
     
     printf("%s %s(", typeToString(FUNDEF_TYPE(node)), FUNDEF_NAME(node));
     
     if (FUNDEF_PARAMS(node)) {
         TRAVparams(node);
     }
     
     printf(") ");
     
     // Check if body exists before traversing
     if (FUNDEF_BODY(node)) {
         TRAVbody(node);
     } else {
         printf("{ /* No body defined */ }\n");
     }
     
     return node;
 }
 
 /**
  * @fn PCPfunbody
  */
 node_st *PCPfunbody(node_st *node)
 {
     printf("{\n");
     indent_level++;
     
     if (FUNBODY_FUNCONTENTS(node)) {
         TRAVfunContents(node);
     }
     
     indent_level--;
     print_indent();
     printf("}\n");
     
     return node;
 }
 
 /**
  * @fn PCPfunContents
  */
 node_st *PCPfuncontents(node_st *node)
 {
     if (node == NULL) {
         return node;
     }
     
     if (FUNCONTENTS_FUNCONTENT(node)) {
         TRAVfunContent(node);
     }
     
     if (FUNCONTENTS_NEXT(node)) {
         TRAVnext(node);
     }
     
     return node;
 }
 
 /**
  * @fn PCPdowhile
  */
 node_st *PCPdowhile(node_st *node)
 {
     print_indent();
     printf("do {\n");
     
     indent_level++;
     if (DOWHILE_BLOCK(node)) {
         TRAVblock(DOWHILE_BLOCK(node));
     }
     indent_level--;
     
     print_indent();
     printf("} while (");
     if (DOWHILE_COND(node)) {
         TRAVcond(DOWHILE_COND(node));
     }
     printf(");\n");
     
     return node;
 }
 
 /**
  * @fn PCPassign
  */
 node_st *PCPassign(node_st *node)
 {
     print_indent();
     if (ASSIGN_LET(node)) {
         TRAVlet(node);
     }
     printf(" = ");
     if (ASSIGN_EXPR(node)) {
         TRAVexpr(node);
     }
     printf(";\n");
 
     return node;
 }
 
 /**
  * @fn PCParrexpr
  */
 node_st *PCParrexpr(node_st *node)
 {
     printf("[");
     
     if (ARREXPR_EXPRS(node)) {
         TRAVexprs(node);
     }
     
     printf("]");
     
     if (ARREXPR_INDICES(node)) {
         printf("[");
         TRAVindices(node);
         printf("]");
     }
     
     return node;
 }
 
 /**
  * @fn PCPbinop
  */
 node_st *PCPbinop(node_st *node)
 {
     char *op = NULL;
     printf("(");
 
     if (BINOP_LEFT(node)) {
         TRAVleft(node);
     }
 
     switch (BINOP_OP(node)) {
     case BO_add: op = "+"; break;
     case BO_sub: op = "-"; break;
     case BO_mul: op = "*"; break;
     case BO_div: op = "/"; break;
     case BO_mod: op = "%"; break;
     case BO_lt:  op = "<"; break;
     case BO_le:  op = "<="; break;
     case BO_gt:  op = ">"; break;
     case BO_ge:  op = ">="; break;
     case BO_eq:  op = "=="; break;
     case BO_ne:  op = "!="; break;
     case BO_or:  op = "||"; break;
     case BO_and: op = "&&"; break;
     default: op = "?"; break;
     }
 
     printf(" %s ", op);
 
     if (BINOP_RIGHT(node)) {
         TRAVright(node);
     }
 
     printf(")");
 
     return node;
 }
 
 /**
  * @fn PCPcast
  */
 node_st *PCPcast(node_st *node)
 {
     printf("(%s)(", typeToString(CAST_TYPE(node)));
     if (CAST_EXPR(node)) {
         TRAVexpr(node);
     }
     printf(")");
     
     return node;
 }
 
 /**
  * @fn PCPfor
  */
 node_st *PCPfor(node_st *node)
 {
     print_indent();
     printf("for (%s = ", FOR_VAR(node));
     
     if (FOR_START_EXPR(node)) {
         TRAVstart_expr(node);
     }
     
     printf("; %s < ", FOR_VAR(node));
     
     if (FOR_STOP(node)) {
         TRAVstop(node);
     }
     
     printf("; %s = %s + ", FOR_VAR(node), FOR_VAR(node));
     
     if (FOR_STEP(node)) {
         TRAVstep(node);
     } else {
         printf("1");
     }
     
     printf(") {\n");
     
     indent_level++;
     if (FOR_BLOCK(node)) {
         TRAVblock(node);
     }
     indent_level--;
     
     print_indent();
     printf("}\n");
     
     return node;
 }
 
 /**
  * @fn PCPexprs
  */
 node_st *PCPexprs(node_st *node)
 {
     if (node == NULL) {
         return node;
     }
     
     if (EXPRS_EXPR(node)) {
         TRAVexpr(node);
     }
     
     if (EXPRS_NEXT(node)) {
         printf(", ");
         TRAVnext(node);
     }
     
     return node;
 }
 
 /**
  * @fn PCPexprstmt
  */
 node_st *PCPexprstmt(node_st *node)
 {
     print_indent();
     if (EXPRSTMT_EXPR(node)) {
         TRAVexpr(node);
     }
     printf(";\n");
     
     return node;
 }
 
 /**
  * @fn PCPfundec
  */
 node_st *PCPfundec(node_st *node)
 {
     printf("extern %s %s(", typeToString(FUNDEC_TYPE(node)), FUNDEC_NAME(node));
     
     if (FUNDEC_PARAMS(node)) {
         TRAVparams(node);
     }
     
     printf(");\n");
     
     return node;
 }
 
 /**
  * @fn PCPfuncall
  */
 node_st *PCPfuncall(node_st *node)
 {
     printf("%s(", FUNCALL_NAME(node));
     
     if (FUNCALL_FUN_ARGS(node)) {
         TRAVfun_args(node);
     }
     
     printf(")");
     
     return node;
 }
 
 /**
  * @fn PCPifelse
  */
 node_st *PCPifelse(node_st *node)
 {
     print_indent();
     printf("if (");
     
     if (IFELSE_COND(node)) {
         TRAVcond(node);
     }
     
     printf(") {\n");
     
     indent_level++;
     if (IFELSE_THEN(node)) {
         TRAVthen(node);
     }
     indent_level--;
     
     print_indent();
     printf("}");
     
     if (IFELSE_ELSE_BLOCK(node)) {
         printf(" else {\n");
         
         indent_level++;
         TRAVelse_block(node);
         indent_level--;
         
         print_indent();
         printf("}");
     }
     
     printf("\n");
     
     return node;
 }
 
 /**
  * @fn PCPglobdecl
  */
 node_st *PCPglobdecl(node_st *node)
 {
     printf("extern %s %s", typeToString(GLOBDECL_TYPE(node)), GLOBDECL_NAME(node));
     
     if (GLOBDECL_DIMS(node)) {
         printf("[");
         TRAVdims(node);
         printf("]");
     }
     
     printf(";\n");
     
     return node;
 }
 
 /**
  * @fn PCPglobdef
  */
 node_st *PCPglobdef(node_st *node)
 {
     if (GLOBDEF_EXPORT(node)) {
         printf("export ");
     }
     
     printf("%s %s", typeToString(GLOBDEF_TYPE(node)), GLOBDEF_NAME(node));
     
     if (GLOBDEF_DIMS(node)) {
         printf("[");
         TRAVdims(node);
         printf("]");
     }
     
     if (GLOBDEF_INIT(node)) {
         printf(" = ");
         TRAVinit(node);
     }
     
     printf(";\n");
     
     return node;
 }
 
 /**
  * @fn PCPids
  */
 node_st *PCPids(node_st *node)
 {
     if (node == NULL) {
         return node;
     }
     
     printf("%s", IDS_NAME(node));
     
     if (IDS_NEXT(node)) {
         printf(", ");
         TRAVnext(node);
     }
     
     return node;
 }
 
 /**
  * @fn PCPparam
  */
 node_st *PCPparam(node_st *node)
 {
     if (node == NULL) {
         return node;
     }
     
     printf("%s %s", typeToString(PARAM_TYPE(node)), PARAM_NAME(node));
     
     if (PARAM_DIMS(node)) {
         printf("[");
         TRAVdims(node);
         printf("]");
     }
     
     if (PARAM_NEXT(node)) {
         printf(", ");
         TRAVnext(node);
     }
     
     return node;
 }
 
 /**
  * @fn PCPmonop
  */
 node_st *PCPmonop(node_st *node)
 {
     switch (MONOP_OP(node)) {
     case MO_not:
         printf("!");
         break;
     case MO_neg:
         printf("-");
         break;
     default:
         printf("?");
         break;
     }
     
     if (MONOP_OPERAND(node)) {
         TRAVoperand(node);
     }
     
     return node;
 }
 
 /**
  * @fn PCPfloat
  */
 node_st *PCPfloat(node_st *node)
 {
     printf("%f", FLOAT_VAL(node));
     return node;
 }
 
 /**
  * @fn PCPbool
  */
 node_st *PCPbool(node_st *node)
 {
     printf("%s", BOOL_VAL(node) ? "true" : "false");
     return node;
 }
 
 /**
  * @fn PCPnum
  */
 node_st *PCPnum(node_st *node)
 {
     printf("%d", NUM_VAL(node));
     return node;
 }
 
 /**
  * @fn PCPvarlet
  */
 node_st *PCPvarlet(node_st *node)
 {
     printf("%s", VARLET_NAME(node));
     
     if (VARLET_INDICES(node)) {
         printf("[");
         TRAVindices(node);
         printf("]");
     }
     
     return node;
 }
 
 /**
  * @fn PCPwhile
  */
 node_st *PCPwhile(node_st *node)
 {
     print_indent();
     printf("while (");
     
     if (WHILE_COND(node)) {
         TRAVcond(node);
     }
     
     printf(") {\n");
     
     indent_level++;
     if (WHILE_BLOCK(node)) {
         TRAVblock(node);
     }
     indent_level--;
     
     print_indent();
     printf("}\n");
     
     return node;
 }
 
 /**
  * @fn PCPvardecl
  */
 node_st *PCPvardecl(node_st *node)
 {
     print_indent();
     printf("%s %s", typeToString(VARDECL_TYPE(node)), VARDECL_NAME(node));
     
     if (VARDECL_DIMS(node)) {
         printf("[");
         TRAVdims(node);
         printf("]");
     }
     
     if (VARDECL_INIT(node)) {
         printf(" = ");
         TRAVinit(node);
     }
     
     printf(";\n");
     
     return node;
 }
 
 /**
  * @fn PCPvar
  */
 node_st *PCPvar(node_st *node)
 {
     printf("%s", VAR_NAME(node));
     
     if (VAR_INDICES(node)) {
         printf("[");
         TRAVindices(node);
         printf("]");
     }
     
     return node;
 }
 
 /**
  * @fn PCPreturn
  */
 node_st *PCPreturn(node_st *node)
 {
     print_indent();
     printf("return");
     
     if (RETURN_EXPR(node)) {
         printf(" ");
         TRAVexpr(node);
     }
     
     printf(";\n");
     
     return node;
 }
 
 /**
  * @fn PCPstmts
  */
 node_st *PCPstmts(node_st *node)
 {
     if (node == NULL) {
         return node;
     }
     
     if (STMTS_STMT(node)) {
         TRAVstmt(node);
     }
     
     if (STMTS_NEXT(node)) {
         TRAVnext(node);
     }
     
     return node;
 }
 
 /**
  * @fn PCPdecls
  */
 node_st *PCPdecls(node_st *node)
 {
     if (node == NULL) {
         return node;
     }
     
     if (DECLS_DECL(node)) {
         TRAVdecl(node);
     }
     
     if (DECLS_NEXT(node)) {
         TRAVnext(node);
     }
     
     return node;
 }