#include <dirent.h>
#include "__dirent.h"

//+def
int dirfd(DIR *d){
	return d->fd;
}
