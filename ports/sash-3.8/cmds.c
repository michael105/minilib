/*
 * Copyright (c) 2014 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * Most simple built-in commands are here.
 */

#include "sash.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mount.h>
#include <signal.h>
#include <pwd.h>
#include <grp.h>
#include <utime.h>
#include <errno.h>

#if	HAVE_LINUX_MOUNT
#include <linux/fs.h>
#endif

/* Need to tell loop.h what the actual dev_t type is. */
#undef dev_t
#if defined(__alpha) || (defined(__sparc__) && defined(__arch64__))
#define dev_t unsigned int
#else
#define dev_t unsigned short
#endif
#include <linux/loop.h>
#undef dev_t
#define dev_t dev_t


int
do_echo(int argc, const char ** argv)
{
	BOOL	first;

	first = TRUE;

	while (argc-- > 1)
	{
		if (!first)
			fputc(' ', stdout);

		first = FALSE;
		fputs(*(++argv), stdout);
	}

	fputc('\n', stdout);

	return 0;
}


int
do_pwd(int argc, const char ** argv)
{
	char	buf[PATH_LEN];

	if (getcwd(buf, PATH_LEN) == NULL)
	{
		fprintf(stderr, "Cannot get current directory\n");

		return 1;
	}

	printf("%s\n", buf);

	return 0;
}


int
do_cd(int argc, const char ** argv)
{
	const char *	path;

	if (argc > 1)
		path = argv[1];
	else
	{
		path = getenv("HOME");

		if (path == NULL)
		{
			fprintf(stderr, "No HOME environment variable\n");

			return 1;
		}
	}

	if (chdir(path) < 0)
	{
		perror(path);

		return 1;
	}

	return 0;
}


int
do_mkdir(int argc, const char ** argv)
{
	int r = 0;

	while (argc-- > 1)
	{
		if (mkdir(argv[1], 0777) < 0)
		{
			perror(argv[1]);
			r = 1;
		}

		argv++;
	}

	return r;
}


int
do_mknod(int argc, const char ** argv)
{
	const char *	cp;
	int		mode;
	int		major;
	int		minor;

	mode = 0666;

	if (strcmp(argv[2], "b") == 0)
		mode |= S_IFBLK;
	else if (strcmp(argv[2], "c") == 0)
		mode |= S_IFCHR;
	else
	{
		fprintf(stderr, "Bad device type\n");

		return 1;
	}

	major = 0;
	cp = argv[3];

	while (isDecimal(*cp))
		major = major * 10 + *cp++ - '0';

	if (*cp || (major < 0) || (major > 255))
	{
		fprintf(stderr, "Bad major number\n");

		return 1;
	}

	minor = 0;
	cp = argv[4];

	while (isDecimal(*cp))
		minor = minor * 10 + *cp++ - '0';

	if (*cp || (minor < 0) || (minor > 255))
	{
		fprintf(stderr, "Bad minor number\n");

		return 1;
	}

	if (mknod(argv[1], mode, major * 256 + minor) < 0)
	{
		perror(argv[1]);

		return 1;
	}

	return 0;
}


#if HAVE_LINUX_PIVOT

int
do_pivot_root(int argc, const char ** argv)
{
	if (pivot_root(argv[1], argv[2]) < 0)
	{
		perror("pivot_root");

		return 1;
	}

	return 0;
}

#endif


#if HAVE_LINUX_CHROOT

int
do_chroot(int argc, const char ** argv)
{
	if (chroot(argv[1]) < 0)
	{
		perror("chroot");

		return 1;
	}

	return 0;
}

#endif


int
do_rmdir(int argc, const char ** argv)
{
	int r = 0;

	while (argc-- > 1)
	{
		if (rmdir(argv[1]) < 0)
		{
			perror(argv[1]);
			r = 1;
		}

		argv++;
	}

	return r;
}


int
do_sync(int argc, const char ** argv)
{
	sync();

	return 0;
}


