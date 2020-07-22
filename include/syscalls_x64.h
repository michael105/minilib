#ifndef syscalls_x64_h

#define syscalls_x64_h


SYSDEF_syscall(_read,3, unsigned int fd,  char *buf,  size_t count)

SYSDEF_syscall(_write,3, unsigned int fd,  const char *buf,  size_t count)

SYSDEF_syscall(_open,3, const char *filename,  int flags,  int mode)

SYSDEF_syscall(_close,1, unsigned int fd)

SYSDEF_syscall(_stat,2, const char *filename,  struct stat *statbuf)

SYSDEF_syscall(_fstat,2, unsigned int fd,  struct stat *statbuf)

SYSDEF_syscall(_lstat,2, const char *filename,  struct stat *statbuf)

SYSDEF_syscall(_poll,3, struct poll_fd *ufds,  unsigned int nfds,  long timeout_msecs)

SYSDEF_syscall(_lseek,3, unsigned int fd,  off_t offset,  unsigned int origin)

SYSDEF_syscall(_mmap,6, unsigned long addr,  unsigned long len,  unsigned long prot,  unsigned long flags,  unsigned long fd,  unsigned long off)

SYSDEF_syscall(_mprotect,3, unsigned long start,  size_t len,  unsigned long prot)

SYSDEF_syscall(_munmap,2, unsigned long addr,  size_t len)

//SYSDEF_syscall(_brk,1, unsigned long brk)

SYSDEF_syscall(_rt_sigaction,4, int sig,  const struct sigaction *act,  struct sigaction *oact,  size_t sigsetsize)

SYSDEF_syscall(_rt_sigprocmask,4, int how,  sigset_t *nset,  sigset_t *oset,  size_t sigsetsize)

SYSDEF_syscall(_rt_sigreturn,1, unsigned long __unused)

SYSDEF_syscall(_ioctl,3, unsigned int fd,  unsigned int cmd,  unsigned long arg)

SYSDEF_syscall(_pread64,4, unsigned long fd,  char *buf,  size_t count,  loff_t pos)

SYSDEF_syscall(_pwrite64,4, unsigned int fd,  const char *buf,  size_t count,  loff_t pos)

SYSDEF_syscall(_readv,3, unsigned long fd,  const struct iovec *vec,  unsigned long vlen)

SYSDEF_syscall(_writev,3, unsigned long fd,  const struct iovec *vec,  unsigned long vlen)

SYSDEF_syscall(_access,2, const char *filename,  int mode)

SYSDEF_syscall(_pipe,1, int *filedes)

SYSDEF_syscall(_select,5, int n,  fd_set *inp,  fd_set *outp,  fd_set *exp,  struct timeval *tvp)

SYSDEF_syscall(_sched_yield,0)

SYSDEF_syscall(_mremap,5, unsigned long addr,  unsigned long old_len,  unsigned long new_len,  unsigned long flags,  unsigned long new_addr)

SYSDEF_syscall(_msync,3, unsigned long start,  size_t len,  int flags)

SYSDEF_syscall(_mincore,3, unsigned long start,  size_t len,  unsigned char *vec)

SYSDEF_syscall(_madvise,3, unsigned long start,  size_t len_in,  int behavior)

SYSDEF_syscall(_shmget,3, key_t key,  size_t size,  int shmflg)

SYSDEF_syscall(_shmat,3, int shmid,  char *shmaddr,  int shmflg)

SYSDEF_syscall(_shmctl,3, int shmid,  int cmd,  struct shmid_ds *buf)

SYSDEF_syscall(_dup,1, unsigned int fildes)

SYSDEF_syscall(_dup2,2, unsigned int oldfd,  unsigned int newfd)

SYSDEF_syscall(_pause,0)

SYSDEF_syscall(_nanosleep,2, struct timespec *rqtp,  struct timespec *rmtp)

SYSDEF_syscall(_getitimer,2, int which,  struct itimerval *value)

SYSDEF_syscall(_alarm,1, unsigned int seconds)

SYSDEF_syscall(_setitimer,3, int which,  struct itimerval *value,  struct itimerval *ovalue)

