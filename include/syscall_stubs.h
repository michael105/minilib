#ifndef syscall_stubs_h
#define syscall_stubs_h
/*
 These are just wrapped syscalls.
 errno is set, anyways.

 This file (and the other headers) are parsed by 'genheaders.pl',
 and the "real" syscall defines below the mark generated-makros-start created.	

*/

//+header declarations.h
//
///+needs mini_fstream.h


#ifndef mini_globals_on_stack
extern int errno;
#endif
//extern int sysret;

struct stat;
struct timeval;
struct timezone;

// TODO: declarations
// below are untested definitions,
// for the SYSREAL... (expanding to sys"syscallname" ) macros
//typedef long sigset_t;
typedef unsigned long u64;
typedef unsigned long __u64;
typedef unsigned int u32;
typedef unsigned char __s32;

typedef long aio_context_t;
typedef long key_serial_t;
typedef long loff_t;
typedef long qid_t;
typedef long mqd_t;
typedef long stack_t;
typedef long umode_t;
typedef long cap_user_data_t;
typedef long cap_user_header_t;
typedef long semun_u;
struct sockaddr;
struct iovcc;
struct rusage;
struct file_handle;
struct utimbuf;
struct sched_attr;
struct sched_param;
struct itimerspec;
struct kexec_segment;
struct task_struct;
struct msghdr;
struct iocb;
struct io_event;
struct linux_dirent64;
struct pt_regs;
struct perf_event_attr;
struct __sysctl_args;
struct timex;
struct msgbuf;
struct pollfd;
struct getcpu_cache;
struct bpf_attr;
struct shmid_ds;
struct epoll_event;
struct mq_attr;
struct poll_fd;
struct mq_attr;
struct sembuf;
struct statfs;
struct sysinfo;
struct rlimit;
struct ustat;
struct itimerval;
struct linux_dirent;
struct robust_list_head;
struct sigevent;
struct siginfo;
struct bpf_attr;
struct msqid_ds;
struct rlimit64;
struct sigaction;
struct mmsghdr;
struct msqid_ds;
// end of "pre"-definitions


// working and tested syscalls below.
// the 'DEF' and 'SYSDEF' definitions are parsed by
// the script genheader.pl, (invoked by make header)
// and the REALDEF... definitions written. 
// (as well as the documentation)
//
// These macros in turn are defined within syscall.h

// files
//
DEF_syscall(close, 1, int fd )
DEF_syscall(read, 3, int fd, void *buf, int len )
DEF_syscall(write,3,int fd,const void *buf, int len )

DEF_syscall(getdents, 3, unsigned int fd, struct dirent *direntry, unsigned int count )

DEF_syscall(rename,2, const char* oldpath, const char* newpath )
DEF_syscall(unlink,1, const char* path)

DEF_syscall(fstat,2,int fd,struct stat* statbuf)
DEF_syscall(stat,2,const char* filename,struct stat* statbuf)		
DEF_syscall(chdir,1,const char* path)

DEF_syscall(fchown,3, unsigned int fd, uid_t user, gid_t group)
DEF_syscall(fchmod,2, unsigned int fd, mode_t mode)

DEF_syscall(dup,1,int fd)		
DEF_syscall(dup2,2,int oldfd, int newfd)		
DEF_syscall(dup3,3,int oldfd, int newfd, int flags)		

DEF_syscall(getcwd,2, char *buf,  unsigned long size)

DEF_syscall(link,2, const char *oldname, const char *newname)
DEF_syscall(symlink,2, const char *oldname,  const char *newname)
DEF_syscall(sync,0)

// process
DEF_syscall(execve,3, const char *filename,  char* const* argv, char* const* envp)

DEF_syscall(kill,2, pid_t pid,  int sig)

DEF_syscall(fork,0)
DEF_syscall(vfork,0)

// time
DEF_syscall(nanosleep,2, struct timespec *rqtp, struct timespec *rmtp)
DEF_syscall(gettimeofday,2, struct timeval *a1, struct timezone *a2)

DEF_syscall(rt_sigaction,4, int sig,  const struct sigaction *act,  struct sigaction *oact,  size_t sigsetsize)
DEF_syscall(rt_sigreturn,1, unsigned long __unused)

DEF_syscall(chroot,1, const char *filename)
DEF_syscall(pivot_root,2, const char *new_root,  const char *put_old)


DEF_syscall(getpid,0 )
DEF_syscall(setsid,0 )
DEF_syscall(setgid,1, gid_t gid)
DEF_syscall(setuid,1, uid_t uid)

DEF_syscall(vhangup,0 )

DEF_syscall(uname,1,struct old_utsname *name )

// below not thouroughly tested (2020/05)

// (char *argv[] is equivalent to **argv)
DEF_syscall(execveat,5, int dirfd, const char *filename,  char* const* argv, char* const* envp, int flags)
DEF_syscall(mkdir,2, const char *pathname, int mode)
DEF_syscall(rmdir,1, const char *pathname)
DEF_syscall(wait4,4, pid_t upid,  int *stat_addr,  int options,  struct rusage *ru)
DEF_syscall(access,2, const char *filename, int mode)
DEF_syscall(fcntl,3, unsigned int fd, unsigned int cmd, unsigned long arg)

DEF_syscall(umount2,2, const char *mountpoint, int flags) 
DEF_syscall(sendfile,4, int out_fd,  int in_fd,  off_t *offset,  size_t count)
DEF_syscall(reboot,4, int magic1,  int magic2,  unsigned int cmd,  void *arg)

DEF_syscall(mount,5, char *dev_name,  char *dir_name,  char *type,  unsigned long flags,  void *data)

DEF_syscall(rt_sigprocmask,4, int how,  sigset_t *nset,  sigset_t *oset,  size_t sigsetsize)

// below not thouroughly tested (2020/07)

DEF_syscall(memfd_create,2, const char  *uname_ptr,  unsigned int flags)

//DEF_syscallret(mremap,a1,5, void* addr, size_t old_len, size_t new_len, int flags, void* new_addr)
//DEF_syscall(mremap,5, unsigned long addr,  unsigned long old_len,  unsigned long new_len,  unsigned long flags,  unsigned long new_addr)

DEF_syscall(splice,6, int fd_in,  loff_t *off_in,  int fd_out,  loff_t *off_out, size_t len,  unsigned int flags)


DEF_syscall(setgroups,2, int gidsetsize,  gid_t *grouplist)

DEF_syscall(chmod,2, const char *filename, mode_t mode)
DEF_syscall(chown,3, const char *filename, uid_t user, gid_t group)
DEF_syscall(utime,2, const char *filename, struct utimbuf *times)
DEF_syscall(getppid,0)
DEF_syscall(setpgid,2, pid_t pid, pid_t pgid)
DEF_syscall(getgid,0)
DEF_syscall(getpgrp,0)
DEF_syscall(getuid,0)


DEF_syscall(inotify_init,0)
DEF_syscall(inotify_add_watch,3, int fd,  const char *pathname,  u32 mask)
DEF_syscall(inotify_rm_watch,2, int fd,  __s32 wd)
DEF_syscall(inotify_init1,1, int flags)


DEF_syscall(clone,4, int clone_flags,  unsigned long stack,  void *parent_tid,  void *child_tid)


// below untested. 

// TODO might be wrong. ??
DEF_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3 )

DEF_syscall(pipe,1, int *filedes)
DEF_syscall(umask,1, int mask)
DEF_syscall(readahead,3, int fd,  loff_t offset,  size_t count)
DEF_syscall(mknod,3, const char *filename,  umode_t mode,  unsigned dev)

DEF_syscall(munmap,2, void* addr,  size_t len)

DEF_syscall(setitimer,3, int which,  struct itimerval *value,  struct itimerval *ovalue)
DEF_syscall(getitimer,2, int which,  struct itimerval *value)



#ifndef OSX
DEF_syscall(time,1,unsigned int *a1 )
//DEF_syscallret(time,*a1,1,unsigned int *a1 )
#else
#warning Todo: time osx
#endif

	// problem: ifdef / ifndef now doesnt work anymore for the definitions. 
	// Hopefully, thats not going to be a problem.
	// Will see it when trying to compile at osx again
	//
#if 1
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"

/* --- generated-macros-start: syscalldefs --- */
/* minilib/include/syscall_stubs.h, line: 206 */
REAL_define_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3)

/* minilib/include/lseek.h, line: 21 */
REAL_define_syscall(ftruncate,2,unsigned int a1,  unsigned int a2) 

/* minilib/include/syscall_stubs.h, line: 200 */
REAL_define_syscall_noopt(clone,4, int a1,   unsigned long a2,   void *a3,   void *a4) 

/* minilib/include/syscall_stubs.h, line: 164 */
REAL_define_syscall(umount2,2, const char *a1,  int a2)  

/* minilib/include/syscall_stubs.h, line: 127 */
REAL_define_syscall(execve,3, const char *a1,   char* const* a2,  char* const* a3) 

/* minilib/include/syscall_stubs.h, line: 186 */
REAL_define_syscall(utime,2, const char *a1,  struct utimbuf *a2) 

/* minilib/include/syscall_stubs.h, line: 189 */
REAL_define_syscall(getgid,0)

/* minilib/include/syscall_stubs.h, line: 208 */
REAL_define_syscall(pipe,1, int *a1) 

/* minilib/include/syscall_stubs.h, line: 221 */
REAL_define_syscall(time,1,unsigned int *a1) 

/* minilib/include/syscall_stubs.h, line: 141 */
REAL_define_syscall(chroot,1, const char *a1) 

/* minilib/include/syscall_stubs.h, line: 195 */
REAL_define_syscall(inotify_add_watch,3, int a1,   const char *a2,   u32 a3) 

/* minilib/include/syscall_stubs.h, line: 194 */
REAL_define_syscall(inotify_init,0)

