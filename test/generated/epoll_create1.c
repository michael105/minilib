#if 0
mini_epoll_create1
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
  epoll_create1(a1);
  return(ret);
}