SYSDEF_syscall(_getpid,0)

SYSDEF_syscall(_sendfile,4, int out_fd,  int in_fd,  off_t *offset,  size_t count)

SYSDEF_syscall(_socket,3, int family,  int type,  int protocol)

SYSDEF_syscall(_connect,3, int fd,  struct sockaddr *uservaddr,  int addrlen)

SYSDEF_syscall(_accept,3, int fd,  struct sockaddr *upeersockaddr,  int *upeeraddrlen)

SYSDEF_syscall(_sendto,6, int fd,  void *buff,  size_t len,  unsigned flags,  struct sockaddr *addr,  int addr_len)

SYSDEF_syscall(_recvfrom,6, int fd,  void *ubuf,  size_t size,  unsigned flags,  struct sockaddr *addr,  int *addr_len)

SYSDEF_syscall(_sendmsg,3, int fd,  struct msghdr *msg,  unsigned flags)

SYSDEF_syscall(_recvmsg,3, int fd,  struct msghdr *msg,  unsigned int flags)

SYSDEF_syscall(_shutdown,2, int fd,  int how)

SYSDEF_syscall(_bind,3, int fd,  struct sockaddr *umyaddr,  int addrlen)

SYSDEF_syscall(_listen,2, int fd,  int backlog)

SYSDEF_syscall(_getsockname,3, int fd,  struct sockaddr *usockaddr,  int *usockaddr_len)

SYSDEF_syscall(_getpeername,3, int fd,  struct sockaddr *usockaddr,  int *usockaddr_len)

SYSDEF_syscall(_socketpair,4, int family,  int type,  int protocol,  int *usockvec)

SYSDEF_syscall(_setsockopt,5, int fd,  int level,  int optname,  char *optval,  int optlen)

SYSDEF_syscall(_getsockopt,5, int fd,  int level,  int optname,  char *optval,  int *optlen)

SYSDEF_syscall(_clone,4, unsigned long clone_flags,  unsigned long newsp,  void *parent_tid,  void *child_tid)

SYSDEF_syscall(_fork,0)

SYSDEF_syscall(_vfork,0)

SYSDEF_syscall(_execve,3, const char *filename,  const char *const argv[],  const char *const envp[])

SYSDEF_syscall(_exit,1, int error_code)

SYSDEF_syscall(_wait4,4, pid_t upid,  int *stat_addr,  int options,  struct rusage *ru)

SYSDEF_syscall(_kill,2, pid_t pid,  int sig)

SYSDEF_syscall(_uname,1, struct old_utsname *name)

SYSDEF_syscall(_semget,3, key_t key,  int nsems,  int semflg)

SYSDEF_syscall(_semop,3, int semid,  struct sembuf *tsops,  unsigned nsops)

SYSDEF_syscall(_semctl,4, int semid,  int semnum,  int cmd,  semun_u arg)

SYSDEF_syscall(_shmdt,1, char *shmaddr)

SYSDEF_syscall(_msgget,2, key_t key,  int msgflg)

SYSDEF_syscall(_msgsnd,4, int msqid,  struct msgbuf *msgp,  size_t msgsz,  int msgflg)

SYSDEF_syscall(_msgrcv,5, int msqid,  struct msgbuf *msgp,  size_t msgsz,  long msgtyp,  int msgflg)

SYSDEF_syscall(_msgctl,3, int msqid,  int cmd,  struct msqid_ds *buf)

SYSDEF_syscall(_fcntl,3, unsigned int fd,  unsigned int cmd,  unsigned long arg)

SYSDEF_syscall(_flock,2, unsigned int fd,  unsigned int cmd)

SYSDEF_syscall(_fsync,1, unsigned int fd)

SYSDEF_syscall(_fdatasync,1, unsigned int fd)

SYSDEF_syscall(_truncate,2, const char *path,  long length)

SYSDEF_syscall(_ftruncate,2, unsigned int fd,  unsigned long length)

SYSDEF_syscall(_getdents,3, unsigned int fd,  struct linux_dirent *dirent,  unsigned int count)

