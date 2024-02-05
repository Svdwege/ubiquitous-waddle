int mainold(void) {
  problem_t s1 = {1, NULL}; /* do not do ... = {1, "ABC"} */
  problem_t s2 = {2, NULL};

  s1.pText = (char *)malloc(4 * sizeof(char)); /* array of 4 chars */
  if (s1.pText != NULL) {
    strcpy(s1.pText, "111");
    s2          = s1; /* shallow copy, problem? */ // not yet
    s2.pText[0] = 'A'; /* problem? */              // no

    printf("s1 = %d %s\n", s1.count, s1.pText);
    printf("s2 = %d %s\n", s2.count, s2.pText);

    free(s1.pText); /* problem? */ // not perse only if if s2 is used
  }
  s2.pText[1] = 'B'; /* problem? */ // yes use after free

  printf("s1 = %d %s\n", s1.count, s1.pText);
  printf("s2 = %d %s\n", s2.count, s2.pText);

  return 0;
}
