#!../mini-cc --exec 
// this file can be compiled and executed by just calling it..
// The configuration of the functions to be built
#define mini_start 
#define mini_exit 
#define mini_write generate
#define MINILIB_OS LINUX
#define MINILIB_ARCH X64
#define HEADERGUARDS
#define INCLUDESRC
#include "minilib.h"

int main(){
		write(0, "Hello world!\n", 13);
		return(0);
}
