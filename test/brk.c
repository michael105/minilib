#if 0
mini_start
mini_buf 256
mini_printf
mini_prints
mini_itodec
mini_ltodec
mini_itohex

mini_mmap
mini_brk
mini_sbrk
mini_memcpy

INCLUDESRC
LDSCRIPT text_and_bss
STRIPFLAG
OPTFLAG -Os

return
#endif

extern unsigned long _end;

int main(int argc, char **argv){
		

		printf("Ok\n");
		printf("to end: %ld\n",_end);
		printf("hmm end: %x\n",134517936);

		long int r=0;
		unsigned long *memstart;
		r = sbrk(0);
		memstart = r;
		printf("r: %ld\n",r);
		r = sbrk(32);
		printf("r: %ld\n",r);
		r = sbrk(0);
		printf("r: %ld\n",r);


		for( int a=0; a<8; a++ ){
				printf("a: %d\n",a);
				*memstart = a;
				memstart+=32;
		}

		void* m = mmap(0,0, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0 );

		printf("m: %ld\n",m);


		m = mmap(0,64, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0 );
		printf("m: %ld\n",m);

		void* m2 = mmap(0,64, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, 0, 0 );
		printf("m: %ld\n",m2);
		printf("m-m2: %ld\n",m-m2);
		char *c = m2;
		
		for ( int a = 0; a<5000; a+=256 ){
				printf("a: %d\n",a);
				c[a] = a;
				//m2+=4;
		}


		return(0);
}

