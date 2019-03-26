
// The configuration of the functions to be built
#include "minilib.conf"

// Switch to compile also the sources
#define INCLUDESRC

#include "minilib.h"

int main(){
		write(0, "Hello world!\n", 13);
		return(0);
}
