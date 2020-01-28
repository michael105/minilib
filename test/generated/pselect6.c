#if 0
mini_pselect6
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
  volatile   fd_set * a2=0;
  volatile   fd_set * a3=0;
  volatile   fd_set * a4=0;
  volatile   struct timespec * a5=0;
  volatile   void * a6=0;
  pselect6(a1,a2,a3,a4,a5,a6);
  return(ret);
}
