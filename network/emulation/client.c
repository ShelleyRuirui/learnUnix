/*
 * client2.c - Socket over Internet
 */
#include<sys/types.h>
#include<sys/socket.h>
#include <stdio.h>

#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<string.h>
#include<stdio.h>

int main(int argc,char* argv[])
{
 int sockfd;
  int len;
  struct sockaddr_in address;
  int result;

  sockfd=socket(AF_INET,SOCK_STREAM,0);
  address.sin_family=AF_INET;
  address.sin_addr.s_addr=htonl(INADDR_ANY);
  address.sin_port=htons(9734);
  len=sizeof(address);

  result=connect(sockfd,(struct sockaddr*)&address,len);

  if(result==-1){
    perror("oops: client1");
    exit(1);
  }

  char* boatName;
  char msg[128];
  boatName=argv[1];    
  
  int timesToSend=50;
  int currentX=0;
  int currentY=0;
  int i=timesToSend;

  for(;i>0;i--){
    strncpy(msg,boatName,50);
    char xStr[30];
    sprintf(xStr,"%d",currentX);
    strncat(msg,",",1);
    strncat(msg,xStr,30);

    char yStr[30];
    sprintf(yStr,"%d",currentY);
    strncat(msg,",",1);
    strncat(msg,yStr,30);
    printf("Current msg is %s\n",msg);
    currentX++;
    currentY++;
    write(sockfd,msg,128);
    sleep(2);
  }

  close(sockfd);
  exit(0);
}
