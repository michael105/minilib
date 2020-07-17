#ifndef minilib_exit_h
#define minilib_exit_h
//+header unistd.h
//+inc

#ifdef mini_atexit

#ifdef X64
#define exit(ret) asm("jmp _atexit"::"D"(ret))
#define _exit(ret) asm("jmp __exit"::"D"(ret))
#else
#define exit(ret) asm("jmp _atexit"::"b"(ret))
#define _exit(ret) asm("jmp __exit"::"b"(ret))
#endif

#else
#ifdef X64
#define exit(ret) asm("jmp __exit"::"D"(ret))
#define _exit(ret) asm("jmp __exit"::"D"(ret))
#else
#define exit(ret) asm("jmp __exit"::"b"(ret))
#define _exit(ret) asm("jmp __exit"::"b"(ret))
#endif
#endif


//#else
/* inline void volatile __attribute__((always_inline)) exit( int ret ){
		//setup_syscall3(SYS_write,fd,(int)s,len);
	int r;
		syscall1(r,SCALL(exit),ret);
} */
//#endif

#endif
