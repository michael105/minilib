#if 0
mini_semop
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
  semop(a1,a2,a3);
  return(ret);
}
