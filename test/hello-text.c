#if 0
mini_start
mini_writes

mini_ltodec

mini_errno

OPTFLAG -O0
STRIPFLAG 
INCLUDESRC
LDSCRIPT text_and_bss
#LDSCRIPT onlytext

return
#endif

void test2(){
		long l;
	 	char buf[32];
		asm volatile ( "mov %%rbp, %0\n" : "=r"(l) );
		ltodec(l,buf,0,0);
		writes(buf);
		writes("\n");

		asm volatile ( "mov %%rsp, %0\n" : "=r"(l) );
		ltodec(l,buf,0,0);
		writes(buf);
		writes("\n");


}



void test(){
		long l;
	 	char buf[32];
		asm volatile ( "mov %%rbp, %0\n" : "=r"(l) );
		ltodec(l,buf,0,0);
		writes(buf);
		writes("\n");

		asm volatile ( "mov %%rsp, %0\n" : "=r"(l) );
		ltodec(l,buf,0,0);
		writes(buf);
		writes("\n");

		test2();

}

int main(int argc, char **argv){
		writes("Hello!\n");
	 	char buf[32];
		ltodec(argv[0],buf,0,0);
		writes(buf);
		writes("\n");
		ltodec(buf,buf,0,0);
		writes(buf);
		writes("\n");

		long l;
		asm volatile ( "mov %%rbp, %0\n" : "=r"(l) );
		ltodec(l,buf,0,0);
		writes(buf);
		writes("\n");

		asm volatile ( "mov %%rsp, %0\n" : "=r"(l) );
		ltodec(l,buf,0,0);
		writes(buf);
		writes("\n");


		test();
		test();


		int a,b;
		asm("mov %1,%0" : "=r" (a) : "r" (b) );

		return(0);
}

