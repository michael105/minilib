#if 0
mini_start
mini_fgets
mini_prints
mini_eprint
mini_strlen
mini_ewrites
INCLUDESRC
SHRINKELF

return
#endif

// remove leading blanks and empty lines
// read from stdin, write to stdout
//
// matches also within strings,
// so take care

#define MAXLEN 1024

int main(int argc, char **argv){
		char buf[MAXLEN];
		int a;

		while ( fgets( buf, MAXLEN, stdin ) ){
				if ( strlen(buf)>=MAXLEN ){
						ewrites("Warning: line > MAXLEN\n");
						do {
								eprint(buf);
								prints(buf);
						} while ( fgets(buf,MAXLEN,stdin) && (strlen(buf) >= MAXLEN) );
						eprint(buf);
						prints(buf);
				} else {
						for ( a=0; isspace(buf[a]); a++ );
						if ( buf[a] != 0 )
								prints( buf+a );
				}
		}

		return(0);
}
