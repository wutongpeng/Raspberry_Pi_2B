/*
server.c
socket test
2015-11-23 0:19
*/

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main()
{
	int server_sockfd, client_sockfd;
	int server_len, client_len;
	struct socket_in server_address;
	struct socket_in client_address;
	
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr =inet_addr("127.0.0.1");
	server_address.sin_port =9734;
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *) &server_address, server_len); //20  定义
	listen(server_sockfd, 5);
	
	while (1) 
	{
		char ch;
		printf("服务器等待消息\n");
		client_len = sizeof(client_address);
		client_sockfd = accept (server_sockfd,
		  (struct sockaddr *) &client_len 
		  (socklen_t *restrict)&client_len);
		read(client_sockfd, &ch, 1);
		close(client_sockfd);
	}
	
}
