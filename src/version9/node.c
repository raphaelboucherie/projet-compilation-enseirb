#include "node.h"
#define SIZE_OF_NODE ((char *)&p->content - (char *)p)
extern FILE *file;

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
  p->b = value;
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
Content *set_content_vide(void){
   Content *p = (Content*)malloc(sizeof(Content));
   return p;
}
Node *NewNodeVide(void){
  Node *p = NULL;
  p = (Node*)malloc(sizeof(struct NodeTag));
  p->content = set_content_vide();
  p->valuetype = U;
  //p->type = TYPE_CONTENT;
  return p;
}
Node *set_index(int value) {

  Node *p = NULL;
  p = NewNodeVide();
  //p->content = set_content_boolean(0);
  p->type = TYPE_INDEX;
  p->index = value;

 return p;

}

Node *opr(int name, int num, ...) {

  va_list valist;
  Node *p = NewNodeVide();
  size_t sizeNode;
  int i;
  /* 分配结点空间 */
  //sizeNode = SIZE_OF_NODE + sizeof(OpNode) + (num - 1) * sizeof(Node*);
  //p = (Node*)malloc(sizeof(struct NodeTag));

  /* 复制内容 */
  //p->valuetype = F;
  p->type = TYPE_OP;
  p->op.name = name;
  p->op.num = num;
  va_start(valist, num);
  for (i = 0; i < num; i++){
    p->op.node[i] = va_arg(valist, Node*);
    // NodePrint(p->op.node[i]);
  }
  va_end(valist);

 return p;

}

void NodePrint(Node *p){
  switch(p->valuetype){
  case I: printf("%d",p->content->e);break;
  case F: printf("%f",p->content->f);break;
  case S: printf("%s",p->content->s);break;
  case B: {
    if(p->content->b == 1)
      printf("=>true");
    else if (p->content->b == 0)
      printf("=>nil");
    break;
  }
  default:
    //printf("%f",p->content->f);
    printf("type error");
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

Node* opr_node( char opr, Node *a, Node *b){
  int type;
  llvm_opr(file,opr,a,b);
  if(opr == '+' || opr == '-') type = tab_plus[a->valuetype][b->valuetype];
  else if (opr == '*' || opr == '/') type = tab_mult[a->valuetype][b->valuetype];
  float r1,r2;
  switch(type){
  case I: return NewNodeInt(opr_node_int(opr,a->content->e, b->content->e));
  case F: {
    if(a->valuetype==I) 
      r1 = (a->content->e);
    else
      r1 = a->content->f;
   if(b->valuetype==I) 
     r2 = (b->content->e);
    else
      r2 = b->content->f;

   return NewNodeFloat(opr_node_float(opr,r1,r2));
   
  }
  case B:printf("error"); return NewNodeVide();
  case S:printf("error"); return NewNodeVide();
  case U:printf("error"); return NewNodeVide();
  default: printf("error"); return NewNodeVide();
  }

}
int opr_node_int(char opr, int a, int b){
  switch(opr){
  case '+': return (a+b);
  case '-': return (a-b);
  case '*': return (a*b);
  case '/': return (a/b);
  }
}
float opr_node_float(char opr, float a, float b){
  switch(opr){
  case '+': return (a+b);
  case '-': return (a-b);
  case '*': return (a*b);
  case '/': return (a/b);
  }
}
float int2float(Node *a){
  float res;
  if (a->valuetype == I)
    res = a->content->e;
  else if(a->valuetype == F)
    res = a->content->f;
  else
    printf("error");
  
  return res;
}

Node * opr_cmp(int opr,Node *a, Node *b){
  switch(opr){

  case 1:
    if (tab_comp[a->valuetype][b->valuetype] == B)
      {
	llvm_cmp(file,"<",a,b);
	if(int2float(a) < int2float(b))return NewNodeBoolean(1);
	else return NewNodeBoolean(0);
      }

  case 2:
     if (tab_comp[a->valuetype][b->valuetype] == B)
	{
	  llvm_cmp(file,">",a,b);
	  if(int2float(a) >int2float(b)) return NewNodeBoolean(1);
	  else return NewNodeBoolean(0);
	}
  case 3:
     if (tab_comp[a->valuetype][b->valuetype] == B)
	{
	   llvm_cmp(file,"<=",a,b);
	  if(int2float(a) <=int2float(b))return NewNodeBoolean(1);
	  else return NewNodeBoolean(0);
	}
  case 4:
    if (tab_comp [a->valuetype][b->valuetype] == B)
	{
	   llvm_cmp(file,">=",a,b);
	   if(int2float(a) >= int2float(b)) return NewNodeBoolean(1);
	   else return NewNodeBoolean(0);
	}
  case 5:
     if((a->valuetype == B) && (b->valuetype == B)){
       llvm_cmp(file,"!=",a,b);
       if((a->content->b) + (a->content->b) == 1)return NewNodeBoolean(1);
       else return NewNodeBoolean(0);
     }
      
     else if (tab_comp[a->valuetype][b->valuetype] == B){
       llvm_cmp(file,"!=",a,b);
       if(int2float(a) !=int2float(b)) return NewNodeBoolean(1);
       else return NewNodeBoolean(0);
     }
  case 6:
      if((a->valuetype == B) && (b->valuetype == B)){
       llvm_cmp(file,"==",a,b);
       if((a->content->b) + (a->content->b) != 1) return NewNodeBoolean(1);
       else return NewNodeBoolean(0);
      }
      else if (tab_comp[a->valuetype][b->valuetype] == B){
	llvm_cmp(file,"==",a,b);
	if(int2float(a) == int2float(b)) return NewNodeBoolean(1);
	else return NewNodeBoolean(0);
     }
  case 7:
     if((a->valuetype == B) && (b->valuetype == B))
       return NewNodeBoolean(a->content->b *  b->content->b);
  case 8:
     if((a->valuetype == B) && (b->valuetype == B))
       return NewNodeBoolean(1 - a->content->b * b->content->b);

  }
}
