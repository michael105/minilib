/*
 * Copyright (c) 2014 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * The "tar" built-in command.
 * This allows creation, extraction, and listing of tar files.
 */

#include "sash.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <errno.h>


/*
 * Tar file constants.
 */
#define TAR_BLOCK_SIZE	512
#define TAR_NAME_SIZE	100


/*
 * The POSIX (and basic GNU) tar header format.
 * This structure is always embedded in a TAR_BLOCK_SIZE sized block
 * with zero padding.  We only process this information minimally.
 */
typedef struct
{
	char	name[TAR_NAME_SIZE];
	char	mode[8];
	char	uid[8];
	char	gid[8];
	char	size[12];
	char	mtime[12];
	char	checkSum[8];
	char	typeFlag;
	char	linkName[TAR_NAME_SIZE];
	char	magic[6];
	char	version[2];
	char	uname[32];
	char	gname[32];
	char	devMajor[8];
	char	devMinor[8];
	char	prefix[155];
} TarHeader;


#define	TAR_MAGIC	"ustar"
#define	TAR_VERSION	"00"

#define	TAR_TYPE_REGULAR	'0'
#define	TAR_TYPE_HARD_LINK	'1'
#define	TAR_TYPE_SOFT_LINK	'2'


/*
 * Static data.
 */
static	BOOL		listFlag;
static	BOOL		extractFlag;
static	BOOL		createFlag;
static	BOOL		verboseFlag;

static	BOOL		inHeader;
static	BOOL		badHeader;
static	BOOL		errorFlag;
static	BOOL		skipFileFlag;
static	BOOL		warnedRoot;
static	BOOL		eofFlag;
static	long		dataCc;
static	int		outFd;
static	char		outName[TAR_NAME_SIZE];


/*
 * Static data associated with the tar file.
 */
static	const char *	tarName;
static	int		tarFd;
static	dev_t		tarDev;
static	ino_t		tarInode;


/*
 * Local procedures to restore files from a tar file.
 */
static	BOOL	readTarFile(int fileCount, const char ** fileTable);
static	BOOL	readData(const char * cp, int count);
static	BOOL	createPath(const char * name, int mode);
static	long	getOctal(const char * cp, int len);

static	BOOL	readHeader(const TarHeader * hp,
			int fileCount, const char ** fileTable);


/*
 * Local procedures to save files into a tar file.
 */
static	void	saveFile(const char * fileName, BOOL seeLinks);

static	void	saveRegularFile(const char * fileName,
			const struct stat * statbuf);

static	void	saveDirectory(const char * fileName,
			const struct stat * statbuf);

static	BOOL	wantFileName(const char * fileName,
			int fileCount, const char ** fileTable);

static	void	writeHeader(const char * fileName,
			const struct stat * statbuf);

static	BOOL	writeTarFile(int fileCount, const char ** fileTable);
static	void	writeTarBlock(const char * buf, int len);
static	BOOL	putOctal(char * cp, int len, long value);



int
do_tar(int argc, const char ** argv)
{
	const char *	options;
	BOOL		successFlag;

	argc--;
	argv++;

	if (argc < 2)
	{
		fprintf(stderr, "Too few arguments for tar\n");

		return 1;
	}

	extractFlag = FALSE;
	createFlag = FALSE;
	listFlag = FALSE;
	verboseFlag = FALSE;
	tarName = NULL;
	tarDev = 0;
	tarInode = 0;
	tarFd = -1;

	/*
	 * Parse the options.
	 */
	options = *argv++;
	argc--;

	for (; *options; options++)
	{
		switch (*options)
		{
			case 'f':
				if (tarName != NULL)
				{
					fprintf(stderr, "Only one 'f' option allowed\n");

					return 1;
				}

				tarName = *argv++;
				argc--;

				break;

			case 't':
				listFlag = TRUE;
				break;

			case 'x':
				extractFlag = TRUE;
				break;

			case 'c':
				createFlag = TRUE;
				break;

			case 'v':
				verboseFlag = TRUE;
				break;

			default:
				fprintf(stderr, "Unknown tar flag '%c'\n", *options);

				return 1;
		}
	}

	/*
	 * Validate the options.
	 */
	if (extractFlag + listFlag + createFlag != 1)
	{
		fprintf(stderr, "Exactly one of 'c', 'x' or 't' must be specified\n");

		return 1;
	}

	if (tarName == NULL)
	{
		fprintf(stderr, "The 'f' flag must be specified\n");

		return 1;
	}

	/*
	 * Do the correct type of action supplying the rest of the
	 * command line arguments as the list of files to process.
	 */
	if (createFlag)
		successFlag = writeTarFile(argc, argv);
	else
		successFlag = readTarFile(argc, argv);

	return !successFlag;
}


