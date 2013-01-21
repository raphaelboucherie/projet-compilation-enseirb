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

#include "structure.h"


/**
 * @brief provides an empty pile
 */
struct cardspile * empty__pile(void);
/**
 * @brief returns the cardspile size
 */
int size__cardspile(const struct cardspile * );
/**
 * @brief adds a card to the pile
 */
void add__cardspile(struct cardspile * , char );
/**
 * @brief removes the last card from the pile
 */
char remove__cardspile(struct cardspile * );
/**
 * @brief tests whether the pile is empty or not
 */
int is__empty_cardspile(const struct cardspile * );
/**
 * @brief returns a random pile
 */
struct cardspile * random__cardspile(void);
/**
 * @brief sets the pile free
 */
void free_cardspile(struct cardspile *p);
/**
 * @brief prints the pile
 */
void affiche(const struct cardspile * p);

#endif //_MIXCARDS_
