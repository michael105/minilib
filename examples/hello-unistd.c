#include "unistd.h"

// Compile with 
// ./mini-gcc -o hello-unistd hello-unistd.c -Dmini_INCLUDESRC
// and optionally strip with 
// ./tools/shrinkelf hello-unistd
//
// (387 Bytes here.)
// It shows a generic way, to build with the minilib.
// And this also shows, it's double the size of the tailored 
// config of the other hello world's.
// Why it blows up to 2kB, when linked with the linker script 
// ld.script.onlytext - is puzzling to me yet.
// I can just guess, global vars are to blame.
// possibly the linker can't decide, what to drop and what not.
// or. I don't know. Stack. Section alignment. 
// Hopefully I'll find out..



int main(){
		write(0, "Hello world!\n", 13);
		return(0);
}
