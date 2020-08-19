#include <stdio.h>

int main(void)
{
   void *pGeneric = NULL;

   int iVar = 1;
   pGeneric = &iVar;
   printf(" pGeneric = %p points to %d\n", pGeneric, *(int *)pGeneric);

   double dVar = 2.2;
   pGeneric = &dVar;
   printf(" pGeneric = %p points to %lf\n", pGeneric, *(double *)pGeneric);

   char cVar = 'c';
   pGeneric = &cVar;
   printf(" pGeneric = %p points to %c\n", pGeneric, *(char *)pGeneric);

   return 0;
}
