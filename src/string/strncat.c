//+def
char* strncat( char* dst, const char* src, unsigned int n){
	if ( !n )
		return( dst );

	char *d = dst;
	while ( *d ) // find end
		d++;
	while( n && ( *d=*src) ){
		n--;
		d++;src++;
	}
	*d = 0;

	return(dst);
}



