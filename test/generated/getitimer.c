#if 0
mini_getitimer
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
  volatile  int  a1=0;
  volatile   struct itimerval * a2=0;
  getitimer(a1,a2);
  return(ret);
}
