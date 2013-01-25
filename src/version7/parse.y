%{
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "userdef.h"
#include "llvm.h"
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
  int cpt = 0;
  FILE* file = NULL;
  extern int lineno;
  extern int column;
  Node* NodeExecute(Node *p);

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
topstmt {}//NodeExecute($$);$$ = $1;printf("------------------------------------------------------------------------");}
| topstmts terms topstmt {}
//| topstmts terms topstmt {}
;
topstmt	        : 
CLASS ID term stmts term END {printf("--------------------------------class\n");} 
| CLASS ID '<' ID term stmts END {}
| stmt  {$$ = $1;NodePrint($$);}
| exprs {$$ = $1;NodePrint($$);NodeFree($$);}
;

stmts	        : 
stmt {$$ = $1;}
| stmts terms stmt {}
;

stmt		: 
IF expr THEN stmts terms END {printf("I want");$$ = NodeExecute(opr(IF, 2, $2, $4)); }
| IF expr THEN stmts terms ELSE stmts terms END {$$ = NodeExecute(opr(IF, 3, $2, $4, $7));}
| IF expr stmts terms END {$$ = NodeExecute(opr(IF, 2, $2, $3));}
| IF expr stmts terms ELSE stmts terms END {$$ = NodeExecute(opr(IF, 3, $2, $4, $6));} 
| UNLESS expr THEN stmts terms END {$$ = NodeExecute(opr(UNLESS, 2, $2, $4));}
| UNLESS expr THEN stmts terms ELSE stmts terms END {$$ = NodeExecute(opr(UNLESS, 3, $2, $4, $7));}
| UNLESS expr stmts terms END {$$ = NodeExecute(opr(UNLESS, 2, $2, $3));}
| UNLESS expr stmts terms ELSE stmts terms END {$$ = NodeExecute(opr(IF, 3, $2, $4, $6));}
| FOR exprs IN expr TO expr term stmts terms END {$$ = NodeExecute(opr(FOR, 4, $2, $4, $6, $8));printf("\tfor\n");}
| WHILE expr DO term stmts terms END {$$ = NodeExecute(opr(WHILE,2,$2,$5));printf("\twhile\n");}
| lhs '=' expr {$$ = NodeExecute(opr('=',2,$1,$3));}//{$$ = set_index($1); $$->valuetype = $3->valuetype; $$->content = $3->content; NodePrint($$);}
| RETURN expr {$$ = $2;}
| DEF ID opt_params term stmts terms END {$$ = NodeExecute(opr(DEF,3,$2,$3,$5));printf("\t\tdef\n");}
; 

opt_params      : /* none */
'(' ')' {}
| '(' params ')' {$$ = $2;}
;
params          : 
ID ',' params {}
| ID {$$ = set_index($1);}
; 
lhs             : 
ID {$$ = set_index($1);}
| ID '.' primary {$$ = set_index($1);}//$ = set_index(strcat($1,primary));}
| ID '(' exprs ')' {$$ = set_index($1);}//{$$ = set_index(1); $$->valuetype = $3->valuetype; $$->content = $3->content; NodePrint($$);}
;
exprs           : 
exprs ',' expr {}
| expr {$$ = $1;printf("expr");}
;
expr            : 
expr AND comp_expr {$$ = NodeExecute(opr(AND, 2, $1, $3));}
| expr OR comp_expr {$$ = NodeExecute(opr(OR, 2, $1, $3));}
| comp_expr {$$ = $1;}
;
comp_expr       : 
additive_expr '<' additive_expr  {$$ = NodeExecute(opr('<',2,$1,$3));} 
//{$$ = opr('<', 2, $1, $3);$$->valuetype = tab_comp[$1->valuetype][$3->valuetype];}
| additive_expr '>' additive_expr {$$ = NodeExecute(opr('>',2,$1,$3));} 
  //{$$ = opr('>', 2, $1, $3);$$->valuetype = tab_comp[$1->valuetype][$3->valuetype];}
| additive_expr LEQ additive_expr {$$ = NodeExecute(opr(LEQ,2,$1,$3));} 
  //{$$ = opr(LEQ, 2, $1, $3);$$->valuetype = tab_comp[$1->valuetype][$3->valuetype];}
| additive_expr GEQ additive_expr {$$ = NodeExecute(opr(GEQ,2,$1,$3));} 
  //{$$ = opr(GEQ, 2, $1, $3);$$->valuetype = tab_comp[$1->valuetype][$3->valuetype];}
| additive_expr EQ additive_expr  {$$ = NodeExecute(opr(EQ,2,$1,$3));} 
  //{$$ = opr(EQ , 2, $1, $3);$$->valuetype = tab_comp[$1->valuetype][$3->valuetype];}
| additive_expr NEQ additive_expr {$$ = NodeExecute(opr(NEQ,2,$1,$3));} 
  //{$$ = opr(NEQ, 2, $1, $3);$$->valuetype = tab_comp[$1->valuetype][$3->valuetype];}
| additive_expr {$$ = $1;}
;
additive_expr   : 
multiplicative_expr {$$ = $1;}
| additive_expr '+' multiplicative_expr {$$ = NodeExecute(opr('+',2,$1,$3));}
//{$$ = opr('+',2,$1,$3);$$->valuetype = tab_plus[$1->valuetype][$3->valuetype];}
| additive_expr '-' multiplicative_expr {$$ = NodeExecute(opr('-',2,$1,$3));}
  //{$$ = opr('-',2,$1,$3);$$->valuetype = tab_plus[$1->valuetype][$3->valuetype];}
;
multiplicative_expr : 
multiplicative_expr '*' primary {$$ = NodeExecute(opr('*',2,$1,$3));}
//{$$ = opr('*',2,$1,$3);$$->valuetype = tab_mult[$1->valuetype][$3->valuetype];}
| multiplicative_expr '/' primary {$$ = NodeExecute(opr('/',2,$1,$3));}
  //{$$ = opr('+',2,$1,$3); $$->valuetype = tab_mult[$1->valuetype][$3->valuetype];}
| primary {$$ = $1;}
;
primary         : 
lhs
| STRING {printf("string");$$ = NewNodeString($1);}
| FLOAT {$$ = NewNodeFloat($1);}
| INT {$$ = NewNodeInt($1);}
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

Node* NodeExecute(Node *p) {

 if (!p) return 0;

 switch(p->type) {
 case TYPE_CONTENT: return p;
 case TYPE_INDEX:   return G_Var[p->index].val;
 case TYPE_OP:

   switch(p->op.name) {
   case DEF:
     fprintf(file,"fonction");
     NodeExecute(p->op.node[0]);
     return p;
     
   case CLASS:
     return p;
      
   case WHILE:
     while(NodeExecute(p->op.node[0]))
       return NodeExecute(p->op.node[1]);
     return p;

   case FOR:
     /* printf("-------------------------for----------------------------------"); */
     /* // while((int2float(NodeExecute(p->op.node[0])) <= int2float(NodeExecute(p->op.node[1])))&& */
     /* //	   (int2float(NodeExecute(p->op.node[0])) >= int2float(NodeExecute(p->op.node[2])))) */
     /* // NodeExecute(opr('=',2,NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]))); */
     /* while(NodeExecute(opr(GEQ,2,NodeExecute(p->op.node[0]),NodeExecute(p->op.node[2])))) */
     /*   { */
     /* 	 NodeExecute(opr('+',2,NodeExecute(p->op.node[0]), NewNodeInt(1)));//,NodeExecute(p->op.node[3]))); */
     /* 	 NodeExecute(p->op.node[3]); */
     /*   } */
     /* return p; */
     //Node * tmp = NewNodeInt(1);
     if(NodeExecute(p->op.node[1])->content->e <=
	NodeExecute(p->op.node[2])->content->e){
       p->op.node[1] = NodeExecute(opr('+',2,NodeExecute(p->op.node[1]),NewNodeInt(1)));
       NodeExecute(p->op.node[3]);
       return NodeExecute(opr(FOR,
			      4,
			      p->op.node[0],
			      p->op.node[1],
			      p->op.node[2],
			      p->op.node[3]));
     }
			      
   

   case IF:
     
     if (NodeExecute(p->op.node[0])->content->b == 1 && 
	 NodeExecute(p->op.node[0])->valuetype == B)
       return NodeExecute(p->op.node[1]);
     else
       if (p->op.num>2)
	 return NodeExecute(p->op.node[2]);
     return p;
     
   case UNLESS:
     if(!(NodeExecute(p->op.node[0])->content->b == 1))
       return(NodeExecute(p->op.node[1]));
     else
       if(!p->op.num>2)
	 return NodeExecute(p->op.node[2]);
     return p;


   case ';':    NodeExecute(p->op.node[0]);
                return NodeExecute(p->op.node[1]);
   case '=':    return G_Var[p->op.node[0]->index].val = NodeExecute(p->op.node[1]);
   case '+': 
     llvm_opr(file,'+',NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
     return opr_node(tab_plus
		     [NodeExecute(p->op.node[0])->valuetype]
		     [NodeExecute(p->op.node[1])->valuetype],
		     '+',NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
   case '-':   
     llvm_opr(file,'-',NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
     return opr_node(tab_plus
		     [NodeExecute(p->op.node[0])->valuetype]
		     [NodeExecute(p->op.node[1])->valuetype],
		     '-',NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
   case '*':    
     llvm_opr(file,'*',NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
     return opr_node(tab_plus
		     [NodeExecute(p->op.node[0])->valuetype]
		     [NodeExecute(p->op.node[1])->valuetype],
		     '*',NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
   case '/':   
     llvm_opr(file,'/',NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
     return opr_node(tab_plus
		     [NodeExecute(p->op.node[0])->valuetype]
		     [NodeExecute(p->op.node[1])->valuetype],
		     '/',NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));

   case '<': 
     
     if (tab_comp
	 [NodeExecute(p->op.node[0])->valuetype]
	 [NodeExecute(p->op.node[1])->valuetype] == B)
       {
	 llvm_cmp(file,"<",NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
	 if(int2float(NodeExecute(p->op.node[0])) < 
	    int2float(NodeExecute(p->op.node[1])))
	   return NewNodeBoolean(1);
	 else
	   return NewNodeBoolean(0);
       }

   case '>': 
     
      if (tab_comp
	 [NodeExecute(p->op.node[0])->valuetype]
	  [NodeExecute(p->op.node[1])->valuetype] == B)
	{
	  llvm_cmp(file,"<",NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
	  if(int2float(NodeExecute(p->op.node[0])) >
	     int2float(NodeExecute(p->op.node[1])))
	    return NewNodeBoolean(1);
	  else
	    return NewNodeBoolean(0);
	}

   case GEQ:    
      if (tab_comp
	  [NodeExecute(p->op.node[0])->valuetype]
	  [NodeExecute(p->op.node[1])->valuetype] == B)
	{
	   llvm_cmp(file,"<=",NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
	  if(int2float(NodeExecute(p->op.node[0])) <=
	     int2float(NodeExecute(p->op.node[1])))
	    return NewNodeBoolean(1);
	  else
	    return NewNodeBoolean(0);
	}
   case LEQ:   
      if (tab_comp
	  [NodeExecute(p->op.node[0])->valuetype]
	  [NodeExecute(p->op.node[1])->valuetype] == B)
	{
	   llvm_cmp(file,">=",NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
	   if(int2float(NodeExecute(p->op.node[0])) >= 
	      int2float(NodeExecute(p->op.node[1])))
	     return NewNodeBoolean(1);
	   else
	     return NewNodeBoolean(0);
	}

   case NEQ: 
     if((NodeExecute(p->op.node[0])->valuetype == B) && 
	(NodeExecute(p->op.node[1])->valuetype == B)){
        llvm_cmp(file,"!=",NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
       if
	 ((NodeExecute(p->op.node[0])->content->b) +
	  (NodeExecute(p->op.node[0])->content->b) == 1)
	 return NewNodeBoolean(1);
       else
	 return NewNodeBoolean(0);
     }
      
     else if (tab_comp
	      [NodeExecute(p->op.node[0])->valuetype]
	      [NodeExecute(p->op.node[1])->valuetype] == B){
       llvm_cmp(file,"!=",NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
       if(int2float(NodeExecute(p->op.node[0])) !=
	  int2float(NodeExecute(p->op.node[1])))
	 return NewNodeBoolean(1);
       else
	 return NewNodeBoolean(0);
     }
			      
     
   case EQ:    
     if((NodeExecute(p->op.node[0])->valuetype == B) && 
	(NodeExecute(p->op.node[1])->valuetype == B)){
       llvm_cmp(file,"==",NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
       if
	 ((NodeExecute(p->op.node[0])->content->b) +
	  (NodeExecute(p->op.node[0])->content->b) != 1)
	 return NewNodeBoolean(1);
       else
	 return NewNodeBoolean(0);
     }
     
     else if (tab_comp
	      [NodeExecute(p->op.node[0])->valuetype]
	      [NodeExecute(p->op.node[1])->valuetype] == B){
       llvm_cmp(file,"==",NodeExecute(p->op.node[0]),NodeExecute(p->op.node[1]));
       if(int2float(NodeExecute(p->op.node[0])) ==
	  int2float(NodeExecute(p->op.node[1])))
	 return NewNodeBoolean(1);
       else
	 return NewNodeBoolean(0);
     }

   case AND:
     if((NodeExecute(p->op.node[0])->valuetype == B) && 
	(NodeExecute(p->op.node[1])->valuetype == B))
       return NewNodeBoolean(NodeExecute(p->op.node[0])->content->b *  NodeExecute(p->op.node[1])->content->b);
     
   case OR:    
     if((NodeExecute(p->op.node[0])->valuetype == B) && 
	(NodeExecute(p->op.node[1])->valuetype == B))
       return NewNodeBoolean(1 - 
			     NodeExecute(p->op.node[0])->content->b * 
			     NodeExecute(p->op.node[1])->content->b);

   /* case ADD_T:  return ++G_Var[p->op.node[0]->index].val; */
   /* case MUS_T:  return --G_Var[p->op.node[0]->index].val; */
   /* case ADD_TT: return G_Var[p->op.node[0]->index].val++; */
   /* case MUS_TT: return G_Var[p->op.node[0]->index].val--; */
   }
 }
 return 0;

}


int main(void) {
  init_tab(tab_plus,tab_mult,tab_comp);
  file =fopen("file.ll","w");
  //creer le fichier
  llvm_title(file);
  llvm_main(file);
  yyparse();
  llvm_return(file);
  llvm_fini(file);
  return 0;

}
