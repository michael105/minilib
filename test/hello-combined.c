#define mini_start start
#define mini_write

//#define OSX
//#define X64

#define INCLUDESRC
#include "minilib/minilibcombined.h"

#if 0
testhello:
	$(info Testing makefile hello)
	./hello 0> results/hello.stdout
	@diff -q results/hello-expect.stdout results/hello.stdout && echo $RED Pass: hello || echo Fail: hello

ifdef undef
#endif

int main(){
		write(stdout, "Hello world!\n", 13);
		return(0);
}

#if 0
endif
#endif

