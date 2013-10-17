/****************************************************************
 *
 * Alvin Hao <freealvin@sina.com>
 *
 * 使用epoll实现的服务器
 *
 * ***************************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <sys/resource.h>

#define MAXEPOLL 10000
#define MAXLINE 1024
#define PORT 1987
#define MAXBACK 1000

int main(int argc, char* argv[])
{
    int listen_fd;
    int conn_fd;
    int epoll_fd;
    int nread;
    int cur_fds;
    int wait_fds;
    int i;
    int yes = 1;
    struct sockaddr_in servaddr;
    struct sockaddr_in cliaddr;
    struct epoll_event ev;
    struct epoll_event evs[MAXEPOLL];
    struct rlimit rlt;
    char buf[MAXLINE];
    socklen_t len = sizeof(struct sockaddr_in);

    // 设置每个进程允许打开的文件数
    // 每个主机是不一样的，一般服务器应该很大
    rlt.rlim_max = rlt.rlim_cur = MAXEPOLL;
    if( -1==setrlimit(RLIMIT_NOFILE, &rlt) )
    {
        perror("setlimit");

        exit(EXIT_FAILURE);
    }

    // server 套接字
    // memset(&servaddr, 0, sizeof(servaddr));
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    // 建立套接字
    if( -1==(listen_fd=socket(AF_INET, SOCK_STREAM, 0)))
    {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // 设置非阻塞模式
    if( -1 == fcntl(listen_fd, F_SETFL, fcntl(listen_fd, F_GETFD, 0)|O_NONBLOCK))
    {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    // 端口复用
    if( -1 == setsockopt(listen_fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes)) )
    {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // 绑定
    if( -1 == bind(listen_fd, (struct sockaddr *)&servaddr, sizeof(struct sockaddr)))
    {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    // 监听
    if(-1 == listen(listen_fd, MAXBACK))
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // 创建epoll
    epoll_fd = epoll_create(MAXEPOLL);
    ev.events = EPOLLIN|EPOLLET;
    ev.data.fd = listen_fd;
    if( epoll_ctl(epoll_fd, EPOLL_CTL_ADD, listen_fd, &ev) < 0)
    {
        perror("epoll_ctl");
        exit(EXIT_FAILURE);
    }

    cur_fds = 1;

    while(1)
    {
        if(-1==(wait_fds=epoll_wait(epoll_fd, evs, cur_fds, -1)))
        {
            perror("epoll_wait");
            exit(EXIT_FAILURE);
        }
        else
        {
            printf("epoll_eait success!\n");
        }

        for(i=0; i<wait_fds; i++)
        {
            if(evs[i].data.fd == listen_fd&&cur_fds<MAXEPOLL)
            {
                if(-1 == (conn_fd=accept(listen_fd, (struct sockaddr *)&cliaddr, &len)))
                {
                    perror("accept");
                    exit(EXIT_FAILURE);
                }
                else
                {
                    printf("accept success!\n");
                }

                //printf("Server get connection from client%s:%d, new socket %d!\n", inet_ntoa(cliaddr.sin_addr), cliaddr.sin_port, conn_fd);
                ev.events = EPOLLIN|EPOLLET;
                ev.data.fd = conn_fd;
                if( epoll_ctl(epoll_fd,EPOLL_CTL_ADD, conn_fd, &ev) < 0 )
                {
                    perror("epoll_ctl");
                    exit(EXIT_FAILURE);
                }

                ++cur_fds;
                continue;
            }

            // 下面处理数据呢
            memset(buf, 0, sizeof(buf));
            nread = read(evs[i].data.fd, buf, sizeof(buf));
            if( nread < 0 )
            {
                printf("Disconnected with the socket %d, so close it!\n", evs[i].data.fd);
                close(evs[i].data.fd);
                epoll_ctl(epoll_fd, EPOLL_CTL_DEL, evs[i].data.fd, &ev);

                --cur_fds; // 事件队列内的fd减一
                continue;
            }
            printf("Received:%s\n",buf);
            write(evs[i].data.fd, buf, nread);
        }
    }

    close(listen_fd);
    return 0;


}
