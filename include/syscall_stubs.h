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

#include "timeval.h"

extern int sysret;
extern int errno;

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

DEF_syscall(gettimeofday,2, struct timeval *a1, struct timezone *a2)

DEF_syscall(getpid,0 )
DEF_syscall(setsid,0 )
DEF_syscall(setgid,1, gid_t gid)
DEF_syscall(setuid,1, uid_t uid)

DEF_syscall(vhangup,0 )
DEF_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3 )

DEF_syscall(close, 1, int fd )
DEF_syscall(read, 3, int fd, void *buf, int len )
DEF_syscall(write,3,int fd,const void *buf, int len )

DEF_syscall(uname,1,struct old_utsname *name )

DEF_syscall(getdents, 3, unsigned int fd, struct dirent *direntry, unsigned int count )


DEF_syscall(rename,2, const char* oldpath, const char* newpath )		
DEF_syscall(unlink,1, const char* a1)		

DEF_syscall(fstat,2,int a1,struct stat* a2)		
DEF_syscall(stat,2,const char* filename,struct stat* a2)		
DEF_syscall(chdir,1,const char* path)		

DEF_syscall(fchown,3, unsigned int fd, uid_t user, gid_t group)
DEF_syscall(fchmod,2, unsigned int fd, mode_t mode)

DEF_syscall(dup,1,int a1)		
DEF_syscall(dup2,2,int a1, int a2)		
DEF_syscall(dup3,3,int a1, int a2, int a3)		

DEF_syscall(getcwd,2,char *buf,long size)		


// below not thouroughly tested (2020/05)
DEF_syscall(fork,0)
DEF_syscall(vfork,0)
DEF_syscall(nanosleep,2, struct timespec *rqtp, struct timespec *rmtp)
DEF_syscall(rt_sigaction,4, int sig,  const struct sigaction *act,  struct sigaction *oact,  size_t sigsetsize)
DEF_syscall(chroot,1, const char *filename)
DEF_syscall(pivot_root,2, const char *new_root,  const char *put_old)

// (char *argv[] is equivalent to **argv)
DEF_syscall(execve,3, const char *filename,  const char **argv,  const char **envp)
DEF_syscall(mkdir,2, const char *pathname, int mode)
DEF_syscall(kill,2, pid_t pid,  int sig)
DEF_syscall(rmdir,1, const char *pathname)


// below untested. 
DEF_syscall(access,2, const char *filename, int mode)
DEF_syscall(fcntl,3, unsigned int fd, unsigned int cmd, unsigned long arg)
DEF_syscall(pipe,1, int *filedes)
DEF_syscall(umask,1, int mask)
DEF_syscall(chmod,2, const char *filename, mode_t mode)
DEF_syscall(chown,3, const char *filename, uid_t user, gid_t group)
DEF_syscall(link,2, const char *oldname, const char *newname)
DEF_syscall(utime,2, char *filename, struct utimbuf *times)
DEF_syscall(getppid,0)
DEF_syscall(setpgid,2, pid_t pid, pid_t pgid)
DEF_syscall(getgid,0)
DEF_syscall(getpgrp,0)
DEF_syscall(brk,1, unsigned long brk)
DEF_syscall(sendfile,4, int out_fd,  int in_fd,  off_t *offset,  size_t count)
DEF_syscall(getcwd,2, char *buf,  unsigned long size)
DEF_syscall(sync,0)
DEF_syscall(mount,5, char *dev_name,  char *dir_name,  char *type,  unsigned long flags,  void *data)
DEF_syscall(readahead,3, int fd,  loff_t offset,  size_t count)
DEF_syscall(reboot,4, int magic1,  int magic2,  unsigned int cmd,  void *arg)
DEF_syscall(getuid,0)
DEF_syscall(wait4,4, pid_t upid,  int *stat_addr,  int options,  struct rusage *ru)
DEF_syscall(mknod,3, const char *filename,  umode_t mode,  unsigned dev)



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
/* minilib/include/syscall_stubs.h, line: 91 */
REAL_define_syscall(gettimeofday,2, struct timeval *a1,  struct timezone *a2) 

