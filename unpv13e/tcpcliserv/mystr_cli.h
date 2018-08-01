#ifndef _MYSTR_CLI_H 
#define _MYSTR_CLI_H

#include	"unp.h"

void
str_cli(FILE *fp, int sockfd)
{
	char	sendline[MAXLINE], recvline[MAXLINE];

	while (Fgets(sendline, MAXLINE, fp) != NULL) {

		//Writen(sockfd, sendline, strlen(sendline));
		sleep(2);           
		Writen(sockfd, sendline, 2);           
		sleep(2);	
		Writen(sockfd, sendline + 2, strlen(sendline) - 2); 


		if (Readline(sockfd, recvline, MAXLINE) == 0)
			err_quit("str_cli: server terminated prematurely");

		Fputs(recvline, stdout);
	}
}

#endif /* _MYSTR_CLI_H */
