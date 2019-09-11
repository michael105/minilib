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
OPTFLAG 


return
#endif

//static unsigned char table[256];

#if 0
unsigned char* decompstack( unsigned char* table, 
				unsigned char *data, unsigned char* dataend,
				unsigned char *buf, unsigned char* bufend ){
		int *i;
		union {
				unsigned char d,c;
				short s;
		} u,u2;
		u.s=0;
		u2.s=0;
		do {
				if ( *data > 127 ){
						u.c = table[((*data-128)<<1)+1];
						printf("c: %d\n", u.s );
						printf("tb: %d\n", table[u.c] );
						asm volatile ("push %0" :"+g"(u.s));
						printf("cx: %d\n", u.s );
						printf("tb: %d\n", table[u.s] );
						asm volatile("pushw $0x1");
						printf("cx: %d\n", u.s );
						asm volatile ("popw %0" : "=g"(u.s) );
						printf("ccx: %d\n", u.s );
						asm volatile ("pop %0" : "=g"(u.s) );
						printf("ccx: %d\n", u.s );
						//asm volatile ("pushw 0xFF;\npush %0" ::"g"(table[((*data-128)<<1)+1]) );
						asm volatile ("pushw $0xFFFF;\npushw %0" :"+g"(u.s) );
					//	printf("c: %d\n", u.s );
						u.c = table[((*data-128)<<1)];
						printf("c: %d\n", u.s );
						do {
								if ( u.c <128 ){
										*buf = u.c;
										buf++;
										asm volatile("popw %0" : "=g"(u) );
								} else {
										u2.c = table[((u.c-128)<<1)+1];
										asm volatile("pushw %0" : "+g"(u2) );
										//asm volatile("push %0" :: "g"(table[((c-128)<<1)+1]) );
										u.c = table[((u.c-128)<<1)];
								}
						} while ( u.s != 0xFFFF );
				} else {
						*buf = *data;
						buf++;
				}
				data++;
		} while ( (data<=dataend) && ( buf<=bufend));
		return( buf );
}




// ~5% faster than not unrolled at all.
// ~68 Bytes more.
unsigned char* decompf( unsigned char* table, 
				unsigned char *data, unsigned char* dataend,
				unsigned char *buf, unsigned char* bufend ){
		do {
				if ( *data > 127 ){
						if ( table[(*data-128)<<1] <128 ){
								*buf=table[(*data-128)<<1];
								buf++;
								if ( table[((*data-128)<<1)+1] < 128 ){
										*buf=table[((*data-128)<<1)+1];
										buf++;
								} else {
										buf = decompf( table, table+((*data-128)<<1)+1, table+((*data-128)<<1)+1, 
												buf, bufend  );
								}
						} else {
										buf = decompf( table, table+((*data-128)<<1), table+((*data-128)<<1)+1, 
												buf, bufend  );
						}	
				} else {
						*buf = *data;
						buf++;
				}
				data++;
		} while ( (data<=dataend) && ( buf<=bufend));
		return( buf );
}

static unsigned char *stable;
static unsigned char *sbuf;
static unsigned char *sbufend;

static inline unsigned char* decomps2( unsigned char *data, unsigned char* data2 ){
		if ( *data > 127 ){
				sbuf = decomps2( stable+(unsigned char)(*data<<1), stable+((unsigned char)(*data<<1)+1) ); 
		} else {
				*sbuf = *data;
				if ( sbuf >= sbufend )
						return(sbuf);
				sbuf++;
		}
		if ( *data2 > 127 ){
				sbuf = decomps2( stable+(unsigned char)(*data2<<1), stable+((unsigned char)(*data2<<1)+1) ); 
		} else {
				*sbuf = *data2;
				if ( sbuf >= sbufend )
						return(sbuf);
				sbuf++;
		}
		return( sbuf );
}

// with decomps2 about 15% faster than decomp
unsigned char* decomps( unsigned char *data, unsigned char* dataend ){
		do {
				if ( *data > 127 ){
						sbuf = decomps2( stable+(unsigned char)(*data<<1), stable+((unsigned char)(*data<<1)+1) ); 
				} else {
						*sbuf = *data;
						sbuf++;
				}
				data++;
		} while ( (data<=dataend) && ( sbuf<=sbufend));
		return( sbuf );
}
#endif
#if 0
unsigned char* decompsm( unsigned char *data, unsigned char* dataend ){
		do {
				unsigned char c = *data;
				asm volatile(
								"salb %3;\n"
								"jnc store;\n"
								"mov %3, (%0)\n"
								"inc %0\n"
								"jmp loop;\n"
//						sbuf = decomps2( stable+c, stable+c+1); 
//						goto loop;
"sstore:\n"
"movb %2, (%0)\n"
"inc %0\n"
"sloop:\n"
:"+g"(sbuf),"+r"(data),"+r"(*data) : "r"(c)  );
				data++;
		} while ( (data<=dataend) && ( sbuf<=sbufend));
		return( sbuf );
}


