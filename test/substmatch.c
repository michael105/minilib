#if 0
mini_start

mini_group_print
mini_ext_match

mini_strcpy

mini_buf 256
mini_printf
mini_itodec

INCLUDESRC

return
#endif

void matched(int num, char *pos, int len){
		printf("Match num: %%%d, len: %d\n--- ",num,len);
		write(1,pos,len);
		printsl(" ---");
		if ( num==1 ){
				strcpy(pos,"replacement");
		}
}


int match_char(int num, char *c){

		int ret = RE_NOMATCH;
		// the last char of text gives a match,
		// so the whole expression is a match.
		// (with the given regexes)
		if ( c[1]==0 ) ret = RE_MATCH;

		if ( num==1 ){
				if ( *c=='r' ){
						*c='X';
				}
		}
		if ( num==2 ){
				*c='=';
		}

		if ( num==3 ){
				if ( *c=='r' ){
				for( char *p = c+1; *c; p++,c++ )
						*c=*p;
				}
		}

		return( ret );
}

void mt( char* text, char *re ){
		regex_match stmatch;
		prints("=== text: ",text,"  re: ",re,"\n");
		if (ext_match(text,re,matched,match_char,&stmatch))
				printsl(" Matched");
		else
				printsl(" No match");
		if ( stmatch.len ){
				prints("stmatch: ");
				write(1,stmatch.pos,stmatch.len);
				printl();
		}
}

int main(int argc, char **argv){
		printsl("---------------");

		mt("arg      ","% *");
		mt("      ","% *");
		mt("x=start vesa=0x300 runlevel=terminal mouse=13", "*runlevel=%#*");
		mt("x=start vesa=0x300 runlevel=terminal", "*runlevel=%#");
		mt("x=start vesa=0x300 runlevel=terminal mouse", "*runlevel=%#");
		mt("x=start vesa=0x300 runlevel=terminal mouse", "*runlevel=%#*");

		char *text="start vesa=0x300 runlevel=terminal mouse";
		printsl(text);
		mt( text,"*runlevel=%1#");
		printsl(text);

		mt( text,"*&1*");
		printsl(text);

		mt( text,"*&2*");
		printsl(text);

		char *t2="start vesa=0x303 runlevel=terminal mouse";
		printsl(t2);
		mt( t2,"*&3*");
		printsl(t2);

		return(0);
}
