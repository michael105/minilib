
//+def
static inline int fexecveat(int fd, char *const argv[], char *const envp[]){
		return( execveat(fd,0,argv,envp,AT_EMPTY_PATH) );
}


