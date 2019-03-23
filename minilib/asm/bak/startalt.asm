.global _start
_start:
	pop %eax #; the ret address, if compiled as a c file
	pop %eax #; argc

  leal  8(%esp,%eax,4),%ebx #; %ebx = envp = (4*eax)+%esp+8
	mov %esp,%ecx #; argv

	push %ebx #; envp
#ifdef mini_vsyscalls
	call __start_c
#endif

	push %ecx #; argv
	push %eax #; argc


	call main
	mov %eax, %ebx
	mov $1, %eax
	int $0x80