/*
 * Read a tar file and extract or list the specified files within it.
 * If the list is empty than all files are extracted or listed.
 * Returns TRUE on success.
 */
static BOOL
readTarFile(int fileCount, const char ** fileTable)
{
	const char *	cp;
	BOOL		successFlag;
	int		cc;
	int		inCc;
	int		blockSize;
	char		buf[BUF_SIZE];

	skipFileFlag = FALSE;
	badHeader = FALSE;
	warnedRoot = FALSE;
	eofFlag = FALSE;
	inHeader = TRUE;
	successFlag = TRUE;

	inCc = 0;
	dataCc = 0;
	outFd = -1;
	blockSize = sizeof(buf);
	cp = buf;

	/*
	 * Open the tar file for reading.
	 */
	tarFd = open(tarName, O_RDONLY);

	if (tarFd < 0)
	{
		perror(tarName);

		return FALSE;
	}

	/*
	 * Read blocks from the file until an end of file header block
	 * has been seen.  (A real end of file from a read is an error.)
	 */
	while (!intFlag && !eofFlag)
	{
		/*
		 * Read the next block of data if necessary.
		 * This will be a large block if possible, which we will
		 * then process in the small tar blocks.
		 */
		if (inCc <= 0)
		{
			cp = buf;
			inCc = fullRead(tarFd, buf, blockSize);

			if (inCc < 0)
			{
				perror(tarName);
				successFlag = FALSE;

				goto done;
			}

			if (inCc == 0)
			{
				fprintf(stderr,
					"Unexpected end of file from \"%s\"",
					tarName);
				successFlag = FALSE;

				goto done;
			}
		}

		/*
		 * If we are expecting a header block then examine it.
		 */
		if (inHeader)
		{
			if (!readHeader((const TarHeader *) cp, fileCount, fileTable))
				successFlag = FALSE;

			cp += TAR_BLOCK_SIZE;
			inCc -= TAR_BLOCK_SIZE;

			continue;
		}

		/*
		 * We are currently handling the data for a file.
		 * Process the minimum of the amount of data we have available
		 * and the amount left to be processed for the file.
		 */
		cc = inCc;

		if (cc > dataCc)
			cc = dataCc;

		if (!readData(cp, cc))
			successFlag = FALSE;

		/*
		 * If the amount left isn't an exact multiple of the tar block
		 * size then round it up to the next block boundary since there
		 * is padding at the end of the file.
		 */
		if (cc % TAR_BLOCK_SIZE)
			cc += TAR_BLOCK_SIZE - (cc % TAR_BLOCK_SIZE);

		cp += cc;
		inCc -= cc;
	}

	/*
	 * Check for an interrupt.
	 */
	if (intFlag)
	{
		fprintf(stderr, "Interrupted - aborting\n");
		successFlag = FALSE;
	}

done:
	/*
	 * Close the tar file if needed.
	 */
	if ((tarFd >= 0) && (close(tarFd) < 0))
	{
		perror(tarName);
		successFlag = FALSE;
	}

	/*
	 * Close the output file if needed.
	 * This is only done here on a previous error and so no
	 * message is required on errors.
	 */
	if (outFd >= 0)
		(void) close(outFd);

	return successFlag;
}


