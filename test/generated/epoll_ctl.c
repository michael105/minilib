#if 0
mini_epoll_ctl
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
  volatile   int  a2=0;
  volatile   int  a3=0;
  volatile   struct epoll_event * a4=0;
  epoll_ctl(a1,a2,a3,a4);
  return(ret);
}