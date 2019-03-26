#ifndef mfprintf_c
#define mfprintf_c

#ifndef mini_write
#define mini_write
#endif


#ifndef mini_prints
#define mini_prints
#endif

#include "../macros/overrun.h"
#include "../include/write.h"
#include "../include/minilib_global.h"
//#include "../include/exit.h" // Needed for testing for ml.mbuffer overrun
#include "mprints.c"
#include "../include/stdarg.h"
//#include <stdarg.h>
//#include "ml.mbuf.c"

/// mfprintf
/// conversions implemented:
/// %d  
/// %u
/// %f (max precision 8 digits, highest possible number: 2^31
/// %s
/// %c
/// %b : binary output
/// %x/X : hex output
/// %(
/// 
//+ansi stdio.h
//+depends write prints
//+after itobin atoi itodec dtodec ltodec itohex
//+def
int fprintf(int fd, const char* fmt, ... ){
/*		va_list args, ca;
		va_start(args,fmt);
		va_copy(ca,args);
		int len = msprintf(ml.mbuf,fmt,&ca);
		va_end(args);
		va_end(ca);
		return(write(fd,ml.mbuf,len));
}*/ //no ork.

		va_list args;
		va_start(args,fmt);
		int a = 0;
		int b = 0;
		int end, padding, c,groups=0;
		char sep;
		char tmp[16];
		char *s;

#if 1
		while ( fmt[a] != 0){
				if ( fmt[a] == '%' ){
						end=0;
						padding = 0;
						sep = 0;
						groups=0;
						do {
								a++;
								if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
										c = 0;
										do { 
												tmp[c] = fmt[a]; 
												a++;
												c++;
										} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
										tmp[c] = 0;
#ifdef mini_atoi
										padding = atoi(tmp);
#endif
								}
								switch (fmt[a]){
										case '%': 	
												ml.mbuf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
#if 1
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&ml.mbuf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&ml.mbuf[b],padding,sep);
#endif
												end=1;
												break;
#endif
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&ml.mbuf[b],padding);
#endif
												end=1;
												break;
										case 'l':
#ifdef mini_ltodec
												MINI_TEST_OVERRUN(b+27);
												b = b + ltodec(va_arg(args,long),&ml.mbuf[b],padding,sep);
#endif
												end=1;
												break;

										case 39:
												sep = '.';
												break;
										case 'x':
										case 'X':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itohex(va_arg(args,int),&ml.mbuf[b],padding);
#endif
												end=1;
												break;
										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&ml.mbuf[b],padding,groups);
#endif
												end=1;
												break;
										case '(':
												a++;
												if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
														c = 0;
														do { 
																tmp[c] = fmt[a]; 
																a++;
																c++;
														} while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
														a--;
														tmp[c] = 0;
#ifdef mini_atoi
														groups = atoi(tmp);
#endif
												}
												break;
										case 's':
												s = va_arg(args,char*);
												c=0;
												while(s[c] != 0){
														ml.mbuf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												ml.mbuf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						ml.mbuf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
		ml.mbuf[b] = 0;
		va_end(args);
		return(write(fd,ml.mbuf,b));
		//return(b);
#endif
}

//#define fprintf(...) mfprintf(__VA_ARGS__)

#endif
