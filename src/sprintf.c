#ifndef msprintf_c
#define msprintf_c

#ifndef mini_write
#define mini_write
#endif


#ifndef mini_prints
#define mini_prints
#endif

#include "../macros/overrun.h"
//#include "../include/write.h"
#include "../include/exit.h" // Needed for testing for buffer overrun
#include "../include/stdarg.h"


#undef MINI_TEST_OVERRUN
#define MINI_TEST_OVERRUN(pos) if ( pos>= size ){ overflow=1; goto msprintfout;}

//+include

//+depends snprintf vsnprintf
//+macro
#define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)

// I'm really uncertain about the size arg here, amongst others
// these are just misdefined functions, inhaerent insecure. :/
// If possible, do not use sprintf. Use snprintf instead. 

//+ansi stdio.h
//+depends write
//+needs exit.h stdarg.h overrun.h
//+after itohex itoHEX
//+doc the function, translating the fmt of printf.
// warning - most possibly you'd like to define besides fprintf, or family,
// mini_itodec (%d conversion) 
// mini_atoi is needed for grouping numbers
//+def
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args ){

		//va_list args;
		//va_start(args,fmt);
		int a = 0;
		int b = 0;
		int overflow = 0;
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
								padding = 0;
								while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
												//tmp[c] = fmt[a]; 
												//c++;
												padding*=10;
												padding+=fmt[a]-48;
												a++;
								}
								switch (fmt[a]){
										case '%': 	
												buf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
#if 1
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&buf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
#endif
												end=1;
												break;
#endif
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&buf[b],padding);
#endif
												end=1;
												break;
										case 'l':
#ifdef mini_ltodec
												MINI_TEST_OVERRUN(b+27);
												b = b + ltodec(va_arg(args,long),&buf[b],padding,sep);
#endif
												end=1;
												break;

										case 39:
												sep = '.';
												break;
										case 'x':
#ifdef mini_itohex
												MINI_TEST_OVERRUN(b+8);
												b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;
										case 'X':
#ifdef mini_itoHEX
												MINI_TEST_OVERRUN(b+8);
												b = b + itoHEX(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;

										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&buf[b],padding,groups);
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
														buf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												buf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						buf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
msprintfout:
		buf[b] = 0;
		va_end(args);

		//write( 2, buf, 20 );
		//return(write(fd,buf,b));
		if ( overflow )
				return(-b);
		else
				return(b);
#endif
}



/// fprintf
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
//+header stdio.h
//+depends write prints dprintf sprintf fileno
//+needs mini_fstream.h 
//+after itobin atoi itodec dtodec ltodec itohex
//+macro fprintf(stream,...)	write(fileno(stream),mlgl->mbuf,sprintf(mlgl->mbuf,__VA_ARGS__))



#if 0		
		va_list args;
		va_start(args,fmt);
		int a = 0;
		int b = 0;
		int end, padding, c,groups;
		char sep;
		char tmp[16];
		char *s;

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
												buf[b] = '%';
												end=1;
												b++;
												MINI_TEST_OVERRUN(b);
												break;
										case 'u':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + uitodec(va_arg(args,unsigned int),&mlgl->mbuf[b],padding,sep);
#endif
												end=1;
												break;
										case 'd':
#ifdef mini_itodec
												MINI_TEST_OVERRUN(b+13);
												b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
#endif
												end=1;
												break;
										case 'f':
#ifdef mini_dtodec
												MINI_TEST_OVERRUN(b+27);
												if ( padding==0 )
														padding = 9;
												b = b + dtodec(va_arg(args,double),&buf[b],padding);
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
												b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
												end=1;
												break;
										case 'b':
#ifdef mini_itobin

												MINI_TEST_OVERRUN(b+32);
												b += itobin(va_arg(args,int),&buf[b],padding,groups);
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
														buf[b] = s[c];
														c++;
														b++;
														MINI_TEST_OVERRUN(b);
												}
												end=1;
												break;
										case 'c':
												buf[b] = va_arg(args,int);
												b++;
												end=1;
												MINI_TEST_OVERRUN(b);
												break;
												





								}

						} while ((end==0) && (fmt[a+1] != 0 ));

				} else {
						buf[b] = fmt[a];
						b++;
						MINI_TEST_OVERRUN(b);
				}
				a++;
		}
		buf[b] = 0;
		va_end(args);
		//return(write(1,buf,b));
		return(b);
}
#endif
#endif
