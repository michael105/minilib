#ifndef syscalls_x64_h

#define syscalls_x64_h


DEF_syscall(read,3, unsigned int fd,  char *buf,  size_t count)

DEF_syscall(write,3, unsigned int fd,  const char *buf,  size_t count)

DEF_syscall(open,3, const char *filename,  int flags,  int mode)

DEF_syscall(close,1, unsigned int fd)

DEF_syscall(stat,2, const char *filename,  struct stat *statbuf)

DEF_syscall(fstat,2, unsigned int fd,  struct stat *statbuf)

DEF_syscall(lstat,2, const char *filename,  struct stat *statbuf)

DEF_syscall(poll,3, struct poll_fd *ufds,  unsigned int nfds,  long timeout_msecs)

DEF_syscall(lseek,3, unsigned int fd,  off_t offset,  unsigned int origin)

DEF_syscall(mmap,6, unsigned long addr,  unsigned long len,  unsigned long prot,  unsigned long flags,  unsigned long fd,  unsigned long off)

DEF_syscall(mprotect,3, unsigned long start,  size_t len,  unsigned long prot)

DEF_syscall(munmap,2, unsigned long addr,  size_t len)

DEF_syscall(brk,1, unsigned long brk)

DEF_syscall(rt_sigaction,4, int sig,  const struct sigaction *act,  struct sigaction *oact,  size_t sigsetsize)

DEF_syscall(rt_sigprocmask,4, int how,  sigset_t *nset,  sigset_t *oset,  size_t sigsetsize)

DEF_syscall(rt_sigreturn,1, unsigned long __unused)

DEF_syscall(ioctl,3, unsigned int fd,  unsigned int cmd,  unsigned long arg)

DEF_syscall(pread64,4, unsigned long fd,  char *buf,  size_t count,  loff_t pos)

DEF_syscall(pwrite64,4, unsigned int fd,  const char *buf,  size_t count,  loff_t pos)

DEF_syscall(readv,3, unsigned long fd,  const struct iovec *vec,  unsigned long vlen)

DEF_syscall(writev,3, unsigned long fd,  const struct iovec *vec,  unsigned long vlen)

DEF_syscall(access,2, const char *filename,  int mode)

DEF_syscall(pipe,1, int *filedes)

DEF_syscall(select,5, int n,  fd_set *inp,  fd_set *outp,  fd_set *exp,  struct timeval *tvp)

DEF_syscall(sched_yield,0)

DEF_syscall(mremap,5, unsigned long addr,  unsigned long old_len,  unsigned long new_len,  unsigned long flags,  unsigned long new_addr)

DEF_syscall(msync,3, unsigned long start,  size_t len,  int flags)

DEF_syscall(mincore,3, unsigned long start,  size_t len,  unsigned char *vec)

DEF_syscall(madvise,3, unsigned long start,  size_t len_in,  int behavior)

DEF_syscall(shmget,3, key_t key,  size_t size,  int shmflg)

DEF_syscall(shmat,3, int shmid,  char *shmaddr,  int shmflg)

DEF_syscall(shmctl,3, int shmid,  int cmd,  struct shmid_ds *buf)

DEF_syscall(dup,1, unsigned int fildes)

DEF_syscall(dup2,2, unsigned int oldfd,  unsigned int newfd)

DEF_syscall(pause,0)

DEF_syscall(nanosleep,2, struct timespec *rqtp,  struct timespec *rmtp)

DEF_syscall(getitimer,2, int which,  struct itimerval *value)

DEF_syscall(alarm,1, unsigned int seconds)

DEF_syscall(setitimer,3, int which,  struct itimerval *value,  struct itimerval *ovalue)

DEF_syscall(getpid,0)

DEF_syscall(sendfile,4, int out_fd,  int in_fd,  off_t *offset,  size_t count)

DEF_syscall(socket,3, int family,  int type,  int protocol)

DEF_syscall(connect,3, int fd,  struct sockaddr *uservaddr,  int addrlen)

DEF_syscall(accept,3, int fd,  struct sockaddr *upeersockaddr,  int *upeeraddrlen)

DEF_syscall(sendto,6, int fd,  void *buff,  size_t len,  unsigned flags,  struct sockaddr *addr,  int addr_len)

