%{


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "palm/memory.h"
#include "palm/ctinfo.h"
#include "palm/dbug.h"
#include "palm/str.h"
#include "ccngen/ast.h"
#include "ccngen/enum.h"
#include "global/globals.h"

static node_st *parseresult = NULL;
extern int yylex();
int yyerror(char *errname);
extern FILE *yyin;
void AddLocToNode(node_st *node, void *begin_loc, void *end_loc);


%}

%union {
 char               *id;
 int                 cint;
 float               cflt;
 enum BinOpType     cbinop;
 enum Type           ctype;
 node_st             *node;
}

%locations

%token BRACKET_L BRACKET_R COMMA SEMICOLON CURLY_L CURLY_R SQUARE_L SQUARE_R
%token MINUS PLUS STAR SLASH PERCENT LE LT GE GT EQ NE OR AND
%token TRUEVAL FALSEVAL LET


// %token 

%token <cint> NUM
%token <cflt> FLOAT
%token <id> ID

// Functions
%token EXPORT RETURN
%type <node> fundef funbody param var_decl return_stmt

%type <node> intval floatval boolval constant expr
%type <node> stmts stmt assign varlet program
%type <cbinop> binop

// enum Type 
%token TYPE_INT TYPE_FLOAT TYPE_BOOL TYPE_VOID
%type <ctype> type

// %token IF ELSE
%token IF ELSE
%type <node> if_stmt

// token while
%token WHILE
%type <node> while_stmt

%token EXTERN
%type <node> decls decl glob_decl glob_def

%start program

%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left STAR SLASH PERCENT
// %right NOT

%%

program: decls
         {
           parseresult = ASTprogram($1);
         }
         ;

decls: decl decls
        {
          $$ = ASTdecls($1, $2);
        }
      | decl
        {
          $$ = ASTdecls($1, NULL);
        }
        ;

//TODO VRAGEN
//WAAROM GEEN FunDec optie in nodeset DECL vanuit coconut
//nodeset Decl = {GlobDef, GlobDecl, FunDef};

decl: glob_decl
      {
        $$ = $1;
      }
    | fundef
      {
        $$ = $1;
      }
    |
      glob_def
      {
        $$ = $1;
      }
    ;

glob_decl: EXTERN type ID SEMICOLON
           {
             $$ = ASTglobdecl($3, $2);
           }
        ;

glob_def: EXPORT type ID LET expr SEMICOLON
        {
          $$ = ASTglobdef($5, $3, $2, true);
        }
        | type ID LET expr SEMICOLON
        {
          $$ = ASTglobdef($4, $2, $1, false);
        }
        | EXPORT type ID SEMICOLON
        {
          $$ = ASTglobdef(NULL, $3, $2, true);
        }
        | type ID SEMICOLON
        {
          $$ = ASTglobdef(NULL, $2, $1, true);
        }          
        ;

stmts: stmt stmts
        {
          $$ = ASTstmts($1, $2);
        }
      | stmt
        {
          $$ = ASTstmts($1, NULL);
        }
        ;

// exprs: expr exprs
    

stmt: assign
       {
         $$ = $1;
       }
      |
      if_stmt
      {
        $$ = $1;
      }
      |
      while_stmt
      {
        $$ = $1;
      }
      ; 

// fundec: EXTERN type ID BRACKET_L param BRACKET_R SEMICOLON
//       {
        
//       }

fundef: EXPORT type ID BRACKET_L param BRACKET_R funbody
        {
          $$ = ASTfundef($7, $5, $3, $2, true); // Exported function
        }
      | EXPORT type ID BRACKET_L BRACKET_R funbody
        {
          $$ = ASTfundef($6, NULL, $3, $2, true);
        }
      | type ID BRACKET_L param BRACKET_R funbody
        {
          $$ = ASTfundef($6, $4, $2, $1, false); // Non-exported function
        }
      | type ID BRACKET_L BRACKET_R funbody
        {
          $$ = ASTfundef($5, NULL, $2, $1, false);
        }
      ;

