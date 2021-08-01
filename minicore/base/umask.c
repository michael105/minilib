#if 0
mini_start
mini_writes

mini_atoi
mini_putchar

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

// misc 2020/06
// BSD license

void usage(){
		writes("umask \n");
		exit(0);
}


int main(int argc, char *argv[]){
	if (argc != 2) {
			usage();
	}
	int i = atoi(argv[1]);

	char c;
	c = i/0100 + '0';
	putchar(c);

	i = umask(0);
	//umask(i);

}
