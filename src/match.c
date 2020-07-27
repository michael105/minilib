//+doc simple regex engine.
// matches: * for every count of any char
// ? for 1 char
// backslash: escape *,?, and backslash itself.
//
// %[1]..%[9]: matches like a asterisk (*),
//  and calls the function, supplied as 3rd argument.
//  the number past the %, e.g. %1, is optional,
//  p_matched will be callen with this number
//  as first parameter.
//  When not supplied, p_matched will be callen with 
//  the paramater number set to 0.
//
//  The matching is 'nongreedy'.
//  Please beware, the 'match' can have a length of 0 as well.
//  It is possible to rewrite the string to match
//  from within the p_matched callback.
//  This will not have an effect onto the current matching,
//  even if text is e.g. deleted by writing 0's.
//  The matched positions are called in reverse order.
//  (The last matched % calls p_matched first)
//
// supply 0 for p_matched, when you do not need to extract matches
//
// returns: 1 on match, 0 on no match
// ( RE_MATCH / RE_NOMATCH )
//
// (memo) When the regex ist defined as C string,
// a backslash has to be defined as double backslash
// in the source code.
//+def match
int match(char *text, const char *re,void(*p_matched)(int number, char *pos,int len)){
		int n_match=0;
		char *matchpos = 0;

		while ( *text!=0 ){
				int neg = 0;
				switch ( *re ){
						case '?':
								break;
						case '%':
								if ( re[1]!=0 && re[1] >='0' && re[1] <= '9' ){
										n_match = re[1]-'0';
										*re++;
								}
								matchpos=text;
						case '*':
								re++;
								if ( *re == 0){
										if ( p_matched && matchpos ){
												while ( *text )	
														text++;
												p_matched(n_match, matchpos,text-matchpos);
										}
										return(RE_MATCH); // no chars anymore. so a match
								}

								while ( !match(text,re,p_matched) ){
										text++;
										if ( !*text )
												return(RE_NOMATCH);
								}

								if ( p_matched && matchpos )
										p_matched(n_match,matchpos,text-matchpos);

								return(RE_MATCH);

						case '!':
								neg = 1;
						case '\\': // match escaped *,?,backslashes, %
								*re++;
						default:
								if ( *re==0 ) //partial match ( could be spared )
										return(RE_NOMATCH);
								if ( neg ^ (*re!=*text) ){
										return(RE_NOMATCH);
								}
				}
				re++; text++;
		}

		if ( *re==0 || *re=='*' ){
						return(RE_MATCH); //matched
		}
		
		return(RE_NOMATCH); 
		// regex matched text, but the regex is longer than text
		// also the case for text==0
}


