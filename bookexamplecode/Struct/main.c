#include <math.h>
#include <stdio.h>

/* Point2D: 2D coordinates x and y */
typedef struct {
   double x;
   double y;
} point2D_t;

/* Linear equation: y = ax + b */
typedef struct {
   double a;
   double b;
} linearEquationParameters_t;

/* const: the struct cannot be mutated in functions */
double distance(const point2D_t *pP1, const point2D_t *pP2);
double linearEquation(const linearEquationParameters_t *pPars, double x);
double inverseLinearEquation(const linearEquationParameters_t *pPars,
                             double y);
linearEquationParameters_t pointsToLinearEquation(const point2D_t *pP1,
                                                  const point2D_t *pP2);

int main(void)
{
   point2D_t p1 = {0, 0};
   point2D_t p2 = {0, 0};
   point2D_t points[5] = {{0, 1}, {1, 2}};
   linearEquationParameters_t lep = {1, 1};
   double x = 0.0;
   double y = 0.0;

   p1.x = 1;
   p1.y = 1;

   p2.x = 0;
   p2.y = 0;

   /* You van assign one struct to another (copy) */
   points[0] = p1;
   points[1] = p2;

   printf("2D points containing x and y (coordinates)\n\n");
   printf(
      "  p1 = [%.2lf,%.2lf]\n"
      "  p2 = [%.2lf,%.2lf]\n"
      "  points[0] = [%.2f,%.2f]\n\n",
      p1.x, p1.y, p2.x, p2.y, points[0].x, points[0].y);

   printf("  Distance between p1 and p2 = %.2lf\n\n", distance(&p1, &p2));

   x = 2.0;
   y = linearEquation(&lep, x);
   printf(
      "  x = %.2lf\n"
      "  y = %.2lfx%+.2lf = %.2lf\n\n",
      x, lep.a, lep.b, y);

   y = 3.0;
   x = inverseLinearEquation(&lep, y);
   printf(
      "  y = %.2lf\n"
      "  x = (y-%.2lf)/%.2lf = %.2lf\n\n",
      y, lep.b, lep.a, x);

   lep = pointsToLinearEquation(&p1, &p2);
   printf(
      "  Line through p1 [%.2lf,%.2lf] and p2 [%.2lf,%.2lf]: "
      "y = %.2lfx%+.2lf\n\n",
      p1.x, p1.y, p2.x, p2.y, lep.a, lep.b);

   return 0;
}

double distance(const point2D_t *pP1, const point2D_t *pP2)
{
   double deltaX = pP2->x - pP1->x;
   double deltaY = pP2->y - pP1->y;

   return sqrt(deltaX * deltaX + deltaY * deltaY);
}

/* y = ax + b */
double linearEquation(const linearEquationParameters_t *pPars, double x)
{
   return pPars->a * x + pPars->b;
}

/* x = (y - b)/a and a != 0 */
double inverseLinearEquation(const linearEquationParameters_t *pPars,
                             double y)
{
   return (y - pPars->b) / pPars->a;
}

linearEquationParameters_t pointsToLinearEquation(const point2D_t *pP1,
                                                  const point2D_t *pP2)
{
   linearEquationParameters_t result = {0, 0};
   /* calculate a and b */
   result.a = (pP2->x - pP1->x) / (pP2->y - pP1->y);
   result.b = (result.a * pP1->x) - pP1->y;

   return result;
}
