#define mini_start start
#define mini_write

#define INCLUDESRC
#include "minilib/minilib.h"

int main(){
		write(STDOUT_FILENO, "Hello world!\n", 13);
		return(0);
}


