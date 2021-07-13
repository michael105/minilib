#if 0
mini_start
mini_writes
mini_puts
mini_printf
mini_strlen
mini_itodec
mini_ltodec
mini_atoi
mini_buf 256
mini_mmap
mini_open
mini_itohex
mini_itoHEX

mini_environ
INCLUDESRC
LDSCRIPT text_and_bss
globals_on_stack
HEADERGUARDS
#shrinkelf
STRIPFLAG
OPTFLAG
return
#endif

static char *m;
static char *addr;

static void __attribute__((naked))put_errstr(int e){
	//puts(verbose_errstr2(e));
	//asm("call *%%rcx"::"rcx"(addr):"rax");
	asm("jmp *addr");
	//asm("mov $0x13,%%rax\njmp %%rcx"::"rcx"(addr):"rax");
}


static void __attribute__((naked))put_errstr2(int e){
	//puts(verbose_errstr2(e));
	//asm("call *%%rcx"::"rcx"(addr):"rax");
	asm("mov $0x23,%rax\njmp *addr");
	//asm("mov $0x13,%%rax\njmp *addr");
}



int main(int argc, char **argv){
	writes("Running \n");

	int fd = open( "e",O_RDONLY);
	printf("fd: %d\n",fd);
	m = mmap( 0, 16000, PROT_EXEC | PROT_READ , MAP_PRIVATE|MAP_POPULATE, fd, 0 );
	addr = m;
	printf("%x\n",m[0]);
	printf("%x\n",m[1]);
	addr = m+0xf60;
	printf("%x\n",addr[0]);
	printf("%x\n",addr[1]);
	printf("%x\n",addr[2]);
	printf("%x\n",addr[3]);

	asm("call *addr");

	put_errstr(13);


	writes("ok\n");

	addr = m+0x108c;
	printf("%x\n",addr[0]);
	printf("%x\n",addr[1]);
	
	put_errstr2(13);


	addr = m+0x10c6;
	printf("%x\n",addr[0]);
	printf("%x\n",addr[1]);
	
	put_errstr2(13);


	writes("ok\n");
	return(0);
}
