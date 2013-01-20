%{
#include <stdlib.h>
#include <stdio.h>
#include "lexya_a.tab.h"
  int yylex(void);
  void yyerror(char *);
  %}
//%token FLOAT
%token INTEGER
%left '+' '-'
%left '*' '/'
%%
program:
program expr_int '\n' { printf("%d\n", $2); }
|//expr_float '\n' {printf("%f\n", $2); }
;
expr_int:
INTEGER { $$ = $1; }
| expr_int '*' expr_int { $$ = $1 * $3; }
| expr_int '/' expr_int { $$ = $1 / $3; }
| expr_int '+' expr_int { $$ = $1 + $3; }
| expr_int '-' expr_int { $$ = $1 - $3; }
;
/* expr_float: */
/* FLOAT { $$ = $1; } */
/* | expr_float '*' expr_float { $$ = $1 * $3; } */
/* | expr_float '/' expr_float { $$ = $1 / $3; } */
/* | expr_float '+' expr_float { $$ = $1 + $3; } */
/* | expr_float '-' expr_float { $$ = $1 - $3; } */
/* ; */
%%
void yyerror(char *s) {
  printf("%s\n", s);
}
int main(void) {
  yyparse();
  return 0;
}
