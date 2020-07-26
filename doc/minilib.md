

==========
declarations.h
==========



==========
dirent.h
==========

closedir       int closedir(DIR *dir);

               (src/dirent/closedir.c: 6)

opendir        static DIR *opendir(const char *name );

               (src/dirent/opendir.c: 24)

readdir        struct dirent *readdir(DIR *dir);

               read a directory.
              return the next dirent, or 0, if the end is reached.
              return 0 on error and set errno,
              if mini_errno is not defined, return -errno on error
               (src/dirent/readdir.c: 10)

rewinddir      void rewinddir(DIR *dir);

               (src/dirent/rewinddir.c: 2)

scandir        int scandir(const char *path, struct dirent **listing[], int (*fp_select)(const struct dirent *),	int (*cmp)(const struct dirent **, const struct dirent **));

               list files and dirs in a directory
             
              This implementation uses malloc_brk() for the dynamic allocation
              of the listing, and tries to do as less copies as possible.
              The dynamically allocated space for the result list (**listing[])
              is guaranteed to be at one continuous memory location.
             
              if the select callback is 0, meaning all entries should be returned,
              There are no copies done at all, 
              besides the copying from kernelspace to userspace.
             
              To free the space, allocated for the listing,
              either call free_brk(),
              when no other allocations via malloc_brk took place.
             
              Or save the brk before you call scandir,
              and restore it after the call.
              (e.g.)
              long savebrk=getbrk();
              int ret=scandir(...);
              brk(savebrk);
              Freeing single list entries might give unexpected results.
             
              returns the number of the read entries,
              or the negative errno on error.
               (src/dirent/scandir.c: 35)

seekdir        void seekdir(DIR *dir, long off);

               (src/dirent/seekdir.c: 2)

telldir        long telldir(DIR *dir);

               (src/dirent/telldir.c: 2)



==========
fcntl.h
==========

creat          int volatile creat( const char *s, int mode );

               (src/open.c: 36)

mkfifo         static int mkfifo( const char* path, mode_t mode );

               (include/mkfifo.h: 4)



==========
ioctl.h
==========

ioctl          int volatile  __attribute__((optimize("O0"))) ioctl( int fd, unsigned long int request, ... );

               (src/ioctl.c: 11)



==========
mini_addons.h
==========

_itobin        int _itobin(int i, char*buf, int prec, int groups );

               (src/itobin.c: 8)

_mprints       #define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)

               (src/prints.c: 69)

alphasort      int alphasort( const struct dirent** de1, const struct dirent** de2 );

               Sort dirents by name.
              Deviating of the standard, 
              the asciitables is used for the comparison
              (using strcmp)
               (src/dirent/alphasort.c: 7)

ansicolors     

               defines for ansicolors at the console, 16 color mode
             the names are:
              AC_NORM ( white text on black background)
              AC_BLACK 
              AC_RED 
              AC_GREEN 
              AC_BROWN 
              AC_BLUE 
              AC_MAGENTA 
              AC_MARINE (= AC_CYAN)
              AC_LGREY 
              AC_WHITE 
              AC_GREY 
              AC_LRED 
              AC_LGREEN 
              AC_YELLOW 
              AC_LBLUE 
              AC_LMAGENTA 
              AC_LMARINE (= AC_LCYAN)
              AC_LWHITE 
              AC_BGBLACK 
              AC_BGRED 
              AC_BGGREEN 
              AC_BGBROWN 
              AC_BGBLUE 
              AC_BGMAGENTA 
              AC_BGMARINE 
              AC_BGLGREY 
              AC_BGWHITE 
             
              AC_BOLD
              AC_FAINT
              AC_CURSIVE
              AC_UNDERLINE
              AC_LIGHTBG
              AC_BLINK
              AC_INVERTED
              AC_INVERSE
             
              ( Faint to inverse are not available at every terminal )
               (include/ansicolors.h: 45)

basename       char *basename(char *path);

               (src/basename.c: 29)

brk            static int brk( const void* addr );

               set the brk to addr
              return 0 on success.
              conformant brk, when mini_errno is defined return -1 and set errno.
              if errno isn't available,
              returns the negative errno value on error
               (src/brk.c: 19)

def            #define SETOPT_short( opts, option ) (;

               Set a option flag(s) (bit(s))  manually.
             		param options: e.g. just a, or ( a+h+l) to check for several flags at once
               (macros/getoptm.h: 52)

dirbuf         

               the switch for defining the dirbuf.
              used internally
               (include/dirent.h: 7)

dirbufsize     #ifndef mini_dirbufsize

               the dir stream bufsize
              The size of the buffer can be changed by setting mini_dirbufsize
              to it's size in Bytes. (default 2048)
              The buffer is allocated via malloc,
              therefore mini_buf must be set to a value greater than dirbufsize
               (include/dirent.h: 22)

