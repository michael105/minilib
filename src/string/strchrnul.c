
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


