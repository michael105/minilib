#if 0
mini_start
mini_strlen
mini_strcmp
mini_basename
mini_puts
mini_ewrites
LDSCRIPT onlytext
INCLUDESRC
shrinkelf
return
#endif

// Original work by ammongit (github.com/ammongit/minutils)
// Modified by misc 2019


static void remove_suffix(char *base, const char *suffix)
{
	size_t baselen, suflen;
	char *ptr;

	baselen = strlen(base);
	suflen = strlen(suffix);

	ptr = base + baselen - suflen;
	if (!strcmp(ptr, suffix))
		*ptr = '\0';
}

/* Usage: basename PATH [SUFFIX] */
int main(int argc, char *argv[])
{
	const char *suffix;
	char *base;

	switch (argc) {
	case 2:
		suffix = NULL;
		break;
	case 3:
		suffix = argv[2];
		break;
	default:
		ewrites("basename: missing operand\n" );
		return 1;
	}
	base = basename(argv[1]);
	if (suffix)
		remove_suffix(base, suffix);

	puts(base);
	return 0;
}
