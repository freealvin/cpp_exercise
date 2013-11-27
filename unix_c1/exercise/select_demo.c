/********************************************************************************
 *
 *
 *
 *Alvin Hao <freealvin@sina.com>
 *
 *本实例是一个框架而已，它假设一个大小为MAX_SESSION_UP的int类型数组雷存储了一堆文件描述符
 *其中凡是大于零的文件描述符皆默认为我们关心的文件描述符，需要select监管它，小于或等于零的文件描述符则被忽视
 *
 *
 *
 *
 *******************************************************************************/

#include <stdio.h>
#include <sys/types.h>
#include <time.h>

#define SLEEP_TIME 10
#define MAX_SESSION_UP 10

int main(void)
{
    int i, max_sock = 0;
    int fd_num = 0;
    int accept_fd_up[MAX_SESSION_UP] = {0};
    fd_set readfds;
    struct timeval select_timeval;

    while(1)
    {
        FD_ZERO(&readfds);
        for(i=0; i<MAX_SESSION_UP; i++)
        {
            if(accept_fd_up[i] > max_sock)
            {
                max_sock = accept_fd_up[i];
            }
            if(accept_fd_up > 0)
            {
                FD_SET(accept_fd_up[i], &readfds);
            }
        }

        // 每次select之前都需要重新设置下一次的超时时间
        select_timeval.tv_sec = SLEEP_TIME;
        select_timeval.tv_usec = 0;

        fd_num = select(max_sock+1, &readfds, NULL, NULL, &select_timeval);

        if(fd_num < 0)
        {
            perror("selct");
            continue;
        }
        else if( 0 == fd_num )
        {
            printf("selct timeout...\n");
            continue;
        }

        for(i=0;i<MAX_SESSION_UP; i++)
        {
            if( FD_ISSET(accept_fd_up[i], &readfds) )
            {
                printf("do case in do_fd_up:%d, %d", accept_fd_up[i], i);
            }
        }
    }

    return 0;
}
