#include "dll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
John Abreu
3/26/2018
*/

List add(List L, void *item) {
  List node = (List)malloc(sizeof(List));
  node->next = NULL;
  node->prev = NULL;
  node->item = item;

  if (item == NULL) {
    puts("item is NULL");
    return L;
  }

  if (L == NULL)
    return node;

  List temp;
  temp = L;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = node;
  node->prev = temp;

  return L;
}

void next(List L) { L = L->next; }

void prev(List L) { L = L->prev; }

List rem(List L, void * item, int (*compare)(void * A, void * B)) {
  List temp = L;

  while (temp != NULL) {
    if (compare(temp->item, item) == 0) {
      if (temp->prev != NULL)
        (temp->prev)->next = temp->next;
      if (temp->next != NULL)
        (temp->next)->prev = temp->prev;

      free(temp->item);
      free(temp);
      puts("Successfully deleted");
      return L;
    }
    else {
      temp = temp->next;
    }
  }
  puts("Not in LinkedList");
  return L;
}

void nthNode(List L, int x, void (*print)(void *item)) {
  if (L == NULL) {
    puts("LinkedList is empty");
    return;
  }

  while (x != 0) {
    if (L->next == NULL) {
      puts("This LinkedList does not have that many nodes");
      return;
    } else {
      L = L->next;
      x--;
    }
  }
  print(L->item);
}

void printList(List L, void (*print)(void *item)) {
  List temp;
  int cnt=0;
  temp = L;
  if (temp==NULL){
    puts("No LinkedList");
    return;
  }
  while (temp != NULL){
    print(temp->item);
    temp=temp->next;
    cnt++;
  }
  printf("This LinkedList has %d items\n",cnt);
}
