#if 0
mini_start
mini_buf 256
mini_printf

mini_ltodec
mini_atol
mini_atoi
mini_itodec
mini_ultodec

#LDSCRIPT default
LDSCRIPT text_and_bss
OPTFLAG -O0
DEBUG
INCLUDESRC


return
#endif


int main(int argc, char **argv){
		printf("Ok\n");

		printf("sizeof long: %d\n", sizeof(long) );
		char buf[32];
		int r = ultodec(1234,buf,0,0);
		printf("1234: %s\n",buf);

		if ( argc>1 ){
		long l = atol(argv[1]);
		ltodec(l,buf,0,0);
		printf("argv: %s\n",buf);

		}



		return(0);
}

