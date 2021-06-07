#if 0
#mini_macro
mini_buf 64
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
  volatile void* a1=0;
  //macro(a1);
  return(ret);
}
