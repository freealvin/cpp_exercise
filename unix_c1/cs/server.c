/*********************************************************
 *
 *Copyright (c) 2013
 *Alvin Hao <freealvin@sina.com>
 *All rights reserved
 *
 *********************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <strings.h>

#define MAX_BUF 256

int main(int argc, char *argv[])
{
    int s = 0;
    int n = 0;
    int reuse = 1;
    int cli_len = sizeof(struct sockaddr);
    int port = 1987;
    char buf[MAX_BUF] = {0};
    struct sockaddr_in addr, cli;

    bzero(&addr, sizeof(addr));
    addr.sin_family = PF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(port);

    s = socket(AF_INET, SOCK_DGRAM, 0);
    if(s < 0)
    {
        perror("socket");
        return -1;
    }

    setsockopt(s, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    if(bind(s, (struct sockaddr *)&addr, sizeof(addr)) > 0)
    {
        perror("bind");
        return -1;
    }

    while(1)
    {
        memset(buf, 0, MAX_BUF);

        n = recvfrom(s, buf, MAX_BUF, 0, (struct sockaddr *)&cli, (socklen_t *)&cli_len);
        if(n < 0)
        {
            perror("recvfrom");
            return -1;
        }
        else
        {
            printf("receive msg from %s(port=%d) len %d:%s\n", inet_ntoa(cli.sin_addr), port, n, buf);

        }
    }

    return 0;
}
