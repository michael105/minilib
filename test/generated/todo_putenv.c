#if 0
mini_todo_putenv
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
  volatile  char * a1="";
  todo_putenv(a1);
  return(ret);
}
