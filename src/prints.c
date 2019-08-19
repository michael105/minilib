#ifndef prints_c
#define prints_c
//#include "../include/write.h"
#include "../include/prints.h"
#include "../include/stdarg.h"

#ifndef mini_prints
#define mini_prints
#endif

//TODO: Handle errors of write (ret == -1)

#if 0
int _prints(char *msg,...){
		int a;
		int ret = 0;

		do {
				a = 0;
				while (msg[a] != 0 ){
						a++;
				}
				ret += write(1,msg,a);
				//msg = 0;//va_arg(args,char*);
				//msg+=4;
				printf("\nmsg: %u\n",msg);
				printf("msg: %u\n",&msg);
				unsigned int i;
				i = &msg;
				printf("i: %u\n",i);
				i+=4;
				printf("i: %u\n",i);
				*msg = i;
				printf("\nmsg: %u\n",msg);
				printf("msg: %u\n",&msg);

				msg=0;
		} while ( msg != 0 );
		return(ret);
}

#else

//+needs write.h prints.h stdarg.h
//+depends write
int dprints(int fd, char *msg,...){
		va_list args;
		va_start(args,msg);
		int a;
		int ret = 0;

		do {
				a = 0;
				while (msg[a] != 0 ){
						a++;
				}
				ret += write(fd,msg,a);
				msg = va_arg(args,char*);
		} while ( msg != 0 );
		va_end(args);
		return(ret);
}

//+needs write.h prints.h stdarg.h
//+depends dprints
//+macro _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)


static inline int volatile fputs(const char *c, FILE *F);

//+depends fputs write fileno
//+after fputs
//+doc prints formatted to the stream F.
//+doc only %s is recognized.
//+doc no mini_buf needed, so using fprintfs instead of fprintf can save some sections / bytes.
//+def
int fprintfs( FILE* F, char *fmt, ...){
		va_list args;
		va_start(args,fmt);
		char *msg;
		int fd = fileno(F);
		int a;
		int p=0;
		int ret = 0;

		a = 0;
		while (fmt[a] != 0 ){
				if ( fmt[a] == '%' ){
						a++;
						if (fmt[a] == 's'){
								ret += write(fd,&fmt[p],a-1-p);
								p=a+1;
								msg = va_arg(args,char*);
								ret += fputs( msg, F );
						}
				}
				a++;
		}
		ret += write(fd,&fmt[p],a-p);

		va_end(args);
		return(ret);

}

#endif

#endif
