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
%type <node> fundef funbody param var_decl return_stmt call ids

%type <node> intval floatval boolval constant expr cast exprs arrExpr arrExprs arrVar matVar matVarlet arrVarlet
%type <node> stmts stmt assign varlet program args 

// enum Type 
%token TYPE_INT TYPE_FLOAT TYPE_BOOL TYPE_VOID
%type <ctype> type

// %token IF ELSE
%token IF ELSE
%type <node> if_stmt

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



%left OR
%left AND
%left EQ NE
%left LT LE GT GE
%left PLUS MINUS
%left STAR SLASH PERCENT

%start program

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
  }
  |  EXTERN type ID BRACKET_L BRACKET_R SEMICOLON
  {
    $$ = ASTfundec(NULL, $3, $2);
  };


glob_decl: EXTERN type ID SEMICOLON
  {
    $$ = ASTglobdecl(NULL, $3, $2);
  };

glob_def: EXPORT type ID LET expr SEMICOLON
  {
    $$ = ASTglobdef(NULL,$5, $3, $2, true);
  }
  | type ID LET expr SEMICOLON
  {
    $$ = ASTglobdef(NULL,$4, $2, $1, false);
  }
  | EXPORT type ID SEMICOLON
  {
    $$ = ASTglobdef(NULL,NULL, $3, $2, true);
  }
  | type ID SEMICOLON
  {
    $$ = ASTglobdef(NULL,NULL, $2, $1, true);
  };

stmts: stmt stmts
  {
    $$ = ASTstmts($1, $2);
  }
  | stmt
  {
    $$ = ASTstmts($1, NULL);
  };


// exprs: expr exprs
    

stmt: assign { $$ = $1; }
    | if_stmt { $$ = $1; }
    | while_stmt { $$ = $1; }
    | do_while_stmt { $$ = $1; }
    | for_stmt { $$ = $1; }
    | expr SEMICOLON { $$ = ASTexprstmt($1); 
};

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
  };

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
  {
    $$ = ASTvardecl(NULL, NULL, NULL, $2, $1);
  }
  | type ID LET expr SEMICOLON
  {
    $$ = ASTvardecl(NULL, $4, NULL, $2, $1);
  }
  | type ID LET expr COMMA
  {
    $$ = ASTvardecl(NULL, $4, NULL, $2, $1);
  }
  | type ID LET expr SEMICOLON var_decl
  {
    $$ = ASTvardecl(NULL, $4, $6, $2, $1);
  }

  //var dec like int[5] empty_vec
  | type SQUARE_L NUM SQUARE_R ID SEMICOLON
  {
        $$ = ASTvardecl(ASTexprs(ASTnum($3), NULL),
            NULL,
            NULL,
            $5,
            $1
        );
  }

  //var dec like int[5] empty_vec; int[10] empty_vec2;
  | type SQUARE_L NUM SQUARE_R ID SEMICOLON var_decl
  {
        $$ = ASTvardecl(ASTexprs(ASTnum($3), NULL),
            NULL,
            $7,
            $5,
            $1
        );
  }

  //var dec like int[1,1] empty_matrix;
  | type SQUARE_L NUM COMMA NUM SQUARE_R ID SEMICOLON
  {
      $$ = ASTvardecl(
          ASTexprs(
              ASTnum($3),  
              ASTexprs(
                  ASTnum($5),
                  NULL
              )
          ),
          NULL,  
          NULL,  
          $7,    
          $1
      );
  };

  //var dec like int[1,1] empty_matrix; int[15,10] empty_vec3
  | type SQUARE_L NUM COMMA NUM SQUARE_R ID SEMICOLON var_decl
  {
      $$ = ASTvardecl(
          ASTexprs(
              ASTnum($3), 
              ASTexprs(
                  ASTnum($5),
                  NULL
              )
          ),
          NULL,  
          $9,
          $7,   
          $1
      );
  }

  //var dec for initializing a vector like int[5] vec = [1,2,3,4,5];
  | type SQUARE_L NUM SQUARE_R ID LET arrExpr SEMICOLON
  {
      node_st *size_node = ASTnum($3);

      $$ = ASTvardecl(
          ASTexprs(size_node, NULL),  // Store the array size
          $7,                         // Use arrExpr directly
          NULL,  
          $5,
          $1
      );
  }

  //var dec for initializing a vector like int[5] vec = [1,2,3,4,5]; int[3] vec2 = [1,2,3];
  | type SQUARE_L NUM SQUARE_R ID LET arrExpr SEMICOLON var_decl
  {
      node_st *size_node = ASTnum($3);
      $$ = ASTvardecl(
          ASTexprs(size_node, NULL), 
          $7,
          $9,  
          $5,
          $1
      );
  }

  //var dec for initializing a matrix int[3,3] mat = [[1,2,3], [4,5,6], [7,8,9]];
