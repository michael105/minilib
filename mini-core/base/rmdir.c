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
		writes("Usage: rmdir dir1 [dir2] ...\n");
		exit(1);
}




int main(int argc, const char *argv[])
{
	int i;

	if (argc == 1) {
			usage();
	}
	for (i = 1; i < argc; i++) {
		if (rmdir(argv[i])) {
			perror("rmdir: ");
			return 1;

		}
	}
	return 0;
}
