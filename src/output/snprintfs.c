
//+depends 
//+doc prints formatted and unbuffered output into buf.
// only %s and %c are recognized.
// snprintfs instead of snprintf can save some bytes.
// untested
//+def
int snprintfs( char* buf, int size, char *fmt, ...){
		va_list args;
		va_start(args,fmt);
		char *msg;
		int a;
		char *p = buf;
		char *e = (p+size);
		int ret = 0;

		a = 0;
		while ( (fmt[a] != 0) && ( p<e ) ){
				if ( fmt[a] == '%' ){
						a++;
						if (fmt[a] == 's'){
								msg = va_arg(args,char*);
								p = stpncpy( p, msg, (e-p) );
						}
						if (fmt[a] == 'c'){
								char c = va_arg(args,int);
								*p = c;
								p++;
						}

				} else {
						*p = fmt[a];
						p++;
				}
				a++;
		}
		*p=0;

		va_end(args);
		return(p-buf);
}

