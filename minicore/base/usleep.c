#if 0
mini_start
mini_writes
mini_usleep

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

// misc 2020/07
// Public domain

void usage(){
		writes("Usage: usleep microseconds\n");
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
	if (argc != 2){
			usage();
	}
	
	int v = toint( argv[1] );
	
	if ( v < 1 ){ // -h returns 0 as well
			usage();
	}
	
	usleep(v);

	return 0;
}
