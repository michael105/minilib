#if 0
mini_execve
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
  volatile   char* const* a2="";
  volatile  char* const* a3="";
  execve(a1,a2,a3);
  return(ret);
}
