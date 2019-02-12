#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dll.h"
#include "student.h"

/*
John Abreu
3/26/2018
*/

main() {
  STUDENT s1 = create(0, "John");
  STUDENT s2 = create(1, "Still John");
  STUDENT s3 = create(2, "Bob");
  List l = add(NULL, s1);
  l = add(l, s2);
  l = add(l, s3);
  printList(l, toString);
  l = rem(l, s2, compare);
  printList(l, toString);

}
