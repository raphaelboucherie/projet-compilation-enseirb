/**
 * @file   mixcards.h
 * @author D.Ben Brahim M.Wang
 * @date   March, 2012
 * @brief  mixcards utilities (header)
 *
 */
#ifndef _USERDEF_
#define _USERDEF_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>

typedef enum {INT_T = 0, FLOAT_T = 1, STRING_T = 2, BOOL_T = 3, UNDEF_T = 4} typpo;
#define I 0
#define F 1
#define S 2
#define B 3
#define U -1
#define MAXSIZE 100
typedef struct {
  int e;
  float f;
  char *s;
  enum {VRAI = 1, FAUX = 0} b;
}Valeur;

typedef struct{
  char name[MAXSIZE];
  typpo type;
  Valeur *value;
  struct varIndex * next ;
} VarIndex;

typedef struct{
  VarIndex courant;
  VarIndex englobant;
  struct Table *back;
} Table;
VarIndex strMem[10000];
VarIndex* NewVarIndex();
void InitVarIndex(VarIndex *element);
void PrintVarIndex(VarIndex *element);
#endif //_USERDEF_
