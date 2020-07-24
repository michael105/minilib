//+doc simple regex engine.
// matches: * for every count of any char
// ? for 1 char
// backslash: escape *,?, and backslash itself.
// \d - digit
// \D - nondigit
// \s - space
// \S - nonspace
// \w - word character ( defined as ascii 32-126,160-255 )
// \W - nonword character ( defined as ascii 0-31,127-159 )
//
// (memo) When the regex ist defined as C string,
// a backslash has to be defined as double backslash
// in the source code.
//+def
int ext_match(const char *text, const char *re){
		while ( *text!=0 ){
				switch ( *re ){
						case '?':
								break;
						case '*':
								re++;
								if ( *re == 0)
										return(0); // no chars anymore. so a match
								for ( ; *text != *re; text++ ){
										if ( *text==0 )
												return(-2);
										if ( match( text,re) == 0 )
												return(0);
								}
								break;
						case '\\': // match escaped *,?,backslashes
								*re++;
								if ( *re == 'd' ){
										if ( *text>='0' && *text <= '9' )
												break;
										else
												return(-1);
								}
								if ( *re == 'D' ){
										if ( *text>='0' && *text <= '9' )
												return(-1);
										else
												break;
								}
								if ( *re == 'w' ){
										if ( (*text>=32 && *text <= 126 ) || ( *text>=160 ) )
												break;
										else
												return(-1);
								}

								if ( *re == 'W' ){
										if ( (*text>=127 && *text <= 159 ) || ( *text<32 ) )
												break;
										else
												return(-1);
								}


								if ( *re == 's' ){
										if ( isspace(*text) )
												break;
										else
												return(-1);
								}
								if ( *re == 'S' ){
										if ( !isspace(*text) )
												break;
										else
												return(-1);
								}

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


