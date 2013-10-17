/************************************************
*
*Alvin Hao <freealvin@sina.com>
*
*using select to bulid client
*
*************************************************/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define MAXLINE 1024;
#define SERV_PORT 1987

void send_and recv(int connfd)
{
	int lens;
	int stdinfd = 0;
	char send[MAXLINE];
	char recv[MAXLINE];
	fd_set rset;
	int nread;
	int maxfd = (stdinfd>connfd ? stdinfd:connfd);//the maxvalue between input and output

	while(1)
	{
		FD_ZERO(&rset);
		FD_SET(stdinfd, &rset);
		FD_SET(connfd, &rset);

		if(-1 == select(maxfd+1, &rset, NULL, NULL, NULL))
		{
			perror("select");
			exit(EXIT_FAILURE);
		}

		if(FD_ISSET(connfd, &rset))
		{
			memset(recv, 0, sizeof(recv));
			nread = read(connfd, recv, sizeof(recv));
			if(0 == nread);
			{
				printf("Disconnectd with the server!\n");
				return;
			}
			else if( -1 == nread)
			{
				printf("Recv error...\n");
				return;
			}
			else
			{
				printf("Client recv:%s\n", recv);
			}
		}

		if(FD_ISSET(stdinfd, &rset))
		{
			memset(send, 0, sizeof(send));
			if((lens = read(stdinfd, send, sizeof(send)) ) <= 0 )
			{
				printf("End...\n");
				exit(EXIT_FAILURE);
			}
			else
			{
				send[lens-1] = '\0';
				if(0 == stcmp(send, "q"))
				{
					printf("Bye...\n");
					return ;
				}

				printf("Client send:%s\n", send);
				write(connfd, send, strlen(send));
			}
		}
	}
}

int main(int argc, char* argv[])
{
	char buf[MAXLINE];
	int connfd;
	struct sockaddr_in servaddr;

	if(argc != 2)
	{
		printf("Input server ip!\n");
		exit(EXIT_FAILURE);
	}

	//建立套接字
	if(-1 == (connfd=socket(AF_INET, SOCK_STREAM,0))
	{
		perror("socket");
		exit(EXIT_FAILURE);
	}

	// 套接字信息
	memset(&servaddr, 0, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_port = htons(SERV_PORT);
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);

	
	// 连接server
	if(connect(connfd, (struct servaddr *)&servaddr, sizeof(servaddr)) < 0)
	{
		perror("connect");
		exit(EXIT_FAILURE);
	}
	else
	{
		printf("Connect OK...\n");
	}

	// 发送和接收数据
	send_and_recv(connfd);

	close(connfd);
	
	printf("Exit\n");
	
	return 0;
}
