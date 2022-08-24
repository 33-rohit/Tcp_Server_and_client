#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include "../headerfiles/client_headerfile.h"
//#include "client_headerfile.h"  //you can use this if your headerfile present in the same program directory 

#define PORT 5555

 void main(){

 int clientSocket;
 struct sockaddr_in serverAddr;
 char buf[1024];


 
 clientSocket=socket(PF_INET,SOCK_STREAM,0);
 printf("Client socket Created Successfully...\n");
 
 memset(&serverAddr,'\0',sizeof(serverAddr));
 serverAddr.sin_family=AF_INET;
 serverAddr.sin_port=htons(PORT);
 serverAddr.sin_addr.s_addr=inet_addr("127.0.0.1");
 
 connect_fun(clientSocket,serverAddr,serverAddr);
 // connect(clientSocket,(struct sockaddr*)&serverAddr,sizeof(serverAddr));
 //printf("Connected to Server Successfully...\n");

 recieve_fun(clientSocket,buf,1024,0);
 //recv(clientSocket,buf,1024,0);
 //printf("Data recieved from server : %s\n",buf);

 printf("Enter Data for server : ");
 scanf("%s" , buf);
 send_fun(clientSocket,buf,strlen(buf),0);
 //send(clientSocket,buf,strlen(buf),0);
 /*strcpy(buf,"HELLO back from client");*/ 


 printf("Closing Connection...\n"); 
}