funbody: CURLY_L var_decl stmts return_stmt CURLY_R
         {
           $$ = ASTfunbody($2, NULL, ASTstmts($3, $4));
         }
       | CURLY_L stmts return_stmt CURLY_R
         {
           $$ = ASTfunbody(NULL, NULL, ASTstmts($2, $3));
         }
       | CURLY_L var_decl stmts CURLY_R
         {
           $$ = ASTfunbody($2, NULL, $3);
         }
       | CURLY_L CURLY_R
         {
           $$ = ASTfunbody(NULL, NULL, NULL);
         }
       | CURLY_L var_decl CURLY_R
         {
           $$ = ASTfunbody($2, NULL, NULL);
         }

       | CURLY_L stmts CURLY_R
         {
           $$ = ASTfunbody(NULL, NULL, $2);
         }
        // | CURLY_L var_decl fundefs stmts return_stmt CURLY_R
        //     {
        //         $$ = ASTfunbody($2, $3, ASTstmts($4, $5));
        //     }
        // | CURLY_L fundefs stmts return_stmt CURLY_R
        //     {
        //         $$ = ASTfunbody(NULL, $2, ASTstmts($3, $4));
        //     }
        // | CURLY_L var_decl fundefs stmts CURLY_R
        //     {
        //         $$ = ASTfunbody($2, $3, ASTstmts($4, NULL));
        //     }
       ;

// var_decls: var_decl var_decls
//            {
//              $$ = ASTvardecls($1, $2);
//            }
//          | var_decl
//            {
//              $$ = ASTvardecls($1, NULL);
//            }
//          ;

//TODO Handle Arrays
var_decl: type ID SEMICOLON
         {
           $$ = ASTvardecl(NULL, NULL, $2, $1);
         }
       | type ID LET expr SEMICOLON
         {
           $$ = ASTvardecl($4, NULL, $2, $1);
         }
       | type ID LET expr SEMICOLON var_decl
         {
           $$ = ASTvardecl($4, $6, $2, $1);
         }
       ;

assign: varlet LET expr SEMICOLON
        {
          $$ = ASTassign($1, $3);
        }
        ;

return_stmt: RETURN expr SEMICOLON
            {
              $$ = ASTreturn($2);
            }
          | RETURN SEMICOLON
            {
              $$ = ASTreturn(NULL);
            }
          ;

if_stmt: IF expr CURLY_L stmts CURLY_R ELSE CURLY_L stmts CURLY_R
        {
          $$ = ASTifelse($2, $4, $8);
        }
      | IF expr CURLY_L stmts CURLY_R
        {
          $$ = ASTifelse($2, $4, NULL);
        }
      ;

while_stmt: WHILE expr CURLY_L stmts CURLY_R
        {
          $$ = ASTwhile($2, $4);
        }
        |

        // Disallow empty while block???
        WHILE expr CURLY_L CURLY_R
        {
          $$ = ASTwhile($2, NULL);
        };



param: type ID
        {
          $$ = ASTparam(NULL, $2, $1);
        }
      |
        type ID COMMA param
        {
          $$ = ASTparam($4, $2, $1);
        }
      ;


varlet: ID
        {
          $$ = ASTvarlet($1);
          AddLocToNode($$, &@1, &@1);
        }
        ;


expr: constant
      {
        $$ = $1;
      }
    | ID
      {
        $$ = ASTvar($1);
      }
    | BRACKET_L expr[left] binop[type] expr[right] BRACKET_R
      {
        $$ = ASTbinop( $left, $right, $type);
        AddLocToNode($$, &@left, &@right);
      }

    | expr[left] binop[type] expr[right]
      {
        $$ = ASTbinop( $left, $right, $type);
        AddLocToNode($$, &@left, &@right);
      }
    ;
 
