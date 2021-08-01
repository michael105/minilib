#if 0
mini_start

COMPILE mmap open

COMPILE writes

COMPILE printf atoi itodec itohex vsnprintf snprintf sprintf vsprintf fprintf ltodec

mini_buf 3800

globals_on_stack


STRIPFLAG
INCLUDESRC
#SHRINKELF

return
#endif


typedef uint16_t Elf64_Half;
typedef uint32_t Elf64_Word;
typedef	int32_t  Elf64_Sword;
typedef uint64_t Elf64_Xword;
typedef	int64_t  Elf64_Sxword;
typedef uint64_t Elf64_Addr;
typedef uint64_t Elf64_Off;
typedef uint16_t Elf64_Section;
typedef Elf64_Half Elf64_Versym;
#define EI_NIDENT (16)


typedef struct {
  unsigned char	e_ident[EI_NIDENT];
  Elf64_Half	e_type;
  Elf64_Half	e_machine;
  Elf64_Word	e_version;
  Elf64_Addr	e_entry;
  Elf64_Off	e_phoff;
  Elf64_Off	e_shoff;
  Elf64_Word	e_flags;
  Elf64_Half	e_ehsize;
  Elf64_Half	e_phentsize;
  Elf64_Half	e_phnum;
  Elf64_Half	e_shentsize;
  Elf64_Half	e_shnum;
  Elf64_Half	e_shstrndx;
} Elf64_Ehdr;


typedef struct {
  Elf64_Word	p_type;
  Elf64_Word	p_flags;
  Elf64_Off	p_offset;
  Elf64_Addr	p_vaddr;
  Elf64_Addr	p_paddr;
  Elf64_Xword	p_filesz;
  Elf64_Xword	p_memsz;
  Elf64_Xword	p_align;
} Elf64_Phdr;



Elf64_Ehdr *hdr;

static void __attribute__((naked))loadf1(){
	asm("call load1\n\
		jmp *do_printf\n");
}

static void __attribute__((naked))loadf2(){
	asm("call load1\n\
		jmp *usage\n");
}


int (*do_printf)(const char* fmt, char *args[], int convert_args) =
  (int(*)(const char*, char **, int))loadf1;
void (*usage)() = (void(*)()) loadf2;


long *addr;
void load(long *p, const char *path){
	write(1,"load\n",5);
	int fd = open( path,O_RDONLY);
	write(1,"1\n",2);
	//long *
		addr = mmap( 0, 4000, PROT_EXEC | PROT_READ , MAP_PRIVATE|MAP_POPULATE, fd, 0 );
	//Elf64_Ehdr* 
		hdr = (Elf64_Ehdr*)addr;
	write(1,"2\n",2);
	//printf("addr: %lx\n",addr);
	//printf("x: %lx\n",0x8048000);
	//do_printf = (int(*)(const char*,char **,int))addr+0x504;
	//printf("xdpp: %lx\n",*do_printf);

	//long *p = (long*)&do_printf;
	//for (long *a = addr+0xb0/8; *a; p++,a++)
	//long *p1 = addr+((hdr->e_phoff + ( hdr->e_phentsize) + 16)-0x804800 )/8;
	//printf("p1 %lx\n",p1);
	//printf("p1 %lx\n",*p1);

	for (long *a = addr+(hdr->e_phoff + ( hdr->e_phnum * hdr->e_phentsize))/8; *a; p++,a++)
	//for (long *a = *p1/8; *a; p++,a++)
		*p = (long)addr+*a;

	//*p = (long)addr+addr[0xb0/8 +1];
	//do_printf = (int(*)(const char*,char **,int))addr+addr[0xb0/8];
	//usage = (void(*)())addr+addr[0xb0/8 + 1];
	//printf("x: %lx\n",*do_printf);
	write(1,"load Ok\n",8);
}
static const char *name = "printf";
void __attribute__((naked))load1(){
	asm("pushq %rdi\npushq %rsi\n\
			movq $do_printf,%rdi\n\
			movq name,%rsi\n\
			jmp loadL\n");
}

void __attribute__((naked))loadL(){
	//asm("pushq %rdi\npushq %rsi\npushq %rcx\npushq %rdx\npushq %r8\npushq %r9\npushq %rax\n");
	asm("pushq %rcx\npushq %rdx\npushq %r8\npushq %r9\npushq %rax\ncall load\n");
	//load((long*)&do_printf);
	asm("popq %rax\npopq %r9\npopq %r8\npopq %rdx\npopq %rcx\npopq %rsi\npopq %rdi\n");
	asm("ret\n");
}


int main(int argc, char *argv[],char **envp){

	usage();
	do_printf("Hello!!\n",0,0);


	do_printf("Hello2 : %s - %d \n",argv,1);

	printf("e_phoff: %ld\ne_shoff: %ld\ne_phnum: %d\ne_shnum: %d\n",
			hdr->e_phoff,
			hdr->e_shoff,
			hdr->e_phnum,
			hdr->e_shnum);
	printf("phentsize: %d\n",hdr->e_phentsize);
	printf("version: %d\n",hdr->e_version);
	printf("type: %d\n",hdr->e_type);
	printf("ident: %s\n",hdr->e_ident);
	int *i = (int*)hdr->e_ident;
	printf("ident: %x\n",*i); // 0x464c457f = "ELF\x7f"

	Elf64_Phdr *p = (Elf64_Phdr*)(addr + hdr->e_phoff/8);

#define P(NAME) printf( NAME ": %d\n", hdr->e_NAME )
	printf("offset: %ld\n", p->p_offset );
	printf("vaddr: %lx\n", p->p_vaddr );
	printf("paddr: %lx\n", p->p_paddr );
	p++;
	printf("offset: %ld\n", p->p_offset );
	printf("vaddr: %lx\n", p->p_vaddr );

	return(0);
}
