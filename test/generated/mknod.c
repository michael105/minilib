#if 0
mini_mknod
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
  volatile   umode_t  a2=0;
  volatile   unsigned  a3=0;
  mknod(a1,a2,a3);
  return(ret);
}
