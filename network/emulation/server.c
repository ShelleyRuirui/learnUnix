/*
 * server4.c - Demo fork for multiple clients
 */
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc,char *argv[])
{
  int server_sockfd,client_sockfd;
  int server_len,client_len;
  struct sockaddr_in server_address,client_address;

  server_sockfd=socket(AF_INET,SOCK_STREAM,0);
  server_address.sin_family=AF_INET;
  server_address.sin_port=htons(9734);
  server_address.sin_addr.s_addr=htonl(INADDR_ANY);
  server_len=sizeof(server_address);

  bind(server_sockfd,(struct sockaddr *)&server_address,server_len);

  listen(server_sockfd,5);

  signal(SIGCHLD,SIG_IGN);

  while(1){
    char ch[128];
    printf("server waiting\n");
    client_len=sizeof(client_address);
    client_sockfd=accept(server_sockfd,(struct sockaddr*)&client_address,&client_len);
    if(fork()==0){
      read(client_sockfd,ch,128);
      fprintf("The thing received is %s\n",ch);
      close(client_sockfd);
      exit(0);
    }else{
      close(client_sockfd);
    }
  }
}
