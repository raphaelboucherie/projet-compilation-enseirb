#include "node.h"
#define SIZE_OF_NODE ((char *)&p->content - (char *)p)

/*INT*/
Content *set_content_int(int value){
  Content *p = (Content*)malloc(sizeof(Content));
  p->e = value;
  return p;
}

Node *NewNodeInt(int value) {

 Node *p = NULL;
 p = (Node*)malloc(sizeof(struct NodeTag));
 p->content = set_content_int(value);
 p->valuetype = I;
 p->type = TYPE_CONTENT;
 return p;
}
/*FLOAT*/
Content *set_content_float(float value){
  Content *p = (Content*)malloc(sizeof(Content));
  p->f = value;
  return p;
}

Node *NewNodeFloat(float value) {

 Node *p = NULL;
 p = (Node*)malloc(sizeof(struct NodeTag));
 p->content = set_content_float(value);
 p->valuetype = F;
 p->type = TYPE_CONTENT;
 return p;
}
/*BOOLEAN*/
Content *set_content_boolean(int value){
  Content *p = (Content*)malloc(sizeof(Content));
  p->f = value;
  return p;
}

Node *NewNodeBoolean(int value) {

 Node *p = NULL;
 p = (Node*)malloc(sizeof(struct NodeTag));
 p->content = set_content_boolean(value);
 p->valuetype = B;
 p->type = TYPE_CONTENT;
 return p;
}
/*STRING*/
Content *set_content_string(char *value){
  Content *p = (Content*)malloc(sizeof(Content) + sizeof(char)*strlen(value));
  p->s = malloc(sizeof(char)*strlen(value));
  strcpy(p->s,value);
  return p;
}

Node *NewNodeString(char* value) {

 Node *p = NULL;
 p = (Node*)malloc(sizeof(struct NodeTag));
 p->content = set_content_string(value);
 p->valuetype = S;
 p->type = TYPE_CONTENT;
 return p;
}
Node *set_index(int value) {

  Node *p = NULL;
  p = (Node*)malloc(sizeof(struct NodeTag));
  p->content = set_content_boolean(0);
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

 if ((p = malloc(sizeNode)) == NULL);
   //yyerror("out of memory");
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

void NodePrint(Node *p){
  switch(p->valuetype){
  case I: printf("%d",p->content->e);break;
  case F: printf("%f",p->content->f);break;
  case S: printf("%s",p->content->s);break;
  case B: {
    if(p->content->b == 0)
      printf("=>true");
    else
      printf("=>nil");
    break;
  }
  default:
    printf("error");
  }
  printf("\n");

}

void NodeFree(Node *p) {

 int i;
 if (!p) return;
 if (p->type == TYPE_OP) {
  for (i = 0; i < p->op.num; i++)
  NodeFree(p->op.node[i]);
 }
 free (p->content);
 free (p);

}
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