constant: floatval
          {
            $$ = $1;
          }
        | intval
          {
            $$ = $1;
          }
        | boolval
          {
            $$ = $1;
          }
        ;

type: TYPE_INT   { $$ = CT_int; }
    | TYPE_FLOAT { $$ = CT_float; }
    | TYPE_BOOL  { $$ = CT_bool; }
    | TYPE_VOID  { $$ = CT_void; }

floatval: FLOAT
           {
             $$ = ASTfloat($1);
           }
         ;

intval: NUM
        {
          $$ = ASTnum($1);
        }
      ;

boolval: TRUEVAL
         {
           $$ = ASTbool(true);
         }
       | FALSEVAL
         {
           $$ = ASTbool(false);
         }
       ;

binop: PLUS      { $$ = BO_add; }
     | MINUS     { $$ = BO_sub; }
     | STAR      { $$ = BO_mul; }
     | SLASH     { $$ = BO_div; }
     | PERCENT   { $$ = BO_mod; }
     | LE        { $$ = BO_le; }
     | LT        { $$ = BO_lt; }
     | GE        { $$ = BO_ge; }
     | GT        { $$ = BO_gt; }
     | EQ        { $$ = BO_eq; }
     | OR        { $$ = BO_or; }
     | AND       { $$ = BO_and; }
     ;

%%

void AddLocToNode(node_st *node, void *begin_loc, void *end_loc)
{
    // Needed because YYLTYPE unpacks later than top-level decl.
    YYLTYPE *loc_b = (YYLTYPE*)begin_loc;
    YYLTYPE *loc_e = (YYLTYPE*)end_loc;
    NODE_BLINE(node) = loc_b->first_line;
    NODE_BCOL(node) = loc_b->first_column;
    NODE_ELINE(node) = loc_e->last_line;
    NODE_ECOL(node) = loc_e->last_column;
}

//21-2-2025 Ruben Edited it plus 1 for vs code actual line
// I think indexing starts at 0 
int yyerror(char *error)
{
  CTI(CTI_ERROR, true, "line %d, col %d\nError parsing source code: %s\n",
            global.line + 1, global.col, error);
  CTIabortOnError();
  return 0;
}

// int yyerror(char *error)
// {
//     FILE *input_file = fopen(global.input_file, "r");
//     if (input_file == NULL) {
//         fprintf(stderr, "Cannot open input file '%s' for error reporting.\n", global.input_file);
//         CTIabortOnError();
//         return 0;
//     }

//     // Read the file line by line until we reach the error line
//     char line[256];
//     int current_line = 1;
//     bool error_line_found = false;

//     while (fgets(line, sizeof(line), input_file)) {
//         if (current_line == global.line + 1) { // Adjust line number to match editor's convention
//             // Print the error location
//             fprintf(stderr, "error: line %d, col %d\n", global.line + 1, global.col);

//             // Print the line where the error occurred
//             fprintf(stderr, "%s", line);

//             // Print an indicator (^) under the error column
//             for (int i = 1; i < global.col; i++) {
//                 fprintf(stderr, " ");
//             }
//             fprintf(stderr, "^\n");

//             // Print the error message
//             fprintf(stderr, "Error parsing source code: %s\n", error);

//             error_line_found = true;
//             break;
//         }
//         current_line++;
//     }

//     // Close the file
//     fclose(input_file);

//     if (!error_line_found) {
//         fprintf(stderr, "error: line %d, col %d\n", global.line + 1, global.col);
//         fprintf(stderr, "Error parsing source code: %s\n", error);
//     }

//     CTIabortOnError();
//     return 0;
// }

node_st *SPdoScanParse(node_st *root)
{
    DBUG_ASSERT(root == NULL, "Started parsing with existing syntax tree.");
    yyin = fopen(global.input_file, "r");
    if (yyin == NULL) {
        CTI(CTI_ERROR, true, "Cannot open file '%s'.", global.input_file);
        CTIabortOnError();
    }
    yyparse();
    return parseresult;
}
