#include "functions.h"

#include <stdio.h>

void showData(const float data[], size_t size);

#define SIZE1 8
#define SIZE2 5

int main(void)
{
   float data1[SIZE1] = {-3.01, 1.05,  0.04, -1.23,
                         -2.5,  1.234, -0.4, -0.23};
   float data2[SIZE2] = {1.051, 0.0423, -1.2, -2.24, 2.234};
   minmax_t minmax1 = {0.0, 0.0};
   minmax_t minmax2 = {0.0, 0.0};

   puts(
      "Program started "
      "-------------------------------------\n");

   printf("  data1 = ");
   showData(data1, SIZE1);
   printf("\n  data2 = ");
   showData(data2, SIZE2);

   puts("\n\n  meanNormalisation() data1 and data2");
   meanNormalisation(data1, SIZE1);
   printf("  Average data1 = %f\n", averageData(data1, SIZE1));
   meanNormalisation(data2, SIZE2);
   printf("  Average data2 = %f\n", averageData(data2, SIZE2));
   printf("  data1 = ");
   showData(data1, SIZE1);
   printf("\n  data2 = ");
   showData(data2, SIZE2);

   puts("\n\n  minmaxScaling() data1 and data2");
   minmaxScaling(data1, 10, -1.0, 1.0);
   minmax1 = findMinMax(data1, SIZE1);
   printf("  data1 min = %f  max = %f\n", minmax1.min, minmax1.max);

   minmaxScaling(data2, SIZE2, -3.0, 2.0);
   minmax2 = findMinMax(data2, SIZE2);
   printf("  data2 min = %f  max = %f\n", minmax2.min, minmax2.max);
   printf("  data1 = ");
   showData(data1, SIZE1);
   printf("\n  data2 = ");
   showData(data2, SIZE2);

   puts(
      "\n\nProgram ready "
      "---------------------------------------\n");

   return 0;
}

void showData(const float data[], size_t size)
{
   for (size_t i = 0; i < size; i++)
   {
      printf("%f ", data[i]);
   }
}
