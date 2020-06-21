//#include <sys/utsname.h>

//#include <errno.h>
//#include <stdbool.h>
//#include <stdio.h>
//#include <string.h>
#define bool char

static struct {
	bool sys     : 1;
	bool node    : 1;
	bool release : 1;
	bool version : 1;
	bool machine : 1;
} opt;

// source: ammongit
/* Usage: uname [-a] [-s] [-n] [-r] [-v] [-m] */
int main(int argc, const char *argv[])
{
	struct old_utsname uts;
	int i, flag;

	flag = 0;
	for (i = 1; i < argc; i++) {
		if (!strcmp("-a", argv[i])) {
			opt.sys = 1;
			opt.node = 1;
			opt.release = 1;
			opt.version = 1;
			opt.machine = 1;
			flag = 1;
		} else if (!strcmp("-s", argv[i])) {
			opt.sys = 1;
			flag = 1;
		} else if (!strcmp("-n", argv[i])) {
			opt.node = 1;
			flag = 1;
		} else if (!strcmp("-r", argv[i])) {
			opt.release = 1;
			flag = 1;
		} else if (!strcmp("-v", argv[i])) {
			opt.version = 1;
			flag = 1;
		} else if (!strcmp("-m", argv[i])) {
			opt.machine = 1;
			flag = 1;
		} else {
			fprintfs(stderr, "%s: invalid argument: %s\n",
				argv[0], argv[i]);
			exit( 1 );
		}
	}
	if (!flag)
		opt.sys = 1;

	if (uname(&uts)) {
		fprintfs(stderr, "%s: %s\n",
			argv[0], strerror(errno));
		exit( 1 );
	}

	flag = 0;
	if (opt.sys) {
		fputs(uts.sysname, stdout);
		flag = 1;
	}
	if (opt.node) {
		if (flag)
			putchar(' ');
		fputs(uts.nodename, stdout);
		flag = 1;
	}
	if (opt.release) {
		if (flag)
			putchar(' ');
		fputs(uts.release, stdout);
		flag = 1;
	}
	if (opt.version) {
		if (flag)
			putchar(' ');
		fputs(uts.version, stdout);
		flag = 1;
	}
	if (opt.machine) {
		if (flag)
			putchar(' ');
		fputs(uts.machine, stdout);
	}
	putchar('\n');
	exit(0);
}
