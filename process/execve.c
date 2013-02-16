/*
 * execve.c - Demo execve
 */
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
  char *args[]={"/bin/ls",NULL};

  printf("First PID=%d\n",getpid());
  if(execve("./pripds",args,NULL)==-1){
    perror("execve");
    exit(EXIT_FAILURE);
  }

  puts("shouldn't get here");
  exit(EXIT_SUCCESS);
}
