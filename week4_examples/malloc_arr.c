#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   int *pVar;
   pVar = (int *)malloc(10 * sizeof(int));
   *pVar = 5;
   *(pVar + 1) = 6;
   printf("Waarde gereserveerd geheugen: %d\n", *pVar);
   printf("Waarde gereserveerd geheugen: %d\n", pVar[1]);
   free(pVar);
   return 0;
}
