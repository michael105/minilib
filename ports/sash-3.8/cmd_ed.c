/*
 * Copyright (c) 2014 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * The "ed" built-in command (much simplified)
 */

#include "sash.h"

#define	USERSIZE	1024	/* max line length typed in by user */
#define	INITBUF_SIZE	1024	/* initial buffer size */


typedef	int	NUM;
typedef	int	LEN;

typedef	struct	LINE	LINE;

struct	LINE
{
	LINE *	next;
	LINE *	prev;
	LEN	len;
	char	data[1];
};


static	LINE	lines;
static	LINE *	curLine;
static	NUM	curNum;
static	NUM	lastNum;
static	NUM	marks[26];
static	BOOL	dirty;
static	char *	fileName;
static	char	searchString[USERSIZE];

static	char *	bufBase;
static	char *	bufPtr;
static	LEN	bufUsed;
static	LEN	bufSize;


static	void	doCommands(void);
static	void	subCommand(const char * cmd, NUM num1, NUM num2);
static	BOOL	getNum(const char ** retcp, BOOL * retHaveNum, NUM * retNum);
static	BOOL	setCurNum(NUM num);
static	BOOL	initEdit(void);
static	void	termEdit(void);
static	void	addLines(NUM num);
static	BOOL	insertLine(NUM num, const char * data, LEN len);
static	BOOL	deleteLines(NUM num1, NUM num2);
static	BOOL	printLines(NUM num1, NUM num2, BOOL expandFlag);
static	BOOL	writeLines(const char * file, NUM num1, NUM num2);
static	BOOL	readLines(const char * file, NUM num);
static	NUM	searchLines(const char * str, NUM num1, NUM num2);
static	LINE *	findLine(NUM num);

static	LEN	findString
	(const LINE * lp, const char * str, LEN len, LEN offset);


int
do_ed(int argc, const char ** argv)
{
	if (!initEdit())
		return 1;

	if (argc > 1)
	{
		fileName = strdup(argv[1]);

		if (fileName == NULL)
		{
			fprintf(stderr, "No memory\n");
			termEdit();

			return 1;
		}

		if (!readLines(fileName, 1))
		{
			termEdit();

			return 1;
		}

		if (lastNum)
			setCurNum(1);

		dirty = FALSE;
	}

	doCommands();

	termEdit();
	return 0;
}


/*
 * Read commands until we are told to stop.
 */
