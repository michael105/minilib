#if 0
mini_waitid
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
  volatile   pid_t  a2=0;
  volatile   struct siginfo * a3=0;
  volatile   int  a4=0;
  volatile   struct rusage * a5=0;
  waitid(a1,a2,a3,a4,a5);
  return(ret);
}
