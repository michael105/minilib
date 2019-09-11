#if 0
mini_printf
mini_itodec
mini_itoHEX
mini_puts
mini_putc
mini_buf 4096
mini_open
mini_fopen
mini_prints
mini_read
mini_write
mini_fwrites
mini_start
mini_errno
mini_memset
INCLUDESRC
OPTFLAG


return
#endif

// Buf ~ 8 MB
#define BUF 8000000

int comp( unsigned char* data, int len, FILE *F ){
		union {
				long l[(256*256*sizeof(short))/sizeof(long)];
				unsigned
				short int k[256][256];
		} k;
		unsigned char ct[256];
		int saved = 0;
		unsigned char prev = 0xFF;


		int diff = 0;
		//memset( k, 0, 256*256 * sizeof(short int) );
		for ( long *l = (long*)(k.k[0]); l<(long*)(k.k[255]+255);l++){
				*l= 0; // set k to 0. l+1 means l=l+8 here. or which size a long has.
		}


		for ( int b = 0; b<len-1; b++ ){
				unsigned char c1 = data[b];
				int p = b+1;
				if ( (c1 == prev) && ( prev == data[p]) ){
						prev = 0xFF;
				} else {
						if ( k.k[c1][data[p]] == 0 )
								diff++;
						k.k[c1][data[p]] = k.k[c1][data[p]] + 1;
						prev = c1;
				}
		}
		fprintf(stderr, "different pairs: %d\n", diff );
		fprintf(stderr, "count 0,0: %u\n", (ushort)k.k[0][0] );


		saved = 10;
		for ( int a = 128; (a<256) && (saved>2); a++ ){

				saved=0;
				for ( int i=0; i<32; i++ ) fprintf(stderr, " %2X", data[i] ); fprintf(stderr,"\n");

				prev=0xff;
				unsigned short int count = 0;
				for ( int i1 =0; i1<a; i1++ ){
						for ( int i2 =0; i2<a; i2++ ){
								if ( (ushort)k.k[i1][i2] > (ushort)count ){
										count = (ushort)k.k[i1][i2];
										ct[(a-128)*2] = i1;
										ct[(a-128)*2+1] = i2;
								}
						}
				}
				int p = 1;
				int b = 0;
				for ( b = 0; p<len; b++ ){
						if ( (data[b] == ct[(a-128)*2]) && ( data[p] == ct[(a-128)*2+1] ) ){
								if ( b>0 ){

										if ( prev != a ){
												if ( (ushort)k.k[data[b-1]][a] < (ushort)((ushort)0-1) )
														(ushort)k.k[data[b-1]][a]++;
												prev=data[b-1];
										} else {
												prev=0xff;
										}

										if((ushort)k.k[data[b-1]][data[b]]>0)
												(ushort)k.k[data[b-1]][data[b]]--;
								}
								if ( p < len ){

										if ( (ushort)k.k[data[p]][data[p+1]]  > 0 )
												(ushort)k.k[data[p]][data[p+1]] --;

										if ( (ushort)k.k[a][data[p+1]] < (ushort)((ushort)0-1) )
												(ushort)k.k[a][data[p+1]]++;
								}

								p++;
								data[b] = a;
								saved++;
						}
						//if ( p>(b+1) )
						data[b+1] = data[p]; // copy 
						p++;
				}

				fprintf(stderr,"p: %u   b:  %u    len:  %u\n", p,b,len );
				k.k[ct[(a-128)*2]][ct[(a-128)*2+1]] = 0;
				for ( int i=0; i<32; i++ ) fprintf(stderr, " %2X", data[i] ); fprintf(stderr,"\n");
				len = len-saved;
				fprintf(stderr,"p: %u   b:  %u    len:  %u\n", p,b,len );

				//fprintf(stderr, "diff: %d\n", diff );
				fprintf(stderr, "a: %X\ncount: %d =  -%2X-%2X-\nsaved: %d\n\n*********\n",a, (ushort)count, ct[(a-128)*2], ct[(a-128)*2+1], saved);
		}

		fprintf(stderr,"Saved: %d\n",saved);

		write( fileno(F), (char*)ct, 256 ); 

		int newlen = len;

		write( fileno(F), data, newlen );
		fprintf(stderr,"newlen: %d\n", newlen );
		return(newlen);
}


int main( int argc, char *argv[] ){
		unsigned char in[BUF];
		int r;

		int fd = open( argv[1], O_RDONLY ); 
		//int fdout = STDOUT_FILENO;

		r = read( fd, (POINTER*)in, BUF );
		fprintf(stderr,"Got: %d\nerrno: %d\n", r, errno );

		FILE  *FOUT;
		FOUT  = fopen( argv[2], "w" );
		if ( FOUT == NULL ){
				fprintf(stderr,"Error: Couldn't open %s for writing.\nerrno: %d\n", argv[2], errno );
		}

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
				comp( in, r, FOUT );
				r = read( fd, (POINTER*)in, BUF );
		};





		return(0);
}