dirfd          int dirfd(DIR *d);

               (src/dirent/dirfd.c: 2)

dirname        char *dirname(char *s);

               (src/dirname.c: 8)

djb2_hash      unsigned long djb2_hash(const unsigned char *str);

               hashes, from d.j.Bernstein
              (http://www.cse.yorku.ca/~oz/hash.html)
              I've tested djb2_hash, and it gives quite good results.
              But I'm sure, Bernstein did think and test his algorithm sincerely.
              When combining djb2_hash and sdbm_hash, the probability of collisions
              might tend to zero.
              Me I'm going this way. I guess. I might check djb2_hash for collisions within a space of around 8 digits.
               (src/hashes.c: 10)

dprintf        int dprintf( int fd, const char *fmt, ... );

               (src/dprintf.c: 5)

dprints        int dprints(int fd, const char *msg,...);

               (src/prints.c: 48)

dtodec         int dtodec(double d, char* buf, int precision);

               (src/dtodec.c: 10)

eprint         #define eprint(str) write(STDERR_FILENO,str,strlen(str))

               write str to stderr. Needs strlen
               (include/prints.h: 42)

eprintfs       #define eprintfs(fmt,...) fprintfs(stderr, fmt, __VA_ARGS__)

               write str to stderr. 
              only format %s is recognized
               (include/prints.h: 90)

eprintl        #define eprintl() write(STDERR_FILENO,"\n",1)

               write a newline to stderr
               (include/prints.h: 67)

eprints        #define eprints(...) dprints(STDERR_FILENO,__VA_ARGS__,0)

               print the string(s) supplied as arg(s) to stdout
               (include/prints.h: 17)

eputs          #define eputs(msg) ( eprint(msg) + eprintl() )

               write msg to stderr, append a newline. Needs strlen.
               (include/prints.h: 77)

errno_str      static char *errno_str(int err);

               convert errno to str, with 3 chars length
              ending the string (global) 
              with two \0\0, when errno<100
              errnum must be <200.
               (src/errno_str.c: 7)

ewrites        #define ewrites(str) write(STDERR_FILENO,str,sizeof(str))

               write the constant str to stderr. Computes length with sizeof(str) at compile time.
               (include/prints.h: 52)

exit_errno     void exit_errno( int errnum );

               exit, and execute /bin/errno
              this is intended to give a error message for the 
              given errno num.
              Instead of having the error messages compiled 
              into each binary, they can stay within one executable, "errno"
              This spares about 4kB, but needs errno installed to /bin/errno
              It's the drawback of not having a shared library,
              where all executables would share the same errno messages
              in memory.
              On the other hand, a shared library would need to be installed
              as well.
              The supplied errno can be negative,
              the absolute value is supplied to errno.
               (src/exit_errno.c: 17)

ext_match      int ext_match(const char *text, const char *re);

               simple regex engine.
              matches: * for every count of any char
              ? for 1 char
              backslash: escape *,?, and backslash itself.
              \d - digit
              \D - nondigit
              \s - space
              \S - nonspace
              \w - word character ( defined as ascii 32-126,160-255 )
              \W - nonword character ( defined as ascii 0-31,127-159 )
             
              (memo) When the regex ist defined as C string,
              a backslash has to be defined as double backslash
              in the source code.
               (src/ext_match.c: 16)

fexecve        static inline int fexecve(int fd, char *const argv[], char *const envp[]);

               (include/fexecve.h: 3)

fexecveat      static inline int fexecveat(int fd, char *const argv[], char *const envp[]);

               (include/fexecveat.h: 3)

fprintfs       int fprintfs( FILE* F, char *fmt, ...);

               prints formatted to the stream F.only %s and %c are recognized.no mini_buf needed, so using fprintfs instead of fprintf can save some sections / bytes.
               (src/fprintfs.c: 10)

fprints        #define fprints(F,str) write(fileno(F),str,strlen(str))

               print the string(s) supplied as arg(s) to stream
               (include/prints.h: 24)

fwrites        #define fwrites(fd,str) write(fd,str,sizeof(str))

               write the constant str to fd. Computes length with sizeof(str) at compile time.
               (include/prints.h: 58)

getbrk         static long getbrk();

               get the current brk
              does either a syscall to brk,
              or returns the globally saved var
               (src/brk.c: 39)

grantpt        int grantpt(int fd);

               (src/pty.c: 13)

itobin         #define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )

               convert a number to a binary representation.
              the conversion assumes a size of 32bits for integers,
              negative values are represented as they are stored internally.
              ( -1 is 11111111111111111111111111111111,
                -2    11111111111111111111111111111110, ...)
               (src/itobin.c: 46)

itodec         int itodec(int i, char *buf, int prec, char limiter );

               (src/itodec.c: 118)

itooct         int itooct(int i, char *buf);

               convert int to octal
              return the number of chars written.
               (src/itooct.c: 4)

ltodec         int ltodec(long i, char *buf, int prec, char limiter );

               (src/ltodec.c: 75)

macro          static void __attribute__((noipa,cold)) optimization_fence(void*p){}

               prevent optimizations.
              cast a var to void*, and calling this,
              leaves the compiler unknown on what he can strip.
              (noipa) means the compiler doesn't know, what the function itself does.
              (the function does nothing, but don't tell that gcc, please..)
              therefore, everything used as parameter to this function,
              will be calculated, defined, and so on before.
              It's used for the globals, 
              shich are pushed within _start onto the stack.
              since _start itself only provides a global pointer,
              and initialitzes some of the globals,
              but doesn't use them again,
              this construction is needed.
              more funnily, the function will never be called.
              It's past the asm inline syscall to exit.
              But again, luckily gcc doesn't know.
              All other options, like having the globals volatile, 
              setting the optimization flag of _start to 0, 
              having a volatile asm call with the globals as param, and so on,
              have been useless. All after all, seems to me, ai has it's restrictions.
               (include/minilib_global.h: 90)

match          int match(const char *text, const char *re);

               simple regex engine.
              matches: * for every count of any char
              ? for 1 char
              backslash: escape *,?, and backslash itself.
             
              (memo) When the regex ist defined as C string,
              a backslash has to be defined as double backslash
              in the source code.
               (src/match.c: 10)

memfrob        void* memfrob(void* s, unsigned int len);

               (src/memfrob.c: 3)

mmap           static void* __attribute__((optimize("O0"))) mmap(void* addr,  size_t len,  int prot,  int flags,  int fd,  off_t off);

               mmap wrapper
              address length is rounded up to a multiple of pagesize (4096 Bytes here)
              for the description, please look up the according manpage
              errno is only set, when mini_errno is defined
              if not, on error the negative errno value is returned.
              (e.g. -22 for "invalid argument")
               (src/mmap.c: 8)

mremap         static void* volatile __attribute__((optimize("O0"))) mremap(void* addr, size_t old_len, size_t new_len, int flags, void* new_addr);

               (include/mremap.h: 4)

opendirp       static DIR *opendirp(const char *name, DIR *dir);

               (src/dirent/opendir.c: 10)

posix_openpt   int posix_openpt(int flags);

               (src/pty.c: 8)

print          #define print(str) write(STDOUT_FILENO,str,strlen(str))

               write str to stdout. Needs strlen
               (include/prints.h: 38)

printfs        #define printfs(fmt,...) fprintfs(stdout, fmt, __VA_ARGS__)

               write str to stdout. 
              only format %s is recognized
               (include/prints.h: 84)

printl         #define printl() write(STDOUT_FILENO,"\n",1)

               write a newline to stdout
               (include/prints.h: 63)

prints         #define prints(...) _mprints(__VA_ARGS__,0)

               print the string(s) supplied as arg(s) to stdout
               (include/prints.h: 11)

printsl        #define printsl(...) _mprints(__VA_ARGS__,"\n",0)

               print the string(s) supplied as arg(s) and newline to stdout
               (include/prints.h: 32)

ptsname        char *ptsname(int fd);

               (src/pty.c: 40)

ptsname_r      int ptsname_r(int fd, char *buf, size_t len);

               (src/pty.c: 27)

putenv         int putenv( char *string );

               put a string into the environmental vars
              the supplied string's pointer is put into the environmental array of pointers.
              Subsequent changes of the string therefore will change the environment,
              and the supplied string may not be deallocated.
              Returns: 
              - 0 on success, 
              - EINVAL: string was 0, didn't contain a '=', some other error
               (src/putenv.c: 10)

ret_errno      #ifdef mini_errno

               This macro expands to a return, and
              (when mini_errno is defined) returns -1 and sets errno,
              or returns the negative errno value.
               (include/ret_errno.h: 5)

sbrk           static void* sbrk(long incr);

               Set the new brk, increment/decrement by incr bytes.
              return the old brk on success.
              conformant sbrk, when mini_errno is defined
              if no errno is available,
              returns the negative errno value on error
               (src/brk.c: 57)

scandir_bufsize//#define mini_scandir_bufsize 4096

               the increment of the buffer of scandir in bytes for memory allocations
              (default:4096)
               (src/dirent/scandir.c: 4)

sdbm_hash      unsigned long sdbm_hash(const unsigned char *str);

               (src/hashes.c: 21)

seterrno       #ifdef mini_errno

               set errno, but only when errno is defined.
               (include/seterrno.h: 3)

shortcolornames

               short ansi color names
              all colornames, without the praefix "AC_"
               (include/ansicolors.h: 103)

snprintf       int snprintf( char *buf, size_t size, const char *fmt, ... );

               (src/snprintf.c: 5)

swap           static inline void swap(void* a, void* b,int size);

               swap a with b, with 'size' bytes
              swaps integers and longs at once, when size eq sizeof(int/long)
               (src/qsort.c: 31)

sys_brk        static long sys_brk(unsigned long addr);

               the kernel syscall brk.
               (src/brk.c: 6)

uitodec        int __attribute__((optimize("Os")))uitodec(unsigned int i, char *buf, int prec, char limiter );

               convert int to string.
              prec: precision, e.g. 4=> 0087 
               (src/itodec.c: 8)

ultodec        int ultodec(unsigned long ui, char *buf, int prec, char limiter );

               (src/ltodec.c: 6)

unlockpt       int unlockpt(int fd);

               (src/pty.c: 20)

verbose_errstr const char* verbose_errstr(int num);

               verbose error (errno) string. 
              this adds about 3.5kB to the compiled binary(!)
               (include/errstr.h: 8)

verbose_errstr2static const char* verbose_errstr2(int num);

               verbose error (errno) string. 
              this adds about 3.5kB to the compiled binary(!)
              Trying to shrink that here.
               (include/errstr2.h: 11)

vexec          int vexec( const char* path, char* const* argv, char* const* envp );

               execute a path, wait until the executed file exits.
              Deviating of system() an absolute pathname is taken.
               (src/vexec.c: 5)

vexec_q        int vexec_q( const char* path, char* const* argv, char* const* envp );

               execute a path, wait until the executed file exits, 
              do not write any output of the process. (close stdout)
              Deviating of system() an absolute pathname is taken.
               (src/vexec.c: 28)

vsnprintf      int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );

               the function, translating the fmt of printf.
              warning - most possibly you'd like to define besides fprintf, or family,
              mini_itodec (%d conversion) 
              mini_atoi is needed for grouping numbers
               (src/sprintf.c: 41)

writes         #define writes(str) write(STDOUT_FILENO,str,sizeof(str))

               write the constant str to stdout. Computes length with sizeof(str) at compile time.
               (include/prints.h: 48)



==========
mini_syscalls
==========

sys__sysctl       
sys_accept        
sys_accept4       
sys_access        
sys_acct          
sys_add_key       
sys_adjtimex      
sys_alarm         
sys_arch_prctl    
sys_bind          
sys_capget        
sys_capset        
sys_chdir         
sys_chmod         
sys_chown         
sys_chroot        
sys_clock_adjtime 
sys_clock_getres  
sys_clock_gettime 
sys_clock_nanosleep
sys_clock_settime 
sys_clone         
sys_close         
sys_connect       
sys_creat         
sys_delete_module 
sys_dup           
sys_dup2          
sys_dup3          
sys_epoll_create  
sys_epoll_create1 
sys_epoll_ctl     
sys_epoll_pwait   
sys_epoll_wait    
sys_eventfd       
sys_eventfd2      
sys_execve        
sys_exit          
sys_exit_group    
sys_faccessat     
sys_fadvise64     
sys_fallocate     
sys_fanotify_init 
sys_fanotify_mark 
sys_fchdir        
sys_fchmod        
sys_fchmodat      
sys_fchown        
sys_fchownat      
sys_fcntl         
sys_fdatasync     
sys_fgetxattr     
sys_finit_module  
sys_flistxattr    
sys_flock         
sys_fork          
sys_fremovexattr  
sys_fsetxattr     
sys_fstat         
sys_fstatfs       
sys_fsync         
sys_ftruncate     
sys_futex         
sys_futimesat     
sys_get_mempolicy 
sys_get_robust_list
sys_getcpu        
sys_getcwd        
sys_getdents      
sys_getdents64    
sys_getegid       
sys_geteuid       
sys_getgid        
sys_getgroups     
sys_getitimer     
sys_getpeername   
sys_getpgid       
sys_getpgrp       
sys_getpid        
sys_getppid       
sys_getpriority   
sys_getrandom     
sys_getresgid     
sys_getresuid     
sys_getrlimit     
sys_getrusage     
sys_getsid        
sys_getsockname   
sys_getsockopt    
sys_gettid        
sys_gettimeofday  
sys_getuid        
sys_getxattr      
sys_init_module   
sys_inotify_add_watch
sys_inotify_init  
sys_inotify_init1 
sys_inotify_rm_watch
sys_io_cancel     
sys_io_destroy    
sys_io_getevents  
sys_io_setup      
sys_io_submit     
sys_ioctl         
sys_ioperm        
sys_iopl          
sys_ioprio_get    
sys_ioprio_set    
sys_kcmp          
sys_kexec_file_load
sys_kexec_load    
sys_keyctl        
sys_kill          
sys_lchown        
sys_lgetxattr     
sys_link          
sys_linkat        
sys_listen        
sys_listxattr     
sys_llistxattr    
sys_lookup_dcookie
sys_lremovexattr  
sys_lseek         
sys_lsetxattr     
sys_lstat         
sys_madvise       
sys_mbind         
sys_memfd_create  
sys_migrate_pages 
sys_mincore       
sys_mkdir         
sys_mkdirat       
sys_mknod         
sys_mknodat       
sys_mlock         
sys_mlockall      
sys_mmap          
sys_modify_ldt    
sys_mount         
sys_move_pages    
sys_mprotect      
sys_mq_getsetattr 
sys_mq_notify     
sys_mq_open       
sys_mq_timedreceive
sys_mq_timedsend  
sys_mq_unlink     
sys_mremap        
sys_msgctl        
sys_msgget        
sys_msgrcv        
sys_msgsnd        
sys_msync         
sys_munlock       
sys_munlockall    
sys_munmap        
sys_name_to_handle_at
sys_nanosleep     
sys_newfstatat    
sys_open          
sys_open_by_handle_at
sys_openat        
sys_pause         
sys_perf_event_open
sys_personality   
sys_pipe          
sys_pipe2         
sys_pivot_root    
sys_poll          
sys_ppoll         
sys_prctl         
sys_pread64       
sys_preadv        
sys_prlimit64     
sys_process_vm_readv
sys_process_vm_writev
sys_pselect6      
sys_ptrace        
sys_pwrite64      
sys_pwritev       
sys_quotactl      
sys_read          
sys_readahead     
sys_readlink      
sys_readlinkat    
sys_readv         
sys_reboot        
sys_recvfrom      
sys_recvmmsg      
sys_recvmsg       
sys_remap_file_pages
sys_removexattr   
sys_rename        
sys_renameat      
sys_renameat2     
sys_request_key   
sys_restart_syscall
sys_rmdir         
sys_rt_sigaction  
sys_rt_sigpending 
sys_rt_sigprocmask
sys_rt_sigqueueinfo
sys_rt_sigreturn  
sys_rt_sigsuspend 
sys_rt_sigtimedwait
sys_rt_tgsigqueueinfo
sys_sched_get_priority_max
sys_sched_get_priority_min
sys_sched_getaffinity
sys_sched_getattr 
sys_sched_getparam
sys_sched_getscheduler
sys_sched_rr_get_interval
sys_sched_setaffinity
sys_sched_setattr 
sys_sched_setparam
sys_sched_setscheduler
sys_sched_yield   
sys_seccomp       
sys_select        
sys_semctl        
sys_semget        
sys_semop         
sys_semtimedop    
sys_sendfile      
sys_sendmmsg      
sys_sendmsg       
sys_sendto        
sys_set_mempolicy 
sys_set_robust_list
sys_set_tid_address
sys_setdomainname 
sys_setfsgid      
sys_setfsuid      
sys_setgid        
sys_setgroups     
sys_sethostname   
sys_setitimer     
sys_setns         
sys_setpgid       
sys_setpriority   
sys_setregid      
sys_setresgid     
sys_setresuid     
sys_setreuid      
sys_setrlimit     
sys_setsid        
sys_setsockopt    
sys_settimeofday  
sys_setuid        
sys_setxattr      
sys_shmat         
sys_shmctl        
sys_shmdt         
sys_shmget        
sys_shutdown      
sys_sigaltstack   
sys_signalfd      
sys_signalfd4     
sys_socket        
sys_socketpair    
sys_splice        
sys_stat          
sys_statfs        
sys_swapoff       
sys_swapon        
sys_symlink       
sys_symlinkat     
sys_sync          
sys_sync_file_range
sys_syncfs        
sys_sysfs         
sys_sysinfo       
sys_syslog        
sys_tee           
sys_tgkill        
sys_time          
sys_timer_create  
sys_timer_delete  
sys_timer_getoverrun
sys_timer_gettime 
sys_timer_settime 
sys_timerfd_create
sys_timerfd_gettime
sys_timerfd_settime
sys_times         
sys_tkill         
sys_truncate      
sys_umask         
sys_umount2       
sys_uname         
sys_unlink        
sys_unlinkat      
sys_unshare       
sys_ustat         
sys_utime         
sys_utimensat     
sys_utimes        
sys_vfork         
sys_vhangup       
sys_vmsplice      
sys_wait4         
sys_waitid        
sys_write         
sys_writev        


==========
signal.h
==========

raise          static inline int raise(int signr);

               (src/sigaction.c: 135)

sigaction      static int volatile sigaction(int sig, const struct sigaction *act, struct sigaction *oact);

               (src/sigaction.c: 107)

sigaddset      int sigaddset(sigset_t *set, int sig);

               (src/sigaction.c: 34)

sigdelset      int sigdelset(sigset_t *set, int sig);

               (src/sigaction.c: 58)

sigemptyset    static int sigemptyset(sigset_t *set);

               (src/sigaction.c: 7)

sigfillset     static int sigfillset(sigset_t *set);

               (src/sigaction.c: 20)

sigismember    int sigismember(sigset_t *set, int sig);

               (src/sigaction.c: 75)

signal         sighandler_t signal(int sig, sighandler_t func );

               (src/signal.c: 8)

sigprocmask    int sigprocmask(int how, const sigset_t *set, sigset_t *oldset);

               (src/sigaction.c: 52)



==========
stdio.h
==========

_fopen         FILE *_fopen(int fd, const char* filename, const char* mode, FILE *f);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 12)

