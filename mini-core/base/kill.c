#if 0
mini_start
mini_writes
mini_perror
mini_errno
mini_atoi
mini_putchar
mini_fprintf
mini_strcasecmp
mini_tolower
mini_buf 1024
LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif


#define ARRAY_SIZE(x)	((sizeof(x) / sizeof((x)[0])))

static struct {
	const char *argv0;
	int signum;
} opt;

static const struct sig_entry {
	const char *name;
	int signum;
} sig_table[] = {
	{ "HUP", 1 },
	{ "INT", 2 },
	{ "QUIT", 3 },
	{ "ILL", 4 },
	{ "TRAP", 5 },
	{ "ABRT", 6 },
	{ "IOT", 6 },
	{ "BUS", 7 },
	{ "FPE", 8 },
	{ "KILL", 9 },
	{ "USR1", 10 },
	{ "SEGV", 11 },
	{ "USR2", 12 },
	{ "PIPE", 13 },
	{ "ALRM", 14 },
	{ "TERM", 15 },
	{ "STKFLT", 16 },
	{ "CHLD", 17 },
	{ "CLD", 17 },
	{ "CONT", 18 },
	{ "STOP", 19 },
	{ "TSTP", 20 },
	{ "TTIN", 21 },
	{ "TTOU", 22 },
	{ "URG", 23 },
	{ "XCPU", 24 },
	{ "XFSZ", 25 },
	{ "VTALRM", 26 },
	{ "PROF", 27 },
	{ "WINCH", 28 },
	{ "IO", 29 },
	{ "POLL", 29 },
	{ "PWR", 30 },
	{ "UNUSED", 31 },
	{ "SYS", 31 },
	{ "RTMIN", 34 },
	{ "RTMAX", 64 },
};

#define NSIG 64

static int parse_int(const char *str)
{
	int val;
	char *ptr;

	val = atoi(str);
	return val;
}

static int get_signum(const char *name)
{
	const struct sig_entry *ent;
	int signum;
	size_t i;

	signum = parse_int(name);
	if (0 <= signum && signum <= NSIG)
		return signum;

	if (!strncasecmp(name, "SIG", 3))
		name += 3;

	for (i = 0; i < ARRAY_SIZE(sig_table); i++) {
		ent = &sig_table[i];
		if (!strcasecmp(ent->name, name))
			return ent->signum;
	}
	fprintf(stderr, "%s: invalid signal: %s\n", opt.argv0, name);
	exit(1);
}

static void print_table(void)
{
	const struct sig_entry *ent;
	size_t i;

	for (i = 0; i < ARRAY_SIZE(sig_table); i++) {
		ent = &sig_table[i];
		printf("%2d %-7s ", ent->signum, ent->name);
		if (i % 10 == 9)
			putchar('\n');
	}
}

static void print_names(int signum)
{
	const struct sig_entry *ent;
	size_t i, j;

	j = 0;
	for (i = 0; i < ARRAY_SIZE(sig_table); i++) {
		ent = &sig_table[i];
		if (signum < 0 || signum == ent->signum) {
			printf("%s ", ent->name);
			if (j++ == 15) {
				putchar('\n');
				j = 0;
			}
		}
	}
}

void usage(){
		writes("Usage: kill [-SIGNAL] [-l NUMBER] [-L] [PID1] [PID2] ...\n");
		exit(1);
}

/* Usage: kill [-SIGNAL] PID... */
/* Usage: kill -l [NUMBER] */
/* Usage: kill -L */
int main(int argc, const char *argv[])
{
	int signum, ret, i;
	pid_t pid;

	if (argc == 1) {
			usage();
	}

	opt.argv0 = argv[0];
	opt.signum = SIGTERM;

	if (!strcmp(argv[1], "-L")) {
		print_table();
		return 0;
	} else if (!strcmp(argv[1], "-l")) {
		if (argc > 2)
			signum = get_signum(argv[2]);
		else
			signum = -1;

		print_names(signum);
		return 0;
	} else if (argv[1][0] == '-') {
		opt.signum = get_signum(argv[1] + 1);
		i = 2;
	} else {
		i = 1;
	}

	ret = 0;
	for (; i < argc; i++) {
		pid = parse_int(argv[i]);
		if (kill(pid, opt.signum)) {
			fprintf(stderr, "%s: %d: %s\n",
				opt.argv0, pid, strerror(errno));
			ret = 1;
		}
	}
	return ret;
}
