
//+ansi string.h
//+def
void* memcpy( void*d, const void *s, int n ){
#ifndef mini_OPTIMIZE
	for ( int a=0; a<n; a++ ){
		*(char*)(d+a)=*(char*)(s+a);
	}

	return(d);
#else
	if ( !n ) return(d);

	int e, a = 0;
	// needs sizeof macros
	for ( e=n>>3; a<e; a++ ){
		*(long*)(d+a)=*(long*)(s+a);
	}
	if ( a == n ) return(d);

	for ( e=n>>2; a<e; a++ ){
		*(int*)(d+a)=*(int*)(s+a);
	}
	if ( a == n ) return(d);

	for ( ; a<n; a++ ){
		*(char*)(d+a)=*(char*)(s+a);
	}

	return(d);
#endif
}

