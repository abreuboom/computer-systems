#ifndef SLL_H
#define SLL_H
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char *w;
  int frequency;

  struct node *next;
} Node;

typedef Node *NodePtr;

/* prototypes */
void addNode(NodePtr L, char *word);
void printList(NodePtr L);
#endif /* SLL_H */
