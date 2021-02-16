#if 0
mini_group_write

mini_prints

mini_start
mini_strcmp

INCLUDESRC
shrinkelf

return
#endif


enum shortopts { 
	opt_A=01,opt_B=02,opt_C=04,opt_D=010,opt_E=020,opt_F=040,opt_G=0100,opt_H=0200,
	opt_I=0400,opt_J=01000,opt_K=02000,opt_L=04000,opt_M=010000,opt_N=020000,
	opt_O=040000,opt_P=0100000,opt_Q=0200000,opt_R=0400000,opt_S=01000000,
	opt_T=02000000,opt_U=04000000,opt_V=010000000,opt_W=020000000,opt_X=040000000,
	opt_Y=0100000000,opt_Z=0200000000,opt_a=0400000000,opt_b=01000000000,
	opt_c=02000000000,opt_d=04000000000,opt_e=010000000000,opt_f=020000000000,
	opt_g=040000000000,opt_h=0100000000000,opt_i=0200000000000,opt_j=0400000000000,
	opt_k=01000000000000,opt_l=02000000000000,opt_m=04000000000000,
	opt_n=010000000000000,opt_o=020000000000000,opt_p=040000000000000,
	opt_q=0100000000000000,opt_r=0200000000000000,opt_s=0400000000000000,
	opt_t=01000000000000000,opt_u=02000000000000000,opt_v=04000000000000000,
	opt_w=010000000000000000,opt_x=020000000000000000,opt_y=040000000000000000,
	opt_z=0100000000000000000 };

// better let the praeprocessor do the work, than at runtime..
#define _LIT_A 'A'
#define _LIT_B 'B'
#define _LIT_C 'C'
#define _LIT_D 'D'
#define _LIT_E 'E'
#define _LIT_F 'F'
#define _LIT_G 'G'
#define _LIT_H 'H'
#define _LIT_I 'I'
#define _LIT_J 'J'
#define _LIT_K 'K'
#define _LIT_L 'L'
#define _LIT_M 'M'
#define _LIT_N 'N'
#define _LIT_O 'O'
#define _LIT_P 'P'
#define _LIT_Q 'Q'
#define _LIT_R 'R'
#define _LIT_S 'S'
#define _LIT_T 'T'
#define _LIT_U 'U'
#define _LIT_V 'V'
#define _LIT_W 'W'
#define _LIT_X 'X'
#define _LIT_Y 'Y'
#define _LIT_Z 'Z'
#define _LIT_a 'a'
#define _LIT_b 'b'
#define _LIT_c 'c'
#define _LIT_d 'd'
#define _LIT_e 'e'
#define _LIT_f 'f'
#define _LIT_g 'g'
#define _LIT_h 'h'
#define _LIT_i 'i'
#define _LIT_j 'j'
#define _LIT_k 'k'
#define _LIT_l 'l'
#define _LIT_m 'm'
#define _LIT_n 'n'
#define _LIT_o 'o'
#define _LIT_p 'p'
#define _LIT_q 'q'
#define _LIT_r 'r'
#define _LIT_s 's'
#define _LIT_t 't'
#define _LIT_u 'u'
#define _LIT_v 'v'
#define _LIT_w 'w'
#define _LIT_x 'x'
#define _LIT_y 'y'
#define _LIT_z 'z'

//  QUOTE(x) gets 'x'
#define QUOTE(a) _LIT_##a

#define OPT_A 01
#define OPT_B 02
#define OPT_C 04
#define OPT_D 010
#define OPT_E 020
#define OPT_F 040
#define OPT_G 0100
#define OPT_H 0200
#define OPT_I 0400
#define OPT_J 01000
#define OPT_K 02000
#define OPT_L 04000
#define OPT_M 010000
#define OPT_N 020000
#define OPT_O 040000
#define OPT_P 0100000
#define OPT_Q 0200000
#define OPT_R 0400000
#define OPT_S 01000000
#define OPT_T 02000000
#define OPT_U 04000000
#define OPT_V 010000000
#define OPT_W 020000000
#define OPT_X 040000000
#define OPT_Y 0100000000
#define OPT_Z 0200000000
#define OPT_a 0400000000
#define OPT_b 01000000000
#define OPT_c 02000000000
#define OPT_d 04000000000
#define OPT_e 010000000000
#define OPT_f 020000000000
#define OPT_g 040000000000
#define OPT_h 0100000000000
#define OPT_i 0200000000000
#define OPT_j 0400000000000
#define OPT_k 01000000000000
#define OPT_l 02000000000000
#define OPT_m 04000000000000
#define OPT_n 010000000000000
#define OPT_o 020000000000000
#define OPT_p 040000000000000
#define OPT_q 0100000000000000
#define OPT_r 0200000000000000
#define OPT_s 0400000000000000
#define OPT_t 01000000000000000
#define OPT_u 02000000000000000
#define OPT_v 04000000000000000
#define OPT_w 010000000000000000
#define OPT_x 020000000000000000
#define OPT_y 040000000000000000
#define OPT_z 0100000000000000000



void _OPT_option_desc( const char* option, const char* desc, int len ){
		char buf[8] = "   - : ";
		buf [4] = *option;
		write(STDERR_FILENO, buf, 7);
		write( STDERR_FILENO, desc, len );
		write(STDERR_FILENO, "\n", 1 );
}