int
do_rm(int argc, const char ** argv)
{
	int r = 0;

	while (argc-- > 1)
	{
		if (unlink(argv[1]) < 0)
		{
			perror(argv[1]);
			r = 1;
		}

		argv++;
	}

	return r;
}


int
do_chmod(int argc, const char ** argv)
{
	const char *	cp;
	int		mode;
	int		r;

	r = 0;
	mode = 0;
	cp = argv[1];

	while (isOctal(*cp))
		mode = mode * 8 + (*cp++ - '0');

	if (*cp)
	{
		fprintf(stderr, "Mode must be octal\n");

		return 1;
	}

	argc--;
	argv++;

	while (argc-- > 1)
	{
		if (chmod(argv[1], mode) < 0)
		{
			perror(argv[1]);
			r = 1;
		}

		argv++;
	}

	return r;
}


int
do_chown(int argc, const char ** argv)
{
	const char *	cp;
	int		uid;
	struct passwd *	pwd;
	struct stat	statBuf;
	int		r;

	r = 0;
	cp = argv[1];

	if (isDecimal(*cp))
	{
		uid = 0;

		while (isDecimal(*cp))
			uid = uid * 10 + (*cp++ - '0');

		if (*cp)
		{
			fprintf(stderr, "Bad uid value\n");

			return 1;
		}
	}
	else
	{
		pwd = getpwnam(cp);

		if (pwd == NULL)
		{
			fprintf(stderr, "Unknown user name\n");

			return 1;
		}

		uid = pwd->pw_uid;
	}

	argc--;
	argv++;

	while (argc-- > 1)
	{
		argv++;

		if ((stat(*argv, &statBuf) < 0) ||
			(chown(*argv, uid, statBuf.st_gid) < 0))
		{
			perror(*argv);
			r = 1;
		}
	}

	return r;
}


int
do_chgrp(int argc, const char ** argv)
{
	const char *	cp;
	int		gid;
	struct group *	grp;
	struct stat	statBuf;
	int		r;

	r = 0;
	cp = argv[1];

	if (isDecimal(*cp))
	{
		gid = 0;

		while (isDecimal(*cp))
			gid = gid * 10 + (*cp++ - '0');

		if (*cp)
		{
			fprintf(stderr, "Bad gid value\n");

			return 1;
		}
	}
	else
	{
		grp = getgrnam(cp);

		if (grp == NULL)
		{
			fprintf(stderr, "Unknown group name\n");

			return 1;
		}

		gid = grp->gr_gid;
	}

	argc--;
	argv++;

	while (argc-- > 1)
	{
		argv++;

		if ((stat(*argv, &statBuf) < 0) ||
			(chown(*argv, statBuf.st_uid, gid) < 0))
		{
			perror(*argv);
			r = 1;
		}
	}

	return r;
}


int
do_touch(int argc, const char ** argv)
{
	const char *	name;
	int		fd;
	struct utimbuf	now;
	int		r;

	r = 0;
	time(&now.actime);
	now.modtime = now.actime;

	while (argc-- > 1)
	{
		name = *(++argv);

		fd = open(name, O_CREAT | O_WRONLY | O_EXCL, 0666);

		if (fd >= 0)
		{
			close(fd);

			continue;
		}

		if (errno != EEXIST)
		{
			perror(name);
			r = 1;

			continue;
		}

		if (utime(name, &now) < 0)
		{
			perror(name);
			r = 1;
		}
	}

	return r;
}


