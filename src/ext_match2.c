//+doc regex engine
// This is somewhere between a fully fledged expression machine,
// and a simplicistic solution.
// The engine matches from left to right,
// no backtracking is done. (Besides the matching %'s,
// which are callen right to left)
//
// It is a compromise between performance, size
// and capabilities.
// The logic is different of a "regular" regular expression
// machine, but has advantages (and disadvantages).
// I'd say, the main advantage is the easiness of adding callbacks,
// and defining your own matching/logic within these. 
// Performance might be better as well overall,
// but this depends also on the expressions.
//
// A few nonextensive benchmarks show,
// this engine is a bit faster than perl's regular expression machine,
// slower than gnu grep (around factor2), and has the same speed as sed.
// This might however vary with each usecase.
// In favor of codesize I'm not going to optimize ext_match,
// but there would be several possibilities, if you'd need a faster engine.
// (Albite I'd like to emphasise, sed (and ext_match), also perl, are quite fast.
// About 10 times faster than most expression engines.)
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
// ,: separator. e.g. %,1 matches like ?*1. 
//   ( without the commata, the '1' would be part of the % match)
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
// {nX}: counted match
//  Match n times X.
//  For X, all expressions are allowed.
//  If you need to match a number at the first char of 'X',
//  separate X by a commata. E.g. {5,0} matches 5 times '0'.
//
// (X): match the subexpression X. atm, no nesting of round () and {} brackets allowed
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
//  (The last matched % in the regex calls p_match first, 
//  the first % in the regex from the left will be callen last)
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
//  "match" like a '?' and call p_match_char
//  p_match_char has to return either RE_MATCH, RE_NOMATCH, RE_MATCHEND
//  or a number of the count of chars, which have been matched.
//
//  Therefore it is possible to e.g. rule your own
//  character classes, defined at runtime, 
//  or do further tricks like changing the matched chars,
//  match several chars, andsoon.
//  When returning RE_NOMATCH,
//  it is possible, the p_match and p_match_char callbacks are callen several times,
//  but with different pos or len parameters.
//
//  The matching works straight from left to right.
//  So, a "*&*" will call the callback & for the first char.
//  When returning RE_NOMATCH, the second char will be matched.
//  Until either RE_MATCH is returned from the callback,
//  or the last char has been matched.
//
//  Matching several characters is also posssible from within the callback,
//  the position within the text will be incremented by that number,
//  you return from the callback.
//
//  When returning RE_MATCHEND from the callback, 
//  the whole regular expression is aborted, and returns with matched;
//  no matter, if there are chars left in the expression.
//
//
//  The difference between % and & is the logic.
//  % matches nongreedy, and has to check therefore the right side of the star
//  for its matching.
//  Possibly this has to be repeated, when following chars do not match.
//
//  & is matched straight from left to right.
//  Whatever number you return, the textpointer will be incremented by that value.
//  However, a & isn't expanded on it's own. ( what a % is ).
//  e.g. "x%x" will match 'aa' in xaax, x&x will match the whole expression
//  only, when you return '2' from the callback.
//
//  Performancewise, matching with & is faster,
//  since the % has on its right side to be matched
//  with recursing calls of ext_match.
//
// When using closures for the callbacks, you will possibly have to
// enable an executable stack for the trampoline code
// of gcc. Here, gcc complains about that. 
// For setting this bit, have a look into the ldscripts in the folder
// with the same name.
//
// supply 0 for p_match_char, when you don't need it.
// This will treat & in the regex like ?, 
// and match a following digit (0..9) in the text,
// a following digit (0..9) in the regex is ignored.
// 
// -----
// In general, you have to somehow invert the logic of regular expressions
// when using ext_match.
// e.g. when matching the parameter 'runlevel=default' at the kernel's
// commandline, a working regular expression would be
// "runlevel=(\S*)". This could be written here as "*runlevel=%#".
// For matching e.g. numbers, you'd most possibly best of
// with writing your own & callback.
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
//  in km/s out of the solar system, btw.
//
//  (I'm not kidding here. Just don't do a regex with !* or !?..
//  And, please, do not ask me what is going to happen when the impossible
//  gets possibilized. I have to point at the according sentences of the BSD license;//  there is NO WARRANTY for CONSEQUENTIAL DAMAGE, LOSS OF PROFIT, etc pp.)
//
//  A "!+" will translate into nongreedy matching of any char, however;
//  "%!+" will match with % everything but the last char;
//  while "%+" matches with % only the first char.
//  !+ basically sets the greedyness of the left * or % higher.
//
// (work in progress here) please use ext_match
// return 0 for nomatch, the current textpos ( >0 ) for a match
// With the exception of an empty text, matched by e.g. "*".
// This will return 0, albite the regex formally matches, with 0 chars.
//
// (todo)
// bracket matching () and {} needs debugging. (test/extmatch2 for testing)
// Add a callback for backet matches, and add a matchlist
// (linked list, allocated with malloc_brk)
// Trouble: e.g. *:(*) doesn't match, albite it should
//  .. better. Now: # matches the end, after a bracket. Like it should
//   $ doesn't. But should as well.
//
//+def ext_match2
char* ext_match2(char *text, char *re, void(*p_match)(int number, char *pos,int len), int(*p_match_char)(int number, char *match_char), regex_match *st_match){
		int n_match=0;
		char *matchpos = 0;
		int neg = 0;
		printsl("ext_match2, text: ", text, " re: ", re );
		if ( st_match ) st_match->len=0;

		while ( *text!=0 ){
				int match_char = 0;
				neg = 0;
				if ( *re == '!' ){
						re++;
						neg=1;
				}
				int count = 0;
				if ( *re == '}' )
						re++;
				if ( *re == '{' ){
						while ( re++ && isdigit(*re) ){
								count += (count*10) + (*re-'0');
						}
				} else {
						count = 1;
				}
				if ( *re == ',' ) // separate e.g. %,1
						re++;
				char *pos = re;
				while ( count --> 0 ){
						re=pos;
						switch ( *re ){
								case '?':
										if ( neg )
												return(RE_NOMATCH); // !? breaks down to $
										break; // matches, but only if there's a char (not 0)
								case '[':
										for ( re++; *re && *re!=*text; re++ )
												if ( *re==']' )
														return(neg?text:RE_NOMATCH);
										while ( *re && *re != ']' )
												re++;
										if ( !*re )
												return( RE_ERROR );
										if ( neg )
												return( RE_NOMATCH );
										break;
								case '(':
										re++;
										char *bpos = re;
										char *mpos = text;
										while ( *re && *re!=')' )
												re++;
										if ( !*re )
												return(RE_ERROR);
										*re = ','; // end subregex at the closing bracket
										text=ext_match2(text,bpos,p_match,p_match_char,st_match);
										*re=')'; // needed for several count's: e.g. '*{3(a%1a)}*'
										if ( text==0 )
												return(RE_NOMATCH);
										// fill bracket matches here, from bpos to text
										prints("bracket match: ");
										write(1,mpos,text-mpos);
										printl();
										return(text); // MATCH

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

										if ( match_char ){ // match &
												// if ( *re== d ) match char classes: &d, &D, ..
												// match e.g. %d: several digits, &d: one digit.
												if ( p_match_char ){
														int m = p_match_char(n_match,text);
														if ( m==RE_NOMATCH ){
																if ( neg ) break;
																return( RE_NOMATCH );
														}
														if ( m==RE_MATCHEND ){
																	// fill  st_match here
																return(neg?RE_NOMATCH:text);
														}
														// m > 0 here. increment text 
														text=text+m;
														//break;
												}
												// fill  st_match here
												if ( neg ) return( RE_NOMATCH );
												break; // matched, also for p_match_char == 0
										}

										matchpos=text;
								case '+': // match one or more chars . not needed. no gain. (can be written as ?*)
										text++; 
										if ( !*text ) return(neg?text:RE_NOMATCH);//
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
												return(text); //rpl
												//return(neg?RE_NOMATCH:text); // no chars anymore. so a match
										}
										//if ( *re=='d' || *re=='D' || *re=='w' || *re=='W' ){ // match %d, and sort of
										// match nongreedy. (has more possibilities, e.g. match %d\D, or %d\d\D
										//}
										//switch ( *re ){

										while ( ext_match2(text,re,p_match,p_match_char,st_match) == RE_NOMATCH ){
												text++;
												if ( !*text ){
														//if ( (*re == '#' || *re == '$') && ( re[1]==0 ) )
														if ( (*re == '#' || *re == '$')  )
																goto __MATCHEND;
														return(RE_NOMATCH); //rpl
														return(neg?text:RE_NOMATCH);
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

										return(text); //rpl
										return(neg?RE_NOMATCH:text);

								case '\\': // match escaped *,?,backslashes, %
										re++;
										printsl("match \\, re: ",re, " text: ",text);
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
						text++;
				}
				re++; 		
		}

		// *text == 0 here.
		if ( ( *re=='#' ) || ( *re=='$') ){ // match end of text 
				//re++;
				return(text);
		}
	
		if ( *re==0 || ( *re=='*' && re[1]==0 ) ){ 
				// * at the end. doesnt match "**", or other pathological cases
						return(text); //matched
		}
	
		return(RE_NOMATCH); 
		// regex matched text, but the regex is longer than text
		// also the case for text==0
}


