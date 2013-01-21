/**
 * @file   init_client.h
 * @author D.Ben Brahim M.Wang
 * @date   March, 2012
 * @brief  client utilities (header)
 *
 * This file contains the functions used for managing the client structure.
 */

#ifndef _INIT_CLIENT_
#define _INIT_CLIENT_
#include "structure.h"

#include <dirent.h>
/**
 * @brief provides an empty client structure.
 */
struct client * empty__client(void);

/**
 * @brief returns the table of cards after distributing 24 cards.
 */ 
void handcards (struct cardspile * ,char [][NUMBER_PLAYERS]);

/**
 * @brief returns the message that the server sends to one player.
 */
int init__client(struct client *  ,int  ,char [][NUMBER_PLAYERS],struct map * m);

/**
 * @brief free client.
 */
void free__client(struct client *);

/**
 * @brief returns the message that the server sends to all players.
 */
void init_all_clients(struct cardspile * p, struct map * m);

//struct client * exec_client(const char *exec_name, struct client *client);

//void handle_write(struct client *client);

#endif //_INIT_CLIENT_
