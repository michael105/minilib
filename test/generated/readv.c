#if 0
mini_readv
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
  volatile   const struct iovec * a2=0;
  volatile   unsigned long  a3=0;
  readv(a1,a2,a3);
  return(ret);
}
