#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>

#define PORT 1987

int main(int argc, char* argv[])
{
    int fd = 0;
    int newfd = 0;
    int addrlen = sizeof(struct sockaddr_in);
    int recv_len = 0;
    struct sockaddr_in addr;
    struct sockaddr_in serv_addr;
    char buf[1024] = {0};

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);/*本地字节序转化为网络字节序*/
    addr.sin_addr.s_addr = htonl(INADDR_ANY);/*自动填入IP地址*/

    if( (fd=socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("socket");
        return -1;
    }
    else
    {
        printf("create socket %d success.\n", fd);
    }

    if(bind(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
    {
        perror("bind");
        close(fd);
        return -1;
    }
    else
    {
        printf("bind the addr to socket %d success.\n", fd);
    }

    if( listen(fd, 3) < 0 )
    {
        perror("listen");
        close(fd);
        return -1;
    }
    else
    {
        printf("listen the socket %d, port %d success.\n", fd, PORT);
    }

    while(1)
    {
        if( (newfd=accept(fd, (void *)&serv_addr, (socklen_t *)&addrlen)) < 0 )
        {
            perror("accept");
            close(fd);
            return -1;
        }
        else
        {
            printf("accept a new socket %d from addr:%s port:%d success.\n", newfd, inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));
            recv_len = recv(newfd, buf, sizeof(buf), 0);
            if(recv_len < 0)
            {
                perror("recv");
                close(newfd);
                close(fd);
                return -1;
            }
            else
            {
                printf("received %d bytes of data as follow:\n", recv_len);
                printf("%s\n", buf);
            }

            close(newfd);
        }
    }

    close(fd);

    return 0;
}
