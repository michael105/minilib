#define mini_start start
#define mini_write
#define mini_exit

#include "minilib_implementation.c"
//void _exit(int i);

int main(){
		write(stdout, "Hello world!\n", 13);
		exit(7);
//		asm volatile ("jmp _exit" :: "D" (7)); // Ok. works. 12 bytes -O0 und stripped.
//		_exit(7);
//	  	asm volatile ( "movq $7, %rbx\n\t"
//						"jmp _exit" );  // -O0: 16 B -Os 8 B

/*	 	asm volatile ( "movq $7, %rbx\n\t"
						"movq $1,%rax\n\t"
						"int $0x80" );*/ // again: 16 bytes.. auch mit O 0 ( all with -Os )
	  /*asm volatile ( "movq $7, %rdi\n\t"
						"movq $60,%rax\n\t"
						"syscall\n\t" );*/ // surprisingly, this asm is 16 Bytes. 
		// (also with -Os  defing and calling exit adds 8 Bytes. 
		// with -O0 exit adds 32B

//	  	asm volatile ( "movq $7, %rdi\n\t"
//						"jmp _exit"); // ok. this is also 8 Bytes. with -O0 16B
		//exit(7);
//		exit(23);
	 	//return(7); //cheapest //with -O0 432B (223 stripped)
}


