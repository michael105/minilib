/*
 * Copyright (c) 2014 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * The "gzip" and "gunzip" built-in commands.
 * These commands are optionally built into sash.
 * This uses the zlib library by Jean-loup Gailly to compress and
 * uncompress the files.
 */

#if	HAVE_GZIP


#include <sys/types.h>
#include <sys/stat.h>
#include <zlib.h>

#include "sash.h"


#define	GZ_EXT		".gz"
#define	TGZ_EXT		".tgz"
#define	Z_EXT		".Z"
#define	TAR_EXT		".tar"
#define	NO_EXT		""


/*
 * Tables of conversions to make to file extensions.
 */
typedef	struct
{
	const char *	input;
	const char *	output;
} CONVERT;


static const CONVERT	gzipConvertTable[] =
{
	{TAR_EXT,	TGZ_EXT},
	{NO_EXT,	GZ_EXT}
};


static const CONVERT	gunzipConvertTable[] =
{
	{TGZ_EXT,	TAR_EXT},
	{GZ_EXT,	NO_EXT},
	{Z_EXT,		NO_EXT},
	{NO_EXT,	NO_EXT}
};


/*
 * Local routines to compress and uncompress files.
 */
static BOOL	gzip(const char * inputFile, const char * outputFile);
static BOOL	gunzip(const char * inputFile, const char * outputFile);

static const char * convertName
	(const CONVERT * table, const char * inFile);


int
do_gzip(int argc, const char ** argv)
{
	const char *	outPath;
	const char *	inFile;
	const char *	outFile;
	int		i;
	int		r;

	r = 0;
	argc--;
	argv++;

	/*
	 * Look for the -o option if it is present.
	 * If present, it must be at the end of the command.
	 * Remember the output path and remove it if found.
	 */
	outPath = NULL;

	if ((argc >= 2) && (strcmp(argv[argc - 2], "-o") == 0) &&
		(argv[argc - 1][0] != '-'))
	{
		argc -= 2;
		outPath = argv[argc + 1];
	}

	/*
	 * Now make sure that there are no more options.
	 */
	for (i = 0; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			if (strcmp(argv[i], "-o") == 0)
				fprintf(stderr, "Illegal use of -o\n");
			else
				fprintf(stderr, "Illegal option\n");

			return 1;
		}
	}
	
	/*
	 * If there is no output path specified, then compress each of
	 * the input files in place using their full paths.  The input
	 * file names are then deleted.
	 */
	if (outPath == NULL)
	{
		while (!intFlag && (argc-- > 0))
		{
			inFile = *argv++;

			outFile = convertName(gzipConvertTable, inFile);

			/*
			 * Try to compress the file.
			 */
			if (!gzip(inFile, outFile))
			{
				r = 1;

				continue;
			}

			/*
			 * This was successful.
			 * Try to delete the original file now.
			 */
			if (unlink(inFile) < 0)
			{
				fprintf(stderr, "%s: %s\n", inFile,
					"Compressed ok but unlink failed");

				r = 1;
			}
		}

		return r;
	}

	/*
	 * There is an output path specified.
	 * If it is not a directory, then either compress the single
	 * specified input file to the exactly specified output path,
	 * or else complain.
	 */
	if (!isDirectory(outPath))
	{
		if (argc == 1)
			r = !gzip(*argv, outPath);
		else
		{
			fprintf(stderr, "Exactly one input file is required\n");
			r = 1;
		}

		return r;
	}

	/*
	 * There was an output directory specified.
	 * Compress each of the input files into the specified
	 * output directory, converting their extensions if possible.
	 */
	while (!intFlag && (argc-- > 0))
	{
		inFile = *argv++;

		/*
		 * Strip the path off of the input file name to make
		 * the beginnings of the output file name.
		 */
		outFile = strrchr(inFile, '/');

		if (outFile)
			outFile++;
		else
			outFile = inFile;

		/*
		 * Convert the extension of the output file name if possible.
		 * If we can't, then that is ok.
		 */
		outFile = convertName(gzipConvertTable, outFile);

		/*
		 * Now build the output path name by prefixing it with
		 * the output directory.
		 */
		outFile = buildName(outPath, outFile);

		/*
		 * Compress the input file without deleting the input file.
		 */
		if (!gzip(inFile, outFile))
			r = 1;
	}

	return r;
}


