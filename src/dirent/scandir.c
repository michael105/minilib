


//+doc list files and dirs in a directory
// This implementation uses malloc_brk() for the dynamic allocation
// of the listing, and tries to do as less copies as possible.
// if the select callback is 0, meaning all entries should be returned,
// There are no copies done at all, 
// besides the copying from kernelspace to userspace.
// returns the number of the read entries,
// or the negative errno on error.
//+depends errno malloc_brk realloc free memcpy dirbuf seterrno
//+def scandir
int scandir(const char *path, struct dirent **listing[], int (*fp_select)(const struct dirent *),	int (*cmp)(const struct dirent **, const struct dirent **)){

	struct dirent **names=0, **tmp;
	int cnt=0, len=0;

	int fd;

	if ((fd = open(path, O_RDONLY|O_DIRECTORY|O_CLOEXEC)) < 0){
			seterrno(fd);
		return(fd);
	}

	char *buf = malloc_brk(4096);
	if ( buf==0 ){
#ifdef errno
			errno=ENOMEM;
			return(-ENOMEM);
#endif
			return(-ENOMEM);
	}


	int pos = 0;
	int cp = 0;
	int oldcp = 0;
	int bufpos=0;
	while ( (len = getdents( fd, (struct dirent*) buf, 4096) )>0){
			printf("Len: %d\n",len);
			while ( pos < len + bufpos ){
					dirent *de = (void *)(buf+pos);
					pos+=de->d_reclen;
					// select here.
					if ( 0 ){
					} else { 
							cp += de->d_reclen;
					}
					if ( cp < pos ){
							//copy
					}
					oldcp=cp;
			}

	}



	close(fd);


	//if (cmp) qsort(names, cnt, sizeof *names, (int (*)(const void *, const void *))cmp);
	return(cnt);
}

