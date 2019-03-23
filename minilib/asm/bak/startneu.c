void _start(){
__asm__ volatile (
		"pop %eax #; the ret address, if compiled as a c file\n\t"
		"pop %eax #; argc\n\t"
		"leal  8(%esp,%eax,4),%ebx #; %eax = envp = (4*ecx)+%esi+4 \n\t"
		"mov %esp,%ecx #; argv\n\t"
		"push %ebx #; envp\n\t"
		"push %ecx #; argv\n\t"
		"push %eax #; argc\n\t"
#ifdef mini_vsyscalls
		"push %ebx #; envp\n\t"
		"call __start_c\n\t"
		"pop %ebx \n"
#endif
		"call main\n\t"
		"mov %eax, %ebx\n\t"
		"mov $1, %eax\n\t"
		"int $0x80\n\t"
	);
};
