/**
 * @file   initmap.h
 * @author D.Ben Brahim M.Wang
 * @date   March, 2012
 * @brief  map code file
 *
 * This file contains the functions used for initializing the map.
 */

#include "initmap.h"
static char type__cards[TYPE_CARDS] = {'P','S','K','T','B','C'};

struct map * 
empty__map(void){
  int i;
  struct map *m = NULL;  
  m = malloc(sizeof(struct map));

  if(m == NULL)
    return NULL;

  m->symbols[0] = '\0';
  for(i = 0; i < NUMBER_SQUARES ; i++)
    m->pirates[i] = 0;
      
  return m;
}

struct map * 
random__map(void){
  int i, j;
  struct map *m = NULL;

  m = empty__map();
  assert(m != NULL);

  m->pirates[0] = NUMBER_PLAYERS * PIRATE;
  
  int symbol;
  int tabsquares[TYPE_CARDS];
   
  int nb = (NUMBER_SQUARES - 2)/TYPE_CARDS;

  srand((unsigned int)time(0));

  for (i = 0 ; i < nb; i++)
    { 
      for (j = 0 ; j < TYPE_CARDS; j++) 
	tabsquares[j] = 0;
      j = 0;
      while(j < TYPE_CARDS){ 
	symbol = rand() % TYPE_CARDS;
	if (tabsquares[symbol] == 0)
	  {
	    tabsquares[symbol]++;
	    m->symbols[i*TYPE_CARDS + j + 1] = type__cards[symbol];
	    j++;
	  }
      }
    }


  m->symbols[NUMBER_SQUARES-1]= '1';

  return m;
}

void free_map(struct map *m){
  assert( m != NULL);
  free(m);
}

void affiche__map(struct map *m){
  
  int j;
  assert(m != NULL);

  for(j = 0 ; j < NUMBER_SQUARES ; j++)
    printf(" %c",m->symbols[j]);
  printf("\n");   
  
  for(j = 0 ; j < NUMBER_SQUARES ; j++)
    printf(" %d",m->pirates[j]);
  printf("\n");
  

}

/**********************test**************************/

/*
int main(void){

  struct map * map;
  
  map = random__map();
  affiche__map(map);
  printf("\n");
  return 0;

  }*/

  