/* minilib/include/syscall_stubs.h, line: 101 */
REAL_define_syscall(read, 3, int a1,  void *a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 104 */
REAL_define_syscall(getdents, 3, unsigned int a1,  struct dirent *a2,  unsigned int a3) 

/* minilib/include/syscall_stubs.h, line: 106 */
REAL_define_syscall(rename,2, const char* a1,  const char* a2) 

/* minilib/include/syscall_stubs.h, line: 146 */
REAL_define_syscall(setsid,0 )

/* minilib/include/syscall_stubs.h, line: 158 */
REAL_define_syscall(mkdir,2, const char *a1,  int a2) 

/* minilib/include/syscall_stubs.h, line: 211 */
REAL_define_syscall(mknod,3, const char *a1,   umode_t a2,   unsigned a3) 

/* minilib/include/syscall_stubs.h, line: 100 */
REAL_define_syscall(close, 1, int a1) 

/* minilib/include/syscall_stubs.h, line: 213 */
REAL_define_syscall(munmap,2, void* a1,   size_t a2) 

/* minilib/include/syscall_stubs.h, line: 216 */
REAL_define_syscall(getitimer,2, int a1,   struct itimerval *a2) 

/* minilib/include/syscall_stubs.h, line: 148 */
REAL_define_syscall(setuid,1, uid_t a1) 

/* minilib/include/syscall_stubs.h, line: 209 */
REAL_define_syscall(umask,1, int a1) 

/* minilib/include/syscall_stubs.h, line: 118 */
REAL_define_syscall(dup3,3,int a1,  int a2,  int a3) 		

/* minilib/include/syscall_stubs.h, line: 152 */
REAL_define_syscall(uname,1,struct old_utsname *a1) 

/* minilib/include/syscall_stubs.h, line: 182 */
REAL_define_syscall(setgroups,2, int a1,   gid_t *a2) 

/* minilib/include/syscall_stubs.h, line: 145 */
REAL_define_syscall(getpid,0 )

/* minilib/include/syscall_stubs.h, line: 102 */
REAL_define_syscall(write,3,int a1, const void *a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 135 */
REAL_define_syscall(nanosleep,2, struct timespec *a1,  struct timespec *a2) 

/* minilib/include/syscall_stubs.h, line: 179 */
REAL_define_syscall_noopt(splice,6, int a1,   loff_t *a2,   int a3,   loff_t *a4,  size_t a5,   unsigned int a6) 

/* minilib/include/syscall_stubs.h, line: 159 */
REAL_define_syscall(rmdir,1, const char *a1) 

/* minilib/include/syscall_stubs.h, line: 187 */
REAL_define_syscall(getppid,0)

/* minilib/include/syscall_stubs.h, line: 196 */
REAL_define_syscall(inotify_rm_watch,2, int a1,   __s32 a2) 

/* minilib/include/syscall_stubs.h, line: 170 */
REAL_define_syscall_noopt(rt_sigprocmask,4, int a1,   sigset_t *a2,   sigset_t *a3,   size_t a4) 

/* minilib/include/syscall_stubs.h, line: 166 */
REAL_define_syscall_noopt(reboot,4, int a1,   int a2,   unsigned int a3,   void *a4) 

/* minilib/include/syscall_stubs.h, line: 188 */
REAL_define_syscall(setpgid,2, pid_t a1,  pid_t a2) 

/* minilib/include/syscall_stubs.h, line: 215 */
REAL_define_syscall(setitimer,3, int a1,   struct itimerval *a2,   struct itimerval *a3) 

/* minilib/include/syscall_stubs.h, line: 122 */
REAL_define_syscall(link,2, const char *a1,  const char *a2) 

/* minilib/include/syscall_stubs.h, line: 142 */
REAL_define_syscall(pivot_root,2, const char *a1,   const char *a2) 

/* minilib/include/syscall_stubs.h, line: 113 */
REAL_define_syscall(fchown,3, unsigned int a1,  uid_t a2,  gid_t a3) 

/* minilib/include/syscall_stubs.h, line: 174 */
REAL_define_syscall(memfd_create,2, const char  *a1,   unsigned int a2) 

/* minilib/include/syscall_stubs.h, line: 110 */
REAL_define_syscall(stat,2,const char* a1, struct stat* a2) 		

/* minilib/include/syscall_stubs.h, line: 191 */
REAL_define_syscall(getuid,0)

/* minilib/include/syscall_stubs.h, line: 136 */
REAL_define_syscall(gettimeofday,2, struct timeval *a1,  struct timezone *a2) 

/* minilib/include/syscall_stubs.h, line: 107 */
REAL_define_syscall(unlink,1, const char* a1) 

/* minilib/include/lseek.h, line: 22 */
REAL_define_syscall(fsync,1,int a1) 

/* minilib/include/syscall_stubs.h, line: 165 */
REAL_define_syscall_noopt(sendfile,4, int a1,   int a2,   off_t *a3,   size_t a4) 

/* minilib/include/syscall_stubs.h, line: 111 */
REAL_define_syscall(chdir,1,const char* a1) 

/* minilib/include/syscall_stubs.h, line: 168 */
REAL_define_syscall_noopt(mount,5, char *a1,   char *a2,   char *a3,   unsigned long a4,   void *a5) 

/* minilib/include/syscall_stubs.h, line: 161 */
REAL_define_syscall(access,2, const char *a1,  int a2) 

/* minilib/include/syscall_stubs.h, line: 129 */
REAL_define_syscall(kill,2, pid_t a1,   int a2) 

/* minilib/include/syscall_stubs.h, line: 114 */
REAL_define_syscall(fchmod,2, unsigned int a1,  mode_t a2) 

/* minilib/include/syscall_stubs.h, line: 117 */
REAL_define_syscall(dup2,2,int a1,  int a2) 		

/* minilib/include/syscall_stubs.h, line: 150 */
REAL_define_syscall(vhangup,0 )

/* minilib/include/syscall_stubs.h, line: 185 */
REAL_define_syscall(chown,3, const char *a1,  uid_t a2,  gid_t a3) 

/* minilib/include/syscall_stubs.h, line: 123 */
REAL_define_syscall(symlink,2, const char *a1,   const char *a2) 

/* minilib/include/syscall_stubs.h, line: 109 */
REAL_define_syscall(fstat,2,int a1, struct stat* a2) 

/* minilib/include/syscall_stubs.h, line: 197 */
REAL_define_syscall(inotify_init1,1, int a1) 

/* minilib/include/syscall_stubs.h, line: 131 */
REAL_define_syscall(fork,0)

/* minilib/include/syscall_stubs.h, line: 147 */
REAL_define_syscall(setgid,1, gid_t a1) 

/* minilib/include/syscall_stubs.h, line: 120 */
REAL_define_syscall(getcwd,2, char *a1,   unsigned long a2) 

/* minilib/include/syscall_stubs.h, line: 210 */
REAL_define_syscall(readahead,3, int a1,   loff_t a2,   size_t a3) 

/* minilib/include/syscall_stubs.h, line: 116 */
REAL_define_syscall(dup,1,int a1) 		

/* minilib/include/syscall_stubs.h, line: 190 */
REAL_define_syscall(getpgrp,0)

/* minilib/include/syscall_stubs.h, line: 184 */
REAL_define_syscall(chmod,2, const char *a1,  mode_t a2) 

/* minilib/include/syscall_stubs.h, line: 138 */
REAL_define_syscall_noopt(rt_sigaction,4, int a1,   const struct sigaction *a2,   struct sigaction *a3,   size_t a4) 

/* minilib/include/syscall_stubs.h, line: 124 */
REAL_define_syscall(sync,0)

/* minilib/include/syscall_stubs.h, line: 139 */
REAL_define_syscall(rt_sigreturn,1, unsigned long a1) 

/* minilib/include/syscall_stubs.h, line: 132 */
REAL_define_syscall(vfork,0)

/* minilib/include/lseek.h, line: 19 */
REAL_define_syscall(lseek,3,unsigned int a1,  int a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 157 */
REAL_define_syscall_noopt(execveat,5, int a1,  const char *a2,   char* const* a3,  char* const* a4,  int a5) 

/* minilib/include/syscall_stubs.h, line: 162 */
REAL_define_syscall(fcntl,3, unsigned int a1,  unsigned int a2,  unsigned long a3) 

/* minilib/include/syscall_stubs.h, line: 160 */
REAL_define_syscall_noopt(wait4,4, pid_t a1,   int *a2,   int a3,   struct rusage *a4) 

#ifdef mini_syscalls

// minilib/include/syscalls_x64.h, line: 95
// SYSDEF_syscall(_recvfrom,6, int fd,  void *ubuf,  size_t size,  unsigned flags,  struct sockaddr *addr,  int *addr_len)
SYSREAL_define_syscall_noopt(_recvfrom,6, int a1,   void *a2,   size_t a3,   unsigned a4,   struct sockaddr *a5,   int *a6) 

// minilib/include/syscalls_x64.h, line: 487
// SYSDEF_syscall(_migrate_pages,4, pid_t pid,  unsigned long maxnode,  const unsigned long *old_nodes,  const unsigned long *new_nodes)
SYSREAL_define_syscall_noopt(_migrate_pages,4, pid_t a1,   unsigned long a2,   const unsigned long *a3,   const unsigned long *a4) 

// minilib/include/syscalls_x64.h, line: 613
// SYSDEF_syscall(_memfd_create,2, const char  *uname_ptr,  unsigned int flags)
SYSREAL_define_syscall(_memfd_create,2, const char  *a1,   unsigned int a2) 

// minilib/include/syscalls_x64.h, line: 499
// SYSDEF_syscall(_newfstatat,4, int dfd,  const char *filename,  struct stat *statbuf,  int flag)
SYSREAL_define_syscall_noopt(_newfstatat,4, int a1,   const char *a2,   struct stat *a3,   int a4) 

// minilib/include/syscalls_x64.h, line: 81
// SYSDEF_syscall(_setitimer,3, int which,  struct itimerval *value,  struct itimerval *ovalue)
SYSREAL_define_syscall(_setitimer,3, int a1,   struct itimerval *a2,   struct itimerval *a3) 

// minilib/include/syscalls_x64.h, line: 381
// SYSDEF_syscall(_lremovexattr,2, const char *pathname,  const char *name)
SYSREAL_define_syscall(_lremovexattr,2, const char *a1,   const char *a2) 

// minilib/include/syscalls_x64.h, line: 13
// SYSDEF_syscall(_stat,2, const char *filename,  struct stat *statbuf)
SYSREAL_define_syscall(_stat,2, const char *a1,   struct stat *a2) 

// minilib/include/syscalls_x64.h, line: 249
// SYSDEF_syscall(_setfsuid,1, uid_t uid)
SYSREAL_define_syscall(_setfsuid,1, uid_t a1) 

// minilib/include/syscalls_x64.h, line: 569
// SYSDEF_syscall(_rt_tgsigqueueinfo,4, pid_t tgid,  pid_t pid,  int sig,  siginfo_t *uinfo)
SYSREAL_define_syscall_noopt(_rt_tgsigqueueinfo,4, pid_t a1,   pid_t a2,   int a3,   siginfo_t *a4) 

// minilib/include/syscalls_x64.h, line: 239
// SYSDEF_syscall(_setresuid,3, uid_t *ruid,  uid_t *euid,  uid_t *suid)
SYSREAL_define_syscall(_setresuid,3, uid_t *a1,   uid_t *a2,   uid_t *a3) 

// minilib/include/syscalls_x64.h, line: 305
// SYSDEF_syscall(_mlockall,1, int flags)
SYSREAL_define_syscall(_mlockall,1, int a1) 

// minilib/include/syscalls_x64.h, line: 33
// SYSDEF_syscall(_rt_sigprocmask,4, int how,  sigset_t *nset,  sigset_t *oset,  size_t sigsetsize)
SYSREAL_define_syscall_noopt(_rt_sigprocmask,4, int a1,   sigset_t *a2,   sigset_t *a3,   size_t a4) 

// minilib/include/syscalls_x64.h, line: 89
// SYSDEF_syscall(_connect,3, int fd,  struct sockaddr *uservaddr,  int addrlen)
SYSREAL_define_syscall(_connect,3, int a1,   struct sockaddr *a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 319
// SYSDEF_syscall(_arch_prctl,3, struct task_struct *task,  int code,  unsigned long *addr)
SYSREAL_define_syscall(_arch_prctl,3, struct task_struct *a1,   int a2,   unsigned long *a3) 

// minilib/include/syscalls_x64.h, line: 439
// SYSDEF_syscall(_exit_group,1, int error_code)
SYSREAL_define_syscall(_exit_group,1, int a1) 

// minilib/include/syscalls_x64.h, line: 99
// SYSDEF_syscall(_recvmsg,3, int fd,  struct msghdr *msg,  unsigned int flags)
SYSREAL_define_syscall(_recvmsg,3, int a1,   struct msghdr *a2,   unsigned int a3) 

// minilib/include/syscalls_x64.h, line: 203
// SYSDEF_syscall(_sysinfo,1, struct sysinfo *info)
SYSREAL_define_syscall(_sysinfo,1, struct sysinfo *a1) 

// minilib/include/syscalls_x64.h, line: 121
// SYSDEF_syscall(_vfork,0)
SYSREAL_define_syscall(_vfork,0)

// minilib/include/syscalls_x64.h, line: 391
// SYSDEF_syscall(_sched_setaffinity,3, pid_t pid,  unsigned int len,  unsigned long *user_mask_ptr)
SYSREAL_define_syscall(_sched_setaffinity,3, pid_t a1,   unsigned int a2,   unsigned long *a3) 

// minilib/include/syscalls_x64.h, line: 145
// SYSDEF_syscall(_msgrcv,5, int msqid,  struct msgbuf *msgp,  size_t msgsz,  long msgtyp,  int msgflg)
SYSREAL_define_syscall_noopt(_msgrcv,5, int a1,   struct msgbuf *a2,   size_t a3,   long a4,   int a5) 

// minilib/include/syscalls_x64.h, line: 327
// SYSDEF_syscall(_sync,0)
SYSREAL_define_syscall(_sync,0)

// minilib/include/syscalls_x64.h, line: 427
// SYSDEF_syscall(_timer_getoverrun,1, timer_t timer_id)
SYSREAL_define_syscall(_timer_getoverrun,1, timer_t a1) 

// minilib/include/syscalls_x64.h, line: 605
// SYSDEF_syscall(_sched_getattr,4, pid_t pid,  struct sched_attr  *attr,  unsigned int size,  unsigned int flags)
SYSREAL_define_syscall_noopt(_sched_getattr,4, pid_t a1,   struct sched_attr  *a2,   unsigned int a3,   unsigned int a4) 

// minilib/include/syscalls_x64.h, line: 525
// SYSDEF_syscall(_splice,6, int fd_in,  loff_t *off_in,  int fd_out,  loff_t *off_out, size_t len,  unsigned int flags)
SYSREAL_define_syscall_noopt(_splice,6, int a1,   loff_t *a2,   int a3,   loff_t *a4,  size_t a5,   unsigned int a6) 

// minilib/include/syscalls_x64.h, line: 245
// SYSDEF_syscall(_getresgid,3, gid_t *rgid,  gid_t *egid,  gid_t *sgid)
SYSREAL_define_syscall(_getresgid,3, gid_t *a1,   gid_t *a2,   gid_t *a3) 

// minilib/include/syscalls_x64.h, line: 261
// SYSDEF_syscall(_rt_sigtimedwait,4, const sigset_t *uthese,  siginfo_t *uinfo,  const struct timespec *uts,  size_t sigsetsize)
SYSREAL_define_syscall_noopt(_rt_sigtimedwait,4, const sigset_t *a1,   siginfo_t *a2,   const struct timespec *a3,   size_t a4) 

// minilib/include/syscalls_x64.h, line: 39
// SYSDEF_syscall(_pread64,4, unsigned long fd,  char *buf,  size_t count,  loff_t pos)
SYSREAL_define_syscall_noopt(_pread64,4, unsigned long a1,   char *a2,   size_t a3,   loff_t a4) 

// minilib/include/syscalls_x64.h, line: 517
// SYSDEF_syscall(_ppoll,5, struct pollfd *ufds,  unsigned int nfds,  struct timespec *tsp,  const sigset_t *sigmask,  size_t sigsetsize)
SYSREAL_define_syscall_noopt(_ppoll,5, struct pollfd *a1,   unsigned int a2,   struct timespec *a3,   const sigset_t *a4,   size_t a5) 

// minilib/include/syscalls_x64.h, line: 169
// SYSDEF_syscall(_rename,2, const char *oldname,  const char *newname)
SYSREAL_define_syscall(_rename,2, const char *a1,   const char *a2) 

// minilib/include/syscalls_x64.h, line: 477
// SYSDEF_syscall(_ioprio_set,3, int which,  int who,  int ioprio)
SYSREAL_define_syscall(_ioprio_set,3, int a1,   int a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 35
// SYSDEF_syscall(_rt_sigreturn,1, unsigned long __unused)
SYSREAL_define_syscall(_rt_sigreturn,1, unsigned long a1) 

// minilib/include/syscalls_x64.h, line: 367
// SYSDEF_syscall(_getxattr,4, const char *pathname,  const char *name,  void *value,  size_t size)
SYSREAL_define_syscall_noopt(_getxattr,4, const char *a1,   const char *a2,   void *a3,   size_t a4) 

// minilib/include/syscalls_x64.h, line: 151
// SYSDEF_syscall(_flock,2, unsigned int fd,  unsigned int cmd)
SYSREAL_define_syscall(_flock,2, unsigned int a1,   unsigned int a2) 

// minilib/include/syscalls_x64.h, line: 469
// SYSDEF_syscall(_waitid,5, int which,  pid_t upid,  struct siginfo *infop,  int options,  struct rusage *ru)
SYSREAL_define_syscall_noopt(_waitid,5, int a1,   pid_t a2,   struct siginfo *a3,   int a4,   struct rusage *a5) 

// minilib/include/syscalls_x64.h, line: 571
// SYSDEF_syscall(_perf_event_open,5, struct perf_event_attr *attr_uptr,  pid_t pid,  int cpu,  int group_fd,  unsigned long flags)
SYSREAL_define_syscall_noopt(_perf_event_open,5, struct perf_event_attr *a1,   pid_t a2,   int a3,   int a4,   unsigned long a5) 

// minilib/include/syscalls_x64.h, line: 473
// SYSDEF_syscall(_request_key,4, const char *_type,  const char *_description,  const char *_callout_info,  key_serial_t destringid)
SYSREAL_define_syscall_noopt(_request_key,4, const char *a1,   const char *a2,   const char *a3,   key_serial_t a4) 

// minilib/include/syscalls_x64.h, line: 455
// SYSDEF_syscall(_mq_open,4, const char *u_name,  int oflag,  mode_t mode,  struct mq_attr *u_attr)
SYSREAL_define_syscall_noopt(_mq_open,4, const char *a1,   int a2,   mode_t a3,   struct mq_attr *a4) 

// minilib/include/syscalls_x64.h, line: 593
// SYSDEF_syscall(_getcpu,3, unsigned *cpup,  unsigned *nodep,  struct getcpu_cache *unused)
SYSREAL_define_syscall(_getcpu,3, unsigned *a1,   unsigned *a2,   struct getcpu_cache *a3) 

// minilib/include/syscalls_x64.h, line: 237
// SYSDEF_syscall(_setgroups,2, int gidsetsize,  gid_t *grouplist)
SYSREAL_define_syscall(_setgroups,2, int a1,   gid_t *a2) 

// minilib/include/syscalls_x64.h, line: 149
// SYSDEF_syscall(_fcntl,3, unsigned int fd,  unsigned int cmd,  unsigned long arg)
SYSREAL_define_syscall(_fcntl,3, unsigned int a1,   unsigned int a2,   unsigned long a3) 

// minilib/include/syscalls_x64.h, line: 555
// SYSDEF_syscall(_eventfd2,2, unsigned int count,  int flags)
SYSREAL_define_syscall(_eventfd2,2, unsigned int a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 337
// SYSDEF_syscall(_swapon,2, const char *specialfile,  int swap_flags)
SYSREAL_define_syscall(_swapon,2, const char *a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 523
// SYSDEF_syscall(_get_robust_list,3, int pid,  struct robust_list_head **head_ptr,  size_t *len_ptr)
SYSREAL_define_syscall(_get_robust_list,3, int a1,   struct robust_list_head **a2,   size_t *a3) 

// minilib/include/syscalls_x64.h, line: 135
// SYSDEF_syscall(_semop,3, int semid,  struct sembuf *tsops,  unsigned nsops)
SYSREAL_define_syscall(_semop,3, int a1,   struct sembuf *a2,   unsigned a3) 

// minilib/include/syscalls_x64.h, line: 163
// SYSDEF_syscall(_getcwd,2, char *buf,  unsigned long size)
SYSREAL_define_syscall(_getcwd,2, char *a1,   unsigned long a2) 

// minilib/include/syscalls_x64.h, line: 87
// SYSDEF_syscall(_socket,3, int family,  int type,  int protocol)
SYSREAL_define_syscall(_socket,3, int a1,   int a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 515
// SYSDEF_syscall(_pselect6,6, int n,  fd_set *inp,  fd_set *outp,  fd_set *exp,  struct timespec *tsp,  void *sig)
SYSREAL_define_syscall_noopt(_pselect6,6, int a1,   fd_set *a2,   fd_set *a3,   fd_set *a4,   struct timespec *a5,   void *a6) 

// minilib/include/syscalls_x64.h, line: 457
// SYSDEF_syscall(_mq_unlink,1, const char *u_name)
SYSREAL_define_syscall(_mq_unlink,1, const char *a1) 

// minilib/include/syscalls_x64.h, line: 507
// SYSDEF_syscall(_symlinkat,3, const char *oldname,  int newfd,  const char *newname)
SYSREAL_define_syscall(_symlinkat,3, const char *a1,   int a2,   const char *a3) 

// minilib/include/syscalls_x64.h, line: 389
// SYSDEF_syscall(_futex,6, u32 *uaddr,  int op,  u32 val,  struct timespec *utime,  u32 *uaddr2,  u32 val3)
SYSREAL_define_syscall_noopt(_futex,6, u32 *a1,   int a2,   u32 a3,   struct timespec *a4,   u32 *a5,   u32 a6) 

// minilib/include/syscalls_x64.h, line: 63
// SYSDEF_syscall(_shmget,3, key_t key,  size_t size,  int shmflg)
SYSREAL_define_syscall(_shmget,3, key_t a1,   size_t a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 253
// SYSDEF_syscall(_getsid,1, pid_t pid)
SYSREAL_define_syscall(_getsid,1, pid_t a1) 

// minilib/include/syscalls_x64.h, line: 223
// SYSDEF_syscall(_setpgid,2, pid_t pid,  pid_t pgid)
SYSREAL_define_syscall(_setpgid,2, pid_t a1,   pid_t a2) 

// minilib/include/syscalls_x64.h, line: 345
// SYSDEF_syscall(_setdomainname,2, char *name,  int len)
SYSREAL_define_syscall(_setdomainname,2, char *a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 155
// SYSDEF_syscall(_fdatasync,1, unsigned int fd)
SYSREAL_define_syscall(_fdatasync,1, unsigned int a1) 

// minilib/include/syscalls_x64.h, line: 101
// SYSDEF_syscall(_shutdown,2, int fd,  int how)
SYSREAL_define_syscall(_shutdown,2, int a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 561
// SYSDEF_syscall(_pipe2,2, int *filedes,  int flags)
SYSREAL_define_syscall(_pipe2,2, int *a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 403
// SYSDEF_syscall(_io_cancel,3, aio_context_t ctx_id,  struct iocb *iocb,  struct io_event *result)
SYSREAL_define_syscall(_io_cancel,3, aio_context_t a1,   struct iocb *a2,   struct io_event *a3) 

// minilib/include/syscalls_x64.h, line: 45
// SYSDEF_syscall(_writev,3, unsigned long fd,  const struct iovec *vec,  unsigned long vlen)
SYSREAL_define_syscall(_writev,3, unsigned long a1,   const struct iovec *a2,   unsigned long a3) 

// minilib/include/syscalls_x64.h, line: 21
// SYSDEF_syscall(_lseek,3, unsigned int fd,  off_t offset,  unsigned int origin)
SYSREAL_define_syscall(_lseek,3, unsigned int a1,   off_t a2,   unsigned int a3) 

// minilib/include/syscalls_x64.h, line: 301
// SYSDEF_syscall(_mlock,2, unsigned long start,  size_t len)
SYSREAL_define_syscall(_mlock,2, unsigned long a1,   size_t a2) 

// minilib/include/syscalls_x64.h, line: 311
// SYSDEF_syscall(_modify_ldt,3, int func,  void *ptr,  unsigned long bytecount)
SYSREAL_define_syscall(_modify_ldt,3, int a1,   void *a2,   unsigned long a3) 

// minilib/include/syscalls_x64.h, line: 303
// SYSDEF_syscall(_munlock,2, unsigned long start,  size_t len)
SYSREAL_define_syscall(_munlock,2, unsigned long a1,   size_t a2) 

// minilib/include/syscalls_x64.h, line: 543
// SYSDEF_syscall(_eventfd,1, unsigned int count)
SYSREAL_define_syscall(_eventfd,1, unsigned int a1) 

// minilib/include/syscalls_x64.h, line: 577
// SYSDEF_syscall(_fanotify_mark,5, long fanotify_fd,  long flags,  __u64 mask,  long dfd, long pathname)
SYSREAL_define_syscall_noopt(_fanotify_mark,5, long a1,   long a2,   __u64 a3,   long a4,  long a5) 

// minilib/include/syscalls_x64.h, line: 601
// SYSDEF_syscall(_finit_module,3, int fd,  const char  *uargs,  int flags)
SYSREAL_define_syscall(_finit_module,3, int a1,   const char  *a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 459
// SYSDEF_syscall(_mq_timedsend,5, mqd_t mqdes,  const char *u_msg_ptr,  size_t msg_len,  unsigned int msg_prio,  const struct timespec *u_abs_timeout)
SYSREAL_define_syscall_noopt(_mq_timedsend,5, mqd_t a1,   const char *a2,   size_t a3,   unsigned int a4,   const struct timespec *a5) 

// minilib/include/syscalls_x64.h, line: 365
// SYSDEF_syscall(_fsetxattr,5, int fd,  const char *name,  const void *value,  size_t size, int flags)
SYSREAL_define_syscall_noopt(_fsetxattr,5, int a1,   const char *a2,   const void *a3,   size_t a4,  int a5) 

// minilib/include/syscalls_x64.h, line: 15
// SYSDEF_syscall(_fstat,2, unsigned int fd,  struct stat *statbuf)
SYSREAL_define_syscall(_fstat,2, unsigned int a1,   struct stat *a2) 

// minilib/include/syscalls_x64.h, line: 495
// SYSDEF_syscall(_fchownat,5, int dfd,  const char *filename,  uid_t user,  gid_t group,  int flag)
SYSREAL_define_syscall_noopt(_fchownat,5, int a1,   const char *a2,   uid_t a3,   gid_t a4,   int a5) 

// minilib/include/syscalls_x64.h, line: 533
// SYSDEF_syscall(_move_pages,6, pid_t pid,  unsigned long nr_pages,  const void *pages[], const int *nodes,  int *status,  int flags)
SYSREAL_define_syscall_noopt(_move_pages,6, pid_t a1,   unsigned long a2,   const void *a3,  const int *a4,   int *a5,   int a6) 

// minilib/include/syscalls_x64.h, line: 173
// SYSDEF_syscall(_rmdir,1, const char *pathname)
SYSREAL_define_syscall(_rmdir,1, const char *a1) 

// minilib/include/syscalls_x64.h, line: 157
// SYSDEF_syscall(_truncate,2, const char *path,  long length)
SYSREAL_define_syscall(_truncate,2, const char *a1,   long a2) 

// minilib/include/syscalls_x64.h, line: 483
// SYSDEF_syscall(_inotify_add_watch,3, int fd,  const char *pathname,  u32 mask)
SYSREAL_define_syscall(_inotify_add_watch,3, int a1,   const char *a2,   u32 a3) 

// minilib/include/syscalls_x64.h, line: 37
// SYSDEF_syscall(_ioctl,3, unsigned int fd,  unsigned int cmd,  unsigned long arg)
SYSREAL_define_syscall(_ioctl,3, unsigned int a1,   unsigned int a2,   unsigned long a3) 

// minilib/include/syscalls_x64.h, line: 213
// SYSDEF_syscall(_getgid,0)
SYSREAL_define_syscall(_getgid,0)

// minilib/include/syscalls_x64.h, line: 263
// SYSDEF_syscall(_rt_sigqueueinfo,3, pid_t pid,  int sig,  siginfo_t *uinfo)
SYSREAL_define_syscall(_rt_sigqueueinfo,3, pid_t a1,   int a2,   siginfo_t *a3) 

// minilib/include/syscalls_x64.h, line: 481
// SYSDEF_syscall(_inotify_init,0)
SYSREAL_define_syscall(_inotify_init,0)

// minilib/include/syscalls_x64.h, line: 575
// SYSDEF_syscall(_fanotify_init,2, unsigned int flags,  unsigned int event_f_flags)
SYSREAL_define_syscall(_fanotify_init,2, unsigned int a1,   unsigned int a2) 

// minilib/include/syscalls_x64.h, line: 597
// SYSDEF_syscall(_process_vm_writev,6, pid_t pid,  const struct iovec *lvec,  unsigned long liovcnt,  const struct iovcc *rvec,  unsigned long riovcnt,  unsigned long flags)
SYSREAL_define_syscall_noopt(_process_vm_writev,6, pid_t a1,   const struct iovec *a2,   unsigned long a3,   const struct iovcc *a4,   unsigned long a5,   unsigned long a6) 

// minilib/include/syscalls_x64.h, line: 437
// SYSDEF_syscall(_clock_nanosleep,4, const clockid_t which_clock,  int flags,  const struct timespec *rqtp,  struct timespec *rmtp)
SYSREAL_define_syscall_noopt(_clock_nanosleep,4, const clockid_t a1,   int a2,   const struct timespec *a3,   struct timespec *a4) 

// minilib/include/syscalls_x64.h, line: 351
// SYSDEF_syscall(_init_module,3, void *umod,  unsigned long len,  const char *uargs)
SYSREAL_define_syscall(_init_module,3, void *a1,   unsigned long a2,   const char *a3) 

// minilib/include/syscalls_x64.h, line: 9
// SYSDEF_syscall(_open,3, const char *filename,  int flags,  int mode)
SYSREAL_define_syscall(_open,3, const char *a1,   int a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 141
// SYSDEF_syscall(_msgget,2, key_t key,  int msgflg)
SYSREAL_define_syscall(_msgget,2, key_t a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 375
// SYSDEF_syscall(_llistxattr,3, const char *pathname,  char *list,  size_t size)
SYSREAL_define_syscall(_llistxattr,3, const char *a1,   char *a2,   size_t a3) 

// minilib/include/syscalls_x64.h, line: 53
// SYSDEF_syscall(_sched_yield,0)
SYSREAL_define_syscall(_sched_yield,0)

// minilib/include/syscalls_x64.h, line: 413
// SYSDEF_syscall(_set_tid_address,1, int *tidptr)
SYSREAL_define_syscall(_set_tid_address,1, int *a1) 

// minilib/include/syscalls_x64.h, line: 287
// SYSDEF_syscall(_sched_setparam,2, pid_t pid,  struct sched_param *param)
SYSREAL_define_syscall(_sched_setparam,2, pid_t a1,   struct sched_param *a2) 

// minilib/include/syscalls_x64.h, line: 117
// SYSDEF_syscall(_clone,4, unsigned long clone_flags,  unsigned long newsp,  void *parent_tid,  void *child_tid)
SYSREAL_define_syscall_noopt(_clone,4, unsigned long a1,   unsigned long a2,   void *a3,   void *a4) 

// minilib/include/syscalls_x64.h, line: 143
// SYSDEF_syscall(_msgsnd,4, int msqid,  struct msgbuf *msgp,  size_t msgsz,  int msgflg)
SYSREAL_define_syscall_noopt(_msgsnd,4, int a1,   struct msgbuf *a2,   size_t a3,   int a4) 

// minilib/include/syscalls_x64.h, line: 453
// SYSDEF_syscall(_get_mempolicy,5, int *policy,  unsigned long *nmask,  unsigned long maxnode,  unsigned long addr,  unsigned long flags)
SYSREAL_define_syscall_noopt(_get_mempolicy,5, int *a1,   unsigned long *a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

// minilib/include/syscalls_x64.h, line: 185
// SYSDEF_syscall(_chmod,2, const char *filename,  mode_t mode)
SYSREAL_define_syscall(_chmod,2, const char *a1,   mode_t a2) 

// minilib/include/syscalls_x64.h, line: 475
// SYSDEF_syscall(_keyctl,5, int option,  unsigned long arg2,  unsigned long arg3,  unsigned long arg4,  unsigned long arg5)
SYSREAL_define_syscall_noopt(_keyctl,5, int a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

// minilib/include/syscalls_x64.h, line: 425
// SYSDEF_syscall(_timer_gettime,2, timer_t timer_id,  struct itimerspec *setting)
SYSREAL_define_syscall(_timer_gettime,2, timer_t a1,   struct itimerspec *a2) 

// minilib/include/syscalls_x64.h, line: 5
// SYSDEF_syscall(_read,3, unsigned int fd,  char *buf,  size_t count)
SYSREAL_define_syscall(_read,3, unsigned int a1,   char *a2,   size_t a3) 

// minilib/include/syscalls_x64.h, line: 83
// SYSDEF_syscall(_getpid,0)
SYSREAL_define_syscall(_getpid,0)

// minilib/include/syscalls_x64.h, line: 587
// SYSDEF_syscall(_syncfs,1, int fd)
SYSREAL_define_syscall(_syncfs,1, int a1) 

// minilib/include/syscalls_x64.h, line: 559
// SYSDEF_syscall(_dup3,3, unsigned int oldfd,  unsigned int newfd,  int flags)
SYSREAL_define_syscall(_dup3,3, unsigned int a1,   unsigned int a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 589
// SYSDEF_syscall(_sendmmsg,4, int fd,  struct mmsghdr *mmsg,  unsigned int vlen,  unsigned int flags)
SYSREAL_define_syscall_noopt(_sendmmsg,4, int a1,   struct mmsghdr *a2,   unsigned int a3,   unsigned int a4) 

// minilib/include/syscalls_x64.h, line: 177
// SYSDEF_syscall(_link,2, const char *oldname,  const char *newname)
SYSREAL_define_syscall(_link,2, const char *a1,   const char *a2) 

// minilib/include/syscalls_x64.h, line: 447
// SYSDEF_syscall(_utimes,2, char *filename,  struct timeval *utimes)
SYSREAL_define_syscall(_utimes,2, char *a1,   struct timeval *a2) 

// minilib/include/syscalls_x64.h, line: 267
// SYSDEF_syscall(_sigaltstack,2, const stack_t *uss,  stack_t *uoss)
SYSREAL_define_syscall(_sigaltstack,2, const stack_t *a1,   stack_t *a2) 

// minilib/include/syscalls_x64.h, line: 193
// SYSDEF_syscall(_lchown,3, const char *filename,  uid_t user,  gid_t group)
SYSREAL_define_syscall(_lchown,3, const char *a1,   uid_t a2,   gid_t a3) 

// minilib/include/syscalls_x64.h, line: 209
// SYSDEF_syscall(_getuid,0)
SYSREAL_define_syscall(_getuid,0)

// minilib/include/syscalls_x64.h, line: 277
// SYSDEF_syscall(_statfs,2, const char *pathname,  struct statfs *buf)
SYSREAL_define_syscall(_statfs,2, const char *a1,   struct statfs *a2) 

// minilib/include/syscalls_x64.h, line: 115
// SYSDEF_syscall(_getsockopt,5, int fd,  int level,  int optname,  char *optval,  int *optlen)
SYSREAL_define_syscall_noopt(_getsockopt,5, int a1,   int a2,   int a3,   char *a4,   int *a5) 

// minilib/include/syscalls_x64.h, line: 333
// SYSDEF_syscall(_mount,5, char *dev_name,  char *dir_name,  char *type,  unsigned long flags,  void *data)
SYSREAL_define_syscall_noopt(_mount,5, char *a1,   char *a2,   char *a3,   unsigned long a4,   void *a5) 

// minilib/include/syscalls_x64.h, line: 285
// SYSDEF_syscall(_setpriority,3, int which,  int who,  int niceval)
SYSREAL_define_syscall(_setpriority,3, int a1,   int a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 69
// SYSDEF_syscall(_dup,1, unsigned int fildes)
SYSREAL_define_syscall(_dup,1, unsigned int a1) 

// minilib/include/syscalls_x64.h, line: 111
// SYSDEF_syscall(_socketpair,4, int family,  int type,  int protocol,  int *usockvec)
SYSREAL_define_syscall_noopt(_socketpair,4, int a1,   int a2,   int a3,   int *a4) 

// minilib/include/syscalls_x64.h, line: 75
// SYSDEF_syscall(_nanosleep,2, struct timespec *rqtp,  struct timespec *rmtp)
SYSREAL_define_syscall(_nanosleep,2, struct timespec *a1,   struct timespec *a2) 

// minilib/include/syscalls_x64.h, line: 19
// SYSDEF_syscall(_poll,3, struct poll_fd *ufds,  unsigned int nfds,  long timeout_msecs)
SYSREAL_define_syscall(_poll,3, struct poll_fd *a1,   unsigned int a2,   long a3) 

// minilib/include/syscalls_x64.h, line: 23
// SYSDEF_syscall(_mmap,6, unsigned long addr,  unsigned long len,  unsigned long prot,  unsigned long flags,  unsigned long fd,  unsigned long off)
SYSREAL_define_syscall_noopt(_mmap,6, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5,   unsigned long a6) 

// minilib/include/syscalls_x64.h, line: 369
// SYSDEF_syscall(_lgetxattr,4, const char *pathname,  const char *name,  void *value,  size_t size)
SYSREAL_define_syscall_noopt(_lgetxattr,4, const char *a1,   const char *a2,   void *a3,   size_t a4) 

// minilib/include/syscalls_x64.h, line: 529
// SYSDEF_syscall(_sync_file_range,4, long fd,  loff_t offset,  loff_t bytes,  long flags)
SYSREAL_define_syscall_noopt(_sync_file_range,4, long a1,   loff_t a2,   loff_t a3,   long a4) 

// minilib/include/syscalls_x64.h, line: 231
// SYSDEF_syscall(_setreuid,2, uid_t ruid,  uid_t euid)
SYSREAL_define_syscall(_setreuid,2, uid_t a1,   uid_t a2) 

// minilib/include/syscalls_x64.h, line: 127
// SYSDEF_syscall(_wait4,4, pid_t upid,  int *stat_addr,  int options,  struct rusage *ru)
SYSREAL_define_syscall_noopt(_wait4,4, pid_t a1,   int *a2,   int a3,   struct rusage *a4) 

// minilib/include/syscalls_x64.h, line: 129
// SYSDEF_syscall(_kill,2, pid_t pid,  int sig)
SYSREAL_define_syscall(_kill,2, pid_t a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 189
// SYSDEF_syscall(_chown,3, const char *filename,  uid_t user,  gid_t group)
SYSREAL_define_syscall(_chown,3, const char *a1,   uid_t a2,   gid_t a3) 

// minilib/include/syscalls_x64.h, line: 373
// SYSDEF_syscall(_listxattr,3, const char *pathname,  char *list,  size_t size)
SYSREAL_define_syscall(_listxattr,3, const char *a1,   char *a2,   size_t a3) 

// minilib/include/syscalls_x64.h, line: 419
// SYSDEF_syscall(_fadvise64,4, int fd,  loff_t offset,  size_t len,  int advice)
SYSREAL_define_syscall_noopt(_fadvise64,4, int a1,   loff_t a2,   size_t a3,   int a4) 

// minilib/include/syscalls_x64.h, line: 429
// SYSDEF_syscall(_timer_delete,1, timer_t timer_id)
SYSREAL_define_syscall(_timer_delete,1, timer_t a1) 

// minilib/include/syscalls_x64.h, line: 279
// SYSDEF_syscall(_fstatfs,2, unsigned int fd,  struct statfs *buf)
SYSREAL_define_syscall(_fstatfs,2, unsigned int a1,   struct statfs *a2) 

// minilib/include/syscalls_x64.h, line: 137
// SYSDEF_syscall(_semctl,4, int semid,  int semnum,  int cmd,  semun_u arg)
SYSREAL_define_syscall_noopt(_semctl,4, int a1,   int a2,   int a3,   semun_u a4) 

// minilib/include/syscalls_x64.h, line: 31
// SYSDEF_syscall(_rt_sigaction,4, int sig,  const struct sigaction *act,  struct sigaction *oact,  size_t sigsetsize)
SYSREAL_define_syscall_noopt(_rt_sigaction,4, int a1,   const struct sigaction *a2,   struct sigaction *a3,   size_t a4) 

// minilib/include/syscalls_x64.h, line: 291
// SYSDEF_syscall(_sched_setscheduler,3, pid_t pid,  int policy,  struct sched_param *param)
SYSREAL_define_syscall(_sched_setscheduler,3, pid_t a1,   int a2,   struct sched_param *a3) 

// minilib/include/syscalls_x64.h, line: 11
// SYSDEF_syscall(_close,1, unsigned int fd)
SYSREAL_define_syscall(_close,1, unsigned int a1) 

// minilib/include/syscalls_x64.h, line: 359
// SYSDEF_syscall(_readahead,3, int fd,  loff_t offset,  size_t count)
SYSREAL_define_syscall(_readahead,3, int a1,   loff_t a2,   size_t a3) 

// minilib/include/syscalls_x64.h, line: 85
// SYSDEF_syscall(_sendfile,4, int out_fd,  int in_fd,  off_t *offset,  size_t count)
SYSREAL_define_syscall_noopt(_sendfile,4, int a1,   int a2,   off_t *a3,   size_t a4) 

// minilib/include/syscalls_x64.h, line: 541
// SYSDEF_syscall(_timerfd_create,2, int clockid,  int flags)
SYSREAL_define_syscall(_timerfd_create,2, int a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 309
// SYSDEF_syscall(_vhangup,0)
SYSREAL_define_syscall(_vhangup,0)

// minilib/include/syscalls_x64.h, line: 105
// SYSDEF_syscall(_listen,2, int fd,  int backlog)
SYSREAL_define_syscall(_listen,2, int a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 415
// SYSDEF_syscall(_restart_syscall,0)
SYSREAL_define_syscall(_restart_syscall,0)

// minilib/include/syscalls_x64.h, line: 513
// SYSDEF_syscall(_faccessat,3, int dfd,  const char *filename,  int mode)
SYSREAL_define_syscall(_faccessat,3, int a1,   const char *a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 103
// SYSDEF_syscall(_bind,3, int fd,  struct sockaddr *umyaddr,  int addrlen)
SYSREAL_define_syscall(_bind,3, int a1,   struct sockaddr *a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 585
// SYSDEF_syscall(_clock_adjtime,2, clockid_t which_clock,  struct timex *tx)
SYSREAL_define_syscall(_clock_adjtime,2, clockid_t a1,   struct timex *a2) 

// minilib/include/syscalls_x64.h, line: 441
// SYSDEF_syscall(_epoll_wait,4, int epfd,  struct epoll_event *events,  int maxevents,  int timeout)
SYSREAL_define_syscall_noopt(_epoll_wait,4, int a1,   struct epoll_event *a2,   int a3,   int a4) 

// minilib/include/syscalls_x64.h, line: 511
// SYSDEF_syscall(_fchmodat,3, int dfd,  const char *filename,  mode_t mode)
SYSREAL_define_syscall(_fchmodat,3, int a1,   const char *a2,   mode_t a3) 

// minilib/include/syscalls_x64.h, line: 197
// SYSDEF_syscall(_gettimeofday,2, struct timeval *tv,  struct timezone *tz)
SYSREAL_define_syscall(_gettimeofday,2, struct timeval *a1,   struct timezone *a2) 

// minilib/include/syscalls_x64.h, line: 595
// SYSDEF_syscall(_process_vm_readv,6, pid_t pid,  const struct iovec *lvec,  unsigned long liovcnt,  const struct iovec *rvec,  unsigned long riovcnt,  unsigned long flags)
SYSREAL_define_syscall_noopt(_process_vm_readv,6, pid_t a1,   const struct iovec *a2,   unsigned long a3,   const struct iovec *a4,   unsigned long a5,   unsigned long a6) 

// minilib/include/syscalls_x64.h, line: 431
// SYSDEF_syscall(_clock_settime,2, const clockid_t which_clock,  const struct timespec *tp)
SYSREAL_define_syscall(_clock_settime,2, const clockid_t a1,   const struct timespec *a2) 

// minilib/include/syscalls_x64.h, line: 385
// SYSDEF_syscall(_tkill,2, pid_t pid,  int sig)
SYSREAL_define_syscall(_tkill,2, pid_t a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 257
// SYSDEF_syscall(_capset,2, cap_user_header_t header,  const cap_user_data_t data)
SYSREAL_define_syscall(_capset,2, cap_user_header_t a1,   const cap_user_data_t a2) 

// minilib/include/syscalls_x64.h, line: 73
// SYSDEF_syscall(_pause,0)
SYSREAL_define_syscall(_pause,0)

// minilib/include/syscalls_x64.h, line: 407
// SYSDEF_syscall(_epoll_create,1, int size)
SYSREAL_define_syscall(_epoll_create,1, int a1) 

// minilib/include/syscalls_x64.h, line: 179
// SYSDEF_syscall(_unlink,1, const char *pathname)
SYSREAL_define_syscall(_unlink,1, const char *a1) 

// minilib/include/syscalls_x64.h, line: 323
// SYSDEF_syscall(_setrlimit,2, unsigned int resource,  struct rlimit *rlim)
SYSREAL_define_syscall(_setrlimit,2, unsigned int a1,   struct rlimit *a2) 

// minilib/include/syscalls_x64.h, line: 545
// SYSDEF_syscall(_fallocate,4, long fd,  long mode,  loff_t offset,  loff_t len)
SYSREAL_define_syscall_noopt(_fallocate,4, long a1,   long a2,   loff_t a3,   loff_t a4) 

// minilib/include/syscalls_x64.h, line: 227
// SYSDEF_syscall(_getpgrp,0)
SYSREAL_define_syscall(_getpgrp,0)

// minilib/include/syscalls_x64.h, line: 607
// SYSDEF_syscall(_renameat2,5, int olddfd,  const char  *oldname,  int newdfd,  const char  *newname,  unsigned int flags)
SYSREAL_define_syscall_noopt(_renameat2,5, int a1,   const char  *a2,   int a3,   const char  *a4,   unsigned int a5) 

// minilib/include/syscalls_x64.h, line: 167
// SYSDEF_syscall(_fchdir,1, unsigned int fd)
SYSREAL_define_syscall(_fchdir,1, unsigned int a1) 

// minilib/include/syscalls_x64.h, line: 195
// SYSDEF_syscall(_umask,1, int mask)
SYSREAL_define_syscall(_umask,1, int a1) 

// minilib/include/syscalls_x64.h, line: 119
// SYSDEF_syscall(_fork,0)
SYSREAL_define_syscall(_fork,0)

// minilib/include/syscalls_x64.h, line: 609
// SYSDEF_syscall(_seccomp,3, unsigned int op,  unsigned int flags,  const char  *uargs)
SYSREAL_define_syscall(_seccomp,3, unsigned int a1,   unsigned int a2,   const char  *a3) 

// minilib/include/syscalls_x64.h, line: 485
// SYSDEF_syscall(_inotify_rm_watch,2, int fd,  __s32 wd)
SYSREAL_define_syscall(_inotify_rm_watch,2, int a1,   __s32 a2) 

// minilib/include/syscalls_x64.h, line: 549
// SYSDEF_syscall(_timerfd_gettime,2, int ufd,  struct itimerspec *otmr)
SYSREAL_define_syscall(_timerfd_gettime,2, int a1,   struct itimerspec *a2) 

// minilib/include/syscalls_x64.h, line: 553
// SYSDEF_syscall(_signalfd4,4, int ufd,  sigset_t *user_mask,  size_t sizemask,  int flags)
SYSREAL_define_syscall_noopt(_signalfd4,4, int a1,   sigset_t *a2,   size_t a3,   int a4) 

// minilib/include/syscalls_x64.h, line: 139
// SYSDEF_syscall(_shmdt,1, char *shmaddr)
SYSREAL_define_syscall(_shmdt,1, char *a1) 

// minilib/include/syscalls_x64.h, line: 379
// SYSDEF_syscall(_removexattr,2, const char *pathname,  const char *name)
SYSREAL_define_syscall(_removexattr,2, const char *a1,   const char *a2) 

// minilib/include/syscalls_x64.h, line: 463
// SYSDEF_syscall(_mq_notify,2, mqd_t mqdes,  const struct sigevent *u_notification)
SYSREAL_define_syscall(_mq_notify,2, mqd_t a1,   const struct sigevent *a2) 

// minilib/include/syscalls_x64.h, line: 255
// SYSDEF_syscall(_capget,2, cap_user_header_t header,  cap_user_data_t dataptr)
SYSREAL_define_syscall(_capget,2, cap_user_header_t a1,   cap_user_data_t a2) 

// minilib/include/syscalls_x64.h, line: 133
// SYSDEF_syscall(_semget,3, key_t key,  int nsems,  int semflg)
SYSREAL_define_syscall(_semget,3, key_t a1,   int a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 343
// SYSDEF_syscall(_sethostname,2, char *name,  int len)
SYSREAL_define_syscall(_sethostname,2, char *a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 27
// SYSDEF_syscall(_munmap,2, unsigned long addr,  size_t len)
SYSREAL_define_syscall(_munmap,2, unsigned long a1,   size_t a2) 

// minilib/include/syscalls_x64.h, line: 47
// SYSDEF_syscall(_access,2, const char *filename,  int mode)
SYSREAL_define_syscall(_access,2, const char *a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 275
// SYSDEF_syscall(_ustat,2, unsigned dev,  struct ustat *ubuf)
SYSREAL_define_syscall(_ustat,2, unsigned a1,   struct ustat *a2) 

// minilib/include/syscalls_x64.h, line: 181
// SYSDEF_syscall(_symlink,2, const char *oldname,  const char *newname)
SYSREAL_define_syscall(_symlink,2, const char *a1,   const char *a2) 

// minilib/include/syscalls_x64.h, line: 395
// SYSDEF_syscall(_io_setup,2, unsigned nr_events,  aio_context_t *ctxp)
SYSREAL_define_syscall(_io_setup,2, unsigned a1,   aio_context_t *a2) 

// minilib/include/syscalls_x64.h, line: 299
// SYSDEF_syscall(_sched_rr_get_interval,2, pid_t pid,  struct timespec *interval)
SYSREAL_define_syscall(_sched_rr_get_interval,2, pid_t a1,   struct timespec *a2) 

// minilib/include/syscalls_x64.h, line: 339
// SYSDEF_syscall(_swapoff,1, const char *specialfile)
SYSREAL_define_syscall(_swapoff,1, const char *a1) 

// minilib/include/syscalls_x64.h, line: 357
// SYSDEF_syscall(_gettid,0)
SYSREAL_define_syscall(_gettid,0)

// minilib/include/syscalls_x64.h, line: 397
// SYSDEF_syscall(_io_destroy,1, aio_context_t ctx)
SYSREAL_define_syscall(_io_destroy,1, aio_context_t a1) 

// minilib/include/syscalls_x64.h, line: 537
// SYSDEF_syscall(_epoll_pwait,6, int epfd,  struct epoll_event *events,  int maxevents,  int timeout,  const sigset_t *sigmask,  size_t sigsetsize)
SYSREAL_define_syscall_noopt(_epoll_pwait,6, int a1,   struct epoll_event *a2,   int a3,   int a4,   const sigset_t *a5,   size_t a6) 

// minilib/include/syscalls_x64.h, line: 65
// SYSDEF_syscall(_shmat,3, int shmid,  char *shmaddr,  int shmflg)
SYSREAL_define_syscall(_shmat,3, int a1,   char *a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 211
// SYSDEF_syscall(_syslog,3, int type,  char *buf,  int len)
SYSREAL_define_syscall(_syslog,3, int a1,   char *a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 519
// SYSDEF_syscall(_unshare,1, unsigned long unshare_flags)
SYSREAL_define_syscall(_unshare,1, unsigned long a1) 

// minilib/include/syscalls_x64.h, line: 123
// SYSDEF_syscall(_execve,3, const char *filename,  const char *const argv[],  const char *const envp[])
SYSREAL_define_syscall(_execve,3, const char *a1,   const char *const a2,   const char *const a3) 

// minilib/include/syscalls_x64.h, line: 59
// SYSDEF_syscall(_mincore,3, unsigned long start,  size_t len,  unsigned char *vec)
SYSREAL_define_syscall(_mincore,3, unsigned long a1,   size_t a2,   unsigned char *a3) 

// minilib/include/syscalls_x64.h, line: 199
// SYSDEF_syscall(_getrlimit,2, unsigned int resource,  struct rlimit *rlim)
SYSREAL_define_syscall(_getrlimit,2, unsigned int a1,   struct rlimit *a2) 

// minilib/include/syscalls_x64.h, line: 433
// SYSDEF_syscall(_clock_gettime,2, const clockid_t which_clock,  struct timespec *tp)
SYSREAL_define_syscall(_clock_gettime,2, const clockid_t a1,   struct timespec *a2) 

// minilib/include/syscalls_x64.h, line: 557
// SYSDEF_syscall(_epoll_create1,1, int flags)
SYSREAL_define_syscall(_epoll_create1,1, int a1) 

// minilib/include/syscalls_x64.h, line: 465
// SYSDEF_syscall(_mq_getsetattr,3, mqd_t mqdes,  const struct mq_attr *u_mqstat,  struct mq_attr *u_omqstat)
SYSREAL_define_syscall(_mq_getsetattr,3, mqd_t a1,   const struct mq_attr *a2,   struct mq_attr *a3) 

// minilib/include/syscalls_x64.h, line: 443
// SYSDEF_syscall(_epoll_ctl,4, int epfd,  int op,  int fd,  struct epoll_event *event)
SYSREAL_define_syscall_noopt(_epoll_ctl,4, int a1,   int a2,   int a3,   struct epoll_event *a4) 

// minilib/include/syscalls_x64.h, line: 331
// SYSDEF_syscall(_settimeofday,2, struct timeval *tv,  struct timezone *tz)
SYSREAL_define_syscall(_settimeofday,2, struct timeval *a1,   struct timezone *a2) 

// minilib/include/syscalls_x64.h, line: 7
// SYSDEF_syscall(_write,3, unsigned int fd,  const char *buf,  size_t count)
SYSREAL_define_syscall(_write,3, unsigned int a1,   const char *a2,   size_t a3) 

// minilib/include/syscalls_x64.h, line: 399
// SYSDEF_syscall(_io_getevents,4, aio_context_t ctx_id,  long min_nr,  long nr,  struct io_event *events)
SYSREAL_define_syscall_noopt(_io_getevents,4, aio_context_t a1,   long a2,   long a3,   struct io_event *a4) 

// minilib/include/syscalls_x64.h, line: 293
// SYSDEF_syscall(_sched_getscheduler,1, pid_t pid)
SYSREAL_define_syscall(_sched_getscheduler,1, pid_t a1) 

// minilib/include/syscalls_x64.h, line: 17
// SYSDEF_syscall(_lstat,2, const char *filename,  struct stat *statbuf)
SYSREAL_define_syscall(_lstat,2, const char *a1,   struct stat *a2) 

// minilib/include/syscalls_x64.h, line: 363
// SYSDEF_syscall(_lsetxattr,5, const char *pathname,  const char *name,  const void *value, size_t size,  int flags)
SYSREAL_define_syscall_noopt(_lsetxattr,5, const char *a1,   const char *a2,   const void *a3,  size_t a4,   int a5) 

// minilib/include/syscalls_x64.h, line: 219
// SYSDEF_syscall(_geteuid,0)
SYSREAL_define_syscall(_geteuid,0)

// minilib/include/syscalls_x64.h, line: 125
// SYSDEF_syscall(_exit,1, int error_code)
SYSREAL_define_syscall(_exit,1, int a1) 

// minilib/include/syscalls_x64.h, line: 159
// SYSDEF_syscall(_ftruncate,2, unsigned int fd,  unsigned long length)
SYSREAL_define_syscall(_ftruncate,2, unsigned int a1,   unsigned long a2) 

// minilib/include/syscalls_x64.h, line: 551
// SYSDEF_syscall(_accept4,4, int fd,  struct sockaddr *upeer_sockaddr,  int *upeer_addrlen,  int flags)
SYSREAL_define_syscall_noopt(_accept4,4, int a1,   struct sockaddr *a2,   int *a3,   int a4) 

// minilib/include/syscalls_x64.h, line: 297
// SYSDEF_syscall(_sched_get_priority_min,1, int policy)
SYSREAL_define_syscall(_sched_get_priority_min,1, int a1) 

// minilib/include/syscalls_x64.h, line: 183
// SYSDEF_syscall(_readlink,3, const char *path,  char *buf,  int bufsiz)
SYSREAL_define_syscall(_readlink,3, const char *a1,   char *a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 147
// SYSDEF_syscall(_msgctl,3, int msqid,  int cmd,  struct msqid_ds *buf)
SYSREAL_define_syscall(_msgctl,3, int a1,   int a2,   struct msqid_ds *a3) 

// minilib/include/syscalls_x64.h, line: 43
// SYSDEF_syscall(_readv,3, unsigned long fd,  const struct iovec *vec,  unsigned long vlen)
SYSREAL_define_syscall(_readv,3, unsigned long a1,   const struct iovec *a2,   unsigned long a3) 

// minilib/include/syscalls_x64.h, line: 401
// SYSDEF_syscall(_io_submit,3, aio_context_t ctx_id,  long nr,  struct iocb **iocbpp)
SYSREAL_define_syscall(_io_submit,3, aio_context_t a1,   long a2,   struct iocb **a3) 

// minilib/include/syscalls_x64.h, line: 273
// SYSDEF_syscall(_personality,1, unsigned int personality)
SYSREAL_define_syscall(_personality,1, unsigned int a1) 

// minilib/include/syscalls_x64.h, line: 591
// SYSDEF_syscall(_setns,2, int fd,  int nstype)
SYSREAL_define_syscall(_setns,2, int a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 445
// SYSDEF_syscall(_tgkill,3, pid_t tgid,  pid_t pid,  int sig)
SYSREAL_define_syscall(_tgkill,3, pid_t a1,   pid_t a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 493
// SYSDEF_syscall(_mknodat,4, int dfd,  const char *filename,  int mode,  unsigned dev)
SYSREAL_define_syscall_noopt(_mknodat,4, int a1,   const char *a2,   int a3,   unsigned a4) 

// minilib/include/syscalls_x64.h, line: 283
// SYSDEF_syscall(_getpriority,2, int which,  int who)
SYSREAL_define_syscall(_getpriority,2, int a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 79
// SYSDEF_syscall(_alarm,1, unsigned int seconds)
SYSREAL_define_syscall(_alarm,1, unsigned int a1) 

// minilib/include/syscalls_x64.h, line: 527
// SYSDEF_syscall(_tee,4, int fdin,  int fdout,  size_t len,  unsigned int flags)
SYSREAL_define_syscall_noopt(_tee,4, int a1,   int a2,   size_t a3,   unsigned int a4) 

// minilib/include/syscalls_x64.h, line: 113
// SYSDEF_syscall(_setsockopt,5, int fd,  int level,  int optname,  char *optval,  int optlen)
SYSREAL_define_syscall_noopt(_setsockopt,5, int a1,   int a2,   int a3,   char *a4,   int a5) 

// minilib/include/syscalls_x64.h, line: 489
// SYSDEF_syscall(_openat,4, int dfd,  const char *filename,  int flags,  int mode)
SYSREAL_define_syscall_noopt(_openat,4, int a1,   const char *a2,   int a3,   int a4) 

// minilib/include/syscalls_x64.h, line: 539
// SYSDEF_syscall(_signalfd,3, int ufd,  sigset_t *user_mask,  size_t sizemask)
SYSREAL_define_syscall(_signalfd,3, int a1,   sigset_t *a2,   size_t a3) 

// minilib/include/syscalls_x64.h, line: 41
// SYSDEF_syscall(_pwrite64,4, unsigned int fd,  const char *buf,  size_t count,  loff_t pos)
SYSREAL_define_syscall_noopt(_pwrite64,4, unsigned int a1,   const char *a2,   size_t a3,   loff_t a4) 

// minilib/include/syscalls_x64.h, line: 501
// SYSDEF_syscall(_unlinkat,3, int dfd,  const char *pathname,  int flag)
SYSREAL_define_syscall(_unlinkat,3, int a1,   const char *a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 491
// SYSDEF_syscall(_mkdirat,3, int dfd,  const char *pathname,  int mode)
SYSREAL_define_syscall(_mkdirat,3, int a1,   const char *a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 383
// SYSDEF_syscall(_fremovexattr,2, int fd,  const char *name)
SYSREAL_define_syscall(_fremovexattr,2, int a1,   const char *a2) 

// minilib/include/syscalls_x64.h, line: 215
// SYSDEF_syscall(_setuid,1, uid_t uid)
SYSREAL_define_syscall(_setuid,1, uid_t a1) 

// minilib/include/syscalls_x64.h, line: 187
// SYSDEF_syscall(_fchmod,2, unsigned int fd,  mode_t mode)
SYSREAL_define_syscall(_fchmod,2, unsigned int a1,   mode_t a2) 

// minilib/include/syscalls_x64.h, line: 325
// SYSDEF_syscall(_chroot,1, const char *filename)
SYSREAL_define_syscall(_chroot,1, const char *a1) 

// minilib/include/syscalls_x64.h, line: 225
// SYSDEF_syscall(_getppid,0)
SYSREAL_define_syscall(_getppid,0)

// minilib/include/syscalls_x64.h, line: 411
// SYSDEF_syscall(_getdents64,3, unsigned int fd,  struct linux_dirent64 *dirent,  unsigned int count)
SYSREAL_define_syscall(_getdents64,3, unsigned int a1,   struct linux_dirent64 *a2,   unsigned int a3) 

// minilib/include/syscalls_x64.h, line: 479
// SYSDEF_syscall(_ioprio_get,2, int which,  int who)
SYSREAL_define_syscall(_ioprio_get,2, int a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 567
// SYSDEF_syscall(_pwritev,5, unsigned long fd,  const struct iovec *vec,  unsigned long vlen,  unsigned long pos_l,  unsigned long pos_h)
SYSREAL_define_syscall_noopt(_pwritev,5, unsigned long a1,   const struct iovec *a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

// minilib/include/syscalls_x64.h, line: 435
// SYSDEF_syscall(_clock_getres,2, const clockid_t which_clock,  struct timespec *tp)
SYSREAL_define_syscall(_clock_getres,2, const clockid_t a1,   struct timespec *a2) 

// minilib/include/syscalls_x64.h, line: 449
// SYSDEF_syscall(_mbind,6, unsigned long start,  unsigned long len,  unsigned long mode,  unsigned long *nmask,  unsigned long maxnode,  unsigned flags)
SYSREAL_define_syscall_noopt(_mbind,6, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long *a4,   unsigned long a5,   unsigned a6) 

// minilib/include/syscalls_x64.h, line: 573
// SYSDEF_syscall(_recvmmsg,5, int fd,  struct msghdr *mmsg,  unsigned int vlen,  unsigned int flags,  struct timespec *timeout)
SYSREAL_define_syscall_noopt(_recvmmsg,5, int a1,   struct msghdr *a2,   unsigned int a3,   unsigned int a4,   struct timespec *a5) 

// minilib/include/syscalls_x64.h, line: 461
// SYSDEF_syscall(_mq_timedreceive,5, mqd_t mqdes,  char *u_msg_ptr,  size_t msg_len,  unsigned int *u_msg_prio,  const struct timespec *u_abs_timeout)
SYSREAL_define_syscall_noopt(_mq_timedreceive,5, mqd_t a1,   char *a2,   size_t a3,   unsigned int *a4,   const struct timespec *a5) 

// minilib/include/syscalls_x64.h, line: 269
// SYSDEF_syscall(_utime,2, char *filename,  struct utimbuf *times)
SYSREAL_define_syscall(_utime,2, char *a1,   struct utimbuf *a2) 

// minilib/include/syscalls_x64.h, line: 451
// SYSDEF_syscall(_set_mempolicy,3, int mode,  unsigned long *nmask,  unsigned long maxnode)
SYSREAL_define_syscall(_set_mempolicy,3, int a1,   unsigned long *a2,   unsigned long a3) 

// minilib/include/syscalls_x64.h, line: 423
// SYSDEF_syscall(_timer_settime,4, timer_t timer_id,  int flags,  const struct itimerspec *new_setting,  struct itimerspec *old_setting)
SYSREAL_define_syscall_noopt(_timer_settime,4, timer_t a1,   int a2,   const struct itimerspec *a3,   struct itimerspec *a4) 

// minilib/include/syscalls_x64.h, line: 535
// SYSDEF_syscall(_utimensat,4, int dfd,  const char *filename,  struct timespec *utimes, int flags)
SYSREAL_define_syscall_noopt(_utimensat,4, int a1,   const char *a2,   struct timespec *a3,  int a4) 

// minilib/include/syscalls_x64.h, line: 505
// SYSDEF_syscall(_linkat,5, int oldfd,  const char *oldname,  int newfd,  const char *newname,  int flags)
SYSREAL_define_syscall_noopt(_linkat,5, int a1,   const char *a2,   int a3,   const char *a4,   int a5) 

// minilib/include/syscalls_x64.h, line: 233
// SYSDEF_syscall(_setregid,2, gid_t rgid,  gid_t egid)
SYSREAL_define_syscall(_setregid,2, gid_t a1,   gid_t a2) 

// minilib/include/syscalls_x64.h, line: 581
// SYSDEF_syscall(_name_to_handle_at,5, int dfd,  const char *name,  struct file_handle *handle,  int *mnt_id,  int flag)
SYSREAL_define_syscall_noopt(_name_to_handle_at,5, int a1,   const char *a2,   struct file_handle *a3,   int *a4,   int a5) 

// minilib/include/syscalls_x64.h, line: 349
// SYSDEF_syscall(_ioperm,3, unsigned long from,  unsigned long num,  int turn_on)
SYSREAL_define_syscall(_ioperm,3, unsigned long a1,   unsigned long a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 289
// SYSDEF_syscall(_sched_getparam,2, pid_t pid,  struct sched_param *param)
SYSREAL_define_syscall(_sched_getparam,2, pid_t a1,   struct sched_param *a2) 

// minilib/include/syscalls_x64.h, line: 329
// SYSDEF_syscall(_acct,1, const char *name)
SYSREAL_define_syscall(_acct,1, const char *a1) 

// minilib/include/syscalls_x64.h, line: 55
// SYSDEF_syscall(_mremap,5, unsigned long addr,  unsigned long old_len,  unsigned long new_len,  unsigned long flags,  unsigned long new_addr)
SYSREAL_define_syscall_noopt(_mremap,5, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

// minilib/include/syscalls_x64.h, line: 563
// SYSDEF_syscall(_inotify_init1,1, int flags)
SYSREAL_define_syscall(_inotify_init1,1, int a1) 

// minilib/include/syscalls_x64.h, line: 405
// SYSDEF_syscall(_lookup_dcookie,3, u64 cookie64,  long buf,  long len)
SYSREAL_define_syscall(_lookup_dcookie,3, u64 a1,   long a2,   long a3) 

// minilib/include/syscalls_x64.h, line: 307
// SYSDEF_syscall(_munlockall,0)
SYSREAL_define_syscall(_munlockall,0)

// minilib/include/syscalls_x64.h, line: 217
// SYSDEF_syscall(_setgid,1, gid_t gid)
SYSREAL_define_syscall(_setgid,1, gid_t a1) 

// minilib/include/syscalls_x64.h, line: 93
// SYSDEF_syscall(_sendto,6, int fd,  void *buff,  size_t len,  unsigned flags,  struct sockaddr *addr,  int addr_len)
SYSREAL_define_syscall_noopt(_sendto,6, int a1,   void *a2,   size_t a3,   unsigned a4,   struct sockaddr *a5,   int a6) 

// minilib/include/syscalls_x64.h, line: 417
// SYSDEF_syscall(_semtimedop,4, int semid,  struct sembuf *tsops,  unsigned nsops,  const struct timespec *timeout)
SYSREAL_define_syscall_noopt(_semtimedop,4, int a1,   struct sembuf *a2,   unsigned a3,   const struct timespec *a4) 

// minilib/include/syscalls_x64.h, line: 317
// SYSDEF_syscall(_prctl,5, int option,  unsigned long arg2,  unsigned long arg3,  unsigned long arg4,  unsigned long arg5)
SYSREAL_define_syscall_noopt(_prctl,5, int a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

// minilib/include/syscalls_x64.h, line: 341
// SYSDEF_syscall(_reboot,4, int magic1,  int magic2,  unsigned int cmd,  void *arg)
SYSREAL_define_syscall_noopt(_reboot,4, int a1,   int a2,   unsigned int a3,   void *a4) 

// minilib/include/syscalls_x64.h, line: 313
// SYSDEF_syscall(_pivot_root,2, const char *new_root,  const char *put_old)
SYSREAL_define_syscall(_pivot_root,2, const char *a1,   const char *a2) 

// minilib/include/syscalls_x64.h, line: 67
// SYSDEF_syscall(_shmctl,3, int shmid,  int cmd,  struct shmid_ds *buf)
SYSREAL_define_syscall(_shmctl,3, int a1,   int a2,   struct shmid_ds *a3) 

// minilib/include/syscalls_x64.h, line: 131
// SYSDEF_syscall(_uname,1, struct old_utsname *name)
SYSREAL_define_syscall(_uname,1, struct old_utsname *a1) 

// minilib/include/syscalls_x64.h, line: 565
// SYSDEF_syscall(_preadv,5, unsigned long fd,  const struct iovec *vec,  unsigned long vlen,  unsigned long pos_l,  unsigned long pos_h)
SYSREAL_define_syscall_noopt(_preadv,5, unsigned long a1,   const struct iovec *a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

// minilib/include/syscalls_x64.h, line: 547
// SYSDEF_syscall(_timerfd_settime,4, int ufd,  int flags,  const struct itimerspec *utmr,  struct itimerspec *otmr)
SYSREAL_define_syscall_noopt(_timerfd_settime,4, int a1,   int a2,   const struct itimerspec *a3,   struct itimerspec *a4) 

// minilib/include/syscalls_x64.h, line: 599
// SYSDEF_syscall(_kcmp,5, pid_t pid1,  pid_t pid2,  int type,  unsigned long idx1,  unsigned long idx2)
SYSREAL_define_syscall_noopt(_kcmp,5, pid_t a1,   pid_t a2,   int a3,   unsigned long a4,   unsigned long a5) 

// minilib/include/syscalls_x64.h, line: 355
// SYSDEF_syscall(_quotactl,4, unsigned int cmd,  const char *special,  qid_t id,  void *addr)
SYSREAL_define_syscall_noopt(_quotactl,4, unsigned int a1,   const char *a2,   qid_t a3,   void *a4) 

// minilib/include/syscalls_x64.h, line: 165
// SYSDEF_syscall(_chdir,1, const char *filename)
SYSREAL_define_syscall(_chdir,1, const char *a1) 

// minilib/include/syscalls_x64.h, line: 315
// SYSDEF_syscall(__sysctl,1, struct __sysctl_args *args)
SYSREAL_define_syscall(__sysctl,1, struct __sysctl_args *a1) 

// minilib/include/syscalls_x64.h, line: 503
// SYSDEF_syscall(_renameat,4, int oldfd,  const char *oldname,  int newfd,  const char *newname)
SYSREAL_define_syscall_noopt(_renameat,4, int a1,   const char *a2,   int a3,   const char *a4) 

// minilib/include/syscalls_x64.h, line: 71
// SYSDEF_syscall(_dup2,2, unsigned int oldfd,  unsigned int newfd)
SYSREAL_define_syscall(_dup2,2, unsigned int a1,   unsigned int a2) 

// minilib/include/syscalls_x64.h, line: 467
// SYSDEF_syscall(_kexec_load,4, unsigned long entry,  unsigned long nr_segments,  struct kexec_segment *segments,  unsigned long flags)
SYSREAL_define_syscall_noopt(_kexec_load,4, unsigned long a1,   unsigned long a2,   struct kexec_segment *a3,   unsigned long a4) 

// minilib/include/syscalls_x64.h, line: 161
// SYSDEF_syscall(_getdents,3, unsigned int fd,  struct linux_dirent *dirent,  unsigned int count)
SYSREAL_define_syscall(_getdents,3, unsigned int a1,   struct linux_dirent *a2,   unsigned int a3) 

// minilib/include/syscalls_x64.h, line: 247
// SYSDEF_syscall(_getpgid,1, pid_t pid)
SYSREAL_define_syscall(_getpgid,1, pid_t a1) 

// minilib/include/syscalls_x64.h, line: 471
// SYSDEF_syscall(_add_key,4, const char *_type,  const char *_description,  const void *_payload,  size_t plen)
SYSREAL_define_syscall_noopt(_add_key,4, const char *a1,   const char *a2,   const void *a3,   size_t a4) 

// minilib/include/syscalls_x64.h, line: 229
// SYSDEF_syscall(_setsid,0)
SYSREAL_define_syscall(_setsid,0)

// minilib/include/syscalls_x64.h, line: 221
// SYSDEF_syscall(_getegid,0)
SYSREAL_define_syscall(_getegid,0)

// minilib/include/syscalls_x64.h, line: 265
// SYSDEF_syscall(_rt_sigsuspend,2, sigset_t *unewset,  size_t sigsetsize)
SYSREAL_define_syscall(_rt_sigsuspend,2, sigset_t *a1,   size_t a2) 

// minilib/include/syscalls_x64.h, line: 171
// SYSDEF_syscall(_mkdir,2, const char *pathname,  int mode)
SYSREAL_define_syscall(_mkdir,2, const char *a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 61
// SYSDEF_syscall(_madvise,3, unsigned long start,  size_t len_in,  int behavior)
SYSREAL_define_syscall(_madvise,3, unsigned long a1,   size_t a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 521
// SYSDEF_syscall(_set_robust_list,2, struct robust_list_head *head,  size_t len)
SYSREAL_define_syscall(_set_robust_list,2, struct robust_list_head *a1,   size_t a2) 

// minilib/include/syscalls_x64.h, line: 271
// SYSDEF_syscall(_mknod,3, const char *filename,  umode_t mode,  unsigned dev)
SYSREAL_define_syscall(_mknod,3, const char *a1,   umode_t a2,   unsigned a3) 

// minilib/include/syscalls_x64.h, line: 57
// SYSDEF_syscall(_msync,3, unsigned long start,  size_t len,  int flags)
SYSREAL_define_syscall(_msync,3, unsigned long a1,   size_t a2,   int a3) 

// minilib/include/syscalls_x64.h, line: 201
// SYSDEF_syscall(_getrusage,2, int who,  struct rusage *ru)
SYSREAL_define_syscall(_getrusage,2, int a1,   struct rusage *a2) 

// minilib/include/syscalls_x64.h, line: 235
// SYSDEF_syscall(_getgroups,2, int gidsetsize,  gid_t *grouplist)
SYSREAL_define_syscall(_getgroups,2, int a1,   gid_t *a2) 

// minilib/include/syscalls_x64.h, line: 509
// SYSDEF_syscall(_readlinkat,4, int dfd,  const char *pathname,  char *buf,  int bufsiz)
SYSREAL_define_syscall_noopt(_readlinkat,4, int a1,   const char *a2,   char *a3,   int a4) 

// minilib/include/syscalls_x64.h, line: 497
// SYSDEF_syscall(_futimesat,3, int dfd,  const char *filename,  struct timeval *utimes)
SYSREAL_define_syscall(_futimesat,3, int a1,   const char *a2,   struct timeval *a3) 

// minilib/include/syscalls_x64.h, line: 91
// SYSDEF_syscall(_accept,3, int fd,  struct sockaddr *upeersockaddr,  int *upeeraddrlen)
SYSREAL_define_syscall(_accept,3, int a1,   struct sockaddr *a2,   int *a3) 

// minilib/include/syscalls_x64.h, line: 175
// SYSDEF_syscall(_creat,2, const char *pathname,  int mode)
SYSREAL_define_syscall(_creat,2, const char *a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 321
// SYSDEF_syscall(_adjtimex,1, struct timex *txc_p)
SYSREAL_define_syscall(_adjtimex,1, struct timex *a1) 

// minilib/include/syscalls_x64.h, line: 361
// SYSDEF_syscall(_setxattr,5, const char *pathname,  const char *name,  const void *value, size_t size,  int flags)
SYSREAL_define_syscall_noopt(_setxattr,5, const char *a1,   const char *a2,   const void *a3,  size_t a4,   int a5) 

// minilib/include/syscalls_x64.h, line: 251
// SYSDEF_syscall(_setfsgid,1, gid_t gid)
SYSREAL_define_syscall(_setfsgid,1, gid_t a1) 

// minilib/include/syscalls_x64.h, line: 205
// SYSDEF_syscall(_times,1, struct sysinfo *info)
SYSREAL_define_syscall(_times,1, struct sysinfo *a1) 

// minilib/include/syscalls_x64.h, line: 377
// SYSDEF_syscall(_flistxattr,3, int fd,  char *list,  size_t size)
SYSREAL_define_syscall(_flistxattr,3, int a1,   char *a2,   size_t a3) 

// minilib/include/syscalls_x64.h, line: 347
// SYSDEF_syscall(_iopl,2, unsigned int level,  struct pt_regs *regs)
SYSREAL_define_syscall(_iopl,2, unsigned int a1,   struct pt_regs *a2) 

// minilib/include/syscalls_x64.h, line: 603
// SYSDEF_syscall(_sched_setattr,3, pid_t pid,  struct sched_attr  *attr,  unsigned int flags)
SYSREAL_define_syscall(_sched_setattr,3, pid_t a1,   struct sched_attr  *a2,   unsigned int a3) 

// minilib/include/syscalls_x64.h, line: 393
// SYSDEF_syscall(_sched_getaffinity,3, pid_t pid,  unsigned int len,  unsigned long *user_mask_ptr)
SYSREAL_define_syscall(_sched_getaffinity,3, pid_t a1,   unsigned int a2,   unsigned long *a3) 

// minilib/include/syscalls_x64.h, line: 207
// SYSDEF_syscall(_ptrace,4, long request,  long pid,  unsigned long addr,  unsigned long data)
SYSREAL_define_syscall_noopt(_ptrace,4, long a1,   long a2,   unsigned long a3,   unsigned long a4) 

// minilib/include/syscalls_x64.h, line: 353
// SYSDEF_syscall(_delete_module,2, const char *name_user,  unsigned int flags)
SYSREAL_define_syscall(_delete_module,2, const char *a1,   unsigned int a2) 

// minilib/include/syscalls_x64.h, line: 259
// SYSDEF_syscall(_rt_sigpending,2, sigset_t *set,  size_t sigsetsize)
SYSREAL_define_syscall(_rt_sigpending,2, sigset_t *a1,   size_t a2) 

// minilib/include/syscalls_x64.h, line: 615
// SYSDEF_syscall(_kexec_file_load,5, int kernel_fd,  int initrd_fd,  unsigned long cmdline_len,  const char  *cmdline_ptr,  unsigned long flags)
SYSREAL_define_syscall_noopt(_kexec_file_load,5, int a1,   int a2,   unsigned long a3,   const char  *a4,   unsigned long a5) 

// minilib/include/syscalls_x64.h, line: 51
// SYSDEF_syscall(_select,5, int n,  fd_set *inp,  fd_set *outp,  fd_set *exp,  struct timeval *tvp)
SYSREAL_define_syscall_noopt(_select,5, int a1,   fd_set *a2,   fd_set *a3,   fd_set *a4,   struct timeval *a5) 

// minilib/include/syscalls_x64.h, line: 243
// SYSDEF_syscall(_setresgid,3, gid_t rgid,  gid_t egid,  gid_t sgid)
SYSREAL_define_syscall(_setresgid,3, gid_t a1,   gid_t a2,   gid_t a3) 

// minilib/include/syscalls_x64.h, line: 97
// SYSDEF_syscall(_sendmsg,3, int fd,  struct msghdr *msg,  unsigned flags)
SYSREAL_define_syscall(_sendmsg,3, int a1,   struct msghdr *a2,   unsigned a3) 

// minilib/include/syscalls_x64.h, line: 583
// SYSDEF_syscall(_open_by_handle_at,5, int dfd,  const char *name,  struct file_handle *handle,  int *mnt_id,  int flags)
SYSREAL_define_syscall_noopt(_open_by_handle_at,5, int a1,   const char *a2,   struct file_handle *a3,   int *a4,   int a5) 

// minilib/include/syscalls_x64.h, line: 611
// SYSDEF_syscall(_getrandom,3, char  *buf,  size_t count,  unsigned int flags)
SYSREAL_define_syscall(_getrandom,3, char  *a1,   size_t a2,   unsigned int a3) 

// minilib/include/syscalls_x64.h, line: 295
// SYSDEF_syscall(_sched_get_priority_max,1, int policy)
SYSREAL_define_syscall(_sched_get_priority_max,1, int a1) 

// minilib/include/syscalls_x64.h, line: 335
// SYSDEF_syscall(_umount2,2, const char *target,  int flags)
SYSREAL_define_syscall(_umount2,2, const char *a1,   int a2) 

// minilib/include/syscalls_x64.h, line: 107
// SYSDEF_syscall(_getsockname,3, int fd,  struct sockaddr *usockaddr,  int *usockaddr_len)
SYSREAL_define_syscall(_getsockname,3, int a1,   struct sockaddr *a2,   int *a3) 

// minilib/include/syscalls_x64.h, line: 281
// SYSDEF_syscall(_sysfs,3, int option,  unsigned long arg1,  unsigned long arg2)
SYSREAL_define_syscall(_sysfs,3, int a1,   unsigned long a2,   unsigned long a3) 

// minilib/include/syscalls_x64.h, line: 421
// SYSDEF_syscall(_timer_create,3, const clockid_t which_clock,  struct sigevent *timer_event_spec,  timer_t *created_timer_id)
SYSREAL_define_syscall(_timer_create,3, const clockid_t a1,   struct sigevent *a2,   timer_t *a3) 

// minilib/include/syscalls_x64.h, line: 531
// SYSDEF_syscall(_vmsplice,4, int fd,  const struct iovec *iov,  unsigned long nr_segs, unsigned int flags)
SYSREAL_define_syscall_noopt(_vmsplice,4, int a1,   const struct iovec *a2,   unsigned long a3,  unsigned int a4) 

// minilib/include/syscalls_x64.h, line: 25
// SYSDEF_syscall(_mprotect,3, unsigned long start,  size_t len,  unsigned long prot)
SYSREAL_define_syscall(_mprotect,3, unsigned long a1,   size_t a2,   unsigned long a3) 

// minilib/include/syscalls_x64.h, line: 387
// SYSDEF_syscall(_time,1, time_t *tloc)
SYSREAL_define_syscall(_time,1, time_t *a1) 

// minilib/include/syscalls_x64.h, line: 241
// SYSDEF_syscall(_getresuid,3, uid_t *ruid,  uid_t *euid,  uid_t *suid)
SYSREAL_define_syscall(_getresuid,3, uid_t *a1,   uid_t *a2,   uid_t *a3) 

// minilib/include/syscalls_x64.h, line: 409
// SYSDEF_syscall(_remap_file_pages,5, unsigned long start,  unsigned long size,  unsigned long prot,  unsigned long pgoff,  unsigned long flags)
SYSREAL_define_syscall_noopt(_remap_file_pages,5, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

// minilib/include/syscalls_x64.h, line: 371
// SYSDEF_syscall(_fgetxattr,4, int fd,  const char *name,  void *value,  size_t size)
SYSREAL_define_syscall_noopt(_fgetxattr,4, int a1,   const char *a2,   void *a3,   size_t a4) 

// minilib/include/syscalls_x64.h, line: 579
// SYSDEF_syscall(_prlimit64,4, pid_t pid,  unsigned int resource,  const struct rlimit64 *new_rlim,  struct rlimit64 *old_rlim)
SYSREAL_define_syscall_noopt(_prlimit64,4, pid_t a1,   unsigned int a2,   const struct rlimit64 *a3,   struct rlimit64 *a4) 

// minilib/include/syscalls_x64.h, line: 109
// SYSDEF_syscall(_getpeername,3, int fd,  struct sockaddr *usockaddr,  int *usockaddr_len)
SYSREAL_define_syscall(_getpeername,3, int a1,   struct sockaddr *a2,   int *a3) 

// minilib/include/syscalls_x64.h, line: 153
// SYSDEF_syscall(_fsync,1, unsigned int fd)
SYSREAL_define_syscall(_fsync,1, unsigned int a1) 

// minilib/include/syscalls_x64.h, line: 77
// SYSDEF_syscall(_getitimer,2, int which,  struct itimerval *value)
SYSREAL_define_syscall(_getitimer,2, int a1,   struct itimerval *a2) 

// minilib/include/syscalls_x64.h, line: 49
// SYSDEF_syscall(_pipe,1, int *filedes)
SYSREAL_define_syscall(_pipe,1, int *a1) 

// minilib/include/syscalls_x64.h, line: 191
// SYSDEF_syscall(_fchown,3, unsigned int fd,  uid_t user,  gid_t group)
SYSREAL_define_syscall(_fchown,3, unsigned int a1,   uid_t a2,   gid_t a3) 

#endif

/* --- generated-macros-end: syscalldefs --- */

#pragma GCC diagnostic pop
#endif

#endif
