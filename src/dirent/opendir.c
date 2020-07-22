#ifndef mini_opendir_c
#define mini_opendir_c


// opendir with predefined DIR handler. (dirbuf)

//+depends open close malloc dirbuf
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

//+depends open close malloc dirbuf opendirp
//+needs dirent.h
//+def
static DIR *opendir(const char *name ){
		DIR *dir;
	dir = malloc(sizeof(*dir));
	if ( dir == 0 ){
		//	fprintf("Got: %d\n", dir);
		return 0;
	}

	DIR* ret = opendirp(name,dir);
	if ( ret == 0 ){
			free(dir);
			return(0);
	}
	return(dir);
}
	

#endif

