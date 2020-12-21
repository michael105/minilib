//+doc put a string into the environmental vars
// UNTESTED (!) TODO
// the supplied string's pointer is put into the environmental array of pointers.
// The supplied strings are copied into memory.
// If overwrite is zero, an existing environmental variable is not overritten.
// If overwrite is 1, the environmental variable is overwritten,
// but not(!) freed from memory.
// The supplied value is not checked for e.g. an '='
//
// Returns: 
// - 0 on success
// - EINVAL on error
//+depends environ getenv strcmp ret_errno malloc strcpy
//+def
int setenv( const char *name, const char *value, int overwrite ){

	char **envp;
		//ret_errno(EINVAL); // error. 

	for ( envp=environ; *envp; envp++ ) {
		if ( strcmp((char*)*envp, (char*)name) == 0 ) {
			*envp=malloc(strlen(value));
			if ( !*envp )
				ret_errno(ENOMEM);
			strcpy(*envp,value);
			return(0);
		}
	}

	*envp=malloc(strlen(value));
	if ( !*envp )
		ret_errno(ENOMEM);
	strcpy(*envp,value);

	envp++;
	*envp=0;
	
	return(0);
}




