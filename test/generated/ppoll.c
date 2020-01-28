#if 0
mini_ppoll
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
  volatile  struct pollfd * a1=0;
  volatile   unsigned int  a2=0;
  volatile   struct timespec * a3=0;
  volatile   const sigset_t * a4=0;
  volatile   size_t  a5=0;
  ppoll(a1,a2,a3,a4,a5);
  return(ret);
}
