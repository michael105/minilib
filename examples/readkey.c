#ifdef MLIB
#include "minilibcompiled.h"
#else

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/select.h>
#include <sys/ioctl.h>
#include <sys/termios.h>

#endif

#define TTY struct termio

/* Add definitions to make termio look like termios.
 * But ifdef it, since there are some implementations
 * that try to do this for us in a fake <termio.h>.
 */
#if 0
#ifndef TCSANOW
#define TCSANOW TIOCSETA
#endif
#ifndef TCSADRAIN
#define TCSADRAIN TCSETAW
#endif
#ifndef TCSAFLUSH
#define TCSAFLUSH TCSETAF
#endif
#ifndef tcsetattr
#define tcsetattr(fd, cmd, arg) ioctl(fd, cmd, arg)
#endif
#ifndef tcgetattr
#define tcgetattr(fd, arg) ioctl(fd, TIOCGETA, arg)
#endif
#endif



#ifndef NULL
#define NULL 0
#endif

char *modifiers[] = { "CTRL", "ALT", "", "SHIFT" };
char *keys[] = {"", "?", "F%u", "ESC", "INS", 
		"POS1", "END", "PGUP", "PGDOWN", 
		"RET", "DEL", "BACKSPACE", "TAB", 
		"UP", "DOWN", "LEFT", "RIGHT" };

enum MODIFIERS { CTRL=1, ALT=2, SHIFT=4 }; 
enum KEYS { NOKEY, UNKNOWN, FKEY, ESC, INS, POS1, END, PGUP, PGDOWN, RET, DEL, BACKSPACE, TAB, UP, DOWN, LEFT, RIGHT };


int pmod = 0;
char keybuf[16];
int keycount = 0;
//Args
char debug=0;
char ret_modifier=0;
char print_modifier=0;
char only_key=0;
char repeat=0;

int key_output(int pmod,int pkey, int f,char*pstring){
		int i=0,ret=0;
		/*if ( debug )
				printf("pmod: %d, pkey: %d, f: %d\n",pmod,pkey,f);*/
		if ( pkey == UNKNOWN ){
				fputs("Unknown keycode: ", stderr);
				for (i=0;i<keycount;i++){
						fprintf(stderr,"%u ",keybuf[i]);
				}
				fputs("",stderr);
				return(253);
		}
		if ( only_key== 0 ){
				for ( i=1; i<5; i<<=1 ){
						if ( i & pmod ){
								fprintfs( stdout, "%s+", modifiers[i-1] );
						}
				}
		}
		if ( f ){
				printf(keys[FKEY], f );
		} else {
				if ( (pkey > 0) && (pkey < 17) ){
						print(keys[pkey]);
				} else {
						if ( pkey ){
								printf("%c",pkey);
						} else {
								if ( pstring!=0){
										prints(pstring);
								}
						}
				}
		}
		if(debug!=0){ // print the whole sequence
				printf("\n");
				if ( i )
						prints("Sequence: ");
				else
						prints("Key: ");
				for (i=0;i<keycount;i++){
						printf("%d ",keybuf[i]);
				}
				prints("\n");
		}
		if ( ret_modifier )
				ret=pmod;
		return(ret);
}


#define K(code,key) case code: pkey=key;break;
#define S(code,string) case code: pstring=string;break;
#define M(code,modifier) case code: pmod=pmod|modifier;break;
#define F(code,fkeynumber) case code: fkey=fkeynumber;break;

// Read a key, wait for wait seconds, usecs microseconds.
// returns: -1 on error
// 					0 on timeout
// 					otherwise the scancode of the key
char readkey_usecs( int wait, int usecs ){
		struct timeval tv;
		void *p = &tv;
		fd_set set;
		char c;

		tv.tv_sec = wait;
		tv.tv_usec = usecs;

		FD_ZERO( &set );
		FD_SET( fileno( stdin ), &set );

		if ( wait == -1 ) 
				p = NULL;

		int res = 0;
		
#ifndef X64
	 		res = select( fileno( stdin )+1, &set, NULL,NULL, p );
#else
		register long int r10 asm ("r10") = 0 ; 
		register long int r8 asm ("r8") = (long int) p ; 
		asm volatile ("syscall" : "=a" (res) : "a" ( SCALL(select) ) , "D" (fileno(stdin)+1), "S" (&set), "d" (0), "r" (r10), "r" (r8) : "memory" );
#endif
		
			//asm volatile ("syscall" : "=a" (ret) : "a" ( (23 | 0 ) ) , "D" (&fd), "S" (readfd), "d" (writefd), "r" (r10), "r" (r8) : "memory" );

		if ( debug )
				printf("res 1: %d %d\n",13,res);
		if ( res > 0 ){
				read( fileno( stdin ), &c, 1 );
				keybuf[keycount] = c;
				keycount++;
				if ( debug )
						printf("readkey 1: %u\n",c);

				return c;
		}
		if ( debug )
				printf("res 2: %d\n",res);
		if ( res == 0 ) // timeout
				return 0;

		perror( "select error" );
		return -1;
}
// Read a key, wait for wait seconds.
// set wait to -1 to wait forever
//
// returns: -1 on error
// 					0 on timeout
// 					otherwise the scancode of the key
char readkey( int wait ){
		return readkey_usecs( wait, 0 );
}


