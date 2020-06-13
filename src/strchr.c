#ifndef strchr_c
#define strchr_c

//+header string.h

//+def
const char *strchrnul(const char *s, int c){

		while ( *s != 0 ){
				if ( *s==c ){
						return(s);
				}
				s++;
		}
		return(s);
}

//+depends strchrnul
//+def
const char *strchr(const char *s, int c){
		
		char *ret = strchrnul(s,c);

		if ( c==0 )
				return(ret);

		if ( *ret==0 )
				return(0);

		return(ret);
}


//+depends strchrnul
//+def
const char *strrchr(const char *s, int c){
	char *ret = 0;
	char *tmp = s-1;
	while ( (tmp = strchrnul(tmp+1,c) ) && ( *tmp != 0 ) ){
			ret=tmp;
	}
	return(ret);
}

#endif
