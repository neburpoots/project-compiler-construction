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
  node_st *generate_indices(node_st *length_node);
  node_st *generate_matrix_indices(int width, int height);

%}
/* %glr-parser */

%union {
	 char               *id;
	 int                 cint;
	 float               cflt;
	 enum BinOpType     cbinop;
	 enum Type           ctype;
	 node_st             *node;
}
%precedence CAST

%locations

%token BRACKET_L BRACKET_R COMMA SEMICOLON CURLY_L CURLY_R SQUARE_L SQUARE_R
%token MINUS PLUS STAR SLASH PERCENT LE LT GE GT EQ NE OR AND PLUSEQ MINUSEQ STAREQ SLASHEQ PERCENTEQ
%token TRUEVAL FALSEVAL LET

//arithmetic 
%type <node> arithmetic

// %token 
%token <cint> NUM
%token <cflt> FLOAT
%token <id> ID

// Functions
%token EXPORT RETURN
%type <node> fundef funbody funContents funContent param var_decl return_stmt call ids

%type <node> intval floatval boolval constant expr cast exprs arrExpr arrVar matVar matVarlet arrVarlet
%type <node> stmts stmt assign varlet program args 

// enum Type 
%token TYPE_INT TYPE_FLOAT TYPE_BOOL TYPE_VOID TYPE_ARRAY
%type <ctype> type

// %token IF ELSE
%token IF ELSE
%type <node> if_stmt

%precedence IF_WITHOUT_ELSE
%right ELSE

// token while
%token WHILE
%type <node> while_stmt

// token do while
%token DO
%type <node> do_while_stmt

// token for
%token FOR
%type <node> for_stmt

%token EXTERN
%type <node> decls decl glob_decl glob_def fun_dec


%right '=' PLUSEQ MINUSEQ STAREQ SLASHEQ PERCENTEQ
%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left STAR SLASH PERCENT


%precedence LOWER
%precedence HIGHER

// give precedence to function when type id is found
%nonassoc FUNDEC


%start program

// %right NOT

%%

program: decls
	{
		parseresult = ASTprogram($1);
		AddLocToNode(parseresult, &@1, &@1);
	}
	;

decls: decl decls
	{
		$$ = ASTdecls($1, $2);
		AddLocToNode($$, &@1, &@2);
	}
	| decl
	{
		$$ = ASTdecls($1, NULL);
		AddLocToNode($$, &@1, &@1);
	}
	;

ids: ID
  {
    //single dimensions
    $$ = ASTids(NULL, $1);
  }
  |
  ID COMMA ids
  {
    //multi dimensional
    $$ = ASTids($3, $1);  
  };

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
  | glob_def
  {
    $$ = $1;
  }
  | fun_dec
  {
    $$ = $1;
  };

fun_dec: EXTERN type ID BRACKET_L param BRACKET_R SEMICOLON
  {
    $$ = ASTfundec($5, $3, $2);
    AddLocToNode($$, &@1, &@6);
  }
  |  EXTERN type ID BRACKET_L BRACKET_R SEMICOLON
  {
    $$ = ASTfundec(NULL, $3, $2);
    AddLocToNode($$, &@1, &@5);
  };


glob_decl: EXTERN type ID SEMICOLON
  {
    $$ = ASTglobdecl(NULL, $3, $2);
    AddLocToNode($$, &@1, &@4);
  };

