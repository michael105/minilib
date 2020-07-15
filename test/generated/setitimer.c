#if 0
mini_setitimer
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
  volatile   struct itimerval * a3=0;
  setitimer(a1,a2,a3);
  return(ret);
}
