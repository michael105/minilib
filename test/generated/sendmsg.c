#if 0
mini_sendmsg
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
  volatile   struct msghdr * a2=0;
  volatile   unsigned  a3=0;
  sendmsg(a1,a2,a3);
  return(ret);
}