glob_def: 
  EXPORT type SQUARE_L expr SQUARE_R ID LET expr SEMICOLON
  {
    $$ = ASTglobdef(ASTexprs($4, NULL), $8, $6, $2, true);
    AddLocToNode($$, &@1, &@8);
  }
  |
  EXPORT type SQUARE_L expr COMMA expr SQUARE_R ID LET expr SEMICOLON
  {
    $$ = ASTglobdef(ASTexprs($4, ASTexprs($6, NULL)), $10, $8, $2, true);
    AddLocToNode($$, &@1, &@10);
  }
  | EXPORT type SQUARE_L expr SQUARE_R ID SEMICOLON
  {
    $$ = ASTglobdef(ASTexprs($4, NULL), NULL, $6, $2, true);
    AddLocToNode($$, &@1, &@6);
  }
  | EXPORT type SQUARE_L expr COMMA expr SQUARE_R ID SEMICOLON
  {
    $$ = ASTglobdef(ASTexprs($4, ASTexprs($6, NULL)), NULL, $8, $2, true);
    AddLocToNode($$, &@1, &@8);
  }
  | type SQUARE_L expr COMMA expr SQUARE_R ID LET expr SEMICOLON
  {
    $$ = ASTglobdef(ASTexprs($3, ASTexprs($5, NULL)), $9, $7, $1, false);
    AddLocToNode($$, &@1, &@10);
  }
  | type SQUARE_L expr SQUARE_R ID LET expr SEMICOLON
  {
    $$ = ASTglobdef(ASTexprs($3, NULL), $7, $5, $1, false);
    AddLocToNode($$, &@1, &@8);
  }
  | type SQUARE_L expr SQUARE_R ID SEMICOLON
  {
    $$ = ASTglobdef(ASTexprs($3, NULL), NULL, $5, $1, false);
    AddLocToNode($$, &@1, &@6);
  }
  | type SQUARE_L expr COMMA expr SQUARE_R ID SEMICOLON
  {
    $$ = ASTglobdef(ASTexprs($3, ASTexprs($5, NULL)), NULL, $7, $1, false);
    AddLocToNode($$, &@1, &@7);
  }
 | EXPORT type ID LET expr SEMICOLON
  {
    $$ = ASTglobdef(NULL,$5, $3, $2, true);
    AddLocToNode($$, &@1, &@6);
  }
  | type ID LET expr SEMICOLON
  {
    $$ = ASTglobdef(NULL,$4, $2, $1, false);
    AddLocToNode($$, &@1, &@5);
  }
  | EXPORT type ID SEMICOLON
  {
    $$ = ASTglobdef(NULL,NULL, $3, $2, true);
    AddLocToNode($$, &@1, &@4);
  }
  | type ID SEMICOLON
  {
    $$ = ASTglobdef(NULL,NULL, $2, $1, true);
    AddLocToNode($$, &@1, &@3);
  };

stmts: stmt stmts
  {
    $$ = ASTstmts($1, $2);
    AddLocToNode($$, &@1, &@2);
  }
  | stmt
  {
    $$ = ASTstmts($1, NULL);
    AddLocToNode($$, &@1, &@1);
  }
  ;


// exprs: expr exprs
    

 stmt: assign { $$ = $1; }
    | if_stmt { $$ = $1; }
    | while_stmt { $$ = $1; }
    | do_while_stmt { $$ = $1; }
    | return_stmt { $$ = $1; }
    | for_stmt { $$ = $1; }
    | expr SEMICOLON { $$ = ASTexprstmt($1); }  // ✅ Added closing '}';

funContents: funContent funContents
  {
    $$ = ASTfuncontents($1, $2);
  }
  | %empty
  {
    $$ = NULL;
  };

funContent: fundef { $$ = $1; }
          | stmt { $$ = $1; }
          | var_decl { $$ = $1; }


fundef: EXPORT type ID BRACKET_L param BRACKET_R funbody
  %prec FUNDEC
  {
    $$ = ASTfundef($5, $7, $3, $2, true); // Exported function
    AddLocToNode($$, &@1, &@7);
  }
  | EXPORT type ID BRACKET_L BRACKET_R funbody
    %prec FUNDEC
  {
    $$ = ASTfundef(NULL, $6, $3, $2, true);
    AddLocToNode($$, &@1, &@6);
  }
  | type ID BRACKET_L param BRACKET_R funbody
  %prec FUNDEC
  {
    $$ = ASTfundef($4, $6, $2, $1, false); // Non-exported function
    AddLocToNode($$, &@1, &@6);
  }
  | type ID BRACKET_L BRACKET_R funbody
    %prec FUNDEC
  {
    $$ = ASTfundef(NULL, $5, $2, $1, false);
    AddLocToNode($$, &@1, &@5);
  };

