#include<stdio.h>
#include "llvm.h"
extern int cpt;
extern int res;
extern int tab_plus[4][4];
extern int tab_mult[4][4];
extern int tab_comp[4][4];
void llvm_title(FILE *pFile){
  fprintf(pFile,"@str = constant[7 x i8] c\"=> %%");
  fprintf(pFile,"d\\0A\\00\"\n");
  fprintf(pFile,"declare i32 @printf(i8*, ...)\n\n");
}

void llvm_opr(FILE *pFile, char opr, Node* a, Node *b){
  cpt++;
  int x,y;
  float w,z;
  if(opr == '+' || opr == '-'){
    switch (tab_plus[a->valuetype][b->valuetype]){
    case I :{
      x = a->content->e;
      y = b->content->e;
      if(opr == '+')	fprintf(pFile, "%%r%d = add i32 %d, %d \n", cpt, x, y);
      else		fprintf(pFile, "%%r%d = sub i32 %d, %d \n", cpt, x, y);
      break;
    }
    case F :
      w = int2float(a);
      z = int2float(b);
      if(opr == '+')fprintf(pFile, "%%r%d = fadd float %fe+00, %fe+00 \n", cpt, w, z);
      else fprintf(pFile, "%%r%d = fsub float %f, %f \n", cpt, w, z);
      break;
    }
  }

  else if(opr == '*' || opr == '/'){
    switch (tab_mult[a->valuetype][b->valuetype]){
    case I :
      x = a->content->e;
      y = b->content->e;
      if(opr =='*')fprintf(pFile, "%%r%d = mul i32 %d, %d \n", cpt, x, y);
      else	fprintf(pFile, "%%r%d = div i32 %d, %d \n", cpt, x, y);
     
      break;
    case F :
      w = int2float(a);
      z = int2float(b);
      if(opr == '*')fprintf(pFile, "%%r%d = fmul float %f,%f \n", cpt, w, z);
      else 	 fprintf(pFile, "%%r%d = fdiv float %f, %f \n", cpt, w, z);
      break;
    }
  }
}

void llvm_cmp(FILE *pFile, char* cmp, Node* a, Node *b){ 
  
  cpt++;
  int x,y;
  float w = int2float(a);
  float z = int2float(b);
  if(a->valuetype == I && b->valuetype == I){
    x = a->content->e;
    y = b->content->e;
    if (strcmp(cmp, "==") == 0) 
      fprintf(pFile, "%%r%d = icmp eq i32 %d, %d \n", cpt, x , y);

    else if(strcmp(cmp , "!=") == 0) 
      fprintf(pFile, "%%r%d = icmp eq i32 %d, %d \n", cpt, x,y);

      
    else if (strcmp(cmp , ">")==0) {
      if (x >= 0 && y >= 0)
	fprintf(pFile, "%%r%d = icmp ugt i32 %d, %d \n", cpt, x,y);
      else
	fprintf(pFile, "%%r%d = icmp sgt i32 %d, %d \n", cpt, x,y);
    }
      
    else if(strcmp(cmp , ">=")==0) {
      if (x >= 0 && y >= 0)
	fprintf(pFile, "%%r%d = icmp uge i32 %d, %d \n", cpt, x,y);
      else
	fprintf(pFile, "%%r%d = icmp sge i32 %d, %d \n", cpt, x,y);
    }

      
    else if (strcmp(cmp ,"<" )==0){
      if (x >= 0 && y >= 0)
	fprintf(pFile, "%%r%d = icmp ult i32 %d, %d \n", cpt, x,y);
      else
	fprintf(pFile, "%%r%d = icmp slt i32 %d, %d \n", cpt, x,y);
    }
      
    else if (strcmp(cmp ,"<=")== 0) { 
      if (x >= 0 && y >= 0)
	fprintf(pFile, "%%r%d = icmp ule i32 %d, %d \n", cpt, x,y);
      else
	fprintf(pFile, "%%r%d = icmp use i32 %d, %d \n", cpt, x,y);
    }
   }
   else if(tab_comp[a->valuetype][b->valuetype]==B && 
	   ((a->valuetype == F)||(b->valuetype))){
     w = int2float(a);//->content->e;
     z = int2float(a);//->content->e;
     if (!strcmp(cmp, "==" ))
       fprintf(pFile, "%%r%d = fcmp oeq float %f, %f \n", cpt, w, z);
    
     else if (!strcmp(cmp, "!="))
       fprintf(pFile, "%%r%d = fcmp one float  %f, %f \n", cpt, w, z);
    
     else if (!strcmp(cmp, ">")) 
       fprintf(pFile, "%%r%d = fcmp ogt float  %f, %f \n", cpt, w, z);
    
    else if (!strcmp(cmp,">="))
      fprintf(pFile, "%%r%d = fcmp oge float  %f, %f \n", cpt, w, z);
      
    else if(!strcmp(cmp, "<"))
      fprintf(pFile, "%%r%d = fcmp olt float  %f, %f \n", cpt, w, z);
      
    else if (!strcmp(cmp,"<="))
      fprintf(pFile, "%%r%d = fcmp ole float  %f, %f \n", cpt, w, z);
   }
}


void llvm_main(FILE *pFile){

  char buffer[] = "define i32 @main(){\n";
  fprintf(pFile,"%s", buffer);
}


void llvm_fini(FILE *pFile){
  char buffer[] = "}";
  fprintf(pFile,"ret i32 0;\n");
  fprintf(pFile,"%s", buffer);
}

void llvm_return(FILE *pFile,Node *a){
  fprintf(pFile, "%%ptr%d = alloca i32\n",res);
  fprintf(pFile, "store i32 %d, i32* %%ptr%d\n", a->content->e, res);
  res++;
}

void llvm_print(FILE *pFile){
  fprintf(pFile,"call i32 (i8*, ...)*");
  fprintf(pFile,"@printf(i8* getelementptr ([7 x i8]* @str, i32 0, i32 0), i32 %%r%d)\n",cpt);
}

void llvm_if(FILE *pFile){
  cpt++;
  fprintf(pFile,"%%r%d = load i32* %%ptr%d\n", cpt, res-2);
  cpt++;
  fprintf(pFile,"%%r%d = load i32* %%ptr%d\n", cpt, res-1);
  cpt++;
  fprintf(pFile,"%%r%d = select i1 %%r%d,i32 %%r%d,i32 %%r%d\n" ,cpt, cpt-3, cpt-2, cpt-1);
  llvm_print(pFile);
}
