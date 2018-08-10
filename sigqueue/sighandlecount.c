#include <stdio.h>
#include <unistd.h>

#include <signal.h>

int counter = 0;


static void
info_dump(int sig)
{
   printf("counter = %d\n",counter);
   counter = 0;
}

/*
 * because this handler was registered with SA_SIGINFO it gets 3 args
 * (see sigaction(2)) sival_int can be filled by the sigqueue call
 */
static void
test_function(int sig, siginfo_t *sip, void *ucp)
{
   counter++;
}

int main(int argc, char **argv)
{
   struct sigaction sa;
   sigset_t sigmask;

   printf("My process ID : %d\n", getpid());


   /* catch sigusr1 and dump a bunch of debug stuff */
   sa.sa_flags = 0;
   sa.sa_handler = info_dump;
   (void)sigfillset(&sa.sa_mask);
   (void)sigaction(SIGUSR1, &sa, (struct sigaction *)0); /* dump debug info */

   /* catch sigusr2 and call the test function */
   sa.sa_flags = SA_SIGINFO;
   sa.sa_sigaction = test_function;
   (void)sigfillset(&sa.sa_mask);
   (void)sigaction(SIGUSR2, &sa, (struct sigaction *)0); /*  */

   /* catch SIGRTMIN and call the test function */
   sa.sa_flags = SA_SIGINFO;
   sa.sa_sigaction = test_function;
   (void)sigfillset(&sa.sa_mask);
   (void)sigaction(SIGRTMIN, &sa, (struct sigaction *)0); /*  */

   (void)sigfillset(&sigmask);
   (void)sigdelset(&sigmask, SIGUSR1);
   (void)sigdelset(&sigmask, SIGUSR2);
   (void)sigdelset(&sigmask, SIGRTMIN);
   (void)sigdelset(&sigmask, SIGINT);  // ctrl-C
   (void)sigprocmask(SIG_SETMASK, &sigmask, (sigset_t *)0);


   
   while( counter < 1000000 ) {

   }
   return 0;
}
