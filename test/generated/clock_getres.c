#if 0
mini_clock_getres
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
  volatile   struct timespec * a2=0;
  clock_getres(a1,a2);
  return(ret);
}
