#ifndef mini_malloc_c
#define mini_malloc_c
//+header stdlib.h
//#include "../include/syscall.h"

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
#define MBUF_FREEMASK 0x8FFFFFFF
#define MBUF_OCC 0x40000000
// simple checksum whether a area is free or occupied.
// If neither nor, most possibly there's a problem.
#define MBUF_CHK 0xC0000000   

#define MBUF_PREVISFREE 0x20000000
#define MBUF_V 0x1FFFFFFF


// Here we go.. with the .. well. 
// Fastes and smallest malloc/free combi ever. 
// Not the smartest.
// Since it isn't exactly a memory allocation,
// instead it (mis)uses the minilib buf.
// muahaha. 1024 Bytes should be enough for everyone.
//  Ok. If you really do need more memory - 
//  rethink your design, increase mini_mbuf,
//  or use a proper malloc implementation.
//
// Here we misuse mbuf from top to bottom as stack.
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
//
// I'm not sure yet, 
// whether a better implementation of free would be useful at all.
// Overall, I'd really prefer keeping minilib tiny.
//
// Reusing also sparse freed memory areas leads 
// to a whole bunch of complications.
// cache misses, searching complexity,
// storage overhead,
// just to name a few.
//
// I'm not sure whether it's worth it.
//
// And the existing malloc implementations 
// out there are countless.
//
// ;) It's sometimes smarter to stay special,
// although in this case this means the opposite.
//   ? I'm not sure what this sentence means XD
//misc
//
//+def
void* malloc(int size){
		size = ((size-1) >> 2 ) + 2; // alignment and reserving space for the "pointer"
		if( ml.mbufsize-(size<<2)<64 ){
				write( STDERR_FILENO, "Out of memory.\n",15 );
				return((void*)0);
		}

		ml.ibuf[(ml.mbufsize>>2)] = ml.ibuf[(ml.mbufsize>>2)] & MBUF_V; // clear flag prev_isfree
		ml.mbufsize -= (size<<2);
		ml.ibuf[(ml.mbufsize>>2)] = size;
		return( &ml.mbuf[ml.mbufsize+4] );
}


//+def
void free(void *p){
		if ( p == 0 )
				return;

		char *c = p;
		int *i = p;
		i--;
		c-=4;
		
		if ( &ml.mbuf[ml.mbufsize] == (char*)c ){ // at the bottom of the stack
				ml.mbufsize += (i[0] & MBUF_V) <<2;
				if ( ml.mbufsize == mini_buf )
						return;
				if ( ml.ibuf[ml.mbufsize>>2] & MBUF_FREE )
						ml.mbufsize += ( ( ml.ibuf[ml.mbufsize>>2] & MBUF_V ) << 2 );
				return;
				/*do {
						ml.mbufsize += mbuf[ml.mbufsize] +4;
						} while ( (ml.mbufsize < mini_buf ) && ( mbuf[ml.mbufsize] & MBUF_FREE ) );*/ // next area also free'd
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

							 /*	(int)c[ -(int)c[-4] ] = (int)c[ -(int)c[-4] ] + ( (int)c[0] & MBUF_V ) + ( (int)c[ ((int)c[0] & MBUF_V) ] & MBUF_V ); // add this and next area to prev area.
								(int)c[(int)c[ ((int)c[0] & MBUF_V)]-4] = (int)c[ -(int)c[-4] ] -4; // write combined free areas
								else { // next not free
										(int)c[ -(int)c[-4] ] += ( (int)c[0] & MBUF_V ); // add this area to prev area.
										(int)c[(int)c[0] & MBUF_V ] = (int)c[(int)c[0]&MBUF_V] | MBUF_PREVISFREE // mark next area 
												(int)c[(int)c[0]-4] = (int)c[ -(int)c[-4] ]-4; //write len of combined free areas there 
								}
						} else { //prev not free
								if ( (int)c[ (int)c[0] & MBUF_V ] & MBUF_FREE ){ // next free
										//mbuf[ (int)c[0]
								}
						}

				}*/
		
}

// TODO
// rewrite free and malloc.
// best would be storing the allocated length in the first byte.
// need to do some benchmarking.
// comparing different malloc implementations.
// again, it's a trade of speed and size.
// especially with realloc, the minimalistic implementation hurts

//+doc non conform realloc. Doesn't keep the old memory content(!)
//+depends free malloc
//+def
void* realloc(void *p, int size){
		free(p);
		return( malloc(size) );
}

#if 0

POINTER* ml_brk=0;
extern POINTER _bssend;

//+def
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

//+def
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
