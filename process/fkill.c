/*
 * fkill.c - Demo kill(2) signal
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
 
  if((child=fork())<0){
    perror("fkill");
    exit(EXIT_FAILURE);
  }else if(child==0){
    sleep(30);
  }else{
    printf("Sending SIGCHLD to %d\n",child);
    errret=kill(child,SIGCHLD);
    if(errret<0)
      perror("kill:SIGCHLD");
    else
      printf("%d still alive\n",child);
    printf("killing %d\n",child);
    if((kill(child,SIGTERM))<0)
      perror("kill:SIGTERM");
    /*If child is killed but parent hasn't exited, this will prevent zombie processes*/
    waitpid(child,NULL,0);
  }
  exit(EXIT_SUCCESS);
}
