#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv)
{
    int sockfd, portno, n;
    struct hostent *hostname;
    char *ipaddr;
    unsigned short port = 8784;
    struct sockaddr_in saddr, caddr;
    int sockfd;
    unsigned short port = 80;


    if ((sockfd=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket \n");
        return -1
    }

        if(argc == 2) {
	hostname = gethostbyname(argv[1]);
	}
        else {
            printf("%s\n", " Enter hostname: ");
            char str[50];
            scanf("%s", str);
            hostname = gethostbyname(str);
	 }

	 printf("IP address is: \n");
    
    if (h=gethostbyname() == NULL) {
        printf("Unknown host. \n");
        return -1
    }

    else {
	for (unsigned int i=0; hostname->h_addr_list[i] != NULL; i++){
	    printf("%s\n", inet_ntoa( *(struct in_addr*)(hostname->h_addr_list[i])));
         }
    }

    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    memcpy((char *) &saddr.sin_addr.s_addr, h->h_addr_list[0], h->h_length);
    saddr.sin_port = htons(port);
    
    if (connect(sockfd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0) {
        printf("Cannot connect \n");
        return -1
    }
    else {}
    return 0;

    FILE *fp;
    read(connfd,buffer,200);
    fp=fopen("add1.txt","w");
    fprintf(fp,"%s",buf);
    printf("the file was received successfully");
    printf("the new file created is add1.txt");
}
