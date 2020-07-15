#if 0
mini_setvbuf
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
  volatile FILE * a1=0;
  volatile  char * a2="";
  volatile  int  a3=0;
  volatile  size_t  a4=0;
  setvbuf(a1,a2,a3,a4);
  return(ret);
}
