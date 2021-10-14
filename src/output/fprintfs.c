//+depends fputs write fileno strlen
//+after fputs
//+doc prints formatted and unbuffered output to the stream F.
// only %s and %c are recognized.
// no mini_buf or globals are used, so using fprintfs instead of fprintf can 
// save some sections / bytes.
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
			if (fmt[a] == 'c'){
				ret += write(fd,&fmt[p],a-1-p);
				p=a+1;
				char c = va_arg(args,int);
				ret += write( fd,&c,1 );
			}

		}
		a++;
	}
	ret += write(fd,&fmt[p],a-p);

	va_end(args);
	return(ret);

}

