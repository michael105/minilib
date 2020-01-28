#if 0
mini_clock_nanosleep
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
  volatile   int  a2=0;
  volatile   const struct timespec * a3=0;
  volatile   struct timespec * a4=0;
  clock_nanosleep(a1,a2,a3,a4);
  return(ret);
}
