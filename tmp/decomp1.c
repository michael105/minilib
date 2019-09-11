#if 0
mini_printf
mini_itodec
mini_puts
mini_putc
mini_buf 4096
mini_open
mini_prints
mini_read
mini_write
mini_start
INCLUDESRC



return
#endif


int decomp( const unsigned char* table, const unsigned char *from, 
				unsigned char *buf, int fp, int fpmax, int bp, int bpmax ){
		do {
				if ( from[fp] > 127 ){
						bp = decomp( table, table, buf, 
										( from[fp]-128)*2, ( from[fp]-128)*2 +2, bp, bpmax );
				} else {
						buf[bp] = from[fp];
						bp++;
				}
				fp++;
		} while ( (fp<fpmax) && ( bp<bpmax));
		return( bp );
}


void decomp_toF( FILE *F, const unsigned char* table, 
				const unsigned char *from, int fp, int fpmax ){
		do {
				if ( from[fp] > 127 ){
						decomp_toF( F, table, table, 
										( from[fp]-128)*2, ( from[fp]-128)*2 +2  );
				} else {
						putc(from[fp], F);
				}
				fp++;
		} while (fp<fpmax);
}



int main( int argc, char *argv[] ){
	//	write(STDOUT_FILENO,"Hallo\n",6);

		int fd = open( argv[1], O_RDONLY );
		if ( fd<0 ){
				write(STDERR_FILENO, "Error. Couldn't open Arg1.\n", 27 );
				exit(1);
		}
		unsigned char buf[8192];
		unsigned char out[32768];
		unsigned char ct[256];
		int r = read( fd, (POINTER*) ct, 256 );
		printf("Got: %d\n", r );

		r = read( fd, (POINTER*)buf, 8192 );
		printf("Got: %d\n", r );

		for ( int a = 0; a<20000; a++ ){
			int i = decomp( ct, buf, out, 0, r, 0, 4096 );
		printf("Got: r %d\n",i ); 
		}

		//printf("Bytes decompressed: %d\n", r );
		//decomp_toF( stderr, ct, buf, 0, 2048 );
		return(0);
}
