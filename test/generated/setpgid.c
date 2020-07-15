#if 0
mini_setpgid
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
  volatile  pid_t  a1=0;
  volatile  pid_t  a2=0;
  setpgid(a1,a2);
  return(ret);
}
