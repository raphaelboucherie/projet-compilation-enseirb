/**
 * @file   initmap.h
 * @author D.Ben Brahim M.Wang
 * @date   March, 2012
 * @brief  map utilities (header)
 *
 * This file contains the functions used for initializing the map
 */

#ifndef _INITMAP_
#define _INITMAP_

#include "structure.h"

/**
 * @brief provides an empty map
 */
struct map * empty__map(void);
/**
 * @brief 
 */
struct map * random__map(void);
/**
 * @brief 
 */
void free_map(struct map *m);
/**
 * @brief 
 */
void affiche__map(struct map *m); 

#endif // _INITMAP_ 
