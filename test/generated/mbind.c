#if 0
mini_mbind
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
  volatile  unsigned long  a1=0;
  volatile   unsigned long  a2=0;
  volatile   unsigned long  a3=0;
  volatile   unsigned long * a4=0;
  volatile   unsigned long  a5=0;
  volatile   unsigned  a6=0;
  mbind(a1,a2,a3,a4,a5,a6);
  return(ret);
}
