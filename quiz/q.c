#include <stdio.h>

int main(int argc, char **argv)
{
   int a = (100 + 1.0/3) - 100;
   int b = (1.0/3);

   if ( a==b ) 
      printf("a==b\n");
   else
      printf("a!=b\n");

   return a==b;
}
      

            
