//+doc copy src to dest, return a pointer to the last char +1 ( ending '0' )
// doesn't pad dest with 0, when size<src;
//+def
char *stplcpy(char *dest, const char *src, int size){
	char *d = dest;
	char *e = (dest+size);
	while ( *src && ( d<e) ){
		*d=*src;
		d++;
		src++;
	}
	*d= 0;

	return(d);
}


