#if 0
mini_mremap
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
  volatile   unsigned long  a4=0;
  volatile   unsigned long  a5=0;
  mremap(a1,a2,a3,a4,a5);
  return(ret);
}
