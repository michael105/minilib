#if 0
mini_getenv
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
  volatile const char* a1="";
  getenv(a1);
  return(ret);
}