static void
doCommands(void)
{
	const char *	cp;
	char *		endbuf;
	char *		newname;
	int		len;
	NUM		num1;
	NUM		num2;
	BOOL		have1;
	BOOL		have2;
	char		buf[USERSIZE];

	while (TRUE)
	{
		intFlag = FALSE;
		printf(": ");
		fflush(stdout);

		if (fgets(buf, sizeof(buf), stdin) == NULL)
			return;

		len = strlen(buf);

		if (len == 0)
			return;

		endbuf = &buf[len - 1];

		if (*endbuf != '\n')
		{
			fprintf(stderr, "Command line too long\n");

			do
			{
				len = fgetc(stdin);
			}
			while ((len != EOF) && (len != '\n'));

			continue;
		}

		while ((endbuf > buf) && isBlank(endbuf[-1]))
			endbuf--;

		*endbuf = '\0';

		cp = buf;

		while (isBlank(*cp))
			cp++;

		have1 = FALSE;
		have2 = FALSE;

		if ((curNum == 0) && (lastNum > 0))
		{
			curNum = 1;
			curLine = lines.next;
		}

		if (!getNum(&cp, &have1, &num1))
			continue;

		while (isBlank(*cp))
			cp++;

		if (*cp == ',')
		{
			cp++;

			if (!getNum(&cp, &have2, &num2))
				continue;

			if (!have1)
				num1 = 1;

			if (!have2)
				num2 = lastNum;

			have1 = TRUE;
			have2 = TRUE;
		}

		if (!have1)
			num1 = curNum;

		if (!have2)
			num2 = num1;

		switch (*cp++)
		{
			case 'a':
				addLines(num1 + 1);
				break;

			case 'c':
				deleteLines(num1, num2);
				addLines(num1);
				break;

			case 'd':
				deleteLines(num1, num2);
				break;

			case 'f':
				if (*cp && !isBlank(*cp))
				{
					fprintf(stderr, "Bad file command\n");
					break;
				}

				while (isBlank(*cp))
					cp++;

				if (*cp == '\0')
				{
					if (fileName)
						printf("\"%s\"\n", fileName);
					else
						printf("No file name\n");

					break;
				}

				newname = strdup(cp);

				if (newname == NULL)
				{
					fprintf(stderr, "No memory for file name\n");
					break;
				}

				if (fileName)
					free(fileName);

				fileName = newname;
				break;

			case 'i':
				addLines(num1);
				break;

			case 'k':
				while (isBlank(*cp))
					cp++;

				if ((*cp < 'a') || (*cp > 'a') || cp[1])
				{
					fprintf(stderr, "Bad mark name\n");
					break;
				}

				marks[*cp - 'a'] = num2;
				break;

			case 'l':
				printLines(num1, num2, TRUE);
				break;

			case 'p':
				printLines(num1, num2, FALSE);
				break;

			case 'q':
				while (isBlank(*cp))
					cp++;

				if (have1 || *cp)
				{
					fprintf(stderr, "Bad quit command\n");
					break;
				}

				if (!dirty)
					return;

				printf("Really quit? ");
				fflush(stdout);

				buf[0] = '\0';

				if (fgets(buf, sizeof(buf), stdin) == NULL)
					return;

				cp = buf;

				while (isBlank(*cp))
					cp++;

				if ((*cp == 'y') || (*cp == 'Y'))
					return;

				break;

			case 'r':
				if (*cp && !isBlank(*cp))
				{
					fprintf(stderr, "Bad read command\n");
					break;
				}

				while (isBlank(*cp))
					cp++;

				if (*cp == '\0')
				{
					fprintf(stderr, "No file name\n");
					break;
				}

				if (!have1)
					num1 = lastNum;

				if (readLines(cp, num1 + 1))
					break;

				if (fileName == NULL)
					fileName = strdup(cp);

				break;

			case 's':
				subCommand(cp, num1, num2);
				break;

			case 'w':
				if (*cp && !isBlank(*cp))
				{
					fprintf(stderr, "Bad write command\n");
					break;
				}

				while (isBlank(*cp))
					cp++;

				if (!have1) {
					num1 = 1;
					num2 = lastNum;
				}

				if (*cp == '\0')
					cp = fileName;

				if (cp == NULL)
				{
					fprintf(stderr, "No file name specified\n");
					break;
				}
	
				writeLines(cp, num1, num2);
				break;

			case 'z':
				switch (*cp)
				{
				case '-':
					printLines(curNum-21, curNum, FALSE);
					break;
				case '.':
					printLines(curNum-11, curNum+10, FALSE);
					break;
				default:
					printLines(curNum, curNum+21, FALSE);
					break;
				}
				break;

			case '.':
				if (have1)
				{
					fprintf(stderr, "No arguments allowed\n");
					break;
				}

				printLines(curNum, curNum, FALSE);
				break;
	
			case '-':
				if (setCurNum(curNum - 1))
					printLines(curNum, curNum, FALSE);

				break;

			case '=':
				printf("%d\n", num1);
				break;

			case '\0':
				if (have1)
				{
					printLines(num2, num2, FALSE);
					break;
				}

				if (setCurNum(curNum + 1))
					printLines(curNum, curNum, FALSE);

				break;

			default:
				fprintf(stderr, "Unimplemented command\n");
				break;
		}
	}
}


/*
 * Do the substitute command.
 * The current line is set to the last substitution done.
 */
