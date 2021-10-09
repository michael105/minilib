//+doc conversion
//+needs isspace
//+def
long int strtol(const char *c, const char **endp, int base){
		
		while(isspace(*c)){
				c++;
		};

		if ( !c ){
				goto strtol_err;
		}

		int sign = 0;
		if ( *c=='-' ){
				sign = 1;
				c++;
		}
		// base. pref 0x = hex, pref 0 = octal
		if ( base == 0 ){
				if ( *c=='0' ){
						c++;
						if ( *c== 'x' ){
								c++;
								base=16;
						} else {
								base=8;
						}
				} else {
						base=10;
				}
		}

		long ret = 0;

		while ( 1 ){
				if ( endp )
						*endp=c;

				int add = -1;
				if ( *c>='0' && *c<='9' )
						add = (*c-48);
				if ( *c>= 'A' && *c<= 'Z' )
						add = (*c-'A'+10);
				if ( *c>= 'a' && *c<= 'z' )
						add = (*c-'a'+10);

				if ( add > base || add == -1 )
						return( sign?-ret:ret );

				c++;
				ret *= base;
				ret += add;
				if ( ret < 0 ){ //overflow
#ifdef mini_errno
					errno=ERANGE;
#endif
					return( sign?LONG_MIN:LONG_MAX );
				}
		}


strtol_err:
#ifdef mini_errno
		errno=EINVAL;
#endif
		if ( endp ){
				*endp = 0;
		}
		return(0);
}

