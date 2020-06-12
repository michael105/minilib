/*
 * Copyright (c) 2014 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * The "ls" built-in command.
 */

#include "sash.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>


#define	LISTSIZE	8192


#ifdef	S_ISLNK
#define	LSTAT	lstat
#else
#define	LSTAT	stat
#endif


/*
 * Flags for the LS command.
 */
#define	LSF_LONG	0x01
#define	LSF_DIR		0x02
#define	LSF_INODE	0x04
#define	LSF_MULT	0x08
#define	LSF_FLAG	0x10
#define	LSF_COLUMN	0x20
#define	LSF_NUMERIC	0x40


/*
 * Data holding list of files.
 */
static	char **	list;
static	int	listSize;
static	int	listUsed;

/*
 * Cached user and group name data.
 */
static	char	userName[12];
static	int	userId;
static	BOOL	userIdKnown;
static	char	groupName[12];
static	int	groupId;
static	BOOL	groupIdKnown;


/*
 * Local procedures.
 */
static	void	listFile(
	const char *		name,
	const struct stat *	statBuf,
	int			flags,
	int			width
);

static	BOOL	addListName(const char * fileName);
static	void	listAllFiles(int flags, int displayWidth);
static	void	clearListNames(void);


int
do_ls(int argc, const char ** argv)
{
	const char *	cp;
	const char *	name;
	int		flags;
	int		i;
	int		displayWidth;
	BOOL		endSlash;
	DIR *		dirp;
	struct dirent *	dp;
	char		fullName[PATH_LEN];
	struct	stat	statBuf;
	int		r;

	static const char *	def[] = {"."};

	/*
	 * Reset for a new listing run.
	 */
	clearListNames();

	userIdKnown = FALSE;
	groupIdKnown = FALSE;

	displayWidth = 0;
	flags = 0;

	/*
	 * Handle options.
	 */
	argc--;
	argv++;

	while ((argc > 0) && (**argv == '-'))
	{
		cp = *argv++ + 1;
		argc--;

		while (*cp) switch (*cp++)
		{
			case 'l':	flags |= LSF_LONG; break;
			case 'n':	flags |= LSF_NUMERIC; break;
			case 'd':	flags |= LSF_DIR; break;
			case 'i':	flags |= LSF_INODE; break;
			case 'F':	flags |= LSF_FLAG; break;
			case 'C':	flags |= LSF_COLUMN; break;

			default:
				fprintf(stderr, "Unknown option -%c\n", cp[-1]);

				return 1;
		}
	}

	/*
	 * If long or numeric listing is specified then turn off column listing.
	 */
	if (flags & (LSF_LONG | LSF_NUMERIC))
		flags &= ~LSF_COLUMN;

	/*
	 * If column listing is specified then calculate the maximum
	 * width available for the columns of file names.
	 * This is settable using the COLS environment variable.
	 */
	if (flags & LSF_COLUMN)
	{
		name = getenv("COLS");

		if (name)
			displayWidth = atoi(name);

		if (displayWidth <= 0)
			displayWidth = 80;
	}

	/*
	 * If no arguments are given set up to show the current directory.
	 */
	if (argc <= 0)
	{
		argc = 1;
		argv = def;
	}

	if (argc > 1)
		flags |= LSF_MULT;

	/*
	 * Make one pass over the file names to collect together
	 * all of the files which are not directories.
	 * We will process them all as one list.
	 */
	for (i = 0; i < argc; i++)
	{
		if ((flags & LSF_DIR) || !isDirectory(argv[i]))
		{
			if (!addListName(argv[i]))
				return 1;
		}
	}

	/*
	 * List those file names, and then clear the list.
	 */
	listAllFiles(flags, displayWidth);
	clearListNames();

	/*
	 * If directories were being listed as themselves, then we are done.
	 */
	if (flags & LSF_DIR)
		return r;

	/*
	 * Now iterate over the file names processing the directories.
	 */
	while (!intFlag && (argc-- > 0))
	{
		name = *argv++;
		endSlash = (*name && (name[strlen(name) - 1] == '/'));

		if (LSTAT(name, &statBuf) < 0)
		{
			perror(name);
			r = 1;

			continue;
		}

		/*
		 * If this file name is not a directory, then ignore it.
		 */
		if (!S_ISDIR(statBuf.st_mode))
			continue;

		/*
		 * Collect all the files in the directory.
		 */
		dirp = opendir(name);

		if (dirp == NULL)
		{
			perror(name);

			continue;
		}

		if (flags & LSF_MULT)
			printf("\n%s:\n", name);

		while (!intFlag && ((dp = readdir(dirp)) != NULL))
		{
			fullName[0] = '\0';

			if ((*name != '.') || (name[1] != '\0'))
			{
				strcpy(fullName, name);

				if (!endSlash)
					strcat(fullName, "/");
			}

			strcat(fullName, dp->d_name);

			/*
			 * Save the file name in the list.
			 */
			if (!addListName(fullName))
			{
				closedir(dirp);

				return 1;
			}
		}

		closedir(dirp);

		/*
		 * List the files we collected in this directory,
		 * and then clear the list.
		 */
		listAllFiles(flags, displayWidth);
		clearListNames();
	}

	return r;
}


