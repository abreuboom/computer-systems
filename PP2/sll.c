#include "sll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void addNode(NodePtr L, char *word) {
  NodePtr node;
  node = (NodePtr)malloc(sizeof(Node));

  node->w = word;
  node->next = NULL;

  puts("okay");

  if (L == NULL) {
    puts("L is node");
    L = node;
    return;
  }
  else {
    puts("bout to compare");
    if (strcmp(word, L->w) == 0) {
      puts("compared em!");
      L->frequency++;
      return;
    }
    else {
      puts("recurse");
      addNode(L->next, word);
    }
  }
}

NodePtr findMax(NodePtr L) {
  NodePtr list = NULL;
  while (L) {
    NodePtr tmp = L;
    L = L->next;
    tmp->next = list;
    list = tmp;
  }
  return list;
}


void printList(NodePtr L) {
  while (L) {
    printf(" %s: %d", L->w, L->frequency);
    L = L->next;
  }
  printf(" NULL \n");
}
