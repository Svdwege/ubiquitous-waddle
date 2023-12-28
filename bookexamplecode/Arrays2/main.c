#include <stdio.h>

/* Examples of the use of arrays */
int main(void) {
  int a[20]; // An array with 20 elements of type integer, not initialised
  int b[6] = {22, 21, 43, 12, 13, 67}; // An array with 6 elements
  int i    = 0;

  /* Elements can be addressed by their index in the array */
  /* the array index starts with 0! */
  i = 1;
  printf("Second element of array b: %d\n\n", b[i]);

  i = 5;
  printf("Last element of array b: %d\n\n", b[i]);

  /* An element in an array can be used in an assignment or expression */
  b[i] = 5;
  b[2] = 3 * b[i];
  printf("Second element of array b: %d\n", b[1]);
  printf("Third element of array b: %d\n\n", b[2]);

  return 0;
}
