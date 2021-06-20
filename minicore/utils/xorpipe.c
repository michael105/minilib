#if 0
mini_start
mini_write 
mini_writes
mini_ewritesl
mini_read
mini_malloc_brk
mini_realloc
mini_eprints

mini_buf 1024
mini_group_printf

INCLUDESRC

return
#endif

#define BUF 4096

//// doesnt ork


void usage(){
	writes("xorpipe [-h] [-a] [-s] [-k key] [-i file] [-o file]\n\
convert input to hexadecimal, xor with key.\n\
If the key is shorter than the input, the key is repeated.\n\
\n\
If no options are supplied, read key and input from stdin.\n\
key given as hexadecimal numbers, and separated from the input by a linebreak.\n\
\n\
-h show this help\n\
-s key is given as binary string\n\
-a: convert output to ascii\n\
\n\
");
	exit(0);
}

#define FAIL(c,err) {ewritesl(c);exit(err);}

char* index(const char *s, int c){
	while( *s ){
		s++;
		if ( *s == c )
			return((char*)s);
	}
	return(0);
}

char* xor(char *key, char *keypos, char *keyend, char *buf, int len){
	for ( int a = 0; a<len; a++ ){
		*buf = *keypos ^ *buf;
		buf++;
		keypos++;
		if ( keypos==keyend )
			keypos=key;
	}
	return(keypos);
}


char* xor64(char *key, char *keypos, char *keyend, char *buf, int len){
	for ( int a = 0; a<=(len>>3); a++ ){
		*(long*)buf = (long)(*(long*)keypos ^ *(long*)buf);
		buf+=8;
		keypos+=8;
		if ( keypos>keyend-8 )
			keypos=key;
	}
	return(keypos);
}

int main(int argc, char **argv){
		char buf[BUF];
		char *key = malloc_brk(0); // initialize to use brk with realloc
		int datalen = 0;
		char *keyend = 0;
		int r;
		
		// read key
		while ( keyend == 0 ){
			// (more) memory for the key
			// realloc won't copy any data, since malloc_brk is used.
			key = realloc(key,datalen+BUF); 
			r = read( 0, key+datalen, BUF );
			datalen = datalen + r;
			keyend = index( key, '\n' );
		}

		datalen--;
		int keylen = keyend - key ;
		eprintf("keylen: %d\ndatalen: %d\nkey: ",keylen,datalen);
		write(2,key,keylen);
		eprints("\n==\n");
		char *keypos = key;

		if ( keylen < datalen ){
			keypos = xor(key,key,keyend,keyend+1,datalen-keylen);
			write(1,keyend+1,datalen-keylen);
		}

		while ( r ){
			r=read( 0, buf, BUF );
			keypos = xor(key,keypos,keyend,buf,r);
			write(1,buf,r);
		}

		return(0);
}
