#include<arpa/inet.h>
//void connect_fun(int sockfd ,struct sockaddr_in serverAddr , struct sockaddr_in servAddr){
//connect(sockfd,(struct sockaddr*)&serverAddr , sizeof(servAddr));
//printf("Connection created\n");

//}

void send_fun(int sockfd, const char *data, size_t len , int flag){

send(sockfd,data,len,flag);


}
void recieve_fun(int sockfd, char *data, size_t len , int flag){

recv(sockfd,data,len,flag);
printf("Data Recieved from client: %s\n",data);

}