DEF_syscall(recvfrom,6, int fd,  void *ubuf,  size_t size,  unsigned flags,  struct sockaddr *addr,  int *addr_len)

DEF_syscall(sendmsg,3, int fd,  struct msghdr *msg,  unsigned flags)

DEF_syscall(recvmsg,3, int fd,  struct msghdr *msg,  unsigned int flags)

DEF_syscall(shutdown,2, int fd,  int how)

DEF_syscall(bind,3, int fd,  struct sockaddr *umyaddr,  int addrlen)

DEF_syscall(listen,2, int fd,  int backlog)

DEF_syscall(getsockname,3, int fd,  struct sockaddr *usockaddr,  int *usockaddr_len)

DEF_syscall(getpeername,3, int fd,  struct sockaddr *usockaddr,  int *usockaddr_len)

DEF_syscall(socketpair,4, int family,  int type,  int protocol,  int *usockvec)

DEF_syscall(setsockopt,5, int fd,  int level,  int optname,  char *optval,  int optlen)

DEF_syscall(getsockopt,5, int fd,  int level,  int optname,  char *optval,  int *optlen)

DEF_syscall(clone,4, unsigned long clone_flags,  unsigned long newsp,  void *parent_tid,  void *child_tid)

DEF_syscall(fork,0)

DEF_syscall(vfork,0)

DEF_syscall(execve,3, const char *filename,  const char *const argv[],  const char *const envp[])

DEF_syscall(exit,1, int error_code)

DEF_syscall(wait4,4, pid_t upid,  int *stat_addr,  int options,  struct rusage *ru)

DEF_syscall(kill,2, pid_t pid,  int sig)

DEF_syscall(uname,1, struct old_utsname *name)

DEF_syscall(semget,3, key_t key,  int nsems,  int semflg)

DEF_syscall(semop,3, int semid,  struct sembuf *tsops,  unsigned nsops)

DEF_syscall(semctl,4, int semid,  int semnum,  int cmd,  semun_u arg)

DEF_syscall(shmdt,1, char *shmaddr)

DEF_syscall(msgget,2, key_t key,  int msgflg)

DEF_syscall(msgsnd,4, int msqid,  struct msgbuf *msgp,  size_t msgsz,  int msgflg)

DEF_syscall(msgrcv,5, int msqid,  struct msgbuf *msgp,  size_t msgsz,  long msgtyp,  int msgflg)

DEF_syscall(msgctl,3, int msqid,  int cmd,  struct msqid_ds *buf)

DEF_syscall(fcntl,3, unsigned int fd,  unsigned int cmd,  unsigned long arg)

DEF_syscall(flock,2, unsigned int fd,  unsigned int cmd)

DEF_syscall(fsync,1, unsigned int fd)

DEF_syscall(fdatasync,1, unsigned int fd)

DEF_syscall(truncate,2, const char *path,  long length)

DEF_syscall(ftruncate,2, unsigned int fd,  unsigned long length)

DEF_syscall(getdents,3, unsigned int fd,  struct linux_dirent *dirent,  unsigned int count)

DEF_syscall(getcwd,2, char *buf,  unsigned long size)

DEF_syscall(chdir,1, const char *filename)

DEF_syscall(fchdir,1, unsigned int fd)

DEF_syscall(rename,2, const char *oldname,  const char *newname)

DEF_syscall(mkdir,2, const char *pathname,  int mode)

DEF_syscall(rmdir,1, const char *pathname)

DEF_syscall(creat,2, const char *pathname,  int mode)

DEF_syscall(link,2, const char *oldname,  const char *newname)

DEF_syscall(unlink,1, const char *pathname)

DEF_syscall(symlink,2, const char *oldname,  const char *newname)

DEF_syscall(readlink,3, const char *path,  char *buf,  int bufsiz)

DEF_syscall(chmod,2, const char *filename,  mode_t mode)

DEF_syscall(fchmod,2, unsigned int fd,  mode_t mode)

DEF_syscall(chown,3, const char *filename,  uid_t user,  gid_t group)

DEF_syscall(fchown,3, unsigned int fd,  uid_t user,  gid_t group)

