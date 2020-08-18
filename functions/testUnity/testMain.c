/* Unit tests: using Unity unit test framework
 *
 * Test code should be complemented with more tests.
 */

#include "functions.h"
#include "unity.h"

#include <stdio.h>

const float DELTA = 0.001f;

void test_findMinMax(void)
{
   printf("---- findMinMax()\n");

   {
      float data1[1] = {-1.0};
      minmax_t result = findMinMax(data1, 1);

      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, -1.0, result.min, "test 1");
      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, -1.0, result.max, "test 2");
   }

   {
      float data2[5] = {-1.0, 0.0, 1.0, 2.0, 3.0};
      minmax_t result = findMinMax(data2, 5);

      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, -1.0, result.min, "test 3");
      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, 3.0, result.max, "test 4");
   }
}

void test_averageData(void)
{
   printf("\n---- averageData()\n");

   {
      float data1[1] = {1.0};
      float result = averageData(data1, 1);

      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, 1.0, result, "test 1");
   }

   {
      float data2[5] = {1.0, 1.0, 1.0, 1.0, 1.0};
      float result = averageData(data2, 5);

      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, 1.0, result, "test 2");
   }
}

void test_meanNormalisation(void)
{
   printf("\n---- meanNormalisation()\n");

   {
      float data1[5] = {0.0, 2.0, 0.0, -2.0, 0.0};

      meanNormalisation(data1, 5);
      minmax_t result = findMinMax(data1, 5);

      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, -1.0, result.min, "test 1");
      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, 1.0, result.max, "test 2");

      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, 0.0, averageData(data1, 5),
                                       "test 3");
   }

   {
      float data2[5] = {2.0, -2.0, 1.0, -1.0, 1.0};

      meanNormalisation(data2, 5);
      minmax_t result = findMinMax(data2, 5);

      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, -1.0, result.min, "test 4");
      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, 1.0, result.max, "test 5");

      TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, 0.0, averageData(data2, 5),
                                       "test 6");
   }
}

void test_minmaxScaling(void)
{
   printf("\n---- minmaxScaling()\n");

   float data1[4] = {1.0, -5.0, 5.0, -1.0};
   float min = -2.0;
   float max = 4.0;

   TEST_ASSERT(min < max && min < 0.0 && max > 0.0);

   minmaxScaling(data1, 4, min, max);
   TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, min, findMinMax(data1, 4).min,
                                    "test 1");

   min = -2.0;
   max = 4.0;
   TEST_ASSERT(min < max && min < 0.0 && max > 0.0);

   minmaxScaling(data1, 4, min, max);
   TEST_ASSERT_FLOAT_WITHIN_MESSAGE(DELTA, max, findMinMax(data1, 4).max,
                                    "test 2");
}

int main(void)
{
   UNITY_BEGIN();

   printf("== Unity unit tests 'functions' ==\n\n");
   
   RUN_TEST(test_findMinMax);
   RUN_TEST(test_averageData);
   RUN_TEST(test_meanNormalisation);
   RUN_TEST(test_minmaxScaling);

   return UNITY_END();
}
