/**
 * @file   init_client.c
 * @author D. Ben Brahim M.Wang
 * @date   March, 2012
 * @brief  client utilities (code file)
 *
 * This file contains the functions used for managing the client structure.
 */



#include "initclient.h"
#include "initmap.h"
#include "mixcards.h"

#define __USE_BSD 1
#include <unistd.h>
#include <getopt.h>

#define MAX 100

struct client * 
empty__client(void)
{
  struct client * c = NULL;

  c = malloc(sizeof(struct client));
  if (c == NULL)
    return NULL;
 
  c->alive = 1;
  c->name = "";
  c->r = NULL;
  c->w = NULL;
  c->pid = 1;
 
  return c;
}

void 
handcards(struct cardspile *p,char handcards[][NUMBER_PLAYERS]){  
  assert(p != NULL);
  char card;
  int i,j;

  for(j = 0; j < NUMBER_PLAYERS; j++){
    for(i = 0; i < INIT_NB_CARDS ;i++)
      {
	card = remove__cardspile(p);
	handcards[i][j] = card; 
      }
  }
}
  

int
init__client(struct client * c,int nb,char hc[][NUMBER_PLAYERS],struct map *m){
  
  assert(c != NULL);

  // DIR *pdir;
  int position = 0; 
  int i,j;

  /*pdir = opendir("../clientfile");
  if(!pdir)
    {
      i = mkdir("../clientfile",0777);
      
      if(i == -1)
	printf("create directory failed\n");

      else
	printf("create directory clientfile sucessful\n");
	}*/

  //char *name = (char *) malloc(CLIENT_NAME_SIZE * sizeof *name);
  //snprintf(name, CLIENT_NAME_SIZE, "Player #%d", nb);

  printf("0\t : Sending Hello to client %s\n", c->name);
  fflush(stdout);
  fprintf(c->w,"Player %d\n",nb);
  fflush(c->w);

  fprintf(c->r ,"Map");
  fflush(c->r);
  for(i = 1; i < NUMBER_SQUARES - 1 ; i++)
    {
      fprintf(c->r,"%c",m->symbols[i]);
      fflush(c->r);
    }
  fprintf(c->r,"\n");
  fflush(c->r);

  for(j = 0; j < NUMBER_PLAYERS; j++){
    fprintf(c->r,"Handsize %d %d ",j,INIT_NB_CARDS);
    fflush(c->r);
    for( i = 0 ; i < INIT_NB_CARDS ; i++)
      {
	fprintf(c->r,"%8c",hc[i][j]);
	fflush(c->r);
      }
    fprintf(c->r,"\n");
    fflush(c->r);
  }

  for(j = 0; j < NUMBER_PLAYERS ;j++){
    fprintf(c->r,"Position %d",j);
    fflush(c->r);
    for(i = 0; i < PIRATE ;i++)
      {
	fprintf(c->r,"%8d",position);
	fflush(c->r);
      }
    fprintf(c->r,"\n");
    fflush(c->r);
  }
  fprintf(c->r,"Done");
  fflush(c->r);
  
  return 0;
}

void
free__client(struct client *c){
  assert(c != NULL);
  free(c->w);
  free(c->r);
  free(c);
}
  
void
init_all_clients(struct cardspile * p, struct map * m){

  assert(p != NULL);
  assert(m != NULL);

  char hc[INIT_NB_CARDS][NUMBER_PLAYERS];
  handcards(p,hc);

  struct client * c[NUMBER_PLAYERS];

  int i;
  for(i = 0; i < NUMBER_PLAYERS; i++){
     c[i] = empty__client();
     assert(c[i] != NULL);
     exec_client("1",c[i]);
     init__client(c[i],i,hc,m);
  }

} 
