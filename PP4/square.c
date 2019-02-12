#include "square.h"

/*
John Abreu
3/26/2018
*/

SQUARE newSquare(int row, char* color, char* special, int x) {
  SQUARE s = (SQUARE)malloc(sizeof(square_t));
  s->row = row;
  s->color = color;
  s->special = special;
  s->x = x;

  return s;
}

void toString(SQUARE s) {
  if (s!=NULL) {
    printf("%d: %s %s %d\n", s->row, s->color, s->special, s->x);
  }
  else {
    puts("NULL Square");
  }
}
