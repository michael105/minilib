#if 0
mini_strtol
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
  volatile const char * a1="";
  volatile  const char ** a2="";
  volatile  int  a3=0;
  strtol(a1,a2,a3);
  return(ret);
}
