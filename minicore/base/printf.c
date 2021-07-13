#if 0
mini_start
COMPILE strlen atoi ewritesl raise itohex
COMPILE ltodec itodec itoHEX
#COMPILE itobin dtodec itooct uitodec ultodec

mini_buf "(PAGESIZE-128)"
globals_on_stack
#LDSCRIPT mlplugin
LDSCRIPT mlplugin_onlytext
INCLUDESRC
export PICFLAG="-fPIE"

STRIPFLAG
#SHRINKELF

#PLUGIN printf
#EXPORT do_printf


return
#endif



#ifdef MINI_TEST_OVERRUN
#undef MINI_TEST_OVERRUN
#endif
#define MINI_TEST_OVERRUN(pos) if ( pos>= size ){ goto OVERFLOW;}

#define CHECKARG if ( ! *args ) goto MISSING


void usage(){
	ewritesl("printf format [arguments]");
	//exit(0);
}

#define buf mlgl->mbuf
#define size mlgl->mbufsize
int do_printf(const char* fmt, char *args[], int convert_args){
	int a = 0;
	int b = 0;
	int end, padding, c,groups=0;
	char sep,pad;
	char tmp[16];
	char *s;
	int mod;  // modifier. : 0==int, 1==long

//	write(1,"dbg\n",4);
//	write(1, fmt, strlen(fmt));
//	write(1,"dbg\n---\n",8);

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
					case 'u':
#ifdef mini_itodec

						if ( mod == 0 ){
							CHECKARG;
							MINI_TEST_OVERRUN(b+13);
							b = b + uitodec((convert_args?atoi(*args):(int)**args),&buf[b],(padding?padding:1),sep,pad);
							args++;
							//b = b + uitodec(va_arg(args,unsigned int),&buf[b],padding,sep);
						}
#endif
#ifdef mini_ultodec
						if ( mod == 1 ){
							CHECKARG;
							MINI_TEST_OVERRUN(b+27);
							b = b + ultodec((convert_args?atol(*args):(long)**args),&buf[b],(padding?padding:1),sep);
							//b = b + ltodec(va_arg(args,long),&buf[b],padding,sep);
						}
#endif


						end=1;
						break;
					case 'd':
#ifdef mini_itodec
						if ( mod == 0 ){
							CHECKARG;
							MINI_TEST_OVERRUN(b+13);
							b = b + itodec((convert_args?atoi(*args):(int)**args),&buf[b],padding,sep,pad);
							args++;
							//b = b + itodec(va_arg(args,int),&buf[b],padding,sep);
						} 
#endif
#ifdef mini_ltodec
						if ( mod == 1 ){
							CHECKARG;
							MINI_TEST_OVERRUN(b+27);
							b = b + ltodec((convert_args?atoi(*args):(int)**args),&buf[b],(padding?padding:1),sep);
							args++;
							//b = b + ltodec(va_arg(args,long),&buf[b],padding,sep);
						}
#endif

						end=1;
						break;
					case 'f':
#ifdef mini_dtodec
						CHECKARG;
						MINI_TEST_OVERRUN(b+27);
						if ( padding==0 )
							padding = 9;
						// no double yet
						b = b + dtodec((convert_args?atoi(*args):(int)**args)va_arg(args,double),&buf[b],(padding?padding:1));
						args++;
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
						CHECKARG;
						MINI_TEST_OVERRUN(b+8);
						b = b + itohex((convert_args?atoi(*args):(int)**args),&buf[b],padding);
						args++;
						//b = b + itohex(va_arg(args,int),&buf[b],padding);
#endif
						end=1;
						break;
					case 'X':
#ifdef mini_itoHEX
						CHECKARG;
						MINI_TEST_OVERRUN(b+8);
						b = b + itoHEX((convert_args?atoi(*args):(int)**args),&buf[b],padding);
						args++;
#endif
						end=1;
						break;

					case 'o':
#ifdef mini_itooct	
						CHECKARG;
						MINI_TEST_OVERRUN(b+16);
						b = b + itooct((convert_args?atoi(*args):(int)**args),&buf[b]);
						args++;
#endif
						end=1;
						break;

					case 'b':
#ifdef mini_itobin
						CHECKARG;
						MINI_TEST_OVERRUN(b+32);
						b += itobin((convert_args?atoi(*args):(int)**args),&buf[b],(padding?padding:1),groups);
						args++;
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
						CHECKARG;
						s = *args;
						args++;
						//s = va_arg(args,char*);
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
						CHECKARG;
						buf[b] = (int)(**args);
						b++;
						end=1;
						MINI_TEST_OVERRUN(b);
						args++;
						break;

				}

			} while ((end==0) && (fmt[a+1] != 0 ));

		} else { // fmt[a] == '%'
			if ( fmt[a] == '\\' ){
				a++;
				switch(fmt[a]){
					case 'n': buf[b] = '\n'; break;
					case 'b': buf[b] = '\b'; break;
					case 'f': buf[b] = '\f'; break;
					case 'a': buf[b] = '\a'; break;
					case 'r': buf[b] = '\r'; break;
					case 't': buf[b] = '\t'; break;
					case 'v': buf[b] = '\v'; break;
					default: buf[b] = fmt[a];
				}

			} else {
				buf[b] = fmt[a];
			}
			b++;
			MINI_TEST_OVERRUN(b);
		}
		a++;
	}
	buf[b] = 0;
	//va_end(args);

	write( STDOUT_FILENO, buf, b );

	//write(1,"\n---\n",5);

	return(b);

MISSING:
	ewritesl("Missing Argument");
	return(-1);

OVERFLOW:
	raise(SIGSEGV);
	return(-b);
}

static const int* __plugin_export[] = {
	(int*)(do_printf - 0x8048000),
	(int*)(usage - 0x8048000),
	0
};


int main(int argc, char *argv[],char **envp){
	if ( argc<= 1 )
		usage();

	do_printf(argv[1],argv+2,1);

	asm("jmp __exit\n"::"D"(0));
	opt_fence(__plugin_export);
}
