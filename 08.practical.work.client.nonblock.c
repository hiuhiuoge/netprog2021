#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define CMD_QUIT "q"
#define CMD_SHUTDOWN "shutdown"

int main(int argc, char *argv)
{
    int sockfd, portno, n;
    struct hostent *hostname;
    char *ipaddr;
    unsigned short port = 8784;



    if ((sockfd=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error creating socket \n");
        return -1
    }

        setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &(int){ 1 }, sizeof(int));
        int fl = fcntl(sockfd, F_GETFL, 0);
        fl |= O_NONBLOCK

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

   
    while (1) {
        bzero(buffer, sizeof(buffer));
        fgets(buffer, sizeof(buffer), stdin);
    
        n = write(sockfd, buffer, strlen(buffer));
        if (n < 0) 
                error("ERROR writing to socket\n");
        bzero(buffer, sizeof(buffer));
    
        n = read(sockfd, buffer ,sizeof(buffer));
        if (n < 0) 
            error("ERROR reading from socket\0");
        printf("%s\0", buffer);
        
        if(n > 0) {
            chat_room_write(STDOUT_FILENO, buffer, bytes);
            }
            else {
                printf("connection closed\n");
                break;
            }
        return 0;
        }

    }
    exit(0);
}