unsigned char* decompasm( unsigned char *data, unsigned char* dataend ){
		do {
				unsigned char c = *data;
				asm volatile(
								"salb %0;\n"
								"jnc store;\n" : "+r"(c) );
						//sbuf = decomps2( stable+c, stable+c+1); 
						sbuf = decomps2( stable+(unsigned char)(*data<<1), stable+((unsigned char)(*data<<1)+1) ); 
				asm volatile ( 
"jmp loop\n"
"store:\n"
"movb %2, (%0)\n"
"inc %0\n"
"loop:\n"
:"+g"(sbuf),"+r"(data),"+r"(*data) : "r"(c)  );
				data++;
		} while ( (data<=dataend) && ( sbuf<=sbufend));
		return( sbuf );
}

#endif

#if 0

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

#endif
#if 0

// ok. 30% faster than decomp
// ~ 160 Bytes (mit Aufruf)
unsigned char* decompstacked( unsigned char* table, 
				unsigned char *data, unsigned char* dataend,
				unsigned char *buf, unsigned char* bufend ){
		unsigned char stack[64];
		unsigned char* stackp;
		stackp = stack;
		do {
				if ( *data > 127 ){
						stackp++;
						unsigned char c = table[(uchar)(*data<<1)]; 
						*stackp = table[(uchar)(*data<<1)+1];
						stackp++;
						//while ( stackp != stack ) {
			//			do{
loopst:
								if ( c > 127 ){
										*stackp = table[(uchar)(c<<1)+1];
										c= table[(uchar)(c<<1)];
										stackp++;
								} else {
										stackp--;
										*buf = c;
										if ( stackp == stack )
												goto out;
										c = *stackp;
										buf++;
								}
goto loopst;

				//		} while (1);//( stackp!=stack );

				} else {
						*buf = *data;
				}
out:
				data++;
				buf++;
		} while ( (data<=dataend) && ( buf<=bufend));
		return( buf );
}


// ok. 30% faster than decomp
unsigned char* decompstacked2( unsigned char* table, 
				unsigned char *data, unsigned char* dataend,
				unsigned char *buf, unsigned char* bufend ){

		unsigned char stack[64];
		register unsigned char* stackp = stack;
		register unsigned char c;

dataloop:
				if ( *data > 127 ){
						stackp++;
						c = table[(uchar)(*data<<1)]; 
						*stackp = table[(uchar)(*data<<1)+1];
loopst:
								if ( c > 127 ){
										stackp++;
										*stackp = table[(uchar)(c<<1)+1];
										c= table[(uchar)(c<<1)];
								} else {
										*buf = c;
										if ( stackp == stack )
												goto out;
										c = *stackp;
										buf++;
										stackp--;
								}
goto loopst;

				} else {
						*buf = *data;
				}
out:
				if ( data == dataend )
						return(buf);
				if ( buf >= bufend )
						return(buf);
				data++;
				buf++;
		goto dataloop;
}
#endif
#if 0
// ok. 30% faster than decomp
unsigned char* decompstacked5( unsigned char* table, 
				unsigned char *data, unsigned char* dataend,
				unsigned char *buf, unsigned char* bufend ){

		unsigned char stack[64];
		register unsigned char* stackp = stack;
		register unsigned char c;
		volatile register unsigned char d asm("dl");

		goto dataloop;

//asm volatile ("lp:\n");
L1:
					//d=d<<1;
					stackp++;
					c = table[d]; 
					*stackp = table[d+1];
loopst:  // unroll
					if ( c & 0x80 ){
							d = c<<1;
							stackp[1] = table[d+1];
							c= table[d];
							stackp++;
					} else {
							*buf = c;
							if ( stackp == stack )
									goto out;
							c = *stackp;
							buf++;
							stackp--;
					}

					goto loopst;


dataloop: __attribute__((hot))
					d = *data;
					//if ( *data & 0x80 )
							//goto lp;
					asm volatile goto (
								//	"mov %0, %%dl\n"
									"salb %%dl\n"
									"jc %l0\n"
									::::L1);
					*buf = *data;
//					goto lp;
out:
					if ( (data == dataend) || ( buf>=bufend) )
							goto retf;
					data++;
					buf++;
					goto dataloop;

retf:__attribute__((cold))
				 return(buf);
}
#endif

#if 0