_itohex        int _itohex(int i,char* buf,int padding, int capitals);

               (src/itohex.c: 6)

clearerr       static inline void clearerr(FILE *f);

               (include/mini_fstream.h: 198)

clearerror     static inline void clearerror(FILE *f);

               (include/mini_fstream.h: 203)

fclose         static inline int __attribute__((always_inline)) fclose( FILE* f );

               (include/mini_fstream.h: 65)

fdopen         FILE *fdopen(int fd, const char* mode);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 91)

feof           static inline int feof(FILE *f);

               (include/mini_fstream.h: 184)

ferror         static inline int ferror(FILE *f);

               (include/mini_fstream.h: 191)

fflush         static inline int __attribute__((always_inline)) fflush( FILE *F );

               This does nothing, since minilib doesn't provide buffered streams yet.In order to sync data to disc, please use fsync
               (include/mini_fstream.h: 28)

fgetc          static inline int fgetc(FILE *F);

               (include/fgetc.h: 11)

fgetpos        static inline void fgetpos(FILE *f, long *pos );

               (include/mini_fstream.h: 127)

fgets          char* fgets(char *buf, int size, FILE* F);

               (src/fgets.c: 6)

fileno         static int fileno( FILE *f );

               Return the fd nummber of stdin,-out,-err. 
               (include/mini_fstream.h: 56)

