#if 0
mini_move_pages
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
  volatile  pid_t  a1=0;
  volatile   unsigned long  a2=0;
  volatile   const void * a3=0;
  volatile  const int * a4=0;
  volatile   int * a5=0;
  volatile   int  a6=0;
  move_pages(a1,a2,a3,a4,a5,a6);
  return(ret);
}
