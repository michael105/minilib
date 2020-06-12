/*
 * Original:
 * Copyright (c) 1999 by Aaron R. Crane.
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * Modified:
 * Copyright (c) 2014 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * The "ar" built-in command.
 * This allows extraction and listing of ar files.
 */

#include <ar.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "sash.h"


/*
 * Structure to hold information about the archive file.
 */
typedef struct
{
	int	fd;		/* file reading archive from */
	BOOL	eof;		/* end of file has been seen */
	BOOL	rescan;		/* rescan the header just read */
	char *	nameTable;	/* long name table */

	/*
	 * Information about the current file read from the archive.
	 * This is extracted from the latest member header read.
	 */
	char *	name;		/* current file name */
	time_t	date;		/* date of file */
	uid_t	uid;		/* user id */
	gid_t	gid;		/* group id */
	mode_t	mode;		/* file protection */
	off_t	size;		/* file size */
	int	pad;		/* padding to next header */
} Archive;


/*
 * Local procedures.
 */
static	void	initArchive(Archive * arch);
static	BOOL	openArchive(const char * name, Archive * arch);
static	void	closeArchive(Archive * arch);
static	BOOL	readSpecialMember(Archive * arch);
static	BOOL	readNormalMember(Archive * arch);
static	BOOL	readMember(Archive * arch, struct ar_hdr * hdr);
static	BOOL	skipMember(const Archive * arch);
static	BOOL	skipPadding(int fd, int pad);
static	BOOL	writeFile(const Archive * arch, int outfd);
static	int	createFile(const Archive * arch);
static	BOOL	canonicalize(Archive * arch, const struct ar_hdr * hdr);
static	void	listMember(const Archive * arch);
static	int	shortNameMatches44BSD(const char * name);
static	int	shortNameMatchesSysV(const char * name);

static	BOOL	wantMember(const Archive * arch, int n_names,
			const char ** names);

static BOOL	getNumber(const char * s, unsigned base, int max_digits,
			unsigned long * ul);


int
do_ar(int argc, const char ** argv)
{
	const char *	options;
	const char *	archiveName;
	BOOL		doExtract;
	BOOL		doTable;
	BOOL		doPrint;
	BOOL		verbose;
	int		r;
	Archive		arch;

	r = 0;
	verbose = FALSE;
	doExtract = FALSE;
	doTable = FALSE;
	doPrint = FALSE;

	if (argc < 3)
	{
		fprintf(stderr, "Too few arguments for ar\n");

		return 1;
	}

	/*
	 * Get the option string and archive file name.
	 */
	options = argv[1];
	archiveName = argv[2];

	/*
	 * Advance the arguments to the list of file names (if any).
	 */
	argc -= 3;
	argv += 3;

	/*
	 * Parse the option characters.
	 */
	for (; *options; options++)
	{
		switch (*options)
		{
		case 't':
			doTable = TRUE;
			break;

		case 'x':
			doExtract = TRUE;
			break;

		case 'p':
			doPrint = TRUE;
			break;

		case 'v':
			verbose = TRUE;
			break;

		case 'd': case 'm': case 'q': case 'r':
			fprintf(stderr, "Writing ar files is not supported\n");

			return 1;

		default:
			fprintf(stderr, "Unknown ar flag: %c\n", *options);

			return 1;
		}
	}

	if (doExtract + doTable + doPrint != 1)
	{
		fprintf(stderr,
			"Exactly one of 'x', 'p' or 't' must be specified\n");

		return 1;
	}

	/*
	 * Open the archive file.
	 */
	initArchive(&arch);

	if (!openArchive(archiveName, &arch))
		return 1;

	/*
	 * Read the first special member of the archive.
	 */
	if (!readSpecialMember(&arch))
		return 1;

	/*
	 * Read all of the normal members of the archive.
	 */
	while (readNormalMember(&arch))
	{
		/*
		 * If this file is not wanted then skip it.
		 */
		if (!wantMember(&arch, argc, argv))
		{
			if (!skipMember(&arch))
				break;

			continue;
		}

		/*
		 * This file is wanted.
		 */
		if (doTable)
		{
			if (verbose)
				listMember(&arch);
			else
				puts(arch.name);

			if (!skipMember(&arch))
				break;
		}
		else if (doPrint)
		{
			if (verbose)
			{
				/*
				 * The verbose format makes me gag,
				 * but 4.4BSD, GNU and even V7 all
				 * have the same lossage.
				 */
				printf("\n<%s>\n\n", arch.name);
				fflush(stdout);
			}

			if (!writeFile(&arch, STDOUT))
				break;
		}
		else if (doExtract)
		{
			int	outfd;
			BOOL	success;

			if (verbose)
				printf("x - %s\n", arch.name);

			outfd = createFile(&arch);

			if (outfd == -1)
				break;

			success = writeFile(&arch, outfd);

			if (close(outfd) == -1)
			{
				fprintf(stderr, "Can't close %s: %s\n",
					arch.name, strerror(errno));

				break;
			}

			if (!success)
			{
				r = 1;
				break;
			}
		}
		else
		{
			fprintf(stderr, "Oops -- I don't know what to do\n");
			r = 1;
			break;
		}
	}

	closeArchive(&arch);

	return r;
}


