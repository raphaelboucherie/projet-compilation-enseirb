%{
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "userdef.h"
#include "node.h"
#include "y.tab.h"


  int yylex(void);
  void yyerror(char *);
  extern VarIndex strMem[10000];
  int tab_plus[4][4];
  int tab_mult[4][4];
  int tab_comp[4][4];
  int iMaxIndex=0;
  int iCurIndex=0;
  char sBuff[10][20]={0};
  int iBuffX=0;
  int iBuffY=0;
  extern int lineno;
  extern int column;
  float NodeExecute(Node *p);

  /* typedef union { */

/*     float val;  /\* 变量值 *\/ */
/*     int index;  /\* 用于存放 变量数组索引 或 一元操作符值 或 多元操作符索引 *\/ */
/*     Node *node; /\* 结点地址 *\/ */

/*   }yystype; */
/* #define YYSTYPE yystype */

/*   void debug_vsp(YYSTYPE , char * ,YYSTYPE *, char * ); */

  void add_var(char *);
  int G_iVarMaxIndex = 0;  /* 变量最大个数 */
  int G_iVarCurIndex = -1; /* 变量当前索引 */

  struct VarIndex G_Var[MAX_VARS];  /* 变量内存数组 */


%}

%union {
  int index;
  int ival;
  float fval;
  char *sval;
  Node *node;
};
%token <sval>STRING 
%token <fval>FLOAT 
%token <ival>INT 
%token <index>ID 
%token CLASS IF THEN ELSE END 
%token WHILE DO UNLESS
%token DEF LEQ GEQ
%token FOR TO RETURN IN
%token PRINT
%left '*' 
%left '/'
%left '+' '-'
%left '<' '>' LEQ GEQ EQ NEQ
%left AND OR
%left ADD_T ADD_TT MUS_T MUS_TT
%type<node> primary
%type<node> expr
%type<node> additive_expr
%type<node> comp_expr
%type<node> multiplicative_expr
%type<node> lhs
%type<node> exprs
%type<node> params
%type<node> stmts
%type<node> stmt
%type<node> topstmt
%type<node> topstmts
%type<node> term
%type<node> terms
%type<node> opt_params
%%
program		:  
topstmts opt_terms {printf("fini");}
;
topstmts        :      
topstmt {$$ = $1;;printf("I am in topstmt\n");}
| topstmts terms topstmt {}
//| topstmts terms topstmt {}
;
topstmt	        : 
CLASS ID term stmts term END {printf("--------------------------------class\n");} 
| CLASS ID '<' ID term stmts END {}
| stmt  {$$ = $1;}
| exprs {$$ = $1;printf("I am in exprs\n");}//printf("%d\n",tmp);}
;

stmts	        : 
stmt {$$ = $1;}
| stmts terms stmt {}
;

stmt		: 
IF expr THEN stmts terms END {$$ = opr(IF, 2, $2, $4); printf("\tif\n");}
| IF expr THEN stmts terms ELSE stmts terms END {$$ = opr(IF, 3, $2, $4, $7);printf("\tif\n");}
| IF expr stmts terms END {$$ = opr(IF, 2, $2, $3);printf("if\n");}
| IF expr stmts terms ELSE stmts terms END {$$ = opr(IF, 3, $2, $4, $6);printf("\tif\n");} 
| UNLESS expr THEN stmts terms END {$$ = opr(UNLESS, 2, $2, $4);printf("\tunless\n");}
| UNLESS expr THEN stmts terms ELSE stmts terms END {$$ = opr(UNLESS, 3, $2, $4, $7);printf("\tunless\n");}
| UNLESS expr stmts terms END {$$ = opr(UNLESS, 2, $2, $3);printf("\tunless\n");}
| UNLESS expr stmts terms ELSE stmts terms END {$$ = opr(IF, 3, $2, $4, $6);printf("\tunless\n");}
| FOR exprs IN expr TO expr term stmts terms END {$$ = opr(FOR, 4, $2, $4, $6, $8);printf("\tfor\n");}
| WHILE expr DO term stmts terms END {$$ = opr(WHILE,2,$2,$5);printf("\twhile\n");}
| lhs '=' expr {$$ = opr('=', 2, $1, $3);}
| RETURN expr {$$ = $2;}
| DEF ID opt_params term stmts terms END {$$ = opr(DEF,3,$2,$3,$5);printf("\t\tdef\n");}
; 

