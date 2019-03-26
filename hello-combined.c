// file: hello-combined.c
//   howto use minilib with the combined source
//   compile with: 
//   gcc -o hello-combined hello-combined.c -static -nostdlib
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

#define INCLUDESRC

// include definitions as well as the sources.
// Only functions, you define before, will be built.
#include "minilibcombined.h"

int main(){
		write(0, "Hello world!\n", 13);
		return(0);
}