/*
 * Open the file for writing for the specified archive structure,
 * setting its mode and owner if possible.  Returns the file handle
 * of the opened file, or -1 on an error.
 */
static int
createFile(const Archive * arch)
{
	int	fd;

	fd = open(arch->name, O_WRONLY | O_CREAT | O_TRUNC, arch->mode);

	if (fd == -1)
	{
		fprintf(stderr, "Can't create \"%s\": %s\n",
			arch->name, strerror(errno));

		return -1;
	}

	/*
	 * Don't worry if these fail.  We have to do the fchmod() despite
	 * specifying the mode in the open() call, because that mode is
	 * munged by the umask.
	 */
	checkStatus("fchmod", fchmod(fd, arch->mode));
	checkStatus("fchown", fchown(fd, arch->uid, arch->gid));

	return fd;
}


/*
 * Return whether the current archive member is wanted.
 * This means that the file name is contained in the specified list of
 * file names, or else that the specified list of file names is empty.
 */
static BOOL
wantMember(const Archive * arch, int n_names, const char ** name)
{
	int	i;

	/*
	 * If there are no names then all archive members are wanted.
	 */
	if (n_names == 0)
		return TRUE;

	/*
	 * See if the member file name is contained in the list.
	 */
	for (i = 0; i < n_names; i++)
	{
		if (strcmp(arch->name, name[i]) == 0)
			return TRUE;
	}

	return FALSE;
}


/*
 * Parse a number from the specified string in the specified base.
 * The number is terminated by a null, space, or the specified number
 * of digits.  The number is returned through the supplied pointer.
 * Only non-negatives numbers are parsed.  Returns TRUE on success.
 */
static BOOL
getNumber(const char * s, unsigned base, int max_digits, unsigned long * ul)
{
	const char *	p;
	const char *	endp;
	unsigned long	cutoff;
	unsigned long	cutlim;

	if (base < 2 || base > 10  ||  s == 0 || *s == 0  ||  ul == 0)
		return FALSE;

	cutoff = ULONG_MAX / (unsigned long) base;
	cutlim = ULONG_MAX % (unsigned long) base;
	*ul = 0;

	endp = (max_digits >= 0) ? s + max_digits : 0;

	for (p = s;  endp ? p < endp : 1;  p++)
	{
		unsigned d;

		if (*p == 0 || *p == ' ')
			break;	/* end of string */

		if (!isDecimal(*p))
			return FALSE; /* non-digit */

		d = *p - '0';

		if (d >= base)
			return FALSE; /* digit outside range for base */

		if (*ul > cutoff || (*ul == cutoff && d > cutlim))
			return FALSE; /* overflow */

		*ul *= base;
		*ul += d;
	}

	if (p == s)
		return FALSE;	/* nothing was converted */

	if (*p && *p != ' ')
		return FALSE;	/* trailing garbage */

	return TRUE;
}


/*
 * Initialise the specified Archive structure for use.
 */
static void
initArchive(Archive * arch)
{
	arch->fd = -1;
	arch->name = 0;
	arch->nameTable = 0;
	arch->eof = FALSE;
	arch->rescan = FALSE;
}


/*
 * Open the specified archive file name and read the header from it.
 * The file handle is saved in the Archive structure for further use.
 * Returns TRUE on success.
 */