fopen          FILE *fopen(const char* filename, const char* mode);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 81)

fprint         #define fprint(...) fprintf(__VA_ARGS__)

               (include/mini_fstream.h: 95)

fprintf        #define fprintf(stream,...)	write(fileno(stream),mlgl->mbuf,sprintf(mlgl->mbuf,__VA_ARGS__))

               (src/sprintf.c: 228)

fputc          static inline int volatile fputc(int c, FILE* F);

               (include/fputc.h: 10)

fputs          static inline int volatile fputs(const char *c, FILE *F);

               (include/fputs.h: 20)

fread          static inline size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f);

               (include/mini_fstream.h: 162)

freopen        FILE *freopen(const char* filename, const char* mode, FILE *F);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 101)

fseek          static inline int fseek(FILE *f, long offset, int whence );

               (include/mini_fstream.h: 146)

fsetpos        static inline int fsetpos(FILE *f, int pos );

               (include/mini_fstream.h: 133)

ftell          static inline long ftell(FILE *f);

               (include/mini_fstream.h: 121)

fwrite         static inline size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *f);

               (include/mini_fstream.h: 106)

getc           #define getc(F) fgetc(F)

               (include/fgetc.h: 26)

getchar        #define getchar() fgetc(0)

               (include/fgetc.h: 29)

