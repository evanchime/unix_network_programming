#ifndef _MYSIGCHLDWAIT_H 
#define _MYSIGCHLDWAIT_H

#include	"unp.h"

void
sig_chld(int signo)
{
	pid_t	pid;
	int	stat;

	/*pid = wait(&stat);
	printf("child %d terminated\n", pid);*/
	while ( (pid = waitpid(-1, &stat, WNOHANG)) > 0)  //version that calls waitpid      
    		printf("child %d terminated\n", pid);
	return;
}

#endif /* _MYSIGCHLDWAIT_H */
