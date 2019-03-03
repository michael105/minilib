.global _start
_start:
	#pop %rax #; the ret address, if compiled as a c file
  #leaq  8(%rsp,%rax,4),%rdx #; %ebx = envp = (4*eax)+%esp+8
	# TODO : env doesn't seem to be correct

#ifdef mini_vsyscall
#	push %rbx
#	call __start_c
#	pop %rbx
#endif

	popq %rdi #; argc
	movq %rsp,%rsi #; argv
	#pushq %rdi #; argc
  leaq  8(%rsi,%rdi,8),%rdx #; %ebx = envp = (4*eax)+%esp+8


	call main
	movq %rax, %rbx
	movq $1, %rax
	int $0x80
