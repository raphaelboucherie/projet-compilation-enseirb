/**
 * @file   structure.h
 * @author D.Ben Brahim M.Wang
 * @date   March, 2012
 * @brief  Client threads utilities (header)
 *
 * This file contains the methods used for launching threads,
 * attaching their standard input and output to the correct file
 * descriptors, and evntually terminating them when finished.
 */

#ifndef _STRUCTURE_H_
#define _STRUCTURE_H_

/// Allow fdopen, kill without warning
//#define _POSIX_SOURCE 
//we donot understand this 

/******************include******************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ncurses.h>
#include <math.h>
#include <time.h>
#include <sys/types.h>

#define PIRATE 6
#define NUMBER_PLAYERS 5
#define TYPE_CARDS 6
#define NUMBER_CARDS 102
#define NUMBER_SQUARES 38
#define INIT_NB_CARDS 6

#define CLIENT_NAME_SIZE 10

//static char type__cards[TYPE_CARDS] = {'P','S','K','T','B','C'};

/// Check the return value of a system call and exit on error
#define CK_SC(s,msg) do if ((s)==-1) {		\
	perror(msg);				\
	exit(EXIT_FAILURE);			\
  } while (/* CONSTCOND */ 0)
//we donot understand this 

/****servers***/

/**
 * @struct cardspile
 * @brief structure storing the infortmation related to the cards
 */
struct cardspile{
  //represents the cardspile
  char cards[NUMBER_CARDS+1];
  //number of cards
  unsigned int  size;
};
/**
 * @struct map
 * @brief structure storing the information  related to the map
 */

struct map{
  //represents symbols in the map
  char symbols[NUMBER_SQUARES];
  //number of pirates in each case 
  int pirates[NUMBER_SQUARES]; //Not decide
};

#endif // _STRUCTURE_H_
