#if 0
mini_timer_create
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
  volatile  const clockid_t  a1=0;
  volatile   struct sigevent * a2=0;
  volatile   timer_t * a3=0;
  timer_create(a1,a2,a3);
  return(ret);
}