SYSDEF_syscall(_getcwd,2, char *buf,  unsigned long size)

SYSDEF_syscall(_chdir,1, const char *filename)

SYSDEF_syscall(_fchdir,1, unsigned int fd)

SYSDEF_syscall(_rename,2, const char *oldname,  const char *newname)

SYSDEF_syscall(_mkdir,2, const char *pathname,  int mode)

SYSDEF_syscall(_rmdir,1, const char *pathname)

SYSDEF_syscall(_creat,2, const char *pathname,  int mode)

SYSDEF_syscall(_link,2, const char *oldname,  const char *newname)

SYSDEF_syscall(_unlink,1, const char *pathname)

SYSDEF_syscall(_symlink,2, const char *oldname,  const char *newname)

SYSDEF_syscall(_readlink,3, const char *path,  char *buf,  int bufsiz)

SYSDEF_syscall(_chmod,2, const char *filename,  mode_t mode)

SYSDEF_syscall(_fchmod,2, unsigned int fd,  mode_t mode)

SYSDEF_syscall(_chown,3, const char *filename,  uid_t user,  gid_t group)

SYSDEF_syscall(_fchown,3, unsigned int fd,  uid_t user,  gid_t group)

SYSDEF_syscall(_lchown,3, const char *filename,  uid_t user,  gid_t group)

SYSDEF_syscall(_umask,1, int mask)

SYSDEF_syscall(_gettimeofday,2, struct timeval *tv,  struct timezone *tz)

SYSDEF_syscall(_getrlimit,2, unsigned int resource,  struct rlimit *rlim)

SYSDEF_syscall(_getrusage,2, int who,  struct rusage *ru)

SYSDEF_syscall(_sysinfo,1, struct sysinfo *info)

SYSDEF_syscall(_times,1, struct sysinfo *info)

SYSDEF_syscall(_ptrace,4, long request,  long pid,  unsigned long addr,  unsigned long data)

SYSDEF_syscall(_getuid,0)

SYSDEF_syscall(_syslog,3, int type,  char *buf,  int len)

SYSDEF_syscall(_getgid,0)

SYSDEF_syscall(_setuid,1, uid_t uid)

SYSDEF_syscall(_setgid,1, gid_t gid)

SYSDEF_syscall(_geteuid,0)

SYSDEF_syscall(_getegid,0)

SYSDEF_syscall(_setpgid,2, pid_t pid,  pid_t pgid)

SYSDEF_syscall(_getppid,0)

SYSDEF_syscall(_getpgrp,0)

SYSDEF_syscall(_setsid,0)

SYSDEF_syscall(_setreuid,2, uid_t ruid,  uid_t euid)

SYSDEF_syscall(_setregid,2, gid_t rgid,  gid_t egid)

SYSDEF_syscall(_getgroups,2, int gidsetsize,  gid_t *grouplist)

SYSDEF_syscall(_setgroups,2, int gidsetsize,  gid_t *grouplist)

SYSDEF_syscall(_setresuid,3, uid_t *ruid,  uid_t *euid,  uid_t *suid)

SYSDEF_syscall(_getresuid,3, uid_t *ruid,  uid_t *euid,  uid_t *suid)

SYSDEF_syscall(_setresgid,3, gid_t rgid,  gid_t egid,  gid_t sgid)

SYSDEF_syscall(_getresgid,3, gid_t *rgid,  gid_t *egid,  gid_t *sgid)

SYSDEF_syscall(_getpgid,1, pid_t pid)

SYSDEF_syscall(_setfsuid,1, uid_t uid)

SYSDEF_syscall(_setfsgid,1, gid_t gid)

SYSDEF_syscall(_getsid,1, pid_t pid)

SYSDEF_syscall(_capget,2, cap_user_header_t header,  cap_user_data_t dataptr)

SYSDEF_syscall(_capset,2, cap_user_header_t header,  const cap_user_data_t data)

SYSDEF_syscall(_rt_sigpending,2, sigset_t *set,  size_t sigsetsize)

