//+def
char* strpbrk(const char* s, const char* charset){
	while ( *s ){
		if ( strchrnul( charset, s ) ){
			return( s );
		}
		s++;
	}
	return(0);
}
