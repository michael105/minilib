#if 0
mini_time
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
  volatile unsigned int * a1=0;
  time(a1);
  return(ret);
}
