#include <stdio.h>
#include <string.h> // library for string manipulation

int main(void) {
  char text1[80] = {'G', 'r', 'e', 'e', 't', 'i', 'n', 'g', 's', '\0'};
  char text2[]   = " Professor";

  printf("String text1 is: %s\n", text1);
  printf("String text2 is: %s\n\n", text2);

  /* there are a lot of standard functions to manipulate string variables
   */
  /* concatenation of strings */
  strcat(text1, text2);
  printf("Concatenated strings: %s\n", text1);

  /* copy new text into string text 2 */
  strcpy(text2, " Falken");

  /* concatenation of the new text to text 1 */
  strcat(text1, text2);
  printf("Concatenated strings: %s\n", text1);

  return 0;
}
