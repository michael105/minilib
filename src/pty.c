#ifndef pty_c
#define pty_c

// musl

//+depends open
//+def
int posix_openpt(int flags){
		return open("/dev/ptmx", flags);
}

//+def
int grantpt(int fd){
		return 0;
}


//+depends ioctl
//+def
int unlockpt(int fd){
		int unlock = 0;
		return ioctl(fd, TIOCSPTLCK, &unlock);
}

/* /+def
int ptsname_r(int fd, char *buf, size_t len){
		int pty, err;
		if (!buf) len = 0;
		if ((err = __syscall(SYS_ioctl, fd, TIOCGPTN, &pty))) return -err;
		if (snprintf(buf, len, "/dev/pts/%d", pty) >= len) return ERANGE;
		return 0;
}
*/

#endif