int
do_mv(int argc, const char ** argv)
{
	const char *	srcName;
	const char *	destName;
	const char *	lastArg;
	BOOL		dirFlag;
	int		r;

	r = 0;
	lastArg = argv[argc - 1];

	dirFlag = isDirectory(lastArg);

	if ((argc > 3) && !dirFlag)
	{
		fprintf(stderr, "%s: not a directory\n", lastArg);

		return 1;
	}

	while (!intFlag && (argc-- > 2))
	{
		srcName = *(++argv);

		if (access(srcName, 0) < 0)
		{
			perror(srcName);
			r = 1;

			continue;
		}

		destName = lastArg;

		if (dirFlag)
			destName = buildName(destName, srcName);

		if (rename(srcName, destName) >= 0)
			continue;

		if (errno != EXDEV)
		{
			perror(destName);
			r = 1;

			continue;
		}

		if (!copyFile(srcName, destName, TRUE))
		{
			r = 1;

			continue;
		}

		if (unlink(srcName) < 0)
		{
			perror(srcName);
			r = 1;
		}
	}

	return r;
}


int
do_ln(int argc, const char ** argv)
{
	const char *	srcName;
	const char *	destName;
	const char *	lastArg;
	BOOL		dirFlag;
	int		r;

	r = 0;

	if (argv[1][0] == '-')
	{
		if (strcmp(argv[1], "-s"))
		{
			fprintf(stderr, "Unknown option\n");

			return 1;
		}

		if (argc != 4)
		{
			fprintf(stderr, "Wrong number of arguments for symbolic link\n");

			return 1;
		}

#ifdef	S_ISLNK
		if (symlink(argv[2], argv[3]) < 0)
		{
			perror(argv[3]);

			return 1;
		}

		return 0;
#else
		fprintf(stderr, "Symbolic links are not allowed\n");

		return 1;
#endif
	}

	/*
	 * Here for normal hard links.
	 */
	lastArg = argv[argc - 1];
	dirFlag = isDirectory(lastArg);

	if ((argc > 3) && !dirFlag)
	{
		fprintf(stderr, "%s: not a directory\n", lastArg);

		return 1;
	}

	while (argc-- > 2)
	{
		srcName = *(++argv);

		if (access(srcName, 0) < 0)
		{
			perror(srcName);
			r = 1;

			continue;
		}

		destName = lastArg;

		if (dirFlag)
			destName = buildName(destName, srcName);

		if (link(srcName, destName) < 0)
		{
			perror(destName);
			r = 1;

			continue;
		}
	}

	return r;
}


int
do_cp(int argc, const char ** argv)
{
	const char *	srcName;
	const char *	destName;
	const char *	lastArg;
	BOOL		dirFlag;
	int		r;

	r = 0;
	lastArg = argv[argc - 1];

	dirFlag = isDirectory(lastArg);

	if ((argc > 3) && !dirFlag)
	{
		fprintf(stderr, "%s: not a directory\n", lastArg);

		return 1;
	}

	while (!intFlag && (argc-- > 2))
	{
		srcName = *(++argv);
		destName = lastArg;

		if (dirFlag)
			destName = buildName(destName, srcName);

		if (!copyFile(srcName, destName, FALSE))
			r = 1;
	}

	return r;
}


