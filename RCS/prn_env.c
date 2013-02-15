/*$Id: prn_env.c,v 2.1 2013/02/05 22:25:49 cse Exp cse $
 *prn_env.c - Display values of environment variables
 */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(void)
{
  extern char **environ;
  char **my_env=environ;

  while(*my_env){
    printf("%s\n",*my_env);
    my_env++;
  }

  exit(EXIT_SUCCESS);
}
