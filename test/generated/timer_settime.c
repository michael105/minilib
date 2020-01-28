#if 0
mini_timer_settime
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
  volatile  timer_t  a1=0;
  volatile   int  a2=0;
  volatile   const struct itimerspec * a3=0;
  volatile   struct itimerspec * a4=0;
  timer_settime(a1,a2,a3,a4);
  return(ret);
}
