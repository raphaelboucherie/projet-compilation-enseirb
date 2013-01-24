#include "node.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define FILENAME "./test.ll"
void llvm_title(void);
void llvm_opr(char opr, Node* a, Node *b);
void llvm_cmp(char cmp, Node* a, Node *b);
void llvm_if();
void llvm_for();
void llvm_while();
void llvm_def();