funbody:  CURLY_L funContents CURLY_R
  {
    $$ = ASTfunbody($2);
    AddLocToNode($$, &@1, &@3);
  };


exprs: expr
  {
      $$ = ASTexprs($1, NULL);
  }
  | expr COMMA exprs
  {
      $$ = ASTexprs($1, $3);
  };

//TODO Handle Arrays
var_decl: type ID SEMICOLON
  %prec LOWER
  {
    $$ = ASTvardecl(NULL, NULL, $2, $1);
    AddLocToNode($$, &@1, &@3);
  }
  | type ID LET expr SEMICOLON
  %prec LOWER
  {
    $$ = ASTvardecl(NULL, $4, $2, $1);
    AddLocToNode($$, &@1, &@5);
  }
  // | type ID LET expr COMMA 
  // {
  //   $$ = ASTvardecl(NULL, $4, NULL, $2, $1);
  // }
  // | type ID LET expr SEMICOLON var_decl
  // %prec LOWER
  // {
  //   $$ = ASTvardecl(NULL, $4, $6, $2, $1);
  // }

  //var dec like int[5] empty_vec
  | type SQUARE_L expr SQUARE_R ID SEMICOLON
  %prec LOWER
  {
        $$ = ASTvardecl(ASTexprs($3, NULL),
            NULL,
            $5,
            $1
        );
    AddLocToNode($$, &@1, &@6);
  }

  //var dec like int[1,1] empty_matrix;
  | type SQUARE_L expr COMMA expr SQUARE_R ID SEMICOLON
  %prec LOWER
  {
      $$ = ASTvardecl(
          ASTexprs(
              $3,  
              ASTexprs(
                  $5,
                  NULL
              )
          ),
          NULL,  
          $7,    
          $1
      );
    AddLocToNode($$, &@1, &@7);
  };

  //var dec for initializing a vector like int[5] vec = [1,2,3,4,5];
  // | type SQUARE_L expr SQUARE_R ID LET arrExpr SEMICOLON
  // %prec LOWER
  // {

  //     $$ = ASTvardecl(
  //         ASTexprs($3, NULL),  // Store the array size
  //         $7,                         // Use arrExpr directly
  //         $5,
  //         $1
  //     );
  //   AddLocToNode($$, &@1, &@7);
  // }
  //var dec for initializing a matrix int[3,3] mat = [[1,2,3], [4,5,6], [7,8,9]];
// | type SQUARE_L expr COMMA expr SQUARE_R ID LET SQUARE_L arrExprs SQUARE_R SEMICOLON
//   %prec LOWER

// {
//     //construct dimensions
//     node_st *dims = ASTexprs($3, ASTexprs($5, NULL));

//     //construct ArrExpr node
//     node_st *init = ASTarrexpr($10, NULL);

//     //create vardecl
//     $$ = ASTvardecl(
//         dims,
//         init,
//         $7,
//         $1
//     );
//     AddLocToNode($$, &@1, &@11);
// }
| type SQUARE_L expr COMMA expr SQUARE_R ID LET expr SEMICOLON
{
      //construct dimensions
    node_st *dims = ASTexprs($3, ASTexprs($5, NULL));

    //create vardecl
    $$ = ASTvardecl(
        dims,
        $9,
        $7,
        $1
    );
    AddLocToNode($$, &@1, &@10);
}
| type SQUARE_L expr SQUARE_R ID LET expr SEMICOLON
{
    //construct dimensions
    node_st *dims = ASTexprs($3, NULL);

    //create vardecl
    $$ = ASTvardecl(
        dims,
        $7,
        $5,
        $1
    );
    AddLocToNode($$, &@1, &@8);
}

assign: varlet LET expr SEMICOLON
{
  $$ = ASTassign($1, $3);
  AddLocToNode($$, &@1, &@4);
}
//vec[c1] = scanInt()
| arrVarlet LET expr SEMICOLON
{
  $$ = ASTassign($1, $3);
  AddLocToNode($$, &@1, &@4);
}
//mat[x,y] = scanInt();
| matVarlet LET expr SEMICOLON
{
  $$ = ASTassign($1, $3);
  AddLocToNode($$, &@1, &@4);
};

