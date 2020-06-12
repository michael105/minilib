/*
 * Copyright (c) 2014 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * The "find" built-in command.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>

#include "sash.h"


#ifdef	S_ISLNK
#define	LSTAT	lstat
#else
#define	LSTAT	stat
#endif


#define	MAX_NAME_SIZE	(1024 * 10)


/*
 * Items that can be specified to restrict the output.
 */
static	BOOL		xdevFlag;
static	dev_t		xdevDevice;
static	long		fileSize;
static	const char *	filePattern;
static	const char *	fileType;


/*
 * Recursive routine to examine the files in a directory.
 */
static	void	examineDirectory(const char * path);
static	BOOL	testFile(const char * fullName, const struct stat * statBuf);



/*
 * Find files from the specified directory path.
 * This is limited to just printing their file names.
 */
int
do_find(int argc, const char ** argv)
{
	const char *	cp;
	const char *	path;
	struct stat	statBuf;

	argc--;
	argv++;

	xdevFlag = FALSE;
	fileType = NULL;
	filePattern = NULL;
	fileSize = 0;

	if ((argc <= 0) || (**argv == '-'))
	{
		fprintf(stderr, "No path specified\n");

		return 1;
	}

	path = *argv++;
	argc--;

	while (argc > 0)
	{
		argc--;
		cp = *argv++;

		if (strcmp(cp, "-xdev") == 0)
			xdevFlag = TRUE;
		else if (strcmp(cp, "-type") == 0)
		{
			if ((argc <= 0) || (**argv == '-'))
			{
				fprintf(stderr, "Missing type string\n");

				return 1;
			}

			argc--;
			fileType = *argv++;
		}
		else if (strcmp(cp, "-name") == 0)
		{
			if ((argc <= 0) || (**argv == '-'))
			{
				fprintf(stderr, "Missing file name\n");

				return 1;
			}

			argc--;
			filePattern = *argv++;
		}
		else if (strcmp(cp, "-size") == 0)
		{
			if ((argc <= 0) || (**argv == '-'))
			{
				fprintf(stderr, "Missing file size\n");

				return 1;
			}

			argc--;
			cp = *argv++;

			fileSize = 0;

			while (isDecimal(*cp))
				fileSize = fileSize * 10 + (*cp++ - '0');

			if (*cp || (fileSize < 0))
			{
				fprintf(stderr, "Bad file size specified\n");

				return 1;
			}
		}
		else
		{
			if (*cp != '-')
				fprintf(stderr, "Missing dash in option\n");
			else
				fprintf(stderr, "Unknown option\n");

			return 1;
		}
	}

	/*
	 * Get information about the path and make sure that it
	 * is a directory.
	 */
	if (stat(path, &statBuf) < 0)
	{
		fprintf(stderr, "Cannot stat \"%s\": %s\n", path,
			strerror(errno));

		return 1;
	}

	if (!S_ISDIR(statBuf.st_mode))
	{
		fprintf(stderr, "Path \"%s\" is not a directory\n", path);

		return 1;
	}

	/*
	 * Remember the device that this directory is on in case we need it.
	 */
	xdevDevice = statBuf.st_dev;

	/*
	 * If the directory meets the specified criteria, then print it out.
	 */
	if (testFile(path, &statBuf))
		printf("%s\n", path);

	/*
	 * Now examine the files in the directory.
	 */
	examineDirectory(path);

	return 0;
}


/*
 * Recursive routine to examine the files in a directory.
 */
static void
examineDirectory(const char * path)
{
	DIR *		dir;
	BOOL		needSlash;
	struct dirent *	entry;
	struct stat	statBuf;
	char		fullName[MAX_NAME_SIZE];

	/*
	 * Open the directory.
	 */
	dir = opendir(path);

	if (dir == NULL)
	{
		fprintf(stderr, "Cannot read directory \"%s\": %s\n",
			path, strerror(errno));

		return;
	}

	/*
	 * See if a slash is needed.
	 */
	needSlash = (*path && (path[strlen(path) - 1] != '/'));

	/*
	 * Read all of the directory entries and check them,
	 * except for the current and parent directory entries.
	 */
	while (!intFlag && ((entry = readdir(dir)) != NULL))
	{
		if ((strcmp(entry->d_name, ".") == 0) ||
			(strcmp(entry->d_name, "..") == 0))
		{
			continue;
		}

		/*
		 * Build the full path name.
		 */
		strcpy(fullName, path);

		if (needSlash)
			strcat(fullName, "/");

		strcat(fullName, entry->d_name);

		/*
		 * Find out about this file.
		 */
		if (LSTAT(fullName, &statBuf) < 0)
		{
			fprintf(stderr, "Cannot stat \"%s\": %s\n",
				fullName, strerror(errno));

			continue;
		}

		/*
		 * If this file matches the criteria that was
		 * specified then print its name out.
		 */
		if (testFile(fullName, &statBuf))
			printf("%s\n", fullName);

		/*
		 * If this is a directory and we are allowed to cross
		 * mount points or the directory is still on the same
		 * device, then examine it's files too.
		 */
		if (S_ISDIR(statBuf.st_mode) &&
			(!xdevFlag || (statBuf.st_dev == xdevDevice)))
		{
			examineDirectory(fullName);
		}
	}

	closedir(dir);
}


/*
 * Test a file name having the specified status to see if it should
 * be acted on.  Returns TRUE if the file name has been selected.
 */
static BOOL
testFile(const char * fullName, const struct stat * statBuf)
{
	const char *	cp;
	const char *	entryName;
	BOOL		wantType;
	int		mode;

	mode = statBuf->st_mode;

	/*
	 * Check the file type if it was specified.
	 */
	if (fileType != NULL)
	{
		wantType = FALSE;

		for (cp = fileType; *cp; cp++)
		{
			switch (*cp)
			{
				case 'f':
					if (S_ISREG(mode))
						wantType = TRUE;
					break;

				case 'd':
					if (S_ISDIR(mode))
						wantType = TRUE;

					break;

				case 'p':
					if (S_ISFIFO(mode))
						wantType = TRUE;

					break;

				case 'c':
					if (S_ISCHR(mode))
						wantType = TRUE;

					break;

				case 'b':
					if (S_ISBLK(mode))
						wantType = TRUE;

					break;

				case 's':
					if (S_ISSOCK(mode))
						wantType = TRUE;

					break;

#ifdef	S_ISLNK
				case 'l':
					if (S_ISLNK(mode))
						wantType = TRUE;

					break;
#endif
				default:
					break;
			}
		}

		if (!wantType)
			return FALSE;
	}

	/*
	 * Check the file size if it was specified.
	 * This check only lets regular files and directories through.
	 */
	if (fileSize > 0)
	{
		if (!S_ISREG(mode) && !S_ISDIR(mode))
			return FALSE;

		if (statBuf->st_size < fileSize)
			return FALSE;
	}

	/*
	 * Check the file name pattern if it was specified.
	 */
	if (filePattern != NULL)
	{
		entryName = strrchr(fullName, '/');

		if (entryName)
			entryName++;
		else
			entryName = fullName;

		if (!match(entryName, filePattern))
			return FALSE;
	}

	/*
	 * This file name is wanted.
	 */
	return TRUE;
}

/* END CODE */
