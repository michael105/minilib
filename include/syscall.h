#ifndef minilib_syscall_h
#define minilib_syscall_h

#ifdef mini_vsyscalls
extern int __mini_vsys;
#endif


//extern int sysret;
#ifdef mini_errno
#ifndef mini_globals_on_stack
extern int errno;
#endif
#endif

#ifdef OSX

#define NCONST 0x2000000
#define SCALL(call) SYS_##call
#define __SYSCALL(call) SYS##call
#include <sys/syscall.h>

#else

#define NCONST 0
#define SCALL(call) __NR_##call
#define __SYSCALL(call) __NR##call

#ifdef X64
#include <sys/syscall.h>
#else
#include "i386syscalls.h"
#endif

#endif


// syscall table at: /usr/src/linux/include/linux/syscalls.h. 
// table, ordered: /usr/src/linux/arch/x86/syscalls/syscall_32.tbl

// defining sycalls as static inline has these advantages:
// -not compiled, if not used
// -optimization can take place, gcc (4.4.5, at least) doesn't use the stack at all.
// since the syscall parameters have to be placed into registers,
// using functions would mean push and pop every parameter.
// even with -O (lowest Optimization) gcc handles putting the parameters into the right registers fine.
// so static inline even results often in smaller codesize than not inlining.
//
// when minilib is compiled without errno,
// the syscalls return the negative value of errno on error.
//

//#define __callend : "rcx" )

// Seems linux x86_64 has same convention as osx darwin
#ifdef X64

// memory clobber is needed, gcc optimizes syscalls very likely away without
#define __callend : "memory","rcx", "r11" )
//(also osx)
#define __SYSCALL_ASM(ret,call) asm volatile ("syscall" : "=a" (ret)  : "a" ( (call | NCONST ) )
#else
#ifdef mini_vsyscalls
#define __SYSCALL_ASM(ret,call) asm volatile ("call *__mini_vsys" : "=a" (ret)  : "a" (call)
#else
//linux32bit
// memory clobber is needed, gcc optimizes syscalls very likely away without
#define __callend : "memory" )
#define __SYSCALL_ASM(ret,call) asm volatile ("int $0x80" : "=a" (ret)  : "a" (call)
#endif
#endif

#ifdef X64 
	// also osx
#define syscall1(ret,call,a1) __SYSCALL_ASM(ret,call) , "D" (a1) __callend
#define syscall2(ret,call,a1,a2) __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2) __callend
#define syscall3(ret,call,a1,a2,a3) __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3) __callend
#define syscall4(ret,call,a1,a2,a3,a4) register long int r10 asm ("r10") = a4 ; __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3), "r" (r10) __callend
#define syscall5(ret,call,a1,a2,a3,a4,a5) register long int r10 asm ("r10") = a4 ; register long int r8 asm ("r8") = a5 ; __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3), "r" (r10), "r" (r8) __callend
#define syscall6(ret,call,a1,a2,a3,a4,a5,a6) register long int r10 asm ("r10") = a4 ; register long int r8 asm ("r8") = a5 ; register long int r9 asm ("r9") = a6; __SYSCALL_ASM(ret,call) , "D" (a1), "S" (a2), "d" (a3), "r" (r10), "r" (r8), "r" (r9) __callend


// save value in (temporary) var sysret.
// return -1 if an error occured, set errno.
#define syscall0_ret(call) __SYSCALL_ASM(sysret,call) 
#define syscall1_ret(call) syscall0_ret(call) , "D" (a1) 
#define syscall2_ret(call) syscall1_ret(call) , "S" (a2) 
#define syscall3_ret(call) syscall2_ret(call) , "d" (a3) 
#define syscall4_ret(call) register long int r10 asm("r10")= a4; syscall3_ret(call) , "r" (r10)
#define syscall5_ret(call) register long int r10 asm("r10")= a4; register long int r8 asm("r8")= a5 ; syscall3_ret(call) , "r" (r8) 
#define syscall6_ret(call) register long int r10 asm("r10")= a4; register long int r8 asm("r8")= a5 ; register long int r9 asm("r9")=a6; syscall3_ret(call) , "r" (r8) 
// r9: 6th param..

