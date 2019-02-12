#include "student.h"

/*
John Abreu
3/26/2018
*/

STUDENT create(int id, char* name) {
  STUDENT s = (STUDENT)malloc(sizeof(student_t));
  s->id = id;
  strcpy(s->name, name);

  return s;
}

int compare(STUDENT A, STUDENT B) {
  if(A->id == B->id){
    printf("%s and %s have the same Eagle ID #\n", A->name, B->name);
    return 0;
  }
  else {
    printf("%s and %s don't have the same Eagle ID #\n", A->name, B->name);
    return 1;
  }
}

void toString(STUDENT s) {
  printf("%d: %s\n", s->id, s->name);
}
