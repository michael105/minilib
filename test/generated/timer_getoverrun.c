#if 0
mini_timer_getoverrun
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
  timer_getoverrun(a1);
  return(ret);
}