#if 0
mini_reboot
mini_buf 128
globals_on_stack
mini_start
shrinkelf
INCLUDESRC
LDSCRIPT default
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
  volatile  int  a1=0;
  volatile   int  a2=0;
  volatile   unsigned int  a3=0;
  volatile   void * a4=0;
  reboot(a1,a2,a3,a4);
  return(ret);
}
