#include <unistd.h>

// read len bytes from file and deal with error
ssize_t ret;
while(len!=0&&(ret=read(file, buff,len))!=0)
{
    if( ret == -1 )
    {
        if( errno == EINTER ) // failure because of recieving a interruption signal, can invoke again
	    continue;
	perror(errno); // failure because of serious error 
	break;
    }
    len -= ret; // "len - ret" bytes left to be read
    buff += ret; //  save the remaning bytes in a new index
}
