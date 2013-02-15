/*
 * filefcn.h - A function to open files
 */
#ifndef FILEFCN_H_
#define FILEFCN_H_
#include <stdio.h>

int open_file(FILE **fp,char *fname,char *mode,int line,char *file);

#endif /*FILEFCN_H_*/