DEF_syscall(lchown,3, const char *filename,  uid_t user,  gid_t group)

DEF_syscall(umask,1, int mask)

DEF_syscall(gettimeofday,2, struct timeval *tv,  struct timezone *tz)

DEF_syscall(getrlimit,2, unsigned int resource,  struct rlimit *rlim)

DEF_syscall(getrusage,2, int who,  struct rusage *ru)

DEF_syscall(sysinfo,1, struct sysinfo *info)

DEF_syscall(times,1, struct sysinfo *info)

DEF_syscall(ptrace,4, long request,  long pid,  unsigned long addr,  unsigned long data)

DEF_syscall(getuid,0)

DEF_syscall(syslog,3, int type,  char *buf,  int len)

DEF_syscall(getgid,0)

DEF_syscall(setuid,1, uid_t uid)

DEF_syscall(setgid,1, gid_t gid)

DEF_syscall(geteuid,0)

DEF_syscall(getegid,0)

DEF_syscall(setpgid,2, pid_t pid,  pid_t pgid)

DEF_syscall(getppid,0)

DEF_syscall(getpgrp,0)

DEF_syscall(setsid,0)

DEF_syscall(setreuid,2, uid_t ruid,  uid_t euid)

DEF_syscall(setregid,2, gid_t rgid,  gid_t egid)

DEF_syscall(getgroups,2, int gidsetsize,  gid_t *grouplist)

DEF_syscall(setgroups,2, int gidsetsize,  gid_t *grouplist)

DEF_syscall(setresuid,3, uid_t *ruid,  uid_t *euid,  uid_t *suid)

DEF_syscall(getresuid,3, uid_t *ruid,  uid_t *euid,  uid_t *suid)

DEF_syscall(setresgid,3, gid_t rgid,  gid_t egid,  gid_t sgid)

DEF_syscall(getresgid,3, gid_t *rgid,  gid_t *egid,  gid_t *sgid)

DEF_syscall(getpgid,1, pid_t pid)

DEF_syscall(setfsuid,1, uid_t uid)

DEF_syscall(setfsgid,1, gid_t gid)

DEF_syscall(getsid,1, pid_t pid)

DEF_syscall(capget,2, cap_user_header_t header,  cap_user_data_t dataptr)

DEF_syscall(capset,2, cap_user_header_t header,  const cap_user_data_t data)

DEF_syscall(rt_sigpending,2, sigset_t *set,  size_t sigsetsize)

DEF_syscall(rt_sigtimedwait,4, const sigset_t *uthese,  siginfo_t *uinfo,  const struct timespec *uts,  size_t sigsetsize)

DEF_syscall(rt_sigqueueinfo,3, pid_t pid,  int sig,  siginfo_t *uinfo)

DEF_syscall(rt_sigsuspend,2, sigset_t *unewset,  size_t sigsetsize)

DEF_syscall(sigaltstack,2, const stack_t *uss,  stack_t *uoss)

DEF_syscall(utime,2, char *filename,  struct utimbuf *times)

DEF_syscall(mknod,3, const char *filename,  umode_t mode,  unsigned dev)

DEF_syscall(personality,1, unsigned int personality)

DEF_syscall(ustat,2, unsigned dev,  struct ustat *ubuf)

DEF_syscall(statfs,2, const char *pathname,  struct statfs *buf)

DEF_syscall(fstatfs,2, unsigned int fd,  struct statfs *buf)

DEF_syscall(sysfs,3, int option,  unsigned long arg1,  unsigned long arg2)

DEF_syscall(getpriority,2, int which,  int who)

DEF_syscall(setpriority,3, int which,  int who,  int niceval)

DEF_syscall(sched_setparam,2, pid_t pid,  struct sched_param *param)

DEF_syscall(sched_getparam,2, pid_t pid,  struct sched_param *param)

DEF_syscall(sched_setscheduler,3, pid_t pid,  int policy,  struct sched_param *param)

DEF_syscall(sched_getscheduler,1, pid_t pid)

DEF_syscall(sched_get_priority_max,1, int policy)

DEF_syscall(sched_get_priority_min,1, int policy)

DEF_syscall(sched_rr_get_interval,2, pid_t pid,  struct timespec *interval)