#else

//linux

#ifndef X64
//linux 32bit

#define syscall1(ret,call,a1) __SYSCALL_ASM(ret,call) , "b" (a1) __callend
#define syscall2(ret,call,a1,a2) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2) __callend
#define syscall3(ret,call,a1,a2,a3) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3) __callend
#define syscall4(ret,call,a1,a2,a3,a4) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4) __callend
#define syscall5(ret,call,a1,a2,a3,a4,a5) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4), "D" (a5) __callend


// save value in (temporary) var sysret.
// return -1 if an error occured, set errno.
#define syscall0_ret(call) __SYSCALL_ASM(sysret,call) 
#define syscall1_ret(call) syscall0_ret(call) , "b" (a1) 
#define syscall2_ret(call) syscall1_ret(call) , "c" (a2) 
#define syscall3_ret(call) syscall2_ret(call) , "d" (a3) 
#define syscall4_ret(call) syscall3_ret(call) , "S" (a4)
#define syscall5_ret(call) syscall4_ret(call) , "D" (a5) 

#else
// linux 86_X64
#define syscall1(ret,call,a1) __SYSCALL_ASM(ret,call) , "b" (a1) __callend
#define syscall2(ret,call,a1,a2) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2) __callend
#define syscall3(ret,call,a1,a2,a3) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3) __callend
#define syscall4(ret,call,a1,a2,a3,a4) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4) __callend
#define syscall5(ret,call,a1,a2,a3,a4,a5) __SYSCALL_ASM(ret,call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4), "D" (a5) __callend


// save value in (temporary) var sysret.
// return -1 if an error occured, set errno.
#define syscall0_ret(call) __SYSCALL_ASM(sysret,call) 
#define syscall1_ret(call) syscall0_ret(call) , "b" (a1) 
#define syscall2_ret(call) syscall1_ret(call) , "c" (a2) 
#define syscall3_ret(call) syscall2_ret(call) , "d" (a3) 
#define syscall4_ret(call) syscall3_ret(call) , "S" (a4)
#define syscall5_ret(call) syscall4_ret(call) , "D" (a5) 
#define syscall6_ret(call) syscall5_ret(call) , "r10" (a6) 

#endif

#endif


// args: count of parameters, syscall number, [parameters...]
#define __DO_syscall(n,...) syscall##n##_ret( __VA_ARGS__ ) __callend

// args: name (e.g. getpid), count of args, arguments (e.g. int* a1, char *a2).
// arguments must be named a1,a2,...

#ifndef GENSYNTAXCHECK 

#ifdef mini_errno
#define REAL_define_syscall( name, argcount, ... ) inline \
		int volatile __attribute__((always_inline)) name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, (SCALL(name) | NCONST ) );\
				if ( sysret<0){\
						errno = -sysret;\
						return(-1);}\
				return(sysret);\
		}
// syscalls with more than 4 args may not be optimized nor inlined.
// register assignment gets optimized out otherways.
#define REAL_define_syscall_noopt( name, argcount, ... ) \
		int volatile __attribute__((optimize("O0"))) name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, (SCALL(name) | NCONST ) );\
				if ( sysret<0){\
						errno = -sysret;\
						return(-1);}\
				return(sysret);\
		}

#else //errno
#define REAL_define_syscall( name, argcount, ... ) inline \
		int volatile __attribute__((always_inline)) name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, ( SCALL(name) | NCONST ) );\
				return( sysret );\
		}
#define REAL_define_syscall_noopt( name, argcount, ... ) \
		int volatile __attribute__((optimize("O0"))) name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, ( SCALL(name) | NCONST ) );\
				return( sysret );\
		}

