/*
    *Modify Figure 1.5 to call getsockname after connect returns successfully. 
    *Print the local IP address and local port assigned to the TCP socket using sock_ntop. 
    *In what range (Figure 2.10) are your system's ephemeral ports?
*/

#include "../lib/unp.h"
#include "../lib/sock_ntop.c"
#include "sockfd_to_socket_struct.h"

int main(int argc, char **argv)
{
	int sockfd, n;
	char recvline[MAXLINE + 1];
	struct sockaddr_in	servaddr;

	if (argc != 2)
		err_quit("usage: a.out <IPaddress>");

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
				//printf("%d\n", errno);
				err_sys("socket error");
	}

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port   = htons(13);	/* daytime server */
	if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0)
		err_quit("inet_pton error for %s", argv[1]);

	if (connect(sockfd, (SA *) &servaddr, sizeof(servaddr)) < 0){
		//printf("%d\n", errno);
		err_sys("connect error");
	}

	struct sockaddr_storage ss; 
	sockfd_to_socket_struct(sockfd, &ss);
	printf("%s\n", Sock_ntop((SA *)&ss, sizeof(ss)));

	int counter = 1;

	while ( (n = read(sockfd, recvline, MAXLINE)) > 0) {
		counter++;
		recvline[n] = 0;	/* null terminate */
		if (fputs(recvline, stdout) == EOF)
			err_sys("fputs error");
	}
	if (n < 0)
		err_sys("read error");

	printf("%d\n", counter);
	exit(0);
}


