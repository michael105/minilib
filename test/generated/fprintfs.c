#if 0
mini_fprintfs
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
  volatile  FILE* a1=0;
  volatile  char * a2="";
  volatile   a3=0;
  fprintfs(a1,a2,a3);
  return(ret);
}
