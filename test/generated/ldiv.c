#if 0
mini_ldiv
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
  volatile long int  a1=0;
  volatile  long int  a2=0;
  ldiv(a1,a2);
  return(ret);
}
