#include <stdio.h>
/* examples of the use of arrays */

int main(void) {
  int    a[20]; // an array with 20 elements of type integer
  int    b[6] = {22, 21, 43, 12, 13, 67}; // an array with 6 elements
  double c[4];
  double d[3] = {12.6, 4.5, 6.7};

  /* elements can be adressed by their index in the array */
  /* the index starts with 0! */
  printf("First element of array b: %d\n", b[0]);
  printf("Second element of array b: %d\n", b[1]);
  printf("Fourth element of array b: %d\n", b[3]);
  printf("Last element of array b: %d\n\n", b[5]);

  /* an element in an array can be used in an assignment or expression */

  b[1] = 5;
  b[2] = 3 * b[4];
  printf("Second element of array b: %d\n", b[1]);
  printf("Third element of array b: %d\n\n", b[2]);

  /* an element in an array is of the type as in the declaration */
  /* next line will give a compiler warning or error! */
  b[1] = 5.6;
  printf("Second element of array b: %d\n\n", b[1]);

  /* another example next line will also give a compiler warning or error!
   */
  b[5] = d[2];
  printf("Last element of array b: %d\n", b[5]);

  return 0;
}
