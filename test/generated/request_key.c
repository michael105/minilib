#if 0
mini_request_key
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
  volatile   const char * a2="";
  volatile   const char * a3="";
  volatile   key_serial_t  a4=0;
  request_key(a1,a2,a3,a4);
  return(ret);
}
