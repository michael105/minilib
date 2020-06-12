/*
 * Copyright (c) 2014 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * Stand-alone shell for system maintainance for Linux.
 * This program should NOT be built using shared libraries.
 */

#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

#include "sash.h"


static const char * const	version = "3.8";


/*
 * The special maximum argument value which means that there is
 * no limit to the number of arguments on the command line.
 */
#define	INFINITE_ARGS	0x7fffffff


/*
 * One entry of the command table.
 */
typedef struct
{
	const char *	name;
	int		(*func)(int argc, const char ** argv);
	int		minArgs;
	int		maxArgs;
	const char *	description;
	const char *	usage;
} CommandEntry;


/*
 * The table of built-in commands.
 * This is terminated wih an entry containing NULL values.
 */
static const CommandEntry	commandEntryTable[] =
{
	{
		"alias",	do_alias,	1,	INFINITE_ARGS,
		"Define a command alias",
		"[name [command]]"
	},

	{
		"aliasall",	do_aliasall,	1,	1,
		"Define aliases for all of the build-in commands",
		""
	},

/*	{
		"-ar",		do_ar,		3,	INFINITE_ARGS,
		"Extract or list files from an AR file",
		"[txp]v arFileName fileName ..."
	},
*/
	{
		"cd",		do_cd,		1,	2,
		"Change current directory",
		"[dirName]"
	},

/*	
#if	HAVE_LINUX_ATTR
	{
		"-chattr",	do_chattr,	3,	INFINITE_ARGS,
		"Change ext2 file attributes",
		"[+i] [-i] [+a] [-a] fileName ..."
	},
#endif
*/
	{
		"-chgrp",	do_chgrp,	3,	INFINITE_ARGS,
		"Change the group id of some files",
		"gid fileName ..."
	},

	{
		"-chmod",	do_chmod,	3,	INFINITE_ARGS,
		"Change the protection of some files",
		"mode fileName ..."
	},

	{
		"-chown",	do_chown,	3,	INFINITE_ARGS,
		"Change the owner id of some files",
		"uid fileName ..."
	},

	{
		"-cmp",		do_cmp,		3,	3,
		"Compare two files for equality",
		"fileName1 fileName2"
	},

	{
		"-cp",		do_cp,		3,	INFINITE_ARGS,
		"Copy files",
		"srcName ... destName"
	},

#ifdef	HAVE_LINUX_CHROOT
	{
		"-chroot",	do_chroot,	2,	2,
		"change root file system",
		"new_root_dir"
	},
#endif
/*
	{
		"-dd",		do_dd,		3,	INFINITE_ARGS,
		"Copy data between two files",
		"if=name of=name [bs=n] [count=n] [skip=n] [seek=n]"
	},
*/
	{
		"-echo",	do_echo,	1,	INFINITE_ARGS,
		"Echo the arguments",
		"[args] ..."
	},
/*
	{
		"-ed",		do_ed,		1,	2,
		"Edit a fileName using simple line mode commands",
		"[fileName]"
	},
*/
	{
		"exec",		do_exec,	2,	INFINITE_ARGS,
		"Execute another program in place of this sash process",
		"fileName [args]"
	},

	{
		"exit",		do_exit,	1,	2,
		"Exit from sash",
		"[exit value]"
	},
/*
	{
		"-file",	do_file,	1,	INFINITE_ARGS,
		"Describe information about files",
		"fileName ..."
	},

	{
		"-find",	do_find,	2,	INFINITE_ARGS,
		"Find files in a directory tree meeting some conditions",
		"dirName [-xdev] [-type chars] [-name pattern] [-size minSize]"
	},

	{
		"-grep",	do_grep,	3,	INFINITE_ARGS,
		"Look for lines containing a word in some files",
		"[-in] word fileName ..."
	},

#if	HAVE_GZIP
	{
		"-gunzip",	do_gunzip,	2,	INFINITE_ARGS,
		"Uncompress files which were saved in GZIP or compress format",
		"fileName ... [-o outputPath]"
	},

	{
		"-gzip",	do_gzip,	2,	INFINITE_ARGS,
		"Compress files into GZIP format",
		"fileName ... [-o outputPath]"
	},
#endif
*/
	{
		"help",		do_help,	1,	2,
		"Print help about a command",
		"[word]"
	},

	{
		"-kill",	do_kill,	2,	INFINITE_ARGS,
		"Send a signal to the specified process",
		"[-sig] pid ..."
	},

#ifdef	HAVE_LINUX_LOSETUP
	{
		"-losetup",	do_losetup,	3,	3,
		"Associate a loopback device with a file",
		"[-d] device\n       -losetup device filename"
	},
#endif

	{
		"-ln",		do_ln,		3,	INFINITE_ARGS,
		"Link one fileName to another",
		"[-s] srcName ... destName"
	},
/*
	{
		"-ls",		do_ls,		1,	INFINITE_ARGS,
		"List information about files or directories",
		"[-lidFC] fileName ..."
	},
*/
#if	HAVE_LINUX_ATTR
	{
		"-lsattr",	do_lsattr,	2,	INFINITE_ARGS,
		"List ext2 file attributes",
		"fileName ..."
	},
#endif

	{
		"-mkdir",	do_mkdir,	2,	INFINITE_ARGS,
		"Create a directory",
		"dirName ..."
	},

	{
		"-mknod",	do_mknod,	5,	5,
		"Create a special type of file",
		"fileName type major minor"
	},

	{
		"-more",	do_more,	2,	INFINITE_ARGS,
		"Type file contents page by page",
		"fileName ..."
	},

	{
		"-mount",	do_mount,	3,	INFINITE_ARGS,
		"Mount or remount a filesystem on a directory",
#if	HAVE_LINUX_MOUNT
		"[-t type] [-r] [-s] [-e] [-m] devName dirName"
#elif	HAVE_BSD_MOUNT
		"[-t type] [-r] [-s] [-e] devName dirName"
#else
		"[-t type] devName dirName"
#endif
	},

	{
		"-mv",		do_mv,		3,	INFINITE_ARGS,
		"Move or rename files",
		"srcName ... destName"
	},

#ifdef	HAVE_LINUX_PIVOT
	{
		"-pivot_root",	do_pivot_root,	3,	3,
		"pivot the root file system",
		"new_dir old_dir"
	},
#endif

	{
		"-printenv",	do_printenv,	1,	2,
		"Print environment variables",
		"[name]"
	},

	{
		"prompt",	do_prompt,	2,	INFINITE_ARGS,
		"Set the prompt string for sash",
		"string"
	},

	{
		"-pwd",		do_pwd,		1,	1,
		"Print the current working directory",
		""
	},

	{
		"quit",		do_exit,	1,	1,
		"Exit from sash",
		""
	},

	{
		"-rm",		do_rm,		2,	INFINITE_ARGS,
		"Remove the specified files",
		"fileName ..."
	},

	{
		"-rmdir",	do_rmdir,	2,	INFINITE_ARGS,
		"Remove the specified empty directories",
		"dirName ..."
	},

	{
		"setenv",	do_setenv,	3,	3,
		"Set an environment variable value",
		"name value"
	},

	{
		"source",	do_source,	2,	2,
		"Read commands from the specified file",
		"fileName"
	},

	{
		"-sum",		do_sum,		2,	INFINITE_ARGS,
		"Calculate checksums of the specified files",
		"fileName ..."
	},

	{
		"-sync",	do_sync,	1,	1,
		"Sync the disks to force cached data to them",
		""
	},
/*
	{
		"-tar",		do_tar,		2,	INFINITE_ARGS,
		"Create, extract, or list files from a TAR file",
		"[cxtv]f tarFileName fileName ..."
	},
*/
	{
		"-touch",	do_touch,	2,	INFINITE_ARGS,
		"Update times or create the specified files",
		"fileName ..."
	},

	{
		"umask",	do_umask,	1,	2,
		"Set the umask value for file protections",
		"[mask]"
	},

	{
#if	HAVE_BSD_MOUNT
		"-umount",	do_umount,	2,	3,
		"Unmount a filesystem",
		"[-f] fileName"
#else
		"-umount",	do_umount,	2,	2,
		"Unmount a filesystem",
		"fileName"
#endif
	},

	{
		"unalias",	do_unalias,	2,	2,
		"Remove a command alias",
		"name"
	},

	{
		"-where",	do_where,	2,	2,
		"Type the location of a program",
		"program"
	},

	{
		NULL,		0,		0,	0,
		NULL,
		NULL
	}
};


