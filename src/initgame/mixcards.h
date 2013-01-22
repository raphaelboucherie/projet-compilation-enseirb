/**
 * @file   mixcards.h
 * @author D.Ben Brahim M.Wang
 * @date   March, 2012
 * @brief  mixcards utilities (header)
 *
 * This file contains the functions used for managing the cardspile and mixing the 
 * cards.
 */

#ifndef _MIXCARDS_
#define _MIXCARDS_

//#include "structure.h"
#define NUMBER_CARDS 102
#define TYPE_CARDS 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
//#include <ncurses.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>

struct cardspile{
  //represents the cardspile
  char cards[NUMBER_CARDS+1];
  //number of cards
  unsigned int  size;
};
/**
 * @brief provides an empty pile
 */
struct cardspile * empty__pile(void);


#endif //_MIXCARDS_
