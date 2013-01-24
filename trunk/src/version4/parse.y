%{
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "userdef.h"
#include "y.tab.h"

#define I 0 //int
#define F 1 //float
#define S 2 //string
#define B 3 //bool
#define U -1 //indef

  int yylex(void);
  void yyerror(char *);
  extern VarIndex strMem[10000];
  int tab_plus[4][4];
  int tab_mult[4][4];
  int tab_comp[4][4];
  int tmp = 0;
  void init();
  void init_tab(int tab_plus[4][4],
		int tab_mult[4][4],
		int tab_comp[4][4]);
  int iMaxIndex=0;
  int iCurIndex=0;
  char sBuff[10][20]={0};
  int iBuffX=0;
  int iBuffY=0;
%}
%union{
  int index;
  int ival;
  float fval;
  char *sval;
  int bval;
  int type;
  char *id;
  VarIndex *node;
 }
%token CLASS IF THEN ELSE END WHILE DO DEF LEQ GEQ
%token <node>STRING 
%token <node>FLOAT 
%token <node>INT 
%token <node>ID 
%token FOR TO RETURN IN
%left '*' 
%left '/'
%left '+' '-'
%left '<' '>' LEQ GEQ EQ NEQ
%left AND OR
%type<node> primary
%type<node> expr
%type<node> additive_expr
%type<node> comp_expr
%type<node> multiplicative_expr
%type<node> lhs
%type<node> exprs
%%
program		:  
topstmts opt_terms
;
topstmts        :      
| topstmt {}
| topstmts terms topstmt {}
;
topstmt	        : 
CLASS ID term stmts END {} 
| CLASS ID '<' ID term stmts END {}
| stmt {}
| exprs {}//printf("%d\n",tmp);}
;

stmts	        : /* none */
| stmt {}
| stmts terms stmt {}
;

stmt		: 
IF expr THEN stmts terms END {}
| IF expr THEN stmts terms ELSE stmts terms END {} 
| FOR ID IN expr TO expr term stmts terms END {}
| WHILE expr DO term stmts terms END {}
| lhs '=' expr {}
| RETURN expr {}
| DEF ID opt_params term stmts terms END {}
; 

opt_params      : /* none */
| '(' ')' {}
| '(' params ')' {}
;
params          : 
ID ',' params {}
| ID {}
; 
lhs             : 
ID
| ID '.' primary {}
| ID '(' exprs ')' {}
;
exprs           : 
exprs ',' expr {}
| expr {}//printf("%s\n",$1->name);}
;
expr            : 
expr AND comp_expr {}
| expr OR comp_expr {}
| comp_expr {$$ = $1;}
;
comp_expr       : 
additive_expr '<' additive_expr {$$->type = tab_comp[$1->type][$3->type];}
| additive_expr '>' additive_expr {$$->type = tab_comp[$1->type][$3->type];}
| additive_expr LEQ additive_expr {}
| additive_expr GEQ additive_expr {}
| additive_expr EQ additive_expr {}
| additive_expr NEQ additive_expr {}
| additive_expr {$$ = $1;}
;
additive_expr   : 
multiplicative_expr {$$ = $1;}
| additive_expr '+' multiplicative_expr {$$->type = tab_plus[$1->type][$3->type];}
| additive_expr '-' multiplicative_expr {$$->type = tab_plus[$1->type][$3->type];}
;
multiplicative_expr : 
multiplicative_expr '*' primary {$$->type = tab_mult[$1->type][$3->type];}
| multiplicative_expr '/' primary {$$->type = tab_mult[$1->type][$3->type];}
| primary {$$ = $1;}
;
primary         : 
lhs
| STRING //{$$ = $1;} 
| FLOAT //{$$ = $1;}//{ $$.type = $1.type; $$.fval = $1.fval;}
| INT {$$ = $1;} //$$.type = $1.type; $$.ival = $1.ival;}//add_res();}
| '(' expr ')' {}
;
opt_terms	: /* none */
| terms
;
terms		: 
terms ';'
| terms '\n'
| ';'
| '\n'
;
term            : 
';'
| '\n'
;

%%
void init(int tab[4][4])
{
      int i=0;int j=0;
       for(i=0;i<4;i++){for(j=0;j<4;j++){tab[i][j]=-1;}}
}
void init_tab(int tab_plus[4][4],
	      int tab_mult[4][4],
	      int tab_comp[4][4]){

  init(tab_plus);
  tab_plus[I][I]=I;
  tab_plus[I][F]=F;
  tab_plus[F][I]=F;
  tab_plus[F][F]=F;
  tab_plus[S][S]=S;

  init(tab_mult);
  tab_mult[I][I]=I;
  tab_mult[I][F]=F;
  tab_mult[F][I]=F;
  tab_mult[F][F]=F;

  init(tab_comp);
  tab_comp[I][I]=B;
  tab_comp[I][F]=B;
  tab_comp[F][I]=B;
  tab_comp[F][F]=B;
  tab_comp[S][S]=B;
}


VarIndex *opr(VarIndex *a, VarIndex *b,char op) {
  VarIndex *p = NewVarIndex();
  int i;

  if (p == NULL)
    yyerror("out of memory");
  
  if(op == '+'){
  }else if(op == '-'){
  }else if(op == '*'){
  }else{
  }

  /* p->type = TYPE_OP; */
  /* p->op.name = name; */

  /* p->op.num = num; */

  /* va_start(valist, num); */
  
  /* for (i = 0; i < num; i++) */
    
  /*   p->op.node[i] = va_arg(valist, Node*); */
  /* va_end(valist); */
  return p;

}

int main(void) {

  yyparse();
  return 0;

}
