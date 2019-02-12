#include <stdio.h>
#include <stdlib.h>

/*
John Abreu
2/9/2018
*/

char *getCharBlock();
int findMatch(char *ptr, char *txt);
void printIt(char *ptr, int occurences, char *txt);
int findSize(char *ptr);

int main() {
  char *text, *pattern; // pointers for the characters you will read
  char *p, *q, *r;      // some pointer variables
  int occurences, size, ptrsize, y;       // some integers

  pattern = (char *)malloc(80 * sizeof(char));
  printf("Enter the pattern you'd like to search for: ");
  scanf("%s", pattern);
  text = getCharBlock();

  size = findSize(text);
  ptrsize = findSize(pattern);
  pattern = (char *)realloc(ptrsize * sizeof(char));

  occurences = findMatch(pattern, text);


  printIt(pattern, occurences, text);

  free(text);
  free(pattern);


  // this would fill in the "string" of chars for the passed in char pointer.
  // YOU SHOULD  place a '\0' character at the end of the "string" (as an end of
  // string sentinel)  this code MUST use pointer arithmetic
}

char *getCharBlock() {
  char *p;
  int size;

  p = (char *)malloc(81 * sizeof(char));

  printf("Enter your text: ");
  scanf("%s", p);
  size = findSize(p);
  p = (char *)realloc(size * sizeof(char));
  *(p + size) = '\0';

  return p;
}


int findMatch(char *ptr, char *txt) {
  int found = 0;
  int index = 0;
  int occurences = 0;
  int size =  findSize(txt);
  int ptrsize = findSize(ptr);

  char c, d;
  char pattern[80];


  while (index <= size) {
    c = *(txt+index);
    d = *(ptr+found);
    if (*(pattern) == *(ptr)) {
      if(ptrsize == found) {
        return 1 + findMatch(ptr,(txt+index-1));
      }
      found++;
      index++;
    }
    else {
      //printf("Does %s equal %s?\n", &c, &d);
      if (c == d) {
        *(pattern+found) = *(txt+index);
        found++;
      } else {
        found = 0;
      }
      index++;
    }
  }
  return 0;
}
// looks for a match, returns -1 for failure or an int which is the index to the
// location where the match starts.  the return values can be used to determine IF
// a match was found, and where.

void printIt(char *ptr, int occurences, char *txt) {
  if (occurences!=0) {
    printf("The pattern %s occurs %d times in %s\n", ptr, occurences, txt);
  }
  else {
    printf("The pattern %s does not occur in %s\n", ptr, txt);
  }
  // this is simple, just remember how pointer arithmetic works
  // prints a "string", starting from the pointer "index"
  // and any more functions for clarification of work done by the program.
  // Remember, by designing and implementing //your code well, you simply need
  // to call the functions nicely in main to find multiple locations of the
  // pattern in the //text.
}

int findSize(char *ptr) {
  int x = 0;
  while (*(ptr+x)!='\0') {
    x++;
  }
  return x;
}
