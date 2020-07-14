#if 0
mini_strdup
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
  volatile const char * a1="";
  strdup(a1);
  return(ret);
}
