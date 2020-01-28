#if 0
mini_statfs
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
  volatile  const char * a1="";
  volatile   struct statfs * a2=0;
  statfs(a1,a2);
  return(ret);
}
