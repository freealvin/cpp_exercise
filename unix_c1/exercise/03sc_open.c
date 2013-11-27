#include<stdlib.h>
#include<fcntl.h>

#define PERMS 0644

char* filename = "newfile";

int main()
{
	int filedes;
	if((filedes=open(filename, O_RDONLY|O_CREAT, PERMS))==-1)
	{
		printf("couldn't create %s \n", filename);
		exit(1);
	}
	exit(0);
	return 0;
}
