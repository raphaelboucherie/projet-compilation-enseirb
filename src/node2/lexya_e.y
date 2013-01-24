%{

 

#include <stdio.h>

#include <stdlib.h>

#include <stdarg.h>
#include <string.h>

#include "node.h"

 

/* 属性操作类型 */

Node *opr(int name, int num, ...);

Node *set_index(int value);

Node *set_content(float value);

 

/* 树结点操作 */

void NodeFree(Node *p);

float NodeExecute(Node *p);

 

typedef union {

float val;  /* 变量值 */

int index;  /* 用于存放 变量数组索引 或 一元操作符值 或 多元操作符索引 */

Node *node; /* 结点地址 */

}yystype;

#define YYSTYPE yystype

 

/* 打印分析调试信息 */

void debug_vsp(YYSTYPE , char * ,YYSTYPE *, char * );

void print_stmt();

 

 /* 在内存中添加变量 */

void add_var(char *);

 

int G_iVarMaxIndex = 0;  /* 变量最大个数 */

int G_iVarCurIndex = -1; /* 变量当前索引 */

struct VarIndex G_Var[MAX_VARS];  /* 变量内存数组 */

 

 

void yyerror(char *s);

%}

 

%union {

float val; /* 变量值 */

int index; /* 变量数组索引 */

Node *node; /* 结点地址 */

};

 

%token <val> NUMBER
%token <index> VARIABLE
%token PRINT
%token FOR WHILE
%token CLASS END
%token DEF IN END DO
%token THEN
%nonassoc IF
%nonassoc ELSE

%left AND OR
%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
%left ADD_T ADD_TT MUS_T MUS_TT
%left LEQ


%nonassoc UMINUS

 //%type <node> stmt stmt_list expr_set expr_setself expr_comp expr
%type <node> topstmts topstmt
%type <node> comp_expr additive_expr multiplicative_expr
%type <node> primary

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
additive_expr '<' additive_expr //{$$->type = tab_comp[$1->type][$3->type];}
| additive_expr '>' additive_expr //{$$->type = tab_comp[$1->type][$3->type];}
| additive_expr LEQ additive_expr {}
| additive_expr GEQ additive_expr {}
| additive_expr EQ additive_expr {}
| additive_expr NEQ additive_expr {}
| additive_expr {$$ = $1;}
;
additive_expr   : 
multiplicative_expr {$$ = $1;}
| additive_expr '+' multiplicative_expr //{$$->type = tab_plus[$1->type][$3->type];}
| additive_expr '-' multiplicative_expr //{$$->type = tab_plus[$1->type][$3->type];}
;
multiplicative_expr : 
multiplicative_expr '*' primary //{$$->type = tab_mult[$1->type][$3->type];}
| multiplicative_expr '/' primary //{$$->type = tab_mult[$1->type][$3->type];}
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

//| '(' expr error        { $$ = $2; printf("ERROR"); exit(0); }

 

%%

#define SIZE_OF_NODE ((char *)&p->content - (char *)p)

 

Node *set_content(float value) {

 

 Node *p;

 

 size_t sizeNode;

 /* 分配结点空间 */

 sizeNode = SIZE_OF_NODE + sizeof(float);

 

 if ((p = malloc(sizeNode)) == NULL)

  yyerror("out of memory");

 

 /* 复制内容 */

 p->type = TYPE_CONTENT;

 p->content = value;

 

 return p;

 

}

 

Node *set_index(int value) {

 

 Node *p;

 size_t sizeNode;

 /* 分配结点空间 */

 sizeNode = SIZE_OF_NODE + sizeof(int);

 

 if ((p = malloc(sizeNode)) == NULL)

  yyerror("out of memory");

 

 /* 复制内容 */

 p->type = TYPE_INDEX;

 p->index = value;

 

 return p;

}

 

Node *opr(int name, int num, ...) {

 

 va_list valist;

 Node *p;

 size_t sizeNode;

 int i;

 /* 分配结点空间 */

 sizeNode = SIZE_OF_NODE + sizeof(OpNode) + (num - 1) * sizeof(Node*);

 

 if ((p = malloc(sizeNode)) == NULL)

  yyerror("out of memory");

 

 /* 复制内容 */

 

 p->type = TYPE_OP;

 p->op.name = name;

 p->op.num = num;

 

 va_start(valist, num);

 

 for (i = 0; i < num; i++)

 p->op.node[i] = va_arg(valist, Node*);

 

 va_end(valist);

 return p;

}

 

/**/

