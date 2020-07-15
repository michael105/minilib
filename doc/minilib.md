

==========
declarations.h
==========



==========
dirent.h
==========

closedir       int closedir(DIR *dir);

               (src/dirent/closedir.c: 6)

opendir        DIR *opendir(const char *name);

               (src/dirent/opendir.c: 10)

readdir        struct dirent *readdir(DIR *dir);

               (src/dirent/readdir.c: 10)



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

basename       char *basename(char *path);

               (src/basename.c: 29)

brk            static int brk( const void* addr );

               conformant brk, when mini_errno is defined
              if no errno is available,
              returns the negative errno value on error,
              0 on success
               (src/brk.c: 14)

def            #define SETOPT_short( opts, option ) (;

               Set a option flag(s) (bit(s))  manually.
             		param options: e.g. just a, or ( a+h+l) to check for several flags at once
               (macros/getoptm.h: 52)

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

               (src/sprintf.c: 203)

dtodec         int dtodec(double d, char* buf, int precision);

               (src/dtodec.c: 10)

eprint         #define eprint(str) write(STDERR_FILENO,str,strlen(str))

               write str to stderr. Needs strlen
               (include/prints.h: 35)

eprintfs       #define eprintfs(fmt,...) fprintfs(stderr, fmt, __VA_ARGS__)

               write str to stderr. 
              only format %s is recognized
               (include/prints.h: 83)

eprintl        #define eprintl() write(STDERR_FILENO,"\n",1)

               write a newline to stderr
               (include/prints.h: 60)

eputs          #define eputs(msg) ( eprint(msg) + eprintl() )

               write msg to stderr, append a newline. Needs strlen.
               (include/prints.h: 70)

ewrites        #define ewrites(str) write(STDERR_FILENO,str,sizeof(str))

               write the constant str to stderr. Computes length with sizeof(str) at compile time.
               (include/prints.h: 45)

fexecve        static inline int fexecve(int fd, char *const argv[], char *const envp[]);

               (include/fexecve.h: 3)

fexecveat      static inline int fexecveat(int fd, char *const argv[], char *const envp[]);

               (include/fexecveat.h: 3)

fprintfs       int fprintfs( FILE* F, char *fmt, ...);

               prints formatted to the stream F.only %s is recognized.no mini_buf needed, so using fprintfs instead of fprintf can save some sections / bytes.
               (src/fprintfs.c: 10)

fprints        #define fprints(F,str) write(fileno(F),str,strlen(str))

               print the string(s) supplied as arg(s) to stream
               (include/prints.h: 17)

fwrites        #define fwrites(fd,str) write(fd,str,sizeof(str))

               write the constant str to fd. Computes length with sizeof(str) at compile time.
               (include/prints.h: 51)

grantpt        int grantpt(int fd);

               (src/pty.c: 13)

itobin         #define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )

               (src/itobin.c: 41)

itodec         int itodec(int i, char *buf, int prec, char limiter );

               (src/itodec.c: 116)

ltodec         int ltodec(long i, char *buf, int prec, char limiter );

               (src/ltodec.c: 75)

macro          static void __attribute__((noipa)) optimization_fence(void*p){}

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
               (include/minilib_global.h: 77)

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

posix_openpt   int posix_openpt(int flags);

               (src/pty.c: 8)

print          #define print(str) write(STDOUT_FILENO,str,strlen(str))

               write str to stdout. Needs strlen
               (include/prints.h: 31)

printfs        #define printfs(fmt,...) fprintfs(stdout, fmt, __VA_ARGS__)

               write str to stdout. 
              only format %s is recognized
               (include/prints.h: 77)

printl         #define printl() write(STDOUT_FILENO,"\n",1)

               write a newline to stdout
               (include/prints.h: 56)

prints         #define prints(...) _mprints(__VA_ARGS__,0)

               print the string(s) supplied as arg(s) to stdout
               (include/prints.h: 11)

printsl        #define printsl(...) _mprints(__VA_ARGS__,"\n",0)

               print the string(s) supplied as arg(s) and newline to stdout
               (include/prints.h: 25)

ptsname        char *ptsname(int fd);

               (src/pty.c: 40)

ptsname_r      int ptsname_r(int fd, char *buf, size_t len);

               (src/pty.c: 27)

sbrk           static void* sbrk(int incr);

               conformant sbrk, when mini_errno is defined
              if no errno is available,
              returns the negative errno value on error,
              or the new break on success. 
               (src/brk.c: 35)

