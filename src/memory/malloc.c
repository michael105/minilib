#ifndef mini_malloc_c
#define mini_malloc_c
//+header stdlib.h

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

static int brk( const void* addr );
static void* sbrk( long incr );
static long getbrk();

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
// instead it uses the minilib buf.
// Which is allocated by the kernel, and located
// either in the bss section, or is allocated on the stack.
// (option "globals_on_stack")
// When allocated at the stack, the stack is first expanded
// within startup_c.c, and the return address of startup_c
// discarded. (Jump to exit)
// Therefore an overflow of the globals would result in a segfault.
//
// For debugging and analization of mallocs and free's, there's 
// the option analyzemalloc; which dumps all malloc's and free's to stderr.
// Format: Address - size)
//
// This is basically a linked list,
// optimized for fast access, allocation of new elements, 
// and small memory overhead.
// Albite the list structure might be hard to recognize.
// It is not the right malloc, if you expect
// many de- or reallocations.
// And it obviously is not the right choose, when
// expecting medium to big sized allocations. (> 1 page, here 4kB, as medium sized)
// 
// Here we use mbuf from top to bottom as stack.
// 64 Bytes are left at the bottom as reserve.
// Possibly we'd like to complain
// about the lack of memory, before we exit.
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
// albite in this case this means the opposite.
// /misc
//
// The memory layout looks like this:
// mlgl->ibuf and mlgl->mbuf do point to the same address range.
// mlgl->ibuf is provided for alignment and faster access to the int values.
//
// flag prev free is the first bit in size. (0x8000, eq 1000 0000 0000 0000 binary when free), 
// (mbufsize)
// ```
//      size  data  size    mini_buf size
//      8008dataxxxx0004data8000|
//      ----========----====----|
//
// also, when free space is in between two areas
// 
// 8004data8008  free  0004data8000|
// ----====----________----====----|
//
// ```
// the free space is only freed, 
// when all areas below (left) have been free'd as well.
//
// Memory is allocated from right to left, 
// meaning from top to down.
//+depends
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
#ifdef analyzemalloc
		fprintf(stderr, "malloc: %x - %d - mbufsize: %d\n",&mlgl->mbuf[mlgl->mbufsize+4],size,mlgl->mbufsize);
#endif
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
#ifdef analyzemalloc
		fprintf(stderr, "free_brk: %x - %d\n",p,i[0]&MALLOC_SIZE);
#endif

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

#ifdef analyzemalloc
		fprintf(stderr, "free: %lx - %d\n",p,i[0]&MALLOC_SIZE);
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
		int *s = (int*)p;
		void *n = malloc(size);
		if ( p > n ){
				//writes("p>n\n"); // todo: replace with memcpy / copy longs
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

		free(p);
		return( n );
}



#endif
