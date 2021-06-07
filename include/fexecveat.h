
//+def
static inline int fexecveat(int fd, char *const argv[], char *const envp[]){
		return( execveat(fd,"",argv,envp,AT_EMPTY_PATH) );
}


