#if 0
mini_fstatfs
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
  volatile  unsigned int  a1=0;
  volatile   struct statfs * a2=0;
  fstatfs(a1,a2);
  return(ret);
}