// read a key, show dots dots per second
char readkey_dots( int wait, int dots ){
		int a;
		int usecs = 0;
		int res = 0;
		int loops = wait;

		wait = 1;

		if ( dots > 1 ){ // more dots per second..
				wait = 0;
				usecs = 1000000 / dots;
				loops *= dots;
				//printf("usecs: %d\n", usecs );
		}

		for ( a = 0; a < loops; a++ ){
				fprint( stderr, "." );
				res = readkey_usecs( wait, usecs );
				if ( res != 0 ){ // got a result, could also be -1 (means error)
						fputs( "", stderr );
						return( res );
				}
		}
		fputs( "", stderr );
		return( res );
}

// Read an extended modifier keycode
char read_mod(){
		char mod;
		mod=readkey(0);
		if ( mod == 59 )
				mod = readkey(0);
//		} else{
				switch (mod){
						M(50,SHIFT);
						M(51,ALT);
						M(52,ALT|SHIFT);
						M(53,CTRL);
						M(54,CTRL|SHIFT);
						M(55,CTRL|ALT);
						M(56,CTRL|ALT|SHIFT);
						case 126:
							return(126);
						default:
						//printf("mod2: %u\n",mod);
						return(mod);
				} 
				mod = readkey(0);
		// else {
				//printf("mod3: %u\n",mod);
				return(mod);
		//}

}


