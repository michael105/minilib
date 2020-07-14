#if 0
mini_start
mini_exit
mini_writes
mini_fwrites
mini_atoi
mini_fopen
mini_fclose
mini_getc
mini_putc
mini_printl
mini_prints
mini_globals

mini_buf 256
#LDSCRIPT onlytext
#LDSCRIPT text_and_bss
#globals_on_stack

shrinkelf
INCLUDESRC
return
#endif


/* head - print the first few lines of a file	Author: Andy Tanenbaum */


#define DEFAULT 10



void usage(){
  fwrites(STDERR_FILENO,"Usage: head [-n] [file ...]\n");
  exit(1);
}


void do_file(n, f)
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


int main(argc, argv)
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
	if (nfiles > 1) {
			writes("==> ");
			prints(argv[k]);
			writes(" <==\n"); 
	}
	f = fopen(argv[k], "r");
	if (!f){
		writes("head: cannot open ");
		prints( argv[k]);
		writes("\n");

	} else {
		do_file(n, f);
		fclose(f);
	}
	k++;
	if (k < argc) printl();
  }
  exit(0);
}