int
do_mount(int argc, const char ** argv)
{
	#if 0
	const char *	str;
	const char *	type;
	int		flags;

	argc--;
	argv++;

	type = MOUNT_TYPE;

#if	HAVE_LINUX_MOUNT
	flags = MS_MGC_VAL;
#else
	flags = 0;
#endif

	while ((argc > 0) && (**argv == '-'))
	{
		argc--;
		str = *argv++;

		while (*++str) switch (*str)
		{
			case 't':
				if ((argc <= 0) || (**argv == '-'))
				{
					fprintf(stderr, "Missing file system type\n");

					return 1;
				}

				type = *argv++;
				argc--;
				break;

#if	HAVE_LINUX_MOUNT
			case 'r':
				flags |= MS_RDONLY;
				break;

			case 'm':
				flags |= MS_REMOUNT;
				break;

			case 's':
				flags |= MS_NOSUID;
				break;

			case 'e':
				flags |= MS_NOEXEC;
				break;

#elif	HAVE_BSD_MOUNT
			case 'r':
				flags |= MNT_RDONLY;
				break;

			case 's':
				flags |= MNT_NOSUID;
				break;

			case 'e':
				flags |= MNT_NOEXEC;
				break;
#endif
			default:
				fprintf(stderr, "Unknown option\n");

				return 1;
		}
	}

	if (argc != 2)
	{
		fprintf(stderr, "Wrong number of arguments for mount\n");

		return 1;
	}

#if	HAVE_LINUX_MOUNT

	if (mount(argv[0], argv[1], type, flags, 0) < 0)
	{
		perror("mount failed");
		return 1;
	}
#elif	HAVE_BSD_MOUNT
	{
		struct	    ufs_args ufs;
		struct	    adosfs_args adosfs;
		struct	    iso_args iso;
		struct	    mfs_args mfs;
		struct	    msdosfs_args msdosfs;
		void *	    args;

		if (!strcmp(type, "ffs") || !strcmp(type, "ufs"))
		{
			ufs.fspec = (char*) argv[0];
			args = &ufs;
		}
		else if (!strcmp(type, "adosfs"))
		{
			adosfs.fspec = (char*) argv[0];
			adosfs.uid = 0;
			adosfs.gid = 0;
			args = &adosfs;
		}
		else if (!strcmp(type, "cd9660"))
		{
			iso.fspec = (char*) argv[0];
			args = &iso;
		}
		else if (!strcmp(type, "mfs"))
		{
			mfs.fspec = (char*) argv[0];
			args = &mfs;
		}
		else if (!strcmp(type, "msdos"))
		{
			msdosfs.fspec = (char*) argv[0];
			msdosfs.uid = 0;
			msdosfs.gid = 0;
			args = &msdosfs;
		}
		else
		{
			fprintf(stderr, "Unknown filesystem type: %s", type);
			fprintf(stderr,
			    "Supported: ffs ufs adosfs cd9660 mfs msdos\n");

			return 1;
		}

		if (mount(type, argv[1], flags, args) < 0)
		{
			perror(argv[0]);

			return 1;
		}
	}
#endif
#endif
	return 0;
}


int
do_umount(int argc, const char ** argv)
{
#if	HAVE_LINUX_MOUNT
	if (umount(argv[1]) < 0)
	{
		perror(argv[1]);

		return 1;
	}
#elif	HAVE_BSD_MOUNT
	{
		const char *	str;
		int		flags = 0;

		for (argc--, argv++;
		    (argc > 0) && (**argv == '-');)
		{
			argc--;
			str = *argv++;

			while (*++str)
{
				switch (*str)
				{
					case 'f':
						flags = MNT_FORCE;
						break;
				}
			}
		}

		if (unmount(argv[0], flags) < 0)
		{
			perror(argv[0]);

			return 1;
		}
	}
#endif
	return 0;
}


