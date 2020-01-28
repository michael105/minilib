#if 0
mini_poll
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
  volatile  struct poll_fd * a1=0;
  volatile   unsigned int  a2=0;
  volatile   long  a3=0;
  poll(a1,a2,a3);
  return(ret);
}
