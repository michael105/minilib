
#include "../macros/overrun.h"
#include "../include/exit.h" // Needed for testing for buffer overrun


#undef MINI_TEST_OVERRUN
#define MINI_TEST_OVERRUN(pos) if ( pos>= size ){ goto OVERFLOW;}



//+ansi stdio.h
//+needs exit.h stdarg.h overrun.h
//+after itohex itoHEX
//+doc the function, translating the fmt of printf.
// warning - most possibly you'd like to define besides fprintf, or family,
// mini_itodec (%d conversion) 
// mini_atoi is needed for grouping numbers
//+depends write strlen raise
//+def
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args ){

	//va_list args;
	//va_start(args,fmt);
	int a = 0;
	int b = 0;
	int end, padding, c,groups=0;
	char sep,pad;
	char tmp[16];
	char *s;
	int mod;  // modifier. : 0==int, 1==long

#if 1
	while ( fmt[a] != 0){
		if ( fmt[a] == '%' ){
			end=0;
			padding = 0;
			sep = 0;
			groups=0;
			mod = 0;
			pad = ' ';
			do {
				a++;
				if ( fmt[a] == '0' ){
					a++;
					pad = '0';
				}

				while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
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

						if ( mod == 0 ){
							MINI_TEST_OVERRUN(b+13);
							b = b + uitodec(va_arg(args,unsigned int),&buf[b],(padding?padding:1),sep,pad);
							//b = b + uitodec(va_arg(args,unsigned int),&buf[b],padding,sep);
						}
#endif
#ifdef mini_ultodec
						if ( mod == 1 ){
							MINI_TEST_OVERRUN(b+27);
							b = b + ultodec(va_arg(args,long),&buf[b],(padding?padding:1),sep);
							//b = b + ltodec(va_arg(args,long),&buf[b],padding,sep);
						}
#endif


						end=1;
						break;
					case 'd':
#ifdef mini_itodec
						if ( mod == 0 ){
							MINI_TEST_OVERRUN(b+13);
							b = b + itodec(va_arg(args,int),&buf[b],padding,sep,pad);
							//b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
						} 
#endif
#ifdef mini_ltodec
						if ( mod == 1 ){
							MINI_TEST_OVERRUN(b+27);
							b = b + ltodec(va_arg(args,long),&buf[b],(padding?padding:1),sep);
							//b = b + ltodec(va_arg(args,long),&buf[b],padding,sep);
						}
#endif

						end=1;
						break;
#endif
					case 'f':
#ifdef mini_dtodec
						MINI_TEST_OVERRUN(b+27);
						if ( padding==0 )
							padding = 9;
						b = b + dtodec(va_arg(args,double),&buf[b],(padding?padding:1));
						//b = b + dtodec(va_arg(args,double),&buf[b],padding);
#endif
						end=1;
						break;
					case 'l':
						mod = 1;
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

					case 'o':
#ifdef mini_itooct
						MINI_TEST_OVERRUN(b+16);
						b = b + itooct(va_arg(args,int),&buf[b]);
#endif
						end=1;
						break;

					case 'b':
#ifdef mini_itobin

						MINI_TEST_OVERRUN(b+32);
						b += itobin(va_arg(args,int),&buf[b],(padding?padding:1),groups);
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
						if ( padding ){
							int l=strlen(s);
							while ( padding > l ){
								buf[b] = ' ';
								b++;l++;
							}
						}
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

	return(b);

OVERFLOW:
	raise(SIGSEGV);
	return(-b);
#endif
}