/*
 * The definition of an command alias.
 */
typedef struct
{
	char *	name;
	char *	value;
} Alias;


/*
 * Local data.
 */
static	Alias *	aliasTable;
static	int	aliasCount;

static	FILE *	sourcefiles[MAX_SOURCE];
static	int	sourceCount;

static	BOOL	intCrlf = TRUE;
static	char *	prompt;


/*
 * Local procedures.
 */
static	void	catchInt(int);
static	void	catchQuit(int);
static	int	readFile(const char * name);
static	int	command(const char * cmd);
static	BOOL	tryBuiltIn(const char * cmd);
static	int	runCmd(const char * cmd);
static	void	childProcess(const char * cmd);
static	void	showPrompt(void);
static	void	usage(void);
static	Alias *	findAlias(const char * name);
static	void	expandVariable(char * name);


/*
 * Global interrupt flag.
 */
BOOL	intFlag;


int
main(int argc, const char ** argv)
{
	const char *	cp;
	const char *	singleCommand;
	const char *	commandFile;
	BOOL		quietFlag;
	BOOL		aliasFlag;
        BOOL		interactiveFlag;
	char		buf[PATH_LEN];

	singleCommand = NULL;
	commandFile = NULL;
	quietFlag = FALSE;
	aliasFlag = FALSE;
        interactiveFlag = FALSE;

	/*
	 * Look for options.
	 */
	argv++;
	argc--;

	while ((argc > 0) && (**argv == '-'))
	{
		cp = *argv++ + 1;
		argc--;

		while (*cp) switch (*cp++)
		{
                        case '-':
                                /*
                                 * Ignore.  This is so that we can be
                                 * run from login.
                                 */
                                break;

			case 'c':
				/*
				 * Execute specified command.
				 */
				if ((argc != 1) || singleCommand || interactiveFlag)
					usage();

				singleCommand = *argv++;
				argc--;

				break;

			case 'f':
				/*
				 * Execute commands from file.
				 * This is used for sash script files.
				 * The quiet flag is also set.
				 */
				if ((argc != 1) || commandFile)
					usage();

				quietFlag = TRUE;
				commandFile = *argv++;
				argc--;

				break;

			case 'i':
				/*
				 * Be an interactive shell
				 * ..is a no-op, but some contexts require this
				 * ..interactiveFlag is to avoid -ic as a legacy
				 */
				 if (singleCommand)
				 	usage();
				 
				 interactiveFlag = TRUE;
				 break;
				 
			case 'p':
				/*
				 * Set the prompt string.
				 */
				if ((argc <= 0) || (**argv == '-'))
					usage();

				if (prompt)
					free(prompt);

				prompt = strdup(*argv++);
				argc--;

				break;

			case 'q':
				quietFlag = TRUE;
				break;

			case 'a':
				aliasFlag = TRUE;
				break;

			case 'h':
			case '?':
				usage();
				break;

			default:
				fprintf(stderr, "Unknown option -%c\n", cp[-1]);

				return 1;
		}
	}

	/*
	 * No more arguments are allowed.
	 */
	if (argc > 0)
		usage();

	/*
	 * Default our path if it is not set.
	 */
	if (getenv("PATH") == NULL)
		putenv("PATH=/bin:/usr/bin:/sbin:/usr/sbin:/etc");

	/*
	 * If the alias flag is set then define all aliases.
	 */
	if (aliasFlag)
		do_aliasall(0, NULL);

	/*
	 * If we are to execute a single command, then do so and exit.
	 */
	if (singleCommand)
	{
		return command(singleCommand);
	}

	/*
	 * Print a hello message unless we are told to be silent.
	 */
	if (!quietFlag && isatty(STDIN))
	{
		printf("Stand-alone shell (version %s)\n", version);

		if (aliasFlag)
			printf("Built-in commands are aliased to standard commands\n");
	}

	signal(SIGINT, catchInt);
	signal(SIGQUIT, catchQuit);

	/*
	 * Execute the user's alias file if present.
	 */
	cp = getenv("HOME");

	if (cp)
	{
		strcpy(buf, cp);
		strcat(buf, "/");
		strcat(buf, ".aliasrc");

		if ((access(buf, 0) == 0) || (errno != ENOENT))
			readFile(buf);
	}

	/*
	 * Read commands from stdin or from a command file.
	 */
	return readFile(commandFile);

}


