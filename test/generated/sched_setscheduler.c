#if 0
mini_sched_setscheduler
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
  volatile   int  a2=0;
  volatile   struct sched_param * a3=0;
  sched_setscheduler(a1,a2,a3);
  return(ret);
}