SYSDEF_syscall(_rt_sigtimedwait,4, const sigset_t *uthese,  siginfo_t *uinfo,  const struct timespec *uts,  size_t sigsetsize)

SYSDEF_syscall(_rt_sigqueueinfo,3, pid_t pid,  int sig,  siginfo_t *uinfo)

SYSDEF_syscall(_rt_sigsuspend,2, sigset_t *unewset,  size_t sigsetsize)

SYSDEF_syscall(_sigaltstack,2, const stack_t *uss,  stack_t *uoss)

SYSDEF_syscall(_utime,2, char *filename,  struct utimbuf *times)

SYSDEF_syscall(_mknod,3, const char *filename,  umode_t mode,  unsigned dev)

SYSDEF_syscall(_personality,1, unsigned int personality)

SYSDEF_syscall(_ustat,2, unsigned dev,  struct ustat *ubuf)

SYSDEF_syscall(_statfs,2, const char *pathname,  struct statfs *buf)

SYSDEF_syscall(_fstatfs,2, unsigned int fd,  struct statfs *buf)

SYSDEF_syscall(_sysfs,3, int option,  unsigned long arg1,  unsigned long arg2)

SYSDEF_syscall(_getpriority,2, int which,  int who)

SYSDEF_syscall(_setpriority,3, int which,  int who,  int niceval)

SYSDEF_syscall(_sched_setparam,2, pid_t pid,  struct sched_param *param)

SYSDEF_syscall(_sched_getparam,2, pid_t pid,  struct sched_param *param)

SYSDEF_syscall(_sched_setscheduler,3, pid_t pid,  int policy,  struct sched_param *param)

SYSDEF_syscall(_sched_getscheduler,1, pid_t pid)

SYSDEF_syscall(_sched_get_priority_max,1, int policy)

SYSDEF_syscall(_sched_get_priority_min,1, int policy)

SYSDEF_syscall(_sched_rr_get_interval,2, pid_t pid,  struct timespec *interval)

SYSDEF_syscall(_mlock,2, unsigned long start,  size_t len)

SYSDEF_syscall(_munlock,2, unsigned long start,  size_t len)

SYSDEF_syscall(_mlockall,1, int flags)

SYSDEF_syscall(_munlockall,0)

SYSDEF_syscall(_vhangup,0)

SYSDEF_syscall(_modify_ldt,3, int func,  void *ptr,  unsigned long bytecount)

SYSDEF_syscall(_pivot_root,2, const char *new_root,  const char *put_old)

SYSDEF_syscall(__sysctl,1, struct __sysctl_args *args)

SYSDEF_syscall(_prctl,5, int option,  unsigned long arg2,  unsigned long arg3,  unsigned long arg4,  unsigned long arg5)

SYSDEF_syscall(_arch_prctl,3, struct task_struct *task,  int code,  unsigned long *addr)

SYSDEF_syscall(_adjtimex,1, struct timex *txc_p)

SYSDEF_syscall(_setrlimit,2, unsigned int resource,  struct rlimit *rlim)

SYSDEF_syscall(_chroot,1, const char *filename)

SYSDEF_syscall(_sync,0)

SYSDEF_syscall(_acct,1, const char *name)

SYSDEF_syscall(_settimeofday,2, struct timeval *tv,  struct timezone *tz)

SYSDEF_syscall(_mount,5, char *dev_name,  char *dir_name,  char *type,  unsigned long flags,  void *data)

SYSDEF_syscall(_umount2,2, const char *target,  int flags)

SYSDEF_syscall(_swapon,2, const char *specialfile,  int swap_flags)

SYSDEF_syscall(_swapoff,1, const char *specialfile)

SYSDEF_syscall(_reboot,4, int magic1,  int magic2,  unsigned int cmd,  void *arg)

SYSDEF_syscall(_sethostname,2, char *name,  int len)

SYSDEF_syscall(_setdomainname,2, char *name,  int len)

SYSDEF_syscall(_iopl,2, unsigned int level,  struct pt_regs *regs)

SYSDEF_syscall(_ioperm,3, unsigned long from,  unsigned long num,  int turn_on)

