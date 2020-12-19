//+header string.h
//+def
char* strstr(const char *big, const char *little){
		register char *s = (char*)big;
		register char *p = (char*)little;
		char *sp = s;

		if ( *little == 0 )
				return(s);

		do {
				if (*s==*p){
						sp = s;

						do {
						p++;s++;
						if ( *p == 0 )
								return( sp ); // match
						} while ( *s==*p );

						s=sp;
						p=(char*)little;
				}
				s++;
		} while ( *s != 0 ); // end of big reached

		return(0);
}
