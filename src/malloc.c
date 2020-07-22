#ifndef mini_malloc_c
#define mini_malloc_c
//+header stdlib.h
//#include "../include/syscall.h"

//+include

#ifdef __NR_brk
#define BRK
#else
#ifdef SYS_brk
#define BRK
#endif
#endif

#include "include/minilib_global.h"
#include "include/utils.h"

//#include "mbuf.c"

#define MBUF_FREE 0x80000000
#define MALLOC_FREE MBUF_FREE
#define MBUF_FREEMASK 0x8FFFFFFF
#define MBUF_OCC 0x40000000

// at the end of the brk
#define MALLOC_BRK_END MBUF_OCC
// simple checksum whether a area is free or occupied.
// If neither nor, most possibly there's a problem.
#define MBUF_CHK 0xC0000000   

#define MBUF_PREVISFREE 0x20000000
#define MALLOC_PREVISFREE MBUF_PREVISFREE

// has been allocated with brk
#define MALLOC_BRK 0x10000000

// The size mask. 
// (maximum size is 268.435.455 Bytes.
#define MBUF_V 0xFFFFFFF
#define MALLOC_SIZE MBUF_V


//+todo alignment of malloc. ( align *p, and the bits at the beginning.)
// now its aligned to 4 Bytes.


//+doc
// Here we go.. with the .. well. 
// Fastes and smallest malloc/free combi ever. 
// Not the smartest.
// Since it isn't exactly a memory allocation,
// instead it (mis)uses the minilib buf.
// ;) 1024 Bytes should be enough for everyone.
//  Ok. If you really do need more memory - 
//  rethink your design, increase mini_mbuf,
//  or use a proper malloc implementation.
//
// Here we use mbuf from top to bottom as stack.
// 64 Bytes are left at the bottom as reserve.
// Possibly we'd like to complain
// about the lack of memory, before we exit..
//
// ATM, the 'free' is really lazy. 
// It free's memory, but a real 'free' is only commited,
// when all memory below a freed area is also freed.
// Since the target of minilib atm are tiny tools, 
// this might be ok.
// ;) but, as I told before - 
// probably you should look out for a proper malloc implementation.
// It depends on your needs.
//
// I'm not sure yet, 
// whether another implementation of free would be useful at all.
// Overall, I'd really prefer keeping minilib tiny.
//
// Reusing sparse freed memory areas also leads 
// to a whole bunch of complications.
// cache misses, searching complexity,
// storage overhead, potentially page faults,
// just to name a few.
//
// I'm not sure whether it's worth it.
//
// And the existing malloc implementations 
// out there are countless.
//
// ;) It's sometimes smarter to stay special,
// although in this case this means the opposite.
// /misc
//
// The memory layout looks like this:
// mlgl->ibuf and mlgl->mbuf do point to the same address range.
// mlgl->ibuf is provided for alignment and faster access to the int values.
//
// flag prev free is the first bit in size. (0x8000, eq 1000 0000 0000 0000 binary when free), 
// (mbufsize)
//      size  data  size    mini_buf size
//      8008dataxxxx0004data8000|
//      ----========----====----|
//
// also, when free space is in between two areas
// 
// 8004data8008  free  0004data8000|
// ----====----________----====----|
//
// the free space is only freed, 
// when all areas below (left) have been free'd as well.
//
// Memory is allocated from right to left, 
// meaning from top to down.
//
//+def
void* malloc(int size){
#ifndef mini_buf
#error malloc needs a defined mini_buf
#endif
		size = ((size-1) >> 2 ) + 2; // alignment and reserving space for the "pointer", 
																//  size is in integers (4Bytes)
		if( mlgl->mbufsize-(size<<2)<64 ){
				write( STDERR_FILENO, "Out of memory.\n",15 );
				return((void*)0);
		}

		mlgl->ibuf[(mlgl->mbufsize>>2)] = mlgl->ibuf[(mlgl->mbufsize>>2)] & MBUF_V; // clear flag prev_isfree
		mlgl->mbufsize -= (size<<2);
		mlgl->ibuf[(mlgl->mbufsize>>2)] = size;
		return( &mlgl->mbuf[mlgl->mbufsize+4] );
}


