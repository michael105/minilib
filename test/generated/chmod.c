#if 0
mini_chmod
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
  volatile  mode_t  a2=0;
  chmod(a1,a2);
  return(ret);
}
