#ifndef pty_c
#define pty_c

// musl

//+depends open
//+def
int posix_openpt(int flags){
		return open("/dev/ptmx", flags);
}

//+depends ioctl
//+def
int unlockpt(int fd){
		int unlock = 0;
		return ioctl(fd, TIOCSPTLCK, &unlock);
}

//+depends snprintf itodec ioctl open sprintf
//+def
int ptsname_r(int fd, char *buf, size_t len){
		int pty, err;
		if (!buf) len = 0;
		if ((err = ioctl( fd, TIOCGPTN, &pty))) return -err;
	//	printf("pts: %d, %d\n",pty,len);
		if (sprintf(buf, "/dev/pts/%d", pty) >= len) return ERANGE;

	//	printf("pts: %s\n",buf);
		return 0;
}

//+depends ptsname_r snprintf itodec ioctl sprintf
//+def
char *ptsname(int fd){
		static char buf[9 + sizeof(int)*3 + 1];
		int err = ptsname_r(fd, buf, sizeof buf);
		if (err) {
#ifdef mini_errno
				errno = err;
#endif
				return 0;
		}
		return buf;
}


//+depends fstat ptsname
//+def
int grantpt(int fd){
	struct stat st;
  if ((fstat(fd, &st))<0) return -1;
  if ((chmod((char*)ptsname(fd), st.st_mode | S_IRUSR | S_IWUSR | S_IWGRP))<0)
    return -1;
  return 0;
}


#endif
