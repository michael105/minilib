
//+doc write fmt and arguments into buf
// calls vsnprintf, 
// the size is limited to 4096 by default and assumes
// a buf len of 4096.
//+depends write vsnprintf
//+needs stdarg.h
//+depends
//+def
int vsprintf( char *buf, const char *fmt, ... ){
		va_list args;
		va_start(args,fmt);
		int r = vsnprintf(buf, 4096, fmt, args);
		va_end(args);
		return(r);
}


