#if 0
mini_clone
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
  volatile   void * a3=0;
  volatile   void * a4=0;
  clone(a1,a2,a3,a4);
  return(ret);
}
