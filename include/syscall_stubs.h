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
typedef aio_context_t;
typedef siginfo_t;
struct utimbuf;
struct sched_attr;
struct sched_param;
typedef key_serial_t;
typedef loff_t;
typedef qid_t;
typedef mqd_t;
typedef stack_t;
typedef umode_t;
typedef cap_user_data_t;
typedef cap_user_header_t;
typedef unsigned long u64;
typedef unsigned int u32;
union semun;

//

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
/* --- generated-macros-start: syscalldefs --- */
/* minilib/include/syscalls_x64.h, line: 394 */
REAL_define_syscall(llistxattr,3, const char *a1,   char *a2,   size_t a3) 

/* minilib/include/syscalls_x64.h, line: 123 */
REAL_define_syscall(execve,3, const char *a1,   const char *const a2,   const char *const a3) 

/* minilib/include/syscalls_x64.h, line: 461 */
REAL_define_syscall(clock_settime,2, const clockid_t a1,   const struct timespec *a2) 

/* minilib/include/syscalls_x64.h, line: 594 */
REAL_define_syscall(pipe2,2, int *a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 333 */
REAL_define_syscall(settimeofday,2, struct timeval *a1,   struct timezone *a2) 

/* minilib/include/syscalls_x64.h, line: 291 */
REAL_define_syscall(sched_getparam,2, pid_t a1,   struct sched_param *a2) 

/* minilib/include/syscalls_x64.h, line: 201 */
REAL_define_syscall(getrusage,2, int a1,   struct rusage *a2) 

/* minilib/include/syscalls_x64.h, line: 524 */
REAL_define_syscall(mkdirat,3, int a1,   const char *a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 429 */
REAL_define_syscall(lookup_dcookie,3, u64 a1,   long a2,   long a3) 

/* minilib/include/syscalls_x64.h, line: 135 */
REAL_define_syscall(semop,3, int a1,   struct sembuf *a2,   unsigned a3) 

/* minilib/include/syscalls_x64.h, line: 592 */
REAL_define_syscall(dup3,3, unsigned int a1,   unsigned int a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 496 */
REAL_define_syscall(mq_notify,2, mqd_t a1,   const struct sigevent *a2) 

/* minilib/include/syscalls_x64.h, line: 640 */
REAL_define_syscall(renameat2,5, int a1,   const char  *a2,   int a3,   const char  *a4,   unsigned int a5) 

/* minilib/include/syscalls_x64.h, line: 520 */
REAL_define_syscall(migrate_pages,4, pid_t a1,   unsigned long a2,   const unsigned long *a3,   const unsigned long *a4) 

/* minilib/include/syscalls_x64.h, line: 512 */
REAL_define_syscall(ioprio_get,2, int a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 420 */
REAL_define_syscall(io_getevents,4, aio_context_t a1,   long a2,   long a3,   struct io_event *a4) 

/* minilib/include/syscalls_x64.h, line: 121 */
REAL_define_syscall(vfork,0)

/* minilib/include/syscalls_x64.h, line: 219 */
REAL_define_syscall(geteuid,0)

/* minilib/include/syscalls_x64.h, line: 400 */
REAL_define_syscall(lremovexattr,2, const char *a1,   const char *a2) 

/* minilib/include/syscalls_x64.h, line: 271 */
REAL_define_syscall(mknod,3, const char *a1,   umode_t a2,   unsigned a3) 

/* minilib/include/syscalls_x64.h, line: 570 */
REAL_define_syscall(epoll_pwait,5, int a1,   struct epoll_event *a2,   int a3,   int a4,   const sigset_t *a5, size_t a6) 

/* minilib/include/syscalls_x64.h, line: 281 */
REAL_define_syscall(fstatfs,2, unsigned int a1,   struct statfs *a2) 

/* minilib/include/syscalls_x64.h, line: 77 */
REAL_define_syscall(getitimer,2, int a1,   struct itimerval *a2) 

/* minilib/include/syscalls_x64.h, line: 471 */
REAL_define_syscall(epoll_wait,4, int a1,   struct epoll_event *a2,   int a3,   int a4) 

/* minilib/include/syscalls_x64.h, line: 443 */
REAL_define_syscall(set_tid_address,1, int *a1) 

/* minilib/include/syscalls_x64.h, line: 9 */
REAL_define_syscall(open,3, const char *a1,   int a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 15 */
REAL_define_syscall(fstat,2, unsigned int a1,   struct stat *a2) 

/* minilib/include/syscalls_x64.h, line: 251 */
REAL_define_syscall(setfsgid,1, gid_t a1) 

/* minilib/include/syscalls_x64.h, line: 277 */
REAL_define_syscall(ustat,2, unsigned a1,   struct ustat *a2) 

/* minilib/include/syscalls_x64.h, line: 582 */
REAL_define_syscall(timerfd_gettime,2, int a1,   struct itimerspec *a2) 

/* minilib/include/syscalls_x64.h, line: 89 */
REAL_define_syscall(connect,3, int a1,   struct sockaddr *a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 227 */
REAL_define_syscall(getpgrp,0)

/* minilib/include/syscalls_x64.h, line: 305 */
REAL_define_syscall(munlock,2, unsigned long a1,   size_t a2) 

/* minilib/include/syscalls_x64.h, line: 488 */
REAL_define_syscall(mq_open,4, const char *a1,   int a2,   mode_t a3,   struct mq_attr *a4) 

/* minilib/include/syscalls_x64.h, line: 386 */
REAL_define_syscall(getxattr,4, const char *a1,   const char *a2,   void *a3,   size_t a4) 

/* minilib/include/syscalls_x64.h, line: 311 */
REAL_define_syscall(vhangup,0)

/* minilib/include/syscalls_x64.h, line: 181 */
REAL_define_syscall(symlink,2, const char *a1,   const char *a2) 

/* minilib/include/syscalls_x64.h, line: 614 */
REAL_define_syscall(name_to_handle_at,5, int a1,   const char *a2,   struct file_handle *a3,   int *a4,   int a5) 

/* minilib/include/syscalls_x64.h, line: 574 */
REAL_define_syscall(timerfd_create,2, int a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 129 */
REAL_define_syscall(kill,2, pid_t a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 392 */
REAL_define_syscall(listxattr,3, const char *a1,   char *a2,   size_t a3) 

/* minilib/include/syscalls_x64.h, line: 408 */
REAL_define_syscall(futex,5, u32 *a1,   int a2,   u32 a3,   struct timespec *a4,   u32 *a5, u32 a6) 

/* minilib/include/syscalls_x64.h, line: 424 */
REAL_define_syscall(io_cancel,3, aio_context_t a1,   struct iocb *a2,   struct io_event *a3) 

/* minilib/include/syscalls_x64.h, line: 97 */
REAL_define_syscall(sendmsg,3, int a1,   struct msghdr *a2,   unsigned a3) 

/* minilib/include/syscalls_x64.h, line: 412 */
REAL_define_syscall(sched_getaffinity,3, pid_t a1,   unsigned int a2,   unsigned long *a3) 

/* minilib/include/syscalls_x64.h, line: 632 */
REAL_define_syscall(kcmp,5, pid_t a1,   pid_t a2,   int a3,   unsigned long a4,   unsigned long a5) 

/* minilib/include/syscalls_x64.h, line: 502 */
REAL_define_syscall(waitid,5, int a1,   pid_t a2,   struct siginfo *a3,   int a4,   struct rusage *a5) 

/* minilib/include/syscalls_x64.h, line: 329 */
REAL_define_syscall(sync,0)

/* minilib/include/syscalls_x64.h, line: 596 */
REAL_define_syscall(inotify_init1,1, int a1) 

/* minilib/include/syscalls_x64.h, line: 197 */
REAL_define_syscall(gettimeofday,2, struct timeval *a1,   struct timezone *a2) 

/* minilib/include/syscalls_x64.h, line: 313 */
REAL_define_syscall(modify_ldt,3, int a1,   void *a2,   unsigned long a3) 

/* minilib/include/syscalls_x64.h, line: 27 */
REAL_define_syscall(munmap,2, unsigned long a1,   size_t a2) 

/* minilib/include/syscalls_x64.h, line: 469 */
REAL_define_syscall(exit_group,1, int a1) 

/* minilib/include/syscalls_x64.h, line: 622 */
REAL_define_syscall(sendmmsg,4, int a1,   struct mmsghdr *a2,   unsigned int a3,   unsigned int a4) 

/* minilib/include/syscalls_x64.h, line: 580 */
REAL_define_syscall(timerfd_settime,4, int a1,   int a2,   const struct itimerspec *a3,   struct itimerspec *a4) 

/* minilib/include/syscalls_x64.h, line: 279 */
REAL_define_syscall(statfs,2, const char *a1,   struct statfs *a2) 

/* minilib/include/syscalls_x64.h, line: 453 */
REAL_define_syscall(timer_settime,4, timer_t a1,   int a2,   const struct itimerspec *a3,   struct itimerspec *a4) 

/* minilib/include/syscalls_x64.h, line: 380 */
REAL_define_syscall(setxattr,5, const char *a1,   const char *a2,   const void *a3,  size_t a4,   int a5) 

/* minilib/include/syscalls_x64.h, line: 259 */
REAL_define_syscall(rt_sigpending,2, sigset_t *a1,   size_t a2) 

/* minilib/include/syscalls_x64.h, line: 301 */
REAL_define_syscall(sched_rr_get_interval,2, pid_t a1,   struct timespec *a2) 

/* minilib/include/syscalls_x64.h, line: 538 */
REAL_define_syscall(linkat,5, int a1,   const char *a2,   int a3,   const char *a4,   int a5) 

/* minilib/include/syscalls_x64.h, line: 602 */
REAL_define_syscall(rt_tgsigqueueinfo,4, pid_t a1,   pid_t a2,   int a3,   siginfo_t *a4) 

/* minilib/include/syscalls_x64.h, line: 179 */
REAL_define_syscall(unlink,1, const char *a1) 

/* minilib/include/syscalls_x64.h, line: 41 */
REAL_define_syscall(pwrite64,4, unsigned int a1,   const char *a2,   size_t a3,   loff_t a4) 

/* minilib/include/syscalls_x64.h, line: 143 */
REAL_define_syscall(msgsnd,4, int a1,   struct msgbuf *a2,   size_t a3,   int a4) 

/* minilib/include/syscalls_x64.h, line: 406 */
REAL_define_syscall(time,1, time_t *a1) 

/* minilib/include/syscalls_x64.h, line: 398 */
REAL_define_syscall(removexattr,2, const char *a1,   const char *a2) 

/* minilib/include/syscalls_x64.h, line: 590 */
REAL_define_syscall(epoll_create1,1, int a1) 

/* minilib/include/syscalls_x64.h, line: 167 */
REAL_define_syscall(fchdir,1, unsigned int a1) 

/* minilib/include/syscalls_x64.h, line: 616 */
REAL_define_syscall(open_by_handle_at,5, int a1,   const char *a2,   struct file_handle *a3,   int *a4,   int a5) 

/* minilib/include/syscalls_x64.h, line: 566 */
REAL_define_syscall(move_pages,5, pid_t a1,   unsigned long a2,   const void **a3,  const int *a4,   int *a5, int a6) 

/* minilib/include/syscalls_x64.h, line: 165 */
REAL_define_syscall(chdir,1, const char *a1) 

/* minilib/include/syscalls_x64.h, line: 644 */
REAL_define_syscall(getrandom,3, char  *a1,   size_t a2,   unsigned int a3) 

/* minilib/include/syscalls_x64.h, line: 323 */
REAL_define_syscall(adjtimex,1, struct timex *a1) 

/* minilib/include/syscalls_x64.h, line: 317 */
REAL_define_syscall(_sysctl,1, struct __sysctl_args *a1) 

/* minilib/include/syscalls_x64.h, line: 81 */
REAL_define_syscall(setitimer,3, int a1,   struct itimerval *a2,   struct itimerval *a3) 

/* minilib/include/syscalls_x64.h, line: 187 */
REAL_define_syscall(fchmod,2, unsigned int a1,   mode_t a2) 

/* minilib/include/syscalls_x64.h, line: 337 */
REAL_define_syscall(umount2,2, const char *a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 612 */
REAL_define_syscall(prlimit64,4, pid_t a1,   unsigned int a2,   const struct rlimit64 *a3,   struct rlimit64 *a4) 

/* minilib/include/syscalls_x64.h, line: 177 */
REAL_define_syscall(link,2, const char *a1,   const char *a2) 

/* minilib/include/syscalls_x64.h, line: 546 */
REAL_define_syscall(faccessat,3, int a1,   const char *a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 578 */
REAL_define_syscall(fallocate,4, long a1,   long a2,   loff_t a3,   loff_t a4) 

/* minilib/include/syscalls_x64.h, line: 498 */
REAL_define_syscall(mq_getsetattr,3, mqd_t a1,   const struct mq_attr *a2,   struct mq_attr *a3) 

/* minilib/include/syscalls_x64.h, line: 151 */
REAL_define_syscall(flock,2, unsigned int a1,   unsigned int a2) 

/* minilib/include/syscalls_x64.h, line: 183 */
REAL_define_syscall(readlink,3, const char *a1,   char *a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 486 */
REAL_define_syscall(get_mempolicy,5, int *a1,   unsigned long *a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* minilib/include/syscalls_x64.h, line: 504 */
REAL_define_syscall(add_key,4, const char *a1,   const char *a2,   const void *a3,   size_t a4) 

/* minilib/include/syscalls_x64.h, line: 604 */
REAL_define_syscall(perf_event_open,5, struct perf_event_attr *a1,   pid_t a2,   int a3,   int a4,   unsigned long a5) 

/* minilib/include/syscalls_x64.h, line: 447 */
REAL_define_syscall(semtimedop,4, int a1,   struct sembuf *a2,   unsigned a3,   const struct timespec *a4) 

/* minilib/include/syscalls_x64.h, line: 530 */
REAL_define_syscall(futimesat,3, int a1,   const char *a2,   struct timeval *a3) 

/* minilib/include/syscalls_x64.h, line: 576 */
REAL_define_syscall(eventfd,1, unsigned int a1) 

/* minilib/include/syscalls_x64.h, line: 492 */
REAL_define_syscall(mq_timedsend,5, mqd_t a1,   const char *a2,   size_t a3,   unsigned int a4,   const struct timespec *a5) 

/* minilib/include/syscalls_x64.h, line: 245 */
REAL_define_syscall(getresgid,3, gid_t *a1,   gid_t *a2,   gid_t *a3) 

/* minilib/include/syscalls_x64.h, line: 199 */
REAL_define_syscall(getrlimit,2, unsigned int a1,   struct rlimit *a2) 

/* minilib/include/syscalls_x64.h, line: 75 */
REAL_define_syscall(nanosleep,2, struct timespec *a1,   struct timespec *a2) 

/* minilib/include/syscalls_x64.h, line: 451 */
REAL_define_syscall(timer_create,3, const clockid_t a1,   struct sigevent *a2,   timer_t *a3) 

/* minilib/include/syscalls_x64.h, line: 588 */
REAL_define_syscall(eventfd2,2, unsigned int a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 83 */
REAL_define_syscall(getpid,0)

/* minilib/include/syscalls_x64.h, line: 37 */
REAL_define_syscall(ioctl,3, unsigned int a1,   unsigned int a2,   unsigned long a3) 

/* minilib/include/syscalls_x64.h, line: 235 */
REAL_define_syscall(getgroups,2, int a1,   gid_t *a2) 

/* minilib/include/syscalls_x64.h, line: 634 */
REAL_define_syscall(finit_module,3, int a1,   const char *a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 457 */
REAL_define_syscall(timer_getoverrun,1, timer_t a1) 

/* minilib/include/syscalls_x64.h, line: 610 */
REAL_define_syscall(fanotify_mark,5, long a1,   long a2,   u64 a3,   long a4,  long a5) 

/* minilib/include/syscalls_x64.h, line: 345 */
REAL_define_syscall(sethostname,2, char *a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 445 */
REAL_define_syscall(restart_syscall,0)

/* minilib/include/syscalls_x64.h, line: 465 */
REAL_define_syscall(clock_getres,2, const clockid_t a1,   struct timespec *a2) 

/* minilib/include/syscalls_x64.h, line: 87 */
REAL_define_syscall(socket,3, int a1,   int a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 528 */
REAL_define_syscall(fchownat,5, int a1,   const char *a2,   uid_t a3,   gid_t a4,   int a5) 

/* minilib/include/syscalls_x64.h, line: 61 */
REAL_define_syscall(madvise,3, unsigned long a1,   size_t a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 558 */
REAL_define_syscall(splice,5, int a1,   loff_t *a2,   int a3,   loff_t *a4,  size_t a5, unsigned int a6) 

/* minilib/include/syscalls_x64.h, line: 117 */
REAL_define_syscall(clone,4, unsigned long a1,   unsigned long a2,   void *a3,   void *a4) 

/* minilib/include/syscalls_x64.h, line: 638 */
REAL_define_syscall(sched_getattr,4, pid_t a1,   struct sched_attr  *a2,   unsigned int a3,   unsigned int a4) 

/* minilib/include/syscalls_x64.h, line: 325 */
REAL_define_syscall(setrlimit,2, unsigned int a1,   struct rlimit *a2) 

/* minilib/include/syscalls_x64.h, line: 568 */
REAL_define_syscall(utimensat,4, int a1,   const char *a2,   struct timespec *a3,  int a4) 

/* minilib/include/syscalls_x64.h, line: 243 */
REAL_define_syscall(setresgid,3, gid_t a1,   gid_t a2,   gid_t a3) 

/* minilib/include/syscalls_x64.h, line: 396 */
REAL_define_syscall(flistxattr,3, int a1,   char *a2,   size_t a3) 

/* minilib/include/syscalls_x64.h, line: 650 */
REAL_define_syscall(bpf,3, int a1,   union bpf_attr *a2,   unsigned int a3) 

/* minilib/include/syscalls_x64.h, line: 473 */
REAL_define_syscall(epoll_ctl,4, int a1,   int a2,   int a3,   struct epoll_event *a4) 

/* minilib/include/syscalls_x64.h, line: 431 */
REAL_define_syscall(epoll_create,1, int a1) 

/* minilib/include/syscalls_x64.h, line: 169 */
REAL_define_syscall(rename,2, const char *a1,   const char *a2) 

/* minilib/include/syscalls_x64.h, line: 484 */
REAL_define_syscall(set_mempolicy,3, int a1,   unsigned long *a2,   unsigned long a3) 

/* minilib/include/syscalls_x64.h, line: 309 */
REAL_define_syscall(munlockall,0)

/* minilib/include/syscalls_x64.h, line: 59 */
REAL_define_syscall(mincore,3, unsigned long a1,   size_t a2,   unsigned char *a3) 

/* minilib/include/syscalls_x64.h, line: 522 */
REAL_define_syscall(openat,4, int a1,   const char *a2,   int a3,   int a4) 

/* minilib/include/syscalls_x64.h, line: 109 */
REAL_define_syscall(getpeername,3, int a1,   struct sockaddr *a2,   int *a3) 

/* minilib/include/syscalls_x64.h, line: 131 */
REAL_define_syscall(uname,1, struct old_utsname *a1) 

/* minilib/include/syscalls_x64.h, line: 540 */
REAL_define_syscall(symlinkat,3, const char *a1,   int a2,   const char *a3) 

/* minilib/include/syscalls_x64.h, line: 105 */
REAL_define_syscall(listen,2, int a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 171 */
REAL_define_syscall(mkdir,2, const char *a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 618 */
REAL_define_syscall(clock_adjtime,2, clockid_t a1,   struct timex *a2) 

/* minilib/include/syscalls_x64.h, line: 267 */
REAL_define_syscall(sigaltstack,2, const stack_t *a1,   stack_t *a2) 

/* minilib/include/syscalls_x64.h, line: 65 */
REAL_define_syscall(shmat,3, int a1,   char *a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 57 */
REAL_define_syscall(msync,3, unsigned long a1,   size_t a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 548 */
REAL_define_syscall(pselect6,5, int a1,   fd_set *a2,   fd_set *a3,   fd_set *a4,   struct timespec *a5, void *a6) 

/* minilib/include/syscalls_x64.h, line: 514 */
REAL_define_syscall(inotify_init,0)

/* minilib/include/syscalls_x64.h, line: 402 */
REAL_define_syscall(fremovexattr,2, int a1,   const char *a2) 

/* minilib/include/syscalls_x64.h, line: 211 */
REAL_define_syscall(syslog,3, int a1,   char *a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 195 */
REAL_define_syscall(umask,1, int a1) 

/* minilib/include/syscalls_x64.h, line: 526 */
REAL_define_syscall(mknodat,4, int a1,   const char *a2,   int a3,   unsigned a4) 

/* minilib/include/syscalls_x64.h, line: 516 */
REAL_define_syscall(inotify_add_watch,3, int a1,   const char *a2,   u32 a3) 

/* minilib/include/syscalls_x64.h, line: 550 */
REAL_define_syscall(ppoll,5, struct pollfd *a1,   unsigned int a2,   struct timespec *a3,   const sigset_t *a4,   size_t a5) 

/* minilib/include/syscalls_x64.h, line: 45 */
REAL_define_syscall(writev,3, unsigned long a1,   const struct iovec *a2,   unsigned long a3) 

/* minilib/include/syscalls_x64.h, line: 17 */
REAL_define_syscall(lstat,2, const char *a1,   struct stat *a2) 

/* minilib/include/syscalls_x64.h, line: 475 */
REAL_define_syscall(tgkill,3, pid_t a1,   pid_t a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 441 */
REAL_define_syscall(getdents64,3, unsigned int a1,   struct linux_dirent64 *a2,   unsigned int a3) 

/* minilib/include/syscalls_x64.h, line: 127 */
REAL_define_syscall(wait4,4, pid_t a1,   int *a2,   int a3,   struct rusage *a4) 

/* minilib/include/syscalls_x64.h, line: 249 */
REAL_define_syscall(setfsuid,1, uid_t a1) 

/* minilib/include/syscalls_x64.h, line: 293 */
REAL_define_syscall(sched_setscheduler,3, pid_t a1,   int a2,   struct sched_param *a3) 

/* minilib/include/syscalls_x64.h, line: 145 */
REAL_define_syscall(msgrcv,5, int a1,   struct msgbuf *a2,   size_t a3,   long a4,   int a5) 

/* minilib/include/syscalls_x64.h, line: 237 */
REAL_define_syscall(setgroups,2, int a1,   gid_t *a2) 

/* minilib/include/syscalls_x64.h, line: 319 */
REAL_define_syscall(prctl,3, int a1,   unsigned long a2,   unsigned long a3,  unsigned a4) 

/* minilib/include/syscalls_x64.h, line: 303 */
REAL_define_syscall(mlock,2, unsigned long a1,   size_t a2) 

/* minilib/include/syscalls_x64.h, line: 321 */
REAL_define_syscall(arch_prctl,3, struct task_struct *a1,   int a2,   unsigned long *a3) 

/* minilib/include/syscalls_x64.h, line: 572 */
REAL_define_syscall(signalfd,3, int a1,   sigset_t *a2,   size_t a3) 

/* minilib/include/syscalls_x64.h, line: 193 */
REAL_define_syscall(lchown,3, const char *a1,   uid_t a2,   gid_t a3) 

/* minilib/include/syscalls_x64.h, line: 287 */
REAL_define_syscall(setpriority,3, int a1,   int a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 544 */
REAL_define_syscall(fchmodat,3, int a1,   const char *a2,   mode_t a3) 

/* minilib/include/syscalls_x64.h, line: 159 */
REAL_define_syscall(ftruncate,2, unsigned int a1,   unsigned long a2) 

/* minilib/include/syscalls_x64.h, line: 107 */
REAL_define_syscall(getsockname,3, int a1,   struct sockaddr *a2,   int *a3) 

/* minilib/include/syscalls_x64.h, line: 215 */
REAL_define_syscall(setuid,1, uid_t a1) 

/* minilib/include/syscalls_x64.h, line: 207 */
REAL_define_syscall(ptrace,4, long a1,   long a2,   unsigned long a3,   unsigned long a4) 

/* minilib/include/syscalls_x64.h, line: 85 */
REAL_define_syscall(sendfile,4, int a1,   int a2,   off_t *a3,   size_t a4) 

/* minilib/include/syscalls_x64.h, line: 620 */
REAL_define_syscall(syncfs,1, int a1) 

/* minilib/include/syscalls_x64.h, line: 101 */
REAL_define_syscall(shutdown,2, int a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 265 */
REAL_define_syscall(rt_sigsuspend,2, sigset_t *a1,   size_t a2) 

/* minilib/include/syscalls_x64.h, line: 269 */
REAL_define_syscall(utime,2, char *a1,   struct utimbuf *a2) 

/* minilib/include/syscalls_x64.h, line: 642 */
REAL_define_syscall(seccomp,3, unsigned int a1,   unsigned int a2,   const char  *a3) 

/* minilib/include/syscalls_x64.h, line: 13 */
REAL_define_syscall(stat,2, const char *a1,   struct stat *a2) 

/* minilib/include/syscalls_x64.h, line: 147 */
REAL_define_syscall(msgctl,3, int a1,   int a2,   struct msqid_ds *a3) 

/* minilib/include/syscalls_x64.h, line: 53 */
REAL_define_syscall(sched_yield,0)

/* minilib/include/syscalls_x64.h, line: 534 */
REAL_define_syscall(unlinkat,3, int a1,   const char *a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 295 */
REAL_define_syscall(sched_getscheduler,1, pid_t a1) 

/* minilib/include/syscalls_x64.h, line: 416 */
REAL_define_syscall(io_setup,2, unsigned a1,   aio_context_t *a2) 

/* minilib/include/syscalls_x64.h, line: 606 */
REAL_define_syscall(recvmmsg,5, int a1,   struct msghdr *a2,   unsigned int a3,   unsigned int a4,   struct timespec *a5) 

/* minilib/include/syscalls_x64.h, line: 500 */
REAL_define_syscall(kexec_load,4, unsigned long a1,   unsigned long a2,   struct kexec_segment *a3,   unsigned long a4) 

/* minilib/include/syscalls_x64.h, line: 624 */
REAL_define_syscall(setns,2, int a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 347 */
REAL_define_syscall(setdomainname,2, char *a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 636 */
REAL_define_syscall(sched_setattr,3, pid_t a1,   struct sched_attr  *a2,   unsigned int a3) 

/* minilib/include/syscalls_x64.h, line: 25 */
REAL_define_syscall(mprotect,3, unsigned long a1,   size_t a2,   unsigned long a3) 

/* minilib/include/syscalls_x64.h, line: 349 */
REAL_define_syscall(iopl,2, unsigned int a1,   struct pt_regs *a2) 

/* minilib/include/syscalls_x64.h, line: 564 */
REAL_define_syscall(vmsplice,4, int a1,   const struct iovec *a2,   unsigned long a3,  unsigned int a4) 

/* minilib/include/syscalls_x64.h, line: 467 */
REAL_define_syscall(clock_nanosleep,4, const clockid_t a1,   int a2,   const struct timespec *a3,   struct timespec *a4) 

/* minilib/include/syscalls_x64.h, line: 99 */
REAL_define_syscall(recvmsg,3, int a1,   struct msghdr *a2,   unsigned int a3) 

/* minilib/include/syscalls_x64.h, line: 247 */
REAL_define_syscall(getpgid,1, pid_t a1) 

/* minilib/include/syscalls_x64.h, line: 79 */
REAL_define_syscall(alarm,1, unsigned int a1) 

/* minilib/include/syscalls_x64.h, line: 477 */
REAL_define_syscall(utimes,2, char *a1,   struct timeval *a2) 

/* minilib/include/syscalls_x64.h, line: 586 */
REAL_define_syscall(signalfd4,4, int a1,   sigset_t *a2,   size_t a3,   int a4) 

/* minilib/include/syscalls_x64.h, line: 315 */
REAL_define_syscall(pivot_root,2, const char *a1,   const char *a2) 

/* minilib/include/syscalls_x64.h, line: 339 */
REAL_define_syscall(swapon,2, const char *a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 161 */
REAL_define_syscall(getdents,3, unsigned int a1,   struct linux_dirent *a2,   unsigned int a3) 

/* minilib/include/syscalls_x64.h, line: 67 */
REAL_define_syscall(shmctl,3, int a1,   int a2,   struct shmid_ds *a3) 

/* minilib/include/syscalls_x64.h, line: 73 */
REAL_define_syscall(pause,0)

/* minilib/include/syscalls_x64.h, line: 229 */
REAL_define_syscall(setsid,0)

/* minilib/include/syscalls_x64.h, line: 299 */
REAL_define_syscall(sched_get_priority_min,1, int a1) 

/* minilib/include/syscalls_x64.h, line: 163 */
REAL_define_syscall(getcwd,2, char *a1,   unsigned long a2) 

/* minilib/include/syscalls_x64.h, line: 331 */
REAL_define_syscall(acct,1, const char *a1) 

/* minilib/include/syscalls_x64.h, line: 133 */
REAL_define_syscall(semget,3, key_t a1,   int a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 646 */
REAL_define_syscall(memfd_create,2, const char  *a1,   unsigned int a2) 

/* minilib/include/syscalls_x64.h, line: 263 */
REAL_define_syscall(rt_sigqueueinfo,3, pid_t a1,   int a2,   siginfo_t *a3) 

/* minilib/include/syscalls_x64.h, line: 119 */
REAL_define_syscall(fork,0)

/* minilib/include/syscalls_x64.h, line: 21 */
REAL_define_syscall(lseek,3, unsigned int a1,   off_t a2,   unsigned int a3) 

/* minilib/include/syscalls_x64.h, line: 390 */
REAL_define_syscall(fgetxattr,4, int a1,   const char *a2,   void *a3,   size_t a4) 

/* minilib/include/syscalls_x64.h, line: 351 */
REAL_define_syscall(ioperm,3, unsigned long a1,   unsigned long a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 125 */
REAL_define_syscall(exit,1, int a1) 

/* minilib/include/syscalls_x64.h, line: 285 */
REAL_define_syscall(getpriority,2, int a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 275 */
REAL_define_syscall(personality,1, unsigned int a1) 

/* minilib/include/syscalls_x64.h, line: 490 */
REAL_define_syscall(mq_unlink,1, const char *a1) 

/* minilib/include/syscalls_x64.h, line: 69 */
REAL_define_syscall(dup,1, unsigned int a1) 

/* minilib/include/syscalls_x64.h, line: 209 */
REAL_define_syscall(getuid,0)

/* minilib/include/syscalls_x64.h, line: 173 */
REAL_define_syscall(rmdir,1, const char *a1) 

/* minilib/include/syscalls_x64.h, line: 482 */
REAL_define_syscall(mbind,5, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long *a4,   unsigned long a5, unsigned a6) 

/* minilib/include/syscalls_x64.h, line: 648 */
REAL_define_syscall(kexec_file_load,5, int a1,   int a2,   unsigned long a3,   const char *a4,   unsigned long a5) 

/* minilib/include/syscalls_x64.h, line: 439 */
REAL_define_syscall(remap_file_pages,5, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* minilib/include/syscalls_x64.h, line: 494 */
REAL_define_syscall(mq_timedreceive,5, mqd_t a1,   char *a2,   size_t a3,   unsigned int *a4,   const struct timespec *a5) 

/* minilib/include/syscalls_x64.h, line: 155 */
REAL_define_syscall(fdatasync,1, unsigned int a1) 

/* minilib/include/syscalls_x64.h, line: 139 */
REAL_define_syscall(shmdt,1, char *a1) 

/* minilib/include/syscalls_x64.h, line: 103 */
REAL_define_syscall(bind,3, int a1,   struct sokaddr *a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 233 */
REAL_define_syscall(setregid,2, gid_t a1,   gid_t a2) 

/* minilib/include/syscalls_x64.h, line: 149 */
REAL_define_syscall(fcntl,3, unsigned int a1,   unsigned int a2,   unsigned long a3) 

/* minilib/include/syscalls_x64.h, line: 630 */
REAL_define_syscall(process_vm_writev,5, pid_t a1,   const struct iovec *a2,   unsigned long a3,   const struct iovcc *a4,   unsigned long a5, unsigned long a6) 

/* minilib/include/syscalls_x64.h, line: 253 */
REAL_define_syscall(getsid,1, pid_t a1) 

/* minilib/include/syscalls_x64.h, line: 384 */
REAL_define_syscall(fsetxattr,5, int a1,   const char *a2,   const void *a3,   size_t a4,  int a5) 

/* minilib/include/syscalls_x64.h, line: 31 */
REAL_define_syscall(rt_sigaction,4, int a1,   const struct sigaction *a2,   struct sigaction *a3,   size_t a4) 

/* minilib/include/syscalls_x64.h, line: 153 */
REAL_define_syscall(fsync,1, unsigned int a1) 

/* minilib/include/syscalls_x64.h, line: 51 */
REAL_define_syscall(select,5, int a1,   fd_set *a2,   fd_set *a3,   fd_set *a4,   struct timeval *a5) 

/* minilib/include/syscalls_x64.h, line: 11 */
REAL_define_syscall(close,1, unsigned int a1) 

/* minilib/include/syscalls_x64.h, line: 185 */
REAL_define_syscall(chmod,2, const char *a1,   mode_t a2) 

/* minilib/include/syscalls_x64.h, line: 223 */
REAL_define_syscall(setpgid,2, pid_t a1,   pid_t a2) 

/* minilib/include/syscalls_x64.h, line: 560 */
REAL_define_syscall(tee,4, int a1,   int a2,   size_t a3,   unsigned int a4) 

/* minilib/include/syscalls_x64.h, line: 608 */
REAL_define_syscall(fanotify_init,2, unsigned int a1,   unsigned int a2) 

/* minilib/include/syscalls_x64.h, line: 327 */
REAL_define_syscall(chroot,1, const char *a1) 

/* minilib/include/syscalls_x64.h, line: 255 */
REAL_define_syscall(capget,2, cap_user_header_t a1,   cap_user_data_t a2) 

/* minilib/include/syscalls_x64.h, line: 47 */
REAL_define_syscall(access,2, const char *a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 542 */
REAL_define_syscall(readlinkat,4, int a1,   const char *a2,   char *a3,   int a4) 

/* minilib/include/syscalls_x64.h, line: 335 */
REAL_define_syscall(mount,5, char *a1,   char *a2,   char *a3,   unsigned long a4,   void *a5) 

/* minilib/include/syscalls_x64.h, line: 418 */
REAL_define_syscall(io_destroy,1, aio_context_t a1) 

/* minilib/include/syscalls_x64.h, line: 7 */
REAL_define_syscall(write,3, unsigned int a1,   const char *a2,   size_t a3) 

/* minilib/include/syscalls_x64.h, line: 19 */
REAL_define_syscall(poll,3, struct poll_fd *a1,   unsigned int a2,   long a3) 

/* minilib/include/syscalls_x64.h, line: 113 */
REAL_define_syscall(setsockopt,5, int a1,   int a2,   int a3,   char *a4,   int a5) 

/* minilib/include/syscalls_x64.h, line: 29 */
REAL_define_syscall(brk,1, unsigned long a1) 

/* minilib/include/syscalls_x64.h, line: 510 */
REAL_define_syscall(ioprio_set,3, int a1,   int a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 459 */
REAL_define_syscall(timer_delete,1, timer_t a1) 

/* minilib/include/syscalls_x64.h, line: 225 */
REAL_define_syscall(getppid,0)

/* minilib/include/syscalls_x64.h, line: 388 */
REAL_define_syscall(lgetxattr,4, const char *a1,   const char *a2,   void *a3,   size_t a4) 

/* minilib/include/syscalls_x64.h, line: 261 */
REAL_define_syscall(rt_sigtimedwait,4, const sigset_t *a1,   siginfo_t *a2,   const struct timespec *a3,   size_t a4) 

/* minilib/include/syscalls_x64.h, line: 55 */
REAL_define_syscall(mremap,5, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* minilib/include/syscalls_x64.h, line: 584 */
REAL_define_syscall(accept4,4, int a1,   struct sockaddr *a2,   int *a3,   int a4) 

/* minilib/include/syscalls_x64.h, line: 341 */
REAL_define_syscall(swapoff,1, const char *a1) 

/* minilib/include/syscalls_x64.h, line: 556 */
REAL_define_syscall(get_robust_list,3, int a1,   struct robust_list_head **a2,   size_t *a3) 

/* minilib/include/syscalls_x64.h, line: 213 */
REAL_define_syscall(getgid,0)

/* minilib/include/syscalls_x64.h, line: 137 */
REAL_define_syscall(semctl,4, int a1,   int a2,   int a3,   union semun a4) 

/* minilib/include/syscalls_x64.h, line: 231 */
REAL_define_syscall(setreuid,2, uid_t a1,   uid_t a2) 

/* minilib/include/syscalls_x64.h, line: 382 */
REAL_define_syscall(lsetxattr,5, const char *a1,   const char *a2,   const void *a3,  size_t a4,   int a5) 

/* minilib/include/syscalls_x64.h, line: 93 */
REAL_define_syscall(sendto,5, int a1,   void *a2,   size_t a3,   unsigned a4,   struct sockaddr *a5, int a6) 

/* minilib/include/syscalls_x64.h, line: 532 */
REAL_define_syscall(newfstatat,4, int a1,   const char *a2,   struct stat *a3,   int a4) 

/* minilib/include/syscalls_x64.h, line: 536 */
REAL_define_syscall(renameat,4, int a1,   const char *a2,   int a3,   const char *a4) 

/* minilib/include/syscalls_x64.h, line: 410 */
REAL_define_syscall(sched_setaffinity,3, pid_t a1,   unsigned int a2,   unsigned long *a3) 

/* minilib/include/syscalls_x64.h, line: 95 */
REAL_define_syscall(recvfrom,5, int a1,   void *a2,   size_t a3,   unsigned a4,   struct sockaddr *a5, int *a6) 

/* minilib/include/syscalls_x64.h, line: 455 */
REAL_define_syscall(timer_gettime,2, timer_t a1,   struct itimerspec *a2) 

/* minilib/include/syscalls_x64.h, line: 157 */
REAL_define_syscall(truncate,2, const char *a1,   long a2) 

/* minilib/include/syscalls_x64.h, line: 239 */
REAL_define_syscall(setresuid,3, uid_t *a1,   uid_t *a2,   uid_t *a3) 

/* minilib/include/syscalls_x64.h, line: 175 */
REAL_define_syscall(creat,2, const char *a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 257 */
REAL_define_syscall(capset,2, cap_user_header_t a1,   const cap_user_data_t a2) 

/* minilib/include/syscalls_x64.h, line: 43 */
REAL_define_syscall(readv,3, unsigned long a1,   const struct iovec *a2,   unsigned long a3) 

/* minilib/include/syscalls_x64.h, line: 628 */
REAL_define_syscall(process_vm_readv,5, pid_t a1,   const struct iovec *a2,   unsigned long a3,   const struct iovec *a4,   unsigned long a5, unsigned long a6) 

/* minilib/include/syscalls_x64.h, line: 562 */
REAL_define_syscall(sync_file_range,4, long a1,   loff_t a2,   loff_t a3,   long a4) 

/* minilib/include/syscalls_x64.h, line: 33 */
REAL_define_syscall(rt_sigprocmask,4, int a1,   sigset_t *a2,   sigset_t *a3,   size_t a4) 

/* minilib/include/syscalls_x64.h, line: 518 */
REAL_define_syscall(inotify_rm_watch,2, int a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 600 */
REAL_define_syscall(pwritev,5, unsigned long a1,   const struct iovec *a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* minilib/include/syscalls_x64.h, line: 191 */
REAL_define_syscall(fchown,3, unsigned int a1,   uid_t a2,   gid_t a3) 

/* minilib/include/syscalls_x64.h, line: 205 */
REAL_define_syscall(times,1, struct sysinfo *a1) 

/* minilib/include/syscalls_x64.h, line: 111 */
REAL_define_syscall(socketpair,4, int a1,   int a2,   int a3,   int *a4) 

/* minilib/include/syscalls_x64.h, line: 71 */
REAL_define_syscall(dup2,2, unsigned int a1,   unsigned int a2) 

/* minilib/include/syscalls_x64.h, line: 221 */
REAL_define_syscall(getegid,0)

/* minilib/include/syscalls_x64.h, line: 449 */
REAL_define_syscall(fadvise64,4, int a1,   loff_t a2,   size_t a3,   int a4) 

/* minilib/include/syscalls_x64.h, line: 355 */
REAL_define_syscall(init_module,3, void *a1,   unsigned long a2,   const char *a3) 

/* minilib/include/syscalls_x64.h, line: 91 */
REAL_define_syscall(accept,3, int a1,   struct sockaddr *a2,   int *a3) 

/* minilib/include/syscalls_x64.h, line: 297 */
REAL_define_syscall(sched_get_priority_max,1, int a1) 

/* minilib/include/syscalls_x64.h, line: 203 */
REAL_define_syscall(sysinfo,1, struct sysinfo *a1) 

/* minilib/include/syscalls_x64.h, line: 626 */
REAL_define_syscall(getcpu,3, unsigned *a1,   unsigned *a2,   struct getcpu_cache *a3) 

/* minilib/include/syscalls_x64.h, line: 115 */
REAL_define_syscall(getsockopt,5, int a1,   int a2,   int a3,   char *a4,   int *a5) 

/* minilib/include/syscalls_x64.h, line: 552 */
REAL_define_syscall(unshare,1, unsigned long a1) 

/* minilib/include/syscalls_x64.h, line: 598 */
REAL_define_syscall(preadv,5, unsigned long a1,   const struct iovec *a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* minilib/include/syscalls_x64.h, line: 63 */
REAL_define_syscall(shmget,3, key_t a1,   size_t a2,   int a3) 

/* minilib/include/syscalls_x64.h, line: 508 */
REAL_define_syscall(keyctl,5, int a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5) 

/* minilib/include/syscalls_x64.h, line: 5 */
REAL_define_syscall(read,3, unsigned int a1,   char *a2,   size_t a3) 

/* minilib/include/syscalls_x64.h, line: 363 */
REAL_define_syscall(quotactl,4, unsigned int a1,   const char *a2,   qid_t a3,   void *a4) 

/* minilib/include/syscalls_x64.h, line: 39 */
REAL_define_syscall(pread64,4, unsigned long a1,   char *a2,   size_t a3,   loff_t a4) 

/* minilib/include/syscalls_x64.h, line: 283 */
REAL_define_syscall(sysfs,3, int a1,   unsigned long a2,   unsigned long a3) 

/* minilib/include/syscalls_x64.h, line: 357 */
REAL_define_syscall(delete_module,2, const char *a1,   unsigned int a2) 

/* minilib/include/syscalls_x64.h, line: 189 */
REAL_define_syscall(chown,3, const char *a1,   uid_t a2,   gid_t a3) 

/* minilib/include/syscalls_x64.h, line: 343 */
REAL_define_syscall(reboot,4, int a1,   int a2,   unsigned int a3,   void *a4) 

/* minilib/include/syscalls_x64.h, line: 463 */
REAL_define_syscall(clock_gettime,2, const clockid_t a1,   struct timespec *a2) 

/* minilib/include/syscalls_x64.h, line: 241 */
REAL_define_syscall(getresuid,3, uid_t *a1,   uid_t *a2,   uid_t *a3) 

/* minilib/include/syscalls_x64.h, line: 307 */
REAL_define_syscall(mlockall,1, int a1) 

/* minilib/include/syscalls_x64.h, line: 49 */
REAL_define_syscall(pipe,1, int *a1) 

/* minilib/include/syscalls_x64.h, line: 506 */
REAL_define_syscall(request_key,4, const char *a1,   const char *a2,   const char *a3,   key_serial_t a4) 

/* minilib/include/syscalls_x64.h, line: 378 */
REAL_define_syscall(readahead,3, int a1,   loff_t a2,   size_t a3) 

/* minilib/include/syscalls_x64.h, line: 422 */
REAL_define_syscall(io_submit,3, aio_context_t a1,   long a2,   struct iocb **a3) 

/* minilib/include/syscalls_x64.h, line: 23 */
REAL_define_syscall(mmap,5, unsigned long a1,   unsigned long a2,   unsigned long a3,   unsigned long a4,   unsigned long a5, unsigned long a6) 

/* minilib/include/syscalls_x64.h, line: 141 */
REAL_define_syscall(msgget,2, key_t a1,   int a2) 

/* minilib/include/syscalls_x64.h, line: 289 */
REAL_define_syscall(sched_setparam,2, pid_t a1,   struct sched_param *a2) 

/* minilib/include/syscalls_x64.h, line: 376 */
REAL_define_syscall(gettid,0)

/* minilib/include/syscalls_x64.h, line: 35 */
REAL_define_syscall(rt_sigreturn,1, unsigned long a1) 

/* minilib/include/syscalls_x64.h, line: 554 */
REAL_define_syscall(set_robust_list,2, struct robust_list_head *a1,   size_t a2) 

/* minilib/include/syscalls_x64.h, line: 217 */
REAL_define_syscall(setgid,1, gid_t a1) 

/* --- generated-macros-end: syscalldefs --- */


#endif