/*
 * Read commands from the specified file.
 * A null name pointer indicates to read from stdin.
 */
static int
readFile(const char * name)
{
	FILE *	fp;
	int	cc;
	BOOL	ttyFlag;
	char	buf[CMD_LEN];
	int	r = 0;

	if (sourceCount >= MAX_SOURCE)
	{
		fprintf(stderr, "Too many source files\n");

		return 1;
	}

	fp = stdin;

	if (name)
	{
		fp = fopen(name, "r");

		if (fp == NULL)
		{
			perror(name);

			return 1;
		}
	}

	sourcefiles[sourceCount++] = fp;

	ttyFlag = isatty(fileno(fp));

	while (TRUE)
	{
		if (ttyFlag)
			showPrompt();

		if (intFlag && !ttyFlag && (fp != stdin))
		{
			fclose(fp);
			sourceCount--;

			return 1;
		}
	
		if (fgets(buf, CMD_LEN - 1, fp) == NULL)
		{
			if (ferror(fp) && (errno == EINTR))
			{
				clearerr(fp);

				continue;
			}

			break;
		}

		cc = strlen(buf);

		if (buf[cc - 1] == '\n')
			cc--;

		while ((cc > 0) && isBlank(buf[cc - 1]))
			cc--;

		buf[cc] = '\0';

		r = command(buf);
	}

	if (ferror(fp))
	{
		perror("Reading command line");

		if (fp == stdin)
			exit(1);
	}

	clearerr(fp);

	if (fp != stdin)
		fclose(fp);

	sourceCount--;

	return r;
}


