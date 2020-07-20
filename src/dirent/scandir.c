//+doc list files and dirs in a directory
// This implementation uses malloc_brk() for the dynamic allocation
// of the listing.
//+depends errno malloc realloc free memcpy
//+def
int scandir(const char *path, struct dirent ***listing,
	int (*fp_select)(const struct dirent *),
	int (*cmp)(const struct dirent **, const struct dirent **)){

	struct dirent *de, **names=0, **tmp;
	size_t cnt=0, len=0;

	DIR *d = opendir(path);
	int old_errno = errno;

	if (!d) return -1;

	while ((errno=0), (de = readdir(d))) {
		if (fp_select && !fp_select(de)) continue;
		if (cnt >= len) {
			len = 2*len+1;
			if (len > SIZE_MAX/sizeof *names) break;
			tmp = realloc(names, len * sizeof *names);
			if (!tmp) break;
			names = tmp;
		}
		names[cnt] = malloc(de->d_reclen);
		if (!names[cnt]) break;
		memcpy(names[cnt++], de, de->d_reclen);
	}

	closedir(d);

	if (errno) {
		if (names) while (cnt-->0) free(names[cnt]);
		free(names);
		return -1;
	}
	errno = old_errno;

	//if (cmp) qsort(names, cnt, sizeof *names, (int (*)(const void *, const void *))cmp);
	*listing = names;
	return cnt;
}

