#if 0
mini_start
mini_exit
mini_writes
mini_sleep

mini_printf
mini_itodec
mini_buf 200

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

// misc 2020/06
// BSD license

void usage(){
		writes("Usage: seq from/to [to]\n");
		exit(-1);
}


int toint( const char c[] ){
	int ret = 0;

	while ( *c > 47 && *c < 58 ){
			ret *= 10;
			ret += (*c-48);
			*c++;		
	}
	return(ret);
}




int main(int argc, char *argv[]){
	if (argc == 1) {
			usage();
	}
	
	int i=0;
	int to = toint( argv[1] );
	if ( argc>2 ){
			i = to;
			to = toint( argv[2] );
	}

	for ( ; i<= to; i++ ){
			printf("%d\n",i);
	}


	return(0);
}

