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

%nonassoc IF

%nonassoc ELSE

%left AND OR

%left GE LE EQ NE '>' '<'

%left '+' '-'

%left '*' '/'

%left ADD_T ADD_TT MUS_T MUS_TT

%nonassoc UMINUS

%type <node> stmt stmt_list expr_set expr_setself expr_comp expr

%%

program:

function { exit(0); }

;

function:

function stmt { NodeExecute($2); NodeFree($2); }

| /* NULL */

;

stmt:

';'                 { $$ = opr(';', 2, NULL, NULL); debug_vsp(yyval,";",yyvsp,"0"); }

| expr_set ';'      { $$ = $1; debug_vsp(yyval,"es;",yyvsp,"01");                   }

| PRINT expr ';'    { $$ = opr(PRINT, 1, $2); debug_vsp(yyval,"p(e);",yyvsp,"401"); }

| PRINT expr_set ';'    { $$ = opr(PRINT, 1, $2); debug_vsp(yyval,"p(es);",yyvsp,"401"); }

| FOR '(' expr_set ';' expr_comp ';' expr_set ')' stmt { $$ = opr(FOR, 4, $3, $5, $7, $9); debug_vsp(yyval,"for(es;ec;es) st",yyvsp,"410101010"); }

| WHILE '(' expr_comp ')' stmt       { $$ = opr(WHILE, 2, $3, $5); debug_vsp(yyval,"while(ec) st",yyvsp,"41010"); }

| IF '(' expr_comp ')' stmt %prec IF { $$ = opr(IF, 2, $3, $5);    debug_vsp(yyval,"if(ec) st",yyvsp,"41010");    }

| IF '(' expr_comp ')' stmt ELSE stmt %prec ELSE       { $$ = opr(IF, 3, $3, $5, $7);      debug_vsp(yyval,"if(ec)else st",yyvsp,"4101040");      }

| '{' stmt_list '}' { $$ = $2; debug_vsp(yyval,"{stl}",yyvsp,"101"); }

;

 

stmt_list:

stmt              { $$ = $1;  debug_vsp(yyval,"st",yyvsp,"0");  }

| stmt_list stmt  { $$ = opr(';', 2, $1, $2); debug_vsp(yyval,"stl st",yyvsp,"00"); }

;

 

expr_set:

VARIABLE '=' expr { $$ = opr('=', 2, set_index($1), $3); debug_vsp(yyval,"v=e",yyvsp,"210"); }

| VARIABLE '=' expr_setself { $$ = opr('=', 2, set_index($1), $3); debug_vsp(yyval,"v=ess",yyvsp,"210"); }

| expr_setself

;

 

expr_setself:

  ADD_T VARIABLE  { $$ = opr(ADD_T, 1, set_index($2));  debug_vsp(yyval,"++v",yyvsp,"42");   }

| MUS_T VARIABLE  { $$ = opr(MUS_T, 1, set_index($2));  debug_vsp(yyval,"--v",yyvsp,"42");   }

| VARIABLE ADD_T  { $$ = opr(ADD_TT, 1, set_index($1));  debug_vsp(yyval,"v++",yyvsp,"24");  }

| VARIABLE MUS_T  { $$ = opr(MUS_TT, 1, set_index($1));  debug_vsp(yyval,"v--",yyvsp,"24");  }

| '(' expr_setself ')' { $$ = $2; debug_vsp(yyval,"(ess)",yyvsp,"101");   }

;

 

expr_comp:

  expr '<' expr   { $$ = opr('<', 2, $1, $3); debug_vsp(yyval,"e<e",yyvsp,"010");    }

| expr '>' expr   { $$ = opr('>', 2, $1, $3); debug_vsp(yyval,"e>e",yyvsp,"010");    }

| expr GE expr    { $$ = opr(GE, 2, $1, $3);  debug_vsp(yyval,"e>=e",yyvsp,"040");   }

| expr LE expr    { $$ = opr(LE, 2, $1, $3);  debug_vsp(yyval,"e<=e",yyvsp,"040");   }

| expr NE expr    { $$ = opr(NE, 2, $1, $3);  debug_vsp(yyval,"e!=e",yyvsp,"040");   }

| expr EQ expr    { $$ = opr(EQ, 2, $1, $3);  debug_vsp(yyval,"e==e",yyvsp,"040");   }

| expr_comp AND expr_comp { $$ = opr(AND, 2, $1, $3); debug_vsp(yyval,"ec&&ec",yyvsp,"040"); }

| expr_comp OR expr_comp  { $$ = opr(OR, 2, $1, $3);  debug_vsp(yyval,"ec||ec",yyvsp,"040"); }

| '(' expr_comp ')'       { $$ = $2;                  debug_vsp(yyval,"(ec)",yyvsp,"101");   }

;

 

expr:

NUMBER            { $$ = set_content($1);      debug_vsp(yyval,"f",yyvsp,"3");     }

| VARIABLE        { $$ = set_index($1);        debug_vsp(yyval,"v",yyvsp,"2");     }

| '-' NUMBER %prec UMINUS { $$ = set_content(-$2);   debug_vsp(yyval,"-e", yyvsp,"13"); }

| expr '+' expr   { $$ = opr('+', 2, $1, $3);  debug_vsp(yyval,"e+e",yyvsp,"010"); }

| expr '-' expr   { $$ = opr('-', 2, $1, $3);  debug_vsp(yyval,"e-e",yyvsp,"010"); }

| expr '*' expr   { $$ = opr('*', 2, $1, $3);  debug_vsp(yyval,"e*e",yyvsp,"010"); }

| expr '/' expr   { $$ = opr('/', 2, $1, $3);  debug_vsp(yyval,"e/e",yyvsp,"010"); }

| '(' expr ')'    { $$ = $2;                   debug_vsp(yyval,"(e)",yyvsp,"101"); }

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