return_stmt: RETURN expr SEMICOLON
  {
    $$ = ASTreturn($2);
    AddLocToNode($$, &@1, &@3);
  }
  | RETURN SEMICOLON
  {
    $$ = ASTreturn(NULL);
    AddLocToNode($$, &@1, &@2);
  };

if_stmt: IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R ELSE if_stmt
  {
    $$ = ASTifelse($3, $6, ASTstmts($9, NULL));
    AddLocToNode($$, &@1, &@9);
  }
  | IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R ELSE CURLY_L stmts CURLY_R
  {
    $$ = ASTifelse($3, $6, $10);
    AddLocToNode($$, &@1, &@10);
  }
  | IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R %prec IF_WITHOUT_ELSE
  {
    $$ = ASTifelse($3, $6, NULL);
    AddLocToNode($$, &@1, &@6);
  }

  | IF BRACKET_L expr BRACKET_R stmt %prec IF_WITHOUT_ELSE
  {
    $$ = ASTifelse($3, ASTstmts($5, NULL), NULL);
    AddLocToNode($$, &@1, &@3);
  }

  | IF BRACKET_L expr BRACKET_R stmt ELSE stmt
  {
    $$ = ASTifelse($3, ASTstmts($5, NULL), ASTstmts($7, NULL));
    AddLocToNode($$, &@1, &@3);
  }

  | IF BRACKET_L expr BRACKET_R stmt ELSE CURLY_L stmts CURLY_R
  {
    $$ = ASTifelse($3, ASTstmts($5, NULL), $8);
    AddLocToNode($$, &@1, &@3);
  }
  ;


while_stmt: WHILE BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R
  {
    $$ = ASTwhile($3, $6);
    AddLocToNode($$, &@1, &@6);
  }
  | WHILE BRACKET_L expr BRACKET_R CURLY_L CURLY_R
  {
    $$ = ASTwhile($3, NULL);
    AddLocToNode($$, &@1, &@5);
  };

do_while_stmt: DO CURLY_L stmts CURLY_R WHILE BRACKET_L expr BRACKET_R SEMICOLON
  {
    $$ = ASTdowhile($7, $3);
    AddLocToNode($$, &@1, &@9);
  }
  | DO CURLY_L CURLY_R WHILE BRACKET_L expr BRACKET_R SEMICOLON
  {
    $$ = ASTdowhile($6, NULL);
    AddLocToNode($$, &@1, &@8);
  }
  //no curlies
  | DO stmt WHILE BRACKET_L expr BRACKET_R SEMICOLON
  {
    $$ = ASTdowhile($5, ASTstmts($2, NULL));
    AddLocToNode($$, &@1, &@2);
  };

for_stmt:

  //no step size, default to 1, no statements
  FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L CURLY_R
  {
    $$ = ASTfor($6, $8, ASTnum(1), NULL, $4);
    AddLocToNode($$, &@1, &@11);

  }

  //with step size, no statements
  | FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L CURLY_R
  {
    $$ = ASTfor($6, $8, $10, NULL, $4);
    AddLocToNode($$, &@1, &@13);
  }

  //no step size, default to 1, with statements
  | FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R
  {
    $$ = ASTfor($6, $8, ASTnum(1), $11, $4);
    AddLocToNode($$, &@1, &@12);
  }

  //with step size, with statements
  | FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R
  {
    $$ = ASTfor($6, $8, $10, $13, $4);
    AddLocToNode($$, &@1, &@14);
  }

  //no step size, 1 statement, no curlies
  | FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R stmt
  {
    $$ = ASTfor($6, $8, ASTnum(1), ASTstmts($10, NULL), $4);
    AddLocToNode($$, &@1, &@10);
  }

  //with step size, 1 statement, no curlies
  | FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R stmt
  {
    $$ = ASTfor($6, $8, $10, ASTstmts($12, NULL), $4);
    AddLocToNode($$, &@1, &@12);
  };

