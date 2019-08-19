


//+depends fputs write fileno
//+after fputs
//+doc prints formatted to the stream F.
//+doc only %s is recognized.
//+doc no mini_buf needed, so using fprintfs instead of fprintf can save some sections / bytes.
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
				}
				a++;
		}
		ret += write(fd,&fmt[p],a-p);

		va_end(args);
		return(ret);

}