SYSDEF_syscall(_init_module,3, void *umod,  unsigned long len,  const char *uargs)

SYSDEF_syscall(_delete_module,2, const char *name_user,  unsigned int flags)

SYSDEF_syscall(_quotactl,4, unsigned int cmd,  const char *special,  qid_t id,  void *addr)

SYSDEF_syscall(_gettid,0)

SYSDEF_syscall(_readahead,3, int fd,  loff_t offset,  size_t count)

SYSDEF_syscall(_setxattr,5, const char *pathname,  const char *name,  const void *value, size_t size,  int flags)

SYSDEF_syscall(_lsetxattr,5, const char *pathname,  const char *name,  const void *value, size_t size,  int flags)

SYSDEF_syscall(_fsetxattr,5, int fd,  const char *name,  const void *value,  size_t size, int flags)

SYSDEF_syscall(_getxattr,4, const char *pathname,  const char *name,  void *value,  size_t size)

SYSDEF_syscall(_lgetxattr,4, const char *pathname,  const char *name,  void *value,  size_t size)

SYSDEF_syscall(_fgetxattr,4, int fd,  const char *name,  void *value,  size_t size)

SYSDEF_syscall(_listxattr,3, const char *pathname,  char *list,  size_t size)

SYSDEF_syscall(_llistxattr,3, const char *pathname,  char *list,  size_t size)

SYSDEF_syscall(_flistxattr,3, int fd,  char *list,  size_t size)

SYSDEF_syscall(_removexattr,2, const char *pathname,  const char *name)

SYSDEF_syscall(_lremovexattr,2, const char *pathname,  const char *name)

SYSDEF_syscall(_fremovexattr,2, int fd,  const char *name)

SYSDEF_syscall(_tkill,2, pid_t pid,  int sig)

SYSDEF_syscall(_time,1, time_t *tloc)

SYSDEF_syscall(_futex,6, u32 *uaddr,  int op,  u32 val,  struct timespec *utime,  u32 *uaddr2,  u32 val3)

SYSDEF_syscall(_sched_setaffinity,3, pid_t pid,  unsigned int len,  unsigned long *user_mask_ptr)

SYSDEF_syscall(_sched_getaffinity,3, pid_t pid,  unsigned int len,  unsigned long *user_mask_ptr)

SYSDEF_syscall(_io_setup,2, unsigned nr_events,  aio_context_t *ctxp)

SYSDEF_syscall(_io_destroy,1, aio_context_t ctx)

SYSDEF_syscall(_io_getevents,4, aio_context_t ctx_id,  long min_nr,  long nr,  struct io_event *events)

SYSDEF_syscall(_io_submit,3, aio_context_t ctx_id,  long nr,  struct iocb **iocbpp)

SYSDEF_syscall(_io_cancel,3, aio_context_t ctx_id,  struct iocb *iocb,  struct io_event *result)

SYSDEF_syscall(_lookup_dcookie,3, u64 cookie64,  long buf,  long len)

SYSDEF_syscall(_epoll_create,1, int size)

SYSDEF_syscall(_remap_file_pages,5, unsigned long start,  unsigned long size,  unsigned long prot,  unsigned long pgoff,  unsigned long flags)

SYSDEF_syscall(_getdents64,3, unsigned int fd,  struct linux_dirent64 *dirent,  unsigned int count)

SYSDEF_syscall(_set_tid_address,1, int *tidptr)

SYSDEF_syscall(_restart_syscall,0)

SYSDEF_syscall(_semtimedop,4, int semid,  struct sembuf *tsops,  unsigned nsops,  const struct timespec *timeout)

SYSDEF_syscall(_fadvise64,4, int fd,  loff_t offset,  size_t len,  int advice)

SYSDEF_syscall(_timer_create,3, const clockid_t which_clock,  struct sigevent *timer_event_spec,  timer_t *created_timer_id)

SYSDEF_syscall(_timer_settime,4, timer_t timer_id,  int flags,  const struct itimerspec *new_setting,  struct itimerspec *old_setting)

