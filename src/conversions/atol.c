//+ansi stdlib.h
//+def
long atol(const char *c){
		long ret = 0;
		int sign = 0;

		if ( *c == '-' ){
				sign=1;
				c++;
		}

		while( (*c>='0') && (*c<='9') ){
				ret*=10;
				ret=ret+(*c-48);
				c++;
		}
		if ( sign )
			return(-ret);
		return(ret);
}
	
	
