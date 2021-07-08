#define mini_start start
#define mini_write

#define INCLUDESRC
#include "minilib.h"

int main(){
		write(STDOUT_FILENO, "Hello world!\n", 13);
		return(0);
}