//+depends brk getbrk
//+def
void free(void *p){
		if ( p == 0 )
				return;

		char *c = p;
		int *i = p;
		i--; // point to the size of the block
		c-=4;
		
#ifdef mini_malloc_brk
		if ( i[0] & MALLOC_BRK ){

				if ( (long)(p+(i[0]&MALLOC_SIZE)) >= getbrk()  ){ // at the end of the data segment
						brk(i);
				} else {
				// not at the end
					i[0]=(i[0]|MALLOC_FREE);
					//i[ i[0]&MALLOC_SIZE // todo: free
				}

				return;
		}

#endif
	

		if ( &mlgl->mbuf[mlgl->mbufsize] == (char*)c ){ // at the bottom of the stack
				mlgl->mbufsize += (i[0] & MBUF_V) <<2;
				if ( mlgl->mbufsize == mini_buf )
						return;
				if ( mlgl->ibuf[mlgl->mbufsize>>2] & MBUF_FREE )
						mlgl->mbufsize += ( ( mlgl->ibuf[mlgl->mbufsize>>2] & MBUF_V ) << 2 );
				return;
		} else { // Not at the bottom
				if ( ( i[0] & MBUF_PREVISFREE )){ // prev area is free
						i[ - i[-1] -1 ] = ( ( i[ - i[-1] -1 ] + i[0] ) & MBUF_V ) | MBUF_FREE; // add this to prev.
						i = i - ( i[-1] + 1 );
				}
				// prev not free
				if ( (i[( i[0] & MBUF_V)] & MBUF_FREE) ){ // next area free
						i[0] = ((i[0] + i[( i[0] & MBUF_V)]) & MBUF_V) | MBUF_FREE; // add next to current. 
						// MBUF_FREE is already set. But for safety set it again. via mask 
						// adding MBUF_FREE twice wouldn't be that great
						i[( i[0] & MBUF_V) - 1 ] = ( i[0] & MBUF_V) - 1;
						return;
				} // prev area not free, next area not free
				i[( i[0] & MBUF_V) - 1 ] = ( i[0] & MBUF_V) - 1;
				i[( i[0] & MBUF_V)] = ( i[( i[0] & MBUF_V)] | MBUF_PREVISFREE ); 
				i[0] = i[0] | MBUF_FREE;
				return;

		} 

}

//+doc allocate via setting the brk
// free and realloc can be used normally.
// The intention of malloc_brk is for subsequent calls to realloc.
// The saved data has not to be copied,
// instead realloc just writes the new size and sets 
// the brk accordingly.
//+depends sbrk
//+def
void* malloc_brk(int size){
		if ( size<=0 )
				return(0);
		
		size = (((size-1) >> 2 ) + 2)<<2; // alignment and reserving space for the "pointer"(int)
		void *mem = sbrk(size);
		if ( mem <= 0 )
				return(0);


		int *i = mem;
		
		*i=( MALLOC_BRK | (size));
		//i = mem+size+4;
		//*i = MALLOC_BRK_END; // at the end
		i++;

		return(mem+4);
}



// TODO
// rewrite free and malloc.
// need to do some benchmarking.
// comparing different malloc implementations.
// again, it's a trade of speed and size.
// especially with realloc, the minimalistic implementation hurts

//+depends free malloc
//+def
void* realloc(void *p, int size){

		if ( size == 0 ){
				free(p);
				return((void*)0);
		}

		if ( p == 0 ){
				return(malloc(size)); // just alloc
		}



		char *c = p;
		int *i = p;
		i--;
		c-=4;
		int oldsize = (i[0] & MBUF_V); //<<2;
		
		size = (((size-1) >> 2 ) + 2)<<2; // alignment and reserving space for the "pointer"(int)

		if ( oldsize == size )
						return( p );

#ifdef mini_malloc_brk
		if ( *i & MALLOC_BRK ){ // has been allocated with malloc_brk
				//prints("hier\n");
				if ( (long)(p+oldsize) >= getbrk()  ){ // at the end of the data segment
				//prints("hier2\n");
						int ret = brk(c+size);
						if ( ret != 0 ){
								return(0);
						}
						*i = MALLOC_BRK | (size);
						return(p);
				}

		}
#endif

		if ( size < oldsize ){ // shrink. But can't free. so do nothing.
						//if ( &mlgl->mbuf[mlgl->mbufsize] == (char*)c ){ // at the bottom of the stack. 

		//mlgl->ibuf[(mlgl->mbufsize>>2)] = mlgl->ibuf[(mlgl->mbufsize>>2)] & MBUF_V; // clear flag prev_isfree
		//mlgl->mbufsize -= (size<<2);
		//mlgl->mbufsize += oldsize-size; // can't free. would need to copy the contents. 
		// I should rearrange to bottom to top layout.
		//mlgl->ibuf[(mlgl->mbufsize>>2)] = size;
		//return( &mlgl->mbuf[mlgl->mbufsize+4] ); 
						return(p); 
				} // if shrink.

			// enlarge
		if( mlgl->mbufsize-(size)+(oldsize<<2)<64 ){
				write( STDERR_FILENO, "Out of memory.\n",15 );
				free(p);
				return((void*)0);
		}
		free(p);
		int *s = (int*)p;
		void *n = malloc(size);
		if ( p > n ){
				//writes("p>n\n");
				for ( int *d = (int*)n; d<=(int*)((void*)n+(oldsize<<2)); d++ ){
						*d = *s;
						s++;
				}
		} else { // p<n
				//writes("p<n\n");
						int *s = (int*)n;
				for ( int *d = (int*)p; d<=(int*)((void*)p+(oldsize<<2)); d++ ){
						*d = *s;
						s++;
				}

		}


		return( n );
}

