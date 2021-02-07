
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


