
//+depends write vsnprintf
//+needs stdarg.h
//+def
int snprintf( char *buf, size_t size, const char *fmt, ... ){
	va_list args;
	va_start(args,fmt);
	int r = vsnprintf(buf, size, fmt, args);
	va_end(args);
	return(r);
}


