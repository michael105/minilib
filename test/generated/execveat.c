#if 0
mini_execveat
mini_buf 0
mini_start
shrinkelf
INCLUDESRC
LDSCRIPT text_and_bss
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
  volatile  int  a1=0;
  volatile  const char * a2="";
  volatile   char* const* a3="";
  volatile  char* const* a4="";
  volatile  int  a5=0;
  execveat(a1,a2,a3,a4,a5);
  return(ret);
}