| type SQUARE_L NUM COMMA NUM SQUARE_R ID LET SQUARE_L arrExprs SQUARE_R SEMICOLON
{
    //construct dimensions
    node_st *dims = ASTexprs(ASTnum($3), ASTexprs(ASTnum($5), NULL));

    //construct ArrExpr node
    node_st *init = ASTarrexpr($10, generate_matrix_indices($3, $5));

    //create vardecl
    $$ = ASTvardecl(
        dims,   
        init,   
        NULL,   
        $7,  
        $1
    );
}

| type SQUARE_L NUM COMMA NUM SQUARE_R ID LET SQUARE_L arrExprs SQUARE_R SEMICOLON var_decl
{
    printf("MATRIX DECLARATION DETECTED: %s\n", $7);

    node_st *dims = ASTexprs(ASTnum($3), ASTexprs(ASTnum($5), NULL));

    node_st *init = ASTarrexpr($10, generate_matrix_indices($3, $5));

    $$ = ASTvardecl(
        dims,   
        init, 
        $13,   
        $7,
        $1
    );
}

assign: varlet LET expr SEMICOLON
{
  $$ = ASTassign($1, $3);
}
//vec[c1] = scanInt()
| arrVarlet LET expr SEMICOLON 
{
  $$ = ASTassign($1, $3);
}
//mat[x,y] = scanInt();
| matVarlet LET expr SEMICOLON 
{
  $$ = ASTassign($1, $3);
};
| varlet PLUSEQ expr SEMICOLON
{
  $$ = ASTassign($1, ASTbinop($1, $3, BO_add));
}
| varlet MINUSEQ expr SEMICOLON
{
  $$ = ASTassign($1, ASTbinop($1, $3, BO_sub));
}
| varlet STAREQ expr SEMICOLON
{
  $$ = ASTassign($1, ASTbinop($1, $3, BO_mul));
}
| varlet SLASHEQ expr SEMICOLON
{
  $$ = ASTassign($1, ASTbinop($1, $3, BO_div));
}
| varlet PERCENTEQ expr SEMICOLON
{
  $$ = ASTassign($1, ASTbinop($1, $3, BO_mod));
};

return_stmt: RETURN expr SEMICOLON
  {
    $$ = ASTreturn($2);
  }
  | RETURN SEMICOLON
  {
    $$ = ASTreturn(NULL);
  };

if_stmt: IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R ELSE CURLY_L stmts CURLY_R
  {
    $$ = ASTifelse($3, $6, $10);
  }
  | IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R
  {
    $$ = ASTifelse($3, $6, NULL);
  };

while_stmt: WHILE BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R
  {
    $$ = ASTwhile($3, $6);
  }
  | WHILE BRACKET_L expr BRACKET_R CURLY_L CURLY_R
  {
    $$ = ASTwhile($3, NULL);
  };

do_while_stmt: DO CURLY_L stmts CURLY_R WHILE BRACKET_L expr BRACKET_R SEMICOLON
  {
    $$ = ASTdowhile($7, $3);
  }
  | DO CURLY_L CURLY_R WHILE BRACKET_L expr BRACKET_R SEMICOLON
  {
    $$ = ASTdowhile($6, NULL);
  };

for_stmt: 

  //no step size, default to 1, no statements
  FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L CURLY_R
  {
    // printf("no step size, default to 1, no statements\n");
    $$ = ASTfor($6, $8, ASTnum(1), NULL);
        free($4);

  }

  //with step size, no statements
  | FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L CURLY_R
  {
    printf("with step size, no statements\n");
    $$ = ASTfor($6, $8, $10, NULL);
        free($4);

  }

  //no step size, default to 1, with statements
  | FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R
  {
    printf("no step size, default to 1, with statements\n");
    $$ = ASTfor($6, $8, ASTnum(1), $11);
        free($4);

  }

  //with step size, with statements
  | FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R
  {
    // printf("with step size, with statements\n");
    $$ = ASTfor($6, $8, $10, $13);
        free($4);
  };


