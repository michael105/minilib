//+doc regex engine
// This is somewhere between a fully fledged expression machine,
// and a simplicistic solution.
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
// # for space or end of text (0)
// $ match end of text
//
// backslash: escape *,?,%,$,!,+,#,& and backslash itself.
// !: invert the matching of the next character or character class
//  
//
// predefined character classes:
// \d - digit
// \D - nondigit
// \s - space
// \S - nonspace
// \w - word character ( defined as ascii 32-126,160-255 )
// \W - nonword character ( defined as ascii 0-31,127-159 )
//
//
// [xyz]: character classes, here x,y or z 
//   the characters are matched literally, also \,*,?,+,..
//   it is not possible to match the closing bracket (])
//   within a character class
//
//
// %[1]..%[9]: matches like a '+',
//  and calls the callback supplied as 3rd argument (when not null).
//  the number past the %, e.g. %1, is optional,
//  p_match will be callen with this number
//  as first parameter.
//  When not supplied, p_matched will be callen with 
//  the parameter 'number' set to 0.
//
//  The matching is 'nongreedy'.
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
// if the 5th argument, a pointer to a regex_match struct, 
// is supplied, it will be filled with the first match.
// (counting from left)
//
//
// &[1] .. &[9]
//  call p_match_char
//  p_match_char has to return either RE_MATCH or RE_NOMATCH.
//  Therefore it is possible to e.g. rule your own
//  character classes, defined at runtime, 
//  or do further tricks like changing the matched char.
//  When returning RE_NOMATCH,
//  it is possible, the p_match and p_match_char callbacks are callen several times,
//  but with different pos or len parameters.
//
// supply 0 for p_match_char, when you don't need it.
// This will treat & in the regex like ?, 
// and match a following digit (0..9) in the text,
// a following digit (0..9) in the regex is ignored.
// 
//
// returns: 1 on match, 0 on no match
// ( RE_MATCH / RE_NOMATCH )
//
// if the pointer (argument 5) st_match is nonnull,
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
//  tragically hit my own foot, and stumbled into a logical paradox.
//
//  Negating EVERYTHING translates to true.
//  However, since truth is negated as well, there's a problem,
//  cause it's now 'false', but 'false' is true. This is very close
//  to proving 42 is the answer. What is the escape velocity
//  in km/s out of the solar system, btw..
//
//  (I'm not kidding here. Just don't do a regex with !* or !?..
//  And, please, do not ask me what is going to happen when the impossible
//  gets possibilized. I have to point at the according sentences of the BSD license;
//  there is NO WARRANTY for CONSEQUENTIAL DAMAGE, LOSS OF PROFIT, etc p..)
//
//  A "!+" will translate into nongreedy matching of any char, however;
//  "%!+" will match with % everything but the last char;
//  while "%+" matches with % only the first char.
//  !+ basically sets the greedyness of the left * or % higher.
//
//+def ext_match
int ext_match(char *text, const char *re, void(*p_match)(int number, char *pos,int len), int(*p_match_char)(int number, char *match_char), regex_match *st_match){
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
						case '#': // match end of text, or a space; here a space
								if ( isspace( *text )){
										if ( neg ) return( RE_NOMATCH );
										break;
								}
								if ( neg ) break;
								return( RE_NOMATCH );

						case '&':
								match_char = 1;
						case '%':
								if ( re[1]!=0 && re[1] >='0' && re[1] <= '9' ){
										n_match = re[1]-'0';
										*re++;
								}

								if ( match_char ){
										if ( p_match_char && (p_match_char(n_match,text)==RE_NOMATCH) ){
												if ( neg ) break;
												return( RE_NOMATCH );
										}
										if ( neg ) return( RE_NOMATCH );
										break; // matched, also for p_match_char == 0
								}

								matchpos=text;
						case '+': // match one or more chars
										text++; 
										if ( !*text ) return(neg ^ RE_NOMATCH);//
						case '*': // match 0 or more chars
								re++;
								if ( *re == 0){ // match. end of regex.
										if ( matchpos && ( p_match || st_match ) ){
												while ( *text )	// find end of text
														text++;
												if ( p_match )
														p_match(n_match, matchpos,text-matchpos);
												if ( st_match ){
														st_match->pos = matchpos;
														st_match->len = text-matchpos;
												}
										}
										return(neg ^ RE_MATCH); // no chars anymore. so a match
								}

								while ( !ext_match(text,re,p_match,p_match_char,st_match) ){
										text++;
										if ( !*text ){
												if ( (*re == '#' || *re == '$') && ( re[1]==0 ) )
														goto __MATCHEND;
												return(neg ^ RE_NOMATCH);
										}
								}
__MATCHEND:
								if ( matchpos ){
										if ( p_match )
												p_match(n_match,matchpos,text-matchpos);
										if ( st_match ){
												st_match->pos = matchpos;
												st_match->len = text-matchpos;
										}
								}

								return(neg ^ RE_MATCH);

						case '\\': // match escaped *,?,backslashes, %
								re++;
#define _MATCH(a,condition) if ( *re == a ){\
		if ( neg ^ condition ) break;\
		else return(RE_NOMATCH);}

								_MATCH('d',isdigit(*text));
								_MATCH('D',!isdigit(*text));
								_MATCH('s',isspace(*text));
								_MATCH('S',!isspace(*text));
								_MATCH('w',(*text>=32 && *text <= 126 ) || ( *text>=160 ) );
								_MATCH('W',(*text<32 ) || (( *text > 126 ) && ( *text<160 )) );
						default:
								if ( *re==0 ) //partial match ( could be spared )
										return(RE_NOMATCH);
								if ( neg ^ (*re!=*text) ){
										return(RE_NOMATCH);
								}
				}
				re++; text++;
		}

		// *text == 0 here.
		if ( ( *re=='#' ) || ( *re=='$') ){ // match end of text 
				re++;
		}
	
		if ( *re==0 || ( *re=='*' && re[1]==0 ) ){ 
				// * at the end. doesnt match "**", or other pathological cases
						return(RE_MATCH); //matched
		}
	
		return(RE_NOMATCH); 
		// regex matched text, but the regex is longer than text
		// also the case for text==0
}


