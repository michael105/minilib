
//+depends environ execvpe access getenv access
//+def
static inline int execvp(const char *file, char *const argv[]){
		return( execvpe( file, argv, environ ) );
};



