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
	
static int brk=0;

void* malloc(POINTER size){
		POINTER ret;
#ifdef BRK	
		if ( brk == 0 ){
				syscall1(ret,SCALL(brk),0);
		} else {
				ret=brk;
		}
		syscall1(brk,SCALL(brk),size+ret);
		return((void*)ret);
#else 
//#todo: doesnt ork at all
//		syscall6(ret, SCALL(mmap), 0, size, PROT_READ|PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
		//size = 4096;
	  register long int r8 asm ("r8") = -1 ; 
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
		return((void*)ret);
#endif
}


