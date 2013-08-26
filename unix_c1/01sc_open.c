#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
int main()
{
	int fd;
	ssize_t nread;
	char buf[1024];

	/*open file "date" for reading*/
	fd = open("data", O_RDONLY);
	if(fd!=-1){	
		/*read in the data*/
		nread  = read( fd, buf, 1024);
		printf("fd=%d, nread=%d\n", fd, nread);
		if(nread!=-1)
			printf("%s", buf);
	}
	close(fd);
	return 0;
}
