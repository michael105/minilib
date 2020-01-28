#if 0
mini_rt_sigtimedwait
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
  volatile  const sigset_t * a1=0;
  volatile   siginfo_t * a2=0;
  volatile   const struct timespec * a3=0;
  volatile   size_t  a4=0;
  rt_sigtimedwait(a1,a2,a3,a4);
  return(ret);
}
