#ifdef mini_start
__asm__ volatile (
		".globl start\n\t"
		"start:	pushq	$0\n\t"
		"movq	%rsp,%rbp\n\t"
		"andq    $-16,%rsp\n\t"
		"movq	8(%rbp),%rdi\n\t"
		"leaq	16(%rbp),%rsi\n\t"
		"movl	%edi,%edx\n\t"
		"addl	$1,%edx\n\t"
		"sall	$3,%edx\n\t"
		"addq	%rsi,%rdx\n\t"
		"movq	%rdx,%rcx\n\t"
		"jmp	Lapple2\n\t"
		"Lapple:	add	$8,%rcx\n\t"
		"Lapple2:cmpq	$0,(%rcx)\n\t"
		"jne	Lapple		    \n\t"
		"add	$8,%rcx\n\t"
		"call _main\n\t"
		"movq %rax, %rdi\n\t"
		"movl $0x2000001, %eax\n\t"
		"syscall\n\t"
	);
#endif