static void
subCommand(const char * cmd, NUM num1, NUM num2)
{
	int	delim;
	char *	cp;
	char *	oldStr;
	char *	newStr;
	LEN	oldLen;
	LEN	newLen;
	LEN	deltaLen;
	LEN	offset;
	LINE *	lp;
	LINE *	nlp;
	BOOL	globalFlag;
	BOOL	printFlag;
	BOOL	didSub;
	BOOL	needPrint;
	char	buf[USERSIZE];

	if ((num1 < 1) || (num2 > lastNum) || (num1 > num2))
	{
		fprintf(stderr, "Bad line range for substitute\n");

		return;
	}

	globalFlag = FALSE;
	printFlag = FALSE;
	didSub = FALSE;
	needPrint = FALSE;

	/*
	 * Copy the command so we can modify it.
	 */
	strcpy(buf, cmd);
	cp = buf;

	if (isBlank(*cp) || (*cp == '\0'))
	{
		fprintf(stderr, "Bad delimiter for substitute\n");

		return;
	}

	delim = *cp++;
	oldStr = cp;

	cp = strchr(cp, delim);

	if (cp == NULL)
	{
		fprintf(stderr, "Missing 2nd delimiter for substitute\n");

		return;
	}

	*cp++ = '\0';

	newStr = cp;
	cp = strchr(cp, delim);

	if (cp)
		*cp++ = '\0';
	else
		cp = "";

	while (*cp) switch (*cp++)
	{
		case 'g':
			globalFlag = TRUE;
			break;

		case 'p':
			printFlag = TRUE;
			break;

		default:
			fprintf(stderr, "Unknown option for substitute\n");

			return;
	}

	if (*oldStr == '\0')
	{
		if (searchString[0] == '\0')
		{
			fprintf(stderr, "No previous search string\n");

			return;
		}

		oldStr = searchString;
	}

	if (oldStr != searchString)
		strcpy(searchString, oldStr);

	lp = findLine(num1);

	if (lp == NULL)
		return;

	oldLen = strlen(oldStr);
	newLen = strlen(newStr);
	deltaLen = newLen - oldLen;
	offset = 0;
	nlp = NULL;

	while (num1 <= num2)
	{
		offset = findString(lp, oldStr, oldLen, offset);

		if (offset < 0)
		{
			if (needPrint)
			{
				printLines(num1, num1, FALSE);
				needPrint = FALSE;
			}

			offset = 0;
			lp = lp->next;
			num1++;

			continue;
		}

		needPrint = printFlag;
		didSub = TRUE;
		dirty = TRUE;

		/*
		 * If the replacement string is the same size or shorter
		 * than the old string, then the substitution is easy.
		 */
		if (deltaLen <= 0)
		{
			memcpy(&lp->data[offset], newStr, newLen);

			if (deltaLen)
			{
				memcpy(&lp->data[offset + newLen],
					&lp->data[offset + oldLen],
					lp->len - offset - oldLen);

				lp->len += deltaLen;
			}

			offset += newLen;

			if (globalFlag)
				continue;

			if (needPrint)
			{
				printLines(num1, num1, FALSE);
				needPrint = FALSE;
			}

			lp = lp->next;
			num1++;

			continue;
		}

		/*
		 * The new string is larger, so allocate a new line
		 * structure and use that.  Link it in in place of
		 * the old line structure.
		 */
		nlp = (LINE *) malloc(sizeof(LINE) + lp->len + deltaLen);

		if (nlp == NULL)
		{
			fprintf(stderr, "Cannot get memory for line\n");

			return;
		}

		nlp->len = lp->len + deltaLen;

		memcpy(nlp->data, lp->data, offset);

		memcpy(&nlp->data[offset], newStr, newLen);

		memcpy(&nlp->data[offset + newLen],
			&lp->data[offset + oldLen],
			lp->len - offset - oldLen);

		nlp->next = lp->next;
		nlp->prev = lp->prev;
		nlp->prev->next = nlp;
		nlp->next->prev = nlp;

		if (curLine == lp)
			curLine = nlp;

		free(lp);
		lp = nlp;

		offset += newLen;

		if (globalFlag)
			continue;

		if (needPrint)
		{
			printLines(num1, num1, FALSE);
			needPrint = FALSE;
		}

		lp = lp->next;
		num1++;
	}

	if (!didSub)
		fprintf(stderr, "No substitutions found for \"%s\"\n", oldStr);
}


/*
 * Search a line for the specified string starting at the specified
 * offset in the line.  Returns the offset of the found string, or -1.
 */
static LEN
findString( const LINE * lp, const char * str, LEN len, LEN offset)
{
	LEN		left;
	const char *	cp;
	const char *	ncp;

	cp = &lp->data[offset];
	left = lp->len - offset;

	while (left >= len)
	{
		ncp = memchr(cp, *str, left);

		if (ncp == NULL)
			return -1;

		left -= (ncp - cp);

		if (left < len)
			return -1;

		cp = ncp;

		if (memcmp(cp, str, len) == 0)
			return (cp - lp->data);

		cp++;
		left--;
	}

	return -1;
}


/*
 * Add lines which are typed in by the user.
 * The lines are inserted just before the specified line number.
 * The lines are terminated by a line containing a single dot (ugly!),
 * or by an end of file.
 */
static void
addLines(NUM num)
{
	int	len;
	char	buf[USERSIZE + 1];

	while (fgets(buf, sizeof(buf), stdin))
	{
		if ((buf[0] == '.') && (buf[1] == '\n') && (buf[2] == '\0'))
			return;

		len = strlen(buf);

		if (len == 0)
			return;

		if (buf[len - 1] != '\n')
		{
			fprintf(stderr, "Line too long\n");

			do
			{
				len = fgetc(stdin);
			}
			while ((len != EOF) && (len != '\n'));

			return;
		}

		if (!insertLine(num++, buf, len))
			return;
	}
}


