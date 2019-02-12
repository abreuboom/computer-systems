#include <stdio.h>
#include <stdlib.h>

/*
John Abreu
3/26/2018
*/

typedef struct student {
   int id;
   char name[20];
} student_t;

typedef student_t * STUDENT;

STUDENT create(int id, char* name);
int compare(STUDENT A, STUDENT B);
void toString(STUDENT s);
