#if 0
mini_fcntl
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
  volatile  unsigned int  a1=0;
  volatile  unsigned int  a2=0;
  volatile  unsigned long  a3=0;
  fcntl(a1,a2,a3);
  return(ret);
}