/*
 * Parse a line number argument if it is present.  This is a sum
 * or difference of numbers, '.', '$', 'x, or a search string.
 * Returns TRUE if successful (whether or not there was a number). 
 * Returns FALSE if there was a parsing error, with a message output.
 * Whether there was a number is returned indirectly, as is the number.
 * The character pointer which stopped the scan is also returned.
 */
static BOOL
getNum(const char ** retcp, BOOL * retHaveNum, NUM * retNum)
{
	const char *	cp;
	char *		endStr;
	char		str[USERSIZE];
	BOOL		haveNum;
	NUM		value;
	NUM		num;
	NUM		sign;

	cp = *retcp;
	haveNum = FALSE;
	value = 0;
	sign = 1;

	while (TRUE)
	{
		while (isBlank(*cp))
			cp++;

		switch (*cp)
		{
			case '.':
				haveNum = TRUE;
				num = curNum;
				cp++;
				break;

			case '$':
				haveNum = TRUE;
				num = lastNum;
				cp++;
				break;

			case '\'':
				cp++;

				if ((*cp < 'a') || (*cp > 'z'))
				{
					fprintf(stderr, "Bad mark name\n");

					return FALSE;
				}

				haveNum = TRUE;
				num = marks[*cp++ - 'a'];
				break;

			case '/':
				strcpy(str, ++cp);
				endStr = strchr(str, '/');

				if (endStr)
				{
					*endStr++ = '\0';
					cp += (endStr - str);
				}
				else
					cp = "";

				num = searchLines(str, curNum, lastNum);

				if (num == 0)
					return FALSE;

				haveNum = TRUE;
				break;

			default:
				if (!isDecimal(*cp))
				{
					*retcp = cp;
					*retHaveNum = haveNum;
					*retNum = value;

					return TRUE;
				}

				num = 0;

				while (isDecimal(*cp))
					num = num * 10 + *cp++ - '0';

				haveNum = TRUE;
				break;
		}

		value += num * sign;

		while (isBlank(*cp))
			cp++;

		switch (*cp)
		{
			case '-':
				sign = -1;
				cp++;
				break;

			case '+':
				sign = 1;
				cp++;
				break;

			default:
				*retcp = cp;
				*retHaveNum = haveNum;
				*retNum = value;

				return TRUE;
		}
	}
}


/*
 * Initialize everything for editing.
 */
static BOOL
initEdit(void)
{
	int	i;

	bufSize = INITBUF_SIZE;
	bufBase = malloc(bufSize);

	if (bufBase == NULL)
	{
		fprintf(stderr, "No memory for buffer\n");

		return FALSE;
	}

	bufPtr = bufBase;
	bufUsed = 0;

	lines.next = &lines;
	lines.prev = &lines;

	curLine = NULL;
	curNum = 0;
	lastNum = 0;
	dirty = FALSE;
	fileName = NULL;
	searchString[0] = '\0';

	for (i = 0; i < 26; i++)
		marks[i] = 0;

	return TRUE;
}


/*
 * Finish editing.
 */
static void
termEdit(void)
{
	if (bufBase)
		free(bufBase);

	bufBase = NULL;
	bufPtr = NULL;
	bufSize = 0;
	bufUsed = 0;

	if (fileName)
		free(fileName);

	fileName = NULL;

	searchString[0] = '\0';

	if (lastNum)
		deleteLines(1, lastNum);

	lastNum = 0;
	curNum = 0;
	curLine = NULL;
}


/*
 * Read lines from a file at the specified line number.
 * Returns TRUE if the file was successfully read.
 */
