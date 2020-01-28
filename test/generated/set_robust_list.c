#if 0
mini_set_robust_list
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
  volatile  struct robust_list_head * a1=0;
  volatile   size_t  a2=0;
  set_robust_list(a1,a2);
  return(ret);
}
