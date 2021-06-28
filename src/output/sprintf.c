#ifndef msprintf_c
#define msprintf_c

//+include

//+doc I'm really uncertain about the size arg here, amongst others
// these are just misdefined functions, inhaerent insecure. :/
// If possible, do not use sprintf. Use snprintf instead. 
//+depends snprintf vsnprintf strlen
//+macro
#define sprintf(str,...) snprintf( str, mini_buf,  __VA_ARGS__)

//
// todo: add attribute printf (gcc format checking)



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