/*
 * Parse and execute one null-terminated command line string.
 * This breaks the command line up into words, checks to see if the
 * command is an alias, and expands wildcards.
 */
static int
command(const char * cmd)
{
	const char *	endCmd;
	const Alias *	alias;
	char		newCommand[CMD_LEN];
	char		cmdName[CMD_LEN];

	/*
	 * Rest the interrupt flag and free any memory chunks that
	 * were allocated by the previous command.
	 */
	intFlag = FALSE;

	freeChunks();

	/*
	 * Skip leading blanks.
	 */
	while (isBlank(*cmd))
		cmd++;

	/*
	 * If the command is empty or is a comment then ignore it.
	 */
	if ((*cmd == '\0') || (*cmd == '#'))
		return 0;

	/*
	 * Look for the end of the command name and then copy the
	 * command name to a buffer so we can null terminate it.
	 */
	endCmd = cmd;

	while (*endCmd && !isBlank(*endCmd))
		endCmd++;

	memcpy(cmdName, cmd, endCmd - cmd);

	cmdName[endCmd - cmd] = '\0';

	/*
	 * Search for the command name in the alias table.
	 * If it is found, then replace the command name with
	 * the alias value, and append the current command
	 * line arguments to that.
	 */
	alias = findAlias(cmdName);

	if (alias)
	{
		strcpy(newCommand, alias->value);
		strcat(newCommand, endCmd);

		cmd = newCommand;
	}

	/*
	 * Expand simple environment variables
	 */
	while (strstr(cmd, "$(")) expandVariable((char *)cmd);

	/*
	 * Now look for the command in the builtin table, and execute
	 * the command if found.
	 */
	if (tryBuiltIn(cmd))
		return 0; /* This is a blatant lie */

	/*
	 * The command is not a built-in, so run the program along
	 * the PATH list.
	 */
	return runCmd(cmd);
}