/*
 * Examine the header block that was just read.
 * This can specify the information for another file, or it can mark
 * the end of the tar file.  Returns TRUE on success.
 */
static BOOL
readHeader(const TarHeader * hp, int fileCount, const char ** fileTable)
{
	int		mode;
	int		uid;
	int		gid;
	long		size;
	time_t		mtime;
	const char *	name;
	int		cc;
	BOOL		hardLink;
	BOOL		softLink;

	/*
	 * If the block is completely empty, then this is the end of the
	 * archive file.  If the name is null, then just skip this header.
	 */
	name = hp->name;

	if (*name == '\0')
	{
		for (cc = TAR_BLOCK_SIZE; cc > 0; cc--)
		{
			if (*name++)
				return TRUE;
		}

		eofFlag = TRUE;

		return TRUE;
	}

	/*
	 * There is another file in the archive to examine.
	 * Extract the encoded information and check it.
	 */
	mode = getOctal(hp->mode, sizeof(hp->mode));
	uid = getOctal(hp->uid, sizeof(hp->uid));
	gid = getOctal(hp->gid, sizeof(hp->gid));
	size = getOctal(hp->size, sizeof(hp->size));
	mtime = getOctal(hp->mtime, sizeof(hp->mtime));

	if ((mode < 0) || (uid < 0) || (gid < 0) || (size < 0))
	{
		if (!badHeader)
			fprintf(stderr, "Bad tar header, skipping\n");

		badHeader = TRUE;

		return FALSE;
	}

	badHeader = FALSE;
	skipFileFlag = FALSE;

	/*
	 * Check for the file modes.
	 */
	hardLink = ((hp->typeFlag == TAR_TYPE_HARD_LINK) ||
		(hp->typeFlag == TAR_TYPE_HARD_LINK - '0'));

	softLink = ((hp->typeFlag == TAR_TYPE_SOFT_LINK) ||
		(hp->typeFlag == TAR_TYPE_SOFT_LINK - '0'));

	/*
	 * Check for a directory or a regular file.
	 */
	if (name[strlen(name) - 1] == '/')
		mode |= S_IFDIR;
	else if ((mode & S_IFMT) == 0)
		mode |= S_IFREG;

	/*
	 * Check for absolute paths in the file.
	 * If we find any, then warn the user and make them relative.
	 */
	if (*name == '/')
	{
		while (*name == '/')
			name++;

		if (!warnedRoot)
		{
			fprintf(stderr,
			"Absolute path detected, removing leading slashes\n");
		}

		warnedRoot = TRUE;
	}

	/*
	 * See if we want this file to be restored.
	 * If not, then set up to skip it.
	 */
	if (!wantFileName(name, fileCount, fileTable))
	{
		if (!hardLink && !softLink && S_ISREG(mode))
		{
			inHeader = (size == 0);
			dataCc = size;
		}

		skipFileFlag = TRUE;

		return TRUE;
	}

	/*
	 * This file is to be handled.
	 * If we aren't extracting then just list information about the file.
	 */
	if (!extractFlag)
	{
		if (verboseFlag)
		{
			printf("%s %3d/%-d %9ld %s %s", modeString(mode),
				uid, gid, size, timeString(mtime), name);
		}
		else
			printf("%s", name);

		if (hardLink)
			printf(" (link to \"%s\")", hp->linkName);
		else if (softLink)
			printf(" (symlink to \"%s\")", hp->linkName);
		else if (S_ISREG(mode))
		{
			inHeader = (size == 0);
			dataCc = size;
		}

		printf("\n");

		return TRUE;
	}

	/*
	 * We really want to extract the file.
	 */
	if (verboseFlag)
		printf("x %s\n", name);

	if (hardLink)
	{
		if (link(hp->linkName, name) < 0)
		{
			perror(name);
			return FALSE;
		}

		return TRUE;
	}

	if (softLink)
	{
#ifdef	S_ISLNK
		if (symlink(hp->linkName, name) < 0)
		{
			perror(name);

			return FALSE;
		}

		return TRUE;
#else
		fprintf(stderr, "Cannot create symbolic links\n");
#endif
		return FALSE;
	}

	/*
	 * If the file is a directory, then just create the path.
	 */
	if (S_ISDIR(mode))
		return createPath(name, mode);

	/*
	 * There is a file to write.
	 * First create the path to it if necessary with a default permission.
	 */
	if (!createPath(name, 0777))
		return FALSE;

	inHeader = (size == 0);
	dataCc = size;

	/*
	 * Start the output file.
	 */
	outFd = open(name, O_WRONLY | O_CREAT | O_TRUNC, mode);

	if (outFd < 0)
	{
		perror(name);
		skipFileFlag = TRUE;

		return FALSE;
	}

	/*
	 * If the file is empty, then that's all we need to do.
	 */
	if (size == 0)
	{
		(void) close(outFd);
		outFd = -1;
	}

	return TRUE;
}