static BOOL
openArchive(const char * name, Archive * arch)
{
	unsigned char	buf[SARMAG];
	ssize_t		cc;

	arch->fd = open(name, O_RDONLY);

	if (arch->fd == -1)
	{
		fprintf(stderr, "Can't open archive file %s: %s\n",
			name, strerror(errno));

		return FALSE;
	}

	cc = read(arch->fd, buf, SARMAG);

	if (cc == -1)
	{
		fprintf(stderr, "Error reading archive header: %s\n",
			strerror(errno));

		goto close_and_out;
	} 

	if (cc != SARMAG)
	{
		fprintf(stderr, "Short read of archive header\n");

		goto close_and_out;
	}

	if (memcmp(buf, ARMAG, SARMAG))
	{
		fprintf(stderr, "Invalid archive header\n");

		goto close_and_out;
	}

	return TRUE;


	/*
	 * Here on an error to clean up.
	 */
close_and_out:
	(void) close(arch->fd);
	arch->fd = -1;

	return FALSE;
}


/*
 * Close the archive file.
 */
static void
closeArchive(Archive * arch)
{
	free(arch->name);
	arch->name = 0;

	free(arch->nameTable);
	arch->nameTable = 0;

	if (arch->fd >= 0)
		(void) close(arch->fd);

	arch->fd = -1;
}


/*
 * Read an archive member header into the specified structure.
 * Returns TRUE on success.  On failure, the eof flag is set if
 * the end of file had been reached.
 */
static BOOL
readMember(Archive * arch, struct ar_hdr * hdr)
{
	ssize_t	cc;

	cc = read(arch->fd, hdr, sizeof(*hdr));

	if (cc < 0)
	{
		fprintf(stderr, "Error reading member header: %s\n",
			strerror(errno));

		return FALSE;
	}

	if (cc == 0)
	{
		arch->eof = TRUE;

		return FALSE;
	}

	if (cc != sizeof(*hdr))
	{
		fprintf(stderr, "Short read of member header\n");

		return FALSE;
	}

	if (memcmp(hdr->ar_fmag, ARFMAG, sizeof(hdr->ar_fmag)))
	{
		fprintf(stderr, "Invalid member header\n");

		return FALSE;
	}

	return TRUE;
}


/*
 * Check the member file name and see if it matches the 4.4 BSD
 * syntax for long file names.  If so, return the number of characters
 * of the actual long file name.  Returns -1 on an error.
 */
static int
shortNameMatches44BSD(const char * name)
{
	const char *	p;
	unsigned long	ul;

	if (strncmp(name, "#1/", 3) != 0)
		return -1;

	if (!isDecimal(name[3]))
		return -1;

	for (p = name + 4;  *p;  p++)
	{
		if (!isDecimal(*p))
			break;
	}

	while (*p)
	{
		if (*p++ != ' ')
			return -1;
	}

	if (!getNumber(name + 3, 10, -1, &ul))
		return -1;

	if (ul == 0)		/* broken archive */
		return -1;

	return ul;
}


/*
 * Check the member file name and see if it matches the SYS V syntax
 * for long file names.  If so, return the number of characters of the
 * actual long file name.  Returns -1 on an error.
 */
static int
shortNameMatchesSysV(const char * name)
{
	const char *	p;
	unsigned long	ul;

	/* "^/(\d+) *$" */
	if (name[0] != '/')
		return -1;

	if (!isDecimal(name[1]))
		return -1;

	for (p = name + 2;  *p;  p++)
	{
		if (!isDecimal(*p))
			break;
	}

	while (*p)
	{
		if (*p++ != ' ')
			return -1;
	}

	if (!getNumber(name + 1, 10, -1, &ul))
		return -1;

	return ul;
}


#define MEMB_NAME_ALLOC(n)					\
	do							\
	{							\
		arch->name = malloc(n);				\
		if (!arch->name)				\
		{						\
			fprintf(stderr, "Out of memory\n");	\
			return FALSE;				\
		}						\
	} while (0);


/*
 * Examine the archive structure that was read and fill in the
 * current member data with the extracted information.  This handles
 * various types of archive headers.  This can read data from the
 * archive file to obtain a long file name.  Returns TRUE on success.
 */
