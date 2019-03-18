//void _start(){
#ifdef mini_start
__asm__ volatile ("\
.global _start\n\
_start:\n\
	pop %eax\n\
	leal  12(%esp,%eax,4),%ebx\n\
	push %ebx\n\
	call __start_c\n\
	pop %ebx\n\
	pop %eax\n\
	mov %esp,%ecx\n\
	push %ebx\n\
	push %ecx\n\
	push %eax\n\
	call main\n\
	mov %eax, %ebx\n\
.global _exit\n\
_exit:
	mov $1, %eax\n\
	int $0x80"
	);
//};
#endif

