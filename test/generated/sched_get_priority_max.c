#if 0
mini_sched_get_priority_max
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
  volatile  int  a1=0;
  sched_get_priority_max(a1);
  return(ret);
}
