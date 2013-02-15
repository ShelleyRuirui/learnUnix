/*
 * blunder.c - Mistakes caught by -W{warning}
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[])
{
  int i,j;
  printf("%c\n","not a character");
  if(i = 10)
    printf("Oops\n");
  if(j!=10)
    printf("another oops\n");
  /* /* */
  no_decl();

    return(EXIT_SUCCESS);
}
 
void no_decl(void)
{
  printf("no_decl\n");
}
