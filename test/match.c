#if 0
mini_start

mini_group_print
mini_ext_match

mini_buf 256
mini_printf
mini_itodec

INCLUDESRC

return
#endif



void mt( char* text, char *re ){
		prints("=== text: ",text,"  re: ",re,"\n");
		if (ext_match(text,re,0,0,0))
				printsl("Matched");
		else
				printsl("No match");
}


void matched(int num, char *pos, int len){
		printf("Match num: %%%d, len: %d\n--- ",num,len);
		write(1,pos,len);
		printsl(" ---");
}

void mt2( char* text, char *re ){
		prints("=== text: ",text,"  re: ",re,"\n");
		if (ext_match(text,re,matched,0,0))
				printsl(" Matched");
		else
				printsl(" No match");
}


void matched3(int num, char *pos, int len){
		printf("Match num: %%%d, len: %d\n--- ",num,len);
		write(1,pos,len);
		printsl(" ---");
}

int match_char(int num, char *c){
		printf("Match char : %c, num: %d\n",*c,num);
		if ( *c<'0' || *c > '9' ){
				printsl(" No match" );
				return( RE_NOMATCH );
		}
		printsl(" Match" );
		return( RE_MATCH );
}

void mt3( char* text, char *re ){
		regex_match stmatch;
		prints("=== text: ",text,"  re: ",re,"\n");
		if (ext_match(text,re,matched3,match_char,&stmatch))
				printsl(" Matched");
		else
				printsl(" No match");
		if ( stmatch.len ){
				prints("stmatch: ");
				write(1,stmatch.pos,stmatch.len);
				printl();
		}
}

int match_nonum(int num, char *c){
		printf("Match char : %c, num: %d\n",*c,num);
		if ( *c<'0' || *c > '9' ){
				if ( num == 0 ){
				printsl(" Match" );
				return( RE_MATCH );
			} else {
				printsl(" Match" );
				return( RE_MATCH );
			}
		}
		if ( num == 1 ){
				printsl(" Match" );
				return( RE_MATCH );
			}
	
		printsl(" No match" );
		return( RE_NOMATCH );
}

void mt4( char* text, char *re ){
		regex_match stmatch;
		prints("=== text: ",text,"  re: ",re,"\n");
		if (ext_match(text,re,matched3,match_nonum,&stmatch))
				printsl(" Matched");
		else
				printsl(" No match");
		if ( stmatch.len ){
				prints("stmatch: ");
				write(1,stmatch.pos,stmatch.len);
				printl();
		}
}

typedef struct str { int a; int b; } st;

st func(int c, int d ){
		st r;
		r.a=23;r.b=42;
		//return(r.a=c,r);
		return(r.a=c,r.b=d,r);
}


int main(int argc, char **argv){

		mt("text","t*t");
		mt("texttext2","t*xt2");
		mt("texttext2","t*");
		mt("texttext2","*x*x*");

		mt("texttext2text3text2text1","t*xt2*xt1");
		mt("texttext2text3text2text1","t*xt2*xt1");
		mt("texttext2text3text2text1","t*xt2*st3*text1");
		mt("texttext2text3text2text1","t*xt2*xt3*text1");

		mt("texttext2text3text2text1text3text1","t*xt2*xt3*text1");

		mt("texttext2text3text2text1text3text1","t*t?xt3*text1");

		printsl("---------------");

		mt2("text","t%1t");
		mt2("texttext2","t%1xt2");
		mt2("texttext2","t%1");
		mt2("texttext2","*x%1x*");
		mt2("texttext2","%1x*");
		mt2("texttext2","%1");

		mt2("text","t%t");
		mt2("texttext2","t%xt2");
		mt2("texttext2","t%");
		mt2("texttext2","*x%x*");
		mt2("texttext2","%x*");
		mt2("texttext2","%");
		mt2("TExttext2","%xt%");
		mt2("texttext2","%xt*");

		printsl("---------------");
		mt2("texttext2","%xt2*");
		mt2("texttext2","%xt!2*");

		printsl("---------------");
		printsl("---------------");

		mt2("texttext2","te%2x%3");

		printsl("---------------");

		mt3("texttext2","te%2x%3");
		mt3("texttext2","te%2x%$");

		printsl("---------------");

		mt4("texttext2","te%2x%3");
		mt4("texttext2","te%2x%$");

		mt4("n12n13x47t32...","*x%$*");


		mt4("n12n13x47t32...","*[tx]%$$1*");
		mt4("n12n13x47t32...","%[tx]%.*");
		mt4("n12n13x47t32...","%[tx]%$*");

		mt4("n12n13x47t32...","*%x*");

		mt4("n12n13x47t32...","*32...*x");



		st r = func(1,2);
		printf("a: %d, b: %d\n",r.a,r.b);

		st nst = {0,0};

		r = func(0,0);

		if ( r.a )
				printsl("Ja 1\n");


		mt4("col1 col2 col3","% % %");

		mt4("col1 col2 col3","*l%*%");

		mt4("col1 col2 col3","*%\\s%\\s%");
		mt4("col1 col2 col3","*%\\S%\\s%");

		mt4("col1 col2 col3","%\\s*");
		mt4("col1 col2 col3","%!1\\s*");

		mt4("col1 col2 col3","%![123]\\s*");
		mt4("col1 col2 col3","%\\scol![12]*");

		mt4("col1 col2  col3","%\\s!\\s*");
		mt4("col1 col2  col3","%!+");
		mt4("col1 col2  col3","%!+c*");
		mt4("col1 col2  col3","%!+*");
		mt4("col1 col2  col3","%!*");
		mt4("col1 col2  col3","%!?");
		mt4("col1 col2  col3","%!+");
		mt4("col1 col2  col3","%!\\W");
		mt4("col1 col2  col3","%!?");
		mt4("col1 col2  col3","%col!+");
		return(0);
}
