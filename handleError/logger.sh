#! /bin/sh
# logger.sh - Demo the shell command interface to syslog
################

echo 'Type the log msg and press ENTER'
read MSG
logger -is -t logger.sh $MSG