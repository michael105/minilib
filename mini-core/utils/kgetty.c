/* See LICENSE file for copyright and license details. */
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



#define TEST
//
//#include <sys/ioctl.h>
//#include <sys/stat.h>
//#include <sys/types.h>
//
//#include <fcntl.h>
//#include <limits.h>
//#include <signal.h>
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
//#include <utmp.h>
//#include <errno.h>
//#include <pwd.h>
//

#define mini_start
#define mini_buf 1024
#define mini_exit
#define mini_vhangup
#define mini_open
#define mini_fopen
#define mini_fread
#define mini_fwrite
#define mini_close
#define mini_fflush
#define mini_ioctl
#define mini_printf
#define mini_fprintf
#define mini_printf
#define mini_strncpy
#define mini_strcmp
#define mini_memset
#define mini_sleep
#define mini_ftell
#define mini_fseek
#define mini_fchmod
#define mini_fchown
#define mini_sigemptyset
#define mini_sigaction

#define INCLUDESRC
#include "minilib.h"

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
	if (argc > 0) {
		tty = argv[0];
		if (argc > 1)
			strncpy(term, argv[1], sizeof(term));
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

	printf("exec ksu.\n");

	char *envp[] = { 
			envp[0]="KRB5CCNAME=FILE:/tmp/krb_csc",
			envp[1]=0 
	};

  char *argvp[] = { 
			argvp[0]="ksu", 
			argvp[1]=&logname, 
			argvp[2]="-n", 
			argvp[3]=&logname, 
			argvp[4]="-k", 
			argvp[5]=NULL 
	};

	return execve("/usr/bin/ksu",argvp, envp );
	//return execlp("/usr/bin/ksu", "ksu", &logname, "-n", &logname, "-k", NULL);
	
	//execlp("/usr/bin/id", "id", NULL);
	//return execlp("/usr/bin/ksu", "ksu", &logname, "-c", "FILE:/home/krb5-micha/.krb5/krb5m", NULL);
	//return execlp("/usr/bin/ksu", "ksu", &logname, "-k", "-n", "krb5-micha", "-c", "FILE:/tmp/krb5-micha", NULL);
	//return execlp("/bin/login", "login", "-p", logname, NULL);
}
