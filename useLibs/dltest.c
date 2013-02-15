/*
 * dltest.c - Dynamically load liberr.so and call err_ret
 */

#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main(void)
{
  void *handle;
  void (*errfcn) (const char *fmt,...);
  const char *errmsg;
  FILE *pf;

  /* open the library */
  handle=dlopen("./liberr.so",RTLD_NOW);
  if(handle==NULL){
    fprintf(stderr,"Failed to load liberr.so:%s\n",dlerror());
    exit(EXIT_FAILURE);
  }

  dlerror();
  errfcn=dlsym(handle,"err_ret");
  if((errmsg=dlerror())!=NULL){
    fprintf(stderr,"Failed to load liberr.so:%s\n",errmsg);
    exit(EXIT_FAILURE);
  }
 
  if((pf=fopen("foobar","r"))==NULL){
    errfcn("Couldn't open foobar");
  }
  dlclose(handle);
  exit(EXIT_SUCCESS);
}
