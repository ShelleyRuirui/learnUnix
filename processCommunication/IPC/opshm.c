/*
 * opshm.c - Reading and writing a shared memory segment
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

#define BUFSZ 4096

int main(int argc,char *argv[])
{
  int shmid;
  char *shmbuf;
  int fd;
  int i;
  
  if(argc!=2){
    puts("USAGE: opshm <identifier>");
    exit(EXIT_FAILURE);
  }

  shmid=atoi(argv[1]);

  if((shmbuf=shmat(shmid,0,0))<(char*)0){
    perror("shmat");
    exit(EXIT_FAILURE);
  }
  
  if((shmbuf=malloc(sizeof(char)*BUFSZ))==NULL){
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  for(i=0;i<BUFSZ;++i){
    shmbuf[i]=rand();
  }
  
  
  fd=open("out.txt",O_CREAT|O_WRONLY,0600);
  write(fd,shmbuf,BUFSZ);

  free(shmbuf);
  exit(EXIT_SUCCESS);
}
