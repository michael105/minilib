#ifndef mini_match_c
#define mini_match_c

//+doc text matching engine
//
// little bit simpler version than match_ext.
// Consciusly named 'text matching', since the inherent logic
// is quite different to a regular expression machine.
//
// The engine matches nongreedy straight from left to right,
// so backtracking is minimized.
// It is a compromise between performance, size
// and capabilities.
//
//
// matches: 
// 
// * for every count of any char (nongreedy(!))
// + for 1 or more chars
// % for 1 or more chars, and fills in arg 3 (text_match)
// ? for 1 char
// @ matches the beginning of the text or endofline (\n) 
//   -> beginning of a line
// # for space, endofline, \t, \n, \f, \r, \v  or end of text (0)
// $ match end of text
// backslash: escape *,?,%,!,+,#,$ and backslash itself.
// ! : invert the matching of the next character or character class
//  
// [xyz]: character classes, here x,y or z 
//   the characters are matched literally, also \,*,?,+,..
//   it is not possible to match the closing bracket (])
//   within a character class
//
//
// % : matches like a '+', and fills in argument 3,
// the text_match struct, when the pointer is non null.
// The matching is 'nongreedy'.
//
//
// returns: 1 on match, 0 on no match
// ( RE_MATCH / RE_NOMATCH )
//
// if the pointer (argument 3) st_match is nonnull,
// the supplied struct text_match will be set to the first matching '%' location;
// if there is no match, text_match.len will be set to 0.
//
// The struct is defined as: 
// typedef struct _text_match { char* pos; int len; } text_match;
//
// examples: 
// "*word*"  matches "words are true" or "true words are rare"
// "word*"   matches "words are true" and not "true words are rare"
// "word"    matches none of the above two texts (!)
// "*words%" extracts with % " are true" and " are rare"
//           into text_match
// 
// "Some\ntext\nwith\nlinebreaks\n\n"
// "*@%#*" matches with % "Some"
// "*@line%#*" matches % = "breaks"
// "*text\n%"  % = "with linebreaks\n\n"
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
//  (I'm not kidding here. Just don't do a regex with !* or !?.,
//  or you might experience the meaning of full featured. 
//  Maybe I should say, it's not allowed?)
//
//  A "!+" will translate into nongreedy matching of any char, however;
//  "%!+" will match with % everything but the last char;
//  while "%+" matches with % only the first char.
//  !+ basically sets the greedyness of the left * or % higher.
//
//+depends _match
//+def match
int match(char *text, const char *re, text_match *st_match){

	int r = 1;
	if ( ( *re == '*' && *(re+1)=='@' && ( r=2 ) ) ||
			 ( *re=='@' ) ){ // beginning of text or line, here of the text
		if ( _match( text, (re+r), st_match ) == RE_MATCH )
			return( RE_MATCH );
	}

	return( _match( text, re, st_match ) );
}

//+def
int _match(char *text, const char *re, text_match *st_match){
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
						case '#': // match end of text, or space chars; here a space
								if ( isspace( *text )){
										if ( neg ) return( RE_NOMATCH );
										break;
								}
								if ( neg ) break;
								return( RE_NOMATCH );
						case '@': // match beginning of text or endofline - here endofline
								if ( *text == '\n' ){
										if ( neg ) return( RE_NOMATCH );
										break;
								}
								if ( neg ) break;
								return( RE_NOMATCH );

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

								while ( !_match(text,re,st_match) ){
										text++;
										if ( !*text ){
												if ( (*re == '#' || *re == '$') && ( re[1]==0 ) )
														goto __MATCHEND2;
												return(neg ^ RE_NOMATCH);
										}
								}
__MATCHEND2:
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
		// *text == 0
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

#endif