int
do_gunzip(int argc, const char ** argv)
{
	const char *	outPath;
	const char *	inFile;
	const char *	outFile;
	int		i;
	int		r;

	r = 0;
	argc--;
	argv++;

	/*
	 * Look for the -o option if it is present.
	 * If present, it must be at the end of the command.
	 * Remember the output path and remove it if found.
	 */
	outPath = NULL;

	if ((argc >= 2) && (strcmp(argv[argc - 2], "-o") == 0) &&
		(argv[argc - 1][0] != '-'))
	{
		argc -= 2;
		outPath = argv[argc + 1];
	}

	/*
	 * Now make sure that there are no more options.
	 */
	for (i = 0; i < argc; i++)
	{
		if (argv[i][0] == '-')
		{
			if (strcmp(argv[i], "-o") == 0)
				fprintf(stderr, "Illegal use of -o\n");
			else
				fprintf(stderr, "Illegal option\n");

			return 1;
		}
	}
	
	/*
	 * If there is no output path specified, then uncompress each of
	 * the input files in place using their full paths.  They must
	 * have one of the proper compression extensions which is converted.
	 * The input file names are then deleted.
	 */
	if (outPath == NULL)
	{
		while (!intFlag && (argc-- > 0))
		{
			inFile = *argv++;

			outFile = convertName(gunzipConvertTable, inFile);

			if (inFile == outFile)
			{
				fprintf(stderr, "%s: %s\n", inFile,
					"missing compression extension");
				r = 1;

				continue;
			}

			/*
			 * Try to uncompress the file.
			 */
			if (!gunzip(inFile, outFile))
			{
				r = 1;
				continue;
			}

			/*
			 * This was successful.
			 * Try to delete the original file now.
			 */
			if (unlink(inFile) < 0)
			{
				fprintf(stderr, "%s: %s\n", inFile,
					"Uncompressed ok but unlink failed");
				r = 1;
			}
		}

		return r;
	}

	/*
	 * There is an output path specified.
	 * If the output path is a device file then uncompress each of
	 * the input files to the device file.
	 */
	if (isDevice(outPath))
	{
		while (!intFlag && (argc-- > 0))
		{
			if (!gunzip(*argv++, outPath))
				r = 1;
		}

		return r;
	}

	/*
	 * If the output path is not a directory then either uncompress the
	 * single specified input file to the exactly specified output path,
	 * or else complain.
	 */
	if (!isDirectory(outPath))
	{
		if (argc == 1)
			return !gunzip(*argv, outPath);
		else
			fprintf(stderr, "Exactly one input file is required\n");

		return 1;
	}

	/*
	 * There was an output directory specified.
	 * Uncompress each of the input files into the specified
	 * output directory, converting their extensions if possible.
	 */
	while (!intFlag && (argc-- > 0))
	{
		inFile = *argv++;

		/*
		 * Strip the path off of the input file name to make
		 * the beginnings of the output file name.
		 */
		outFile = strrchr(inFile, '/');

		if (outFile)
			outFile++;
		else
			outFile = inFile;

		/*
		 * Convert the extension of the output file name if possible.
		 * If we can't, then that is ok.
		 */
		outFile = convertName(gunzipConvertTable, outFile);

		/*
		 * Now build the output path name by prefixing it with
		 * the output directory.
		 */
		outFile = buildName(outPath, outFile);

		/*
		 * Uncompress the input file without deleting the input file.
		 */
		if (!gunzip(inFile, outFile))
			r = 1;
	}

	return r;
}


/*
 * Compress the specified input file to produce the output file.
 * Returns TRUE if successful.
 */
static BOOL
gzip(const char * inputFileName, const char * outputFileName)
{
	gzFile		outGZ;
	int		inFD;
	int		len;
	int		err;
	struct	stat	statBuf1;
	struct	stat	statBuf2;
	char		buf[BUF_SIZE];

	outGZ = NULL;
	inFD = -1;

	/*
	 * See if the output file is the same as the input file.
	 * If so, complain about it.
	 */
	if (stat(inputFileName, &statBuf1) < 0)
	{
		perror(inputFileName);

		return FALSE;
	}

	if (stat(outputFileName, &statBuf2) < 0)
	{
		statBuf2.st_ino = -1;
		statBuf2.st_dev = -1;
	}

	if ((statBuf1.st_dev == statBuf2.st_dev) &&
		(statBuf1.st_ino == statBuf2.st_ino))
	{
		fprintf(stderr,
			"Cannot compress file \"%s\" on top of itself\n",
			inputFileName);

		return FALSE;
	}

	/*
	 * Open the input file.
	 */
	inFD = open(inputFileName, O_RDONLY);

	if (inFD < 0)
	{
		perror(inputFileName);

		goto failed;
	}

	/*
	 * Ask the zlib library to open the output file.
	 */
	outGZ = gzopen(outputFileName, "wb9");

	if (outGZ == NULL)
	{
		fprintf(stderr, "%s: gzopen failed\n", outputFileName);

		goto failed;
	}

	/*
	 * Read the uncompressed data from the input file and write
	 * the compressed data to the output file.
	 */
	while ((len = read(inFD, buf, sizeof(buf))) > 0)
	{
		if (gzwrite(outGZ, buf, len) != len)
		{
			fprintf(stderr, "%s: %s\n", inputFileName,
				gzerror(outGZ, &err));

			goto failed;
		}

		if (intFlag)
			goto failed;
	}

	if (len < 0)
	{
		perror(inputFileName);

		goto failed;
	}

	/*
	 * All done, close the files.
	 */
	if (close(inFD))
	{
		perror(inputFileName);

		goto failed;
	}

	inFD = -1;

	if (gzclose(outGZ) != Z_OK)
	{
		fprintf(stderr, "%s: gzclose failed\n", outputFileName);

		goto failed;
	}

	outGZ = NULL;

	/*
	 * Success.
	 */
	return TRUE;


/*
 * Here on an error, to clean up.
 */
failed:
	if (inFD >= 0)
		(void) close(inFD);

	if (outGZ != NULL)
		(void) gzclose(outGZ);

	return FALSE;
}


