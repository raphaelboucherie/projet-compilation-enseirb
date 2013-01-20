%{
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lexya_b.tab.h"

int yylex(void);
void yyerror(char *);
void debuginfo(char *, int *, char *);
int sMem[256];
char sBuff[10][20]={0};
int iX=0;
int iY=0;
%}
%token INT VAR
%left '+' '-'
%left '*' '/'
%%
program:
program statement
|
;
statement:
expr { printf("%d\n",$1); }
| VAR '=' expr { debuginfo("=",yyvsp,"110"); sMem[$1]=$3;  }
| statement '\n' {}
;
expr:
INT { debuginfo("INT",yyvsp,"0"); $$ = $1;  }
| VAR { debuginfo("VAR",yyvsp,"1"); $$ = sMem[$1]; }
| expr '*' expr {  $$ = $1 * $3; }
| expr '/' expr {  $$ = $1 / $3; }
| expr '+' expr {  $$ = $1 + $3; }
| expr '-' expr {  $$ = $1 - $3; }
| '(' expr ')'  {  $$ = $2;     }
;
%%
void debuginfo(char * info,int * vsp, char * mark) {
}

void yyerror(char *s) {
  printf("%s\n", s);
}

int main(void) {
  yyparse();
  return 0;
}
