
//+ansi string.h
//+def
void* memcpy( void*d, const void *s, int n ){
#ifndef mini_OPTIMIZE
	char *dp=d;
	const char *sp = s;
	int a;
	for ( a=0; a<n; a++ )
		dp[a] = sp[a];
	return(d);
#else
	if ( !n ) return(d);

	int e, a = 0;
	// needs sizeof macros
	long int *ld = d; // dont know. needs testing
	const long int *ls = s;
	for ( e=n>>3; a<e; a++ ){
		ld[a]=ls[a];
	}
	if ( e<<3 == n ) return(d);

	int *i = d;
	const int *is = s;
	for ( e=n>>2; a<e; a++ ){
		i[a]=is[a];
	}
	if ( e<<2 == n ) return(d);

	char *c = d;
	const char *cs = s;

	for ( ; a<n; a++ ){
		c[a]=cs[a];
	}

	return(d);
#endif
}

