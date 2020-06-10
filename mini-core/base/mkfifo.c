#if 0
mini_start
mini_writes
mini_mkfifo
mini_perror
mini_errno

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif


int main(int argc, const char *argv[])
{
	int i;

	if (argc == 1) {
		writes("Usage: mkfifo PATH [PATH...]\n");
		return 1;
	}
	for (i = 1; i < argc; i++) {
		if (mkfifo(argv[i], 0666)) {
				perror("mkfifo ");
			return 1;
		}
	}
	return 0;
}
