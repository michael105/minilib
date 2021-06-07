//+doc copy src to dest, return a pointer to the last char +1 ( ending '0' )
//+def
char *stpcpy(char *dest, const char *src){
	char *d = dest;
	while ( *src ){
		*d=*src;
		d++;
		src++;
	}
	*d = 0;
	return(d);
}


