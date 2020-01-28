#if 0
mini_adjtimex
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
  volatile  struct timex * a1=0;
  adjtimex(a1);
  return(ret);
}
