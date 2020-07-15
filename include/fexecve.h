
//+def
static inline int fexecve(int fd, char *const argv[], char *const envp[]){
		return( execveat(fd,"",argv,envp,AT_EMPTY_PATH) );
}


