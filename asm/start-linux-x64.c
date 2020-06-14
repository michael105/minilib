#ifdef mini_start
void _start(){
#include "src/startup.c"
__asm__ volatile("\
#.global _start\n\
#_start:\n\
	popq %rdi\n\
	movq %rsp,%rsi\n\
	leaq  8(%rsi,%rdi,8),%rdx\n"
#ifdef mini_environ
	"movq %rdx, environ\n"
#endif

	"call main\n\
	movq %rax, %rdi\n\
.global _exit\n\
_exit:\n\
	movq $60, %rax\n\
	syscall\n"
	);
};
#endif

