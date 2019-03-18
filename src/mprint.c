#ifndef mprint_c
#define mprint_c
#include "../include/write.h"

//+def
int print(const char *msg){
		int a=0;
		while (msg[a] != 0 ){
				a++;
		}
		return( write(1,msg,a) );
}

//+def
int printl(const char *msg){
		int ret = print(msg);
		write(1,"\n",1);
		ret++;
		return(ret);
}

#ifdef mini_puts
//int puts( const char *c ){
//		return(printl(c));
//}
#endif

#endif
