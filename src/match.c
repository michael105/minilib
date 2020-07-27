//+doc simple regex engine.
// matches: * for every count of any char
// ? for 1 char
// backslash: escape *,?, and backslash itself.
//
// returns: 1 on match, 0 on no match
//
// (memo) When the regex ist defined as C string,
// a backslash has to be defined as double backslash
// in the source code.
//+def
int match(const char *text, const char *re){
		while ( *text!=0 ){
				switch ( *re ){
						case '?':
								break;
						case '*':
								re++;
								if ( *re == 0)
										return(0); // no chars anymore. so a match
								for ( ; !match(text,re); text++ ){
										if ( !text )
												return(-1);
								}
								return(0);
								break;
						case '\\': // match escaped *,?,backslashes
								*re++;
						default:
								if ( *re==0 ) //partial match ( could be spared )
										return(-2);
								if ( *re!=*text ){
										return(-1);
								}
				}
				re++; text++;
		}

		if ( *re==0 ){
						return(0); //matched
		}
		
		return(-3); 
		// regex matched text, but the regex is longer than text
		// also the case for text==0
}


