//+doc remove a string from the environmental vars
// The env var is not free'd. (It's not possible,
// since we don't know whether the string has been allocated 
// with malloc or has been setup by the system )
// Returns: 
// - 0 on success, 
// - EINVAL: string was 0, did contain a '=', some other error
//+depends environ getenv strncmp ret_errno
//+def
int unsetenv( char *name){
	char **envp;
	int a;

	for ( envp=environ; *envp; envp++ ){
		for ( a=0; (envp[0][a] == name[a]); a++ ){}; 
		if ( envp[0][a] == '=' ){ // found
			for ( char **e = envp+1; ( *envp=*e ); e++,envp++ ){};
		}
	}
	return(0);
}

