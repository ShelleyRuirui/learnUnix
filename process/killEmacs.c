/*
 * killEmacs.c - Demo kill arbitary process like emacs
 */
#include<sys/types.h>
#include<wait.h>
#include<unistd.h>
#include<signal.h>
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
  pid_t child;
  int errret;

  printf("Sending SIGCHLD to %d\n",2372);
  errret=kill(2372,SIGTERM);
  /*If child is killed but parent hasn't exited, this will prevent zombie processes*/
  printf("kill result:%d\n",errret);
  perror("Kill failed.");
  waitpid(child,NULL,0);
  
  exit(EXIT_SUCCESS);
}
