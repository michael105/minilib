#if 0
mini_epoll_pwait
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
  volatile   struct epoll_event * a2=0;
  volatile   int  a3=0;
  volatile   int  a4=0;
  volatile   const sigset_t * a5=0;
  volatile   size_t  a6=0;
  epoll_pwait(a1,a2,a3,a4,a5,a6);
  return(ret);
}
