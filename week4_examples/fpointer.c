#include <stdio.h>
#include <stdlib.h>

double add(double a, double b);
double mul(double a, double b);
double divide(double a, double b);

typedef struct
{
  double (*calculate)(double, double);
  char action[20];
} CalculateFunc_t;

int main(int argc, char *argv[])
{
  int result = 0;
  CalculateFunc_t CalculateFunctions[5] =  { {&add, "Optellen"}, {&mul, "Vermenigvuldigen"}, {&divide, "Delen"} };

  printf("gebruik van de eerste functie %lf\n", CalculateFunctions[0].calculate(4.0, 3.0) );

  printf("gebruik van de derde functie %lf\n", CalculateFunctions[2].calculate(4.0, 3.0) );

  
  return 0;
}

double add(double a, double b)
{
  return a + b;
}

double mul(double a, double b)
{
  return a * b;
}

double divide(double a, double b)
{
  return a / b;
}

  
