#if 0
mini_fexecve
mini_buf 128
globals_on_stack
mini_start
shrinkelf
INCLUDESRC
LDSCRIPT default
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
  volatile int  a1=0;
  volatile  char * a2="";
  volatile  char * a3="";
  fexecve(a1,a2,a3);
  return(ret);
}
