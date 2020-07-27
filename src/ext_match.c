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
// returns: 1 on match, 0 on no match
// ( RE_MATCH / RE_NOMATCH )
//
// (memo) When the regex ist defined as C string,
// a backslash has to be defined as double backslash
// in the source code. 
// ( so to define a backslashed backslash, 4 backslashes are needed..)
//+def
int ext_match(const char *text, const char *re){
		while ( *text!=0 ){
				switch ( *re ){
						case '?':
								break;
						case '*':
								re++;
								if ( *re == 0)
										return(RE_MATCH); // no chars anymore. so a match

								while ( !ext_match(text,re) ){
										text++;
										if ( !*text )
												return(RE_NOMATCH);
								}
								return(RE_MATCH);

						case '\\': // match escaped *,?,backslashes
								*re++;
								if ( *re == 'd' ){
										if ( *text>='0' && *text <= '9' )
												break;
										else
												return(RE_NOMATCH);
								}
								if ( *re == 'D' ){
										if ( *text>='0' && *text <= '9' )
												return(RE_NOMATCH);
										else
												break;
								}
								if ( *re == 'w' ){
										if ( (*text>=32 && *text <= 126 ) || ( *text>=160 ) )
												break;
										else
												return(RE_NOMATCH);
								}

								if ( *re == 'W' ){
										if ( (*text>=127 && *text <= 159 ) || ( *text<32 ) )
												break;
										else
												return(RE_NOMATCH);
								}


								if ( *re == 's' ){
										if ( isspace(*text) )
												break;
										else
												return(RE_NOMATCH);
								}
								if ( *re == 'S' ){
										if ( !isspace(*text) )
												break;
										else
												return(RE_NOMATCH);
								}

						default:
								if ( *re==0 ) //partial match ( could be spared )
										return(RE_NOMATCH);
								if ( *re!=*text ){
										return(RE_NOMATCH);
								}
				}
				re++; text++;
		}

		if ( *re==0 ){
						return(RE_MATCH); //matched
		}
		
		return(RE_NOMATCH); 
		// regex matched text, but the regex is longer than text
		// also the case for text==0
}


