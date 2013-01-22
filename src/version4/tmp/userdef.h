#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
typedef enum {INT_T = 0, FLOAT_T = 1, STRING_T = 2, BOOL_T = 3, UNDEF_T = 4} typpo;
#define I 0
#define F 1
#define S 2
#define B 3
#define U -1
typedef struct {
  int e;
  float f;
  char *s;
  enum {VRAI = 1, FAUX = 0} b;
}Valeur;

typedef struct{
  char *name;
  typpo type;
  Valeur *value;
  struct varIndex * next ;
} VarIndex;

typedef struct{
  VarIndex courant;
  VarIndex englobant;
  struct Table *back;
} Table;

/* /\*Function*\/ */
VarIndex* NewVarIndex();
void InitVarIndex(VarIndex *);
void PrintVarIndex(VarIndex *);
void AddVarIndex(char *nom);
void SearchIndex();
void InitTable();
void AddTable(VarIndex *);
void FreeTable();
/* //void init_type_tab(); */
