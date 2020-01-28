#if 0
mini_sigaltstack
mini_buf 0
mini_start
shrinkelf
INCLUDESRC
LDSCRIPT text_and_bss
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
  volatile  const stack_t * a1=0;
  volatile   stack_t * a2=0;
  sigaltstack(a1,a2);
  return(ret);
}
