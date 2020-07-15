#if 0
mini_select
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
  volatile int  a1=0;
  volatile   fd_set* a2=0;
  volatile   fd_set * a3=0;
  volatile   fd_set * a4=0;
  volatile   struct timeval * a5=1;
  select(a1,a2,a3,a4,a5);
  return(ret);
}
