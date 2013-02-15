/*
 * boom.c - abort in action
 */
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  puts("About to abort...");
  abort();
  puts("I reckon it worked.\n");  /* Never get there */

  exit(EXIT_SUCCESS);
}
