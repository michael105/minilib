#if 0
mini_settimeofday
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
  volatile  struct timeval * a1=0;
  volatile   struct timezone * a2=0;
  settimeofday(a1,a2);
  return(ret);
}
