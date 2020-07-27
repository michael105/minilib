//+doc regex engine
// little bit simpler version than ext_match.
// The engine matches from left to right,
// so no backtracking is done.
// It is a compromise between performance, size
// and capabilities.
//
// matches: 
// 
// * for every count of any char
// + for 1 or more chars
// ? for 1 char
//
// backslash: escape *,?,%,!,+ and backslash itself.
// ! : invert the matching of the next character or character class
//  
// [xyz]: character classes, here x,y or z 
//   the characters are matched literally, also \,*,?,+,..
//   it is not possible to match the closing bracket (])
//   within a character class
//
//
// % : matches like a '+', and fills in argument 3,
// the regex_match struct, when the pointer is non null.
// The matching is 'nongreedy'.
//
//
// returns: 1 on match, 0 on no match
// ( RE_MATCH / RE_NOMATCH )
//
// if the pointer (argument 3) st_match is nonnull,
// the supplied struct regex_match will be set to the first matching '%' location;
// if there is no match, regex_match.len will be set to 0.
// The struct is defined as: 
// typedef struct _regex_match { char* pos; int len; } regex_match;
//
//
// (memo) When the regex ist defined within C/cpp source code,
// a backslash has to be defined as double backslash.
//
// (note) - be careful when negating a following *, or ?.
//  somehow - it is logical, but seems to me I overshoot a bit,
//  and tapped into a logical paradox.
//  Negating EVERYTHING translates to true.
//  However, since truth is negated as,... well, there's a problem.
//
//  (I'm not kidding here. Just don't do a regex with !* or !?..)
//
//  A "!+" will translate into nongreedy matching of any char, however;
//  "%!+" will match with % everything but the last char;
//  while "%+" matches with % only the first char.
//  !+ basically sets the greedyness of the left * or % higher.
//
//+def match
int match(char *text, const char *re, regex_match *st_match){
		int n_match=0;
		char *matchpos = 0;
		int neg = 0;
		if ( st_match ) st_match->len=0;

		while ( *text!=0 ){
				int match_char = 0;
				neg = 0;
				if ( *re == '!' ){
						re++;
						neg=1;
				}
				switch ( *re ){
						case '?':
								if ( neg )
										return(RE_NOMATCH);
								break; // matches, but only if there's a char (not 0)
						case '[':
								for ( re++; *re && *re!=*text; re++ )
										if ( *re==']' )
												return(neg ^ RE_NOMATCH);
								while ( *re && *re != ']' )
										re++;
								if ( !*re )
										return( RE_ERROR );
								if ( neg )
										return( RE_NOMATCH );
								break;

						case '%':
								matchpos=text;
						case '+': // match one or more chars
										text++; 
										if ( !*text ) return(neg ^ RE_NOMATCH);//
						case '*': // match 0 or more chars
								re++;
								if ( *re == 0){ // match. end of regex.
										if ( matchpos && ( st_match ) ){
												while ( *text )	// find end of text
														text++;
												if ( st_match ){
														st_match->pos = matchpos;
														st_match->len = text-matchpos;
												}
										}
										return(neg ^ RE_MATCH); // no chars anymore. so a match
								}

								while ( !match(text,re,st_match) ){
										text++;
										if ( !*text )
												return(neg ^ RE_NOMATCH);
								}

								if ( matchpos ){
										if ( st_match ){
												st_match->pos = matchpos;
												st_match->len = text-matchpos;
										}
								}

								return(neg ^ RE_MATCH);

						case '\\': // match escaped *,?,backslashes, %
								re++;
						default:
								if ( *re==0 ) //partial match ( could be spared )
										return(RE_NOMATCH);
								if ( neg ^ (*re!=*text) ){
										return(RE_NOMATCH);
								}
				}
				re++; text++;
		}

		if ( *re==0 || ( *re=='*' && re[1]==0 ) ){ 
				// * at the end. doesnt match "**", or other pathological cases
						return(RE_MATCH); //matched
		}
		
		return(RE_NOMATCH); 
		// regex matched text, but the regex is longer than text
		// also the case for text==0
}


