void _start(){
__asm__ volatile (
		"pop %eax #; the ret address, if compiled as a c file\n\t"
		"leal  12(%esp,%eax,4),%ebx #; %ebx = envp = (4*eax)+%esp+8\n\t"
#ifdef mini_vsyscalls
		"push %ebx\n\t"
		"call __start_c\n\t"
		"pop %ebx\n\t"
#endif
		"pop %eax #; argc\n\t"
		"mov %esp,%ecx #; argv\n\t"
		"push %ebx #; envp\n\t"
		"push %ecx #; argv\n\t"
		"push %eax #; argc\n\t"
		"call main\n\t"
		"mov %eax, %ebx\n\t"
		"mov $1, %eax\n\t"
		"int $0x80\n\t"
	);
};
