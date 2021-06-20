#if 0
# file: hello.c
# An example, of howto use the inbuilt scripting configuration
# compile with mini-gcc --config hello.c -o hello hello.c
# Atm, something bloats this to 214Byte here
# Have to sort this out. Used to be around 180 Bytes

# The configuration of the functions to be built

# start: build the start function. needed for being executable
mini_start

# build write
mini_write

# Switch to compile the sources
# (only one source file may define this)
INCLUDESRC

# shrink the binary with "shrinkelf"
shrinkelf

# The ldscript file. can be onlytext, text_and_bss or default
LDSCRIPT onlytext

# the optimization flag for gcc
# (also defaults to -Os)
OPTFLAG -Os

# the following two line have to be there
return
#endif

// it's possible to explicitely include minilib.h,
// or syntaxcheck.h; so syntaxcheck plugins are able to do their work
//#include "syntaxcheck.h"

// main, as usual
int main(){
		write(0, "Hello world!\n", 13);
		return(0);
}
