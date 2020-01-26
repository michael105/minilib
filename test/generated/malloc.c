#if 0
mini_malloc
mini_buf 800
mini_start
shrinkelf
INCLUDESRC
LDSCRIPT default
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
  volatile int  a1=1;
  malloc(a1);
  return(ret);
}
