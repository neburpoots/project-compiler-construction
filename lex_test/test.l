/* flex test.l */
/* gcc lex.yy.c -o scanner -lfl */
/* echo "acccccabccc" | ./scanner */

%{
/* C code (header files, global variables) */
#include <stdio.h>
%}

/* Recognize the pattern "a(c|ab)*" */
%%
a(c|ab)*         { printf("VALID STRING: %s\n", yytext); }
%%
