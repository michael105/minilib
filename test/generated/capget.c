#if 0
mini_capget
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
  volatile   cap_user_data_t  a2=0;
  capget(a1,a2);
  return(ret);
}
