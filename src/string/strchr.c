
//+header string.h

//+depends strchrnul
//+def
char *strchr(const char *s, int c){
		
		char *ret = strchrnul(s,c);

		if ( c==0 )
				return(ret);

		if ( *ret==0 )
				return(0);

		return(ret);
}

