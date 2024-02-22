#include <stdbool.h>
#include <stdio.h>

bool compareIntArrays(const int arr1[], const int arr2[], int size);

int main(void) {

  int arr1[] = {1, 2, 3, 4, 5};
  int arr2[] = {1, 2, 3, 4, 5};
  int arr3[] = {2, 2, 3, 4, 5};

  if (compareIntArrays(arr1, arr2, 5)) {
    printf("The arrays 1 and 2 are equal.\n");
  } else {
    printf("The arrays 1 and 2 are not equal.\n");
  }
  if (compareIntArrays(arr1, arr3, 5)) {
    printf("The arrays 1 and 3 are equal.\n");
  } else {
    printf("The arrays 1 and 3 are not equal.\n");
  }

  return 0;
}

bool compareIntArrays(const int arr1[], const int arr2[], int size) {
  for (int i = 0; i < size; i++) {
    if (arr1[i] != arr2[i]) {
      return false;
    }
  }
  return true;
}