/*
 * Handle a data block of some specified size that was read.
 * Returns TRUE on success.
 */
static BOOL
readData(const char * cp, int count)
{
	/*
	 * Reduce the amount of data left in this file.
	 * If there is no more data left, then we need to read
	 * the header again.
	 */
	dataCc -= count;

	if (dataCc <= 0)
		inHeader = TRUE;

	/*
	 * If we aren't extracting files or this file is being
	 * skipped then do nothing more.
	 */
	if (!extractFlag || skipFileFlag)
		return TRUE;

	/*
	 * Write the data to the output file.
	 */
	if (fullWrite(outFd, cp, count) < 0)
	{
		perror(outName);
		(void) close(outFd);
		outFd = -1;
		skipFileFlag = TRUE;

		return FALSE;
	}

	/*
	 * If the write failed, close the file and disable further
	 * writes to this file.
	 */
	if (dataCc <= 0)
	{
		if (close(outFd))
			perror(outName);

		outFd = -1;

		return FALSE;
	}

	return TRUE;
}


/*
 * Write a tar file containing the specified files.
 * Returns TRUE on success.
 */
static BOOL
writeTarFile(int fileCount, const char ** fileTable)
{
	struct	stat	statbuf;
	BOOL		successFlag;

	successFlag = TRUE;
	errorFlag = FALSE;

	/*
	 * Make sure there is at least one file specified.
	 */
	if (fileCount <= 0)
	{
		fprintf(stderr, "No files specified to be saved\n");

		return FALSE;
	}

	/*
	 * Create the tar file for writing.
	 */
	tarFd = open(tarName, O_WRONLY | O_CREAT | O_TRUNC, 0666);

	if (tarFd < 0)
	{
		perror(tarName);

		return FALSE;
	}

	/*
	 * Get the device and inode of the tar file for checking later.
	 */
	if (fstat(tarFd, &statbuf) < 0)
	{
		perror(tarName);
		successFlag = FALSE;

		goto done;
	}

	tarDev = statbuf.st_dev;
	tarInode = statbuf.st_ino;

	/*
	 * Append each file name into the archive file.
	 * Follow symbolic links for these top level file names.
	 */
	while (!intFlag && !errorFlag && (fileCount-- > 0))
	{
		saveFile(*fileTable++, FALSE);
	}

	if (intFlag)
	{
		fprintf(stderr, "Interrupted - aborting archiving\n");
		successFlag = FALSE;
	}

	/*
	 * Now write an empty block of zeroes to end the archive.
	 */
	writeTarBlock("", 1);


done:
	/*
	 * Close the tar file and check for errors if it was opened.
	 */
	if ((tarFd >= 0) && (close(tarFd) < 0))
	{
		perror(tarName);
		successFlag = FALSE;
	}

	return successFlag;
}


/*
 * Save one file into the tar file.
 * If the file is a directory, then this will recursively save all of
 * the files and directories within the directory.  The seeLinks
 * flag indicates whether or not we want to see symbolic links as
 * they really are, instead of blindly following them.
 */
