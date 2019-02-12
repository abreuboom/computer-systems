#include "sll.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getLine(NodePtr L);

int main() {
  char c;
  NodePtr node;

  node = NULL;

  puts("Please type a message:");
  getLine(node);
  puts("swag");
  printList(node);


}

void getLine(NodePtr L) {
  int len, line, i, wordlen;
  char *c, *word;

  line = 0;
  i = 0;
  wordlen = 0;
  c = (char *)malloc(80 * sizeof(char));
  word = (char *)malloc(80 * sizeof(char));

  scanf("%[^STOP]", c);

  while (strcmp((c+i),"\0") != 0) {
      if (*(c+i) == ' ') {
        puts("found a space");
        addNode(L, word);
        puts("iss");
        free(word);
        word = (char *)malloc(80 * sizeof(char));
        wordlen = 0;
        puts("lit!");
      } else {
        *(word+wordlen) = *(c+i);
        wordlen++;
        puts(word);
      }
    i++;
  }
  free(c);
}
