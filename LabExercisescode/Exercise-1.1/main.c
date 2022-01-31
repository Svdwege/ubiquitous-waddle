#include <stdio.h>

typedef struct
{
   int element1;
   char element2;
} data_t;

void fillStruct(data_t *data);
void clearStruct(data_t *data);
void printStruct(const data_t *data);

#define N_ARRAY (3)

data_t array[N_ARRAY];

int main(void)
{
   for(int n=0; n<N_ARRAY; ++n)
   {
      fillStruct(&array[n]);
      printStruct(&array[n]);
   }

   return 0;
}

void fillStruct(data_t *data)
{
   static int n = 1;
   static char c = 'A';

   data->element1 = n;
   data->element2 = c;

   n = (n == 26) ? 1 : (n+1);
   c = (c == 'Z') ? 'A' : (c+1);
}

void printStruct(const data_t *data)
{

      // Implement function printStruct

}

void clearStruct(data_t *data)
{

      // Implement function clearStruct

}