int
do_cmp(int argc, const char ** argv)
{
	int		fd1;
	int		fd2;
	int		cc1;
	int		cc2;
	long		pos;
	const char *	bp1;
	const char *	bp2;
	char		buf1[BUF_SIZE];
	char		buf2[BUF_SIZE];
	struct	stat	statBuf1;
	struct	stat	statBuf2;
	int		r;

	r = 0;

	if (stat(argv[1], &statBuf1) < 0)
	{
		perror(argv[1]);

		return 1;
	}

	if (stat(argv[2], &statBuf2) < 0)
	{
		perror(argv[2]);

		return 1;
	}

	if ((statBuf1.st_dev == statBuf2.st_dev) &&
		(statBuf1.st_ino == statBuf2.st_ino))
	{
		printf("Files are links to each other\n");

		return 0;
	}

	if (statBuf1.st_size != statBuf2.st_size)
	{
		printf("Files are different sizes\n");

		return 1;
	}

	fd1 = open(argv[1], O_RDONLY);

	if (fd1 < 0)
	{
		perror(argv[1]);

		return 1;
	}

	fd2 = open(argv[2], O_RDONLY);

	if (fd2 < 0)
	{
		perror(argv[2]);
		close(fd1);

		return 1;
	}

	pos = 0;

	while (TRUE)
	{
		if (intFlag)
			goto closefiles;

		cc1 = read(fd1, buf1, sizeof(buf1));

		if (cc1 < 0)
		{
			perror(argv[1]);
			r = 1;
			goto closefiles;
		}

		cc2 = read(fd2, buf2, sizeof(buf2));

		if (cc2 < 0)
		{
			perror(argv[2]);
			r = 1;
			goto closefiles;
		}

		if ((cc1 == 0) && (cc2 == 0))
		{
			printf("Files are identical\n");
			r = 0;
			goto closefiles;
		}

		if (cc1 < cc2)
		{
			printf("First file is shorter than second\n");
			r = 1;
			goto closefiles;
		}

		if (cc1 > cc2)
		{
			printf("Second file is shorter than first\n");
			r = 1;
			goto closefiles;
		}

		if (memcmp(buf1, buf2, cc1) == 0)
		{
			pos += cc1;

			continue;
		}

		bp1 = buf1;
		bp2 = buf2;

		while (*bp1++ == *bp2++)
			pos++;

		printf("Files differ at byte position %ld\n", pos);
		r = 1;

		goto closefiles;
	}

closefiles:
	close(fd1);
	close(fd2);

	return r;
}


int
do_more(int argc, const char ** argv)
{
	FILE *		fp;
	const char *	name;
	int		ch;
	int		line;
	int		col;
	int		pageLines;
	int		pageColumns;
	char		buf[80];

	/*
	 * Get the width and height of the screen if it is set.
	 * If not, then default it.
	 */
	pageLines = 0;
	pageColumns = 0;

	name = getenv("LINES");

	if (name)
		pageLines = atoi(name);

	name = getenv("COLS");

	if (name)
		pageColumns = atoi(name);

	if (pageLines <= 0)
		pageLines = 24;

	if (pageColumns <= 0)
		pageColumns = 80;

	/*
	 * OK, process each file.
	 */
	while (argc-- > 1)
	{
		name = *(++argv);

		fp = fopen(name, "r");

		if (fp == NULL)
		{
			perror(name);

			return 1;
		}

		printf("<< %s >>\n", name);
		line = 1;
		col = 0;

		while (fp && ((ch = fgetc(fp)) != EOF))
		{
			switch (ch)
			{
				case '\r':
					col = 0;
					break;

				case '\n':
					line++;
					col = 0;
					break;

				case '\t':
					col = ((col + 1) | 0x07) + 1;
					break;

				case '\b':
					if (col > 0)
						col--;
					break;

				default:
					col++;
			}

			putchar(ch);

			if (col >= pageColumns)
			{
				col -= pageColumns;
				line++;
			}

			if (line < pageLines)
				continue;

			if (col > 0)
				putchar('\n');

			printf("--More--");
			fflush(stdout);

			if (intFlag || (read(0, buf, sizeof(buf)) < 0))
			{
				if (fp)
					fclose(fp);

				return 0;
			}

			ch = buf[0];

			if (ch == ':')
				ch = buf[1];

			switch (ch)
			{
				case 'N':
				case 'n':
					fclose(fp);
					fp = NULL;
					break;

				case 'Q':
				case 'q':
					fclose(fp);

					return 0;
			}

			col = 0;
			line = 1;
		}

		if (fp)
			fclose(fp);
	}

	return 0;
}


