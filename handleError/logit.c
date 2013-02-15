/*
 * logit.c - Demonstrate the syslog interface
 */

#include<syslog.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>

int main(int argc,char * argv[])
{
  int omask;
  openlog("logit",LOG_PID,LOG_USER);
  syslog(LOG_INFO,"This message courtesy of UID #%d\n",getuid());
  syslog(LOG_NOTICE,"Hopefully, you see this\n");
  closelog();

  omask=setlogmask(LOG_UPTO(LOG_NOTICE));
  syslog(LOG_INFO,"You should not be seeing this\n");
  syslog(LOG_DEBUG,"I don't hope you to see this\n");
  syslog(LOG_NOTICE,"Restoring old value\n");

  setlogmask(omask);
  syslog(LOG_INFO,"You should see this\n");
  syslog(LOG_DEBUG,"I hope you see this\n");

  exit(EXIT_SUCCESS);
}



