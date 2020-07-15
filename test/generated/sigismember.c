#if 0
mini_sigismember
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
  volatile sigset_t * a1=0;
  volatile  int  a2=0;
  sigismember(a1,a2);
  return(ret);
}
