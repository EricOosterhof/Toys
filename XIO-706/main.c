#include <stdio.h>

#ifdef TEST_NEW
#include "fpgaTopRegsCitraGenerated.h"
#endif

#ifdef TEST_OLD
#include "fpgaTopRegsCitraOriginal.h"
#endif

#define OLD(x) printf("%80.80s   %d        \n", #x,x );
#define NEW(x) printf("%- 16d    %-80.80s    \n", x,#x );



int
main( int argc, char** argv )
{
  printf("Hello world\n");

  #ifdef TEST_NEW
  #include "NEW.c"
  #endif

  #ifdef TEST_OLD
  #include "OLD.c"
  #endif
  

  printf("\n");

  return 0;
}
