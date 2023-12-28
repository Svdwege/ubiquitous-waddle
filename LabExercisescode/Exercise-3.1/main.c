#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool isInt(const char str[]);

int main(int argc, char *argv[])
{
   // loop through all args except the program name
   for (int i = 1; i < argc; i++)
   {
      if (isInt(argv[i]))
      {
         printf("%s is an integer\n", argv[i]);
      }
      else
      {
         fprintf(stderr, "%s is not an integer\n", argv[i]);
         exit(EXIT_FAILURE);
      }
   }
   exit(EXIT_SUCCESS);
}

bool isInt(const char str[])
{
   int i = 0;
   bool isInteger = true;
   while (str[i] != '\0')
   {
      if (!isdigit(str[i]))
      {
         isInteger = false;
         break;
      }
      i++;
   }
   return isInteger;
}