/*
 * List all of the files in the current list of files.
 * The files are displayed according to the specified flags,
 * in the specified display width.
 */
static void
listAllFiles(int flags, int displayWidth)
{
	const char *	name;
	const char *	cp;
	int		fileWidth;
	int		column;
	int		len;
	int		i;
	struct stat	statBuf;

	/*
	 * Initialise width data until we need it.
	 */
	fileWidth = 0;
	column = 0;

	/*
	 * Sort the files in the list.
	 */
	qsort((void *) list, listUsed, sizeof(char *), nameSort);

	/*
	 * If we are showing the files in columns then calculate the
	 * maximum width of all of the file names, taking into account
	 * various factors.
	 */
	if (flags & LSF_COLUMN)
	{
		for (i = 0; i < listUsed; i++)
		{
			len = strlen(list[i]);

			if (fileWidth < len)
				fileWidth = len;
		}

		if (flags & LSF_FLAG)
			fileWidth++;

		if (flags & LSF_INODE)
			fileWidth += 8;

		fileWidth += 2;
	}

	/*
	 * Now list the fileNames.
	 */
	for (i = 0; i < listUsed; i++)
	{
		name = list[i];

		if (LSTAT(name, &statBuf) < 0)
		{
			perror(name);

			continue;
		}

		cp = strrchr(name, '/');

		if (cp)
			cp++;
		else
			cp = name;

		/*
		 * List the file in the next column or at the end
		 * of a line depending on the width left.
		 */
		if (column + fileWidth * 2 >= displayWidth)
		{
			listFile(cp, &statBuf, flags, 0);
			column = 0;
		}
		else
		{
			listFile(cp, &statBuf, flags, fileWidth);
			column += fileWidth;
		}
	}

	/*
	 * Terminate the last file name if necessary.
	 */
	if (column > 0)
		fputc('\n', stdout);
}


/*
 * Do a listing of a particular file name according to the flags.
 * The output is shown within the specified width if it is nonzero,
 * or on its own line if the width is zero.
 */
