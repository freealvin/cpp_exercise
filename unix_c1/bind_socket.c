/******************************************************
 *
 *Alvin Hao <freealvin@sina.com>
 *
 * 调用socket()函数返回一个Socket后，在使用Socket进行网络传输以前，必须配置该Socket
 * bind函数将Socket与本机上的一个端口相关联，随后我们就可以在该端口监听服务请求
 *
 * bind(int sockfd, struct sockaddr *my_addr, int addrlen)
 *       sockfd是调用socket()函数后返回的socket描述符
 *       my_addr是一个指向本机IP地址及端口号信息的sockaddr类型的指针
 *       addrlen常常被设置为sizeof(struct sockaddr)
 *
 ****************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 1987

int main(int argc, char* argv[])
{
    int fd;
    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT); //指定端口号，本地字节序转化为网络字节序
    addr.sin_addr.s_addr = htonl(INADDR_ANY);//自动填入本机IP地址，并将32位值从本地字节序转换成网络字节序

    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        return -1;
    }
    else{
        printf("create socket %d success.\n", fd);
    }

    if(bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        return -1;
    }
    else
    {
        printf("bind the addr to socket %d success.\n", fd);
    }

    return 0;

}
