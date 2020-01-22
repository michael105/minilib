#if 0
mini_fflush
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
  volatile  FILE * a1=0;
  fflush(a1);
  return(ret);
}
