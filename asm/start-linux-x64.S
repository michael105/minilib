.global _start
_start:
	pop %rax #; the ret address, if compiled as a c file
  leal  12(%esp,%eax,4),%ebx #; %ebx = envp = (4*eax)+%esp+8

#ifdef mini_vsyscall
#	push %rbx
#	call __start_c
#	pop %rbx
#endif

	pop %rax #; argc
	movq %rsp,%rcx #; argv

	push %rbx #; envp
	push %rcx #; argv
	push %rax #; argc


	call main
	movl %eax, %ebx
	movl $1, %eax
	int $0x80