// ok. 30% faster than decomp
unsigned char* decompstacked4( unsigned char* table, 
				unsigned char *data, unsigned char* dataend,
				unsigned char *buf, unsigned char* bufend ){

		unsigned char stack[64];
		register unsigned char* stackp = stack;
		register unsigned char c;
		register unsigned char d;
//		uint c1=0;
//		uint c2=0;
//		uint c3=0;

dataloop: __attribute__((hot))
							//d = *data;
					if ( *data & 0x80 ){ // > 127
							c = *data<<1;

loopst:__attribute__((hot));  // unroll possible

							stackp[1] = table[c+1];
							c= table[c];
							stackp++;

							while( c<128 ) {
									*buf = c;
									if ( stackp == stack )
											goto out;
									c = *stackp;
									buf++;
									stackp--;
									//if ( buf > bufend ) goto retf1; // not neccessarily needed, when keeping a few safety bytes above bufend
							}
							c=c<<1; //comment shift
	goto loopst;

					} else {
							*buf = *data;
					}
out:__attribute__((cold))
					if ( (data == dataend) || ( buf>=bufend) )
							goto retf;
					data++;
					buf++;
					goto dataloop;

retf:__attribute__((cold))
				 //printf("c1: %u    c2:   %u    c3:  %u\n",c1,c2,c3);
				 return(buf);
}
#endif


// ok. 40% faster than decomp
// 1.05 seconds / 160MB
unsigned char* decompstacked42( unsigned char* table, 
				unsigned char *data, unsigned char* dataend,
				unsigned char *buf, unsigned char* bufend ){

		unsigned char stack[64];
		register unsigned char* stackp = stack;
		//register int stackp = 0;
		register unsigned char c;
		register unsigned char d;
		uint c1=0;
		uint c2=0;
		uint c3=0;
		uint c4=0;

dataloop: __attribute__((hot)) //dataloop label
							//d = *data;
					if ( *data & 0x80 ){ // > 127
							d = *data<<1;

loopst:__attribute__((hot));  // unroll possible. loopst label

							c = table[d]; // loopst 1. cmd
						//	d = table[d+1];
							//c2++;
							asm ("nop\n" 
											: "+g"(buf) : "r"(c), "r"(d), "g"(table) : );
							if ( c & 0x80 ){
									stackp[1] = table[d+1];
									stackp++;
									d=c<<1;
									goto loopst; // loopst
							} 
							d = table[d+1];
							*buf = c;
							buf++;
							while ( d<128 ){ // inner while
									*buf = d;
									if ( stackp==stack )
											goto out; // goto out
									d=*stackp;
									buf++;
									stackp--;
							} 
							d=d<<1;

							//c=c<<1; //comment shift
	goto loopst; //loopst

					} 
					//c3++;
					*buf = *data;
				
out:__attribute__((hot)) // out label
					if ( (data == dataend) || ( buf>=bufend) )
							goto retf; //retf
					//c4++;
					data++;
					buf++;

					goto dataloop; //dataloop

retf:__attribute__((cold))
				 //printf("c1: %u    c2:   %u    c3:  %u    c4   %u\n",c1,c2,c3,c4);
				 return(buf);
}

// ~ 112 bytes
// ~1.8 seconds (160MB)
unsigned char* decomp( unsigned char* table, 
				unsigned char *data, unsigned char* dataend,
				unsigned char *buf, unsigned char* bufend ){
		do {
				if ( *data > 127 ){
						buf = decomp( table, table+(unsigned char)(*data<<1), table+((unsigned char)(*data<<1)+1), 
										buf, bufend  );
				} else {
						*buf = *data;
						buf++;
				}
				data++;
		} while ( (data<=dataend) && ( buf<=bufend));
		return( buf );
}




int main( int argc, char *argv[] ){
	//	write(STDOUT_FILENO,"Hallo\n",6);

		int fd = open( argv[1], O_RDONLY );
		if ( fd<0 ){
				write(STDERR_FILENO, "Error. Couldn't open Arg1.\n", 27 );
				exit(1);
		}
		unsigned char buf[4096];
		unsigned char out[4096];
		unsigned char ct[256];
		int r = read( fd, (POINTER*) ct, 256 );
		printf("Got: %d\n", r );

	//	stable = ct;
	//	sbuf = out;
	//	sbufend = out+4095;
/*		short int *p = (short int*)&stable[4];
		printf("int: %d\n", (char)ct[4] );
		printf("int: %d\n", (int)ct[4] );
		printf("int: %d\n", *p );
		printf("int: %d\n", (char)*p );*/
		//return(0);

		r = read( fd, (POINTER*)buf, 4096 );
		printf("Got: %d\n", r );
		int i = 0;
	  	for ( int a = 0; a<40000; a++ ){
			//unsigned char *c =  decompstacked42( ct, buf, buf+r, out, out+4000 );
			uchar *c =  decomp( ct, buf, buf+r, out, out+4000 );
							//buf, buf+r, out, out+4095 );
		//		sbuf = out;
//				uchar *c = decomps( buf, buf+r );
		 i = (c-out);
			//c =  decompstacked2( ct, buf, buf+r, out, out+4095 );
				printf(" r %d\n",i ); 
	 	//write(STDERR_FILENO, out, i );
		}

	 	write(STDERR_FILENO, out, i );
	 	write(STDERR_FILENO, "\n\n", 2 );
		
		//printf("Bytes decompressed: %d\n", r );
		//decomp_toF( stderr, ct, buf, 0, 2048 );
		return(0);
}
