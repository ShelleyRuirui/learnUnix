/*
 * showit.c - using __FUNCTION__ variable
 */

#include<stdio.h>
void foo(void);

int main(void)
{
  printf("The current function is %s\n",__FUNCTION__);
  foo();
  printf("New\n");
  return 0;
}

void foo(void)
{
  printf("The current function is %s\n",__FUNCTION__);
}
