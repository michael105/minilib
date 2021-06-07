#if 0
mini_rewinddir
mini_buf 128
globals_on_stack
mini_start
shrinkelf
INCLUDESRC
LDSCRIPT default
OPTFLAG -Os
return
#endif
int main(){
	volatile int ret=42;
  volatile DIR * a1=0;
  rewinddir(a1);
  return(ret);
}
