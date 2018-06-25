/*
    * Write a new function named inet_pton_loose that handles these scenarios: 
    * If the address family is AF_INET and inet_pton returns 0, call inet_aton and see if it succeeds. 
    * Similarly, if the address family is AF_INET6 and inet_pton returns 0, call inet_aton and if it succeeds, 
    * return the IPv4-mapped IPv6 address.
*/
#include	"../lib/unp.h"

const char *inet_pton_loose(int family, const char *strptr, void *addrptr){
    errno = 0;
    switch (family) {
        case AF_INET:
        {      
            if(inet_pton(family, strptr, addrptr) == 0){//if presentation format invalid 
                struct in_addr in_val; //if inet_aton succeeds, store network byte order address here
                if(inet_aton(strptr, &in_val)){ 
                    //if inet_aton succeeds assign the stored network byte order address to addptr
                    addrptr = &in_val;
                    return strptr; //return presentation
                }else{
                    return NULL; //if inet_aton succeeds not
                }
            }
            else if(errno == EAFNOSUPPORT){
                perror("error");
                return NULL;
            }
            return strptr;
        }
        default:
        {
            errno = EAFNOSUPPORT;
            perror("Invalid Address Family");
            return NULL; 
        }       
    }
}

int main(int argc, char *argv[]){
    if(argc != 3){
        err_quit("usage: a.out <CommandLineArguments>");
    }
    struct sockaddr_in mysock;
    char xx[17] = {};
    if(strcmp(argv[1],"AF_INET") == 0){
        const char *presentation = inet_pton_loose(AF_INET, *(argv + 2), &mysock.sin_addr);
        printf("%s\n%u\n", presentation, mysock.sin_addr.s_addr);
        inet_ntop(AF_INET, &mysock.sin_addr, xx, INET_ADDRSTRLEN);
        printf("%s\n", xx);
    }
    
    exit(0);

} 
              

 