sdbm_hash      unsigned long sdbm_hash(const unsigned char *str);

               (src/hashes.c: 21)

snprintf       int snprintf( char *buf, size_t size, const char *fmt, ... );

               (src/sprintf.c: 220)

sys_brk        static long sys_brk(unsigned long addr);

               the kernel syscall brk.
               (src/brk.c: 3)

todo_abort     void todo_abort();

               (src/abort.c: 3)

uitodec        int uitodec(unsigned int i, char *buf, int prec, char limiter );

               (src/itodec.c: 8)

ultodec        int ultodec(unsigned long ui, char *buf, int prec, char limiter );

               (src/ltodec.c: 6)

unlockpt       int unlockpt(int fd);

               (src/pty.c: 20)

verbose_errstr const char* verbose_errstr(int num);

               verbose error (errno) string. 
              this adds about 3.5kB to the compiled binary(!)
               (include/errstr.h: 8)

vsnprintf      int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );

               the function, translating the fmt of printf.
              warning - most possibly you'd like to define besides fprintf, or family,
              mini_itodec (%d conversion) 
              mini_atoi is needed for grouping numbers
               (src/sprintf.c: 41)

writes         #define writes(str) write(STDOUT_FILENO,str,sizeof(str))

               write the constant str to stdout. Computes length with sizeof(str) at compile time.
               (include/prints.h: 41)



==========
mini_ksyscalls
==========

