void _start(){
#ifdef mini_start
__asm__ volatile (
		"popq %rdi\n\t"
		"movq %rsp,%rsi\n\t"
		"leaq  8(%rsi,%rdi,8),%rdx\n\t"
		"call main\n\t"
		"movq %rax, %rbx\n\t"
		"movq $1, %rax\n\t"
		"int $0x80\n\t"
	);
};
#endif

