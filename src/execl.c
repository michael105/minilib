
#include "../include/stdarg.h"

//+depends environ execve
//+def
static int execl(const char *pathname, const char* arg0,... ){
		va_list ap;
		va_start(ap, arg0);

		int argc = 1;
		while (va_arg(ap, const char *)) 
				argc++;

		va_end(ap);

		{
				int i;
				char *argv[argc+1];
				va_start(ap, arg0);
				argv[0] = (char *)arg0;
				for (i=1; i<argc; i++)
						argv[i] = va_arg(ap, char *);
				argv[i] = 0;
				va_end(ap);

				return(execve(pathname, argv, environ));
		}
}



