/***************************************************************
 *
 *Alvin Hao <freealvin@sina.com>
 *
 *根据域名转换成IP地址
 *
 * *************************************************************/

#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

int main(int argc, char* argv[])
{
    char ** pptr = NULL;
    struct hostent* hptr = NULL;
    char str[64] = {0};

    if(argc != 2)
    {
        printf("Usage:%s domain\n", argv[0]);
        return -1;
    }

    if(NULL == (hptr = gethostbyname(argv[1])))
    {
        perror("gethostbyname");
        return -1;
    }

    printf("official hostname:%s\n", hptr->h_name);

    for( pptr=hptr->h_aliases; *pptr!=NULL; pptr++ )
    {
        printf("alias:%s\n", *pptr);
    }

    switch(hptr->h_addrtype)
    {
        case AF_INET:
        case AF_INET6:
            printf("print ip address\n");
            for(pptr=hptr->h_addr_list; *pptr!=NULL; pptr++)
            {
                // printf("address:%s\n", *pptr);
                // 如果不加上<arpa/inet.h>会出现segment fault段错误
                printf("address:%s\n", inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
                //printf("address:%s\n", inet_ntop(hptr->h_addrtype, *pptr, str, sizeof(str)));
            }
            break;
        default:
            printf("unknown address type\n");
            break;
    }

    return 0;
}