//				return( (sysret<0) ? -1 : sysret );\

#endif


#ifdef mini_errno
#define SYSREAL_define_syscall( name, argcount, ... ) inline \
		int volatile __attribute__((always_inline)) sys##name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, (__SYSCALL(name) | NCONST ) );\
				if ( sysret<0){\
						errno = -sysret;\
						return(-1);}\
				return(sysret);\
		}

#define SYSREAL_define_syscall_noopt( name, argcount, ... ) \
		int volatile __attribute__((optimize("O0"))) sys##name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, (__SYSCALL(name) | NCONST ) );\
				if ( sysret<0){\
						errno = -sysret;\
						return(-1);}\
				return(sysret);\
		}

#else
#define SYSREAL_define_syscall( name, argcount, ... ) inline \
		int volatile __attribute__((always_inline)) sys##name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, ( __SYSCALL(name) | NCONST ) );\
				return( sysret );\
		}

				//return( (sysret<0) ? -1 : sysret );

#define SYSREAL_define_syscall_noopt( name, argcount, ... ) \
		int volatile __attribute__((optimize("O0"))) sys##name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, ( __SYSCALL(name) | NCONST ) );\
				return( sysret );\
		}

#endif

//return( (sysret<0) ? -1 : sysret ); (no errno) : ok. not added anything to the final size

/*
				if ( sysret<0){\
						errno = -sysret;\
						return(-1);}\
				return(sysret);\
		}
		*/

// global sysret: +34 bytes (??)

// errno = (sysret<0) ? 0 : sysret;\ + 42 bytes..

/* (+64bytes) /+38 bytes with local sysret
				if ( sysret<0){\
						errno = -sysret;\
						return(-1);}\
				return(sysret);\
		}\
		*/

// args: name (e.g. getpid), argument to return, count of args, arguments (e.g. int* a1, char *a2).
// arguments must be named a1,a2,...
#ifdef mini_errno
#define REAL_define_syscallret( name, ret, argcount, ... ) inline \
		int volatile __attribute__((always_inline)) name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, SCALL(name));\
				if ( sysret<0 ){\
						errno = -sysret;\
						return(-1);}\
				return(ret);\
		}

#else
#define REAL_define_syscallret( name, ret, argcount, ... ) inline \
		int volatile __attribute__((always_inline)) name( __VA_ARGS__ ){\
				int sysret;\
				__DO_syscall( argcount, SCALL(name));\
				if ( sysret<0 ){\
						return(sysret);}\
				return(ret);\
		}

#endif


#define DEF_syscall(...) 
#define DEF_syscallret(...) 


#else //ifndef gensyntaxcheck
// Boilerplates, to get the syntaxchecking right (syntaxcheck.h)
#define DEF_syscall( name, argcount, ... ) int volatile name( __VA_ARGS__ );
#define DEF_syscallret( name, ret, argcount, ... ) int volatile name( __VA_ARGS__ );
//#define REAL_define_syscall( name, argcount, ... ) int volatile name( __VA_ARGS__ );

#define SYSDEF_syscall( name, argcount, ... ) int volatile sys##name( __VA_ARGS__ );

#define REAL_define_syscall(...) 
#define REAL_define_syscall_noopt(...) 
#define REAL_define_syscallret(...) 
#define SYSREAL_define_syscall(...) 
#define SYSREAL_define_syscall_noopt(...) 

#endif



//#define __DEF_SYSCALL(count) extern int __attribute__((always_inline,optimize("0"))) 

#if 0 

#define __SYSCALL_ASMret(call) asm volatile ("mov %1,%%eax\n\tint $0x80" : "=a" (sysret)  : "g" (call)

