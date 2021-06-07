#if 0
mini_mkfifo
mini_buf 64
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
  volatile  const char* a1="f";
  volatile  mode_t  a2=0666;
  mkfifo(a1,a2);
  return(ret);
}