/*
 * Uncompress the input file to produce the output file.
 * Returns TRUE if successful.
 */
static BOOL
gunzip(const char * inputFileName, const char * outputFileName)
{
	gzFile		inGZ;
	int		outFD;
	int		len;
	int		err;
	struct	stat	statBuf1;
	struct	stat	statBuf2;
	char		buf[BUF_SIZE];

	inGZ = NULL;
	outFD = -1;

	/*
	 * See if the output file is the same as the input file.
	 * If so, complain about it.
	 */
	if (stat(inputFileName, &statBuf1) < 0)
	{
		perror(inputFileName);

		return FALSE;
	}

	if (stat(outputFileName, &statBuf2) < 0)
	{
		statBuf2.st_ino = -1;
		statBuf2.st_dev = -1;
	}

	if ((statBuf1.st_dev == statBuf2.st_dev) &&
		(statBuf1.st_ino == statBuf2.st_ino))
	{
		fprintf(stderr,
			"Cannot uncompress file \"%s\" on top of itself\n",
			inputFileName);

		return FALSE;
	}

	/*
	 * Ask the zlib library to open the input file.
	 */
	inGZ = gzopen(inputFileName, "rb");

	if (inGZ == NULL)
	{
		fprintf(stderr, "%s: gzopen failed\n", inputFileName);

		return FALSE;
	}

	/*
	 * Create the output file.
	 */
	if (isDevice(outputFileName))
		outFD = open(outputFileName, O_WRONLY);
	else
		outFD = open(outputFileName, O_WRONLY|O_CREAT|O_TRUNC, 0666);

	if (outFD < 0)
	{
		perror(outputFileName);

		goto failed;
	}

	/*
	 * Read the compressed data from the input file and write
	 * the uncompressed data extracted from it to the output file.
	 */
	while ((len = gzread(inGZ, buf, sizeof(buf))) > 0)
	{
		if (fullWrite(outFD, buf, len) < 0)
		{
			perror(outputFileName);

			goto failed;
		}

		if (intFlag)
			goto failed;
	}

	if (len < 0)
	{
		fprintf(stderr, "%s: %s\n", inputFileName,
			gzerror(inGZ, &err));

		goto failed;
	}

	/*
	 * All done, close the files.
	 */
	if (close(outFD))
	{
		perror(outputFileName);

		goto failed;
	}

	outFD = -1;

	if (gzclose(inGZ) != Z_OK)
	{
		fprintf(stderr, "%s: gzclose failed\n", inputFileName);

		goto failed;
	}

	inGZ = NULL;

	/*
	 * Success.
	 */
	return TRUE;


/*
 * Here on an error, to clean up.
 */
failed:
	if (outFD >= 0)
		(void) close(outFD);

	if (inGZ != NULL)
		(void) gzclose(inGZ);

	return FALSE;
}


/*
 * Convert an input file name to an output file name according to
 * the specified convertion table.  The returned name points into a
 * static buffer which is overwritten on each call.  The table must
 * end in an entry which always specifies a successful conversion.
 * If no conversion is done the original input file name pointer is
 * returned.
 */
const char *
convertName(const CONVERT * table, const char * inputFile)
{
	int		inputLength;
	int		testLength;
	static char	buf[PATH_LEN];

	inputLength = strlen(inputFile);

	for (;;)
	{
		testLength = strlen(table->input);

		if ((inputLength >= testLength) &&
			(memcmp(table->input,
				inputFile + inputLength - testLength,
				testLength) == 0))
		{
			break;
		}

		table++;
	}

	/*
	 * If no conversion was done, return the original pointer.
	 */
	if ((testLength == 0) && (table->output[0] == '\0'))
		return inputFile;

	/*
	 * Build the new name and return it.
	 */
	memcpy(buf, inputFile, inputLength - testLength);

	memcpy(buf + inputLength - testLength, table->output,
		strlen(table->output) + 1);

	return buf;
}


#endif

/* END CODE */
