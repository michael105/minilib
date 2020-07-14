#if 0
mini_sigfillset
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
  sigfillset(a1);
  return(ret);
}
