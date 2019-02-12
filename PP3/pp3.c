#include "sll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
John Abreu
2/2/2018
*/

int main() {
  int i = 0, x = 0;
  char c = getchar();
  char *w = (char *)malloc(sizeof(char));
  NodePtr node = (NodePtr)malloc(sizeof(Node));
  node->w = NULL;
  node->next = NULL;

  while (c != '\n') {
    if (i%80 == 0 && i>0){
      addNode(node, w);
      free(w);
      w = (char *)malloc(sizeof(char));
      x = 0;
      *(w+x) = c;
      c = getchar();
    }
    else {

      w = (char *)realloc(w, x+1);
      *(w+x) = c;
      c = getchar();
    }
    i++;
    x++;

  }
  if(strlen(w) > 0) {
    w = (char *)realloc(w, x);
    addNode(node, w);
  }
  free(w);


  printList(node);

}
