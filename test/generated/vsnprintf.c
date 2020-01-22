#if 0
mini_vsnprintf
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
  volatile  size_t  a2=0;
  volatile  const char* a3="";
  volatile  va_list  a4;
  vsnprintf(a1,a2,a3,a4);
  return(ret);
}
