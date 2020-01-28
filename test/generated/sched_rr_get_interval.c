#if 0
mini_sched_rr_get_interval
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
  volatile  pid_t  a1=0;
  volatile   struct timespec * a2=0;
  sched_rr_get_interval(a1,a2);
  return(ret);
}
