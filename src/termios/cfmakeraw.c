//+depends termio
//+def
void cfmakeraw(struct termios *tp){
	tp->c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
	tp->c_oflag &= ~OPOST;
	tp->c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
	tp->c_cflag &= ~(CSIZE|PARENB);
	tp->c_cflag |= CS8;
	tp->c_cc[VMIN] = 1;
	tp->c_cc[VTIME] = 0;
}

