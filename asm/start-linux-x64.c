#ifdef mini_start
void volatile _start(){
__asm__ volatile("\
#.global _start\n\
#_start:\n\
 xorl %ebp, %ebp\n\
	popq %rdi\n\
	movq %rsp,%rsi\n\
	leaq  8(%rsi,%rdi,8),%rdx\n"
#ifdef mini_globals
	"call _startup\n"
#else
	"call main\n"
#endif
	"movq %rax, %rdi\n\
.global __exit\n\
__exit:\n\
	movq $60, %rax\n\
	syscall\n"
	);

};
#endif

