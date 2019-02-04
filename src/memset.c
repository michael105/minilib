void *memset( void *s, int c, int n){
		int a;
		char *sp = s;
		for ( a=0; a<n; a++)
				sp[a] = (char)c;
		return(s);
}
