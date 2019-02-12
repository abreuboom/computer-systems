#include <stdio.h>
#include <stdlib.h>

/*
John Abreu
2/9/2018
*/

char *getCharBlock();
int findMatch(char *ptr, char *txt);
void printIt(char *ptr, int index, int size);
int findSize(char *ptr);
int contains(char *ptr, char c);

int main() {
  char *text, *pattern; // pointers for the characters you will read
  char *p, *q, *r;      // some pointer variables
  int index, size, ptrsize, y;       // some integers

  char ptrstr[] = "GCAG";

  pattern = (char *)malloc(80 * sizeof(char));
  text = getCharBlock();
  for (int i = 0; i < 4; i++){
    *(pattern+i) = *(ptrstr+i);
  }

  size = findSize(text);
  ptrsize = findSize(pattern);

  printf("Your pattern is %s\n", pattern);

  index = findMatch(pattern, text);


  printIt(text, index, ptrsize);

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

  printf("Enter your DNA sequence: ");
  scanf("%s", p);
  *(p + 80) = '\0';

  return p;
}


int findMatch(char *ptr, char *txt) {
  int found = 0;
  int index = 0;
  int size =  findSize(txt);
  int ptrsize = findSize(ptr);

  char c, d;
  char pattern[80];
  char *patternptr = &pattern[0];


  printf("%s\n", txt);



  while (index <= size) {
    c = *(txt+index);
    d = *(ptr+found);
    if (*(pattern) == *(ptr)) {
      if(ptrsize == found) {
        return index-found;
      }
      else {
        if (contains(pattern, *(txt+index))){
          index++;
          found = 0;
          *(pattern) = ' ';
        }
        else {
          found++;
          index++;
        }

    }
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
  return -1;
}

int contains(char *ptr, char c) {
  int size = findSize(ptr);

  for(int i=0; i<size; i++) {
    if (*(ptr+i) == c){
      return 1;
    }
  }
  return 0;
}
// looks for a match, returns -1 for failure or an int which is the index to the
// location where the match starts.  the return values can be used to determine IF
// a match was found, and where.

void printIt(char *ptr, int index, int size) {
  char* p = (ptr+index+size);
  int total = findSize(ptr);
  int remaining = findSize(p);
  printf("The match is at index: %d\n%d/%d was left over:\n%s\n", index, remaining, total, p);
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
