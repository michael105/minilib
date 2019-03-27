#define mini_start start
#define mini_write

#include "include/minilib_header.h"


// Check, whether the testing routines work.
// This lines intentionally fail.
// if they don't, there's a serious problem
// with your system.

int main(){
		char *c=0;
		c[42] = 23;
		// That should not happen. 
		// You're in trouble
		return((int)c[666]);
}


