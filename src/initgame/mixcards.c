/**
 * @file   mixcards.c
 * @author D. Ben Brahim M.Wang
 * @date   March, 2012
 * @brief  Mixcard code file
 */

#include "structure.h"
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

int 
size__cardspile(const struct cardspile * p){
  assert(p != NULL);
  return ( p->size );
}

void 
add__cardspile(struct cardspile * p, char card){
  assert(p != NULL);
  
  if(p->size < NUMBER_CARDS){
    p->cards[p->size] = card;
    p->size ++;

    p->cards[p->size] = '\0';
  }
 
}

char 
remove__cardspile(struct cardspile * p){
  assert(p != NULL);
  char card;

  p->size --;
  card = p->cards[p->size];

  p->cards[p->size] = '\0';
  
  return card;
  
}

int 
is__empty_cardspile(const struct cardspile * p){
  return ( p->size == 0);
}

struct cardspile * 
random__cardspile(void){
  
  struct cardspile pile;
  struct cardspile * p = &pile;

  p = empty__pile();
  assert(p != NULL);
  
  int card;
  int tabcards[TYPE_CARDS];
   
  int nb = NUMBER_CARDS/TYPE_CARDS;

  for (int i = 0 ; i < TYPE_CARDS; i++) //initialization of tabcards
    tabcards[i] = 0;
  
  srand((unsigned int)time(0));
  int i = 0;
  while (i < NUMBER_CARDS ){//while 
    
    card = rand() % TYPE_CARDS;

    if(tabcards[card] >= nb)
      continue;

    tabcards[card]++;
    add__cardspile(p,type__cards[card]);
    i++;
  }

  return p;
}
void 
free_cardspile(struct cardspile *p){
  assert(p != NULL);
  
  free(p);
}


void
affiche(const struct cardspile * p){
  assert(p != NULL);
  
  for(int i = 0 ; i < size__cardspile(p) ; i++)
      printf("%c",p->cards[i]);

  printf("\n");
}

/*****************test***************************/
/*

int main(void)//test
{ 
  struct cardspile pile;
  struct cardspile * p = &pile;

  p = empty__pile();
  p = random__cardspile();

  printf("%d\n",size__cardspile(p));
  affiche(p);
  printf("\n");

  char card;
  card = remove_
_cardspile(p);
  printf("1***%c\n",card);
  affiche(p);
  printf("\n");

  card = remove__cardspile(p);
  printf("2***%c\n",card);
  affiche(p);
  printf("\n");

  card = remove__cardspile(p);
  printf("3***%c\n",card);
  affiche(p);
  printf("\n");

  card = remove__cardspile(p);
  printf("4***%c\n",card);
  affiche(p);
  printf("\n");
  return 0;

}
  
*/
