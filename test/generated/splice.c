#if 0
mini_splice
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
  volatile   loff_t * a2=0;
  volatile   int  a3=0;
  volatile   loff_t * a4=0;
  volatile  size_t  a5=0;
  volatile   unsigned int  a6=0;
  splice(a1,a2,a3,a4,a5,a6);
  return(ret);
}
