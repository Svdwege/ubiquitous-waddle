#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

bool isInt(const char str[]);

int main(void)
{

   return 0;
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
