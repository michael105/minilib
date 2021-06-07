#if 0
mini_start
mini_buf 256
mini_printf

mini_ltodec
mini_atol
mini_atoi
mini_itodec
mini_ultodec

OPTFLAG -O0
INCLUDESRC

return
#endif


int main(int argc, char **argv){
		printf("Ok\n");

		printf("sizeof long: %d\n", sizeof(long) );
		char buf[32];
		int r = ultodec(1234,buf,0,0);
		printf("1234: %s\n",buf);
		ultodec(1234,buf,6,0);
		ultodec(1234,buf,10,'.');
		printf("1234: %s\n",buf);

		ultodec(argc,buf,0,0);
		printf("argc: %s\n",buf);

		printf("fmt, 9001: %d\n",(long)9001);
		printf("fmt, 9001: %ld\n",(long)9001);
		printf("fmt, 9001: %1ld\n",(long)9001);
		printf("fmt, 9001: %7ld\n",(long)9001);

		if ( argc>1 ){
		long l = atol(argv[1]);
		ltodec(l,buf,0,0);
		printf("argv: %s\n",buf);

		ltodec(l,buf,10,'.');
		printf("argv: %s\n",buf);
		}



		return(0);
}

