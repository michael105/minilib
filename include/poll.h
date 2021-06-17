
#define POLLIN     0x001
#define POLLPRI    0x002
#define POLLOUT    0x004
#define POLLERR    0x008
#define POLLHUP    0x010
#define POLLNVAL   0x020
#define POLLRDNORM 0x040
#define POLLRDBAND 0x080
#define POLLWRNORM 0x100
#define POLLWRBAND 0x200
#define POLLMSG    0x400

typedef unsigned int nfds_t;

struct pollfd{
		        int fd;
		        short events;
		        short revents;
};

//DEF_syscall(poll,3, struct pollfd *ufds,  unsigned int nfds,  long timeout_msecs)

//+def
static inline int poll(struct pollfd *fds, nfds_t cnt, int timeout){
	int ret;
	__SYSCALL_ASM(ret,__NR_poll) ,"D"(fds), "S"(cnt), "d"(timeout) __callend;
#ifdef mini_errno
	if ( ret<0){
		errno = -ret;
		return(-1);
	}
#endif
	return(ret);
}




