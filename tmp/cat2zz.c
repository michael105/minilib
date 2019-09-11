#if 0
mini_fprints
mini_fwrites
mini_buf 1024
mini_open
mini_read
mini_write
mini_start
#mini_errno
INCLUDESRC
OPTFLAG -Os
shrinkelf


return
#endif

// Buf 4 MB
#define BUF 0x400000

int comp( unsigned char* data, int len, int fd ){

		unsigned short int k[256][256];
		unsigned char ct[256];
		unsigned char prev = 0xFF;

		//memset( k, 0, 256*256 * sizeof(short int) );
		for ( long *l = (long*)(k[0]); l<(long*)(k[255]+255);l++){
				*l= 0; // set k to 0. l+1 means l=l+8 here. or which size a long has.
		}

		// count different pairs
		// 'AAA' count as 1, 'AAAA' as 2
		for ( int b = 0; b<len-1; b++ ){
				unsigned char c1 = data[b];
				int p = b+1;
				if ( (c1 == prev) && ( prev == data[p]) ){
						prev = 0xFF;
				} else {
						k[c1][data[p]] = k[c1][data[p]] + 1;
						if ( c1 == data[p] )
								prev = c1;
						else
								prev=0xff;
				}
		}

		int saved = 3;
		int chr;
		for ( chr = 128; (chr<256) && (saved>2); chr++ ){

				saved=0;
				prev=0xff;
				unsigned short int count = 0;

				for ( int i1 =0; i1<chr; i1++ ){
						for ( int i2 =0; i2<chr; i2++ ){
								if ( (ushort)k[i1][i2] > (ushort)count ){
										count = (ushort)k[i1][i2];
										ct[(chr-128)*2] = i1;
										//ct[(uchar)(chr<<1)] = i1;
										//ct[(uchar)(chr<<1)+1] = i2;
										ct[(chr-128)*2+1] = i2;
								}
						}
				}
				int p = 1;
				int b = 0;
				for ( b = 0; p<len; b++ ){
						if ( (data[b] == ct[(chr-128)*2]) && ( data[p] == ct[(chr-128)*2+1] ) ){
						//if ( (data[b] == ct[(uchar)(chr<<1)]) && ( data[p] == ct[(uchar)(chr<<1)+1] ) ){
								if ( b>0 ){

										if ( prev != chr ){
												if ( (ushort)k[data[b-1]][chr] < (ushort)((ushort)0-1) )
														(ushort)k[data[b-1]][chr]++;
												prev=data[b-1];
										} else {
												prev=0xff;
										}

										if((ushort)k[data[b-1]][data[b]]>0)
												(ushort)k[data[b-1]][data[b]]--;
								}
								if ( p < len ){

										if ( (ushort)k[data[p]][data[p+1]]  > 0 )
												(ushort)k[data[p]][data[p+1]] --;

										if ( (ushort)k[chr][data[p+1]] < (ushort)((ushort)0-1) )
												(ushort)k[chr][data[p+1]]++;
								}

								p++;
								data[b] = chr;
								saved++;
						}
						//if ( p>(b+1) )
						data[b+1] = data[p]; // copy 
						p++;
				}

				k[ct[(chr-128)*2]][ct[(chr-128)*2+1]] = 0;
				len = len-saved;

				//fprintf(stderr, "diff: %d\n", diff );
				//fprintf(stderr, "a: %X\ncount: %d =  -%2X-%2X-\nsaved: %d\n\n*********\n",a, (ushort)count, ct[(a-128)*2], ct[(a-128)*2+1], saved);
		}

	//	chr--;

		chr-=128;
	 //	write( fd, "\xc2", 1 );
		write( fd, &chr, 1 );
		write( fd, (char*)ct, chr*2 ); 

		write( fd, data, len );

//		fprintf(stderr,"newlen: %d,chr: %X, table len(*2): %d\n", len,chr,c );
		return(len);
}


int main( int argc, char *argv[] ){
		unsigned char in[BUF];
		int r;

		int fd = open( argv[1], O_RDONLY ); 
		//int fdout = STDOUT_FILENO;

		r = read( fd, (POINTER*)in, BUF );
		//fprintf(stderr,"Got: %d\nerrno: %d\n", r, errno );

		//FILE  *FOUT;
		//FOUT  = fopen( argv[2], "w" );
		int fdout;
		fdout  = open( argv[2], O_WRONLY|O_CREAT|O_TRUNC );
		if ( fdout <=0 ){
				fprints(stderr,"Error: Couldn't open "); fprints( stderr,argv[2] );fprints(stderr, "for writing\n" );
		}

		while (r>0) {
				for ( int a=0; a<r; a++ ){
						if ( in[a] > 127 ){
								fwrites(STDERR_FILENO, "Error. Input contained char > 127\n");
								exit(1);
						}
				}
				comp( in, r, fdout );
				r = read( fd, (POINTER*)in, BUF );
		};
		close(fdout);

		return(0);
}
