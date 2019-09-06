#ifndef opendir_c
#define opendir_c
#include "dirent.h"



//+depends open close malloc
//+needs dirent.h
//+def
DIR *opendir(const char *name){
	int fd;
	DIR *dir;

	if ((fd = open(name, O_RDONLY|O_DIRECTORY|O_CLOEXEC)) < 0)
		return 0;
	dir = malloc(sizeof(*dir));
	if ( dir == 0 ){
		//	fprintf("Got: %d\n", dir);
		close( fd );
		return 0;
	}

	dir->fd = fd;
	dir->buf_pos=dir->buf_end=0;
	return dir;
}



#endif

