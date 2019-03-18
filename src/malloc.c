//+ansi stdlib.h
// just malloc. no free yet.
//#include "../include/syscall.h"

//bad bad and doesnt ork
#ifndef SYS_brk
//#define SYS_brk 69
#endif

#ifdef __NR_brk
#define BRK
#else
#ifdef SYS_brk
#define BRK
#endif
#endif


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

