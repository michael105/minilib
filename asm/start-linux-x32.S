.global _start
_start:
	pop %eax #; the ret address, if compiled as a c file
  leal  12(%esp,%eax,4),%ebx #; %ebx = envp = (4*eax)+%esp+8

#ifdef mini_vsyscalls
	push %ebx
	call __start_c
	pop %ebx
#endif

	pop %eax #; argc
	mov %esp,%ecx #; argv

	push %ebx #; envp
	push %ecx #; argv
	push %eax #; argc


	call main
	mov %eax, %ebx
	mov $1, %eax
	int $0x80
