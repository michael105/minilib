#ifdef MLIB
#include "minilib.h"
#else
#include <unistd.h>
#endif

int main(){
		write(0, "Hello world!\n", 13);
		return(0);
}
