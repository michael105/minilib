#if 0
mini_strncasecmp
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
  volatile const char* a2="";
  volatile int  a3=0;
  strncasecmp(a1,a2,a3);
  return(ret);
}
