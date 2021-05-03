#include <stdio.h> 
#include <netdb.h> 
#include <arpa/inet.h> 
  

int main() 
{ 
    char hostbuffer[256]; 
    char *IPbuffer; 
    struct hostent *host_entry;

    scanf("%s", hostbuffer);
    host_entry = gethostbyname(hostbuffer);
    if (host_entry == NULL) {
       printf("Invalid\n");
       return 1;
    } 
   
    IPbuffer = inet_ntoa(*((struct in_addr*) 
                           host_entry->h_addr_list[0])); 
  
    printf("Hostname: %s\n", hostbuffer);
    printf("Host IP: %s\n", IPbuffer); 
  
    return 0; 
}