int main( int argc, char *argv[])
{
		int wait = 0;
		int dots = 0;
		int pkey = 0;
		int fkey = 0;
		char *pstring=0;
		//pstring[0] = 0;


		// Parse Arguments
		int a;
		int b = 1; // show help?
		for ( a=1; a < argc; a++) {
				//mprintsl("Arg:",argv[a]);
				if ( strcmp(argv[a], "-b" )==0 )  {
						b = 0;
						wait = -1;
				} else  
				if ( strcmp(argv[a], "-n" )==0 )  {
						b = 0;
						wait = 0;
				}  else 
				if ( strcmp(argv[a], "-w")==0 ){
						if ( (a+1 < argc ) && ( atoi(argv[a+1]) >0 ) ){
								wait = atoi(argv[a+1]);
								//printf("wait: %d\n",wait);
								a++;
								b = 0;
						} else {
								wait=0;
								b=0;
						}
				} else 
				if ( strcmp(argv[a], "-d" )==0 )  {
						dots = 1;
						if ( (a+1 < argc ) && ( atoi(argv[a+1]) >0 ) ){
								dots = atoi(argv[a+1]);
								//printf("dots: %d\n",dots);
								a++;
						}

				} else 
				if ( strcmp(argv[a], "--debug")==0)
						debug=1;
				else
				if ( strcmp(argv[a], "--ret-modifier")==0)
						ret_modifier=1;
				else
				if ( strcmp(argv[a], "--only-key")==0)
						only_key = 1;
				else
				if ( strcmp(argv[a], "--repeat")==0)
						repeat = 1;


	

							
		}

		// Show usage
		if ( b ) {
				int it=0;
				const char* helpstring[] = {
"Usage: term_readkey [-b] [-w secs] [-d [dotrate]]",
"",
"Small program to wait for a key.",
"",
"The key/modifier is printed to stdout,",
"the return code is either the error code or",
"a value describing the modifier keys.",
"",
"parameters:",
"-b             : block until a key is pressed.",
"-w [secs]      : wait for [secs] (default 0) seconds for input.",
"-d [dotrate]   : show 1 dot per second waiting, optional [dotrate] dots per second",
"--ret-modifier : return the pressed modifier - A value composed by these or´ed values: CTRL=1 | ALT=2 | SHIFT=4.",
"--only-key     : Don´t print the modifier. (Doesn´t affect --ret-modifier)",
"--debug        : Debug, print the full scancode",
"",
"Returns 255: unknown (most possibly related to select) error",
"        254: timeout.",
"        253: Unknown Scancode",
"          0: Ok / No modifier",
"",
"Example: key=`term_readkey -w 5`",
"echo $key",
"CC-BY 4.0",
"Michael Misc Myer www.github.com/michael105/readkey"
				};
			//	tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );
				while (helpstring[it] != 0 ){ 
						fprint(stderr,helpstring[it++]);
						fprint(stderr,"\n");
				}

				return(0);
		}
	

		struct termios oldSettings, newSettings;
		char c,c2;
		int ret = 0;

		tcgetattr( fileno( stdin ), &oldSettings );
		newSettings = oldSettings;
		newSettings.c_lflag &= (~ICANON & ~ECHO );
		tcsetattr( fileno( stdin ), TCSANOW, &newSettings );
		//ioctl( fileno( stdin ), TIOCSETA, &newSettings );

		do{
		if ( dots ) {
				c = readkey_dots( wait, dots );
		} else {
				c = readkey( wait );
		}

		if ( debug ){
				printf("c: %d\n",c);
		}

AGAIN:
		switch ( c )
		{
				case 0 : //printf("0\n");
						exit(254); // timeout
						break;
				case -1 : 
						fprint(stderr,"Readkey: An unknown error occured");
						exit(255); // select error
						break;
				K(9,TAB);
				K(10,RET);
				K(127,BACKSPACE);
				case -61:
						 c=readkey(0);
						 if(debug) printf("c2: %d\n",c);
						 switch (c){
								 S(-68,"ü");
								 S(-74,"ö");
								 S(-92,"ä");
								 S(-100,"Ü");
								 S(-106,"Ö");
								 S(-124,"Ä");
								 S(-97,"ß");
						 }
						 break;
				case 27 : {
							c = readkey(0);
							switch ( c ){
									K(0,ESC);
									case 79 : { //F1..F4
AG79:
												c = readkey(0);
												switch ( c ){
												K(0,UNKNOWN);
												F(80,1);
												F(81,2);
												F(82,3);
												F(83,4);
												case 50: pmod |= SHIFT;
														 goto AG79;
												case 77: 
														 pmod |= SHIFT;
														 pkey = RET;
														 break;
												default:
																										 pkey=UNKNOWN;
																				}

																				break;
																		}
													case 91 : {	
																				c = readkey(0);
AG91:
																				switch ( c ){
																						case 51 :{
																												 c = readkey(0);
																												 switch ( c ){
																														 K(126,DEL);
																														 case 59 : read_mod(); 
																																			 pkey=DEL;
																																			 break;
																															case 49:
																															case 50:
																															case 51:
																															case 52: // Terminal, F5-F8
																																			 read_mod();
																																			 pmod |= SHIFT;
																																			 fkey = c-44;
																																			 //printf("SHIFT+F%c",c+4);
																																			 break;

																															default:
																																			 pkey=UNKNOWN;


																												 }
																												 break;
																										 }
																						K(65,UP);
																						K(66,DOWN);
																						K(67,RIGHT);
																						K(68,LEFT);
																						K(70,END);
																						K(72,POS1);
																						case 52: 	read_mod();
																											pkey=END;
																											break;
																						case 53 : //printf("-53");
																											read_mod();
																											pkey=PGUP;
																											break;
																						case 54 : read_mod();
																											pkey=PGDOWN;
																											break;
																						case 55 : pmod |= CTRL | ALT;
																											c = readkey(0);
																											goto AG91;

																						case 90 : pmod |= SHIFT; 
																											pkey = TAB;
																											break;

																						case 50 : // F5..F8
																											c = readkey(0);
																											switch(c){
																													case 1:
																													case 2:
																															//printf("91- 50/49 - 1/2 - %u",c);
																															pkey=UNKNOWN;
																															break;
																													default: 
																															c2 = read_mod();
																															switch ( c ){
																																	F(48,9);
																																	F(49,10);
																																	F(51,11);
																																	F(52,12);
																																	case 53: fkey=1;
																																					 pmod=SHIFT;
																																					 break;
																																	case 54: fkey=2;
																																					 pmod=SHIFT;
																																					 break;
																																	case 56: fkey=3;
																																					 pmod=SHIFT;
																																					 break;
																																	case 57: fkey=4;
																																					 pmod=SHIFT;
																																					 break;

																																	K(126,INS);

																																	default:
																																	//printf("91- 50/49 - %u\n",c);
																																	c=c2;

																																	goto AG91;
																															}
																											}
																													break;

																						case 49 : // F9..F12
																											//printf("u: %u\n",c);
																											c = readkey(0);
																											switch(c){
																													case 1:
																													case 2:
																															//printf("91- 50/49 - 1/2 - %u",c);
																															pkey=UNKNOWN;
																															break;
																													default: 
																															c2 = read_mod();
																															switch ( c ){
																																	F(53,5);
																																	F(55,6);
																																	F(56,7);
																																	F(57,8);
																																	K(126,INS);

																																	default:
																																	//printf("91- 50/49 - %u\n",c);
																																	c=c2;

																																	goto AG91;
																															}


																											}
																											break;
																							K(126,INS);
																							case 91:
																											c = readkey(0);
																											if ( (c>64) && ( c<70 ) )
																													fkey = c - 64;
																											else 
																													pkey=UNKNOWN;
																													//printf("91 - 91 - %u",c);
																											break;

																							default:
																											pkey=UNKNOWN;

																				}
																				break;
																		}
													default : 
																		//printf( "E: %u %c",c,c );
																		pmod |= ALT;
																		goto AGAIN;

											}

											break;
									}


				default: {
										 if ( (c>0) && (c < 27) ){
												 pmod |= CTRL;
												 pkey=c+64;
												 break;
										 }
										 pkey = c;
								 }
		}
		if ( (pkey | fkey) != 0 || ( pstring!=0))
				ret=key_output(pmod,pkey,fkey,pstring);
		
			keycount=0;
			fkey=0;
			pkey=0;
			pstring=0;
			pmod=0;
		} while ( repeat==1 );


		tcsetattr( fileno( stdin ), TCSANOW, &oldSettings );
		return(ret);
		//exit(ret);
}