static void
listFile(
	const char *		name,
	const struct stat *	statBuf,
	int			flags,
	int			width
)
{
	char *		cp;
	struct passwd *	pwd;
	struct group *	grp;
	int		len;
	int		mode;
	int		flagChar;
	int		usedWidth;
	char		buf[PATH_LEN];

	mode = statBuf->st_mode;

	/*
	 * Initialise buffers for use.
	 */
	cp = buf;
	buf[0] = '\0';
	flagChar = '\0';

	/*
	 * Show the inode number if requested.
	 */
	if (flags & LSF_INODE)
	{
		sprintf(cp, "%7ld ", statBuf->st_ino);
		cp += strlen(cp);
	}

	/*
	 * Create the long or numeric status line if requested.
	 */
	if (flags & (LSF_LONG | LSF_NUMERIC))
	{
		strcpy(cp, modeString(mode));
		cp += strlen(cp);

		sprintf(cp, "%3ld ", (long) statBuf->st_nlink);
		cp += strlen(cp);

		if (!userIdKnown || (statBuf->st_uid != userId))
		{
			if (flags & LSF_NUMERIC)
				pwd = 0;
			else
				pwd = getpwuid(statBuf->st_uid);

			if (pwd)
				strcpy(userName, pwd->pw_name);
			else
				sprintf(userName, "%d", statBuf->st_uid);

			userId = statBuf->st_uid;
			userIdKnown = TRUE;
		}

		sprintf(cp, "%-8s ", userName);
		cp += strlen(cp);

		if (!groupIdKnown || (statBuf->st_gid != groupId))
		{
			if (flags & LSF_NUMERIC)
				grp = 0;
			else
				grp = getgrgid(statBuf->st_gid);

			if (grp)
				strcpy(groupName, grp->gr_name);
			else
				sprintf(groupName, "%d", statBuf->st_gid);

			groupId = statBuf->st_gid;
			groupIdKnown = TRUE;
		}

		sprintf(cp, "%-8s ", groupName);
		cp += strlen(cp);

		if (S_ISBLK(mode) || S_ISCHR(mode))
		{
			sprintf(cp, "%3lu, %3lu ",
				((unsigned long) statBuf->st_rdev) >> 8,
				((unsigned long) statBuf->st_rdev) & 0xff);
		}
		else
			sprintf(cp, "%8ld ", statBuf->st_size);

		cp += strlen(cp);

		sprintf(cp, " %-12s ", timeString(statBuf->st_mtime));
	}

	/*
	 * Set the special character if the file is a directory or
	 * symbolic link or executable and the display was requested.
	 */
	if (flags & LSF_FLAG)
	{
		if (S_ISDIR(mode))
			flagChar = '/';
#ifdef S_ISLNK
		else if (S_ISLNK(mode))
			flagChar = '@';
#endif
		else if ((mode & 0111) != 0)
			flagChar = '*';
	}

	/*
	 * Print the status info followed by the file name.
	 */
	fputs(buf, stdout);
	fputs(name, stdout);

	if (flagChar)
		fputc(flagChar, stdout);

	/*
	 * Calculate the width used so far.
	 */
	usedWidth = strlen(buf) + strlen(name);

	if (flagChar)
		usedWidth++;

	/*
	 * Show where a symbolic link points.
	 */
#ifdef	S_ISLNK
	if ((flags & LSF_LONG) && S_ISLNK(mode))
	{
		len = readlink(name, buf, PATH_LEN - 1);

		if (len >= 0)
		{
			buf[len] = '\0';
			printf(" -> %s", buf);
		}

		usedWidth += strlen(buf) + 4;
	}
#endif

	/*
	 * If no width was given then just end the line with a newline.
	 */
	if (width == 0)
	{
		fputc('\n', stdout);

		return;
	}

	/*
	 * There is a width given.
	 * Print as many spaces as it takes to reach that width.
	 */
	while (usedWidth++ < width)
		fputc(' ', stdout);
}


/*
 * Save a file name to the end of the static list, reallocating if necessary.
 * The file name is copied into allocated memory owned by the list.
 * Returns TRUE on success.
 */
static BOOL
addListName(const char * fileName)
{
	char **	newList;

	/*
	 * Reallocate the list if necessary.
	 */
	if (listUsed >= listSize)
	{
		newList = realloc(list,
			((sizeof(char **)) * (listSize + LISTSIZE)));

		if (newList == NULL)
		{
			fprintf(stderr, "No memory for file name buffer\n");

			return FALSE;
		}

		list = newList;
		listSize += LISTSIZE;
	}

	/*
	 * Copy the file name into the next entry.
	 */
	list[listUsed] = strdup(fileName);

	if (list[listUsed] == NULL)
	{
		fprintf(stderr, "No memory for file name\n");

		return FALSE;
	}

	/*
	 * Increment the amount of space used.
	 */
	listUsed++;

	return TRUE;
}


/*
 * Free all of the names from the list of file names.
 */
static void
clearListNames(void)
{
	while (listUsed > 0)
	{
		listUsed--;

		free(list[listUsed]);
	}
}

/* END CODE */
