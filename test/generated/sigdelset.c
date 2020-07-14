#if 0
mini_sigdelset
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
  volatile sigset_t * a1=0;
  volatile  int  a2=0;
  sigdelset(a1,a2);
  return(ret);
}