param: type ID
  {
    $$ = ASTparam(NULL, NULL, $2, $1);
  }

  | type ID COMMA param
  {
    $$ = ASTparam(NULL, $4, $2, $1);
  }

  //single dimension array
  | type SQUARE_L ids SQUARE_R ID{
      $$ = ASTparam($3, NULL, $5, $1);
  }

  // Array followed by another parameter
  | type SQUARE_L ids SQUARE_R ID COMMA param
  {
    $$ = ASTparam($3, $7, $5, $1);  
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
  }
  //multiple args
  | expr COMMA args
  {
    $$ = ASTexprs($1, $3);
  }
  
  // //empty
  // |
  // {
  //   $$ = NULL;
  // };

call: ID BRACKET_L args BRACKET_R
  {
    $$ = ASTfuncall($3, $1);
  }
  |
  ID BRACKET_L BRACKET_R
  {
    $$ = ASTfuncall(NULL, $1);
  }
  ;

arithmetic: expr PLUS expr
{
    $$ = ASTbinop($1, $3, BO_add);
}
| expr MINUS expr
{
    $$ = ASTbinop($1, $3, BO_sub);
}
| expr STAR expr
{
    $$ = ASTbinop($1, $3, BO_mul);
}
| expr SLASH expr
{
    $$ = ASTbinop($1, $3, BO_div);
}
| expr PERCENT expr
{
    $$ = ASTbinop($1, $3, BO_mod);
}
| expr LT expr
{
    $$ = ASTbinop($1, $3, BO_lt);
}
| expr LE expr
{
    $$ = ASTbinop($1, $3, BO_le);
}
| expr GT expr
{
    $$ = ASTbinop($1, $3, BO_gt);
}
| expr GE expr
{
    $$ = ASTbinop($1, $3, BO_ge);
}
| expr EQ expr
{
    $$ = ASTbinop($1, $3, BO_eq);
}
| expr NE expr
{
    $$ = ASTbinop($1, $3, BO_ne);
}
| expr AND expr
{
    $$ = ASTbinop($1, $3, BO_and);
}
| expr OR expr
{
    $$ = ASTbinop($1, $3, BO_or);
}
| BRACKET_L expr BRACKET_R
{
    $$ = $2;
}

//cast variable like bool test = (bool)0;
cast: BRACKET_L type BRACKET_R expr %prec CAST
  {
    $$ = ASTcast($4, $2);
  }

//catches vec[counter];
arrVar: ID SQUARE_L expr SQUARE_R
{
    $$ = ASTvar(ASTexprs($3, NULL), $1);
}

//catches matrix[x,y];
matVar: ID SQUARE_L expr COMMA expr SQUARE_R{
    $$ = ASTvar(ASTexprs($3, ASTexprs($5, NULL)), $1);
}

arrVarlet: ID SQUARE_L expr SQUARE_R
{
    $$ = ASTvarlet(ASTexprs($3, NULL), $1);  // ✅ Use VarLet instead of Var
}

matVarlet: ID SQUARE_L expr COMMA expr SQUARE_R
{
    $$ = ASTvarlet(ASTexprs($3, ASTexprs($5, NULL)), $1);  // ✅ Use VarLet instead of Var
}

arrExpr: SQUARE_L exprs SQUARE_R
{
    $$ = ASTarrexpr($2, generate_indices($2));
}
| arrVar
| matVar

arrExprs: arrExpr
{
    $$ = ASTexprs($1, NULL);
}
| arrExpr COMMA arrExprs
{
    $$ = ASTexprs($1, $3);
};


expr: constant { $$ = $1; }
   | ID {$$ = ASTvar(NULL, $1);}
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

floatval: FLOAT
  {
    $$ = ASTfloat($1);
  };

intval: NUM
  {
    $$ = ASTnum($1);
  };

boolval: TRUEVAL
  {
    $$ = ASTbool(true);
  }
  | FALSEVAL
  {
    $$ = ASTbool(false);
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
node_st *generate_matrix_indices(int width, int height) {
    // printf("Width: %d height: %d \n", width, height);
    return ASTexprs(ASTnum(width), ASTexprs(ASTnum(height), NULL));
}

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
