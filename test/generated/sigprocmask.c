#if 0
mini_sigprocmask
mini_buf 128
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
  volatile int  a1=0;
  volatile  const sigset_t * a2=0;
  volatile  sigset_t * a3=0;
  sigprocmask(a1,a2,a3);
  return(ret);
}