/*
 * Try to execute a built-in command.
 * Returns TRUE if the command is a built in, whether or not the
 * command succeeds.  Returns FALSE if this is not a built-in command.
 */
static BOOL
tryBuiltIn(const char * cmd)
{
	const char *		endCmd;
	const CommandEntry *	entry;
	int			argc;
	const char **		argv;
	char			cmdName[CMD_LEN];

	/*
	 * Look for the end of the command name and then copy the
	 * command name to a buffer so we can null terminate it.
	 */
	endCmd = cmd;

	while (*endCmd && !isBlank(*endCmd))
		endCmd++;

	memcpy(cmdName, cmd, endCmd - cmd);

	cmdName[endCmd - cmd] = '\0';

	/*
	 * Search the command table looking for the command name.
	 */
	for (entry = commandEntryTable; entry->name != NULL; entry++)
	{
		if (strcmp(entry->name, cmdName) == 0)
			break;
	}

	/*
	 * If the command is not a built-in, return indicating that.
	 */
	if (entry->name == NULL)
		return FALSE;

	/*
	 * The command is a built-in.
	 * Break the command up into arguments and expand wildcards.
	 */
	if (!makeArgs(cmd, &argc, &argv))
		return TRUE;

	/*
	 * Give a usage string if the number of arguments is too large
	 * or too small.
	 */
	if ((argc < entry->minArgs) || (argc > entry->maxArgs))
	{
		fprintf(stderr, "usage: %s %s\n", entry->name, entry->usage);

		return TRUE;
	}

	/*
	 * Call the built-in function with the argument list.
	 */
	entry->func(argc, argv);

	return TRUE;
}


/*
 * Execute the specified command either by forking and executing
 * the program ourself, or else by using the shell.  Returns the
 * exit status, or -1 if the program cannot be executed at all.
 */
static int
runCmd(const char * cmd)
{
	const char *	cp;
	BOOL		magic;
	pid_t		pid;
	int		status;

	/*
	 * Check the command for any magic shell characters
	 * except for quoting.
	 */
	magic = FALSE;

	for (cp = cmd; *cp; cp++)
	{
		if ((*cp >= 'a') && (*cp <= 'z'))
			continue;

		if ((*cp >= 'A') && (*cp <= 'Z'))
			continue;

		if (isDecimal(*cp))
			continue;

		if (isBlank(*cp))
			continue;

		if ((*cp == '.') || (*cp == '/') || (*cp == '-') ||
			(*cp == '+') || (*cp == '=') || (*cp == '_') ||
			(*cp == ':') || (*cp == ',') || (*cp == '\'') ||
			(*cp == '"'))
		{
			continue;
		}

		magic = TRUE;
	}

	/*
	 * If there were any magic characters used then run the
	 * command using the shell.
	 */
	if (magic)
		return trySystem(cmd);

	/*
	 * No magic characters were in the command, so we can do the fork
	 * and exec ourself.
	 */
	pid = fork();

	if (pid < 0)
	{
		perror("fork failed");

		return -1;
	}

	/*
	 * If we are the child process, then go execute the program.
	 */
	if (pid == 0)
		childProcess(cmd);

	/*
	 * We are the parent process.
	 * Wait for the child to complete.
	 */
	status = 0;
	intCrlf = FALSE;

	while (((pid = waitpid(pid, &status, 0)) < 0) && (errno == EINTR))
		;

	intCrlf = TRUE;

	if (pid < 0)
	{
		fprintf(stderr, "Error from waitpid: %s", strerror(errno));

		return -1;
	}

	if (WIFSIGNALED(status))
	{
		fprintf(stderr, "pid %ld: killed by signal %d\n",
			(long) pid, WTERMSIG(status));

		return -1;
	}

	return WEXITSTATUS(status);
}


