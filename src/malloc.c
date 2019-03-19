//+ansi stdlib.h
//#include "../include/syscall.h"

#ifdef __NR_brk
#define BRK
#else
#ifdef SYS_brk
#define BRK
#endif
#endif

#include "include/utils.h"

#include "mbuf.c"

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
// 128 Bytes are left at the bottom as reserve.
// Possibly we'd like to print out a complainment
// about no memory, before we exit..
//
//+def
void* malloc(int size){
		if ( mbufsize == 0 ){
				mbufsize = mini_buf;
		}
		size += 4;
		if( mbufsize<size ){
				warn( "Out of memory." );
				return((void*)0);
		}

		mbufsize -= size;
		mbuf[mbufsize] = size;
		return( &mbuf[mbufsize+4] );
}

//+def
void free(void *p){
}

#define MBUF_FREE 0x80000000
#define MBUF_PREVISFREE 0x40000000

#if 0
//+def
void free(void *p){
		char *c = p;
		c-=4;
		
		if ( &mbuf[mbufsize] == (char*)c[0] ){ // at the bottom of the stack
				mbufsize += mbuf[mbufsize];
				if ( mbufsize == mini_buf )
						return;
				if ( (int)mbuf[mbufsize] & MBUF_FREE )
						mbufsize += ( (int)mbuf[mbufsize] & 0x3FFFFFFF );
				return;
				/*do {
						mbufsize += mbuf[mbufsize] +4;
				} while ( (mbufsize < mini_buf ) && ( mbuf[mbufsize] & MBUF_FREE ) );*/ // next area also free'd
		} else { 
				if ( (int)c[0] & MBUF_PREVISFREE ){ // prev area already free'd
						c = &mbuf[ (int)c[-4] 

		}
}

//#if 0

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
