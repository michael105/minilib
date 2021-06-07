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

mini_sleep
mini_getchar

INCLUDESRC
LDSCRIPT text_and_bss
STRIPFLAG
OPTFLAG -O0

return
#endif

// this allocates heapspace via mmap,
// which is accounted as "stack" by the kernel.
// strangely, the memory consumption doesn't show up
// via free / ps ???
// the allocated "stack" has to be available, 
// the default setting (ulimit) is 8MB here.

extern unsigned long _end;

int main(int argc, char **argv){
		

		printf("Ok\n");
		printf("to end: %ld\n",_end);

		long int r=0;
		unsigned long *memstart;
		r = (ulong)sbrk(0);
		memstart = (ulong*)r;
		printf("r: %ld\n",r);
		r = (ulong)sbrk(32);
		printf("r: %ld\n",r);
		r = (ulong)sbrk(0);
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
		printf("m2: %ld\n",m2);
		printf("m-m2: %ld\n",m-m2);
		char *c = m2;
		
		for ( int a = 0; a<8; a++ ){
				printf("a: %d, addr: %ld\n",a,c);
				*c=a;
				c+=1024;
				//m2+=4;
		}
		getchar();

		void* m3 = mmap(0,64, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE | MAP_GROWSDOWN, 0, 0 );
		printf("m3: %ld\n",m3);
		printf("m2-m3: %ld\n",m2-m3);
		c = m2;
			

		getchar();

		for ( int a = 0; a<16; a++ ){
				printf("a: %d, addr: %ld\n",a,c);
				*c=a;
				c-=1024;
				//m2+=4;
		}

		c = m2;

		getchar();

		for ( int a = 0; a<256; a++ ){
				printf("a: %d, addr: %ld\n",a,c);
				*c=a;
				c-=(1<<21); // 2MB
				//m2+=4;
		}
		char *bottom = c+(1<<21);

		for ( int a = 0; a<256; a++ ){
				c+=(1<<21); // 2MB
				printf("a: %d, *c: %d, addr: %ld\n",a,*(int*)c,c);
				//m2+=4;
		}


		getchar();


		for ( int a = 0; a<=128000; a++ ){
				*bottom = a;
				bottom++;
		}

		getchar();

		return(0);
}

