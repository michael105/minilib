#if 0
mini_arch_prctl
mini_buf 0
mini_start
shrinkelf
INCLUDESRC
LDSCRIPT text_and_bss
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
  volatile  struct task_struct * a1=0;
  volatile   int  a2=0;
  volatile   unsigned long * a3=0;
  arch_prctl(a1,a2,a3);
  return(ret);
}
