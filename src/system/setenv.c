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
//+depends environ getenv strncmp ret_errno malloc strcpy strlen stpcpy
//+def
int setenv( const char *name, const char *value, int overwrite ){

	char **envp;
	int len = strlen(name);

	for ( envp=environ; *envp; envp++ ) {
		if ( strncmp((char*)*envp, (char*)name, len) == 0 ) {
			if ( overwrite == 0 )
				return(0);

			*envp=malloc(len+1+strlen(value));
			if ( !*envp )
				ret_errno(ENOMEM);
			char *c = stpcpy(*envp,name);
			*c = '=';
			c++;
			strcpy(c,value);
			return(0);
		}
	}

	*envp=malloc(len+1+strlen(value));
	if ( !*envp )
		ret_errno(ENOMEM);
	char *c = stpcpy(*envp,name);
	*c = '=';
	c++;
	strcpy(c,value);

	envp++;
	*envp=0;

	return(0);
}




