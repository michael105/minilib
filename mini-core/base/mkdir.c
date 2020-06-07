
static struct {
	const char *argv0;
	char parents : 1;
} opt;

static int do_parents_mkdir(const char *path)
{
	const char *parent;
	char *path2;

	if (!strcmp(path, "/") || !strcmp(path, "."))
		return 0;
	path2 = strdup(path);
	if (!path2) {
		fprintf(stderr, "%s: unable to allocate: %s\n",
			opt.argv0, strerror(errno));
		return 1;
	}
	parent = dirname(path2);
	do_parents_mkdir(parent);
	if (mkdir(path, 0777)) {
		fprintf(stderr, "%s: %s: %s\n",
			opt.argv0, path, strerror(errno));
		return 1;
	}
	free(path2);
	return 0;
}

static int do_mkdir(const char *path)
{
	if (mkdir(path, 0777)) {
		fprintf(stderr, "%s: %s: %s\n",
			opt.argv0, path, strerror(errno));
		return 1;
	}
	return 0;
}

void usage(){
	writes("Usage: mkdir [-p] dirname\n");
	exit(1);
}

/* Usage mkdir [-p] DIRECTORY... */
int main(int argc, const char *argv[])
{
	int (*mkdir_func)(const char *);
	int i, ret;

	opt.argv0 = argv[0];
	for (i = 1; i < argc; i++) {
		if (argv[i][0] != '-') {
			break;
		} else if (!strcmp(argv[i], "-p")) {
			opt.parents = 1;
		} else {
				usage();
		}
	}
	if (i == argc) {
			usage();
	}

	mkdir_func = (opt.parents) ? do_parents_mkdir : do_mkdir;
	ret = 0;
	for (; i < argc; i++) {
		if (mkdir_func(argv[i]))
			ret = 1;
	}
	return ret;
}
