/**
 * @file   mixcards.c
 * @author D. Ben Brahim M.Wang
 * @date   March, 2012
 * @brief  Mixcard code file
 */

//#include "structure.h"
#include "mixcards.h"

static char type__cards[TYPE_CARDS] = {'P','S','K','T','B','C'};

struct cardspile * 
empty__pile(void){

  struct cardspile * p = NULL;

  p = (struct cardspile*) malloc(sizeof(struct cardspile));
  
  if(p == NULL)
    return NULL;
  
  p->size = 0;
  p->cards[p->size] = '\0'; 
  return p;
}
