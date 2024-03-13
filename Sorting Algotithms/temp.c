#include <stdio.h>

int main(void) {
  int a = 34;
  char *ptr;

  ptr = &a;

//   printf("The address of %d is %p", a, ptr);
 printf("The value of a is %d", *(ptr));
  return 0;
}