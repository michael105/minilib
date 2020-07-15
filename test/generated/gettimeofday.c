#if 0
mini_gettimeofday
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
  volatile  struct timeval * a1=0;
  volatile  struct timezone * a2=0;
  gettimeofday(a1,a2);
  return(ret);
}
