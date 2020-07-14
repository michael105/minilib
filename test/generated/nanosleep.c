#if 0
mini_nanosleep
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
  volatile  struct timespec * a1=0;
  volatile  struct timespec * a2=0;
  nanosleep(a1,a2);
  return(ret);
}
