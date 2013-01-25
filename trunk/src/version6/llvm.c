#include<stdio.h>
#include "llvm.h"
extern int cpt;
void llvm_title(FILE *pFile){
  
  char buffer[] = "@str = constant[7 x i8] c\"=> \%d\0A\00\"\n";
    // write(STDOUT_FILENO, buffer, file * sizeof(char));
  fprintf(pFile,"%s\n", buffer);
}

void llvm_opr(FILE *pFile, char opr, Node* a, Node *b){

 
  int x,y;
  float w,z;

  switch (opr){
  case '+':
    switch (a->valuetype){
    case I :{
      x = a->content->e;
      y = b->content->e;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", x, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", y, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "%%r%d = add i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      break;
    }
    case F :
       w = a->content->e;
       z = b->content->e;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", w, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", z, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "%%r%d = fadd float %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      break;
    }
    break;
 
 case '-':
  switch (a->valuetype){
    case I :
       x = a->content->e;
       y = b->content->e;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", x, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", y, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "%%r%d = sub i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      break;
    case F :
       w = a->content->e;
       z = b->content->e;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", w, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", z, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "%%r%d = fsub float %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      break;
    }
    break;

       
  case '*':
    switch (a->valuetype){
    case I :
       x = a->content->e;
       y = b->content->e;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", x, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", y, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "%%r%d = mul i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      break;
    case F :
       w = a->content->e;
       z = b->content->e;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", w, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", z, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "%%r%d = fmul float %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      break;
    }
    break;


  case '/':
    switch (a->valuetype){
    case I :
       x = a->content->e;
       y = b->content->e;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", x, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", y, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "%%r%d = div i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      break;
    case F :
       w = a->content->e;
       z = b->content->e;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", w, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", z, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "%%r%d = fdiv float %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      break;
    }
    break;
  }
}


 void llvm_cmp(FILE *pFile, char* cmp, Node* a, Node *b){ 

  int x,y;
  float w,z;

  switch (a->valuetype){
  case I :
    x = a->content->e;
    y = b->content->e;
    if (!strcmp(cmp, "==")) {

      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", x, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", y, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "%%r%d = icmp eq i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
    }

    else if(!strcmp(cmp , "!=")) {
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", x, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", y, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "%%r%d = icmp eq i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
    }
      
    else if (!strcmp(cmp , ">")) {
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", x, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", y, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      if (x >= 0 && y >= 0)
	fprintf(pFile, "%%r%d = icmp ugt i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      else
	fprintf(pFile, "%%r%d = icmp sgt i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
    }
      
    else if(!strcmp(cmp , ">=")) {
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", x, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", y, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      if (x >= 0 && y >= 0)
	fprintf(pFile, "%%r%d = icmp uge i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      else
	fprintf(pFile, "%%r%d = icmp sge i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
    }

      
    else if (!strcmp(cmp ,"<" )){
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", x, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", y, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      if (x >= 0 && y >= 0)
	fprintf(pFile, "%%r%d = icmp ult i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      else
	fprintf(pFile, "%%r%d = icmp slt i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
    }
      
    else if (!strcmp(cmp ,"<=")) { 
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", x, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      fprintf(pFile, "store i32 %d, i32* %%r%d \n", y, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca i32 \n", cpt);
      if (x >= 0 && y >= 0)
	fprintf(pFile, "%%r%d = icmp ule i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      else
	fprintf(pFile, "%%r%d = icmp use i32 %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
    }
    break;
  

  case F:
    w = a->content->e;
    z = b->content->e;
    if (!strcmp(cmp, "==" )){
	fprintf(pFile, "%%r%d = alloca float \n", cpt);
	fprintf(pFile, "store float %f, float* %%r%d \n", w, cpt);
	cpt++;
	fprintf(pFile, "%%r%d = alloca float \n", cpt);
	fprintf(pFile, "store float %f, float* %%r%d \n", z, cpt);
	cpt++;
	fprintf(pFile, "%%r%d = alloca float \n", cpt);
	fprintf(pFile, "%%r%d = fcmp oeq float %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
      }
    
    else if (!strcmp(cmp, "!=")) {
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", w, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", z, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "%%r%d = fcmp one float %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
    }
    
    else if (!strcmp(cmp, ">")) { 
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", w, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", z, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "%%r%d = fcmp ogt float %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
    }
    
    else if (!strcmp(cmp,">=")) {
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", w, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", z, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "%%r%d = fcmp oge float %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
    }
    
    else if(!strcmp(cmp, "<")) { 
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", w, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", z, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "%%r%d = fcmp olt float %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
	      }
    
    else if (!strcmp(cmp,"<=")) {
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", w, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "store float %f, float* %%r%d \n", z, cpt);
      cpt++;
      fprintf(pFile, "%%r%d = alloca float \n", cpt);
      fprintf(pFile, "%%r%d = fcmp ole float %%r%d, %%r%d \n", cpt, cpt-1, cpt-2);
    }
    break;
  }
 }

void llvm_main(FILE *pFile){

  char buffer[] = "define i32 @main(){\n";
  fprintf(pFile,"%s", buffer);
}


void llvm_fini(FILE *pFile){
  char buffer[] = "}";
  fprintf(pFile,"%s", buffer);
}

void llvm_return(FILE *pFile){
  fprintf(pFile,"ret i32 0;\n");
}


/* int main(void){ */
/*   FILE* file = fopen("file.ll","w"); */
/*   if (file == NULL) */
/*     perror("open"); */
  
/*   Node *a = NewNodeInt(1); */
/*   Node *b = NewNodeInt(2); */

/*   llvm_title(file); */
/*   llvm_opr(file,'+',a,b); */

/*   return 1; */
    

/* } */
