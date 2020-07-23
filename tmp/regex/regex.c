#if 0
mini_start
mini_buf 256
mini_prints
mini_printf
mini_itodec


INCLUDESRC
return
#endif

#define extended


// simple regex engine.
// matches: * for every count of any char
// ? for 1 char
// backslash: escape *,?, and backslash itself.
//
// when extended is defined at compilation time, matches:
// \d - digit
// \D - nondigit
// \s - space
// \S - nonspace
//
// When the regex ist defined as C string,
// a backslash has to be defined as double backslash
// in the source code.
int match(char *text, char *re){
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
#ifdef extended
										if ( match( text,re) == 0 )
												return(0);
#endif
								}
								break;
						case '\\': // match escaped *,?,backslashes
								*re++;
#ifdef extended
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

#endif
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





int main(int argc, char**argv){
		prints("regex.\n");

		int ret;
#define M(text,regex)	ret=match(text,regex);	printf(text " - " regex " :%d\n",ret);
 M("Some text", "me*x")

		 M("text","t?xt")
		 M("text","??xt")
		 M("text","x?xt")
		 M("text","????")
		 M("text","???X")
		 M("text","???")
		 M("text","?????")
		 prints("\n");
 		 M("text","t*t")
 		 M("text","t*")
 		 M("text","t*x")
 		 M("text","t*xt")
 		 M("text","te*xt")
 		 M("text","*xt")
 		 M("text","*")

		 prints("\n");
		 prints("\n");

			M("to match","to?*")
			M("to match","to?ma*")
			M("to match","to?m*ch")
			M("to match","to?*")


		 prints("\n");
		 prints("\n");

			M("to *match","to?*")
			M("to *match","to \\*m*")
			M("to *match","to*match")
			M("to *match","to\\* match")
	
		 prints("\n");
		 prints("\n");

		 M("number 8 to match","number \\d to*")
		 M("number 8 to match","number\\d*")
		 M("number 8 to match","*\\d to*")

		 prints("\n");
		 prints("\n");

		 M("extended \t to match 78..","*ded*")
		 M("extended \t to match 78..","*ded\\s\\s\\sto*")
		 M("extended \t to match 78..","*ded*\\s\\d*")
		 M("extended \t to match 78..","*ded*\\s\\d?..")
		 M("extended \t to match 78..","*ded*\\s\\d.X")
		 M("extended \t to match 78..","*ded*")

		return(0);
}
