#if 0
mini_vmsplice
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
  volatile   const struct iovec * a2=0;
  volatile   unsigned long  a3=0;
  volatile  unsigned int  a4=0;
  vmsplice(a1,a2,a3,a4);
  return(ret);
}