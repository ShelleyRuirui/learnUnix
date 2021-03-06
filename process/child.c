/*
 * child.c - Simple fork usage
 */
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  pid_t child;
  if((child=fork())==-1){
    perror("fork");
    exit(EXIT_FAILURE);
  }else if(child==0){
    puts("in child");
    printf("\tchild pid=%d\n",getpid());
    printf("\tchild ppid=%d\n",getppid());
    exit(EXIT_SUCCESS);
  }else{
    puts("in parent");
    sleep(5);
    printf("\tparent pid=%d\n",getpid());
    printf("\tparent pid=%d\n",getppid());
  }
  exit(EXIT_SUCCESS);
}
