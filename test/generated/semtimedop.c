#if 0
mini_semtimedop
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
  volatile   struct sembuf * a2=0;
  volatile   unsigned  a3=0;
  volatile   const struct timespec * a4=0;
  semtimedop(a1,a2,a3,a4);
  return(ret);
}
