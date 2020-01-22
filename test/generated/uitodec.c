#if 0
mini_uitodec
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
  volatile unsigned int  a1=0;
  volatile  char * a2="";
  volatile  int  a3=0;
  volatile  char  a4=0;
  uitodec(a1,a2,a3,a4);
  return(ret);
}
