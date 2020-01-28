#if 0
mini_sched_getparam
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
  volatile   struct sched_param * a2=0;
  sched_getparam(a1,a2);
  return(ret);
}
