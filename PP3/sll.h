#ifndef SLL_H
#define SLL_H
#include <stdio.h>
#include <stdlib.h>

/*
John Abreu
2/2/2018
*/

typedef struct node {
  char *w;
  struct node *next;
} Node;

typedef Node *NodePtr;

/* prototypes */
void addNode(NodePtr L, char *word);
void printList(NodePtr L);
#endif /* SLL_H */
