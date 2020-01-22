#if 0
mini_setbuf
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
  volatile FILE * a1=0;
  volatile  char * a2="";
  setbuf(a1,a2);
  return(ret);
}
