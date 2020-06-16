#if 0
mini_start
mini_writes
mini_perror
mini_errno
LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

void usage(){
		writes("Usage: rm file1 [file2] ...\n");
		exit(1);
}

int main(int argc, char *argv[])
{
	int i;

	if (argc == 1) {
			usage();
	}
	for (i = 1; i < argc; i++) {
		if (unlink(argv[i]) < 0) {
			perror("rm: ");
			return 1;
		}
	}

	return 0;
}
