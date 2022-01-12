#include <stdio.h>
#include <string.h>

typedef struct {
   char fullname[40];
   char street[31];
   int number;
   char city[31];
   int zipnum;
   char zipchar[3];
} persons_t;

int main(void)
{
   /* Declaration of two variables of the user defined type */
   persons_t person1; /* person1 is not initialised */

   persons_t person2 = {"John van den Hooven",
                        "Nonamestreet",
                        42,
                        "Rotterdam",
                        3011,
                        "AA"}; /* person2 is initialized */

   /* Use a structure variables in an assignment */
   strcpy(person1.fullname, "John Doe");
   strcpy(person1.street, "Nonamestreet");
   person1.number = 44;
   strcpy(person1.city, "Rotterdam");
   person1.zipnum = 3011;
   strcpy(person1.zipchar, "AA");

   /* Use the information in the structure */
   printf(" The fullname of person1 is: %s\n", person1.fullname);
   printf(" %s lives in %s\n", person1.fullname, person1.city);

   printf(" Person 2, %s also lives in %s\n", person2.fullname,
          person2.city);

   printf(" %s and %s are neighbours\n", person1.fullname,
          person2.fullname);

   printf(" Their zipcodes are %4d%s and %4d%s\n", person1.zipnum,
          person1.zipchar, person2.zipnum, person2.zipchar);

   return 0;
}
