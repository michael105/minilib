#if 0
mini_ftruncate
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
  volatile unsigned int  a1=0;
  volatile  unsigned int  a2=0;
  ftruncate(a1,a2);
  return(ret);
}