static void
saveFile(const char * fileName, BOOL seeLinks)
{
	int		status;
	int		mode;
	struct stat	statbuf;

	if (verboseFlag)
		printf("a %s\n", fileName);

	/*
	 * Check that the file name will fit in the header.
	 */
	if (strlen(fileName) >= TAR_NAME_SIZE)
	{
		fprintf(stderr, "%s: File name is too long\n", fileName);

		return;
	}

	/*
	 * Find out about the file.
	 */
#ifdef	S_ISLNK
	if (seeLinks)
		status = lstat(fileName, &statbuf);
	else
#endif
		status = stat(fileName, &statbuf);

	if (status < 0)
	{
		perror(fileName);

		return;
	}

	/*
	 * Make sure we aren't trying to save our file into itself.
	 */
	if ((statbuf.st_dev == tarDev) && (statbuf.st_ino == tarInode))
	{
		fprintf(stderr, "Skipping saving of archive file itself\n");

		return;
	}

	/*
	 * Check the type of file.
	 */
	mode = statbuf.st_mode;

	if (S_ISDIR(mode))
	{
		saveDirectory(fileName, &statbuf);

		return;
	}

	if (S_ISREG(mode))
	{
		saveRegularFile(fileName, &statbuf);

		return;
	}

	/*
	 * The file is a strange type of file, ignore it.
	 */
	fprintf(stderr, "%s: not a directory or regular file\n", fileName);
}


/*
 * Save a regular file to the tar file.
 */
static void
saveRegularFile(const char * fileName, const struct stat * statbuf)
{
	BOOL		sawEof;
	int		fileFd;
	int		cc;
	int		dataCount;
	long		fullDataCount;
	char		data[TAR_BLOCK_SIZE * 16];

	/*
	 * Open the file for reading.
	 */
	fileFd = open(fileName, O_RDONLY);

	if (fileFd < 0)
	{
		perror(fileName);

		return;
	}

	/*
	 * Write out the header for the file.
	 */
	writeHeader(fileName, statbuf);

	/*
	 * Write the data blocks of the file.
	 * We must be careful to write the amount of data that the stat
	 * buffer indicated, even if the file has changed size.  Otherwise
	 * the tar file will be incorrect.
	 */
	fullDataCount = statbuf->st_size;
	sawEof = FALSE;

	while (!intFlag && (fullDataCount > 0))
	{
		/*
		 * Get the amount to write this iteration which is
		 * the minumum of the amount left to write and the
		 * buffer size.
		 */
		dataCount = sizeof(data);

		if (dataCount > fullDataCount)
			dataCount = (int) fullDataCount;

		/*
		 * Read the data from the file if we haven't seen the
		 * end of file yet.
		 */
		cc = 0;

		if (!sawEof)
		{
			cc = fullRead(fileFd, data, dataCount);

			if (cc < 0)
			{
				perror(fileName);

				(void) close(fileFd);
				errorFlag = TRUE;

				return;
			}

			/*
			 * If the file ended too soon, complain and set
			 * a flag so we will zero fill the rest of it.
			 */
			if (cc < dataCount)
			{
				fprintf(stderr,
					"%s: Short read - zero filling",
					fileName);

				sawEof = TRUE;
			}
		}

		/*
		 * Zero fill the rest of the data if necessary.
		 */
		if (cc < dataCount)
			memset(data + cc, 0, dataCount - cc);

		/*
		 * Write the buffer to the TAR file.
		 */
		writeTarBlock(data, dataCount);

		fullDataCount -= dataCount;
	}

	/*
	 * Close the file.
	 */
	if (close(fileFd) < 0)
		fprintf(stderr, "%s: close: %s\n", fileName, strerror(errno));
}


/*
 * Save a directory and all of its files to the tar file.
 */
