
//+header string.h
//+depends malloc stplcpy strlen
//+def
char *strndup(const char *source, int maxlen){
	int l = strlen(source);
	if ( l > maxlen )
		l=maxlen;
	char *d = malloc(l+1);
	if ( !d ) return(0);
	stplcpy(d,source,l+1);
	return(d);
}