void _OPT_longoption_desc( const char* option, int optionlen, int maxoptionlen, 
				const char* desc, int len ){

		write( STDERR_FILENO, "  --",4);
		write(STDERR_FILENO, option, optionlen );
		write(STDERR_FILENO, ": ", 2 );
		maxoptionlen-=optionlen;
		while ( maxoptionlen-->0 )
				write(STDERR_FILENO, " ", 1 );
		write( STDERR_FILENO, desc, len );
		write(STDERR_FILENO, "\n", 1 );
}

void missing(){
		write(STDERR_FILENO, "Error: missing argument for: -",31);
}

void missingarg(const char* flag){
		missing();
		write(STDERR_FILENO, flag, 1 );
		write(STDERR_FILENO, "\n\n",2 );
}

void missinglongarg(const char* option, int len){
		missing();
		write(STDERR_FILENO, option, len );
		write(STDERR_FILENO, "\n\n",2 );
}


int main(int argc, char **argv){

	long opts = 0;

	// define to something other for parsing docu
#ifndef OPT

#define printusage {getlen=1;showusage=2;goto SHOWUSAGE;}

#define GETLEN if (!getlen)
#define GETLENELSE(opt) else { if ( maxlen<sizeof(opt) ) maxlen=sizeof(opt); }


#define checkopt(s,flag) {if(!s){missingarg(#flag); printusage;};}
#define checklongopt(s,option) {if(!s){missinglongarg(option,sizeof(option));printusage;};}



#define OPT_USAGE(flag,desc,usage,endusage) GETLEN\
	{ if ( !showusage&& (QUOTE(flag) == *c) && (showusage = 2)){ printusage; } \
		if ( (showusage==4) || (showusage==2) ){ \
			ewritesl(usage); _OPT_option_desc(#flag,desc,sizeof(desc)); }\
	else if ( showusage == 1 ){ ewritesl(endusage); exit(1);};}

#define USAGEEND(msg) GETLEN { if ( showusage==1 ){ ewrites(msg); };}

#define OPT_HELP(flag,desc,in,out) GETLEN\
	{ if ( showusage==2 || showusage==4 ){ _OPT_option_desc(#flag,desc,sizeof(desc)); } else \
	if ( QUOTE(flag) == *c && (showusage==0) ) { ewrites(in); getlen=1;showusage=4;goto SHOWUSAGE;} else\
	if ( showusage==3 ){ ewrites(out); showusage=1;goto SHOWUSAGE; };}



#define OPT(flag,desc,code) GETLEN\
			{ if ( QUOTE(flag) == *c ){ opts |= OPT_##flag; code; continue; } \
	else if ( showusage ){ _OPT_option_desc(#flag,desc,sizeof(desc)); };}

#define OPT_STR(flag,desc,code) GETLEN\
					{ if ( showusage ){ _OPT_option_desc(#flag,desc,sizeof(desc)); } else\
	if ( QUOTE(flag) == *c ){ opts |= OPT_##flag; *argv++; checkopt(*argv,flag);char *opt_str=*argv; code; break; };}


#define LONGOPT( opt,desc,code ) GETLEN\
							{if ( (*c=='-')  && ( strcmp((c+1), opt ) == 0 )){ code; break; } \
	else if ( showusage ){ _OPT_longoption_desc(opt,sizeof(opt),maxlen,desc,sizeof(desc)); };}\
	GETLENELSE(opt)

#define LONGOPT_STR( opt,desc,code ) GETLEN\
		{if ( showusage ){\
			_OPT_longoption_desc(opt,sizeof(opt),maxlen,desc,sizeof(desc)); } else\
			if ( (*c=='-')  && ( strcmp((c+1), opt ) == 0 )){ \
							*argv++; checklongopt(*argv,opt);char *opt_s=*argv; code; break;};}\
	GETLENELSE(opt)


#endif



	int showusage = 0;
	int getlen = 0;
	int maxlen = 0; // the max length of a long arg for padding
	for ( *argv++; *argv && argv[0][0]=='-'; *argv++ ){
			for ( const char *c = argv[0]+1; *c != 0; c++ ){
SHOWUSAGE:

					OPT_USAGE(h,"show usage","Usage: opt [-r] [-h] ..", "\n(C) 2021 misc\n\n");
					OPT_HELP(H,"Show extended help","opt - parse options.\nA Test..\n\n","\nSo here might go the 'manual'.\n\n");
					OPT(r,"reverse order",);
					OPT_STR(s,"a string",printsl(opt_str));
					LONGOPT( "long", "long option", printsl("long opt") );

					LONGOPT_STR( "string", "description", printsl( "Longxx option: ", opt_s ););

					//USAGEEND("\n(C) 2021 misc\n\n");
					
					if (getlen){
							getlen=0;
							goto SHOWUSAGE;
					}
					if ( showusage ){
							showusage--;
							goto SHOWUSAGE;
					}
					eprints("Unknown Option: ",*argv,"\n\n");
					getlen=1;
					showusage = 2;
					goto SHOWUSAGE;
			} 
	}

	writesl("Parsing arguments ok.");

		return(0);
}