DEF_syscall(mlock,2, unsigned long start,  size_t len)

DEF_syscall(munlock,2, unsigned long start,  size_t len)

DEF_syscall(mlockall,1, int flags)

DEF_syscall(munlockall,0)

DEF_syscall(vhangup,0)

DEF_syscall(modify_ldt,3, int func,  void *ptr,  unsigned long bytecount)

DEF_syscall(pivot_root,2, const char *new_root,  const char *put_old)

DEF_syscall(_sysctl,1, struct __sysctl_args *args)

DEF_syscall(prctl,5, int option,  unsigned long arg2,  unsigned long arg3,  unsigned long arg4,  unsigned long arg5)

DEF_syscall(arch_prctl,3, struct task_struct *task,  int code,  unsigned long *addr)

DEF_syscall(adjtimex,1, struct timex *txc_p)

DEF_syscall(setrlimit,2, unsigned int resource,  struct rlimit *rlim)

DEF_syscall(chroot,1, const char *filename)

DEF_syscall(sync,0)

DEF_syscall(acct,1, const char *name)

DEF_syscall(settimeofday,2, struct timeval *tv,  struct timezone *tz)

DEF_syscall(mount,5, char *dev_name,  char *dir_name,  char *type,  unsigned long flags,  void *data)

DEF_syscall(umount2,2, const char *target,  int flags)

DEF_syscall(swapon,2, const char *specialfile,  int swap_flags)

DEF_syscall(swapoff,1, const char *specialfile)

DEF_syscall(reboot,4, int magic1,  int magic2,  unsigned int cmd,  void *arg)

DEF_syscall(sethostname,2, char *name,  int len)

DEF_syscall(setdomainname,2, char *name,  int len)

DEF_syscall(iopl,2, unsigned int level,  struct pt_regs *regs)

DEF_syscall(ioperm,3, unsigned long from,  unsigned long num,  int turn_on)

DEF_syscall(init_module,3, void *umod,  unsigned long len,  const char *uargs)

DEF_syscall(delete_module,2, const char *name_user,  unsigned int flags)

DEF_syscall(quotactl,4, unsigned int cmd,  const char *special,  qid_t id,  void *addr)

DEF_syscall(gettid,0)

DEF_syscall(readahead,3, int fd,  loff_t offset,  size_t count)

DEF_syscall(setxattr,5, const char *pathname,  const char *name,  const void *value, size_t size,  int flags)

DEF_syscall(lsetxattr,5, const char *pathname,  const char *name,  const void *value, size_t size,  int flags)

DEF_syscall(fsetxattr,5, int fd,  const char *name,  const void *value,  size_t size, int flags)

DEF_syscall(getxattr,4, const char *pathname,  const char *name,  void *value,  size_t size)

DEF_syscall(lgetxattr,4, const char *pathname,  const char *name,  void *value,  size_t size)

DEF_syscall(fgetxattr,4, int fd,  const char *name,  void *value,  size_t size)

DEF_syscall(listxattr,3, const char *pathname,  char *list,  size_t size)

DEF_syscall(llistxattr,3, const char *pathname,  char *list,  size_t size)

DEF_syscall(flistxattr,3, int fd,  char *list,  size_t size)

DEF_syscall(removexattr,2, const char *pathname,  const char *name)

DEF_syscall(lremovexattr,2, const char *pathname,  const char *name)

DEF_syscall(fremovexattr,2, int fd,  const char *name)

DEF_syscall(tkill,2, pid_t pid,  int sig)

DEF_syscall(time,1, time_t *tloc)

DEF_syscall(futex,6, u32 *uaddr,  int op,  u32 val,  struct timespec *utime,  u32 *uaddr2,  u32 val3)

DEF_syscall(sched_setaffinity,3, pid_t pid,  unsigned int len,  unsigned long *user_mask_ptr)

DEF_syscall(sched_getaffinity,3, pid_t pid,  unsigned int len,  unsigned long *user_mask_ptr)

DEF_syscall(io_setup,2, unsigned nr_events,  aio_context_t *ctxp)

DEF_syscall(io_destroy,1, aio_context_t ctx)

DEF_syscall(io_getevents,4, aio_context_t ctx_id,  long min_nr,  long nr,  struct io_event *events)

