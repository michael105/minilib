

//+def
int ltodec(long i, char *buf, int prec, char limiter ){
	if ( i < 0 ){
			buf[0]='-';
			i = -i;
			return(ultodec((unsigned long)i,&buf[1],prec,limiter) + 1 );
	}
	return(ultodec((unsigned long)i,buf,prec,limiter) );
}



