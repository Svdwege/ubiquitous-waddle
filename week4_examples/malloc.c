#include <stdio.h>
#include <stdlib.h>

int main(void) {
  int *pVar;
  pVar  = (int *)malloc(sizeof(int));
  *pVar = 5;
  printf("Waarde gereserveerd geheugen: %d\n", *pVar);
  free(pVar);
  return 0;
}