DEF_syscall(io_submit,3, aio_context_t ctx_id,  long nr,  struct iocb **iocbpp)

DEF_syscall(io_cancel,3, aio_context_t ctx_id,  struct iocb *iocb,  struct io_event *result)

DEF_syscall(lookup_dcookie,3, u64 cookie64,  long buf,  long len)

DEF_syscall(epoll_create,1, int size)

DEF_syscall(remap_file_pages,5, unsigned long start,  unsigned long size,  unsigned long prot,  unsigned long pgoff,  unsigned long flags)

DEF_syscall(getdents64,3, unsigned int fd,  struct linux_dirent64 *dirent,  unsigned int count)

DEF_syscall(set_tid_address,1, int *tidptr)

DEF_syscall(restart_syscall,0)

DEF_syscall(semtimedop,4, int semid,  struct sembuf *tsops,  unsigned nsops,  const struct timespec *timeout)

DEF_syscall(fadvise64,4, int fd,  loff_t offset,  size_t len,  int advice)

DEF_syscall(timer_create,3, const clockid_t which_clock,  struct sigevent *timer_event_spec,  timer_t *created_timer_id)

DEF_syscall(timer_settime,4, timer_t timer_id,  int flags,  const struct itimerspec *new_setting,  struct itimerspec *old_setting)

DEF_syscall(timer_gettime,2, timer_t timer_id,  struct itimerspec *setting)

DEF_syscall(timer_getoverrun,1, timer_t timer_id)

DEF_syscall(timer_delete,1, timer_t timer_id)

DEF_syscall(clock_settime,2, const clockid_t which_clock,  const struct timespec *tp)

DEF_syscall(clock_gettime,2, const clockid_t which_clock,  struct timespec *tp)

DEF_syscall(clock_getres,2, const clockid_t which_clock,  struct timespec *tp)

DEF_syscall(clock_nanosleep,4, const clockid_t which_clock,  int flags,  const struct timespec *rqtp,  struct timespec *rmtp)

DEF_syscall(exit_group,1, int error_code)

DEF_syscall(epoll_wait,4, int epfd,  struct epoll_event *events,  int maxevents,  int timeout)

DEF_syscall(epoll_ctl,4, int epfd,  int op,  int fd,  struct epoll_event *event)

DEF_syscall(tgkill,3, pid_t tgid,  pid_t pid,  int sig)

DEF_syscall(utimes,2, char *filename,  struct timeval *utimes)

DEF_syscall(mbind,6, unsigned long start,  unsigned long len,  unsigned long mode,  unsigned long *nmask,  unsigned long maxnode,  unsigned flags)

DEF_syscall(set_mempolicy,3, int mode,  unsigned long *nmask,  unsigned long maxnode)

DEF_syscall(get_mempolicy,5, int *policy,  unsigned long *nmask,  unsigned long maxnode,  unsigned long addr,  unsigned long flags)

DEF_syscall(mq_open,4, const char *u_name,  int oflag,  mode_t mode,  struct mq_attr *u_attr)

DEF_syscall(mq_unlink,1, const char *u_name)

DEF_syscall(mq_timedsend,5, mqd_t mqdes,  const char *u_msg_ptr,  size_t msg_len,  unsigned int msg_prio,  const struct timespec *u_abs_timeout)

DEF_syscall(mq_timedreceive,5, mqd_t mqdes,  char *u_msg_ptr,  size_t msg_len,  unsigned int *u_msg_prio,  const struct timespec *u_abs_timeout)

DEF_syscall(mq_notify,2, mqd_t mqdes,  const struct sigevent *u_notification)

DEF_syscall(mq_getsetattr,3, mqd_t mqdes,  const struct mq_attr *u_mqstat,  struct mq_attr *u_omqstat)

DEF_syscall(kexec_load,4, unsigned long entry,  unsigned long nr_segments,  struct kexec_segment *segments,  unsigned long flags)

DEF_syscall(waitid,5, int which,  pid_t upid,  struct siginfo *infop,  int options,  struct rusage *ru)

DEF_syscall(add_key,4, const char *_type,  const char *_description,  const void *_payload,  size_t plen)

