// file: hello-include.c
//   howto use minilib via including header only
//   compile with: 
//   mlcc -o hello-include hello-include.c
//


// the functions, which should be build
//
// build start, the entry point for the OS
#define mini_start

// define and build the function "write"
#define mini_write

// include definitions as well as the sources.
#define INCLUDESRC

// Only functions, you defined before, will be built.
//
#include "minilib.h"

int main(){
		write(0, "Hello world!\n", 13);
		return(0);
}


