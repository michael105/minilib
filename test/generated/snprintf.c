#if 0
mini_snprintf
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
  volatile  char * a1="";
  volatile  size_t  a2=0;
  volatile  const char * a3="";
  volatile   a4=0;
  snprintf(a1,a2,a3,a4);
  return(ret);
}
