//+doc simple regex engine.
// matches: * for every count of any char
// ? for 1 char
// backslash: escape *,?,%,$,! and backslash itself.
// !: invert the matching of the next character
//  a '!' also escapes a following *,%,$,?,!
//  (not a backslash)
//  
//
// %[1]..%[9]: matches like a asterisk (*),
//  and calls the function, supplied as 3rd argument.
//  the number past the %, e.g. %1, is optional,
//  p_match will be callen with this number
//  as first parameter.
//  When not supplied, p_matched will be callen with 
//  the parameter number set to 0.
//
//  The matching is 'nongreedy'.
//  Please beware, the 'match' can have a length of 0 as well.
//  It is possible to rewrite the string to match
//  from within the p_matched callback.
//  This will not have an effect onto the current matching,
//  even if text is e.g. deleted by writing 0's.
//  The matched positions are called in reverse order.
//  (The last matched % in the regex calls p_match first)
//
// supply 0 for p_matched, when you do not need to extract matches.
// This will treat % in the regex like a *, 
// a following digit (0..9) in the regex is ignored.
//
// $[1] .. $[9]
//  call p_match_char
//  p_match_char has to return either RE_MATCH or RE_NOMATCH.
//  Therefore it is possible to rule your own
//  character classes, and so on.
//  When returning RE_NOMATCH,
//  it is possible, the p_match and p_match_char callbacks are callen several times,
//  but with different pos or len parameters.
//
// supply 0 for p_match_char, when you don't need it.
// This will treat $ in the regex like ?, match a following digit (0..9),
// a following digit (0..9) in the regex is ignored.
//
//
// returns: 1 on match, 0 on no match
// ( RE_MATCH / RE_NOMATCH )
//
//
// (memo) When the regex ist defined as C string,
// a backslash has to be defined as double backslash
// in the source code.
//+def match
int match(char *text, const char *re, void(*p_match)(int number, char *pos,int len), int(*p_match_char)(int number, char *match_char)){
		int n_match=0;
		char *matchpos = 0;

		while ( *text!=0 ){
				int neg = 0;
				int match_char = 0;
				switch ( *re ){
						case '?':
								break; // matches, but only if there's a char (not 0)

						case '$':
								match_char = 1;
						case '%':
								if ( re[1]!=0 && re[1] >='0' && re[1] <= '9' ){
										n_match = re[1]-'0';
										*re++;
								}

								if ( match_char ){
										if ( p_match_char && (p_match_char(n_match,text)==RE_NOMATCH) )
												return( RE_NOMATCH );
										break; // matched, also for p_match_char == 0
								}

								matchpos=text;
						case '*':
								re++;
								if ( *re == 0){
										if ( p_match && matchpos ){
												while ( *text )	// find end of text
														text++;
												p_match(n_match, matchpos,text-matchpos);
										}
										return(RE_MATCH); // no chars anymore. so a match
								}

								while ( !match(text,re,p_match,p_match_char) ){
										text++;
										if ( !*text )
												return(RE_NOMATCH);
								}

								if ( p_match  && matchpos )
										p_match(n_match,matchpos,text-matchpos);

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


