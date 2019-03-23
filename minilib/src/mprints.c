#ifndef mprints_c
#define mprints_c
#include "../include/write.h"
#include "../include/mprints.h"
#include "../include/stdarg.h"

#ifndef mini_mprints
#define mini_mprints
#endif

//TODO: Handle errors of write (ret == -1)

#if 0
int _mprints(char *msg,...){
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

//+needs write.h mprints.h stdarg.h
//+depends write
int _mprints(char *msg,...){
		va_list args;
		va_start(args,msg);
		int a;
		int ret = 0;

		do {
				a = 0;
				while (msg[a] != 0 ){
						a++;
				}
				ret += write(1,msg,a);
				msg = va_arg(args,char*);
		} while ( msg != 0 );
		va_end(args);
		return(ret);
}
#endif

#endif
