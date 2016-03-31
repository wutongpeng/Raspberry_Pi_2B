/****************** server program *****************/
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/socket.h>
#include <linux/in.h>
#include <string.h>

int sockfd,newfd;
void *read_socket();

int main()
{
    int ret;
    pthread_t read_tid,write_tid;
    struct sockaddr_in server_addr;
    server_addr.sin_family=AF_INET;/*设置域为IPV4*/
    server_addr.sin_addr.s_addr=INADDR_ANY;/*绑定到 INADDR_ANY 地址*/
    server_addr.sin_port=htons(5678);/*通信端口号为5678，注意这里必须要用htons函数处理一下，不能直接写5678，否则可能会连不上*/
    sockfd=socket(AF_INET,SOCK_STREAM,0);
    if (sockfd<0)
    {
        printf("调用socket函数建立socket描述符出错！\n");
         exit(1);
    }
    printf("调用socket函数建立socket描述符成功！\n");
    ret=bind(sockfd,(struct sockaddr *)(&server_addr),sizeof(server_addr));
    perror("server");
    if (ret<0)
    {
        printf("调用bind函数绑定套接字与地址出错！\n");
         exit(2);
    }
    printf("调用bind函数绑定套接字与地址成功！\n");
    ret=listen(sockfd,4);
    if (ret<0)
    {
        printf("调用listen函数出错，无法宣告服务器已经可以接受连接！\n");
         exit(3);
    }
    printf("调用listen函数成功，宣告服务器已经可以接受连接请求！\n");
    newfd=accept(sockfd,NULL,NULL);/*newfd连接到调用connect的客户端*/
    if (newfd<0)
    {
        printf("调用accept函数出错，无法接受连接请求，建立连接失败！\n");
         exit(4);
    }
    printf("调用accept函数成功，服务器与客户端建立连接成功！\n");
    
    /** 服务器端建立一个线程，负责从socket读取数据，当然此处并不一定非要建立一个新线程，直接在原线程中写也可以 **/
    pthread_create(&read_tid,NULL,read_socket,NULL);

    
    /********************* 令原线程睡眠 ************************/
    while(1)
    {
        sleep(10000);
    }
}

/****************** 从socket读取数据 ********************/
void *read_socket()
{
    int recv_num,recv_num_total=0;
    char recv_buf[50];
    while (1)
    {
        memset(recv_buf,0,sizeof(recv_buf));/*清空一下recv_buf缓存区*/
        recv_num=recv(newfd,recv_buf,26,0);
        if (recv_num<0)
            printf("服务器端：调用recv接收失败！\n");
        else if(recv_num>0)
        {
            recv_num_total+=recv_num;
            printf("服务器端：调用recv接收成功！本次接收到%d个字节，内容为：\"%s\"。共收到%d个字节的数据。\n",recv_num,recv_buf,recv_num_total);
            sync();
        }
        else/*收到数据为0，表明服务器与客户端的连接已经中断*/
        {
            printf("服务器端：与客户端的连接已中断，当前共收到%d个字节的数据。服务器将再次等待客户端的连接。\n",recv_num_total);
            newfd=accept(sockfd,NULL,NULL);/*当客户端退出后，再次开始接收客户端的连接*/
        }
        sleep(1);
    }
}

