/*
 *testmacs.c - Exercise the function defined in filefcn.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "filefcn.h"

int main(void)
{
  FILE *fp;
  /* This call will work */
  if(open_file(&fp,"foo_bar","w",__LINE__,__FILE__)){
    exit(EXIT_FAILURE);
  } else {
    fputs("This text proves we scribbled in the file.\n",fp);
    fclose(fp);
  }

  /* This call will not work */
  if(open_file(&fp,"bar_bar","r",__LINE__,__FILE__)){
    exit(EXIT_FAILURE);
  } else {
    fputs("This text proves we scribbled in the file.\n",fp);
    fclose(fp);
  }
  return 0; 
}
