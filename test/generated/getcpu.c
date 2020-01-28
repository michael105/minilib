#if 0
mini_getcpu
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
  volatile  unsigned * a1=0;
  volatile   unsigned * a2=0;
  volatile   struct getcpu_cache * a3=0;
  getcpu(a1,a2,a3);
  return(ret);
}
