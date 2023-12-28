#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isInt(const char str[]);

int main(int argc, char *argv[])
{
   if (isInt(""))
      printf("%s\n", "Hello World");
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
         //         exit(EXIT_FAILURE);
      }
   }
   exit(EXIT_SUCCESS);
}

bool isInt(const char str[])
{
   if (strlen(str) == 0)
      return false;
   int i = 0;
   bool isInteger = true;
   bool sign = false;
   while (str[i] != '\0')
   {
      if ((str[i] == '-' || str[i] == '+') && str[i + 1] != '\0')
      {
         if (sign)
         {
            isInteger = false;
            break;
         }
         else
         {
            sign = true;
         }
      }
      else if (!isdigit(str[i]))
      {
         isInteger = false;
         break;
      }
      i++;
   }
   return isInteger;
}
