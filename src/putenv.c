//+doc put a string into the environmental vars
// the supplied string's pointer is put into the environmental array of pointers.
// Subsequent changes of the string therefore will change the environment,
// and the supplied string may not be deallocated.
// Returns: 
// - 0 on success, 
// - EINVAL: string was 0, didn't contain a '=', some other error
// - ENOMEM: no memory for allocating the pointer
//+depends environ getenv strncmp ret_errno
//+def
int putenv( char *string ){

	char **envp;
	int   pos=0;

	for ( ; string[pos]!=0 && string[pos] != '='; pos ++ );

	if ( ! pos || ! string[pos] )
		ret_errno(EINVAL); // error. 

	for ( envp=environ; *envp; envp++ ) {
		if ( strncmp((char*)*envp, (char*)string, pos) == 0 ) {
			*envp=string;
			return(0);
		}
	}

	*envp=string;
	envp++;
	*envp=0;
	
	return(0);
}




