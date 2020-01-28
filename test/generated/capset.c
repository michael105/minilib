#if 0
mini_capset
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
  volatile  cap_user_header_t  a1=0;
  volatile   const cap_user_data_t  a2=0;
  capset(a1,a2);
  return(ret);
}
