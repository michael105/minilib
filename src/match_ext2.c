#ifndef mini_match_ext2_c
#define mini_match_ext2_c
//+doc text matching engine
//
// WORK IN PROGRESS, please use ext_match
// Atm, please nested brackets are featureful.
// nesting {} within () seems to work.
// Nesting round brackets within {} gives sometimes
// trouble, when wildcards are used within the brackets.
// I'm leaving this at it is for now. 
// Possibly I'm going to hardcode an error message for nested brackets,
// or nested brackets with wildcards.
//
// This is somewhere between a fully fledged expression machine,
// and a simplicistic solution.
// Consciusly named 'text matching', since the inherent logic
// is quite different to a regular expression machine;
// "natural expressions" might fit better for the name.
//
// The engine matches from left to right,
// backtracking is done as less as possible.
// Since the matching is nongreedy in general,
// many tries can be spared. Opposed to another route,
// where most patterns are per default greedy, and therfore
// not the first matching next char is seeked for, but the first
// solution while matching the most chars.
// (I do not want to make this a hard statement, and it 
// depends onto each pattern. But it is the way, the solution
// of the pattern is searched for, in most patterns.)
// This shows up in the logic of the patterns, which is more natural to me.
// Your mileage might vary.
//
//
// It is a compromise between performance, size
// and capabilities.
// The logic is different of a "regular" regular expression
// machine, but has advantages (and disadvantages).
// I'd say, the main advantage is the easiness of adding callbacks,
// and defining your own matching/logic within these. 
// Performance might be better as well overall,
// but this depends on the expressions and usecases as well.
//
// Yet I for myself have to get a grip of the possibilities of this engine.
// However, I have the feeling, the logic is much more natural.
// With regular regexes you always have to think kind of 'backwards',
// e.g., match ".*" -> match "." (any char) x times. 
// gets to a simple "*"
// or, to match all group and user id's of /etc/passwd,
// a regular expression would be: "(\d*):(\d*)"
// This is here: "*(\d*):(\d*)*"
// The content in the brackets looks the same,
// but it's matched quite different.
// The regular expression (the first) matches x times \d, for x>=0.
// In the second expressin, the ext_match expression,
// the first digit is matched, and then nongreedy any chars, until
// the first occurence of ':'. 
// It is another logic. Whether it suits you, you have to decide.
//
// The callbacks have shown up to be a mighty tool, while
// at the same time having a good performance. 
// 
//
// A few nonextensive benchmarks show,
// this engine is a bit faster than perl's regular expression machine,
// slower than gnu grep (around factor2), and has the same speed as sed.
// This might vary with each usecase, but the callbacks for extracting matches
// have some advantage, as well as the strict left to right and nongreedy parsing.
//
// In favor of codesize I'm not going to optimize ext_match,
// but there would be several possibilities, if you'd need a faster engine.
// (Albite I'd like to emphasise, sed (and ext_match), also perl, are quite fast.
// About 5 to 10 times faster than most expression engines.)
//
// matches: 
// 
// * for every count of any char
// + for 1 or more chars
// ? for 1 char
// # for space, end of text (\0), linebreak, tab ( \t \n \f \r \v )
// @ matches the beginning of the text or endofline (\n) 
// $ match end of text (\0) or linebreak
//
// backslash: escape *,?,%,@,$,!,+,#,& and backslash itself.
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
// \x - hexadecimal digit (0-9,a-f,A-F)
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
//  n can be a number, * or +. 
//  ('*' matches 0 or more, '+' 1 or more times)
//
// (X): match the subexpression X. atm, no nesting of round () and {} brackets allowed
//
// %[1]..%[9]: matches like a '+',
//  and calls the callback supplied as 3rd argument (when not null).
//  the number past the %, e.g. %1, is optional,
//  p_matched_cb will be callen with this number
//  as first parameter.
//  When not supplied, p_matched_cb will be callen with 
//  the parameter 'number' set to 0.
//
//  The matching is 'nongreedy'.
//  It is possible to rewrite the string to match
//  from within the p_matched_cb callback.
//  This will not have an effect onto the current matching,
//  even if text is e.g. deleted by writing 0's.
//
//  The matched positions are called in reverse order.
//
//  (The last matched % in the regex calls p_matched_cb first, 
//  the first % in the regex from the left will be callen last)
//  / The regex is first matched; when the regex has matched,
//  the %'s are filled/ the callbacks executed.
//  (x) bracketed patterns are matched the same way.
//
//  (Not like &, which callbacks are invoked, while matching)
//
// supply 0 for p_matched_cb, when you do not need to extract matches.
// This will treat % in the regex like a *, 
// a following digit (0..9) in the regex is ignored.
// if the 5th argument, a pointer to a text_match struct, 
// is supplied, it will be filled with the first match.
// (counting from left)
//
//
// &[1] .. &[9]
//  "match" like a '?' and call p_wildcard_cb
//  p_wildcard_cb has to return either RE_MATCH, RE_NOMATCH, RE_MATCHEND
//  or the number of the count of chars, which have been matched.
//
//  Therefore it is possible to e.g. rule your own
//  character classes, defined at runtime, 
//  or do further tricks like changing the matched chars,
//  match several chars, andsoon.
//  When returning RE_NOMATCH,
//  it is possible, the p_wildcard_cb callback is callen several times,
//  but with different pos or len parameters, since p_wildcard_cb is
//  invoked while matching.
//
//  The matching works straight from left to right.
//  So, a "*&*" will call the callback & for the first char.
//  When returning RE_NOMATCH, the second char will be tried to match.
//  Until either RE_MATCH is returned from the callback,
//  or the last char of the text has been tried to match.
//
//  Matching several characters is also posssible from within the callback,
//  the position within the text will be incremented by that number,
//  you return from the callback.
//
//  When returning RE_MATCHEND from the callback, 
//  the whole expression is aborted, and returns with matched;
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
// For setting this bit, please have a look into the ldscripts in the folder
// with the same name.
//
// supply 0 for p_wildcard_cb, when you don't need it.
// This will treat & in the regex like ?, 
// and match a following digit (0..9) in the text,
// a following digit (0..9) in the regex is ignored.
// 
// -----
// In general, you have to somehow invert the logic of regular expressions
// when using ext_match.
// Regular expressions could be regarded as "polish rpn notation",
// first the char to be matched, then the count.
// This expression machine could be described as "natural expression" machine.
// First you define the number, then the chars or expression to be matched.
// 
// Furthermore, *,% and + match as less as possible.
// You have to think about what needs to follow the wildcards.
//
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
// the supplied struct text_match will be set to the first matching '%' location;
// if there is no match, text_match.len will be set to 0.
// The struct is defined as: 
// typedef struct _text_match { char* pos; int len; } text_match;
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
//  gets possibilized. I have to point at the according sentences of the BSD license;
//  there is NO WARRANTY for CONSEQUENTIAL DAMAGE, LOSS OF PROFIT, etc pp.)
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
// Add a callback for bracket matches, and add a matchlist
// (linked list, allocated with malloc_brk)
// Trouble: e.g. *:(*) doesn't match, albite it should
//  .. better. Now: # matches the end, after a bracket. Like it should
//   $ doesn't. But should as well.
// change '+' to greedy matching of any char
// for {n,X} let n be * or + as well.
//  (this would be closer to regular regulars again.?.)
//
//
// note. About a tokenizer:
// matching quoted string is really easy with the callback structure:
//  just match with &. When a quote is matched, look forward to the next quote,
//  and return that many chars. Same time, the quoted string is matched.
//  That's so easy, it is hard to believe.
//  When using closures for that, it is same time easy to collect all tokens.
//
//  It is even easier. just a "*("*")*" is enough.
//
//  ->There is something needed for partial matching. Possibly spare the last *, and return,
//  as soon the pattern is at it's end (and not the text?)
//  Already works this way. 
//
//  Should start to define the language for the init scripts.
//  Or better, start thinking abut that, but follow my other obligations the next time.
//
//  Have to think thouroughly about what points would make such a language useful.
//  The reason to think about that is clear - performance squeezing, faster startup time.
//  And writing the startup scripts in C is. Well. little bit painful.
//  However, together with minilib, there is nearly no difference between having a C program compiled
//  and run, or working with scripts. To not have the overhead of linking the external libraries in,
//  is of quite some advance.
//  The only difference, the compiled binaries are "cached".
//  have just to sort something sensible out for the systematic.
//  Implement an own loader? possibly easy. Since the loading address is fixed.
//  This could possibly also be the solution for the yet unclear question of the line between parsing
//  arguments and calling the main function of the small core tools, andsoon.
//  
// ..yet I've to fiddle out the possibilities (and quirks) of this machine.
// seems, this expression language did overpower it's creator.
//
// Bugs (features): 
// matching e.g. *matches*@*doesn't match*
// potentiates the *@* to many possibilities.
// One for every linebreak following 'matches'.
//
//+depends _match_ext2
//+def match_ext2
int match_ext2(char *text, char *re, void(*p_matched_cb)(int number, char *pos,int len), int(*p_wildcard_cb)(int number, char *match_char),text_match *st_match){
//char* match_ext2(char *text, char *re, int(*p_wildcard_cb)(int number, char *pos), void(*p_matched_cb)(int number, char *pos,int len), void(*p_bracket_cb)(int number, char *pos, int len)){

		int r = 1;
		char *ret = 0;

		if ( ( *re == '*' && *(re+1)=='@' && ( r=2 ) ) ||
						( *re=='@' ) ){ // beginning of text or line, here of the text
				if ( _match_ext2( text, (re+r), p_matched_cb, p_wildcard_cb, st_match ) > (long)0 )
						return( RE_MATCH );
		}
		if ( (ret = _match_ext2( text, re, p_matched_cb, p_wildcard_cb, st_match )) > 0 )
				return( RE_MATCH );

		return ( (int)(long)ret ); // needs a double cast to prevent compiler warnings
		// returns RE_NOMATCH or RE_ERROR
}

