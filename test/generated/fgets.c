#if 0
mini_fgets
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
  volatile char * a1="";
  volatile  int  a2=0;
  volatile  FILE* a3=0;
  fgets(a1,a2,a3);
  return(ret);
}
