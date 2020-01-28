#if 0
mini_pipe
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
  volatile  int * a1=0;
  pipe(a1);
  return(ret);
}
