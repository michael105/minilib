//+header unistd.h
//+include


//+depends environ execve
//+def
static inline int execv(const char *pathname, char *const argv[]){
		return( execve( pathname, argv, environ ) );
};

//+def
static inline int fexecveat(int fd, char *const argv[], char *const envp[]){
		return( execveat(fd,0,argv,envp,AT_EMPTY_PATH) );
};

//TODO: PATH searching
//+depends environ execve
//+doc doesn't search the path env (todo)
//+def
static inline int execvpe(const char *file, char *const argv[], char *const envp[]){
#warning execvpe/execvp do not search the PATH environment
		return( execve( file, argv, envp ) );
};


//+depends environ execve
//+def
static inline int execvp(const char *file, char *const argv[]){
		return( execvpe( file, argv, environ ) );
};




