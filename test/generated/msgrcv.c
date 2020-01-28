#if 0
mini_msgrcv
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
  volatile   struct msgbuf * a2=0;
  volatile   size_t  a3=0;
  volatile   long  a4=0;
  volatile   int  a5=0;
  msgrcv(a1,a2,a3,a4,a5);
  return(ret);
}
