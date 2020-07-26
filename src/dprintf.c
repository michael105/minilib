
//+depends write vsnprintf
//+needs stdarg.h
//+def
int dprintf( int fd, const char *fmt, ... ){
		va_list args;
		va_start(args,fmt);
		int r = vsnprintf(mlgl->mbuf, mlgl->mbufsize, fmt, args);
		if ( r<0 ){
				write(2,"Buffer Overrun.\n",16);
				exit(1);
		}
		write( fd, mlgl->mbuf, r );
		va_end(args);
		return(r);
}


