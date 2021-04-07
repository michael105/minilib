#ifndef epoll_h
#define epoll_h

// TODO: doesn't ork

typedef struct { unsigned long __bits[128/sizeof(long)]; } sigset_t;

#define EPOLL_CLOEXEC 02000000
#define EPOLL_NONBLOCK 04000

enum EPOLL_EVENTS { __EPOLL_DUMMY };
#define EPOLLIN 0x001
#define EPOLLPRI 0x002
#define EPOLLOUT 0x004
#define EPOLLRDNORM 0x040
#define EPOLLRDBAND 0x080
#define EPOLLWRNORM 0x100
#define EPOLLWRBAND 0x200
#define EPOLLMSG 0x400
#define EPOLLERR 0x008
#define EPOLLHUP 0x010
#define EPOLLRDHUP 0x2000
#define EPOLLONESHOT (1U<<30)
#define EPOLLET (1U<<31)

#define EPOLL_CTL_ADD 1
#define EPOLL_CTL_DEL 2
#define EPOLL_CTL_MOD 3

typedef union epoll_data {
		  void *ptr;
			  int fd;
				int u32;
				long u64;
} epoll_data_t;

struct epoll_event {
		  int events;
			  epoll_data_t data;
} __attribute__ ((__packed__));


static inline int epoll_create(int size)
{
		  return syscall1(SCALL(epoll_create), size);
}

static inline int epoll_ctl(int fd, int op, int fd2, struct epoll_event *ev)
{
		  return syscall4(SCALL(epoll_ctl), fd, op, fd2, (int)ev);
}

static inline int epoll_wait(int fd, struct epoll_event *ev, int cnt, int to)
{
		  return syscall4(SCALL(epoll_wait), fd, (int)ev, cnt, to);
}






#endif
