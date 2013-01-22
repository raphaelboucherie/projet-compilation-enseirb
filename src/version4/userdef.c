#include "userdef.h"
VarIndex *NewVarIndex(){
  VarIndex * element = NULL;
  element = (VarIndex*)malloc(sizeof(VarIndex));
  strcpy(element->name,"");
  element->type = -1;
  element->value->e = 0;
  element->value->f = 0.0;
  element->value->s = NULL;
  element->value->b = 0;
  element->next = NULL;
  return element;
}
void InitVarIndex(VarIndex *element){ 
  strcpy(element->name, "");
  element->type = -1;
  element->value->e = 0;
  element->value->f = 0.0;
  element->value->s = NULL;
  element->value->b = 0;
  element->next = NULL; 
}
void PrintVarIndex(VarIndex *element){
  if(element->type == INT_T )
    printf("%d",element->value->e);
  else if(element->type == FLOAT_T)
    printf("%f",element->value->f);
  else if(element->type == STRING_T)
    printf("%s",element->value->s);
  else if(element->type == BOOL_T)
    {
      if(element->value->b == 0)
	printf("=>true");
      else
	printf("=>nil");
    }
  else
    printf("type indef");
  printf("\n");
}
