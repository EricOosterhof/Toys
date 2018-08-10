#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void usage(int argc, char **argv)
{
   printf("Usage:\n");
   printf("\t%s <sig> <sival_int> <pid>\n", argv[0]);
   printf("\t  Send signal sig with sival_int field set to pid\n");
   exit(-1);
}

int main(int argc, char **argv)
{
   int sig = 0;
   int sival = 0;
   int pid = 0;
   union sigval value;

   printf("SIGRTMIN = %d\n", SIGRTMIN);
   

   if ( argc < 3 ) usage(argc, argv);
   sig = atoi(argv[1]);
   sival = (int) strtoul(argv[2], NULL, 0);
   pid = atoi(argv[3]);
   if ((0 == pid) || kill(pid,0) || (0 == sival) || (sig == 0)) usage(argc, argv);

   value.sival_int = sival;
   sigqueue(pid, sig, value);
   
   return 0;
}
