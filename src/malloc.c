// just malloc. no free yet.
#include "../include/syscall.h"

static int brk=0;

void* malloc(unsigned int size){
		int ret;
		if ( brk == 0 ){
				syscall1(ret,SCALL(brk),0);
		} else {
				ret=brk;
		}
		syscall1(brk,SCALL(brk),size+ret);

		return((void*)ret);
}


