#if 0
mini_start
mini_buf 512
globals_on_stack
OPTFLAG "-Os"
mini_printf
mini_itodec
mini_ltodec
mini_itoHEX
mini_itobin
mini_writes
mini_strtol

LDSCRIPT textandbss
INCLUDESRC
SHRINKELF

return
#endif

void usage(){
		writes("Usage: conv number [base]\nbase can be 2 to 36\n");
		exit(0);
}


int main(int argc, char** argv){
		if ( argc<2 || (argv[1][0] == '-' && argv[1][1] == 'h' ) )
				usage();
		int base = 0;
		if (argc > 2 )
				base = (int)strtol(argv[2],0,0);

		long l = strtol(argv[1],0,base);
		printf("%l\n0x%X\n%b\n", l,l,l);

		return(0);
}
