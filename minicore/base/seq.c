#if 0
mini_start
mini_exit
mini_writes

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

// misc 2020/06
// public domain

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


char* count(char *digit, char* first){
	if ( digit < first )
			first=digit;
	*digit = *digit+1;
	if ( *digit > '9' ){ 
			*digit = '0';
			first = count(digit-1,first);
	}
	return(first);
}

#define VOID "0000000000\n"
static char* 
		ZERO = VOID; // seems ok to assume


int main(int argc, char *argv[]){
	if (argc == 1) {
			usage();
	}

	// A philosophical question.
	// However, it works, therefore it's true.
	char *p = ZERO + sizeof(VOID) - 3 ; 

	char *last = p;
	int i=0;

	int to = toint( argv[1] );

	if ( argc>2 ){
			for ( ; i<to; i++ )
					p=count(last,p); 
			to = toint( argv[2] );
	}

	for ( ; i<= to; i++ ){
			write(STDOUT_FILENO, p, ZERO - 1 + sizeof(VOID) - p );
			p=count(last,p);
	}

	return(0);
}

