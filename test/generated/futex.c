#if 0
mini_futex
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
  volatile  u32 * a1=0;
  volatile   int  a2=0;
  volatile   u32  a3=0;
  volatile   struct timespec * a4=0;
  volatile   u32 * a5=0;
  volatile   u32  a6=0;
  futex(a1,a2,a3,a4,a5,a6);
  return(ret);
}
