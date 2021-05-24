#include <stdio.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

int main (int argc, char *argv[])
{
    int sockfd, clen, clientfd;
    struct sockaddr_in saddr, caddr, cli_addr;
    unsigned short port = 8784;

    if ((sockfd=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf(“Error creating socket\n”);
        return -1;
    }
    memset(&saddr, 0, sizeof(saddr));
    saddr.sin_family = AF_INET;
    saddr.sin_addr.s_addr = htonl(INADDR_ANY);
    saddr.sin_port = htons(port);
    
    if ((bind(sockfd, (struct sockaddr *) &saddr, sizeof(saddr)) < 0) {
        printf(“Error binding\n”);
        return -1;
    }

    if (listen(sockfd, 5) < 0) {
        printf(“Error listening\n”);
        return -1;
    }

    clen=sizeof(caddr);

    if ((clientfd=accept(sockfd, (struct sockaddr *) &caddr, &clen)) < 0) {
        printf(“Error accepting connection\n”);
        return -1
    }

    valread = read( new_socket , buffer, 1024);
    printf("%s\n",buffer );
    send(new_socket , buffer , strlen(buffer) , 0 );
    printf("Message sent\n");
    while (1) {
            int n = recv(clientfd, buffer, sizeof(buffer), 0);
            if (n == 0) {
                printf("Error!\n");
                exit(0);
            }
            else {
                int firstChar = 0;
                for (int i = 0; i < n; i++) {
                    if (buffer[i] == '\0') {
                        printf("Client:\n", &buffer[firstChar]);
                        firstChar = i+1;
                    }
                }
                memset(buffer, 0, sizeof(buffer));
                printf("Enter: \n");
                scanf("%s", buffer);
                send(clientfd, buffer, strlen(buffer), 0);
            }
    
    static void process_command (int client_fd, char *buffer, int bytes){
    int len = strlen (CMD_ESC_SEQ);
        if(strncmp(cmd, CMD_QUIT, strlen(CMD_QUIT)) == 0) {
            remove_fd(client_fd);
            close(client_fd);
        }
    
    }
    return 0;
}
