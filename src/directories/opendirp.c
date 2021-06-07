
//+depends open close malloc dirbuf free
//+needs dirent.h
//+def
static DIR *opendirp(const char *name, DIR *dir){
	int fd;

	if ((fd = open(name, O_RDONLY|O_DIRECTORY|O_CLOEXEC)) < 0)
		return 0;
	dir->fd = fd;
	dir->buf_pos=dir->buf_end=0;
	//dir->bufsize = mini_dirbufsize;
	return dir;
}


