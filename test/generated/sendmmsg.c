#if 0
mini_sendmmsg
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
  volatile  int  a1=0;
  volatile   struct mmsghdr * a2=0;
  volatile   unsigned int  a3=0;
  volatile   unsigned int  a4=0;
  sendmmsg(a1,a2,a3,a4);
  return(ret);
}
