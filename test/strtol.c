#if 0
mini_start
mini_buf 256

mini_printf
mini_ltodec
mini_itodec
mini_itohex
mini_strtol
INCLUDESRC
LDSCRIPT text_and_bss
return
#endif

int main(int argc, char **argv){

		printf("sizeof long: %d\n", sizeof(long));
		for ( int a=0; a<argc; a++ ){
				printf("arg %d :",a);
				printf("%s ",argv[a]);
				printf("conv: %ld\n",strtol(argv[a],0,0));
		}

		return(0);
}
