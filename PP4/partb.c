#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "dll.h"
#include "square.h"

/*
John Abreu
3/26/2018
*/

SQUARE createBoardSpace(FILE *file, int row);
List nextMove(List l);
List moveUntil(List l, char * c);
List moveFor(List l, int dir, int x);
int randomNumber(int min, int max);

int main() {
  SQUARE board = NULL;
  int i, numTimes = 0, boardSize = 0;
  float average = 0.0;
  FILE *fp;
  List lst = NULL;

  srand(time(NULL));

  fp = fopen("board.txt", "r");
  while (1) {
    board = createBoardSpace(fp, boardSize);
    if (board!=NULL){
      lst = add(lst, board);
    }
    else {
      break;
    }
    boardSize++;
  }
  fclose(fp);

  //printList(lst, toString);

  if (lst!=NULL) {
    SQUARE space = lst->item;
    while (strcmp(space->special, "WIN")!=0) {
      lst = nextMove(lst);
      space = lst->item;
      toString(space);
    }
  }
}

SQUARE createBoardSpace(FILE *file, int row) {
  char *color;
  char *special;
  char dummy;
  int tempint;
  SQUARE board;

  board = (SQUARE)malloc(sizeof(square_t));
  board->row = row;
  board->color = (char *)malloc(sizeof(char) * 10);
  board->special = (char *)malloc(sizeof(char) * 10);

  fscanf(file,"%s%s%d%c", board->color, board->special, &tempint, &dummy);
  if (feof(file)){
    return NULL;
  }
  board->x = tempint;

  return board;
}

List nextMove(List l) {
  int x = randomNumber(4, 1);
  SQUARE s = l->item;

  switch (x) {
    case 1:
      moveUntil(l, "RED");
      break;
    case 2:
      moveUntil(l, "BLUE");
      break;
    case 3:
      moveUntil(l, "GREEN");
      break;
    case 4:
      moveUntil(l, "ORANGE");
      break;
  }

}

List moveUntil(List l, char * c) {
  SQUARE space = l->item;

  while(strcmp(space->color, c)!=0) {
    if (strcmp(space->special, "WIN")==0) {
      return l;
    }
    if (l->next != NULL) {
      l = l->next;
      space = l->item;
    }
  }

  if (strcmp(space->special, "NONE")==0) {
      return l;
  }
  else if (strcmp(space->special, "GOFORWARD")==0) {
      moveFor(l, 1, space->x);
      return l;
  }
  else if (strcmp(space->special, "GOBACKWARD")==0) {
      moveFor(l, 0, space->x);
      return l;
  }
  else {
      return l;
  }

}

//If dir is 0, the direction is backwards. If dir is anything other than 0, the direction is forwards
List moveFor(List l, int dir, int x) {
  if (dir == 0) {
    while(x!=0) {
      if(l->prev != NULL) {
        l = l->prev;
      }
      x = x-1;
    }
  }
  else {
    while(x!=0) {
      if(l->next != NULL) {
        l = l->next;
      }
      x = x-1;
    }
  }
  return l;
}

int randomNumber(int min, int max){
  double scaled = (double)rand()/RAND_MAX;

  return (max - min +1)*scaled + min;
}
