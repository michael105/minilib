#if 0
mini_start
mini_writes
mini_puts
mini_printf
mini_strlen
mini_itodec
mini_atoi
mini_buf 256
mini_verbose_errstr2
mini_short_errstr
mini_shortcolornames
mini_environ

INCLUDESRC
LDSCRIPT text_and_bss
globals_on_stack
HEADERGUARDS
#shrinkelf
STRIPFLAG
return
#endif

void putx(){
	puts(environ[1]);
	printf(environ[1]);
	write(1,environ[0],10);
}

static void px(int e){
	write(1,"Ok px!\n",7);
}



static void put_errstr(int e){
	puts(verbose_errstr2(e));
	putx();
	px(e);
}

int main(int argc, char *argv[]){
	int e =0;

	if ( argc == 1 ){
		writes("Usage: errno [-l] [-L] [errno number]\n");
		exit(0);
	}

	if ( argv[1][0]=='-' ){
		if ( argv[1][1] == 'l' ){ // list all errno values
			for ( int a=1; a <= ERRNO_MAX; a++ ){
				printf("%d: ", a); 
				put_errstr(a);
				//printf("%d: %s\n", a, verbose_errstr2(a));
			} 
		} 
		if ( argv[1][1] == 'L' ){
			for ( int a=1; a <= ERRNO_MAX; a++ ){
				printf(LRED"%3d:"LGREEN" %15s"NORM"   ", a, short_errstr(a));// verbose_errstr2(a));
				put_errstr(a);
				//printf(LRED"%3d:"LGREEN" %15s"NORM"   %s\n", a, short_errstr(a), verbose_errstr2(a));
			}
		} 
	} else {
			e = atoi( argv[1] );
			if ( e ){
				//puts(verbose_errstr2(e));
				put_errstr(e);
			}
		}
	putx();
	putx();
	px(23);
	write(1,"ooo\n",4);
	exit(e);
}

