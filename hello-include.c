// file: hello-include.c
//   howto use minilib via including header only
//   compile with: 
//   gcc -o hello-include hello-include.c -static -nostdlib
//


// the functions, which should be build
//
  // build start, the entry point for the OS
#define mini_start

  // define and build the function "write"
#define mini_write


// Configuration

 // build on OSX ( atm I can't check whether 32bit linux works )
//#define OSX

#define LINUX

 // build with 64bit( )
#define X64


// include definitions as well as the sources.
// Only functions, you define before, will be built.
#include "minilib_implementation.c"

int main(){
		write(0, "Hello world!\n", 13);
		return(0);
}


