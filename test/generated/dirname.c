#if 0
mini_dirname
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
  dirname(a1);
  return(ret);
}