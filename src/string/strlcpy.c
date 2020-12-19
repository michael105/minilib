//+doc copy max n chars from src to dest, 
// when src is longer than dest, 
// end dest[n-1] with '\0'.
//+def
char *strlcpy(char *dest, const char *src, int n){
		int a = -1;
		do {
				a++;
				if ( a>=(n-1) ){
						dest[n-1] = 0;
						return(dest);
				}
				dest[a] = src[a];
		} while ( src[a] != 0 ); 

		return(dest);
}