SYSDEF_syscall(_timer_gettime,2, timer_t timer_id,  struct itimerspec *setting)

SYSDEF_syscall(_timer_getoverrun,1, timer_t timer_id)

SYSDEF_syscall(_timer_delete,1, timer_t timer_id)

SYSDEF_syscall(_clock_settime,2, const clockid_t which_clock,  const struct timespec *tp)

SYSDEF_syscall(_clock_gettime,2, const clockid_t which_clock,  struct timespec *tp)

SYSDEF_syscall(_clock_getres,2, const clockid_t which_clock,  struct timespec *tp)

SYSDEF_syscall(_clock_nanosleep,4, const clockid_t which_clock,  int flags,  const struct timespec *rqtp,  struct timespec *rmtp)

SYSDEF_syscall(_exit_group,1, int error_code)

SYSDEF_syscall(_epoll_wait,4, int epfd,  struct epoll_event *events,  int maxevents,  int timeout)

SYSDEF_syscall(_epoll_ctl,4, int epfd,  int op,  int fd,  struct epoll_event *event)

SYSDEF_syscall(_tgkill,3, pid_t tgid,  pid_t pid,  int sig)

SYSDEF_syscall(_utimes,2, char *filename,  struct timeval *utimes)

SYSDEF_syscall(_mbind,6, unsigned long start,  unsigned long len,  unsigned long mode,  unsigned long *nmask,  unsigned long maxnode,  unsigned flags)

SYSDEF_syscall(_set_mempolicy,3, int mode,  unsigned long *nmask,  unsigned long maxnode)

SYSDEF_syscall(_get_mempolicy,5, int *policy,  unsigned long *nmask,  unsigned long maxnode,  unsigned long addr,  unsigned long flags)

SYSDEF_syscall(_mq_open,4, const char *u_name,  int oflag,  mode_t mode,  struct mq_attr *u_attr)

SYSDEF_syscall(_mq_unlink,1, const char *u_name)

SYSDEF_syscall(_mq_timedsend,5, mqd_t mqdes,  const char *u_msg_ptr,  size_t msg_len,  unsigned int msg_prio,  const struct timespec *u_abs_timeout)

SYSDEF_syscall(_mq_timedreceive,5, mqd_t mqdes,  char *u_msg_ptr,  size_t msg_len,  unsigned int *u_msg_prio,  const struct timespec *u_abs_timeout)

SYSDEF_syscall(_mq_notify,2, mqd_t mqdes,  const struct sigevent *u_notification)

SYSDEF_syscall(_mq_getsetattr,3, mqd_t mqdes,  const struct mq_attr *u_mqstat,  struct mq_attr *u_omqstat)

SYSDEF_syscall(_kexec_load,4, unsigned long entry,  unsigned long nr_segments,  struct kexec_segment *segments,  unsigned long flags)

SYSDEF_syscall(_waitid,5, int which,  pid_t upid,  struct siginfo *infop,  int options,  struct rusage *ru)

SYSDEF_syscall(_add_key,4, const char *_type,  const char *_description,  const void *_payload,  size_t plen)

SYSDEF_syscall(_request_key,4, const char *_type,  const char *_description,  const char *_callout_info,  key_serial_t destringid)

SYSDEF_syscall(_keyctl,5, int option,  unsigned long arg2,  unsigned long arg3,  unsigned long arg4,  unsigned long arg5)

SYSDEF_syscall(_ioprio_set,3, int which,  int who,  int ioprio)

SYSDEF_syscall(_ioprio_get,2, int which,  int who)

SYSDEF_syscall(_inotify_init,0)

SYSDEF_syscall(_inotify_add_watch,3, int fd,  const char *pathname,  u32 mask)

SYSDEF_syscall(_inotify_rm_watch,2, int fd,  __s32 wd)

SYSDEF_syscall(_migrate_pages,4, pid_t pid,  unsigned long maxnode,  const unsigned long *old_nodes,  const unsigned long *new_nodes)

SYSDEF_syscall(_openat,4, int dfd,  const char *filename,  int flags,  int mode)

SYSDEF_syscall(_mkdirat,3, int dfd,  const char *pathname,  int mode)

