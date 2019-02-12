#ifndef DLL_H
#define DLL_H
#include <stdio.h>
#include <stdlib.h>

/*
John Abreu
3/26/2018
*/

typedef struct node{
   void * item;
   struct node * next;
   struct node * prev;
} Node;

typedef Node *List;

/* prototypes */
List add(List L, void * item);
void next(List L);
void prev(List L);
List rem(List L, void * item, int (*compare)(void * A, void * B));
void nthNode(List L, int x, void (*print)(void *item));
int contains(void * item, int (*compare)(void * A, void * B));
void printList(List L, void (*print)(void *item));
#endif /* DLL_H */
