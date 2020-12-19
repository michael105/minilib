
//+depends environ execve
//+def
static inline int execv(const char *pathname, char *const argv[]){
		return( execve( pathname, argv, environ ) );
};


