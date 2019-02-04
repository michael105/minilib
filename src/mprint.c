#ifndef mprint_c
#define mprint_c
#include "../include/write.h"

int print(const char *msg){
		int a=0;
		while (msg[a] != 0 ){
				a++;
		}
		return( write(1,msg,a) );
}


int printl(const char *msg){
		int ret = print(msg);
		write(1,"\n",1);
		ret++;
		return(ret);
}

#endif
