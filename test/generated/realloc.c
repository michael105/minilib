#if 0
mini_realloc
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
  volatile void * a1=0;
  volatile  int  a2=0;
  realloc(a1,a2);
  return(ret);
}
