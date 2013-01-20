%{
#include <stdlib.h>
#include <stdio.h>
#include "userdef.h"
int yylex(void);
void yyerror(char *);
void debug_info(char *, int *, char *);
extern varIndex strMem[256];
int iMaxIndex=0;
int iCurIndex=0;
char sBuff[10][20]={0};
int iBuffX=0;
int iBuffY=0;
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
| VAR '=' expr { debug_info("=",yyvsp,"210"); strMem[$1].iValue=$3;  }
| statement '\n' {}//{ printf("--------------------------------\n\n"); }
;
expr:
INT { debug_info("INT",yyvsp,"0"); $$ = $1;  }
| VAR { debug_info("VAR",yyvsp,"2"); $$ =  strMem[$1].iValue; }
| expr '*' expr { debug_info("*",yyvsp,"010"); $$ = $1 * $3; }
| expr '/' expr { debug_info("/",yyvsp,"010"); $$ = $1 / $3; }
| expr '+' expr { debug_info("+",yyvsp,"010"); $$ = $1 + $3; }
| expr '-' expr { debug_info("-",yyvsp,"010"); $$ = $1 - $3; }
| '(' expr ')'  { debug_info("()",yyvsp,"101"); $$ = $2;     }
;
%%
void debug_info(char * info,int * vsp, char * mark) {}
void yyerror(char *s) {
  printf("%s\n", s);
}

int main(void) {

  yyparse();
  return 0;

}