static BOOL
canonicalize(Archive * arch, const struct ar_hdr * hdr)
{
	char		buf[sizeof(hdr->ar_name) + 1];
	int		n;
	unsigned long	ul;
	unsigned long	bsd_len;

	bsd_len = 0;

	free(arch->name);
	arch->name = 0;

	strncpy(buf, hdr->ar_name, sizeof(hdr->ar_name));
	buf[sizeof(hdr->ar_name)] = 0;

	/*
	 * 1. If shortname matches "^#1/(\d+) *$", then it's a 4.4BSD
	 *    longname.  Read a longname of $1 bytes from ARCH->fd, or
	 *    return FALSE if impossible.
	 */
	if ((n = shortNameMatches44BSD(buf)) != -1)
	{
		/* N is the length of the longname */
		ssize_t cc;

		bsd_len = n;

		MEMB_NAME_ALLOC(n + 1);

		cc = read(arch->fd, arch->name, n);

		if (cc == -1)
		{
			fprintf(stderr, "Error reading longname: %s\n",
				strerror(errno));

			goto free_and_out;
		}

		if (cc != n)
		{
			fprintf(stderr, "Unexpected end of file in longname\n");

			goto free_and_out;
		}

		arch->name[n] = 0;
	}

	/*
	 * 2. Otherwise, if shortname matches "^/(\d+) *$", then it's a SysV
	 *    longname.  Get the longname from the nameTable, or return FALSE
	 *    if there is none.
	 */
	else if ((n = shortNameMatchesSysV(buf)) != -1)
	{
		/*
		 * N is the index of the longname
		 */
		const char *	longname;
		const char *	p;
		size_t		len;

		if (n >= strlen(arch->nameTable))
		{
			fprintf(stderr, "Longname index too large\n");

			return FALSE;
		}

		longname = arch->nameTable + n;

		p = strchr(longname, '/');

		if (!p)
		{
			fprintf(stderr, "Bad longname index\n");

			return FALSE;
		}

		if (p[1] != '\n')
		{
			fprintf(stderr, "Malformed longname table\n");

			return FALSE;
		}

		len = p - longname;
		MEMB_NAME_ALLOC(len + 1);
		strncpy(arch->name, longname, len);
		arch->name[len] = '\0';
	}

	/*
	 * 3. Otherwise, it's just a shortname.  If the shortname contains a
	 *    slash, then the name terminates before the slash; otherwise,
	 *    the name terminates at the first space, or at the end of the
	 *    field if there is none. */
	else
	{
		const char *	p;
		size_t		len;

		p = strchr(buf, '/');

		if (!p)
			p = strchr(buf, ' ');

		if (p)
			len = p - buf;
		else
			len = sizeof(hdr->ar_name);

		MEMB_NAME_ALLOC(len + 1);
		strncpy(arch->name, buf, len);
		arch->name[len] = 0;
	}

	/*
	 * 4. Parse the remaining fields of the header.  Return FALSE if any
	 *    are missing or ill-formed.
	 */
#define FIELD(AFIELD, MFIELD, base)					\
	if (!getNumber(hdr->AFIELD, base, sizeof(hdr->AFIELD), &ul))	\
	{								\
		fprintf(stderr, "Malformed archive member header\n");	\
		goto free_and_out;					\
	}								\
	arch->MFIELD = ul;

	FIELD(ar_date, date, 10);
	FIELD(ar_uid,  uid,  10);
	FIELD(ar_gid,  gid,  10);
	FIELD(ar_mode, mode,  8);
	FIELD(ar_size, size, 10);
#undef FIELD

	/*
	 * 4a. Decide whether a pad byte will be present.u
	 *
	 * The 4.4BSD format is really broken and needs a whole pile of
	 * cruft to deal with it.  There are several cases:
	 *
	 * 1. Even namelen, even memberlen: no pad.
	 * 2. Even namelen, odd memberlen: pad.  Just like SysV.
	 * 3. Odd namelen, even memberlen: pad.  Cruft.
	 * 4. Odd namelen, odd memberlen: no pad.  Cruft.
	 *
	 * Essentially, whenever the namelen is odd, the naive determination
	 * of whether a pad is needed is reversed.
	 */
	if (!bsd_len)
		arch->pad = (arch->size % 2) ? 1 : 0;
	else
	{
		arch->size -= bsd_len;
		arch->pad = (arch->size % 2) ? 1 : 0;

		if (bsd_len % 2)
			arch->pad = !arch->pad;
	}

	/*
	 * 5. Everything was successful.
	 */
	return TRUE;


	/*
	 * 5a. Error exit -- free memory.
	 */
free_and_out:
	free(arch->name);
	arch->name = 0;

	return FALSE;
}


/*
 * Skip the padding character if required to position to the
 * beginning of the next member header.  This is done if the
 * padding value is nonzero.  Returns TRUE on success.
 */
static BOOL
skipPadding(int fd, int pad)
{
	if (pad)
	{
		if (lseek(fd, 1, SEEK_CUR) == -1)
		{
			fprintf(stderr, "Can't skip pad byte: %s\n",
				strerror(errno));

			return FALSE;
		}
	}

	return TRUE;
}


/*
 * Read the first member of the archive file and check whether it
 * is a special one, and if so, handle it.  If the first member is
 * a normal archive member, then set up to rescan it for the next
 * readNormalMember call.  Returns TRUE on success.
 */