/* minilib/include/syscall_stubs.h, line: 133 */
REAL_define_syscall(pivot_root,2, const char *a1,   const char *a2) 

/* minilib/include/syscall_stubs.h, line: 148 */
REAL_define_syscall(chown,3, const char *a1,  uid_t a2,  gid_t a3) 

/* minilib/include/syscall_stubs.h, line: 130 */
REAL_define_syscall(nanosleep,2, struct timespec *a1,  struct timespec *a2) 

/* minilib/include/syscall_stubs.h, line: 161 */
REAL_define_syscall(reboot,4, int a1,   int a2,   unsigned int a3,   void *a4) 

/* minilib/include/syscall_stubs.h, line: 157 */
REAL_define_syscall(getcwd,2, char *a1,   unsigned long a2) 

/* minilib/include/syscall_stubs.h, line: 159 */
REAL_define_syscall(mount,5, char *a1,   char *a2,   char *a3,   unsigned long a4,   void *a5) 

/* minilib/include/syscall_stubs.h, line: 103 */
REAL_define_syscall(write,3,int a1, const void *a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 139 */
REAL_define_syscall(rmdir,1, const char *a1) 

/* minilib/include/syscall_stubs.h, line: 96 */
REAL_define_syscall(setuid,1, uid_t a1) 

/* minilib/include/syscall_stubs.h, line: 160 */
REAL_define_syscall(readahead,3, int a1,   loff_t a2,   size_t a3) 

/* minilib/include/syscall_stubs.h, line: 98 */
REAL_define_syscall(vhangup,0 )

/* minilib/include/syscall_stubs.h, line: 120 */
REAL_define_syscall(dup,1,int a1) 		

/* minilib/include/syscall_stubs.h, line: 154 */
REAL_define_syscall(getpgrp,0)

/* minilib/include/syscall_stubs.h, line: 118 */
REAL_define_syscall(fchmod,2, unsigned int a1,  mode_t a2) 

/* minilib/include/syscall_stubs.h, line: 155 */
REAL_define_syscall(brk,1, unsigned long a1) 

/* minilib/include/syscall_stubs.h, line: 114 */
REAL_define_syscall(stat,2,const char* a1, struct stat* a2) 		

/* minilib/include/syscall_stubs.h, line: 117 */
REAL_define_syscall(fchown,3, unsigned int a1,  uid_t a2,  gid_t a3) 

/* minilib/include/syscall_stubs.h, line: 132 */
REAL_define_syscall(chroot,1, const char *a1) 

/* minilib/include/syscall_stubs.h, line: 122 */
REAL_define_syscall(dup3,3,int a1,  int a2,  int a3) 		

/* minilib/include/syscall_stubs.h, line: 136 */
REAL_define_syscall(execve,3, const char *a1,   const char **a2,   const char **a3) 

/* minilib/include/syscall_stubs.h, line: 145 */
REAL_define_syscall(pipe,1, int *a1) 

/* minilib/include/lseek.h, line: 19 */
REAL_define_syscall(ftruncate,2,unsigned int a1,  unsigned int a2) 

/* minilib/include/syscall_stubs.h, line: 151 */
REAL_define_syscall(getppid,0)

/* minilib/include/syscall_stubs.h, line: 102 */
REAL_define_syscall(read, 3, int a1,  void *a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 121 */
REAL_define_syscall(dup2,2,int a1,  int a2) 		

/* minilib/include/syscall_stubs.h, line: 105 */
REAL_define_syscall(uname,1,struct old_utsname *a1) 

/* minilib/include/lseek.h, line: 20 */
REAL_define_syscall(fsync,1,int a1) 

/* minilib/include/syscall_stubs.h, line: 93 */
REAL_define_syscall(getpid,0 )

/* minilib/include/syscall_stubs.h, line: 115 */
REAL_define_syscall(chdir,1,const char* a1) 		

/* minilib/include/syscall_stubs.h, line: 95 */
REAL_define_syscall(setgid,1, gid_t a1) 

/* minilib/include/syscall_stubs.h, line: 149 */
REAL_define_syscall(link,2, const char *a1,  const char *a2) 

/* minilib/include/syscall_stubs.h, line: 144 */
REAL_define_syscall(fcntl,3, unsigned int a1,  unsigned int a2,  unsigned long a3) 

/* minilib/include/syscall_stubs.h, line: 137 */
REAL_define_syscall(mkdir,2, const char *a1,  int a2) 

/* minilib/include/syscall_stubs.h, line: 152 */
REAL_define_syscall(setpgid,2, pid_t a1,  pid_t a2) 

/* minilib/include/lseek.h, line: 17 */
REAL_define_syscall(lseek,3,unsigned int a1,  int a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 128 */
REAL_define_syscall(fork,0)

/* minilib/include/syscall_stubs.h, line: 107 */
REAL_define_syscall(getdents, 3, unsigned int a1,  struct dirent *a2,  unsigned int a3) 

/* minilib/include/syscall_stubs.h, line: 153 */
REAL_define_syscall(getgid,0)

/* minilib/include/syscall_stubs.h, line: 110 */
REAL_define_syscall(rename,2, const char* a1,  const char* a2) 		

/* minilib/include/syscall_stubs.h, line: 111 */
REAL_define_syscall(unlink,1, const char* a1) 		

/* minilib/include/syscall_stubs.h, line: 158 */
REAL_define_syscall(sync,0)

/* minilib/include/syscall_stubs.h, line: 101 */
REAL_define_syscall(close, 1, int a1) 

/* minilib/include/syscall_stubs.h, line: 138 */
REAL_define_syscall(kill,2, pid_t a1,   int a2) 

/* minilib/include/syscall_stubs.h, line: 150 */
REAL_define_syscall(utime,2, char *a1,  struct utimbuf *a2) 

/* minilib/include/syscall_stubs.h, line: 131 */
REAL_define_syscall(rt_sigaction,4, int a1,   const struct sigaction *a2,   struct sigaction *a3,   size_t a4) 

/* minilib/include/syscall_stubs.h, line: 129 */
REAL_define_syscall(vfork,0)

/* minilib/include/syscall_stubs.h, line: 162 */
REAL_define_syscall(getuid,0)

/* minilib/include/syscall_stubs.h, line: 147 */
REAL_define_syscall(chmod,2, const char *a1,  mode_t a2) 

/* minilib/include/syscall_stubs.h, line: 99 */
REAL_define_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3)

/* minilib/include/syscall_stubs.h, line: 164 */
REAL_define_syscall(mknod,3, const char *a1,   umode_t a2,   unsigned a3) 

/* minilib/include/syscall_stubs.h, line: 143 */
REAL_define_syscall(access,2, const char *a1,  int a2) 

/* minilib/include/syscall_stubs.h, line: 113 */
REAL_define_syscall(fstat,2,int a1, struct stat* a2) 		

/* minilib/include/syscall_stubs.h, line: 169 */
REAL_define_syscall(time,1,unsigned int *a1) 

/* minilib/include/syscall_stubs.h, line: 163 */
REAL_define_syscall(wait4,4, pid_t a1,   int *a2,   int a3,   struct rusage *a4) 

/* minilib/include/syscall_stubs.h, line: 156 */
REAL_define_syscall(sendfile,4, int a1,   int a2,   off_t *a3,   size_t a4) 

/* minilib/include/syscall_stubs.h, line: 146 */
REAL_define_syscall(umask,1, int a1) 

/* minilib/include/syscall_stubs.h, line: 94 */
REAL_define_syscall(setsid,0 )

/* --- generated-macros-end: syscalldefs --- */

#pragma GCC diagnostic pop
#endif

#endif
