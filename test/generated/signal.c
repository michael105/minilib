#if 0
mini_signal
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
  volatile  sighandler_t  a2=0;
  signal(a1,a2);
  return(ret);
}
