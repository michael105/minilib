#ifdef mini_start
volatile void _start(){
__asm__ volatile("\
#.global _start\n\
#_start:\n\
 xorl %ebp, %ebp\n\
	popq %rdi\n\
	movq %rsp,%rsi\n\
	leaq  8(%rsi,%rdi,8),%rdx\n" );

//#include "src/startup.c"
#ifdef mini_environ
	//asm volatile(	"movq %%rdx, %0\n" : "=m" (environ) );
#endif

__asm__ volatile(
	"call _startup\n\
	movq %rax, %rdi\n\
.global _exit\n\
_exit:\n\
	movq $60, %rax\n\
	syscall\n"
	);
//#ifdef mini_globals_on_stack
	// forces gcc to assign the mlgl data structure, (in startup.c)
	// and put the whole struct on the stack.
	// albite this boilerplate is never reached
	// at runtime. Didn't find a better solution.
	//optimization_fence((void*)mlgl);
//#endif
};
#endif

