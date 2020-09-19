#if 0
mini_strerror
mini_buf 128
globals_on_stack
mini_start
mini_prints
shrinkelf
INCLUDESRC
#LDSCRIPT textandbss
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
  volatile  int  a1=23;
  prints(strerror(a1));
  return(ret);
}
