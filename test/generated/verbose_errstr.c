#if 0
mini_verbose_errstr
mini_printsl
mini_buf 128
globals_on_stack
mini_start
shrinkelf
INCLUDESRC
LDSCRIPT text_and_bss
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
  volatile int  a1=11;
  printsl(verbose_errstr(a1));
  return(ret);
}
