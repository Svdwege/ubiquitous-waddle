#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 5

typedef struct {
   int number;
   char twochars[3]; /* string needs additional '\0' */
} zipcode_t;

/* comparison functions */
int compareInts(int i1, int i2);
int compareZipcode(const void *pD1, const void *pD2);

int main(void)
{
   zipcode_t zipcodes[SIZE] = {{7621, "BL"},
                               {7751, "ZZ"},
                               {6800, "OP"},
                               {6800, "EE"},
                               {4321, "WE"}};

   printf("---- Not sorted:\n");
   for (int i = 0; i < SIZE; i++)
   {
      printf("zipcodes[%d] = {%4d %2s}\n", i, zipcodes[i].number,
             zipcodes[i].twochars);
   }
   printf(" \n");

   /* Sorting algorithm: quick sort */
   /* compareData is a function pointer to a callback function */
   /* 4.2 Complete the call to qsort */
   qsort(zipcodes, SIZE, sizeof(zipcode_t), compareZipcode);

   printf("-------- Sorted:\n");
   for (int i = 0; i < SIZE; i++)
   {
      printf("zipcodes[%d] = {%4d %2s}\n", i, zipcodes[i].number,
             zipcodes[i].twochars);
   }
   printf("\n");

   return 0;
}

static int compareSTR(char *s1, char *s2)
{
   if (strcmp(s1, s2) < 0)
      return -1;
   if (strcmp(s1, s2) > 0)
      return 1;
   return 0;
}

int compareInts(int i1, int i2)
{
   if (i1 < i2)
      return -1;
   if (i1 > i2)
      return 1;
   return 0;
}

/* callback function for qsort */
int compareZipcode(const void *pZC1, const void *pZC2)
{
   int hold = compareInts(((const zipcode_t *)pZC1)->number,
                          ((const zipcode_t *)pZC2)->number);
   if (hold != 0)
   {
      return hold;
   }
   else
   {
      return compareSTR(((const zipcode_t *)pZC1)->twochars,
                        ((const zipcode_t *)pZC2)->twochars);
   }
   // add the correct code, inspiration from listing qsort/main.c
}
