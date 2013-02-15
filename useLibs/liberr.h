/*
 * liberr.h
 * Declarations for simple error-handling library
 */

#ifndef _LIBERR_H

#define _LIBERR_H
#include <stdarg.h>
#define MAXLINELEN 4096

/*
 * Print an error message to stderr and return to caller
 */
void err_ret(const char *fmt,...);

/*
 * Print an error message to stderr and exit
 */
void err_quit(const char *fmt,...);

/*
 * Print an error message to log file and return to caller
 */
void log_ret(char *logfile, const char *fmt,...);

/*
 * Print an error message to logfile and exit
 */
void log_quit(char *logfile,const char *fmt,...);

/*
 * Print an error message and return to caller
 */
void err_prn(const char *fmt,va_list ap,char *logfile);
#endif _LIBERR_H
