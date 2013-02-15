/*
 * errtest.c - Test program for error-handling library
 */

#include <stdio.h>
#include <stdlib.h>
#include "liberr.h"

#define ERR_QUIT_SKIP 1
//#define LOG_QUIT_SKIP 1

int main(void)
{
  FILE *pf;

  puts("Testing err_ret");
  if((pf=fopen("foo","r"))==NULL){
    err_ret("%s %s","err_ret","failed to open foo");
  }

  puts("Testing log_ret");
  if((pf=fopen("foo","r"))==NULL){
    log_ret("errtest.log","%s %s","log_ret","failed to open foo");
  }

  #ifndef ERR_QUIT_SKIP
  puts("Testing err_quit");
  if((pf=fopen("foo","r"))==NULL){
    err_quit("%s %s","err_quit","failed to open foo");
  }
  #endif

  #ifndef LOG_QUIT_SKIP
  puts("Testing log_quit");
  if((pf=fopen("foo","r"))==NULL){
    log_ret("errtest.log","%s %s","log_quit","failed to open foo");
  }

  #endif
  exit(EXIT_SUCCESS);
}
