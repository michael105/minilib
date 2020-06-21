#if 0
mini_start
mini_writes
mini_fwrites
mini_mount
mini_printfs
mini_perror
mini_errno

mini_printf
mini_printfs
mini_strlen
mini_itodec
mini_buf 256

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

// source: sash 
/*
 * Copyright (c) 2014 by David I. Bell
 * Permission is granted to use, distribute, or modify this source,
 * provided that this copyright notice remains intact.
 *
 * Most simple built-in commands are here.
 */

int main(int argc, const char ** argv)
{
	const char *	str;
	const char *	type;
	int		flags;

	argc--;
	argv++;

	type = "reiserfs";

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
					fwrites(STDERR_FILENO, "Missing file system type\n");

					return 1;
				}

				type = *argv++;
				argc--;
				break;

#if	1
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
				fwrites(STDERR_FILENO, "Unknown option\n");

				return 1;
		}
	}

	if (argc != 2)
	{
		fwrites(STDERR_FILENO, "Wrong number of arguments for mount\n");

		return 1;
	}

#if	1

		printf("mount -t %s %s %s  %l\n", type, argv[0],argv[1],flags);
		exit(0);
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
	return 0;
}


