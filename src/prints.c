#ifndef mini_dprints_c
#define mini_dprints_c
//#include "../include/write.h"
//#include "../include/prints.h"
#include "../include/stdarg.h"

#ifndef mini_prints
#define mini_prints
#endif


//TODO: Handle errors of write (ret == -1)

//+needs write.h prints.h stdarg.h
//+depends write
//+def
int dprints(int fd, const char *msg,...){
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

#endif
