#ifdef mini_start
void __attribute__((naked,noreturn))_start(){
__asm__ volatile("\
#.global _start\n\
#_start:\n\
 xorl %ebp, %ebp\n\
	popq %rdi\n\
	movq %rsp,%rsi\n\
	movq %rdi,%rax\n\
	leaq  8(%rsi,%rdi,8),%rdx\n"
#ifdef mini_globals
	"call _startup\n"
#else
	"call main\n"
	"movq %rax, %rdi\n"
#endif
".global __exit\n\
__exit:\n\
	movq $60, %rax\n\
	syscall\n"
	);
	//__builtin_unreachable();
};
#endif

