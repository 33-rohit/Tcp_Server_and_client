#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include "../headerfiles/server_headerfile.h"


#define PORT 5555

void main()
{
 int sockfd;
 struct sockaddr_in serverAddr;
 
 int newSocket;
 struct sockaddr_in newAddr;	
 
 socklen_t addr_size;
 char buf[1024];
 
 sockfd=socket(PF_INET,SOCK_STREAM,0);
 printf("Server socket Created Successfully...\n"); 
 memset(&serverAddr,'\0',sizeof(serverAddr));
 
 
 serverAddr.sin_family=AF_INET;
 serverAddr.sin_port=htons(PORT);
 serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
 
 bind(sockfd,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
 printf("Bind to Port Number %d\n",4455);
 

 listen(sockfd,6);
 printf("Listening...\n");
    
 
 newSocket=accept(sockfd,(struct sockaddr*)&newAddr,&addr_size);


 

printf("Enter Data send to client  : ");
scanf("%s" , buf);
 /*strcpy(buf,"HELLO FROM Server");*/ 
send_fun(newSocket,buf,strlen(buf),0);
// send(newSocket,buf,strlen(buf),0);

 recieve_fun(newSocket,buf,1024,0);
 //recv(newSocket,buf,1024,0);
 //printf("Data Received: %s\n",buf);
 
 printf("Closing Connection...\n"); 
 }


