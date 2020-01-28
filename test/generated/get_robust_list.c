#if 0
mini_get_robust_list
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
  volatile  int  a1=0;
  volatile   struct robust_list_head ** a2=0;
  volatile   size_t * a3=0;
  get_robust_list(a1,a2,a3);
  return(ret);
}