DEF_syscall(request_key,4, const char *_type,  const char *_description,  const char *_callout_info,  key_serial_t destringid)

DEF_syscall(keyctl,5, int option,  unsigned long arg2,  unsigned long arg3,  unsigned long arg4,  unsigned long arg5)

DEF_syscall(ioprio_set,3, int which,  int who,  int ioprio)

DEF_syscall(ioprio_get,2, int which,  int who)

DEF_syscall(inotify_init,0)

DEF_syscall(inotify_add_watch,3, int fd,  const char *pathname,  u32 mask)

DEF_syscall(inotify_rm_watch,2, int fd,  __s32 wd)

DEF_syscall(migrate_pages,4, pid_t pid,  unsigned long maxnode,  const unsigned long *old_nodes,  const unsigned long *new_nodes)

DEF_syscall(openat,4, int dfd,  const char *filename,  int flags,  int mode)

DEF_syscall(mkdirat,3, int dfd,  const char *pathname,  int mode)

DEF_syscall(mknodat,4, int dfd,  const char *filename,  int mode,  unsigned dev)

DEF_syscall(fchownat,5, int dfd,  const char *filename,  uid_t user,  gid_t group,  int flag)

DEF_syscall(futimesat,3, int dfd,  const char *filename,  struct timeval *utimes)

DEF_syscall(newfstatat,4, int dfd,  const char *filename,  struct stat *statbuf,  int flag)

DEF_syscall(unlinkat,3, int dfd,  const char *pathname,  int flag)

DEF_syscall(renameat,4, int oldfd,  const char *oldname,  int newfd,  const char *newname)

DEF_syscall(linkat,5, int oldfd,  const char *oldname,  int newfd,  const char *newname,  int flags)

DEF_syscall(symlinkat,3, const char *oldname,  int newfd,  const char *newname)

DEF_syscall(readlinkat,4, int dfd,  const char *pathname,  char *buf,  int bufsiz)

DEF_syscall(fchmodat,3, int dfd,  const char *filename,  mode_t mode)

DEF_syscall(faccessat,3, int dfd,  const char *filename,  int mode)

DEF_syscall(pselect6,6, int n,  fd_set *inp,  fd_set *outp,  fd_set *exp,  struct timespec *tsp,  void *sig)

DEF_syscall(ppoll,5, struct pollfd *ufds,  unsigned int nfds,  struct timespec *tsp,  const sigset_t *sigmask,  size_t sigsetsize)

DEF_syscall(unshare,1, unsigned long unshare_flags)

DEF_syscall(set_robust_list,2, struct robust_list_head *head,  size_t len)

DEF_syscall(get_robust_list,3, int pid,  struct robust_list_head **head_ptr,  size_t *len_ptr)

DEF_syscall(splice,6, int fd_in,  loff_t *off_in,  int fd_out,  loff_t *off_out, size_t len,  unsigned int flags)

DEF_syscall(tee,4, int fdin,  int fdout,  size_t len,  unsigned int flags)

DEF_syscall(sync_file_range,4, long fd,  loff_t offset,  loff_t bytes,  long flags)

DEF_syscall(vmsplice,4, int fd,  const struct iovec *iov,  unsigned long nr_segs, unsigned int flags)

DEF_syscall(move_pages,6, pid_t pid,  unsigned long nr_pages,  const void *pages[], const int *nodes,  int *status,  int flags)

DEF_syscall(utimensat,4, int dfd,  const char *filename,  struct timespec *utimes, int flags)

DEF_syscall(epoll_pwait,6, int epfd,  struct epoll_event *events,  int maxevents,  int timeout,  const sigset_t *sigmask,  size_t sigsetsize)

DEF_syscall(signalfd,3, int ufd,  sigset_t *user_mask,  size_t sizemask)

DEF_syscall(timerfd_create,2, int clockid,  int flags)

DEF_syscall(eventfd,1, unsigned int count)

DEF_syscall(fallocate,4, long fd,  long mode,  loff_t offset,  loff_t len)

DEF_syscall(timerfd_settime,4, int ufd,  int flags,  const struct itimerspec *utmr,  struct itimerspec *otmr)

DEF_syscall(timerfd_gettime,2, int ufd,  struct itimerspec *otmr)

