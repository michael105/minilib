#ifndef syscall_stubs_h
#define syscall_stubs_h
/*
 These are just wrapped syscalls.
 errno is set, anyway.

 This file (and the other headers) are parsed by 'genheaders.pl',
 and the "real" syscall defines below the mark generated-makros-start created.	

*/

//+header declarations.h
//
///+needs mini_fstream.h

#include "timeval.h"

extern int sysret;
extern int errno;

struct stat;
struct timeval;
struct timezone;

// TODO: declarations
// below are untested definitions,
// for the SYSREAL... (expaning to sys"syscallname" ) macros
//typedef long sigset_t;
typedef unsigned long u64;
typedef unsigned long __u64;
typedef unsigned int u32;
typedef unsigned char __s32;

typedef long aio_context_t;
typedef long siginfo_t;
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

DEF_syscall(gettimeofday,2, struct timeval *a1, struct timezone *a2)

DEF_syscall(getpid,0 )

DEF_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3 )

DEF_syscall(close, 1, int fd )
DEF_syscall(read, 3, int fd, POINTER *buf, int len )

DEF_syscall(uname,1,struct old_utsname *name )

DEF_syscall(getdents, 3, unsigned int fd, struct dirent *direntry, unsigned int count )

DEF_syscall(write,3,int fd,const void *buf, int len )
//rename a1=oldpath a2=newpath

DEF_syscall(rename,2, const char* oldpath, const char* newpath )		
DEF_syscall(unlink,1, const char* a1)		

DEF_syscall(fstat,2,int a1,struct stat* a2)		
DEF_syscall(stat,2,const char* filename,struct stat* a2)		
DEF_syscall(chdir,1,const char* path)		

DEF_syscall(dup,1,int a1)		
DEF_syscall(dup2,2,int a1, int a2)		
DEF_syscall(dup3,3,int a1, int a2, int a3)		

DEF_syscall(getcwd,2,char *buf,long size)		


#ifndef OSX
DEF_syscall(time,1,unsigned int *a1 )
//DEF_syscallret(time,*a1,1,unsigned int *a1 )
#else

#endif

	// problem: ifdef / ifndef now doesnt work anymore for the definitions. 
	// Hopefully, thats not going to be a problem.
	// Will see it when trying to compile at osx again
	//

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-conversion"

/* --- generated-macros-start: syscalldefs --- */
/* minilib/include/syscall_stubs.h, line: 73 */
REAL_define_syscall(unlink,1, const char* a1) 		

/* minilib/include/syscall_stubs.h, line: 79 */
REAL_define_syscall(dup,1,int a1) 		

/* minilib/include/syscall_stubs.h, line: 58 */
REAL_define_syscall(getpid,0 )

/* minilib/include/syscall_stubs.h, line: 75 */
REAL_define_syscall(fstat,2,int a1, struct stat* a2) 		

/* minilib/include/syscall_stubs.h, line: 81 */
REAL_define_syscall(dup3,3,int a1,  int a2,  int a3) 		

/* minilib/include/syscall_stubs.h, line: 80 */
REAL_define_syscall(dup2,2,int a1,  int a2) 		

/* minilib/include/syscall_stubs.h, line: 56 */
REAL_define_syscall(gettimeofday,2, struct timeval *a1,  struct timezone *a2) 

/* minilib/include/syscall_stubs.h, line: 67 */
REAL_define_syscall(getdents, 3, unsigned int a1,  struct dirent *a2,  unsigned int a3) 

