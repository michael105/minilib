#if 0
mini_ioperm
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
  volatile   int  a3=0;
  ioperm(a1,a2,a3);
  return(ret);
}
