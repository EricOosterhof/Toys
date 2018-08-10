#include <stdio.h>


#define s(x) { printf("sizeof %-16s = %d\n", #x, (int)sizeof(x)); }


int
main(int argc, char **argv)
{
  printf("\n");
  s(char);
  s(unsigned);
  s(int);
  s(unsigned int);
  s(float);
  s(long);
  s(double);


  return 0;
}
