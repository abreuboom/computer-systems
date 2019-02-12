#include <stdio.h>
#include <stdlib.h>
#include "dll.h"

/*
John Abreu
3/26/2018
*/

typedef struct player{
  char * name;
  List row;
}player_t;

typedef player_t * Player;

Player newPlayer(char * name, List row);
void printPlayer(Player p);
