#ifndef _SOCKFD_TO_SOCKET_STRUCT_H
#define _SOCKFD_TO_SOCKET_STRUCT_H
/*
  function to return local address structure bound to a socket 
*/
void
sockfd_to_socket_struct(int sockfd, struct sockaddr_storage *ss){ 
    socklen_t len; 
	len = sizeof(*ss);
    if (getsockname(sockfd, (SA *)ss, &len) < 0)
		err_quit("error getting local address"); 
}

#endif /*_SOCKFD_TO_SOCKET_STRUCT_H*/




