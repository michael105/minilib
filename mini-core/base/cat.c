// Original work by ammongit (github.com/ammongit/minutils)
// Modified by misc 2019

#include <fcntl.h>
#include <unistd.h>

#include <errno.h>
#include <stdio.h>
#include <string.h>


int cat(int fd)
{
	char buf[4096];
	ssize_t n;

	while ((n = read(fd, buf, sizeof(buf))) > 0) {
		if (write(STDOUT_FILENO, buf, n) != n) {
			fputs("cat: ", stderr );
			fputs(strerror(errno), stderr);
			return 1;
		}
	}
	return 0;
}

/* Usage: cat [FILE...] */
int main(int argc, const char *argv[])
{
	int i;

	if (argc == 1) {
		return cat(STDIN_FILENO);
	} else for (i = 1; i < argc; i++) {
		int fd;

		fd = open(argv[i], O_RDONLY);
		if (fd < 0) {
			fprintfs(stderr, "%s: Couldn't open %s, %s\n",
				argv[0], argv[i], strerror(errno));
			return 1;
		}
		if (cat(fd))
			return 1;
		if (close(fd)) {
			fprintfs(stderr, "%s: %s: %s\n",
				argv[0], argv[i], strerror(errno));
			return 1;
		}
	}
	return 0;
}
