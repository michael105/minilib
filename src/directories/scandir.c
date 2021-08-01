
//+doc list files and dirs in a directory
//
// This implementation uses malloc_brk() for the dynamic allocation
// of the listing, and tries to do as less copies as possible.
// The dynamically allocated space for the result list (**listing[])
// is guaranteed to be at one continuous memory location.
//
// if the select callback is 0, meaning all entries should be returned,
// There are no copies done at all, 
// besides the copying from kernelspace to userspace.
//
// To free the space, allocated for the listing,
// either call free_brk(),
// when no other allocations via malloc_brk took place.
//
// Or save the brk before you call scandir,
// and restore it after the call.
// (e.g.)
// long savebrk=getbrk();
// int ret=scandir(...);
// brk(savebrk);
// Freeing single list entries might give unexpected results.
//
// returns the number of the read entries,
// or the negative errno on error.
//
//+depends errno malloc_brk realloc free memcpy dirbuf seterrno getbrk sbrk prints open sprintf qsort getdents
//+def scandir
int scandir(const char *path, struct dirent **listing[], int (*fp_select)(const struct dirent *),	int (*cmp)(const struct dirent **, const struct dirent **)){
	struct dirent **names=0, **tmp;
	int cnt=0, len=0;
#ifndef mini_scandir_bufsize
#define _BUFSIZE 4096
#else
#define _BUFSIZE mini_scandir_bufsize
#endif



	int fd;

	if ((fd = open(path, O_RDONLY|O_DIRECTORY|O_CLOEXEC)) < 0){
			seterrno(fd);
		return(fd);
	}

	char *buf;
	buf= malloc_brk(_BUFSIZE);
	if ( buf==0 ){
			seterrno(ENOMEM);
			return(-ENOMEM);
	}


	int pos = 0;
	int cp = 0;
	int oldcp = 0;
	int bufpos=0;
	int oldpos=0;
	while ( (len = getdents( fd, (struct dirent*) (buf+bufpos), _BUFSIZE) )>0){
			//printf("Len: %d\n",len);
			while ( pos < len + bufpos ){
					struct dirent *de = (void *)(buf+pos);
					pos+=de->d_reclen;
					// select here.
					if ( !(fp_select && !(fp_select(de))) ){ // selected
							cnt++;
							cp += de->d_reclen;
							//printf("%s\n", de->d_name );
					}
					if ( oldcp < oldpos ){
							//copy
							memcpy(buf+oldcp,buf+oldpos,de->d_reclen);
					}
					oldcp=cp;
					oldpos=pos;
			}
			bufpos=pos;
			buf=realloc(buf,bufpos+_BUFSIZE);
			//printf("buf: %l, pos: %d, cp: %d\n",buf,pos,cp);
			if ( !buf) {
					seterrno(ENOMEM);
					close(fd);
					return(-ENOMEM);
					break;
			}
	}

	if ( len<0 ){
			close(fd);
			seterrno(len);
			return(len);
	}
	close(fd);

	// alloc place for the pointer list, when needed
	if ( cnt*sizeof(POINTER) > _BUFSIZE+(pos-cp) ){
			//prints("realloc\n");
			realloc(buf,cp+(cnt*sizeof(POINTER)));
			if ( !buf ){
					seterrno(ENOMEM);
					return(-ENOMEM);
			}
	}
	
	struct dirent *de;
	de = (void*)buf;
	struct dirent **list;
	list= (void*)(buf+cp);
	//printf("build list, cnt: %d\n",cnt);
	for(int a=0;a<cnt;a++){
			//printf("a: %d, cnt:%d, de->d_name: %s\n",a,cnt,de->d_name);
			*list = de;
			*list++;
			de=(void*)de+de->d_reclen;
	}
	list = (void*)(buf+cp);
	*listing = (void*)(buf+cp);

	//printf("sort now. %d, cnt: %d\n",sizeof(struct dirent**),cnt);
	if (cmp){
		//qsort_p(*listing,cnt,(int (*)(const void*,const void *))cmp);
		qsort(*listing,cnt,sizeof(struct dirent*),(int (*)(const void*,const void *))cmp);
	}

	return(cnt);
}

