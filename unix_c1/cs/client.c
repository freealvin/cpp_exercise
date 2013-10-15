/**********************************************************
 *
 *Copyright (c) 2013
 *Alvin Hao<freealvin@sina.com>
 *All rights reserved
 *
 ************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <strings.h>
#include <arpa/inet.h>

#define MAXBUF 256

int main(int argc, char *argv[])
{
    int s = 0;
    int n = 0;
    //int reuse = 1;
    int port = 1987;
    struct sockaddr_in srv;
    char buf[MAXBUF] = {0};

    if(argc != 2)
    {
        printf("Usage:%sServerIP",argv[0]);
        return -1;
    }

    bzero(&srv, sizeof(srv));
    srv.sin_family = PF_INET;
    srv.sin_addr.s_addr = inet_addr(argv[1]);
    srv.sin_port = htons(port);

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if(s < 0)
    {
        perror("socket");
        return -1;
    }

    while(1)
    {
        memset(buf, 0, MAXBUF);

        fgets(buf, MAXBUF, stdin);

        if((n = sendto(s, buf, strlen(buf), 0, (struct sockaddr *)&srv, sizeof(struct sockaddr))) < 0)
        {
            perror("sendto");
            return -1;
        }
        else
        {
            printf("send to %s(port=%d) len %d: %s\n", argv[1], port, n, buf);
        }
    }

    return 0;
}
