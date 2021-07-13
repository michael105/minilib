#if 0
mini_start
mini_buf 1024
mini_exit
mini_vhangup
mini_open
mini_fopen
mini_fread
mini_fwrite
mini_close
mini_fflush
mini_ioctl
mini_printf
mini_fprintf
mini_printf
mini_strncpy
mini_strcmp
mini_memset
mini_sleep
mini_ftell
mini_fseek
mini_fchmod
mini_fchown
mini_sigemptyset
mini_sigaction
mini_isatty
mini_vexec

COMPILE setsid setgid setuid execve dup2

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif



/* See LICENSE file for copyright and license details. */
// kgetty, for kerberos. Use this for local logins only !
// The ticket cache is kept after the login,
// therefore, after the first login, it's possible
// to login at other virtual terminals without entering the password again.
//
// most of this is borrowed from the suckless project. (getty,and login)
// Added the code to get kerberos working for authentication
//
// misc

// dropping privilieges to "nobody".
// this user should be present on every unix system,
// with the uid/gid defined below.
// if not dropping privileges, 
// running ksu as root would su to the given user,
// with a wrong or missing password as well.
// On the other hand, setting the tty up could
// need root rights.
// Therefore the code for dropping the user rights.

#define uid_nobody 65534
#define gid_nobody 65534



//#define TEST

static char *tty = "/dev/tty1";
static char *defaultterm = "linux";




static void usage(void){
	printf("usage: kgetty [tty] [term] [cmd] [args...]\n");
	exit(0);
}

void errprintf(const char *msg){
		fprintf(stderr,"Error.\n");
		fprintf(stderr,msg);

		exit(1);
}

void errprintf2(const char *msg1,const char *msg2){
		fprintf(stderr,"Error.\n");
		fprintf(stderr,msg1);
		fprintf(stderr,msg2);

		exit(1);
}


void warnprintf2(const char *msg1,const char *msg2){
		fprintf(stderr,msg1);
		fprintf(stderr,msg2);
		fprintf(stderr,"\n");

		exit(1);
}



int main(int argc, char *argv[]){

	//struct passwd *pw;
	char *user;
	char term[128], logname[LOGIN_NAME_MAX], c;
	char hostname[HOST_NAME_MAX + 1];
//	struct utmp usr;
	struct sigaction sa;
	FILE *fp;
	int fd;
	unsigned int i = 0;
	ssize_t n;
	long pos;
	uid_t uid;
	gid_t gid;


	strncpy(term, defaultterm, sizeof(term));
	if (argc > 1) {
		tty = argv[1];
		if (argc > 2)
			strncpy(term, argv[2], sizeof(term));
	}

	sa.sa_handler = SIG_IGN;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGHUP, &sa, NULL);

//	setenv("TERM", term, 1);

	setsid();
#ifndef TEST

	fd = open(tty, O_RDWR);
	if (fd < 0)
		errprintf2("open %s:", tty);
	if (isatty(fd) == 0)
		errprintf2("%s is not a tty\n", tty);

	/* steal the controlling terminal if necessary */
/*	if (ioctl(fd, TIOCSCTTY, (void *)1) != 0)
		warnprintf2("TIOCSCTTY: could not set controlling tty\n");
	*/
	vhangup();
	close(fd);

	fd = open(tty, O_RDWR);
	if (fd < 0)
		errprintf2("open %s:", tty);
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);
	if (fchown(fd, 0, 0) < 0)
		warnprintf2("fchown ", tty);
	if (fchmod(fd, 0600) < 0)
		warnprintf2("fchmod ", tty);
	if (fd > 2)
		close(fd);

#endif
	sa.sa_handler = SIG_DFL;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGHUP, &sa, NULL);

	/* Clear all utmp entries for this tty */
/*	fp = fopen(UTMP_PATH, "r+");
	if (fp) {
		do {
			pos = ftell(fp);
			if (fread(&usr, sizeof(usr), 1, fp) != 1)
				break;
			if (usr.ut_line[0] == '\0')
				continue;
			if (strcmp(usr.ut_line, tty) != 0)
				continue;
			memset(&usr, 0, sizeof(usr));
			fseek(fp, pos, SEEK_SET);
			if (fwrite(&usr, sizeof(usr), 1, fp) != 1)
				break;
		} while (1);
		if (ferror(fp))
			warnprintf2("I/O error: ", UTMP_PATH);
		fclose(fp);
	} */

	//if (argc > 2)
	//	return execvp(argv[2], argv + 2);
//	if (gethostname(hostname, sizeof(hostname)) == 0)
//		printf("Kerberos@%s - login: ", hostname);
//	else
	printf("Kerberos - login: ");
	fflush(stdout);

	/* Flush pending input */
	ioctl(0, TCFLSH, (void *)0);
	memset(logname, 0, sizeof(logname));
	while (1) {
		n = read(0, &c, 1);
		if (n < 0)
			errprintf("read:");
		if (n == 0)
			return 1;
		if (i >= sizeof(logname) - 1)
			errprintf("login name too long\n");
		if (c == '\n' || c == '\r')
			break;
		logname[i++] = c;
	}
	if (logname[0] == '-')
		errprintf("login name cannot start with '-'\n");
	if (logname[0] == '\0')
		return 1;

	printf("\n");

// get gid and uid.
	//pw = getpwnam(&logname);

//	if (!pw) { //user doesn't exist

			/*
		if (errno)
			eprintf("getpwnam %s:", &logname);
		else
			eprintf("who are you?\n");*/

		// better don't reveal, this user doesn't seem to exist. misc

			// hopefully this user doesn't exist.
			// when - well, there still is the password left to guess.
	// need to emulate kerberos here, somehow ?
//			sleep(1);
//			return(1);
//	}

	//pw = getpwnam("krb5-micha");
//	pw = getpwnam("nobody");

//	if (!pw) {
//			errprintf("Couldn't get uid of user nobody\n");
//	}

//	uid = pw->pw_uid;
//	gid = pw->pw_gid;

//	if (initgroups(&logname, gid) < 0)
//		errprintf("initgroups:");
	if (setgid(gid_nobody) < 0)
		errprintf("setgid:");
	if (setuid(uid_nobody) < 0)
		errprintf("setuid:");

	//printf("exec ksu.\n");

	char *envp[] = { 
			envp[0]="KRB5CCNAME=FILE:/tmp/krb_csc",
			envp[1]=0 
	};

  char *argvpc[] = { 
			argvpc[0]="init", 
			argvpc[1]=&logname, 
			argvpc[2]="-c",
			argvpc[3]="FILE:/tmp/krb5_csc",
			0
	};


  char *argvp[] = { 
			argvp[0]="klist", 
			argvp[1]="/tmp/krb5_csc", 
			argvp[2]=NULL 
	};

		int r = vexec("/usr/bin/klist",argvp,envp);
		i = 0;

		while ( r ){ // not authorized yet
				if ( i++ > 2 )
						exit(1);
				r = vexec("/usr/bin/kinit",argvpc,envp);
		}


	return execve("/usr/bin/ksu",argvpc, envp );
	//return execlp("/usr/bin/ksu", "ksu", &logname, "-n", &logname, "-k", NULL);
	
	//execlp("/usr/bin/id", "id", NULL);
	//return execlp("/usr/bin/ksu", "ksu", &logname, "-c", "FILE:/home/krb5-micha/.krb5/krb5m", NULL);
	//return execlp("/usr/bin/ksu", "ksu", &logname, "-k", "-n", "krb5-micha", "-c", "FILE:/tmp/krb5-micha", NULL);
	//return execlp("/bin/login", "login", "-p", logname, NULL);
}
