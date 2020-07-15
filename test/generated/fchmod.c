#if 0
mini_fchmod
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
  volatile  mode_t  a2=0;
  fchmod(a1,a2);
  return(ret);
}
