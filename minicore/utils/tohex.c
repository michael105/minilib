#if 0
mini_start
mini_write 
mini_writes
mini_read

INCLUDESRC

return
#endif

#define BUF 4096

void usage(){
	writes("tohex. convert stdin to hexadecimal output.\n");
	exit(0);
}


char *table = "0123456789abcdef";

int main(int argc, char **argv){

		if ( argc>1 )
				usage();

		char c[BUF/2];
		char o[BUF];
		int r = 0;
		while ( (r=read(0,&c,BUF/2) ) > 0 ){
				for (int a=0; a<r; a++ ){
						o[a<<1]= table[ c[a]>>4 ];
						o[(a<<1)+1]= table[ c[a] & 0xf ];
				}
				write(1, o, r<<1 );
		}

		return(0);
}
