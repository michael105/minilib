#if 0
mini_seekdir
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
  volatile DIR * a1=0;
  volatile  long  a2=0;
  seekdir(a1,a2);
  return(ret);
}
