.global _start
_start:

#ifdef mini_vsyscall
#	push %rbx
#	call __start_c
#	pop %rbx
#endif

	popq %rdi #; argc
	movq %rsp,%rsi #; argv
	#pushq %rdi #;
  leaq  8(%rsi,%rdi,8),%rdx #; %ebx = envp = (4*eax)+%esp+8
	call main

	movq %rax, %rdi
.global _exit
_exit:
	movq $60, %rax
	syscall

