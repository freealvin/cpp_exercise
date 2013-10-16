#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 1987
#define SERVERIP "192.168.119.128"

int main()
{
        int fd = 0;
        int send_len = 0;
        struct  sockaddr_in addr;
        char buf[] = {"hello world"};

        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(PORT);//指定服务器的端口
        addr.sin_addr.s_addr = inet_addr(SERVERIP);

        if((fd=socket(AF_INET, SOCK_STREAM,0)) < 0)
        {
             perror("socket");
            return -1;
        }
        else
        {
            printf("create socket %d success.\n", fd);
        }

        if(connect(fd, (struct sockaddr*)&addr, sizeof(addr)) < 0)
        {
            perror("connect");
            return -1;
        }
        else
        {
            printf("connect the addr:%s port:%d by socket %d success.\n", SERVERIP, PORT, fd);
        }

        send_len = send(fd, buf, sizeof(buf), 0);

        if(send_len < 0)
        {
            perror("send");
            close(fd);
        }
        else
        {
            printf("send %d bytes data to socket %d, the content of buf is:\n", send_len, fd);
            printf("%s\n", buf);
        }

        close(fd);
        return 0;
}