/* minilib/include/syscall_stubs.h, line: 69 */
REAL_define_syscall(write,3,int a1, const void *a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 65 */
REAL_define_syscall(uname,1,struct old_utsname *a1) 

/* minilib/include/lseek.h, line: 20 */
REAL_define_syscall(fsync,1,int a1) 

/* minilib/include/syscall_stubs.h, line: 63 */
REAL_define_syscall(read, 3, int a1,  POINTER *a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 87 */
REAL_define_syscall(time,1,unsigned int *a1) 

/* minilib/include/syscall_stubs.h, line: 77 */
REAL_define_syscall(chdir,1,const char* a1) 		

/* minilib/include/syscall_stubs.h, line: 60 */
REAL_define_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3)

/* minilib/include/syscall_stubs.h, line: 76 */
REAL_define_syscall(stat,2,const char* a1, struct stat* a2) 		

/* minilib/include/syscall_stubs.h, line: 72 */
REAL_define_syscall(rename,2, const char* a1,  const char* a2) 		

/* minilib/include/lseek.h, line: 19 */
REAL_define_syscall(ftruncate,2,unsigned int a1,  unsigned int a2) 

/* minilib/include/syscall_stubs.h, line: 83 */
REAL_define_syscall(getcwd,2,char *a1, long a2) 		

/* minilib/include/lseek.h, line: 17 */
REAL_define_syscall(lseek,3,unsigned int a1,  int a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 62 */
REAL_define_syscall(close, 1, int a1) 

/* , line:  */
SYSREAL_define_syscall(_sched_setparam,2, pid_t a1,   struct sched_param *a2) 

/* , line:  */
SYSREAL_define_syscall(_clock_gettime,2, const clockid_t a1,   struct timespec *a2) 

/* , line:  */
SYSREAL_define_syscall(_io_getevents,4, aio_context_t a1,   long a2,   long a3,   struct io_event *a4) 

/* , line:  */
SYSREAL_define_syscall(_tgkill,3, pid_t a1,   pid_t a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_lookup_dcookie,3, u64 a1,   long a2,   long a3) 

/* , line:  */
SYSREAL_define_syscall(_creat,2, const char *a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_utimensat,4, int a1,   const char *a2,   struct timespec *a3,  int a4) 

/* , line:  */
SYSREAL_define_syscall(_eventfd2,2, unsigned int a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_removexattr,2, const char *a1,   const char *a2) 

/* , line:  */
SYSREAL_define_syscall(_getrusage,2, int a1,   struct rusage *a2) 

/* , line:  */
SYSREAL_define_syscall(_delete_module,2, const char *a1,   unsigned int a2) 

/* , line:  */
SYSREAL_define_syscall(_process_vm_writev,6, pid_t a1,   const struct iovec *a2,   unsigned long a3,   const struct iovcc *a4,   unsigned long a5,   unsigned long a6) 

/* , line:  */
SYSREAL_define_syscall(_prctl,5, int a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* , line:  */
SYSREAL_define_syscall(_keyctl,5, int a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* , line:  */
SYSREAL_define_syscall(_getpid,0)

/* , line:  */
SYSREAL_define_syscall(_semop,3, int a1,   struct sembuf *a2,   unsigned a3) 

/* , line:  */
SYSREAL_define_syscall(_add_key,4, const char *a1,   const char *a2,   const void *a3,   size_t a4) 

/* , line:  */
SYSREAL_define_syscall(_sendmmsg,4, int a1,   struct mmsghdr *a2,   unsigned int a3,   unsigned int a4) 

/* , line:  */
SYSREAL_define_syscall(_mq_notify,2, mqd_t a1,   const struct sigevent *a2) 

/* , line:  */
SYSREAL_define_syscall(_mbind,6, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long *a4,   unsigned long a5,   unsigned a6) 

/* , line:  */
SYSREAL_define_syscall(_vmsplice,4, int a1,   const struct iovec *a2,   unsigned long a3,  unsigned int a4) 

/* , line:  */
SYSREAL_define_syscall(_fchmodat,3, int a1,   const char *a2,   mode_t a3) 

/* , line:  */
SYSREAL_define_syscall(_modify_ldt,3, int a1,   void *a2,   unsigned long a3) 

/* , line:  */
SYSREAL_define_syscall(_open,3, const char *a1,   int a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_finit_module,3, int a1,   const char  *a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_pwritev,5, unsigned long a1,   const struct iovec *a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* , line:  */
SYSREAL_define_syscall(_linkat,5, int a1,   const char *a2,   int a3,   const char *a4,   int a5) 

/* , line:  */
SYSREAL_define_syscall(_rt_sigaction,4, int a1,   const struct sigaction *a2,   struct sigaction *a3,   size_t a4) 

/* , line:  */
SYSREAL_define_syscall(_mkdir,2, const char *a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_seccomp,3, unsigned int a1,   unsigned int a2,   const char  *a3) 

/* , line:  */
SYSREAL_define_syscall(_sysfs,3, int a1,   unsigned long a2,   unsigned long a3) 

/* , line:  */
SYSREAL_define_syscall(_shutdown,2, int a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_inotify_init,0)

/* , line:  */
SYSREAL_define_syscall(_swapoff,1, const char *a1) 

/* , line:  */
SYSREAL_define_syscall(_getgroups,2, int a1,   gid_t *a2) 

/* , line:  */
SYSREAL_define_syscall(_shmget,3, key_t a1,   size_t a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_mq_timedsend,5, mqd_t a1,   const char *a2,   size_t a3,   unsigned int a4,   const struct timespec *a5) 

/* , line:  */
SYSREAL_define_syscall(_getresgid,3, gid_t *a1,   gid_t *a2,   gid_t *a3) 

/* , line:  */
SYSREAL_define_syscall(_fchownat,5, int a1,   const char *a2,   uid_t a3,   gid_t a4,   int a5) 

/* , line:  */
SYSREAL_define_syscall(_fanotify_mark,5, long a1,   long a2,   __u64 a3,   long a4,  long a5) 

/* , line:  */
SYSREAL_define_syscall(_setrlimit,2, unsigned int a1,   struct rlimit *a2) 

/* , line:  */
SYSREAL_define_syscall(_vfork,0)

/* , line:  */
SYSREAL_define_syscall(_clone,4, unsigned long a1,   unsigned long a2,   void *a3,   void *a4) 

/* , line:  */
SYSREAL_define_syscall(_prlimit64,4, pid_t a1,   unsigned int a2,   const struct rlimit64 *a3,   struct rlimit64 *a4) 

/* , line:  */
SYSREAL_define_syscall(_preadv,5, unsigned long a1,   const struct iovec *a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* , line:  */
SYSREAL_define_syscall(_acct,1, const char *a1) 

/* , line:  */
SYSREAL_define_syscall(_unlink,1, const char *a1) 

/* , line:  */
SYSREAL_define_syscall(_sysinfo,1, struct sysinfo *a1) 

/* , line:  */
SYSREAL_define_syscall(_chdir,1, const char *a1) 

/* , line:  */
SYSREAL_define_syscall(_accept,3, int a1,   struct sockaddr *a2,   int *a3) 

/* , line:  */
SYSREAL_define_syscall(_pipe2,2, int *a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_newfstatat,4, int a1,   const char *a2,   struct stat *a3,   int a4) 

/* , line:  */
SYSREAL_define_syscall(_getsockname,3, int a1,   struct sockaddr *a2,   int *a3) 

/* , line:  */
SYSREAL_define_syscall(_timer_delete,1, timer_t a1) 

/* , line:  */
SYSREAL_define_syscall(_ftruncate,2, unsigned int a1,   unsigned long a2) 

/* , line:  */
SYSREAL_define_syscall(_ioperm,3, unsigned long a1,   unsigned long a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_msgctl,3, int a1,   int a2,   struct msqid_ds *a3) 

/* , line:  */
SYSREAL_define_syscall(_init_module,3, void *a1,   unsigned long a2,   const char *a3) 

/* , line:  */
SYSREAL_define_syscall(_setpgid,2, pid_t a1,   pid_t a2) 

/* , line:  */
SYSREAL_define_syscall(_tkill,2, pid_t a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_setitimer,3, int a1,   struct itimerval *a2,   struct itimerval *a3) 

/* , line:  */
SYSREAL_define_syscall(_munlockall,0)

/* , line:  */
SYSREAL_define_syscall(_getresuid,3, uid_t *a1,   uid_t *a2,   uid_t *a3) 

/* , line:  */
SYSREAL_define_syscall(_select,5, int a1,   fd_set *a2,   fd_set *a3,   fd_set *a4,   struct timeval *a5) 

/* , line:  */
SYSREAL_define_syscall(_set_mempolicy,3, int a1,   unsigned long *a2,   unsigned long a3) 

/* , line:  */
SYSREAL_define_syscall(_io_destroy,1, aio_context_t a1) 

/* , line:  */
SYSREAL_define_syscall(_symlink,2, const char *a1,   const char *a2) 

/* , line:  */
SYSREAL_define_syscall(_dup,1, unsigned int a1) 

/* , line:  */
SYSREAL_define_syscall(_syslog,3, int a1,   char *a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_set_robust_list,2, struct robust_list_head *a1,   size_t a2) 

/* , line:  */
SYSREAL_define_syscall(_mlockall,1, int a1) 

/* , line:  */
SYSREAL_define_syscall(_mknod,3, const char *a1,   umode_t a2,   unsigned a3) 

/* , line:  */
SYSREAL_define_syscall(_getpeername,3, int a1,   struct sockaddr *a2,   int *a3) 

/* , line:  */
SYSREAL_define_syscall(_accept4,4, int a1,   struct sockaddr *a2,   int *a3,   int a4) 

/* , line:  */
SYSREAL_define_syscall(_bind,3, int a1,   struct sockaddr *a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_waitid,5, int a1,   pid_t a2,   struct siginfo *a3,   int a4,   struct rusage *a5) 

/* , line:  */
SYSREAL_define_syscall(_timer_create,3, const clockid_t a1,   struct sigevent *a2,   timer_t *a3) 

/* , line:  */
SYSREAL_define_syscall(_renameat,4, int a1,   const char *a2,   int a3,   const char *a4) 

/* , line:  */
SYSREAL_define_syscall(_mount,5, char *a1,   char *a2,   char *a3,   unsigned long a4,   void *a5) 

/* , line:  */
SYSREAL_define_syscall(_getxattr,4, const char *a1,   const char *a2,   void *a3,   size_t a4) 

/* , line:  */
SYSREAL_define_syscall(_get_robust_list,3, int a1,   struct robust_list_head **a2,   size_t *a3) 

/* , line:  */
SYSREAL_define_syscall(_fadvise64,4, int a1,   loff_t a2,   size_t a3,   int a4) 

/* , line:  */
SYSREAL_define_syscall(_sync,0)

/* , line:  */
SYSREAL_define_syscall(_uname,1, struct old_utsname *a1) 

/* , line:  */
SYSREAL_define_syscall(_migrate_pages,4, pid_t a1,   unsigned long a2,   const unsigned long *a3,   const unsigned long *a4) 

/* , line:  */
SYSREAL_define_syscall(_gettid,0)

/* , line:  */
SYSREAL_define_syscall(_rt_sigsuspend,2, sigset_t *a1,   size_t a2) 

/* , line:  */
SYSREAL_define_syscall(_listen,2, int a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_epoll_pwait,6, int a1,   struct epoll_event *a2,   int a3,   int a4,   const sigset_t *a5,   size_t a6) 

/* , line:  */
SYSREAL_define_syscall(_alarm,1, unsigned int a1) 

/* , line:  */
SYSREAL_define_syscall(_move_pages,6, pid_t a1,   unsigned long a2,   const void *a3,  const int *a4,   int *a5,   int a6) 

/* , line:  */
SYSREAL_define_syscall(_sethostname,2, char *a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_io_setup,2, unsigned a1,   aio_context_t *a2) 

/* , line:  */
SYSREAL_define_syscall(_munlock,2, unsigned long a1,   size_t a2) 

/* , line:  */
SYSREAL_define_syscall(_open_by_handle_at,5, int a1,   const char *a2,   struct file_handle *a3,   int *a4,   int a5) 

/* , line:  */
SYSREAL_define_syscall(_mremap,5, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* , line:  */
SYSREAL_define_syscall(_setdomainname,2, char *a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_fallocate,4, long a1,   long a2,   loff_t a3,   loff_t a4) 

/* , line:  */
SYSREAL_define_syscall(_setxattr,5, const char *a1,   const char *a2,   const void *a3,  size_t a4,   int a5) 

/* , line:  */
SYSREAL_define_syscall(_mknodat,4, int a1,   const char *a2,   int a3,   unsigned a4) 

/* , line:  */
SYSREAL_define_syscall(_clock_getres,2, const clockid_t a1,   struct timespec *a2) 

/* , line:  */
SYSREAL_define_syscall(_get_mempolicy,5, int *a1,   unsigned long *a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* , line:  */
SYSREAL_define_syscall(_signalfd4,4, int a1,   sigset_t *a2,   size_t a3,   int a4) 

/* , line:  */
SYSREAL_define_syscall(_lseek,3, unsigned int a1,   off_t a2,   unsigned int a3) 

/* , line:  */
SYSREAL_define_syscall(_access,2, const char *a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_sigaltstack,2, const stack_t *a1,   stack_t *a2) 

/* , line:  */
SYSREAL_define_syscall(_process_vm_readv,6, pid_t a1,   const struct iovec *a2,   unsigned long a3,   const struct iovec *a4,   unsigned long a5,   unsigned long a6) 

/* , line:  */
SYSREAL_define_syscall(_sendto,6, int a1,   void *a2,   size_t a3,   unsigned a4,   struct sockaddr *a5,   int a6) 

/* , line:  */
SYSREAL_define_syscall(_sendfile,4, int a1,   int a2,   off_t *a3,   size_t a4) 

/* , line:  */
SYSREAL_define_syscall(_clock_nanosleep,4, const clockid_t a1,   int a2,   const struct timespec *a3,   struct timespec *a4) 

/* , line:  */
SYSREAL_define_syscall(_getdents,3, unsigned int a1,   struct linux_dirent *a2,   unsigned int a3) 

/* , line:  */
SYSREAL_define_syscall(_getitimer,2, int a1,   struct itimerval *a2) 

/* , line:  */
SYSREAL_define_syscall(_getpgid,1, pid_t a1) 

/* , line:  */
SYSREAL_define_syscall(_fsync,1, unsigned int a1) 

/* , line:  */
SYSREAL_define_syscall(_sendmsg,3, int a1,   struct msghdr *a2,   unsigned a3) 

/* , line:  */
SYSREAL_define_syscall(_setresuid,3, uid_t *a1,   uid_t *a2,   uid_t *a3) 

/* , line:  */
SYSREAL_define_syscall(_setfsuid,1, uid_t a1) 

/* , line:  */
SYSREAL_define_syscall(_umask,1, int a1) 

/* , line:  */
SYSREAL_define_syscall(_ustat,2, unsigned a1,   struct ustat *a2) 

/* , line:  */
SYSREAL_define_syscall(_clock_settime,2, const clockid_t a1,   const struct timespec *a2) 

/* , line:  */
SYSREAL_define_syscall(_sched_getparam,2, pid_t a1,   struct sched_param *a2) 

/* , line:  */
SYSREAL_define_syscall(_getrlimit,2, unsigned int a1,   struct rlimit *a2) 

/* , line:  */
SYSREAL_define_syscall(_sched_rr_get_interval,2, pid_t a1,   struct timespec *a2) 

/* , line:  */
SYSREAL_define_syscall(_fstat,2, unsigned int a1,   struct stat *a2) 

/* , line:  */
SYSREAL_define_syscall(_sched_get_priority_max,1, int a1) 

/* , line:  */
SYSREAL_define_syscall(_futex,6, u32 *a1,   int a2,   u32 a3,   struct timespec *a4,   u32 *a5,   u32 a6) 

/* , line:  */
SYSREAL_define_syscall(_rt_sigreturn,1, unsigned long a1) 

/* , line:  */
SYSREAL_define_syscall(_chmod,2, const char *a1,   mode_t a2) 

/* , line:  */
SYSREAL_define_syscall(_times,1, struct sysinfo *a1) 

/* , line:  */
SYSREAL_define_syscall(_mkdirat,3, int a1,   const char *a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_setgroups,2, int a1,   gid_t *a2) 

/* , line:  */
SYSREAL_define_syscall(_mq_unlink,1, const char *a1) 

/* , line:  */
SYSREAL_define_syscall(_restart_syscall,0)

/* , line:  */
SYSREAL_define_syscall(_listxattr,3, const char *a1,   char *a2,   size_t a3) 

/* , line:  */
SYSREAL_define_syscall(_lstat,2, const char *a1,   struct stat *a2) 

/* , line:  */
SYSREAL_define_syscall(_fork,0)

/* , line:  */
SYSREAL_define_syscall(_setresgid,3, gid_t a1,   gid_t a2,   gid_t a3) 

/* , line:  */
SYSREAL_define_syscall(_inotify_add_watch,3, int a1,   const char *a2,   u32 a3) 

/* , line:  */
SYSREAL_define_syscall(_inotify_init1,1, int a1) 

/* , line:  */
SYSREAL_define_syscall(_sched_get_priority_min,1, int a1) 

/* , line:  */
SYSREAL_define_syscall(_statfs,2, const char *a1,   struct statfs *a2) 

/* , line:  */
SYSREAL_define_syscall(_fcntl,3, unsigned int a1,   unsigned int a2,   unsigned long a3) 

/* , line:  */
SYSREAL_define_syscall(_semctl,4, int a1,   int a2,   int a3,   semun_u a4) 

/* , line:  */
SYSREAL_define_syscall(_chroot,1, const char *a1) 

/* , line:  */
SYSREAL_define_syscall(_close,1, unsigned int a1) 

/* , line:  */
SYSREAL_define_syscall(_getppid,0)

/* , line:  */
SYSREAL_define_syscall(_getrandom,3, char  *a1,   size_t a2,   unsigned int a3) 

/* , line:  */
SYSREAL_define_syscall(_mlock,2, unsigned long a1,   size_t a2) 

/* , line:  */
SYSREAL_define_syscall(_pselect6,6, int a1,   fd_set *a2,   fd_set *a3,   fd_set *a4,   struct timespec *a5,   void *a6) 

/* , line:  */
SYSREAL_define_syscall(_execve,3, const char *a1,   const char *const a2,   const char *const a3) 

/* , line:  */
SYSREAL_define_syscall(_umount2,2, const char *a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_exit_group,1, int a1) 

/* , line:  */
SYSREAL_define_syscall(_getcwd,2, char *a1,   unsigned long a2) 

/* , line:  */
SYSREAL_define_syscall(_fstatfs,2, unsigned int a1,   struct statfs *a2) 

/* , line:  */
SYSREAL_define_syscall(_msgsnd,4, int a1,   struct msgbuf *a2,   size_t a3,   int a4) 

/* , line:  */
SYSREAL_define_syscall(_rt_sigtimedwait,4, const sigset_t *a1,   siginfo_t *a2,   const struct timespec *a3,   size_t a4) 

/* , line:  */
SYSREAL_define_syscall(_read,3, unsigned int a1,   char *a2,   size_t a3) 

/* , line:  */
SYSREAL_define_syscall(_ptrace,4, long a1,   long a2,   unsigned long a3,   unsigned long a4) 

/* , line:  */
SYSREAL_define_syscall(_remap_file_pages,5, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* , line:  */
SYSREAL_define_syscall(_kcmp,5, pid_t a1,   pid_t a2,   int a3,   unsigned long a4,   unsigned long a5) 

/* , line:  */
SYSREAL_define_syscall(_readv,3, unsigned long a1,   const struct iovec *a2,   unsigned long a3) 

/* , line:  */
SYSREAL_define_syscall(_rt_sigpending,2, sigset_t *a1,   size_t a2) 

/* , line:  */
SYSREAL_define_syscall(_setfsgid,1, gid_t a1) 

/* , line:  */
SYSREAL_define_syscall(_rt_tgsigqueueinfo,4, pid_t a1,   pid_t a2,   int a3,   siginfo_t *a4) 

/* , line:  */
SYSREAL_define_syscall(_write,3, unsigned int a1,   const char *a2,   size_t a3) 

/* , line:  */
SYSREAL_define_syscall(_futimesat,3, int a1,   const char *a2,   struct timeval *a3) 

/* , line:  */
SYSREAL_define_syscall(_ioprio_get,2, int a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_epoll_wait,4, int a1,   struct epoll_event *a2,   int a3,   int a4) 

/* , line:  */
SYSREAL_define_syscall(_getpgrp,0)

/* , line:  */
SYSREAL_define_syscall(_kill,2, pid_t a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_timerfd_create,2, int a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_openat,4, int a1,   const char *a2,   int a3,   int a4) 

/* , line:  */
SYSREAL_define_syscall(_sched_setattr,3, pid_t a1,   struct sched_attr  *a2,   unsigned int a3) 

/* , line:  */
SYSREAL_define_syscall(_semtimedop,4, int a1,   struct sembuf *a2,   unsigned a3,   const struct timespec *a4) 

/* , line:  */
SYSREAL_define_syscall(_stat,2, const char *a1,   struct stat *a2) 

/* , line:  */
SYSREAL_define_syscall(_unshare,1, unsigned long a1) 

/* , line:  */
SYSREAL_define_syscall(_clock_adjtime,2, clockid_t a1,   struct timex *a2) 

/* , line:  */
SYSREAL_define_syscall(_link,2, const char *a1,   const char *a2) 

/* , line:  */
SYSREAL_define_syscall(_wait4,4, pid_t a1,   int *a2,   int a3,   struct rusage *a4) 

/* , line:  */
SYSREAL_define_syscall(_personality,1, unsigned int a1) 

/* , line:  */
SYSREAL_define_syscall(_mq_open,4, const char *a1,   int a2,   mode_t a3,   struct mq_attr *a4) 

/* , line:  */
SYSREAL_define_syscall(_gettimeofday,2, struct timeval *a1,   struct timezone *a2) 

/* , line:  */
SYSREAL_define_syscall(_sync_file_range,4, long a1,   loff_t a2,   loff_t a3,   long a4) 

/* , line:  */
SYSREAL_define_syscall(_poll,3, struct poll_fd *a1,   unsigned int a2,   long a3) 

/* , line:  */
SYSREAL_define_syscall(_mq_timedreceive,5, mqd_t a1,   char *a2,   size_t a3,   unsigned int *a4,   const struct timespec *a5) 

/* , line:  */
SYSREAL_define_syscall(_utimes,2, char *a1,   struct timeval *a2) 

/* , line:  */
SYSREAL_define_syscall(_kexec_file_load,5, int a1,   int a2,   unsigned long a3,   const char  *a4,   unsigned long a5) 

/* , line:  */
SYSREAL_define_syscall(_msgget,2, key_t a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_lgetxattr,4, const char *a1,   const char *a2,   void *a3,   size_t a4) 

/* , line:  */
SYSREAL_define_syscall(_readlinkat,4, int a1,   const char *a2,   char *a3,   int a4) 

/* , line:  */
SYSREAL_define_syscall(_getsockopt,5, int a1,   int a2,   int a3,   char *a4,   int *a5) 

/* , line:  */
SYSREAL_define_syscall(_lremovexattr,2, const char *a1,   const char *a2) 

/* , line:  */
SYSREAL_define_syscall(_setreuid,2, uid_t a1,   uid_t a2) 

/* , line:  */
SYSREAL_define_syscall(_mq_getsetattr,3, mqd_t a1,   const struct mq_attr *a2,   struct mq_attr *a3) 

/* , line:  */
SYSREAL_define_syscall(_llistxattr,3, const char *a1,   char *a2,   size_t a3) 

/* , line:  */
SYSREAL_define_syscall(_truncate,2, const char *a1,   long a2) 

/* , line:  */
SYSREAL_define_syscall(_sched_getscheduler,1, pid_t a1) 

/* , line:  */
SYSREAL_define_syscall(_quotactl,4, unsigned int a1,   const char *a2,   qid_t a3,   void *a4) 

/* , line:  */
SYSREAL_define_syscall(_brk,1, unsigned long a1) 

/* , line:  */
SYSREAL_define_syscall(_munmap,2, unsigned long a1,   size_t a2) 

/* , line:  */
SYSREAL_define_syscall(_readahead,3, int a1,   loff_t a2,   size_t a3) 

/* , line:  */
SYSREAL_define_syscall(_setpriority,3, int a1,   int a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_recvmmsg,5, int a1,   struct msghdr *a2,   unsigned int a3,   unsigned int a4,   struct timespec *a5) 

/* , line:  */
SYSREAL_define_syscall(_fgetxattr,4, int a1,   const char *a2,   void *a3,   size_t a4) 

/* , line:  */
SYSREAL_define_syscall(_timer_gettime,2, timer_t a1,   struct itimerspec *a2) 

/* , line:  */
SYSREAL_define_syscall(_faccessat,3, int a1,   const char *a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_flistxattr,3, int a1,   char *a2,   size_t a3) 

/* , line:  */
SYSREAL_define_syscall(_recvfrom,6, int a1,   void *a2,   size_t a3,   unsigned a4,   struct sockaddr *a5,   int *a6) 

/* , line:  */
SYSREAL_define_syscall(_epoll_ctl,4, int a1,   int a2,   int a3,   struct epoll_event *a4) 

/* , line:  */
SYSREAL_define_syscall(_fremovexattr,2, int a1,   const char *a2) 

/* , line:  */
SYSREAL_define_syscall(_madvise,3, unsigned long a1,   size_t a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_epoll_create,1, int a1) 

/* , line:  */
SYSREAL_define_syscall(_shmctl,3, int a1,   int a2,   struct shmid_ds *a3) 

/* , line:  */
SYSREAL_define_syscall(_sched_setaffinity,3, pid_t a1,   unsigned int a2,   unsigned long *a3) 

/* , line:  */
SYSREAL_define_syscall(_ioprio_set,3, int a1,   int a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_request_key,4, const char *a1,   const char *a2,   const char *a3,   key_serial_t a4) 

/* , line:  */
SYSREAL_define_syscall(_socket,3, int a1,   int a2,   int a3) 

/* , line:  */
//SYSREAL_define_syscall(_bpf,3, int a1,   union bpf_attr *a2,   unsigned int a3) 

/* , line:  */
SYSREAL_define_syscall(_getcpu,3, unsigned *a1,   unsigned *a2,   struct getcpu_cache *a3) 

/* , line:  */
SYSREAL_define_syscall(_syncfs,1, int a1) 

/* , line:  */
SYSREAL_define_syscall(_signalfd,3, int a1,   sigset_t *a2,   size_t a3) 

/* , line:  */
SYSREAL_define_syscall(_ioctl,3, unsigned int a1,   unsigned int a2,   unsigned long a3) 

/* , line:  */
SYSREAL_define_syscall(_connect,3, int a1,   struct sockaddr *a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_geteuid,0)

/* , line:  */
SYSREAL_define_syscall(_ppoll,5, struct pollfd *a1,   unsigned int a2,   struct timespec *a3,   const sigset_t *a4,   size_t a5) 

/* , line:  */
SYSREAL_define_syscall(_splice,6, int a1,   loff_t *a2,   int a3,   loff_t *a4,  size_t a5,   unsigned int a6) 

/* , line:  */
SYSREAL_define_syscall(_set_tid_address,1, int *a1) 

/* , line:  */
SYSREAL_define_syscall(_memfd_create,2, const char  *a1,   unsigned int a2) 

/* , line:  */
SYSREAL_define_syscall(_msgrcv,5, int a1,   struct msgbuf *a2,   size_t a3,   long a4,   int a5) 

/* , line:  */
SYSREAL_define_syscall(_getuid,0)

/* , line:  */
SYSREAL_define_syscall(_getgid,0)

/* , line:  */
SYSREAL_define_syscall(_time,1, time_t *a1) 

/* , line:  */
SYSREAL_define_syscall(_adjtimex,1, struct timex *a1) 

/* , line:  */
SYSREAL_define_syscall(_setregid,2, gid_t a1,   gid_t a2) 

/* , line:  */
SYSREAL_define_syscall(_io_submit,3, aio_context_t a1,   long a2,   struct iocb **a3) 

/* , line:  */
SYSREAL_define_syscall(_setns,2, int a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_chown,3, const char *a1,   uid_t a2,   gid_t a3) 

/* , line:  */
SYSREAL_define_syscall(_getsid,1, pid_t a1) 

/* , line:  */
SYSREAL_define_syscall(__sysctl,1, struct __sysctl_args *a1) 

/* , line:  */
SYSREAL_define_syscall(_renameat2,5, int a1,   const char  *a2,   int a3,   const char  *a4,   unsigned int a5) 

/* , line:  */
SYSREAL_define_syscall(_pwrite64,4, unsigned int a1,   const char *a2,   size_t a3,   loff_t a4) 

/* , line:  */
SYSREAL_define_syscall(_setsid,0)

/* , line:  */
SYSREAL_define_syscall(_fchmod,2, unsigned int a1,   mode_t a2) 

/* , line:  */
SYSREAL_define_syscall(_writev,3, unsigned long a1,   const struct iovec *a2,   unsigned long a3) 

/* , line:  */
SYSREAL_define_syscall(_getegid,0)

/* , line:  */
SYSREAL_define_syscall(_timerfd_gettime,2, int a1,   struct itimerspec *a2) 

/* , line:  */
SYSREAL_define_syscall(_lsetxattr,5, const char *a1,   const char *a2,   const void *a3,  size_t a4,   int a5) 

/* , line:  */
SYSREAL_define_syscall(_name_to_handle_at,5, int a1,   const char *a2,   struct file_handle *a3,   int *a4,   int a5) 

/* , line:  */
SYSREAL_define_syscall(_sched_yield,0)

/* , line:  */
SYSREAL_define_syscall(_symlinkat,3, const char *a1,   int a2,   const char *a3) 

/* , line:  */
SYSREAL_define_syscall(_reboot,4, int a1,   int a2,   unsigned int a3,   void *a4) 

/* , line:  */
SYSREAL_define_syscall(_dup3,3, unsigned int a1,   unsigned int a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_sched_setscheduler,3, pid_t a1,   int a2,   struct sched_param *a3) 

/* , line:  */
SYSREAL_define_syscall(_readlink,3, const char *a1,   char *a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_dup2,2, unsigned int a1,   unsigned int a2) 

/* , line:  */
SYSREAL_define_syscall(_fchown,3, unsigned int a1,   uid_t a2,   gid_t a3) 

/* , line:  */
SYSREAL_define_syscall(_timer_getoverrun,1, timer_t a1) 

/* , line:  */
SYSREAL_define_syscall(_socketpair,4, int a1,   int a2,   int a3,   int *a4) 

/* , line:  */
SYSREAL_define_syscall(_fanotify_init,2, unsigned int a1,   unsigned int a2) 

/* , line:  */
SYSREAL_define_syscall(_setuid,1, uid_t a1) 

/* , line:  */
SYSREAL_define_syscall(_setgid,1, gid_t a1) 

/* , line:  */
SYSREAL_define_syscall(_eventfd,1, unsigned int a1) 

/* , line:  */
SYSREAL_define_syscall(_mmap,6, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5,   unsigned long a6) 

/* , line:  */
SYSREAL_define_syscall(_mincore,3, unsigned long a1,   size_t a2,   unsigned char *a3) 

/* , line:  */
SYSREAL_define_syscall(_semget,3, key_t a1,   int a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_pipe,1, int *a1) 

/* , line:  */
SYSREAL_define_syscall(_epoll_create1,1, int a1) 

/* , line:  */
SYSREAL_define_syscall(_msync,3, unsigned long a1,   size_t a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_inotify_rm_watch,2, int a1,   __s32 a2) 

/* , line:  */
SYSREAL_define_syscall(_capget,2, cap_user_header_t a1,   cap_user_data_t a2) 

/* , line:  */
SYSREAL_define_syscall(_fchdir,1, unsigned int a1) 

/* , line:  */
SYSREAL_define_syscall(_mprotect,3, unsigned long a1,   size_t a2,   unsigned long a3) 

/* , line:  */
SYSREAL_define_syscall(_timerfd_settime,4, int a1,   int a2,   const struct itimerspec *a3,   struct itimerspec *a4) 

/* , line:  */
SYSREAL_define_syscall(_exit,1, int a1) 

/* , line:  */
SYSREAL_define_syscall(_capset,2, cap_user_header_t a1,   const cap_user_data_t a2) 

/* , line:  */
SYSREAL_define_syscall(_swapon,2, const char *a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_sched_getattr,4, pid_t a1,   struct sched_attr  *a2,   unsigned int a3,   unsigned int a4) 

/* , line:  */
SYSREAL_define_syscall(_setsockopt,5, int a1,   int a2,   int a3,   char *a4,   int a5) 

/* , line:  */
SYSREAL_define_syscall(_perf_event_open,5, struct perf_event_attr *a1,   pid_t a2,   int a3,   int a4,   unsigned long a5) 

/* , line:  */
SYSREAL_define_syscall(_getdents64,3, unsigned int a1,   struct linux_dirent64 *a2,   unsigned int a3) 

/* , line:  */
SYSREAL_define_syscall(_io_cancel,3, aio_context_t a1,   struct iocb *a2,   struct io_event *a3) 

/* , line:  */
SYSREAL_define_syscall(_getpriority,2, int a1,   int a2) 

/* , line:  */
SYSREAL_define_syscall(_recvmsg,3, int a1,   struct msghdr *a2,   unsigned int a3) 

/* , line:  */
SYSREAL_define_syscall(_arch_prctl,3, struct task_struct *a1,   int a2,   unsigned long *a3) 

/* , line:  */
SYSREAL_define_syscall(_rename,2, const char *a1,   const char *a2) 

/* , line:  */
SYSREAL_define_syscall(_iopl,2, unsigned int a1,   struct pt_regs *a2) 

/* , line:  */
SYSREAL_define_syscall(_rt_sigprocmask,4, int a1,   sigset_t *a2,   sigset_t *a3,   size_t a4) 

/* , line:  */
SYSREAL_define_syscall(_settimeofday,2, struct timeval *a1,   struct timezone *a2) 

/* , line:  */
SYSREAL_define_syscall(_vhangup,0)

/* , line:  */
SYSREAL_define_syscall(_kexec_load,4, unsigned long a1,   unsigned long a2,   struct kexec_segment *a3,   unsigned long a4) 

/* , line:  */
SYSREAL_define_syscall(_flock,2, unsigned int a1,   unsigned int a2) 

/* , line:  */
SYSREAL_define_syscall(_pivot_root,2, const char *a1,   const char *a2) 

/* , line:  */
SYSREAL_define_syscall(_rmdir,1, const char *a1) 

/* , line:  */
SYSREAL_define_syscall(_pause,0)

/* , line:  */
SYSREAL_define_syscall(_utime,2, char *a1,   struct utimbuf *a2) 

/* , line:  */
SYSREAL_define_syscall(_unlinkat,3, int a1,   const char *a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_lchown,3, const char *a1,   uid_t a2,   gid_t a3) 

/* , line:  */
SYSREAL_define_syscall(_shmdt,1, char *a1) 

/* , line:  */
SYSREAL_define_syscall(_shmat,3, int a1,   char *a2,   int a3) 

/* , line:  */
SYSREAL_define_syscall(_fdatasync,1, unsigned int a1) 

/* , line:  */
SYSREAL_define_syscall(_tee,4, int a1,   int a2,   size_t a3,   unsigned int a4) 

/* , line:  */
SYSREAL_define_syscall(_pread64,4, unsigned long a1,   char *a2,   size_t a3,   loff_t a4) 

/* , line:  */
SYSREAL_define_syscall(_timer_settime,4, timer_t a1,   int a2,   const struct itimerspec *a3,   struct itimerspec *a4) 

/* , line:  */
SYSREAL_define_syscall(_rt_sigqueueinfo,3, pid_t a1,   int a2,   siginfo_t *a3) 

/* , line:  */
SYSREAL_define_syscall(_nanosleep,2, struct timespec *a1,   struct timespec *a2) 

/* , line:  */
SYSREAL_define_syscall(_sched_getaffinity,3, pid_t a1,   unsigned int a2,   unsigned long *a3) 

/* , line:  */
SYSREAL_define_syscall(_fsetxattr,5, int a1,   const char *a2,   const void *a3,   size_t a4,  int a5) 

/* --- generated-macros-end: syscalldefs --- */
//#endif

#pragma GCC diagnostic pop

#endif
