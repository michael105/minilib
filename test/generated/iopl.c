#if 0
mini_iopl
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
  volatile  unsigned int  a1=0;
  volatile   struct pt_regs * a2=0;
  iopl(a1,a2);
  return(ret);
}