static BOOL
readSpecialMember(Archive * arch)
{
	struct ar_hdr	hdr;

	/*
	 * 1. Read a header H.  Fail if impossible.
	 */
	if (!readMember(arch, &hdr))
		return FALSE;

	/*
	 * 2. If H is a symbol table, ditch it.
	 * Fail if impossible.
	 */
	if ((strncmp(hdr.ar_name, "/ ", 2) == 0) ||
		(strncmp(hdr.ar_name, "__.SYMTAB       ",
			sizeof(hdr.ar_name)) == 0))
	{
		if (!canonicalize(arch, &hdr))
			return FALSE;

		return skipMember(arch);
	}

	/*
	 * 3. If H is a SysV longname table, read it into ARCH.
	 */
	if (strncmp(hdr.ar_name, "//", 2) == 0)
	{
		unsigned long	len;
		ssize_t		cc;

		if (!getNumber(hdr.ar_size, 10, sizeof(hdr.ar_size), &len))
		{
			fprintf(stderr, "Invalid name-table size\n");

			return FALSE;
		}

		arch->nameTable = malloc(len + 1);

		if (!arch->nameTable)
		{
			fprintf(stderr, "Out of memory\n");

			return FALSE;
		}

		cc = read(arch->fd, arch->nameTable, len);

		if (cc == -1)
		{
			fprintf(stderr, "Error reading name-table: %s\n",
				strerror(errno));

			return FALSE;
		}

		if (cc != (ssize_t) len)
		{
			fprintf(stderr,
				"Unexpected end of file in name-table\n");

			return FALSE;
		}

		arch->nameTable[len] = 0;

		return skipPadding(arch->fd, len % 2);
	}

	/*
	 * 4. We read a normal header.
	 * Canonicalize it, and mark it as needing rescanning.
	 */
	arch->rescan = TRUE;

	return canonicalize(arch, &hdr);
}


/*
 * Read the next normal member of the archive file if possible.
 * If the member is being rescanned, clear the rescan flag and
 * return the header that was already read.  Returns TRUE on
 * success.  On a failure, the eof flag will be set if end of
 * file has been reached.
 */
static BOOL
readNormalMember(Archive * arch)
{
	struct ar_hdr	hdr;

	/*
	 * If we are rereading an old header then just clear the
	 * rescan flag and return success.
	 */
	if (arch->rescan)
	{
		arch->rescan = FALSE;

		return TRUE;
	}

	/*
	 * We need to read a new member header.
	 */
	if (!readMember(arch, &hdr))
		return FALSE;

	return canonicalize(arch, &hdr);
}


/*
 * Skip the current member of the archive so that we are positioned
 * to tbe beginning of the next member's header (or end of file).
 * Returns TRUE on success.
 */
static BOOL
skipMember(const Archive * arch)
{
	if (lseek(arch->fd, arch->size, SEEK_CUR) == -1)
	{
		fprintf(stderr, "Can't skip past archive member: %s\n",
			strerror(errno));

		return FALSE;
	}

	return skipPadding(arch->fd, arch->pad);
}


/*
 * Copy all of the file data from the archive to the specified
 * open file.  Returns TRUE on success.
 */
static BOOL
writeFile(const Archive * arch, int outfd)
{
	char	buf[BUF_SIZE];
	off_t	n;

	n = arch->size;

	while (n > 0)
	{
		ssize_t cc;

		cc = read(arch->fd, buf, MIN(n, sizeof(buf)));

		if (cc == -1)
		{
			fprintf(stderr, "Error reading archive member: %s\n",
				strerror(errno));

			return FALSE;
		}

		if (cc == 0)
		{
			fprintf(stderr, "Unexpected end of file\n");

			return FALSE;
		}

		if (fullWrite(outfd, buf, cc) < 0)
		{
			fprintf(stderr, "Write error: %s\n", strerror(errno));

			return FALSE;
		}

		n -= cc;
	}

	if (!skipPadding(arch->fd, arch->pad))
		return FALSE;

	return TRUE;
}


/*
 * Print one line listing the information about the specified archive member.
 */
static void
listMember(const Archive * arch)
{
	printf("%s %6ld/%-6ld %8lu %s %s\n",
	       modeString(arch->mode) + 1,
	       (long) arch->uid,
	       (long) arch->gid,
	       (unsigned long) arch->size,
	       timeString(arch->date),
	       arch->name);
}


/* END CODE */
