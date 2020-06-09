#if 0
mini_start
mini_writes
mini_sleep

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif


void usage(){
		writes("Usage: sleep val[s|m|h|d]\n");
		exit(-1);
}


int toint( const char c[] ){
	int ret = 0;

	while ( *c > 47 && *c < 58 ){
			ret *= 10;
			ret += (*c-48);
			*c++;		
	}

	switch (*c) {
			case 'm': ret*=60;
								break;
			case 'h': ret*=60*60;
								break;
			case 'd': ret*=60*60*24;
								break;
			case ' ':
			case '\0':
			case 's':
								break;
			default: usage();
	}
								
	return(ret);
}

int main(int argc, char *argv[]){
	if (argc != 2) {
			usage();
	}
	
	int v = toint( argv[1] );
	
	if ( v < 1 ){
			usage();
	}
	
	sleep(v);

	return 0;
}
