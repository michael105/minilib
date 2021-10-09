//+def
int tcgetpgrp(int fd){
	int pgrp;
	if (ioctl(fd, TIOCGPGRP, &pgrp) < 0)
		return(-1);
	return( pgrp );
}
