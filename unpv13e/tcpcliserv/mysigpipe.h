#ifndef _MYSIGPIPE_H 
#define _MYSIGPIPE_H

#include	"unp.h"

void
sig_pipe(int signo)
{
	printf("SIGPIPE received\n");
	return;
}

#endif /* _MYSIGPIPE_H */