static void
saveDirectory(const char * dirName, const struct stat * statbuf)
{
	DIR *		dir;
	struct dirent *	entry;
	BOOL		needSlash;
	char		fullName[PATH_LEN];

	/*
	 * Construct the directory name as used in the tar file by appending
	 * a slash character to it.
	 */
	strcpy(fullName, dirName);
	strcat(fullName, "/");

	/*
	 * Write out the header for the directory entry.
	 */
	writeHeader(fullName, statbuf);

	/*
	 * Open the directory.
	 */
	dir = opendir(dirName);

	if (dir == NULL)
	{
		fprintf(stderr, "Cannot read directory \"%s\": %s\n",
			dirName, strerror(errno));

		return;
	}

	/*
	 * See if a slash is needed.
	 */
	needSlash = (*dirName && (dirName[strlen(dirName) - 1] != '/'));

	/*
	 * Read all of the directory entries and check them,
	 * except for the current and parent directory entries.
	 */
	while (!intFlag && !errorFlag && ((entry = readdir(dir)) != NULL))
	{
		if ((strcmp(entry->d_name, ".") == 0) ||
			(strcmp(entry->d_name, "..") == 0))
		{
			continue;
		}

		/*
		 * Build the full path name to the file.
		 */
		strcpy(fullName, dirName);

		if (needSlash)
			strcat(fullName, "/");

		strcat(fullName, entry->d_name);

		/*
		 * Write this file to the tar file, noticing whether or not
		 * the file is a symbolic link.
		 */
		saveFile(fullName, TRUE);
	}

	/*
	 * All done, close the directory.
	 */
	closedir(dir);
}


/*
 * Write a tar header for the specified file name and status.
 * It is assumed that the file name fits.
 */
static void
writeHeader(const char * fileName, const struct stat * statbuf)
{
	long			checkSum;
	const unsigned char *	cp;
	int			len;
	TarHeader		header;

	/*
	 * Zero the header block in preparation for filling it in.
	 */
	memset((char *) &header, 0, sizeof(header));

	/*
	 * Fill in the header.
	 */
	strcpy(header.name, fileName);

	strncpy(header.magic, TAR_MAGIC, sizeof(header.magic));
	strncpy(header.version, TAR_VERSION, sizeof(header.version));

	putOctal(header.mode, sizeof(header.mode), statbuf->st_mode & 0777);
	putOctal(header.uid, sizeof(header.uid), statbuf->st_uid);
	putOctal(header.gid, sizeof(header.gid), statbuf->st_gid);
	putOctal(header.size, sizeof(header.size), statbuf->st_size);
	putOctal(header.mtime, sizeof(header.mtime), statbuf->st_mtime);

	header.typeFlag = TAR_TYPE_REGULAR;

	/*
	 * Calculate and store the checksum.
	 * This is the sum of all of the bytes of the header,
	 * with the checksum field itself treated as blanks.
	 */
	memset(header.checkSum, ' ', sizeof(header.checkSum));

	cp = (const unsigned char *) &header;
	len = sizeof(header);
	checkSum = 0;

	while (len-- > 0)
		checkSum += *cp++;

	putOctal(header.checkSum, sizeof(header.checkSum), checkSum);

	/*
	 * Write the tar header.
	 */
	writeTarBlock((const char *) &header, sizeof(header));
}


/*
 * Write data to one or more blocks of the tar file.
 * The data is always padded out to a multiple of TAR_BLOCK_SIZE.
 * The errorFlag static variable is set on an error.
 */
static void
writeTarBlock(const char * buf, int len)
{
	int	partialLength;
	int	completeLength;
	char	fullBlock[TAR_BLOCK_SIZE];

	/*
	 * If we had a write error before, then do nothing more.
	 */
	if (errorFlag)
		return;

	/*
	 * Get the amount of complete and partial blocks.
	 */
	partialLength = len % TAR_BLOCK_SIZE;
	completeLength = len - partialLength;

	/*
	 * Write all of the complete blocks.
	 */
	if ((completeLength > 0) && !fullWrite(tarFd, buf, completeLength))
	{
		perror(tarName);

		errorFlag = TRUE;

		return;
	}

	/*
	 * If there are no partial blocks left, we are done.
	 */
	if (partialLength == 0)
		return;

	/*
	 * Copy the partial data into a complete block, and pad the rest
	 * of it with zeroes.
	 */
	memcpy(fullBlock, buf + completeLength, partialLength);
	memset(fullBlock + partialLength, 0, TAR_BLOCK_SIZE - partialLength);

	/*
	 * Write the last complete block.
	 */
	if (!fullWrite(tarFd, fullBlock, TAR_BLOCK_SIZE))
	{
		perror(tarName);

		errorFlag = TRUE;
	}
}


