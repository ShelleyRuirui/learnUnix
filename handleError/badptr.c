/*
 * badprt.c - Testing assert
 */
#include<stdio.h>
#define NDEBUG
#include<assert.h>
#include<stdlib.h>

int main(void)
{
  FILE *fp;

  fp=fopen("foo_bar","w");
  assert(fp);
  fclose(fp);

  fp=fopen("bar_baz","r");
  assert(fp);
  if( fp != NULL)
    fclose(fp);

  exit(EXIT_SUCCESS);
}