int
do_sum(int argc, const char ** argv)
{
	const char *	name;
	int		fd;
	int		cc;
	int		ch;
	int		i;
	unsigned long	checksum;
	char		buf[BUF_SIZE];
	int		r;

	argc--;
	argv++;
	r = 0;

	while (argc-- > 0)
	{
		name = *argv++;

		fd = open(name, O_RDONLY);

		if (fd < 0)
		{
			perror(name);
			r = 1;

			continue;
		}

		checksum = 0;

		while ((cc = read(fd, buf, sizeof(buf))) > 0)
		{
			for (i = 0; i < cc; i++)
			{
				ch = buf[i];

				if ((checksum & 0x01) != 0)
					checksum = (checksum >> 1) + 0x8000;
				else
					checksum = (checksum >> 1);

				checksum = (checksum + ch) & 0xffff;
			}
		}

		if (cc < 0)
		{
			perror(name);
			r = 1;

			(void) close(fd);

			continue;
		}

		(void) close(fd);

		printf("%05lu %s\n", checksum, name);
	}

	return r;
}


int
do_exit(int argc, const char ** argv)
{
	int r = 0;

	if (getpid() == 1)
	{
		fprintf(stderr, "You are the INIT process!\n");

		return 1;
	}

	if (argc == 2)
	{
		r = atoi(argv[1]);
	}

	exit(r);

	return 1;
}


int
do_setenv(int argc, const char ** argv)
{
	const char *	name;
	const char *	value;
	char *		str;

	name = argv[1];
	value = argv[2];

	/*
	 * The value given to putenv must remain around, so we must malloc it.
	 * Note: memory is not reclaimed if the same variable is redefined.
	 */
	str = malloc(strlen(name) + strlen(value) + 2);

	if (str == NULL)
	{
		fprintf(stderr, "Cannot allocate memory\n");

		return 1;
	}

	strcpy(str, name);
	strcat(str, "=");
	strcat(str, value);

	putenv(str);

	return 0;
}


int
do_printenv(int argc, const char ** argv)
{
	const char **	env;
	extern char **	environ;
	int		len;

	env = (const char **) environ;

	if (argc == 1)
	{
		while (*env)
			printf("%s\n", *env++);

		return 0;
	}

	len = strlen(argv[1]);

	while (*env)
	{
		if ((strlen(*env) > len) && (env[0][len] == '=') &&
			(memcmp(argv[1], *env, len) == 0))
		{
			printf("%s\n", &env[0][len+1]);

			return 0;
		}
		env++;
	}

	return 0;
}


int
do_umask(int argc, const char ** argv)
{
	const char *	cp;
	int		mask;

	if (argc <= 1)
	{
		mask = umask(0);
		umask(mask);
		printf("%03o\n", mask);

		return 0;
	}

	mask = 0;
	cp = argv[1];

	while (isOctal(*cp))
		mask = mask * 8 + *cp++ - '0';

	if (*cp || (mask & ~0777))
	{
		fprintf(stderr, "Bad umask value\n");

		return 1;
	}

	umask(mask);

	return 0;
}


int
do_kill(int argc, const char ** argv)
{
	const char *	cp;
	int		sig;
	int		pid;
	int		r;

	r = 0;
	sig = SIGTERM;

	if (argv[1][0] == '-')
	{
		cp = &argv[1][1];

		if (strcmp(cp, "HUP") == 0)
			sig = SIGHUP;
		else if (strcmp(cp, "INT") == 0)
			sig = SIGINT;
		else if (strcmp(cp, "QUIT") == 0)
			sig = SIGQUIT;
		else if (strcmp(cp, "KILL") == 0)
			sig = SIGKILL;
		else if (strcmp(cp, "STOP") == 0)
			sig = SIGSTOP;
		else if (strcmp(cp, "CONT") == 0)
			sig = SIGCONT;
		else if (strcmp(cp, "USR1") == 0)
			sig = SIGUSR1;
		else if (strcmp(cp, "USR2") == 0)
			sig = SIGUSR2;
		else if (strcmp(cp, "TERM") == 0)
			sig = SIGTERM;
		else
		{
			sig = 0;

			while (isDecimal(*cp))
				sig = sig * 10 + *cp++ - '0';

			if (*cp)
			{
				fprintf(stderr, "Unknown signal\n");

				return 1;
			}
		}

		argc--;
		argv++;
	}

	while (argc-- > 1)
	{
		cp = *(++argv);
		pid = 0;

		while (isDecimal(*cp))
			pid = pid * 10 + *cp++ - '0';

		if (*cp)
		{
			fprintf(stderr, "Non-numeric pid\n");

			return 1;
		}

		if (kill(pid, sig) < 0)
		{
			perror(*argv);
			r = 1;
		}
	}

	return r;
}