static BOOL
readLines(const char * file, NUM num)
{
	int	fd;
	int	cc;
	LEN	len;
	LEN	lineCount;
	LEN	charCount;
	char *	cp;

	if ((num < 1) || (num > lastNum + 1))
	{
		fprintf(stderr, "Bad line for read\n");

		return FALSE;
	}

	fd = open(file, 0);

	if (fd < 0)
	{
		perror(file);

		return FALSE;
	}

	bufPtr = bufBase;
	bufUsed = 0;
	lineCount = 0;
	charCount = 0;
	cc = 0;

	printf("\"%s\", ", file);
	fflush(stdout);

	do
	{
		if (intFlag)
		{
			printf("INTERRUPTED, ");
			bufUsed = 0;
			break;
		}

		cp = memchr(bufPtr, '\n', bufUsed);

		if (cp)
		{
			len = (cp - bufPtr) + 1;

			if (!insertLine(num, bufPtr, len))
			{
				close(fd);

				return FALSE;
			}

			bufPtr += len;
			bufUsed -= len;
			charCount += len;
			lineCount++;
			num++;

			continue;
		}

		if (bufPtr != bufBase)
		{
			memcpy(bufBase, bufPtr, bufUsed);
			bufPtr = bufBase + bufUsed;
		}

		if (bufUsed >= bufSize)
		{
			len = (bufSize * 3) / 2;
			cp = realloc(bufBase, len);

			if (cp == NULL)
			{
				fprintf(stderr, "No memory for buffer\n");
				close(fd);

				return FALSE;
			}

			bufBase = cp;
			bufPtr = bufBase + bufUsed;
			bufSize = len;
		}

		cc = read(fd, bufPtr, bufSize - bufUsed);
		bufUsed += cc;
		bufPtr = bufBase;

	}
	while (cc > 0);

	if (cc < 0)
	{
		perror(file);
		close(fd);

		return FALSE;
	}

	if (bufUsed)
	{
		if (!insertLine(num, bufPtr, bufUsed))
		{
			close(fd);

			return -1;
		}

		lineCount++;
		charCount += bufUsed;
	}

	close(fd);

	printf("%d lines%s, %d chars\n", lineCount,
		(bufUsed ? " (incomplete)" : ""), charCount);

	return TRUE;
}


/*
 * Write the specified lines out to the specified file.
 * Returns TRUE if successful, or FALSE on an error with a message output.
 */
static BOOL
writeLines(const char * file, NUM num1, NUM num2)
{
	int	fd;
	LINE *	lp;
	LEN	lineCount;
	LEN	charCount;

	if ((num1 < 1) || (num2 > lastNum) || (num1 > num2))
	{
		fprintf(stderr, "Bad line range for write\n");

		return FALSE;
	}

	lineCount = 0;
	charCount = 0;

	fd = creat(file, 0666);

	if (fd < 0) {
		perror(file);

		return FALSE;
	}

	printf("\"%s\", ", file);
	fflush(stdout);

	lp = findLine(num1);

	if (lp == NULL)
	{
		close(fd);

		return FALSE;
	}

	while (num1++ <= num2)
	{
		if (write(fd, lp->data, lp->len) != lp->len)
		{
			perror(file);
			close(fd);

			return FALSE;
		}

		charCount += lp->len;
		lineCount++;
		lp = lp->next;
	}

	if (close(fd) < 0)
	{
		perror(file);

		return FALSE;
	}

	printf("%d lines, %d chars\n", lineCount, charCount);

	return TRUE;
}


/*
 * Print lines in a specified range.
 * The last line printed becomes the current line.
 * If expandFlag is TRUE, then the line is printed specially to
 * show magic characters.
 */
static BOOL
printLines(NUM num1, NUM num2, BOOL expandFlag)
{
	const LINE *	lp;
	const char *	cp;
	int		ch;
	LEN		count;

	if ((num1 < 1) || (num2 > lastNum) || (num1 > num2))
	{
		fprintf(stderr, "Bad line range for print\n");

		return FALSE;
	}

	lp = findLine(num1);

	if (lp == NULL)
		return FALSE;

	while (!intFlag && (num1 <= num2))
	{
		if (!expandFlag)
		{
			tryWrite(STDOUT, lp->data, lp->len);
			setCurNum(num1++);
			lp = lp->next;

			continue;
		}

		/*
		 * Show control characters and characters with the
		 * high bit set specially.
		 */
		cp = lp->data;
		count = lp->len;

		if ((count > 0) && (cp[count - 1] == '\n'))
			count--;

		while (count-- > 0)
		{
			ch = *cp++ & 0xff;

			if (ch & 0x80)
			{
				fputs("M-", stdout);
				ch &= 0x7f;
			}

			if (ch < ' ')
			{
				fputc('^', stdout);
				ch += '@';
			}

			if (ch == 0x7f)
			{
				fputc('^', stdout);
				ch = '?';
			}

			fputc(ch, stdout);
		}

		fputs("$\n", stdout);

		setCurNum(num1++);
		lp = lp->next;
	}

	return TRUE;
}


/*
 * Insert a new line with the specified text.
 * The line is inserted so as to become the specified line,
 * thus pushing any existing and further lines down one.
 * The inserted line is also set to become the current line.
 * Returns TRUE if successful.
 */
