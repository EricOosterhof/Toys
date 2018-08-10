#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void usage(int argc, char **argv)
{
   printf("Usage:\n");
   printf("\t%s <count> <pid>\n", argv[0]);
   exit(-1);
}

int main(int argc, char **argv)
{
   int count = 0;
   int pid = 0;
   union sigval value;

   if ( argc < 2 ) usage(argc, argv);
   count = atoi(argv[1]);
   pid = atoi(argv[2]);
   if ( (0 == pid) || kill(pid,0) ) usage(argc, argv);

   value.sival_int = 0;
   while ( count-- ) {
      sigqueue(pid, SIGRTMIN, value);
   }
   
   return 0;
}
