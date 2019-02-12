#include <stdio.h>
#include <stdlib.h>

/*
John Abreu
3/26/2018
*/

typedef struct square{
  int row;
  char * color;    // the color of the space. either red, blue, orange or green;
  char * special;  // the special space. There are four values for special spaces: GOBACK, GOFORWARD
                 // WIN and NONE (i.e. nothing special)
  int x;           // if you land on a special space, this is how many spaces to move.
                 //If you land on WIN, the game is over and you win.
}square_t;

typedef square_t * SQUARE;


SQUARE newSquare(int row, char* color, char* special, int x);
void toString(SQUARE s);
