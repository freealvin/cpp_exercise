#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#define BUFSIZE 512

main()
{
	char buffer[BUFSIZE];
	int filedes;
	ssize_t nread;
	long total = 0;
	
	if((filedes = open("anotherfile", O_RDONLY)) ==-1)
	{
		printf("error in opening anotherfile \n");
		exit(1);
	}
	while((nread = read(filedes, buffer, BUFSIZE))>0)
		total += nread;
	printf("Total chars in anotherfile:%ld \n", total);
	exit(0);
}
