#if 0
mini_init_module
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
  volatile  void * a1=0;
  volatile   unsigned long  a2=0;
  volatile   const char * a3="";
  init_module(a1,a2,a3);
  return(ret);
}
