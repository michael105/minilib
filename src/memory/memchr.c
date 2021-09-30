//+def
void* memchr(const void *s, int c, unsigned int n){
	unsigned char *p = (void*)s;
	for( const unsigned char* end=p+n; p<end; p++ ){
		if ( *p==c )
			return(p);
	}
	return(0);
}

