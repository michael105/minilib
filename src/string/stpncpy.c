//+doc copy src to dest, return a pointer to the last char +1 ( ending '0' )
// Please note stplcpy (terminology borrowed from freebsd), 
// which does the same,
// but doesn't pad dest with 0's.
//+def
char *stpncpy(char *dest, const char *src, int size){
	char *d = dest;
	char *e = (dest+size);
	while ( *src && ( d<e) ){
		*d=*src;
		d++;
		src++;
	}
	char *r = d;
	while ( d<e ){
			*d++= 0;
	}

	return(r);
}