opt_params      : /* none */
'(' ')' {}
| '(' params ')' {$$ = $2;}
;
params          : 
ID ',' params {}
| ID {$$ = set_index($1); printf("id\n");}
; 
lhs             : 
ID {$$ = set_index($1);printf("id\n");}
| ID '.' primary {}
| ID '(' exprs ')' {$$ = opr('=', 2, set_index($1), $3);}
;
exprs           : 
exprs ',' expr {}
| expr {$$ = $1;printf("I am in expr\n");}
;
expr            : 
expr AND comp_expr {$$ = opr(AND, 2, $1, $3);}
| expr OR comp_expr {$$ = opr(OR, 2, $1, $3);}
| comp_expr {$$ = $1;printf("I am in com_expr\n");}
;
comp_expr       : 
additive_expr '<' additive_expr   {$$ = opr('<', 2, $1, $3);$$->valuetype = tab_comp[$1->valuetype][$3->valuetype];}
| additive_expr '>' additive_expr {$$ = opr('>', 2, $1, $3);$$->valuetype = tab_comp[$1->valuetype][$3->valuetype];}
| additive_expr LEQ additive_expr {$$ = opr(LEQ, 2, $1, $3);$$->valuetype = tab_comp[$1->valuetype][$3->valuetype];}
| additive_expr GEQ additive_expr {$$ = opr(GEQ, 2, $1, $3);$$->valuetype = tab_comp[$1->valuetype][$3->valuetype];}
| additive_expr EQ additive_expr  {$$ = opr(EQ , 2, $1, $3);$$->valuetype = tab_comp[$1->valuetype][$3->valuetype];}
| additive_expr NEQ additive_expr {$$ = opr(NEQ, 2, $1, $3);$$->valuetype = tab_comp[$1->valuetype][$3->valuetype];}
| additive_expr {$$ = $1;printf("I am in additive_expr\n");}
;
additive_expr   : 
multiplicative_expr {$$ = $1;printf("I am in multipicative_expr\n");}
| additive_expr '+' multiplicative_expr {$$ = opr('+', 2, $1, $3);$$->valuetype = tab_plus[$1->valuetype][$3->valuetype];}
| additive_expr '-' multiplicative_expr {$$ = opr('-', 2, $1, $3);$$->valuetype = tab_plus[$1->valuetype][$3->valuetype];}
;
multiplicative_expr : 
multiplicative_expr '*' primary {$$ = opr('*', 2, $1, $3);$$->valuetype = tab_mult[$1->valuetype][$3->valuetype];}
| multiplicative_expr '/' primary {$$ = opr('/', 2, $1, $3);$$->valuetype = tab_mult[$1->valuetype][$3->valuetype];}
| primary {$$ = $1;printf("I am in primary\n");}
;
primary         : 
lhs
| STRING {$$ = NewNodeString($1);printf("string");}
| FLOAT {$$ = NewNodeFloat($1);printf("float");}
| INT {$$ = NewNodeInt($1);printf("int");}
| '(' expr ')' {$$ = $2;}
;
opt_terms	: /* none */
| terms
;
terms		: 
terms ';'
| terms '\n'{}
| ';' {$$ = opr(';', 2, NULL, NULL);}
| '\n' {}
| ' ' {}
;
term            : 
';' {$$ = opr(';', 2, NULL, NULL);}
| '\n' {}
| ' ' {}
;

%%

