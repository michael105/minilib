#if 0
mini_sched_getaffinity
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
  volatile   unsigned int  a2=0;
  volatile   unsigned long * a3=0;
  sched_getaffinity(a1,a2,a3);
  return(ret);
}