gets           #define gets(F) fgets(F,0xfffffff,stdin)

               (src/fgets.c: 29)

itoHEX         int itoHEX(int i,char* buf,int padding);

               convert a number to hexadecimal representation with big capitals.
              the conversion assumes a size of 32bits for integers,
              negative values are represented as they are stored internally.
              ( -1 is 0xFFFFFFFF, -2 0xFFFFFFFE, ... )
               (src/itohex.c: 65)

itohex         int itohex(int i,char* buf,int padding);

               convert a number to hexadecimal representation.
              the conversion assumes a size of 32bits for integers,
              negative values are represented as they are stored internally.
              ( -1 is 0xffffffff, -2 0xfffffffe, ... )
               (src/itohex.c: 53)

perror         void perror(const char *msg);

               (src/perror.c: 4)

printf         #define printf(...) fprintf(stdout,__VA_ARGS__)

               (include/mini_fstream.h: 91)

putc           #define putc(c,stream) fputc(c,stream)

               (include/fputc.h: 19)

putchar        #define putchar(c) fputc(c,stdout)

               (include/fputc.h: 16)

puts           #define puts(msg) ( print(msg) + printl() )

               write msg to stdout, append a newline. Needs strlen.
               (include/prints.h: 73)

rewind         static inline void rewind( FILE *f );

               (include/mini_fstream.h: 156)

