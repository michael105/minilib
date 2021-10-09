//+def
int tcsetpgrp(int fd, int pgrp){
	int pgrp_int = pgrp;
	return ioctl(fd, TIOCSPGRP, &pgrp_int);
}
