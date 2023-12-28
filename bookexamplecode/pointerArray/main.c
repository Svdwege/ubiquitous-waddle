#include <stdio.h>

#define SIZE 5

int main(void) {
  /* Every string should be considered a pointer to the string */
  const char *stringData[SIZE] = {"Hello", "world", "of", "pointers",
                                  "in arrays"};

  for (int i = 0; i < SIZE; i++) {
    printf("stringData[%d] = %p  points to \"%s\"\n", i, stringData[i],
           stringData[i]);
  }
  puts("\n");

  /* Only printing the first character of every string */
  puts("First character of every string:");
  for (int i = 0; i < SIZE; i++) {
    printf("stringData[%d][0] = '%c'\n", i, stringData[i][0]);
  }

  return 0;
}
