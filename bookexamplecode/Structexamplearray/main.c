#include <stdio.h>
#include <string.h>

#define N_PERSONS 3

typedef struct {
   char fullname[40];
   char street[31];
   int number;
   char city[31];
   int zipnum;
   char zipchar[3];
} person_t;

int main(void)
{
   /* Declaration and partly initialisation of a struct array variable */
   /* The persons[2] struct is fully filled with 0 values */
   person_t persons[N_PERSONS] = {
      {"John Doe", "Nonamestreet", 44, "Rotterdam", 3011, "AA"},
      {"John van den Hooven", "Nonamestreet", 42, "Rotterdam", 3011,
       "AA"}};

   /* Structs are assignable to each other (arrays are not!) */
   persons[2] = persons[0];

   /* Use the information in the structure */
   printf(" The fullname of persons[0] is: %s\n", persons[0].fullname);
   printf(" %s lives in %s\n", persons[0].fullname, persons[0].city);

   printf(" Persons[1]: %s also lives in %s\n", persons[1].fullname,
          persons[1].city);

   printf(" %s and %s are neighbours\n", persons[0].fullname,
          persons[1].fullname);

   printf(" All zipcodes are %4d%s, %4d%s and %4d%s\n", persons[0].zipnum,
          persons[0].zipchar, persons[1].zipnum, persons[1].zipchar,
          persons[2].zipnum, persons[2].zipchar);

   return 0;
}