void debug_vsp(YYSTYPE yval, char * info, YYSTYPE * vsp, char * mark) {

 

#ifdef PARSE_DEBUG

 

  printf("\n -RULE  0x%x  %s \n ", yval.node, info  );

  int i;

  int ilen=strlen(mark);

  for(i=1-ilen;i<=0;i++) {

  

  switch(mark[ilen+i-1]){

   case '0':

    printf(" [ 0x%x ",vsp[i].node);//「」

    switch(vsp[i].node->type) {

     case TYPE_CONTENT:

      printf("%g ] ",vsp[i].node->content);

      break;

     case TYPE_INDEX:

      printf("%s ] ",G_Var[vsp[i].node->index].mark);

      break;

     case TYPE_OP:

      if(vsp[i].node->op.name<USER_DEF_NUM)

       printf("%c ] ",vsp[i].node->op.name);

      else

       printf("%s ] ",G_Def[vsp[i].node->op.name-USER_DEF_NUM].name);

      break;      

    }

    break;

   case '1':

    printf(" %c ",vsp[i].index);   /* 打印运算符 */

    break;

   case '2':

    printf(" %s ",G_Var[vsp[i].index].mark);

    break;

   case '3':

    printf(" %g ",vsp[i].val);

    break;

   case '4':

    printf(" %s ",G_Def[vsp[i].index].name);

    break;  

    }

   

  }

  printf("\n");

  print_stmt();

 

#endif

 

}

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

void print_stmt() {

 

 printf(" -STMT: \n");

 /*

 int i;

 for(i=0;i<=G_iBuffRowCount;i++)

  printf("%s \n",G_sBuff[i]);

 */

 if(G_iBuffColCount==0)

  printf("  %s \n",G_sBuff[G_iBuffRowCount-1]);

 else

  printf("  %s \n",G_sBuff[G_iBuffRowCount]);

 

 printf("\n");

 

}

 

void NodeFree(Node *p) {

 int i;

 if (!p) return;

 if (p->type == TYPE_OP) {

  for (i = 0; i < p->op.num; i++)

  NodeFree(p->op.node[i]);

 }

 free (p);

}

float NodeExecute(Node *p) {

 if (!p) return 0;

 switch(p->type) {

  case TYPE_CONTENT: return p->content;

  case TYPE_INDEX:   return G_Var[p->index].val;

  case TYPE_OP:

   switch(p->op.name) {

   

    case WHILE:  while(NodeExecute(p->op.node[0]))NodeExecute(p->op.node[1]);

                return 0;

               

     case FOR:    NodeExecute(p->op.node[0]);

                 while(NodeExecute(p->op.node[1])) {

                    NodeExecute(p->op.node[3]);

                    NodeExecute(p->op.node[2]);

                  }

                  return 0;

   

    case IF:     if (NodeExecute(p->op.node[0]))

                  NodeExecute(p->op.node[1]);

                else

                  if (p->op.num>2)

                    NodeExecute(p->op.node[2]);

                return 0;

               

    case PRINT:  printf("%g\n", NodeExecute(p->op.node[0]));

                return 0;

               

    case ';':    NodeExecute(p->op.node[0]);

                return NodeExecute(p->op.node[1]);

               

    case '=':    return G_Var[p->op.node[0]->index].val = NodeExecute(p->op.node[1]);

    case UMINUS: return NodeExecute(p->op.node[0]);

    case '+':    return NodeExecute(p->op.node[0]) + NodeExecute(p->op.node[1]);

    case '-':    return NodeExecute(p->op.node[0]) - NodeExecute(p->op.node[1]);

    case '*':    return NodeExecute(p->op.node[0]) * NodeExecute(p->op.node[1]);

    case '/':    return NodeExecute(p->op.node[0]) / NodeExecute(p->op.node[1]);

    case '<':    return NodeExecute(p->op.node[0]) < NodeExecute(p->op.node[1]);

    case '>':    return NodeExecute(p->op.node[0]) > NodeExecute(p->op.node[1]);

    case GE:     return NodeExecute(p->op.node[0]) >= NodeExecute(p->op.node[1]);

    case LE:     return NodeExecute(p->op.node[0]) <= NodeExecute(p->op.node[1]);

    case NE:     return NodeExecute(p->op.node[0]) != NodeExecute(p->op.node[1]);

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

void yyerror(char *s) {

 //fprintf(stdout, "%s\n", s);

 printf("<Parser Error> Line %d ,Col %d \n",G_iBuffRowCount+1,G_iBuffColCount+1);

 printf(" %s\n",G_sBuff[G_iBuffRowCount]);

}

 

int main(void) {
  yyparse();
  return 0;

}