param: type ID
  {
    $$ = ASTparam(NULL, NULL, $2, $1);
    AddLocToNode($$, &@1, &@2);
  }

  | type ID COMMA param
  {
    $$ = ASTparam(NULL, $4, $2, $1);
    AddLocToNode($$, &@1, &@4);
  }

  //single dimension array
  | type SQUARE_L ids SQUARE_R ID
  {
    $$ = ASTparam($3, NULL, $5, CT_array);
    AddLocToNode($$, &@1, &@5);
  }

  // Array followed by another parameter
  | type SQUARE_L ids SQUARE_R ID COMMA param
  {
    $$ = ASTparam($3, $7, $5, CT_array);
    AddLocToNode($$, &@1, &@7);
  };


varlet: ID
  {
    $$ = ASTvarlet(NULL, $1);
    AddLocToNode($$, &@1, &@1);
  };

args: expr
  //single arg
  {
    $$ = ASTexprs($1, NULL);
    AddLocToNode($$, &@1, &@1);
  }
  //multiple args
  | expr COMMA args
  {
    $$ = ASTexprs($1, $3);
    AddLocToNode($$, &@1, &@3);
  }
  
  // //empty
  // |
  // {
  //   $$ = NULL;
  // };

call: ID BRACKET_L args BRACKET_R
  {
    $$ = ASTfuncall($3, $1);
    AddLocToNode($$, &@1, &@4);
  }
  |
  ID BRACKET_L BRACKET_R
  {
    $$ = ASTfuncall(NULL, $1);
    AddLocToNode($$, &@1, &@3);
  }
  ;

arithmetic: expr PLUS expr
{
    $$ = ASTbinop($1, $3, BO_add);
    AddLocToNode($$, &@1, &@3);
}
| expr MINUS expr
{
    $$ = ASTbinop($1, $3, BO_sub);
    AddLocToNode($$, &@1, &@3);
}
| expr STAR expr
{
    $$ = ASTbinop($1, $3, BO_mul);
    AddLocToNode($$, &@1, &@3);
}
| expr SLASH expr
{
    $$ = ASTbinop($1, $3, BO_div);
    AddLocToNode($$, &@1, &@3);
}
| expr PERCENT expr
{
    $$ = ASTbinop($1, $3, BO_mod);
    AddLocToNode($$, &@1, &@3);
}
| expr LT expr
{
    $$ = ASTbinop($1, $3, BO_lt);
    AddLocToNode($$, &@1, &@3);
}
| expr LE expr
{
    $$ = ASTbinop($1, $3, BO_le);
    AddLocToNode($$, &@1, &@3);
}
| expr GT expr
{
    $$ = ASTbinop($1, $3, BO_gt);
    AddLocToNode($$, &@1, &@3);
}
| expr GE expr
{
    $$ = ASTbinop($1, $3, BO_ge);
    AddLocToNode($$, &@1, &@3);
}
| expr EQ expr
{
    $$ = ASTbinop($1, $3, BO_eq);
    AddLocToNode($$, &@1, &@3);
}
| expr NE expr
{
    $$ = ASTbinop($1, $3, BO_ne);
    AddLocToNode($$, &@1, &@3);
}
| expr AND expr
{
    $$ = ASTbinop($1, $3, BO_and);
    AddLocToNode($$, &@1, &@3);
}
| expr OR expr
{
    $$ = ASTbinop($1, $3, BO_or);
    AddLocToNode($$, &@1, &@3);
}
| expr PLUSEQ expr
{
  $$ = ASTbinop($1, $3, BO_add);
  AddLocToNode($$, &@1, &@3);
}
| expr MINUSEQ expr
{
  $$ = ASTbinop($1, $3, BO_sub);
  AddLocToNode($$, &@1, &@3);
}
| expr STAREQ expr
{
  $$ = ASTbinop($1, $3, BO_mul);
  AddLocToNode($$, &@1, &@3);
}
| expr SLASHEQ expr
{
  $$ = ASTbinop($1, $3, BO_div);
  AddLocToNode($$, &@1, &@3);
}
| expr PERCENTEQ expr
{
  $$ = ASTbinop($1, $3, BO_mod);
  AddLocToNode($$, &@1, &@3);
}
| BRACKET_L expr BRACKET_R
{
  $$ = $2;
  AddLocToNode($$, &@1, &@3);
};

