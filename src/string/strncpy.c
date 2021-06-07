//+doc copy max n chars from src to dest, 
// write 0's up to src[n] when len of dest < n
// Please note strlcpy (borrowed from freebsd), 
// which does the same,
// but doesn't pad dest with 0's.
//+def
char *strncpy(char *dest, const char *src, int n){
		int a;
		for ( a=0; src[a] != 0; a++){
				if ( a>=n )
						return(dest);
				dest[a] = src[a];
		}
		for (;a<n;a++)
				dest[a] = 0;
		return(dest);
}