SYSDEF_syscall(_mknodat,4, int dfd,  const char *filename,  int mode,  unsigned dev)

SYSDEF_syscall(_fchownat,5, int dfd,  const char *filename,  uid_t user,  gid_t group,  int flag)

SYSDEF_syscall(_futimesat,3, int dfd,  const char *filename,  struct timeval *utimes)

SYSDEF_syscall(_newfstatat,4, int dfd,  const char *filename,  struct stat *statbuf,  int flag)

SYSDEF_syscall(_unlinkat,3, int dfd,  const char *pathname,  int flag)

SYSDEF_syscall(_renameat,4, int oldfd,  const char *oldname,  int newfd,  const char *newname)

SYSDEF_syscall(_linkat,5, int oldfd,  const char *oldname,  int newfd,  const char *newname,  int flags)

SYSDEF_syscall(_symlinkat,3, const char *oldname,  int newfd,  const char *newname)

SYSDEF_syscall(_readlinkat,4, int dfd,  const char *pathname,  char *buf,  int bufsiz)

SYSDEF_syscall(_fchmodat,3, int dfd,  const char *filename,  mode_t mode)

SYSDEF_syscall(_faccessat,3, int dfd,  const char *filename,  int mode)

SYSDEF_syscall(_pselect6,6, int n,  fd_set *inp,  fd_set *outp,  fd_set *exp,  struct timespec *tsp,  void *sig)

SYSDEF_syscall(_ppoll,5, struct pollfd *ufds,  unsigned int nfds,  struct timespec *tsp,  const sigset_t *sigmask,  size_t sigsetsize)

SYSDEF_syscall(_unshare,1, unsigned long unshare_flags)

SYSDEF_syscall(_set_robust_list,2, struct robust_list_head *head,  size_t len)

SYSDEF_syscall(_get_robust_list,3, int pid,  struct robust_list_head **head_ptr,  size_t *len_ptr)

SYSDEF_syscall(_splice,6, int fd_in,  loff_t *off_in,  int fd_out,  loff_t *off_out, size_t len,  unsigned int flags)

SYSDEF_syscall(_tee,4, int fdin,  int fdout,  size_t len,  unsigned int flags)

SYSDEF_syscall(_sync_file_range,4, long fd,  loff_t offset,  loff_t bytes,  long flags)

SYSDEF_syscall(_vmsplice,4, int fd,  const struct iovec *iov,  unsigned long nr_segs, unsigned int flags)

SYSDEF_syscall(_move_pages,6, pid_t pid,  unsigned long nr_pages,  const void *pages[], const int *nodes,  int *status,  int flags)

SYSDEF_syscall(_utimensat,4, int dfd,  const char *filename,  struct timespec *utimes, int flags)

SYSDEF_syscall(_epoll_pwait,6, int epfd,  struct epoll_event *events,  int maxevents,  int timeout,  const sigset_t *sigmask,  size_t sigsetsize)

SYSDEF_syscall(_signalfd,3, int ufd,  sigset_t *user_mask,  size_t sizemask)

SYSDEF_syscall(_timerfd_create,2, int clockid,  int flags)

SYSDEF_syscall(_eventfd,1, unsigned int count)

SYSDEF_syscall(_fallocate,4, long fd,  long mode,  loff_t offset,  loff_t len)

SYSDEF_syscall(_timerfd_settime,4, int ufd,  int flags,  const struct itimerspec *utmr,  struct itimerspec *otmr)

SYSDEF_syscall(_timerfd_gettime,2, int ufd,  struct itimerspec *otmr)

SYSDEF_syscall(_accept4,4, int fd,  struct sockaddr *upeer_sockaddr,  int *upeer_addrlen,  int flags)

SYSDEF_syscall(_signalfd4,4, int ufd,  sigset_t *user_mask,  size_t sizemask,  int flags)

SYSDEF_syscall(_eventfd2,2, unsigned int count,  int flags)

SYSDEF_syscall(_epoll_create1,1, int flags)

