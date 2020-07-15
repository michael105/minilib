#if 0
mini_fflush
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
  volatile  FILE * a1=0;
  fflush(a1);
  return(ret);
}
