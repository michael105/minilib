#if 0
mini_accept4
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
  volatile   struct sockaddr * a2=0;
  volatile   int * a3=0;
  volatile   int  a4=0;
  accept4(a1,a2,a3,a4);
  return(ret);
}
