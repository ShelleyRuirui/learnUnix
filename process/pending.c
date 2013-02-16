/*
 * pending.c - Fun with sigpending
 */
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void term_handler(int);

int main(void)
{
  sigset_t set,pendset;
  struct sigaction action;
  sigemptyset(&set);

  sigaddset(&set,SIGTERM);
  sigprocmask(SIG_BLOCK,&set,NULL);

  kill(getpid(),SIGTERM);

  sigpending(&pendset);

  if(sigismember(&pendset,SIGTERM)){
    sigemptyset(&action.sa_mask);
    action.sa_handler=term_handler;
    sigaction(SIGTERM,&action,NULL);
  }

  sigprocmask(SIG_UNBLOCK,&set,NULL);
  puts("Terminate normally");
  exit(EXIT_SUCCESS);
}


void term_handler(int i){
  puts("Handling term");
}
