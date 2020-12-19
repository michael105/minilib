#ifndef strchr_c
#define strchr_c

//+header string.h

//+def
char *strchrnul(const char *s, int c){

		while ( *s != 0 ){
				if ( *s==c ){
						return((char*)s);
				}
				s++;
		}
		return((char*)s);
}

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


//+depends strchrnul
//+def
char *strrchr(const char *s, int c){
	char *ret = 0;
	char *tmp = (char*)s-1;
	while ( (tmp = strchrnul(tmp+1,c) ) && ( *tmp != 0 ) ){
			ret=tmp;
	}
	return(ret);
}

#endif
