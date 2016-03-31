/*
client.c
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
	int sockfd;
	int len;
	sruct sockaddr_in address;
	int result;
	char ch = 'A';
	sockfd = socket(AF_INET,SOCK_STREAM, 0);
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = 9734;
	len = sizeof(address);
	result = connect(socfd, (struct sockaddr *) &address, len);
	
	if (result == -1) 
	{
		perror("连接失败");
		return 1;
	}
	write(sockfd, &ch, 1);
	read(sockfd, &ch, 1);
	printf("来自服务器的消息是%c\n",sh);
	close(sockfd);
	return 0;
}