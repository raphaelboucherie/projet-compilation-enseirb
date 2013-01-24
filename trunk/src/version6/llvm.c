#include "llvm.h"
int file = 0;
void llvm_title(void){
  char buffer[] = "@str = constant[7 x i8] c\"=> %d\0A\00\""
  write(STDOUT_FILENO, buffer, file * sizeof(char)); 
}

void llvm_opr(char opr, Node* a, Node *b){

  switch (opr){
  case '+':{
    switch (a->valuetype){
    case: I
    }
  }
  case '-':{}
  case '*':{}
  case '/':{}
  }
}
int main(void){
  file = open(FILENAME,O_WRONLY|O_CREAT,0666);
  if (file == -1)
    perror("open");

  return 1;
    

}