#define syscall0_ret(call,unused) __SYSCALL_ASMret(call) )
#define syscall1_ret(call,a1) __SYSCALL_ASMret(call) , "b" (a1) )
#define syscall2_ret(call,a1,a2) __SYSCALL_ASMret(call) , "b" (a1), "c" (a2) )
#define syscall3_ret(call,a1,a2,a3) __SYSCALL_ASMret(call) , "b" (a1), "c" (a2), "d" (a3) )
#define syscall4_ret(call,a1,a2,a3,a4) __SYSCALL_ASMret(call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4))
#define syscall5_ret(call,a1,a2,a3,a4,a5) __SYSCALL_ASMret(call) , "b" (a1), "c" (a2), "d" (a3), "S" (a4), "D" (a5) )

// args: count of parameters, syscall number, [parameters...]
#define __DO_syscall(n,...) syscall##n##_ret( __VA_ARGS__ )

// args: name (e.g. getpid), count of args, arguments (e.g. int* a1, char *a2).
#define DEF_syscall( name, argcount, ... ) static inline \
		int __attribute__((always_inline)) name( __VA_ARGS__ ){\
				__DO_syscall( argcount, __NR_##name , __VA_ARGS__ );\
				if ( sysret<0 )\
						errno = -sysret;\
				return(sysret);\
		}\





wantbugs_by_optimizing
#define __SYSCALL_asm(ret) asm volatile ("int $0x80" : "=a" (ret)  : "0" (call),

#define __SYSCALL_CONSTRAINTS_1 "b" (a1)
#define __SYSCALL_CONSTRAINTS_2 __SYSCALL_CONSTRAINTS_1, "c" (a2)
#define __SYSCALL_CONSTRAINTS_3 __SYSCALL_CONSTRAINTS_2, "d" (a3)
#define __SYSCALL_CONSTRAINTS_4 __SYSCALL_CONSTRAINTS_3, "S" (a4)
#define __SYSCALL_CONSTRAINTS_5 __SYSCALL_CONSTRAINTS_4, "D" (a5)

#define __SYSCALL_ARGS1 int a1
#define __SYSCALL_ARGS2 __SYSCALL_ARGS1, int a2
#define __SYSCALL_ARGS3 __SYSCALL_ARGS2, int a3
#define __SYSCALL_ARGS4 __SYSCALL_ARGS3, int a4
#define __SYSCALL_ARGS5 __SYSCALL_ARGS4, int a5
#define __SYSCALL_ARGS6 __SYSCALL_ARGS5, int a6


				
#define __DEF_SYSCALL(count) extern int \
		__syscall ## count \
				( int call, __SYSCALL_ARGS ## count );


#define __IMPL_SYSCALL(count) int \
		__syscall ## count \
				( int call, __SYSCALL_ARGS ## count ){\
		__SYSCALL_asm(call)  __SYSCALL_CONSTRAINTS_ ##count );\
		return(call);\
}

__DEF_SYSCALL(1)
__DEF_SYSCALL(2)
__DEF_SYSCALL(3)
__DEF_SYSCALL(4)
__DEF_SYSCALL(5)


#define syscall1(call,a) __syscall1((int)call,(int)a)
#define syscall2(call,a,b) __syscall2(call,(int)a,(int)b)
#define syscall3(call,a,b,c) __syscall3(call,(int)a,(int)b,(int)c)
#define syscall4(call,a,b,c,d) __syscall4(call,(int)a,(int)b,(int)c,(int)d)
//#define syscall5(call,a,b,c,d,e) __syscall5(call,(int)a,(int)b,(int)c,(int)d,(int)e)
#define syscall6(call,a,b,c,d,e,f) __syscall6(call,(int)a,(int)b,(int)c,(int)d,(int)e,(int)f)

	/*
static inline int __attribute__((always_inline)) __syscall6(int call, __SYSCALL_ARGS6 ){
		int ret;
		asm volatile ("push %%ebp\n\tmov %1,%%ebp\n\t int $0x80\n\tpop %%ebp" \
												 : "=a" (ret) : "g" (a6), "a" (call) __SYSCALL_CONSTRAINTS_5 );
		return(ret);
}
*/

#endif

#endif