int
do_where(int argc, const char ** argv)
{
	const char *	program;
	const char *	dirName;
	char *		path;
	char *		endPath;
	char *		fullPath;
	BOOL		found;
	int		r;

	found = FALSE;
	program = argv[1];

	if (strchr(program, '/') != NULL)
	{
		fprintf(stderr, "Program name cannot include a path\n");

		return 1;
	}

	path = getenv("PATH");

	fullPath = getChunk(strlen(path) + strlen(program) + 2);
	path = chunkstrdup(path);

	if ((path == NULL) || (fullPath == NULL))
	{
		fprintf(stderr, "Memory allocation failed\n");

		return 1;
	}

	/*
	 * Check out each path to see if the program exists and is
	 * executable in that path.
	 */
	for (; path; path = endPath)
	{
		/*
		 * Find the end of the next path and NULL terminate
		 * it if necessary.
		 */
		endPath = strchr(path, ':');

		if (endPath)
			*endPath++ = '\0';

		/*
		 * Get the directory name, defaulting it to DOT if
		 * it is null.
		 */
		dirName = path;

		if (dirName == '\0')
			dirName = ".";

		/*
		 * Construct the full path of the program.
		 */
		strcpy(fullPath, dirName);
		strcat(fullPath, "/");
		strcat(fullPath, program);

		/*
		 * See if the program exists and is executable.
		 */
		if (access(fullPath, X_OK) < 0)
		{
			if (errno != ENOENT)
			{
				perror(fullPath);
				r = 1;
			}

			continue;
		}

		printf("%s\n", fullPath);
		found = TRUE;
	}

	if (!found)
	{
		printf("Program \"%s\" not found in PATH\n", program);
		r = 1;
	}

	return r;
}

#if HAVE_LINUX_LOSETUP

int
do_losetup(int argc, const char ** argv)
{
	int loopfd;
	int targfd;
	struct loop_info loopInfo;

	if (!strcmp(argv[1], "-d"))
	{
		loopfd = open(argv[2], O_RDWR);

		if (loopfd < 0)
		{
			fprintf(stderr, "Error opening %s: %s\n", argv[2], 
				strerror(errno));

			return 1;
		}

		if (ioctl(loopfd, LOOP_CLR_FD, 0))
		{
			fprintf(stderr, "Error unassociating device: %s\n", 
				strerror(errno));

			return 1;
		}
	}

	loopfd = open(argv[1], O_RDWR);

	if (loopfd < 0)
	{
		fprintf(stderr, "Error opening %s: %s\n", argv[1], 
			strerror(errno));

		return 1;
	}

	targfd = open(argv[2], O_RDWR);

	if (targfd < 0)
	{
		fprintf(stderr, "Error opening %s: %s\n", argv[2], 
			strerror(errno));

		return 1;
	}

	if (ioctl(loopfd, LOOP_SET_FD, targfd))
	{
		fprintf(stderr, "Error setting up loopback device: %s\n", 
			strerror(errno));

		return 1;
	}

	memset(&loopInfo, 0, sizeof(loopInfo));
	strcpy(loopInfo.lo_name, argv[2]);

	if (ioctl(loopfd, LOOP_SET_STATUS, &loopInfo))
	{
		fprintf(stderr, "Error setting up loopback device: %s\n", 
			strerror(errno));

		return 1;
	}

	return 0;
}

#endif

/* END CODE */