DEF_syscall(accept4,4, int fd,  struct sockaddr *upeer_sockaddr,  int *upeer_addrlen,  int flags)

DEF_syscall(signalfd4,4, int ufd,  sigset_t *user_mask,  size_t sizemask,  int flags)

DEF_syscall(eventfd2,2, unsigned int count,  int flags)

DEF_syscall(epoll_create1,1, int flags)

DEF_syscall(dup3,3, unsigned int oldfd,  unsigned int newfd,  int flags)

DEF_syscall(pipe2,2, int *filedes,  int flags)

DEF_syscall(inotify_init1,1, int flags)

DEF_syscall(preadv,5, unsigned long fd,  const struct iovec *vec,  unsigned long vlen,  unsigned long pos_l,  unsigned long pos_h)

DEF_syscall(pwritev,5, unsigned long fd,  const struct iovec *vec,  unsigned long vlen,  unsigned long pos_l,  unsigned long pos_h)

DEF_syscall(rt_tgsigqueueinfo,4, pid_t tgid,  pid_t pid,  int sig,  siginfo_t *uinfo)

DEF_syscall(perf_event_open,5, struct perf_event_attr *attr_uptr,  pid_t pid,  int cpu,  int group_fd,  unsigned long flags)

DEF_syscall(recvmmsg,5, int fd,  struct msghdr *mmsg,  unsigned int vlen,  unsigned int flags,  struct timespec *timeout)

DEF_syscall(fanotify_init,2, unsigned int flags,  unsigned int event_f_flags)

DEF_syscall(fanotify_mark,5, long fanotify_fd,  long flags,  __u64 mask,  long dfd, long pathname)

DEF_syscall(prlimit64,4, pid_t pid,  unsigned int resource,  const struct rlimit64 *new_rlim,  struct rlimit64 *old_rlim)

DEF_syscall(name_to_handle_at,5, int dfd,  const char *name,  struct file_handle *handle,  int *mnt_id,  int flag)

DEF_syscall(open_by_handle_at,5, int dfd,  const char *name,  struct file_handle *handle,  int *mnt_id,  int flags)

DEF_syscall(clock_adjtime,2, clockid_t which_clock,  struct timex *tx)

DEF_syscall(syncfs,1, int fd)

DEF_syscall(sendmmsg,4, int fd,  struct mmsghdr *mmsg,  unsigned int vlen,  unsigned int flags)

DEF_syscall(setns,2, int fd,  int nstype)

DEF_syscall(getcpu,3, unsigned *cpup,  unsigned *nodep,  struct getcpu_cache *unused)

DEF_syscall(process_vm_readv,6, pid_t pid,  const struct iovec *lvec,  unsigned long liovcnt,  const struct iovec *rvec,  unsigned long riovcnt,  unsigned long flags)

DEF_syscall(process_vm_writev,6, pid_t pid,  const struct iovec *lvec,  unsigned long liovcnt,  const struct iovcc *rvec,  unsigned long riovcnt,  unsigned long flags)

DEF_syscall(kcmp,5, pid_t pid1,  pid_t pid2,  int type,  unsigned long idx1,  unsigned long idx2)

DEF_syscall(finit_module,3, int fd,  const char  *uargs,  int flags)

DEF_syscall(sched_setattr,3, pid_t pid,  struct sched_attr  *attr,  unsigned int flags)

DEF_syscall(sched_getattr,4, pid_t pid,  struct sched_attr  *attr,  unsigned int size,  unsigned int flags)

DEF_syscall(renameat2,5, int olddfd,  const char  *oldname,  int newdfd,  const char  *newname,  unsigned int flags)

DEF_syscall(seccomp,3, unsigned int op,  unsigned int flags,  const char  *uargs)

DEF_syscall(getrandom,3, char  *buf,  size_t count,  unsigned int flags)

DEF_syscall(memfd_create,2, const char  *uname_ptr,  unsigned int flags)

DEF_syscall(kexec_file_load,5, int kernel_fd,  int initrd_fd,  unsigned long cmdline_len,  const char  *cmdline_ptr,  unsigned long flags)

DEF_syscall(bpf,3, int cmd,  union bpf_attr *attr,  unsigned int size)


#endif

