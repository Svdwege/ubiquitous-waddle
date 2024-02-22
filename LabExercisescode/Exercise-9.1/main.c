
#include <complex.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  double complex result1 = (-3 - I) * (-5 - 2 * I);
  double complex result2 = (1 - I) / (I + 3);

  printf("%f,%f i\n", creal(result1), cimag(result1));
  printf("%f,%f i\n", creal(result2), cimag(result2));
  return EXIT_SUCCESS;
}
