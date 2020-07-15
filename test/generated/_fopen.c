#if 0
mini__fopen
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
  volatile int  a1=0;
  volatile  const char* a2="";
  volatile  const char* a3="";
  volatile  FILE * a4=0;
  _fopen(a1,a2,a3,a4);
  return(ret);
}
