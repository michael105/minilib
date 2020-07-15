#if 0
mini_dup3
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
  volatile int  a1=0;
  volatile  int  a2=0;
  volatile  int  a3=0;
  dup3(a1,a2,a3);
  return(ret);
}
