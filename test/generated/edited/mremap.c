#if 0
mini_mremap
mini_buf 64
globals_on_stack
mini_start
shrinkelf
INCLUDESRC
LDSCRIPT default
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
  volatile void* a1=0;
  volatile  size_t  a2=0;
  volatile  size_t  a3=1024;
  volatile  int  a4=0;
  volatile  void* a5=0;
	asm volatile("jmp _exit");
  mremap(a1,a2,a3,a4,a5);
  return(ret);
}
