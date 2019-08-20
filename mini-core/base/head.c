/* head - print the first few lines of a file	Author: Andy Tanenbaum */

#include <stdio.h>

#define DEFAULT 10

main(argc, argv)
int argc;
char *argv[];
{
  FILE *f;
  int n, k, nfiles;
  char *ptr;

  /* Check for flag.  Only flag is -n, to say how many lines to print. */
  k = 1;
  ptr = argv[1];
  n = DEFAULT;
  if (argc > 1 && *ptr++ == '-') {
	k++;
	n = atoi(ptr);
	if (n <= 0) usage();
  }
  nfiles = argc - k;

  if (nfiles == 0) {
	/* Print standard input only. */
	do_file(n, stdin);
	exit(0);
  }

  /* One or more files have been listed explicitly. */
  while (k < argc) {
	if (nfiles > 1) fprintfs("==> %s <==\n", argv[k]);
	if ((f = fopen(argv[k], "r")) == NULL)
		fprintfs("head: cannot open %s\n", argv[k]);
	else {
		do_file(n, f);
		fclose(f);
	}
	k++;
	if (k < argc) printl();
  }
  exit(0);
}



do_file(n, f)
int n;
FILE *f;
{
  int c;

  /* Print the first 'n' lines of a file. */
  while (n) switch (c = getc(f)) {
	    case EOF:
		return;
	    case '\n':
		--n;
	    default:	putc((char) c, stdout);
	}
}


usage()
{
  fwrites("Usage: head [-n] [file ...]\n", STDERR_FILENO);
  exit(1);
}
