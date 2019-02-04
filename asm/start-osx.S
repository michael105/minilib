.globl start
start:	pushq	$0		    # push a zero for debugger end of frames marker
movq	%rsp,%rbp	    # pointer to base of kernel frame
andq    $-16,%rsp	    # force SSE alignment
movq	8(%rbp),%rdi	    # put argc in %rdi
leaq	16(%rbp),%rsi	    # addr of arg[0], argv, into %rsi
movl	%edi,%edx	    # copy argc into %rdx
		addl	$1,%edx		    # argc + 1 for zero word
sall	$3,%edx		    # * sizeof(char *)
		addq	%rsi,%rdx	    # addr of env[0], envp, into %rdx
		movq	%rdx,%rcx
		jmp	Lapple2
		Lapple:	add	$8,%rcx
		Lapple2:cmpq	$0,(%rcx)	    # look for NULL ending env[] array
		jne	Lapple		    
		add	$8,%rcx		    # once found, next pointer is "apple" parameter now in %rcx
 	call _main
	movq %rax, %rdi
	movl $0x2000001, %eax           # exit 0
	syscall
