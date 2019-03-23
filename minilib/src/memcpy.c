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


//+def
char *strcpy(char *dest, const char *src){
		int a;
		for ( a=0; src[a] != 0; a++)
				dest[a] = src[a];
		dest[a] = 0;
		return(dest);
}

//+depends memcpy
//+def
char *strncpy(char *dest, const char *src, int n){
		return( memcpy( dest, src, n ) );
}

#endif

