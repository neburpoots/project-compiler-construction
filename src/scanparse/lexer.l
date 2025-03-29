%{

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "ccngen/ast.h"
#include "ccngen/enum.h"
#include "parser.h"
#include "palm/str.h"
#include "global/globals.h"
#include "palm/ctinfo.h"

// Use for error messages, see parser.y
extern int yyerror(char *errname);

#define FILTER(token) \
  global.col += yyleng;  \
  return( token);

#define LINEBUF_SIZE 256
#define YY_NO_UNPUT
#define YY_NO_INPUT

static inline void token_action();

int yycolumn = 1;
#define YY_USER_ACTION token_action();


%}

%p 6000 /* set positions to 6000 */
%e 2000 /* set nodes to 1100 */
%option noyywrap
%option nounput
%option yylineno


%%

"("                        { FILTER( BRACKET_L); }
")"                        { FILTER( BRACKET_R); }

"{"                        { FILTER( CURLY_L); }
"}"                        { FILTER( CURLY_R); }

"["                        { FILTER( SQUARE_L); }
"]"                        { FILTER( SQUARE_R); }
","                        { FILTER( COMMA); }
";"                        { FILTER( SEMICOLON); }

"-="                       { FILTER( MINUSEQ); }
"+="                       { FILTER( PLUSEQ); }
"*="                       { FILTER( STAREQ); }
"/="                       { FILTER( SLASHEQ); }
"%="                       { FILTER( PERCENTEQ); }

"-"                        { FILTER( MINUS); }
"+"                        { FILTER( PLUS);  }
"*"                        { FILTER( STAR);  }
"/"                        { FILTER( SLASH);  }
"%"                        { FILTER( PERCENT);  }

"<="                       { FILTER( LE);    }
"<"                        { FILTER( LT);    }
">="                       { FILTER( GE);    }
">"                        { FILTER( GT);    }
"=="                       { FILTER( EQ);    }
"!="                       { FILTER( NE);    }
"&&"                       { FILTER( AND);    }
"||"                       { FILTER( OR);    }

"if"                       { FILTER( IF); }
"else"                     { FILTER( ELSE); }
"do"                       { FILTER( DO); }
"while"                    { FILTER( WHILE); }
"for"                      { FILTER( FOR); }

"="                        { FILTER( LET);    }

"true"                     { FILTER( TRUEVAL); }
"false"                    { FILTER( FALSEVAL); }

"int"                      { FILTER( TYPE_INT); }
"float"                    { FILTER( TYPE_FLOAT); }
"bool"                     { FILTER( TYPE_BOOL); }
"void"                     { FILTER( TYPE_VOID); }

"extern"                   { FILTER( EXTERN); }
"export"                   { FILTER( EXPORT ); }
"return"                   { FILTER( RETURN ); }


"//".*                        { }
"/*"[^*]*\*+([^/*][^*]*\*+)*"/" { }

[A-Za-z][A-Za-z0-9_]*      { yylval.id = STRcpy(yytext);
                             FILTER( ID);
                           }

[0-9]+ {
    char *endptr;
    long num = strtol(yytext, &endptr, 10);

    if (*endptr != '\0') {
        yyerror("Invalid integer literal");
    }

    if (num > INT32_MAX || num < INT32_MIN) {
        char err[100];
        sprintf(err, "Integer overflow: %s exceeds 32-bit range", yytext);
        yyerror(err);
    }
    yylval.cint = (int)num;
    FILTER(NUM);
}

[0-9]+"."[0-9]*            { yylval.cflt = atof(yytext);
                             FILTER(FLOAT);
                           }

\n.*                       {
                             yycolumn = 1;
                             global.line += 1;
                             global.col = 0;
                             yyless(1);
                           }

[ \t]                      { global.col += yyleng;
                           }
%%

static inline void token_action() {
    yylloc.first_line = yylloc.last_line = yylineno;
    yylloc.first_column = yycolumn;
    yylloc.last_column = yycolumn + yyleng - 1;
    yycolumn += yyleng;
}
