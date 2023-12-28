#include <stdio.h>
#include <stdlib.h>

void hexdumpLong(long data);

int main(void) {
  hexdumpLong(0x12345678);
  return 0;
}

void hexdumpLong(long data) { printf("0x%x\n", data); }
