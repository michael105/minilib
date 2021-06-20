#ifndef minilib_exit_h
#define minilib_exit_h
//+header unistd.h
//+inc


#ifdef mini_atexit

#ifdef X64
#define exit(ret) asm("jmp _atexit"::"D"(ret))
static inline void __attribute__((noreturn))_exit(int ret){
	asm("jmp __exit"::"D"(ret));
	__builtin_unreachable();
}
#else
#define exit(ret) asm("jmp _atexit"::"b"(ret))
#define _exit(ret) asm("jmp __exit"::"b"(ret))
#endif

#else
#ifdef X64
static inline void __attribute__((noreturn))exit(int ret){
	asm("jmp __exit"::"D"(ret));
	__builtin_unreachable();
}
static inline void __attribute__((noreturn))_exit(int ret){
	asm("jmp __exit"::"D"(ret));
	__builtin_unreachable();
}
#else
#define exit(ret) asm("jmp __exit"::"b"(ret))
#define _exit(ret) asm("jmp __exit"::"b"(ret))
#endif
#endif


#endif