setbuf         static void setbuf(FILE *stream, char *buf);

               dummy function.
              There is no buffering implemented for the streams yet.
               (include/mini_fstream.h: 211)

setvbuf        static int setvbuf(FILE *stream, char *buf, int mode, size_t size);

               dummy function
               (include/mini_fstream.h: 216)

sprintf        #define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)

               (src/sprintf.c: 26)

ungetc         static int ungetc(int c, FILE *F);

               pushes one char back to the stream.
              Overwrites a previously pushed char
              (conforming to the posix spec) 
               (include/fgetc.h: 35)

vfprintf       #define vfprintf(...) fprintf(__VA_ARGS__)

               (include/mini_fstream.h: 100)

vsprintf       int vsprintf( char *buf, const char *fmt, ... );

               write fmt and arguments into buf
              calls vsnprintf, 
              the size is limited to 4096 by default.
               (src/vsprintf.c: 9)



==========
stdlib.h
==========

abort          void abort();

               (src/abort.c: 3)

abs            static int abs(int i);

               (include/math.h: 25)

atexit         static int atexit( functionp* func );

               register functions, which are callen on exit in reverse order
              the switch mini_atexit takes a optional number,
              which defines the maximum numbers of functions to be registered.
              (defaults to 8)
               (src/atexit.c: 7)

