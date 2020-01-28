#if 0
mini_sendto
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
  volatile   void * a2=0;
  volatile   size_t  a3=0;
  volatile   unsigned  a4=0;
  volatile   struct sockaddr * a5=0;
  volatile   int  a6=0;
  sendto(a1,a2,a3,a4,a5,a6);
  return(ret);
}
