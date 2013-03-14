#include<string.h>

int main(int argc,char* argv[])
{
  char* boatName;
  char msg[128];
  boatName=argv[1];
  
  
    printf("Before msg:%s\n",boatName);
    strncpy(msg,boatName,50);
    printf("Result is:%s\n",msg);  
  
  return 0;
}