#if 0

POINTER* ml_brk=0;
extern POINTER _bssend;

////+def
void* volatile malloc(int size){
#ifdef undef
#warning BRK def
		int ret=1;
		mfprintf(stderr,"MALLOC: _bssend: %d\n",_bssend);
		if ( ml_brk == 0 ){
				ml_brk = _bssend;
				syscall1(ret,SCALL(brk),&ml_brk+size);
				if ( ret!=0 ){
						mfprintf(stderr,"MALLOC: 0\n");
						return(0);
				}
				ml_brk+=size;
				return((void*)_bssend);
		} else {
				syscall1(ret,SCALL(brk),size+ml_brk);
				if ( ret!=0 ){
						mfprintf(stderr,"MALLOC: 0\n");
						return(0);
				}
				int old_brk= ml_brk;
				ml_brk += size;
				return((void*)old_brk);
		}
#else 
#warning malloc SYSCALL
/*		void* ret;
		syscall6(ret, SCALL(mmap), 0, size, (0x01|0x02), 0x1002, -1, 0);
		//syscall6(ret, SCALL(mmap), 0, size, PROT_READ|PROT_WRITE, 0x1002, -1, 0);
		return((void*)ret);*/
#endif

		void* ret;
		size=4096;
	  register volatile long int r8 asm ("r8") = -1 ; 
		register volatile long int r9 asm ("r9") = 0; 
		register volatile long int r10 asm ("r10") = 0x1002; 
			asm volatile (
							//"xor %%r9, %%r9;"
							//"mov $-1, %%r8;"
							//"mov $0x1002, %%r10;"
							"syscall" 
							   : "=a" (ret) 
								 : "a" (SCALL(mmap) ) , "D" (0), "S" (size), "d" (0x01|0x02), "r" (r10), "r" (r8), "r" (r9) 
							   : "rcx", "memory" );
			return( (void*)ret );

}

////+def
void volatile free(void* p){

}




//malloc old
		//size = 4096;
/*	  register long int r8 asm ("r8") = -1 ; 
		register long int r9 asm ("r9") = 0; 
		register volatile long int r10 asm ("r10") = 0x1002; 
			asm volatile (
							//"xor %%r9, %%r9;"
							//"mov $-1, %%r8;"
							//"mov $0x1002, %%r10;"
							"syscall" 
							   : "=a" (ret) 
								 : "a" ( ( 197  | 0x2000000 ) ) , "D" (0), "S" (size), "d" (0x01|0x02), "r" (r10), "r" (r8), "r" (r9) 
							   : "ecx", "memory" );
	*/					
 /*
		asm volatile(
						"mov %p6, %%r9\n\t"
						"mov %p5, %%r8\n\t"
						"mov %p4, %%r10\n\t"
						"mov %p3, %%rdx\n\t"
						"mov %p2, %%rsi\n\t"
						"mov %p1, %%rdi\n\t"
						"mov $0x20000000, %%rax\n\t"
						"syscall\n\t"
						:"=a"(ret)
						:[p1]"m"(0),[p2]"m"(1024),[p3]"m"(0x01),[p4]"m"(0x0002),[p5]"m"(-1),[p6]"m"(0));*/
#endif



#endif
