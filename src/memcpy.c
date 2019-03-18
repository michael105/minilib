#ifndef memcpy_c
#define memcpy_c

//+ansi string.h
//+def
void *memcpy( void *d, const void *s, int n ){
		char *dp=d;
		const char *sp = s;
		int a;
		for ( a=0; a<n; a++ )
				dp[a] = sp[a];
		return(d);
}

#endif

