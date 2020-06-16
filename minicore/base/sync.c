#if 0
mini_start
mini_sync
mini_writes

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

// misc 2020/06
// BSD license


int main(int argc, char *argv[]){
	if (argc > 1) {
			writes("Usage: sync\n");
	} else {
			sync();
	}
	return 0;
}
