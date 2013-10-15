#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 1987
#define SERVERIP "127.0.0.1"

int main(void)
{
    int fd;
    struct sockaddr_in addr;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);

    addr.sin_addr.s_addr = inet_addr(SERVERIP);

    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0 )
    {
        perror("socket");
        return -1;
    }
    else
    {
        printf("create socket %d success.\n",fd);
    }

    if( connect(fd, (struct sockaddr *)&addr, sizeof(addr)) < 0 )
    {
        perror("connect");
        return -1;
    }
    else
    {
        printf("connect the addr:%s port:%d by socket %d success.\n", SERVERIP, PORT, fd);
    }

    close(fd);

    return 0;
}
