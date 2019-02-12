#include "player.h"
#include "dll.h"
#include "square.h"
#include <string.h>

/*
John Abreu
3/26/2018
*/

Player newPlayer(char * name, List row) {
  Player p = (Player)malloc(sizeof(player_t));
  p->name = name;
  p->row = (List)malloc(sizeof(List));
  p->row = row;

  return p;
}

void printPlayer(Player p) {
  SQUARE space = (p->row)->item;
  printf("%s is at the space ", p->name);
  toString(space);
}
