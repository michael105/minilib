/*
 * Copyright (c) 2014 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * The "file" built-in command.
 */

#include <ctype.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "sash.h"


static const char *	checkFile(const char * name);


int
do_file(int argc, const char ** argv)
{
	const char *	name;
	const char *	info;

	argc--;
	argv++;

	while (argc-- > 0)
	{
		name = *argv++;

		info = checkFile(name);

		if (info == NULL)
			info = "No information available";

		printf("%s: %s\n", name, info);
	}

	return 0;
}


/*
 * Examine the specified file and return a static string which
 * describes the file type.  Returns NULL on a failure.
 */
static const char *
checkFile(const char * name)
{
	int		mode;
	int		fd;
	int		cc;
	int		i;
	int		ch;
	int		badCount;
	char *		cp;
	struct	stat	statBuf;
	char		data[8192];
	static	char	info[1024];

	cp = info;
	*cp = '\0';

	if (lstat(name, &statBuf) < 0)
	{
		if (errno == ENOENT)
			return "non-existent";

		sprintf(cp, "stat failed: %s", strerror(errno));

		return info;
	}

	/*
	 * Check the file type.
	 */
	mode = statBuf.st_mode;

	if (S_ISDIR(mode))
		return "directory";

	if (S_ISCHR(mode))
		return "character device";

	if (S_ISBLK(mode))
		return "block device";

	if (S_ISFIFO(mode))
		return "named pipe";

#ifdef	S_ISLNK
	if (S_ISLNK(mode))
		return "symbolic link";
#endif

#ifdef	S_ISSOCK
	if (S_ISSOCK(mode))
		return "socket";
#endif

	/*
	 * If the file is not a regular file mention that.
	 */
	if (!S_ISREG(mode))
	{
		sprintf(cp, "unknown mode 0x%x, \n", mode);

		cp += strlen(cp);
	}

	/*
	 * Check for an executable file.
	 */
	if ((mode & (S_IEXEC | S_IXGRP | S_IXOTH)) != 0)
	{
		strcpy(cp, "executable, ");

		cp += strlen(cp);
	}

	/*
	 * The file is a normal file.
	 * Open it if we can and read in the first block.
	 */
	fd = open(name, O_RDONLY);

	if (fd < 0)
	{
		sprintf(cp, "unreadable: %s", strerror(errno));

		return info;
	}

	cc = read(fd, data, sizeof(data));

	if (cc < 0)
	{
		sprintf(cp, "read error: %s", strerror(errno));

		(void) close(fd);

		return info;
	}

	(void) close(fd);

	/*
	 * Check for an empty file.
	 */
	if (cc == 0)
	{
		strcpy(cp, "empty file");

		return info;
	}

	/*
	 * Check for a script file.
	 */
	if ((cc > 2) && (data[0] == '#') && (data[1] == '!'))
	{
		char *	begin;
		char *	end;

		data[sizeof(data) - 1] = '\0';

		begin = &data[2];

		while (*begin == ' ')
			begin++;

		end = begin;

		while (*end && (*end != ' ') && (*end != '\n'))
			end++;

		*end = '\0';

		sprintf(cp, "script for \"%s\"", begin);

		return info;
	}

	/*
	 * Check for special binary data types.
	 */
	if ((data[0] == '\037') && (data[1] == '\235'))
		return "compressed file";

	if ((data[0] == '\037') && (data[1] == '\213'))
		return "GZIP file";

	if ((data[0] == '\177') && (memcmp(&data[1], "ELF", 3) == 0))
	{
		strcpy(cp, "ELF program");

		return info;
	}

	/*
	 * Check for binary data.
	 */
	badCount = 0;

	for (i = 0; i < cc; i++)
	{
		ch = data[i];

		if ((ch == '\n') || (ch == '\t'))
			continue;

		if (isspace(ch) || isprint(ch))
			continue;

		badCount++;
	}

	if (badCount != 0)
	{
		strcpy(cp, "binary");

		return info;
	}

	/*
	 * It is just a text file.
	 */
	strcpy(cp, "text file");

	return info;
}

/* END CODE */
