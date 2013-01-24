#include "node.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define FILENAME "./test.ll"
void llvm_cmp(FILE* pFile,char* cmp, Node* a, Node *b);
void llvm_if();
void llvm_for();
void llvm_while();
void llvm_def();
void llvm_opr(FILE *pFile, char opr, Node* a, Node *b);
void llvm_title(FILE *pFile);
