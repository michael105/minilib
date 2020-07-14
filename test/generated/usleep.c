#if 0
mini_usleep
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
  usleep(a1);
  return(ret);
}
