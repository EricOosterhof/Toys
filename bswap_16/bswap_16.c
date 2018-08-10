#include <stdio.h>
#include <byteswap.h>

int main(int argc, char **argv)
{
  unsigned short int a = 0xaa55;

  printf("a               = 0x%4.4x\n", a);
  printf("bswap_16(a)     = 0x%4.4x\n", bswap_16(a));
  printf("__bswap_16(a)   = 0x%4.4x\n", __bswap_16(a));

  return 0;
}
