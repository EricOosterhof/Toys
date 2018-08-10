/*
 * Testing conversion error messages and fixes like so:

: dune->conversion ; gcc -Wall -Wpointer-arith -Wconversion -Wstrict-prototypes -Werror main.c
main.c: In function ‘main’:
main.c:10:7: error: conversion to ‘int’ from ‘unsigned int’ may change the sign of the result [-Werror=sign-conversion]
   y = ~x;
       ^
cc1: all warnings being treated as errors
: dune->conversion ; gcc -Wall -Wpointer-arith -Wconversion -Wstrict-prototypes -Werror main.c
: dune->conversion ; ./a.out 
x = 0000000000000001
y = 00000000fffffffe
: dune->conversion ; 

*/

#include <stdio.h>


int
main(int argc, char **argv)
{
  unsigned int x;
  int y;

  x = 0x0001;
  y = (int) ~x;
  printf("x = %16.16x\n", x);
  printf("y = %16.16x\n", y);

  y = -1;
  if ( y == (char)-1 ) {
    printf("0xffffffff == 0xff\n");
  } else {
    printf("0xffffffff == 0xff\n");
  }

  return 0;
}
