#if 0
mini_execv
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
  volatile  char * a2="";
  execv(a1,a2);
  return(ret);
}