//+doc internal implementation of match_ext
//+def _match_ext2
char* _match_ext2(char *text, char *re, void(*p_matched_cb)(int number, char *pos,int len), int(*p_wildcard_cb)(int number, char *match_char), text_match *st_match){
		int n_match=0;
		char *matchpos = 0;
		int neg = 0;
		char *rematch = (char*)RE_MATCH;
#define REMATCH text
		//printsl("match_ext2, text: ", text, " re: ", re );
		if ( st_match ) 
				st_match->len=0;

		char *matchstarpos = 0; // set up a loop for a star, instead of recursion.
		// have to do benchmarking, how much this saves.
		// use a goto, when matchstarpos != 0, and the expression doesn't match.
		// increment text/matchstarpos. 
		// on match, it can be returned as usual. (are recursives needed at all for stars??)

		while ( *text!=0 ){
				//printsl("text != 0");
				int match_char = 0;
				neg = 0;
				int count = 1;

				switch (*re){
						case '!':
						neg=1;
						case ',': // separate e.g. %,1
						re++;
				}

				if ( *re == ')' ){
						//printf("\ntext: %lx\n===\n",text);
						re++;
						if ( ( _match_ext2(text,re,p_matched_cb,p_wildcard_cb,st_match ) ) <=0 )
								return( RE_NOMATCH );
						return( text );
						// return position of the closing bracket
				}

				if ( *re == '}' ){
						writesl("  == closing }");
						return( text ); // match
				}

				if ( *re == '{' ){
						re++;
						char *ret = text;
						char *r2;
						int c = 0;

						switch ( *re ){
								case '+':
										re++;
										if ( (ret = _match_ext2(text,re,
																		p_matched_cb,p_wildcard_cb,st_match ) ) <=0 )
												return(RE_NOMATCH);
										c = -1;
										break;
								case '*':
										c = -1;
										re++;
										break;
								default:
										while ( isdigit(*re) ){
												c += (c*10) + (*re-'0');
												re++;
										}
						}

						r2 = ret;
						while ( c!=0  && ((r2=_match_ext2(ret,re,
														p_matched_cb,p_wildcard_cb,st_match ) ) >0 ) ){
								write(1,r2,10);
								write(1,"\n",1);
								write(1,re,4);
								ret=r2;
								c--;
								printf(" -- while, c: %d\n",c);
						}
						if ( c > 0 )
								return(RE_NOMATCH);
						//printf("c: %d\n",c);
						for ( ;*re != '}'; re++ )
								if ( !*re )
										return( RE_ERROR ); // bracket error
						re++;
						// match the right side of the bracket
						return(_match_ext2(ret,re,p_matched_cb,p_wildcard_cb,st_match ));
				} 

				char *pos = re;
				while ( count --> 0 ){
						re=pos;
						switch ( *re ){
								case '?':
										if ( neg )
												return(RE_NOMATCH); // !? breaks down to $
										break; // matches, but only if there's a char (not 0)
								case '@': // match beginning of text or endofline - here endofline
										// ( -> beginning of new line )
										if ( *text == '\n' ){
												if ( neg ) return( RE_NOMATCH );
												break;
										}
										if ( neg ) break;
										return( RE_NOMATCH );
								case '[':
										for ( re++; *re && *re!=*text; re++ )
												if ( *re==']' )
														return(neg?REMATCH:RE_NOMATCH);
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
										//printf("match bracket %lx\n",text);
										text=_match_ext2(text,bpos,p_matched_cb,p_wildcard_cb,st_match);

										if ( text<=(long)0 )
												return(RE_NOMATCH);

										// fill bracket matches here, from bpos to text
										printf("bracket match: %lx - %lx - rematch: %lx\n",mpos,text,rematch);
										write(1,mpos,text-mpos);
										writesl("\n==========");
										if ( ! count ){
												writesl("retc");
											return(text); // MATCH
										}
										break;

								case '#': // match end of text, space, linebreak, tab; 
										if ( isspace( *text )){
												if ( neg ) return( RE_NOMATCH );
												break;
										}
										if ( neg ) break;
										return( RE_NOMATCH );
								case '$': // match end of text, linebreak
										if ( *text=='\n'){
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
												if ( p_wildcard_cb ){
														int m = p_wildcard_cb(n_match,text);
														if ( m==RE_NOMATCH ){
																if ( neg ) break;
																return( RE_NOMATCH );
														}
														if ( m==RE_MATCHEND ){
																	// fill  st_match here
																return(neg?RE_NOMATCH:REMATCH);
														}
														// m > 0 here. increment text 
														text=text+m;
														//break;
												}
												// fill  st_match here
												if ( neg ) return( RE_NOMATCH );
												break; // matched, also for p_wildcard_cb == 0
										}

										matchpos=text;
								case '+': // match one or more chars . not needed. no gain. (can be written as ?*)
										text++; 
										if ( !*text ) return(neg?REMATCH:RE_NOMATCH);//
								case '*': // match 0 or more chars
										re++;
										if ( *re == 0){ // match. end of regex.
												if ( matchpos && ( p_matched_cb || st_match ) ){
														while ( *text )	// find end of text
																text++;
														if ( p_matched_cb )
																p_matched_cb(n_match, matchpos,text-matchpos);
														if ( st_match ){
																st_match->pos = matchpos;
																st_match->len = text-matchpos;
														}
												}
												if ( !count ){
														printf("starmatch, count: %d rematch: %lx\n",count,rematch);
														return(REMATCH); //rpl
												}
												else break;
												//return(neg?RE_NOMATCH:text); // no chars anymore. so a match
										}
										//printf("starmatch out. rematch: %lx\n",rematch);
										char *pos;
										while ( (rematch=_match_ext2(text,re,p_matched_cb,p_wildcard_cb,st_match)) == RE_NOMATCH ){
												text++;
												if ( !*text ){
														//if ( (*re == '#' || *re == '$') && ( re[1]==0 ) )
														if ( (*re == '#' || *re == '$')  )
																goto __MATCHEND;
														return(RE_NOMATCH); //rpl
												}
										}
__MATCHEND:
										//printf("matchend, rematch: %lx\n",rematch);
										if ( matchpos ){
												if ( p_matched_cb )
														p_matched_cb(n_match,matchpos,text-matchpos);
												if ( st_match ){
														st_match->pos = matchpos;
														st_match->len = text-matchpos;
												}
										}

										if ( !count )
												return(rematch); //rpl
										else break;
										return(neg?RE_NOMATCH:REMATCH);

								case '\\': // match escaped *,?,backslashes, %
										re++;
										//printsl("match \\, re: ",re);
#define _MATCH(a,condition) if ( *re == a ){\
		if ( neg ^ (condition) ) break;\
		else return(RE_NOMATCH);}

										_MATCH('n',*text=='\n'); // match 'escaped' escape sequence
										_MATCH('t',*text=='\t'); // match 'escaped' escape sequence

										_MATCH('d',isdigit(*text));
										_MATCH('D',!isdigit(*text));
										_MATCH('s',isspace(*text));
										_MATCH('S',!isspace(*text));
										_MATCH('w',(*text>=32 && *text <= 126 ) || ( *text>=160 ) );
										_MATCH('W',(*text<32 ) || (( *text > 126 ) && ( *text<160 )) );
										_MATCH('x',isdigit(*text) ||
														('a'<=*text && *text<='f') ||
														('A'<=*text && *text<='F') );
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
		//printsl("loop out");
		//printf("rematch: %lx\n",rematch);

		// *text == 0 here.
		if ( *re == ',' )
				re++;
		if ( ( *re=='#' ) || ( *re=='$') ){ // match end of text 
				//re++;
				printsl("re_match end");
				return(REMATCH);
		}
	
		if ( *re==0 || ( *re=='*' && re[1]==0 ) ){ 
				// * at the end. doesnt match "**", or other pathological cases
						return(REMATCH); //matched
						// if ! count has to match here as well. :/
		}
	
		return(RE_NOMATCH); 
		// regex matched text, but the regex is longer than text
		// also the case for text==0
}

#endif
