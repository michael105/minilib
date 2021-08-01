#if 0
mini_start
mini_fprintf
mini_itodec
mini_perror
mini_errno
mini_strchr
mini_malloc
mini_free
mini_open
mini_creat
mini_strcmp


mini_buf 192

INCLUDESRC
SHRINKELF
LDSCRIPT textandbss

return
#endif

#define BUF_SIZE 4096

/*
 * Copyright (c) 2014 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * The "dd" built-in command.
 */

//#include "sash.h"


#define	PAR_NONE	0
#define	PAR_IF		1
#define	PAR_OF		2
#define	PAR_BS		3
#define	PAR_COUNT	4
#define	PAR_SEEK	5
#define	PAR_SKIP	6


typedef	struct
{
	const char *	name;
	int		value;
} PARAM;


static const PARAM	params[] =
{
	{"if",		PAR_IF},
	{"of",		PAR_OF},
	{"bs",		PAR_BS},
	{"count",	PAR_COUNT},
	{"seek",	PAR_SEEK},
	{"skip",	PAR_SKIP},
	{NULL,		PAR_NONE}
};


static	long	getNum(const char * cp);


int main(int argc, const char ** argv)
{
	const char *	str;
	const PARAM *	par;
	const char *	inFile;
	const char *	outFile;
	char *		cp;
	int		inFd;
	int		outFd;
	int		inCc;
	int		outCc;
	int		blockSize;
	long		count;
	long		seekVal;
	long		skipVal;
	long		inFull;
	long		inPartial;
	long		outFull;
	long		outPartial;
	char *		buf;
	char		localBuf[BUF_SIZE];
	int		r;

	inFile = NULL;
	outFile = NULL;
	seekVal = 0;
	skipVal = 0;
	blockSize = 512;
	count = -1;
	r = 0;

	while (--argc > 0)
	{
		str = *++argv;
		cp = strchr(str, '=');

		if (cp == NULL)
		{
			fprintf(stderr, "Bad dd argument\n");

			return 1;
		}

		*cp++ = '\0';

		for (par = params; par->name; par++)
		{
			if (strcmp(str, par->name) == 0)
				break;
		}

		switch (par->value)
		{
			case PAR_IF:
				if (inFile)
				{
					fprintf(stderr, "Multiple input files illegal\n");

					return 1;
				}
	
				inFile = cp;
				break;

			case PAR_OF:
				if (outFile)
				{
					fprintf(stderr, "Multiple output files illegal\n");

					return 1;
				}

				outFile = cp;
				break;

			case PAR_BS:
				blockSize = getNum(cp);

				if (blockSize <= 0)
				{
					fprintf(stderr, "Bad block size value\n");

					return 1;
				}

				break;

			case PAR_COUNT:
				count = getNum(cp);

				if (count < 0)
				{
					fprintf(stderr, "Bad count value\n");

					return 1;
				}

				break;

			case PAR_SEEK:
				seekVal = getNum(cp);

				if (seekVal < 0)
				{
					fprintf(stderr, "Bad seek value\n");

					return 1;
				}

				break;

			case PAR_SKIP:
				skipVal = getNum(cp);

				if (skipVal < 0)
				{
					fprintf(stderr, "Bad skip value\n");

					return 1;
				}

				break;

			default:
				fprintf(stderr, "Unknown dd parameter\n");

				return 1;
		}
	}

	buf = localBuf;

	if (blockSize > sizeof(localBuf))
	{
		buf = malloc(blockSize);

		if (buf == NULL)
		{
			fprintf(stderr, "Cannot allocate buffer\n");

			return 1;
		}
	}

	inFull = 0;
	inPartial = 0;
	outFull = 0;
	outPartial = 0;

	if (inFile == NULL){
			inFd=STDIN_FILENO;
	} else {
			inFd = open(inFile, 0);
	}

	if (inFd < 0)
	{
		perror(inFile);

		if (buf != localBuf)
			free(buf);

		return 1;
	}

	if (outFile == NULL){
			outFd=STDOUT_FILENO;
	} else {
			outFd = creat(outFile, 0666);
	}

	if (outFd < 0)
	{
		perror(outFile);
		close(inFd);

		if (buf != localBuf)
			free(buf);

		return 1;
	}

	if (skipVal)
	{
		if (lseek(inFd, skipVal * blockSize, 0) < 0)
		{
			while (skipVal-- > 0)
			{
				inCc = read(inFd, buf, blockSize);

				if (inCc < 0)
				{
					perror(inFile);
					r = 1;
					goto cleanup;
				}

				if (inCc == 0)
				{
					fprintf(stderr, "End of file while skipping\n");
					r = 1;
					goto cleanup;
				}
			}
		}
	}

	if (seekVal)
	{
		if (lseek(outFd, seekVal * blockSize, 0) < 0)
		{
			perror(outFile);
			r = 1;
			goto cleanup;
		}
	}

	inCc = 0;

	while (((count < 0) || (inFull + inPartial < count)) &&
	       (inCc = read(inFd, buf, blockSize)) > 0)
	{
		if (inCc < blockSize)
			inPartial++;
		else
			inFull++;
		cp = buf;

		// todo: sigint handler (misc)
		//if (intFlag)
		//{
		//	fprintf(stderr, "Interrupted\n");
		//	r = 1;
		//	goto cleanup;
		//}

		while (inCc > 0)
		{
			outCc = write(outFd, cp, inCc);

			if (outCc < 0)
			{
				perror(outFile);
				r = 1;
				goto cleanup;
			}

			if (outCc < blockSize)
				outPartial++;
			else
				outFull++;
			cp += outCc;
			inCc -= outCc;
		}
	}

	if (inCc < 0)
		perror(inFile);

cleanup:
	close(inFd);

	if (close(outFd) < 0)
	{
		perror(outFile);
		r = 1;
	}

	if (buf != localBuf)
		free(buf);

	printf("%ld+%ld records in\n", inFull, inPartial);

	printf("%ld+%ld records out\n", outFull, outPartial);

	return r;
}

int isDecimal(char c){
		return( (c>='0') && (c<='9') );
}

/*
 * Read a number with a possible multiplier.
 * Returns -1 if the number format is illegal.
 */
static long
getNum(const char * cp)
{
	long	value;

	if (!isDecimal(*cp))
		return -1;

	value = 0;

	while (isDecimal(*cp))
		value = value * 10 + *cp++ - '0';

	switch (*cp++)
	{
		case 'k':
			value *= 1024;
			break;

		case 'b':
			value *= 512;
			break;

		case 'w':
			value *= 2;
			break;

		case '\0':
			return value;

		default:
			return -1;
	}

	if (*cp)
		return -1;

	return value;
}

/* END CODE */
