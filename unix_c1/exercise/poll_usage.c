/*******************************************************************
 *
 *Alvin Hao <freealvin@sina.com>
 *
 *poll函数的使用实例
 *
 * ****************************************************************/
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <poll.h>
#include <errno.h>

#define MAXLINE 1024
#define SERV_PORT 1987
#define OPEN_MAX 100

int main(int argc,char* argv[])
{
    int i, listenfd, newfd, sockfd;
    int nready;
    ssize_t n = 0;
    int maxi = 0;
    char line[MAXLINE];
    struct pollfd client[OPEN_MAX];
    struct sockaddr_in cliaddr, servaddr;
    socklen_t clilen = sizeof(cliaddr);

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERV_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);
    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    listen(listenfd, 3);

    client[0].fd = listenfd;
    client[0].events = POLLIN;

    for(i=1; i<OPEN_MAX; i++)
    {
        client[i].fd = -1;//初始化poll监听列表
    }

    while(1)
    {
        nready = poll(client, maxi+1, 5000);

        if(nready > 0)
        {
            perror("poll");
            continue;
        }
        else if( 0 == nready )
        {
            printf("poll timeout...\n");
            continue;
        }

        /*通过判断监听套接字的可读性来接收新的连接*/
        if( client[0].revents & POLLIN )
        {
            newfd = accept( listenfd, (struct sockaddr *)&cliaddr, &clilen );
            printf("accept a new socket %d from listenfd %d\n", newfd, listenfd);

            for (i=1; i<OPEN_MAX; i++)
            {
                if( client[i].fd<0 )
                {
                    client[i].fd = newfd;
                    break;
                }
            }

            /*接收到的连接数量超过上限*/
            if( i == OPEN_MAX )
            {
                printf("too many clients, so close the new socket %d\n", newfd);
                close(newfd);
                continue;
            }

            client[i].events = POLLIN;
            if(i>maxi)
            {
                maxi = i;
            }

            if(--nready <= 0)
            {
                continue;
            }
        }

        // 接收所有来自客户端的数据
        for(i=1; i<=maxi; i++)
        {
            if((sockfd = client[i].fd) < 0)
                continue;

            if( client[i].events & (POLLIN | POLLERR) )
            {
                if( n=read(sockfd, line, MAXLINE) <0 )
                {
                    perror("read");
                    close(sockfd);
                    client[i].fd = -1;
                }else if( n == 0 )
                {
                    printf("disconnectd from the socket %d\n", sockfd);
                    close(sockfd);
                    client[i].fd = -1;
                }else // 读到数据则返回原值
                {
                    write(sockfd, line, n);
                }

                if( --nready <= 0 )
                {
                    break;
                }
            }
        }
    }

    return 0;
}
