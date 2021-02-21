#ifndef mini_opendir_c
#define mini_opendir_c


// opendir with predefined DIR handler. (dirbuf)

//+depends open close malloc dirbuf opendirp ewrites free
//+needs dirent.h
//+def
static DIR *opendir(const char *name ){
		DIR *dir;
	dir = DIRBUF_MALLOC(sizeof(*dir));
	if ( dir == 0 ){
			ewrites("No memory in opendir\n");
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