SYSDEF_syscall(_dup3,3, unsigned int oldfd,  unsigned int newfd,  int flags)

SYSDEF_syscall(_pipe2,2, int *filedes,  int flags)

SYSDEF_syscall(_inotify_init1,1, int flags)

SYSDEF_syscall(_preadv,5, unsigned long fd,  const struct iovec *vec,  unsigned long vlen,  unsigned long pos_l,  unsigned long pos_h)

SYSDEF_syscall(_pwritev,5, unsigned long fd,  const struct iovec *vec,  unsigned long vlen,  unsigned long pos_l,  unsigned long pos_h)

SYSDEF_syscall(_rt_tgsigqueueinfo,4, pid_t tgid,  pid_t pid,  int sig,  siginfo_t *uinfo)

SYSDEF_syscall(_perf_event_open,5, struct perf_event_attr *attr_uptr,  pid_t pid,  int cpu,  int group_fd,  unsigned long flags)

SYSDEF_syscall(_recvmmsg,5, int fd,  struct msghdr *mmsg,  unsigned int vlen,  unsigned int flags,  struct timespec *timeout)

SYSDEF_syscall(_fanotify_init,2, unsigned int flags,  unsigned int event_f_flags)

SYSDEF_syscall(_fanotify_mark,5, long fanotify_fd,  long flags,  __u64 mask,  long dfd, long pathname)

SYSDEF_syscall(_prlimit64,4, pid_t pid,  unsigned int resource,  const struct rlimit64 *new_rlim,  struct rlimit64 *old_rlim)

SYSDEF_syscall(_name_to_handle_at,5, int dfd,  const char *name,  struct file_handle *handle,  int *mnt_id,  int flag)

SYSDEF_syscall(_open_by_handle_at,5, int dfd,  const char *name,  struct file_handle *handle,  int *mnt_id,  int flags)

SYSDEF_syscall(_clock_adjtime,2, clockid_t which_clock,  struct timex *tx)

SYSDEF_syscall(_syncfs,1, int fd)

SYSDEF_syscall(_sendmmsg,4, int fd,  struct mmsghdr *mmsg,  unsigned int vlen,  unsigned int flags)

SYSDEF_syscall(_setns,2, int fd,  int nstype)

SYSDEF_syscall(_getcpu,3, unsigned *cpup,  unsigned *nodep,  struct getcpu_cache *unused)

SYSDEF_syscall(_process_vm_readv,6, pid_t pid,  const struct iovec *lvec,  unsigned long liovcnt,  const struct iovec *rvec,  unsigned long riovcnt,  unsigned long flags)

SYSDEF_syscall(_process_vm_writev,6, pid_t pid,  const struct iovec *lvec,  unsigned long liovcnt,  const struct iovcc *rvec,  unsigned long riovcnt,  unsigned long flags)

SYSDEF_syscall(_kcmp,5, pid_t pid1,  pid_t pid2,  int type,  unsigned long idx1,  unsigned long idx2)

SYSDEF_syscall(_finit_module,3, int fd,  const char  *uargs,  int flags)

SYSDEF_syscall(_sched_setattr,3, pid_t pid,  struct sched_attr  *attr,  unsigned int flags)

SYSDEF_syscall(_sched_getattr,4, pid_t pid,  struct sched_attr  *attr,  unsigned int size,  unsigned int flags)

SYSDEF_syscall(_renameat2,5, int olddfd,  const char  *oldname,  int newdfd,  const char  *newname,  unsigned int flags)

SYSDEF_syscall(_seccomp,3, unsigned int op,  unsigned int flags,  const char  *uargs)

SYSDEF_syscall(_getrandom,3, char  *buf,  size_t count,  unsigned int flags)

SYSDEF_syscall(_memfd_create,2, const char  *uname_ptr,  unsigned int flags)

SYSDEF_syscall(_kexec_file_load,5, int kernel_fd,  int initrd_fd,  unsigned long cmdline_len,  const char  *cmdline_ptr,  unsigned long flags)

//SYSDEF_syscall(_bpf,3, int cmd,  union bpf_attr *attr,  unsigned int size)


#endif