/*
 * Attempt to create the directories along the specified path, except for
 * the final component.  The mode is given for the final directory only,
 * while all previous ones get default protections.  Errors are not reported
 * here, as failures to restore files can be reported later.
 * Returns TRUE on success.
 */
static BOOL
createPath(const char * name, int mode)
{
	char *	cp;
	char *	cpOld;
	char	buf[TAR_NAME_SIZE];

	strcpy(buf, name);

	cp = strchr(buf, '/');

	while (cp)
	{
		cpOld = cp;
		cp = strchr(cp + 1, '/');

		*cpOld = '\0';

		if (mkdir(buf, cp ? 0777 : mode) == 0)
			printf("Directory \"%s\" created\n", buf);

		*cpOld = '/';
	}

	return TRUE;
}


/*
 * Read an octal value in a field of the specified width, with optional
 * spaces on both sides of the number and with an optional null character
 * at the end.  Returns -1 on an illegal format.
 */
static long
getOctal(const char * cp, int len)
{
	long	val;

	while ((len > 0) && (*cp == ' '))
	{
		cp++;
		len--;
	}

	if ((len == 0) || !isOctal(*cp))
		return -1;

	val = 0;

	while ((len > 0) && isOctal(*cp))
	{
		val = val * 8 + *cp++ - '0';
		len--;
	}

	while ((len > 0) && (*cp == ' '))
	{
		cp++;
		len--;
	}

	if ((len > 0) && *cp)
		return -1;

	return val;
}


/*
 * Put an octal string into the specified buffer.
 * The number is zero and space padded and possibly null padded.
 * Returns TRUE if successful.
 */
static BOOL
putOctal(char * cp, int len, long value)
{
	int	tempLength;
	char *	tempString;
	char	tempBuffer[32];

	/*
	 * Create a string of the specified length with an initial space,
	 * leading zeroes and the octal number, and a trailing null.
	 */
	tempString = tempBuffer;

	sprintf(tempString, " %0*lo", len - 2, value);

	tempLength = strlen(tempString) + 1;

	/*
	 * If the string is too large, suppress the leading space.
	 */
	if (tempLength > len)
	{
		tempLength--;
		tempString++;
	}

	/*
	 * If the string is still too large, suppress the trailing null.
	 */
	if (tempLength > len)
		tempLength--;

	/*
	 * If the string is still too large, fail.
	 */
	if (tempLength > len)
		return FALSE;

	/*
	 * Copy the string to the field.
	 */
	memcpy(cp, tempString, len);

	return TRUE;
}


/*
 * See if the specified file name belongs to one of the specified list
 * of path prefixes.  An empty list implies that all files are wanted.
 * Returns TRUE if the file is selected.
 */
static BOOL
wantFileName(const char * fileName, int fileCount, const char ** fileTable)
{
	const char *	pathName;
	int		fileLength;
	int		pathLength;

	/*
	 * If there are no files in the list, then the file is wanted.
	 */
	if (fileCount == 0)
		return TRUE;

	fileLength = strlen(fileName);

	/*
	 * Check each of the test paths.
	 */
	while (fileCount-- > 0)
	{
		pathName = *fileTable++;

		pathLength = strlen(pathName);

		if (fileLength < pathLength)
			continue;

		if (memcmp(fileName, pathName, pathLength) != 0)
			continue;

		if ((fileLength == pathLength) ||
			(fileName[pathLength] == '/'))
		{
			return TRUE;
		}
	}

	return FALSE;
}

/* END CODE */