/*
 * Here as the child process to try to execute the command.
 * This is only called if there are no meta-characters in the command.
 * This procedure never returns.
 */
static void
childProcess(const char * cmd)
{
	const char **	argv;
	int		argc;

	/*
	 * Close any extra file descriptors we have opened.
	 */	
	while (--sourceCount >= 0)
	{
		if (sourcefiles[sourceCount] != stdin)
			fclose(sourcefiles[sourceCount]);
	}

	/*
	 * Break the command line up into individual arguments.
	 * If this fails, then run the shell to execute the command.
	 */
	if (!makeArgs(cmd, &argc, &argv))
	{
		int status = trySystem(cmd);

		if (status == -1)
			exit(99);

		exit(status);
	}

	/*
	 * Try to execute the program directly.
	 */
	execvp(argv[0], (char **) argv);

	/*
	 * The exec failed, so try to run the command using the shell
	 * in case it is a shell script.
	 */
	if (errno == ENOEXEC)
	{
		int status = trySystem(cmd);

		if (status == -1)
			exit(99);

		exit(status);
	}

	/*
	 * There was something else wrong, complain and exit.
	 */
	perror(argv[0]);
	exit(1);
}


int
do_help(int argc, const char ** argv)
{
	const CommandEntry *	entry;
	const char *		str;

	str = NULL;

	if (argc == 2)
		str = argv[1];

	/*
	 * Check for an exact match, in which case describe the program.
	 */
	if (str)
	{
		for (entry = commandEntryTable; entry->name; entry++)
		{
			if (strcmp(str, entry->name) == 0)
			{
				printf("%s\n", entry->description);

				printf("usage: %s %s\n", entry->name,
					entry->usage);

				return 0;
			}
		}
	}

	/*
	 * Print short information about commands which contain the
	 * specified word.
	 */
	for (entry = commandEntryTable; entry->name; entry++)
	{
		if ((str == NULL) || (strstr(entry->name, str) != NULL) ||
			(strstr(entry->usage, str) != NULL))
		{
			printf("%-10s %s\n", entry->name, entry->usage);
		}
	}

	return 0;
}


int
do_alias(int argc, const char ** argv)
{
	const char *	name;
	char *		value;
	Alias *		alias;
	int		count;
	char		buf[CMD_LEN];

	if (argc < 2)
	{
		count = aliasCount;

		for (alias = aliasTable; count-- > 0; alias++)
			printf("%s\t%s\n", alias->name, alias->value);

		return 0;
	}

	name = argv[1];

	if (argc == 2)
	{
		alias = findAlias(name);

		if (alias)
			printf("%s\n", alias->value);
		else
		{
			fprintf(stderr, "Alias \"%s\" is not defined\n", name);

			return 1;
		}

		return 0;	
	}

	if (strcmp(name, "alias") == 0)
	{
		fprintf(stderr, "Cannot alias \"alias\"\n");

		return 1;
	}

	if (!makeString(argc - 2, argv + 2, buf, CMD_LEN))
		return 1;

	value = malloc(strlen(buf) + 1);

	if (value == NULL)
	{
		fprintf(stderr, "No memory for alias value\n");

		return 1;
	}

	strcpy(value, buf);

	alias = findAlias(name);

	if (alias)
	{
		free(alias->value);
		alias->value = value;

		return 0;
	}

	if ((aliasCount % ALIAS_ALLOC) == 0)
	{
		count = aliasCount + ALIAS_ALLOC;

		if (aliasTable)
		{
			alias = (Alias *) realloc(aliasTable,
				sizeof(Alias) * count);
		}
		else
			alias = (Alias *) malloc(sizeof(Alias) * count);

		if (alias == NULL)
		{
			free(value);
			fprintf(stderr, "No memory for alias table\n");

			return 1;
		}

		aliasTable = alias;
	}

	alias = &aliasTable[aliasCount];

	alias->name = malloc(strlen(name) + 1);

	if (alias->name == NULL)
	{
		free(value);
		fprintf(stderr, "No memory for alias name\n");

		return 1;
	}

	strcpy(alias->name, name);
	alias->value = value;
	aliasCount++;

	return 0;
}


