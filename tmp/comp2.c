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
mini_fwrites
mini_start
mini_errno
mini_memset
INCLUDESRC



return
#endif

// Buf ~ 8 MB
#define BUF 8000000

int comp( unsigned char* data, int len, FILE *F ){
		union {
				long l[(256*256*sizeof(short))/sizeof(long)];
				unsigned short int k[256][256];
		} k;
		unsigned char ct[256];
		int saved = 0;
		unsigned char prev = 0;

		for ( int a = 128; a<256; a++ ){
				int diff = 0;
				//memset( k, 0, 256*256 * sizeof(short int) );
				for ( int i = 0; i<(256*256*sizeof(short int))/sizeof(long);i++)
						k.l[i] = 0;
				//printf("a1: %d\n",a);
				for ( int b = 0; b<len-1; b++ ){
						unsigned char c1 = data[b];
						int p = b+1;
						if ( (c1 == prev) && ( prev == data[p]) ){
								prev = 0;
						} else {
								if ( k.k[c1][data[p]] == 0 )
										diff++;
								k.k[c1][data[p]] = k.k[c1][data[p]] + 1;
								prev = c1;
						}
				}
				int count = 0;
				for ( int i1 =0; i1<256; i1++ ){
						for ( int i2 =0; i2<256; i2++ ){
								if ( k.k[i1][i2] > 0 ){
										//printf("k: %c%c - %d\n", i1, i2, k[i1][i2] );
										if ( k.k[i1][i2] > count ){
												count = k.k[i1][i2];
												ct[(a-128)*2] = i1;
												ct[(a-128)*2+1] = i2;
										}
								}
						}
				}
				int p = 1;
				int b = 0;
				for ( b = 0; p<len; b++ ){
						if ( (data[b] == ct[(a-128)*2]) && ( data[p] == ct[(a-128)*2+1] ) ){
								p++;
								data[b] = a;
								saved++;
						}
						data[b+1] = data[p];
						p++;
				}
				if ( (b+1)<p )
				len = b+1;

				fprintf(stderr, "diff: %d\n", diff );
			 	fprintf(stderr, "a: %d\ncount: %d =  -%3d-%3d-\nsaved: %d\n",a, count, ct[(a-128)*2], ct[(a-128)*2+1], saved);
		}
		fprintf(stderr,"Saved: %d\n",saved);
//		ct[254] = 'X';
//		ct[255] = '\n';
		//ct[256] = 0;
		write( fileno(F), (char*)ct, 256 ); 

		int newlen = len-1;
#if 0
		for ( int a=0; a<len; a++ ){
				if ( data[a] != 255 ){
						fputc( data[a], F );
						newlen++;
				}
		}
//#else
		int a=0;
		int b=0;
		do {
				while ( (b<len) && (data[b] == 255 ) )
						b++;
				if ( b<len ){
						data[a] = data[b];
						newlen = a;
				}
				a++;
				b++;
		} while ( b<len );
		write( fileno(F), data, newlen+1 );
#endif
		write( fileno(F), data, newlen );
		fprintf(stderr,"newlen: %d\n", newlen );
		return(newlen);
}


int main( int argc, char *argv[] ){
		unsigned char in[BUF];
		int r;

		int fd = open( argv[1], O_RDONLY ); 
		int fdout = STDOUT_FILENO;

		r = read( fd, (POINTER*)in, BUF );
		fprintf(stderr,"Got: %d\nerrno: %d\n", r, errno );
		while (r>0) {
				for ( int a=0; a<r; a++ ){
						if ( in[a] > 127 ){
								fwrites(STDERR_FILENO, "Error. Input contained char > 127\n");
								exit(1);
						}
						if ( in[a] == 0 ){
								//fwrites(STDERR_FILENO, "Error. Input contained char == 0\n");
								//exit(1);
						}

				}
				comp( in, r, stdout );
				r = read( fd, (POINTER*)in, BUF );
		};





		return(0);
}