//cast variable like bool test = (bool)0;
cast: BRACKET_L type BRACKET_R expr %prec CAST
  {
    $$ = ASTcast($4, $2);
    AddLocToNode($$, &@1, &@4);
  }

//catches vec[counter];
arrVar: ID SQUARE_L expr SQUARE_R
{
    $$ = ASTvar(ASTexprs($3, NULL), $1);
    AddLocToNode($$, &@1, &@4);
}

//catches matrix[x,y];
matVar: ID SQUARE_L expr COMMA expr SQUARE_R{
    $$ = ASTvar(ASTexprs($3, ASTexprs($5, NULL)), $1);
    AddLocToNode($$, &@1, &@6);
}

arrVarlet: ID SQUARE_L expr SQUARE_R
{
    $$ = ASTvarlet(ASTexprs($3, NULL), $1);
    AddLocToNode($$, &@1, &@4);
}

matVarlet: ID SQUARE_L expr COMMA expr SQUARE_R
{
    $$ = ASTvarlet(ASTexprs($3, ASTexprs($5, NULL)), $1);
    AddLocToNode($$, &@1, &@6);
}

arrExpr: SQUARE_L exprs SQUARE_R
{
    $$ = ASTarrexpr($2, NULL);
    AddLocToNode($$, &@1, &@3);
}
| arrVar
| matVar

// arrExprs: arrExpr
// {
//     $$ = ASTexprs($1, NULL);
//     AddLocToNode($$, &@1, &@1);
// }
// | arrExpr COMMA arrExprs
// {
//     $$ = ASTexprs($1, $3);
//     AddLocToNode($$, &@1, &@3);
// };

expr: constant { $$ = $1; }
   | ID {
      $$ = ASTvar(NULL, $1);
      AddLocToNode($$, &@1, &@1);
    }
   | call
   | cast
   | arithmetic
   | arrExpr
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
  };

type: TYPE_INT   { $$ = CT_int; }
    | TYPE_FLOAT { $$ = CT_float; }
    | TYPE_BOOL  { $$ = CT_bool; }
    | TYPE_VOID  { $$ = CT_void; }
    | TYPE_ARRAY { $$ = CT_array;}

floatval: FLOAT
  {
    $$ = ASTfloat($1);
    AddLocToNode($$, &@1, &@1);
  }
  | MINUS FLOAT
  {
    $$ = ASTnum(-$2);
    AddLocToNode($$, &@1, &@1);
  }

intval: NUM
  {
    $$ = ASTnum($1);
    AddLocToNode($$, &@1, &@1);
  }
  | MINUS NUM
  {
    $$ = ASTnum(-$2);
    AddLocToNode($$, &@1, &@1);
  }

boolval: TRUEVAL
  {
    $$ = ASTbool(true);
    AddLocToNode($$, &@1, &@1);
  }
  | FALSEVAL
  {
    $$ = ASTbool(false);
    AddLocToNode($$, &@1, &@1);
  };
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

//own function create indices for matrix
// node_st *generate_matrix_indices(int width, int height) {
//     // printf("Width: %d height: %d \n", width, height);
//     return ASTexprs(width, ASTexprs(height, NULL));
// }

//own function to create the indices based on the array lenght
node_st *generate_indices(node_st *exprs) {
    int length = 0;
    node_st *temp = exprs;

    //traverse the linked list of Exprs nodes to count them
    while (temp) {
        length++;
        temp = EXPRS_NEXT(temp);
    }

    //generate index nodes
    node_st *expr_list = NULL;
    for (int i = 0; i < length; i++) {
        node_st *num_node = ASTnum(i);
        expr_list = ASTexprs(num_node, expr_list);
    }

    return expr_list;
}

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