atoi           int atoi(const char *c);

               (src/atoi.c: 6)

atol           long atol(const char *c);

               (src/atoi.c: 43)

div            static div_t div(int numerator, int denominator);

               (include/math.h: 8)

free           void free(void *p);

               (src/malloc.c: 139)

free_brk       int free_brk();

               free all memory,
              which has been allocated with malloc_brk.
              Returns 0, if memory has been freed;
              1, when there hasn't been any memory allocations with
              malloc_brk before.
              Then brk() gives an error, return the return value of brk
               (src/malloc.c: 234)

getenv         char* getenv(const char* name);

               (src/getenv.c: 8)

labs           static long int labs(long int i);

               (include/math.h: 30)

ldiv           static ldiv_t ldiv(long int numerator, long int denominator);

               (include/math.h: 16)

malloc         void* malloc(int size);

               0
              Here we go.. with the .. well. 
              Fastes and smallest malloc/free combi ever. 
              Not the smartest.
              Since it isn't exactly a memory allocation,
              instead it (mis)uses the minilib buf.
              ;) 1024 Bytes should be enough for everyone.
               Ok. If you really do need more memory - 
               rethink your design, increase mini_mbuf,
               or use a proper malloc implementation.
             
              Here we use mbuf from top to bottom as stack.
              64 Bytes are left at the bottom as reserve.
              Possibly we'd like to complain
              about the lack of memory, before we exit..
             
              ATM, the 'free' is really lazy. 
              It free's memory, but a real 'free' is only commited,
              when all memory below a freed area is also freed.
              Since the target of minilib atm are tiny tools, 
              this might be ok.
              ;) but, as I told before - 
              probably you should look out for a proper malloc implementation.
              It depends on your needs.
             
              I'm not sure yet, 
              whether another implementation of free would be useful at all.
              Overall, I'd really prefer keeping minilib tiny.
             
              Reusing sparse freed memory areas also leads 
              to a whole bunch of complications.
              cache misses, searching complexity,
              storage overhead, potentially page faults,
              just to name a few.
             
              I'm not sure whether it's worth it.
             
              And the existing malloc implementations 
              out there are countless.
             
              ;) It's sometimes smarter to stay special,
              although in this case this means the opposite.
              /misc
             
              The memory layout looks like this:
              mlgl->ibuf and mlgl->mbuf do point to the same address range.
              mlgl->ibuf is provided for alignment and faster access to the int values.
             
              flag prev free is the first bit in size. (0x8000, eq 1000 0000 0000 0000 binary when free), 
              (mbufsize)
              ```
                   size  data  size    mini_buf size
                   8008dataxxxx0004data8000|
                   ----========----====----|
             
              also, when free space is in between two areas
              
              8004data8008  free  0004data8000|
              ----====----________----====----|
             
              ```
              the free space is only freed, 
              when all areas below (left) have been free'd as well.
             
              Memory is allocated from right to left, 
              meaning from top to down.
               (src/malloc.c: 119)

malloc_brk     void* malloc_brk(int size);

               allocate via setting the brk
              free and realloc can be used normally.
              The intention of malloc_brk is for subsequent calls to realloc.
              The saved data has not to be copied,
              instead realloc just writes the new size and sets 
              the brk accordingly.
              if the break is saved before one or more calls to malloc_brk,
              the allocated memory can also be free'd by setting the brk to the saved value
              with brk(saved_brk)
              free_brk() free's all memory, which has been allocated with malloc_brk
               (src/malloc.c: 206)

