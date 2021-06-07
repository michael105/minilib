#if 0
mini_utime
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
  volatile  const char * a1="";
  volatile  struct utimbuf * a2=0;
  utime(a1,a2);
  return(ret);
}