/*
 * Build aliases for all of the built-in commands which start with a dash,
 * using the names without the dash.
 */
int
do_aliasall(int argc, const char **argv)
{
	const CommandEntry *	entry;
	const char *		name;
	const char *		newArgv[4];

	for (entry = commandEntryTable; entry->name; entry++)
	{
		name = entry->name;

		if (*name != '-')
			continue;

		newArgv[0] = "alias";
		newArgv[1] = name + 1;
		newArgv[2] = name;
		newArgv[3] = NULL;

		do_alias(3, newArgv);
	}

	return 0;
}


/*
 * Look up an alias name, and return a pointer to it.
 * Returns NULL if the name does not exist.
 */
static Alias *
findAlias(const char * name)
{
	Alias *	alias;
	int	count;

	count = aliasCount;

	for (alias = aliasTable; count-- > 0; alias++)
	{
		if (strcmp(name, alias->name) == 0)
			return alias;
	}

	return NULL;
}


int
do_source(int argc, const char ** argv)
{
	return readFile(argv[1]);
}


int
do_exec(int argc, const char ** argv)
{
	const char *	name;

	name = argv[1];

	while (--sourceCount >= 0)
	{
		if (sourcefiles[sourceCount] != stdin)
			fclose(sourcefiles[sourceCount]);
	}

	argv[argc] = NULL;

	execvp(name, (char **) argv + 1);
	perror(name);

	return 1;
}


int
do_prompt(int argc, const char ** argv)
{
	char *	cp;
	char	buf[CMD_LEN];

	if (!makeString(argc - 1, argv + 1, buf, CMD_LEN))
		return 1;

	cp = malloc(strlen(buf) + 2);

	if (cp == NULL)
	{
		fprintf(stderr, "No memory for prompt\n");

		return 1;
	}

	strcpy(cp, buf);
	strcat(cp, " ");

	if (prompt)
		free(prompt);

	prompt = cp;

	return 0;
}


int
do_unalias(int argc, const char ** argv)
{
	Alias *	alias;

	while (--argc > 0)
	{
		alias = findAlias(*++argv);

		if (alias == NULL)
			continue;

		free(alias->name);
		free(alias->value);
		aliasCount--;
		alias->name = aliasTable[aliasCount].name;
		alias->value = aliasTable[aliasCount].value;	
	}

	return 0;
}


/*
 * Display the prompt string.
 */
static void
showPrompt(void)
{
	const char *	cp;

	cp = "> ";

	if (prompt)
		cp = prompt;

	tryWrite(STDOUT, cp, strlen(cp));
}	


static void
catchInt(int val)
{
	signal(SIGINT, catchInt);

	intFlag = TRUE;

	if (intCrlf)
		tryWrite(STDOUT, "\n", 1);
}


static void
catchQuit(int val)
{
	signal(SIGQUIT, catchQuit);

	intFlag = TRUE;

	if (intCrlf)
		tryWrite(STDOUT, "\n", 1);
}


/*
 * Print the usage information and quit.
 */
static void
usage(void)
{
	fprintf(stderr, "Stand-alone shell (version %s)\n", version);
	fprintf(stderr, "\n");
	fprintf(stderr, "Usage: sash [-a] [-q] [-f fileName] [-c command] [-p prompt] [-i]\n");

	exit(1);
}


/*
 * Expand one environment variable: Syntax $(VAR)
 */
static void
expandVariable(char * cmd)
{
	char	tmp[CMD_LEN];
	char 	*cp;
	char	*ep;

	strcpy(tmp, cmd);
	cp = strstr(tmp, "$(");
	if (cp) {
		*cp++ = '\0';
		strcpy(cmd, tmp);
		ep = ++cp;
		while (*ep && (*ep != ')')) ep++;
		if (*ep == ')') *ep++ = '\0';
		cp = getenv(cp);
		if (cp) strcat(cmd, cp);
		strcat(cmd, ep);
	}
	return;
}

/* END CODE */
