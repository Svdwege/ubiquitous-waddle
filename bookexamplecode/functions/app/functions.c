#include "functions.h"
#include <stdio.h>

minmax_t findMinMax(const float data[], int size) {
  minmax_t result = {0.0, 0.0};

  result.min = data[0];
  result.max = data[0];
  for (int i = 1; i < size; i++) {
    if (data[i] > result.max) {
      result.max = data[i];
    } else {
      if (data[i] < result.min) {
        result.min = data[i];
      }
    }
  }
  return result;
}

float averageData(const float data[], int size) {
  float average = 0.0;

  for (int i = 0; i < size; i++) {
    average += data[i];
  }
  average = average / (float)size;
  return average;
}

void meanNormalisation(float data[], int size) {
  minmax_t actualMinMax = findMinMax(data, size);
  float    mean         = averageData(data, size);

  for (int i = 0; i < size; i++) {
    data[i] =
        2.0 * (data[i] + mean) / (actualMinMax.max + actualMinMax.min) - 1.0;
    printf("%f", data[i]);
  }
}

void minmaxScaling(float data[], int size, float min, float max) {
  minmax_t actualMinMax = findMinMax(data, size);
  float    A            = actualMinMax.min / actualMinMax.max;
  float    B            = actualMinMax.min + actualMinMax.max;

  for (int i = 0; i < size; i++) {
    data[i] = A * data[i] + B;
  }
}
