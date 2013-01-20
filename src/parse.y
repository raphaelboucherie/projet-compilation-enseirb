%{
  #include <stdio.h>
  #include <unistd.h>
  #include "y.tab.h"

#define I 0
#define F 1
#define S 2
#define U -1

int plus[3][3];
int moins[3][3];
int mul[3][3];
int div[3][3];

void init(int t[3][3]){
  int i,j;
  for(i=0; i<3; i++){
    for(j=0; j<3;j++)
      tab[i][j] = -1;
  }
}

 void init_tab_sym(){
   init(plus);
   plus[I][I]=I;
   plus[I][F]=F;
   plus[F][F]=F;
   plus[F][I]=F;
   plus[S][S]=S;

   init(moins);
   moins[I][I]=I;
   moins[I][F]=F;
   moins[F][F]=F;
   moins[F][I]=F;

   init(mul);
   mul[I][I]=I;
   mul[I][F]=F;
   mul[F][F]=F;
   mul[F][I]=F;
   
   init(div);
   div[I][I]=I;
   div[I][F]=F;
   div[F][F]=F;
   div[F][I]=F;
 }


 

%}
%token AND OR CLASS IF THEN ELSE END WHILE DO DEF LEQ GEQ 
%token STRING FLOAT INT ID FOR TO RETURN IN NEQ
%left '*' 
%left '/'
%left '+' '-'
%left '<' '>' LEQ GEQ EQ
%left AND OR
%%
program		:  topstmts opt_terms
;
topstmts        :      
| topstmt
| topstmts terms topstmt
;
topstmt	        : CLASS ID term stmts END 
                | CLASS ID '<' ID term stmts END
                | stmt
;

stmts	        : /* none */
                | stmt
                | stmts terms stmt
                ;

stmt		: IF expr THEN stmts terms END
                | IF expr THEN stmts terms ELSE stmts terms END 
                | FOR ID IN expr TO expr term stmts terms END
                | WHILE expr DO term stmts terms END 
                | lhs '=' expr
                | RETURN expr
                | DEF ID opt_params term stmts terms END
; 

opt_params      : /* none */
                | '(' ')'
                | '(' params ')'
;
params          : ID ',' params
                | ID
; 
lhs             : ID
                | ID '.' primary
                | ID '(' exprs ')'
;
exprs           : exprs ',' expr
                | expr
;
primary         : lhs
                | STRING 
                | FLOAT
                | INT
                | '(' expr ')'
;
expr            : expr AND comp_expr
                | expr OR comp_expr
                | comp_expr
;
comp_expr       : additive_expr '<' additive_expr
                | additive_expr '>' additive_expr
                | additive_expr LEQ additive_expr
                | additive_expr GEQ additive_expr
                | additive_expr EQ additive_expr
                | additive_expr NEQ additive_expr
                | additive_expr
;
additive_expr   : multiplicative_expr
                | additive_expr '+' multiplicative_expr
                | additive_expr '-' multiplicative_expr
;
multiplicative_expr : multiplicative_expr '*' primary
                    | multiplicative_expr '/' primary
                    | primary
;
opt_terms	: /* none */
		| terms
		;

terms		: terms ';'
                | terms '\n'
		| ';'
                | '\n'
		;
term            : ';'
                | '\n'
;
%%
int main() {
  yyparse(); 
  return 0;
}
