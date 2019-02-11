void _start(){
#ifdef mini_start
__asm__ (
		"pop %eax\n\t"
		"leal  12(%esp,%eax,4),%ebx\n\t"
		"push %ebx\n\t"
		"call __start_c\n\t"
		"pop %ebx\n\t"
		"pop %eax\n\t"
		"mov %esp,%ecx\n\t"
		"push %ebx\n\t"
		"push %ecx\n\t"
		"push %eax\n\t"
		"call main\n\t"
		"mov %eax, %ebx\n\t"
		"mov $1, %eax\n\t"
		"int $0x80\n\t"
	);
};
#endif