static BOOL
insertLine(NUM num, const char * data, LEN len)
{
	LINE *	newLp;
	LINE *	lp;

	if ((num < 1) || (num > lastNum + 1))
	{
		fprintf(stderr, "Inserting at bad line number\n");

		return FALSE;
	}

	newLp = (LINE *) malloc(sizeof(LINE) + len - 1);

	if (newLp == NULL) 
	{
		fprintf(stderr, "Failed to allocate memory for line\n");

		return FALSE;
	}

	memcpy(newLp->data, data, len);
	newLp->len = len;

	if (num > lastNum)
		lp = &lines;
	else
	{
		lp = findLine(num);

		if (lp == NULL)
		{
			free((char *) newLp);

			return FALSE;
		}
	}

	newLp->next = lp;
	newLp->prev = lp->prev;
	lp->prev->next = newLp;
	lp->prev = newLp;

	lastNum++;
	dirty = TRUE;

	return setCurNum(num);
}


/*
 * Delete lines from the given range.
 */
static BOOL
deleteLines(NUM num1, NUM num2)
{
	LINE *	lp;
	LINE *	nlp;
	LINE *	plp;
	NUM	count;

	if ((num1 < 1) || (num2 > lastNum) || (num1 > num2))
	{
		fprintf(stderr, "Bad line numbers for delete\n");

		return FALSE;
	}

	lp = findLine(num1);

	if (lp == NULL)
		return FALSE;

	if ((curNum >= num1) && (curNum <= num2))
	{
		if (num2 < lastNum)
			setCurNum(num2 + 1);
		else if (num1 > 1)
			setCurNum(num1 - 1);
		else
			curNum = 0;
	}

	count = num2 - num1 + 1;

	if (curNum > num2)
		curNum -= count;

	lastNum -= count;

	while (count-- > 0)
	{
		nlp = lp->next;
		plp = lp->prev;
		plp->next = nlp;
		nlp->prev = plp;
		lp->next = NULL;
		lp->prev = NULL;
		lp->len = 0;
		free(lp);
		lp = nlp;
	}

	dirty = TRUE;

	return TRUE;
}


/*
 * Search for a line which contains the specified string.
 * If the string is NULL, then the previously searched for string
 * is used.  The currently searched for string is saved for future use.
 * Returns the line number which matches, or 0 if there was no match
 * with an error printed.
 */
static NUM
searchLines(const char * str, NUM num1, NUM num2)
{
	const LINE *	lp;
	int		len;

	if ((num1 < 1) || (num2 > lastNum) || (num1 > num2))
	{
		fprintf(stderr, "Bad line numbers for search\n");

		return 0;
	}

	if (*str == '\0')
	{
		if (searchString[0] == '\0')
		{
			fprintf(stderr, "No previous search string\n");

			return 0;
		}

		str = searchString;
	}

	if (str != searchString)
		strcpy(searchString, str);

	len = strlen(str);

	lp = findLine(num1);

	if (lp == NULL)
		return 0;

	while (num1 <= num2)
	{
		if (findString(lp, str, len, 0) >= 0)
			return num1;

		num1++;
		lp = lp->next;
	}

	fprintf(stderr, "Cannot find string \"%s\"\n", str);

	return 0;
}


/*
 * Return a pointer to the specified line number.
 */
static LINE *
findLine(NUM num)
{
	LINE *	lp;
	NUM	lnum;

	if ((num < 1) || (num > lastNum))
	{
		fprintf(stderr, "Line number %d does not exist\n", num);

		return NULL;
	}

	if (curNum <= 0)
	{
		curNum = 1;
		curLine = lines.next;
	}

	if (num == curNum)
		return curLine;

	lp = curLine;
	lnum = curNum;

	if (num < (curNum / 2))
	{
		lp = lines.next;
		lnum = 1;
	}
	else if (num > ((curNum + lastNum) / 2))
	{
		lp = lines.prev;
		lnum = lastNum;
	}

	while (lnum < num)
	{
		lp = lp->next;
		lnum++;
	}

	while (lnum > num)
	{
		lp = lp->prev;
		lnum--;
	}

	return lp;
}


/*
 * Set the current line number.
 * Returns TRUE if successful.
 */
static BOOL
setCurNum(NUM num)
{
	LINE *	lp;

	lp = findLine(num);

	if (lp == NULL)
		return FALSE;

	curNum = num;
	curLine = lp;

	return TRUE;
}

/* END CODE */
