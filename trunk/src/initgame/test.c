#include "initclient.h"
#include "mixcards.h"
#include "initmap.h"
/*
struct game game;

void
init_game(int nplayers) {
  int i;
  
  struct client* player = (struct client*) malloc(nplayers * sizeof *player);
  game.player = player;
  game.nplayers = nplayers;
  // init names
  for ( i = 0; i < nplayers; i++) {
    char *name = (char *) malloc(CLIENT_NAME_SIZE * sizeof *name);
    //printf(name, CLIENT_NAME_SIZE, "Player #%d", i);
    game.player[i].name  = name;
    game.player[i].pid   = -1;
    game.player[i].alive = 0;
  }
  }*/


int main(int argc ,char *argv[]){


  //initialization of map
  struct map *m = NULL;
  m = random__map();
  affiche__map(m);

  //initialization of cards pile
  struct cardspile *p = NULL;
  p = random__cardspile();
  affiche(p);

  /*char hc[INIT_NB_CARDS][NUMBER_PLAYERS];
  handcards(p,hc);

  int nb = atoi(argv[1]);

  struct client *c = NULL;
  c = empty__client();
  init__client(c,nb,hc,m);*/

  //init_all_clients(p,m);

  //initialization of game

  //it_game(NUMBER_PLAYERS); 
  return 0;
}