qsort          void qsort(void  *base,	size_t nel,	size_t width,	int (*comp)(const void *, const void *));

               (quick) shell sort routine
              following the tradition, this isn't exactly a quicksort algorithm,
              albite named quicksort.
              It is a shell sort implementation, originally done by Ray Gardner, 5/90;
              which in turn I did find within musl.
               (src/qsort.c: 57)

rand           unsigned int rand();

               (src/rand.c: 15)

realloc        void* realloc(void *p, int size);

               (src/malloc.c: 252)

srand          void srand( unsigned int i );

               (src/rand.c: 7)

strtol         long int strtol(const char *c, const char **endp, int base);

               conversion
              doesn't check for overflow(!)
               (src/strtol.c: 5)

system         int system( const char* command );

               (src/system.c: 4)



==========
string.h
==========

_strcasecmp    int _strcasecmp(const char*c1,const char*c2,int len);

               (src/strcmp.c: 27)

_strcmp        int _strcmp(const char*c1,const char*c2,int len);

               (src/strcmp.c: 10)

memcmp         int memcmp(const void* c1,const void* c2,int len);

               (src/strcmp.c: 84)

memcpy         void *memcpy( void *d, const void *s, int n );

               (src/memcpy.c: 6)

memmove        void* memmove(void *dest, const void *src, int n);

               (src/memmove.c: 3)

memset         void *memset( void *s, int c, int n);

               (src/memset.c: 3)

strcasecmp     int strcasecmp(const char*c1,const char*c2);

               (src/strcmp.c: 48)

strcat         char *strcat(char *dest, const char *src );

               (src/strcat.c: 7)

strchr         char *strchr(const char *s, int c);

               (src/strchr.c: 20)

strchrnul      char *strchrnul(const char *s, int c);

               (src/strchr.c: 7)

strcmp         int strcmp(const char*c1,const char*c2);

               (src/strcmp.c: 67)

strcpy         char *strcpy(char *dest, const char *src);

               (src/memcpy.c: 17)

strdup         char *strdup(const char *source);

               (src/strdup.c: 7)

strerror       static char* strerror( int errnum );

               (src/strerror.c: 7)

strlen         int strlen(const char*str);

               (src/strlen.c: 7)

strncasecmp    int strncasecmp(const char*c1,const char*c2,int len);

               (src/strcmp.c: 56)

strncmp        int strncmp(const char*c1,const char*c2,int len);

               (src/strcmp.c: 75)

strncpy        char *strncpy(char *dest, const char *src, int n);

               (src/memcpy.c: 27)

strrchr        char *strrchr(const char *s, int c);

               (src/strchr.c: 36)

strstr         char* strstr(const char *big, const char *little);

               (src/strstr.c: 3)



==========
sys/wait.h
==========

wait           pid_t wait(int *wstatus);

               (src/wait.c: 8)

waitpid        pid_t waitpid(pid_t pid, int *wstatus, int options);

               (src/wait.c: 16)



==========
time.h
==========



==========
unistd.h
==========

execl          static int execl(const char *pathname, const char* arg0,... );

               (src/execl.c: 6)

execv          static inline int execv(const char *pathname, char *const argv[]);

               (src/execvp.c: 9)

execvp         static inline int execvp(const char *file, char *const argv[]);

               (src/execvp.c: 58)

execvpe        static int execvpe(const char *file, char *const argv[], char *const envp[]);

               When invoked with a filename, starting with "." or "/",
              interprets this as absolute path. (calls execve with the pathname)
              Looks for file in the PATH environment, othwerise.
               (src/execvp.c: 18)

isatty         int isatty(int fd);

               (src/isatty.c: 7)

open           int volatile open( const char *s, int flags, ... );

               open or create a file.
              warning: when using the flag O_CREAT,
              file permission flags have to be given
              as third argument. Otherwise file permission
              flags will be random. (I still do not know, what 
              the flag showing up as "-T" means..)
               (src/open.c: 19)

select         static int volatile __attribute__((optimize("O0"))) select(int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait);

               (include/select.h: 9)

sleep          unsigned int volatile sleep(unsigned int seconds);

               nonconformant sleep
              TODO: ignore blocked signals, sigchld
               (src/sleep.c: 10)

tcgetattr      static inline int __attribute__((always_inline)) tcgetattr(int fd, struct termios *io);

               (include/tcgetattr.h: 21)

tcsetattr      static inline int __attribute__((always_inline)) tcsetattr(int fd, int opt, const struct termios *io);

               (include/tcsetattr.h: 20)

usleep         unsigned int volatile usleep(unsigned int useconds);

               nonconformant usleep. 
              Sleep useconds.
              I just hope, noone relies on an exact sleep time.
              which isn't possible without a real time os, anyways.
              When for whatever reason you'd need nanoseconds exact times,
              best shot might be a spinloop, and looking for cpu ticks.
             
              TODO: ignore blocked signals, sigchld
               (src/sleep.c: 31)

