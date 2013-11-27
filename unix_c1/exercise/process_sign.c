#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(void)
{
    pid_t p;
    int r;
    p = fork();

    // 创建子进程失败
    if(p<0)
    {
        printf("Creating child process failure!\n");
        exit(1);
    }

    // 子进程
    if(p==0)
    {
        // 调用raise函数， 发送SIGSTOP使子进程暂停
        raise(SIGSTOP);
        exit(0);
    }

    // 父进程
    if (p>0)
    {
        printf("子进程的进程号是:%d\n", p);
        if((waitpid(p, NULL, WNOHANG))==0)
        {
            // 调用kill函数， 发送SIGKILL信号结束子进程
            if(r=kill(p, SIGKILL)==0)
            {
                printf("发出的SIGKILL信号结束的进程号是：%d\n", p);
            }
            else
            {
                printf("调用kill函数失败!\n");
                exit(1);
            }
        }
    }
}