void add_var(char *mark) {

 if(G_iVarMaxIndex==0){
  strcpy(G_Var[0].mark,mark);
  G_iVarMaxIndex++;
  G_iVarCurIndex=0;
  return;
 }

 int i;

 for(i=0;i<=G_iVarMaxIndex-1;i++) {

  if(strcmp(G_Var[i].mark,mark)==0) {
   G_iVarCurIndex=i;
   return;

  }
 }

 strcpy(G_Var[G_iVarMaxIndex].mark,mark);
 G_iVarCurIndex=G_iVarMaxIndex;
 G_iVarMaxIndex++;
}

float NodeExecute(Node *p) {

 if (!p) return 0;

 switch(p->type) {
  case TYPE_CONTENT: return p->content->f;
  case TYPE_INDEX:   return G_Var[p->index].val;
  case TYPE_OP:

   switch(p->op.name) {
   case DEF:
     NodeExecute(p->op.node[0]);
     return 0;
   
   case CLASS:
     return 0;
     
   case WHILE:  
     while(NodeExecute(p->op.node[0]))
       NodeExecute(p->op.node[1]);
     return 0;              

   case FOR:    
     while((NodeExecute(p->op.node[0]) <= NodeExecute(p->op.node[1]))
	   && (NodeExecute(p->op.node[0]) >= NodeExecute(p->op.node[2]))) {
       NodeExecute(p->op.node[3]);
     }
     return 0;
   

   case IF:     
     if (NodeExecute(p->op.node[0]))
       NodeExecute(p->op.node[1]);
     else
       if (p->op.num>2)
	 NodeExecute(p->op.node[2]);
     return 0;
     
   case UNLESS:
     if(!NodeExecute(p->op.node[0]))
       NodeExecute(p->op.node[1]);
     else
       if(!p->op.num>2)
	 NodeExecute(p->op.node[2]);
     return 0;

   case PRINT:  
     //printf("%g\n", NodeExecute(p->op.node[0]));
     NodePrint(p->op.node[0]);
     return 0;         

   case ';':    NodeExecute(p->op.node[0]);
                return NodeExecute(p->op.node[1]);
   case '=':    return G_Var[p->op.node[0]->index].val = NodeExecute(p->op.node[1]);
   case '+':    return NodeExecute(p->op.node[0]) + NodeExecute(p->op.node[1]);
   case '-':    return NodeExecute(p->op.node[0]) - NodeExecute(p->op.node[1]);
   case '*':    return NodeExecute(p->op.node[0]) * NodeExecute(p->op.node[1]);
   case '/':    return NodeExecute(p->op.node[0]) / NodeExecute(p->op.node[1]);
   case '<':    return NodeExecute(p->op.node[0]) < NodeExecute(p->op.node[1]);
   case '>':    return NodeExecute(p->op.node[0]) > NodeExecute(p->op.node[1]);
   case GEQ:    return NodeExecute(p->op.node[0]) >= NodeExecute(p->op.node[1]);
   case LEQ:    return NodeExecute(p->op.node[0]) <= NodeExecute(p->op.node[1]);
   case NEQ:    return NodeExecute(p->op.node[0]) != NodeExecute(p->op.node[1]);
   case EQ:     return NodeExecute(p->op.node[0]) == NodeExecute(p->op.node[1]);
   case AND:    return NodeExecute(p->op.node[0]) && NodeExecute(p->op.node[1]);
   case OR:     return NodeExecute(p->op.node[0]) || NodeExecute(p->op.node[1]);  
   case ADD_T:  return ++G_Var[p->op.node[0]->index].val;
   case MUS_T:  return --G_Var[p->op.node[0]->index].val;
   case ADD_TT: return G_Var[p->op.node[0]->index].val++;
   case MUS_TT: return G_Var[p->op.node[0]->index].val--;
   }
 }
 return 0;

}


int main(void) {
  init_tab(tab_plus,tab_mult,tab_comp);

  //creer le fichier
  
  yyparse();
  return 0;

}
