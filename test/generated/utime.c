#if 0
mini_utime
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
  volatile  char * a1="";
  volatile   struct utimbuf * a2=0;
  utime(a1,a2);
  return(ret);
}
