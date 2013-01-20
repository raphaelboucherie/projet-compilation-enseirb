%{  
#include <stdlib.h>
void yyerror(char *);
#include "lexya_a.tab.h"
%}
%%
[0-9]+       { yylval = atoi(yytext); return INTEGER; }
[-+*/\n]     return *yytext;
[\t]         ;
.            yyerror("error");
%%
int yywrap(void) {
return 1;
}
