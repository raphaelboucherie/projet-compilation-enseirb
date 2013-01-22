#include "userdef.h"
VarIndex *NewVarIndex(){
  VarIndex * element = NULL;
  element = (VarIndex*)malloc(sizeof(VarIndex));
  element->name = NULL;
  element->type = -1;
  element->value->e = 0;
  element->value->f = 0.0;
  element->value->s = NULL;
  element->value->b = 0;
  element->next = NULL;
  return element;
}
void InitVarIndex(VarIndex *element){ 
  element->name = NULL;
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

/* int main() { */
/*   return 0; */
/* } */






//void init_type_tab(){

/*   init(tab_plus); */
/*      tab_plus[I][I]=I; */
/*      tab_plus[I][F]=F; */
/*      tab_plus[F][I]=F; */
/*      tab_plus[F][F]=F; */
/*      tab_plus[S][S]=S; */

/*  init(tab_moins); */
/*       tab_moins[I][I]=I; */
/*       tab_moins[I][F]=F; */
/*       tab_moins[F][I]=F; */
/*       tab_moins[F][F]=F; */

/* init(tab_mult); */
/*       tab_mult[I][I]=I; */
/*       tab_mult[I][F]=F; */
/*       tab_mult[F][I]=F; */
/*       tab_mult[F][F]=F; */

/* init(tab_div); */
/*       tab_div[I][I]=F; */
/*       tab_div[I][F]=F; */
/*       tab_div[F][I]=F; */
/*       tab_div[F][F]=F; */

/* init(tab_cmp); */
/*       tab_cmp[I][I]=B; */
/*       tab_cmp[I][F]=B; */
/*       tab_cmp[F][I]=B; */
/*       tab_cmp[F][F]=B; */
/*       tab_cmp[S][S]=B; */

