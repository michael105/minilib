#if 0
mini_sendfile
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
  volatile  int  a1=0;
  volatile   int  a2=0;
  volatile   off_t * a3=0;
  volatile   size_t  a4=0;
  sendfile(a1,a2,a3,a4);
  return(ret);
}