ksys__sysctl       
ksys_accept        
ksys_accept4       
ksys_access        
ksys_acct          
ksys_add_key       
ksys_adjtimex      
ksys_alarm         
ksys_arch_prctl    
ksys_bind          
ksys_brk           
ksys_capget        
ksys_capset        
ksys_chdir         
ksys_chmod         
ksys_chown         
ksys_chroot        
ksys_clock_adjtime 
ksys_clock_getres  
ksys_clock_gettime 
ksys_clock_nanosleep
ksys_clock_settime 
ksys_clone         
ksys_close         
ksys_connect       
ksys_creat         
ksys_delete_module 
ksys_dup           
ksys_dup2          
ksys_dup3          
ksys_epoll_create  
ksys_epoll_create1 
ksys_epoll_ctl     
ksys_epoll_pwait   
ksys_epoll_wait    
ksys_eventfd       
ksys_eventfd2      
ksys_execve        
ksys_exit          
ksys_exit_group    
ksys_faccessat     
ksys_fadvise64     
ksys_fallocate     
ksys_fanotify_init 
ksys_fanotify_mark 
ksys_fchdir        
ksys_fchmod        
ksys_fchmodat      
ksys_fchown        
ksys_fchownat      
ksys_fcntl         
ksys_fdatasync     
ksys_fgetxattr     
ksys_finit_module  
ksys_flistxattr    
ksys_flock         
ksys_fork          
ksys_fremovexattr  
ksys_fsetxattr     
ksys_fstat         
ksys_fstatfs       
ksys_fsync         
ksys_ftruncate     
ksys_futex         
ksys_futimesat     
ksys_get_mempolicy 
ksys_get_robust_list
ksys_getcpu        
ksys_getcwd        
ksys_getdents      
ksys_getdents64    
ksys_getegid       
ksys_geteuid       
ksys_getgid        
ksys_getgroups     
ksys_getitimer     
ksys_getpeername   
ksys_getpgid       
ksys_getpgrp       
ksys_getpid        
ksys_getppid       
ksys_getpriority   
ksys_getrandom     
ksys_getresgid     
ksys_getresuid     
ksys_getrlimit     
ksys_getrusage     
ksys_getsid        
ksys_getsockname   
ksys_getsockopt    
ksys_gettid        
ksys_gettimeofday  
ksys_getuid        
ksys_getxattr      
ksys_init_module   
ksys_inotify_add_watch
ksys_inotify_init  
ksys_inotify_init1 
ksys_inotify_rm_watch
ksys_io_cancel     
ksys_io_destroy    
ksys_io_getevents  
ksys_io_setup      
ksys_io_submit     
ksys_ioctl         
ksys_ioperm        
ksys_iopl          
ksys_ioprio_get    
ksys_ioprio_set    
ksys_kcmp          
ksys_kexec_file_load
ksys_kexec_load    
ksys_keyctl        
ksys_kill          
ksys_lchown        
ksys_lgetxattr     
ksys_link          
ksys_linkat        
ksys_listen        
ksys_listxattr     
ksys_llistxattr    
ksys_lookup_dcookie
ksys_lremovexattr  
ksys_lseek         
ksys_lsetxattr     
ksys_lstat         
ksys_madvise       
ksys_mbind         
ksys_memfd_create  
ksys_migrate_pages 
ksys_mincore       
ksys_mkdir         
ksys_mkdirat       
ksys_mknod         
ksys_mknodat       
ksys_mlock         
ksys_mlockall      
ksys_mmap          
ksys_modify_ldt    
ksys_mount         
ksys_move_pages    
ksys_mprotect      
ksys_mq_getsetattr 
ksys_mq_notify     
ksys_mq_open       
ksys_mq_timedreceive
ksys_mq_timedsend  
ksys_mq_unlink     
ksys_mremap        
ksys_msgctl        
ksys_msgget        
ksys_msgrcv        
ksys_msgsnd        
ksys_msync         
ksys_munlock       
ksys_munlockall    
ksys_munmap        
ksys_name_to_handle_at
ksys_nanosleep     
ksys_newfstatat    
ksys_open          
ksys_open_by_handle_at
ksys_openat        
ksys_pause         
ksys_perf_event_open
ksys_personality   
ksys_pipe          
ksys_pipe2         
ksys_pivot_root    
ksys_poll          
ksys_ppoll         
ksys_prctl         
ksys_pread64       
ksys_preadv        
ksys_prlimit64     
ksys_process_vm_readv
ksys_process_vm_writev
ksys_pselect6      
ksys_ptrace        
ksys_pwrite64      
ksys_pwritev       
ksys_quotactl      
ksys_read          
ksys_readahead     
ksys_readlink      
ksys_readlinkat    
ksys_readv         
ksys_reboot        
ksys_recvfrom      
ksys_recvmmsg      
ksys_recvmsg       
ksys_remap_file_pages
ksys_removexattr   
ksys_rename        
ksys_renameat      
ksys_renameat2     
ksys_request_key   
ksys_restart_syscall
ksys_rmdir         
ksys_rt_sigaction  
ksys_rt_sigpending 
ksys_rt_sigprocmask
ksys_rt_sigqueueinfo
ksys_rt_sigreturn  
ksys_rt_sigsuspend 
ksys_rt_sigtimedwait
ksys_rt_tgsigqueueinfo
ksys_sched_get_priority_max
ksys_sched_get_priority_min
ksys_sched_getaffinity
ksys_sched_getattr 
ksys_sched_getparam
ksys_sched_getscheduler
ksys_sched_rr_get_interval
ksys_sched_setaffinity
ksys_sched_setattr 
ksys_sched_setparam
ksys_sched_setscheduler
ksys_sched_yield   
ksys_seccomp       
ksys_select        
ksys_semctl        
ksys_semget        
ksys_semop         
ksys_semtimedop    
ksys_sendfile      
ksys_sendmmsg      
ksys_sendmsg       
ksys_sendto        
ksys_set_mempolicy 
ksys_set_robust_list
ksys_set_tid_address
ksys_setdomainname 
ksys_setfsgid      
ksys_setfsuid      
ksys_setgid        
ksys_setgroups     
ksys_sethostname   
ksys_setitimer     
ksys_setns         
ksys_setpgid       
ksys_setpriority   
ksys_setregid      
ksys_setresgid     
ksys_setresuid     
ksys_setreuid      
ksys_setrlimit     
ksys_setsid        
ksys_setsockopt    
ksys_settimeofday  
ksys_setuid        
ksys_setxattr      
ksys_shmat         
ksys_shmctl        
ksys_shmdt         
ksys_shmget        
ksys_shutdown      
ksys_sigaltstack   
ksys_signalfd      
ksys_signalfd4     
ksys_socket        
ksys_socketpair    
ksys_splice        
ksys_stat          
ksys_statfs        
ksys_swapoff       
ksys_swapon        
ksys_symlink       
ksys_symlinkat     
ksys_sync          
ksys_sync_file_range
ksys_syncfs        
ksys_sysfs         
ksys_sysinfo       
ksys_syslog        
ksys_tee           
ksys_tgkill        
ksys_time          
ksys_timer_create  
ksys_timer_delete  
ksys_timer_getoverrun
ksys_timer_gettime 
ksys_timer_settime 
ksys_timerfd_create
ksys_timerfd_gettime
ksys_timerfd_settime
ksys_times         
ksys_tkill         
ksys_truncate      
ksys_umask         
ksys_umount2       
ksys_uname         
ksys_unlink        
ksys_unlinkat      
ksys_unshare       
ksys_ustat         
ksys_utime         
ksys_utimensat     
ksys_utimes        
ksys_vfork         
ksys_vhangup       
ksys_vmsplice      
ksys_wait4         
ksys_waitid        
ksys_write         
ksys_writev        


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
               (src/fopen.c: 90)

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
               (src/fopen.c: 80)

