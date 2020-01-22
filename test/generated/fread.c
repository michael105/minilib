#if 0
mini_fread
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
  volatile void * a1=0;
  volatile  size_t  a2=0;
  volatile  size_t  a3=0;
  volatile  FILE * a4=0;
  fread(a1,a2,a3,a4);
  return(ret);
}
