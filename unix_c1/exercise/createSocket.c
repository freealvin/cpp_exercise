/****************************************************
 *
 *Alvin Hao <freealvin@sina.com>
 *
 ***************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>



int main(int argc, char *argv[])
{
    int fd;

    if((fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        perror("socket");
        return -1;
    }
    else
    {
        printf("a socket was created.\n");
        printf("socket number: %d\n", fd);
    }

    if((fd = socket(AF_INET, 123, 0)) < 0)
    {
        perror("error");
        return -1;
    }
    else
    {
        printf("a socket was created.\n");
        printf("socket number:%d\n", fd);
    }

    return 0;
}