fprint         #define fprint(...) fprintf(__VA_ARGS__)

               (include/mini_fstream.h: 95)

fprintf        #define fprintf(stream,...)	write(fileno(stream),mlgl->mbuf,sprintf(mlgl->mbuf,__VA_ARGS__))

               (src/sprintf.c: 245)

fputc          static inline int volatile fputc(int c, FILE* F);

               (include/fputc.h: 10)

fputs          static inline int volatile fputs(const char *c, FILE *F);

               (include/fputs.h: 20)

fread          static inline size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f);

               (include/mini_fstream.h: 162)

freopen        FILE *freopen(const char* filename, const char* mode, FILE *F);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 100)

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

               (src/itohex.c: 56)

itohex         int itohex(int i,char* buf,int padding);

               (src/itohex.c: 49)

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
               (include/prints.h: 66)

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



==========
stdlib.h
==========

abs            static int abs(int i);

               (include/math.h: 25)

atoi           int atoi(const char *c);

               (src/atoi.c: 6)

atol           long atol(const char *c);

               (src/atoi.c: 43)

div            static div_t div(int numerator, int denominator);

               (include/math.h: 8)

free           void volatile free(void* p);

               (src/malloc.c: 278)

getenv         char* getenv(const char* name);

               (src/getenv.c: 8)

labs           static long int labs(long int i);

               (include/math.h: 30)

ldiv           static ldiv_t ldiv(long int numerator, long int denominator);

               (include/math.h: 16)

malloc         void* volatile malloc(int size);

               (src/malloc.c: 228)

rand           unsigned int rand();

               (src/rand.c: 15)

realloc        void* realloc(void *p, int size);

               (src/malloc.c: 159)

srand          void srand( unsigned int i );

               (src/rand.c: 7)

strtol         long int strtol(const char *c, const char **endp, int base);

               conversion
              doesn't check for overflow(!)
               (src/strtol.c: 5)

system         int system( const char* command );

               (src/system.c: 4)

todo_putenv    int todo_putenv( char *s );

               (src/getenv.c: 22)



==========
string.h
==========

_strcasecmp    int _strcasecmp(const char*c1,const char*c2,int len);

               (src/strcmp.c: 30)

_strcmp        int _strcmp(const char*c1,const char*c2,int len);

               (src/strcmp.c: 13)

errno_str      const char *errno_str(int err);

               convert errno to str, with 3 chars length
              ending the string (located on the stack (!) 
              with two \0\0, when errno<100
               (src/strerror.c: 32)

memcmp         int memcmp(const void* c1,const void* c2,int len);

               (src/strcmp.c: 85)

memcpy         void *memcpy( void *d, const void *s, int n );

               (src/memcpy.c: 6)

memmove        void* memmove(void *dest, const void *src, int n);

               (src/memmove.c: 3)

memset         void *memset( void *s, int c, int n);

               (src/memset.c: 3)

strcasecmp     int strcasecmp(const char*c1,const char*c2);

               (src/strcmp.c: 49)

strcat         char *strcat(char *dest, const char *src );

               (src/strcat.c: 7)

strchr         char *strchr(const char *s, int c);

               (src/strchr.c: 20)

strchrnul      char *strchrnul(const char *s, int c);

               (src/strchr.c: 7)

strcmp         int strcmp(const char*c1,const char*c2);

               (src/strcmp.c: 68)

strcpy         char *strcpy(char *dest, const char *src);

               (src/memcpy.c: 17)

strdup         char *strdup(const char *source);

               (src/strdup.c: 7)

strerror       char* strerror( int errnum );

               (src/strerror.c: 9)

strlen         int strlen(const char*str);

               (src/strlen.c: 7)

strncasecmp    int strncasecmp(const char*c1,const char*c2,int len);

               (src/strcmp.c: 57)

strncmp        int strncmp(const char*c1,const char*c2,int len);

               (src/strcmp.c: 76)

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

