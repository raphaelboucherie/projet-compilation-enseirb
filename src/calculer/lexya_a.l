%{  
#include <stdlib.h>
#include<stdio.h>
void yyerror(char *);
#include "lexya_a.tab.h"
%}
%%
([0-9]+\.[0-9]+) { yylval = atof(yytext); return FLOAT; }
[0-9]+       { yylval = atoi(yytext); return INTEGER; }
[-+*/\n]     return *yytext;
[\t]         ;
.            yyerror("error");
%%
int yywrap(void) {
return 1;
}
