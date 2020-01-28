#if 0
mini_getrusage
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
  volatile   struct rusage * a2=0;
  getrusage(a1,a2);
  return(ret);
}
