#include "sll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
John Abreu
2/2/2018
*/

void addNode(NodePtr L, char *word) {
  int len = strlen(word);
  char *w = (char *)malloc(len);

  for(int i=0; i<len; i++) {
    *(w+i) = *(word+i);
  }

  NodePtr p;


  if(L->w == NULL) {
    L->w = w;
  }
  else if(L->next == NULL){
    NodePtr node = (NodePtr)malloc(sizeof(Node));
    node->w = w;
    node->next = NULL;
    L->next = node;
  }
  else {
     addNode(L->next, w);
  }
}

void printList(NodePtr L) {
  if(L==NULL) {
  }
  else {
  }
  while (L!=NULL) {
    printf("chunk: %s\n", L->w);
    L = L->next;
  }
  puts("All Done, Woohoo!");
}
