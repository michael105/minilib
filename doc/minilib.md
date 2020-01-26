

==========
ctype.h
==========

isprint        static inline int __attribute__((always_inline)) isprint(const char c);

               (include/isprint.h: 8)

isspace        int isspace(int c);

               (src/isspace.c: 6)



==========
declarations.h
==========

dup3           
               (include/syscalls_x64.h: 592)

fstat          
               (include/syscalls_x64.h: 15)

getcwd         
               (include/syscalls_x64.h: 163)

getdents       
               (include/syscalls_x64.h: 161)

gettimeofday   
               (include/syscalls_x64.h: 197)

mprotect       
               (include/syscalls_x64.h: 25)

stat           
               (include/syscalls_x64.h: 13)

uname          
               (include/syscalls_x64.h: 131)



==========
dirent.h
==========

closedir       int closedir(DIR *dir);

               (src/dirent/closedir.c: 6)

opendir        DIR *opendir(const char *name);

               (src/dirent/opendir.c: 10)

readdir        struct dirent *readdir(DIR *dir);

               (src/dirent/readdir.c: 9)

statfs         
               (include/syscalls_x64.h: 279)



==========
fcntl.h
==========

creat          
               (include/syscalls_x64.h: 175)



==========
ioctl.h
==========

ioctl          
               (include/syscalls_x64.h: 37)



==========
mini_addons.h
==========

_itobin        int _itobin(int i, char*buf, int prec, int groups );

               (src/itobin.c: 8)

_mprints       #define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)

               (src/prints.c: 66)

_strcmp        int _strcmp(const char*c1,const char*c2,int len);

               (src/mstrcmp.c: 11)

_sysctl        
               (include/syscalls_x64.h: 317)

accept         
               (include/syscalls_x64.h: 91)

accept4        
               (include/syscalls_x64.h: 584)

acct           
               (include/syscalls_x64.h: 331)

add_key        
               (include/syscalls_x64.h: 504)

adjtimex       
               (include/syscalls_x64.h: 323)

arch_prctl     
               (include/syscalls_x64.h: 321)

basename       char *basename(char *path);

               (src/basename.c: 29)

bind           
               (include/syscalls_x64.h: 103)

bpf            
               (include/syscalls_x64.h: 650)

brk            
               (include/syscalls_x64.h: 29)

capget         
               (include/syscalls_x64.h: 255)

capset         
               (include/syscalls_x64.h: 257)

chmod          
               (include/syscalls_x64.h: 185)

clock_adjtime  
               (include/syscalls_x64.h: 618)

clock_getres   
               (include/syscalls_x64.h: 465)

clock_gettime  
               (include/syscalls_x64.h: 463)

clock_nanosleep
               (include/syscalls_x64.h: 467)

clock_settime  
               (include/syscalls_x64.h: 461)

clone          
               (include/syscalls_x64.h: 117)

connect        
               (include/syscalls_x64.h: 89)

creat          
               (include/syscalls_x64.h: 175)

def            #define SETOPT_short( opts, option ) (;

               Set a option flag(s) (bit(s))  manually.
             		param options: e.g. just a, or ( a+h+l) to check for several flags at once
               (macros/getoptm.h: 52)

delete_module  
               (include/syscalls_x64.h: 357)

dprintf        int dprintf( int fd, const char *fmt, ... );

               (src/sprintf.c: 202)

dtodec         int dtodec(double d, char* buf, int precision);

               (src/dtodec.c: 10)

dup3           
               (include/syscalls_x64.h: 592)

epoll_create   
               (include/syscalls_x64.h: 431)

epoll_create1  
               (include/syscalls_x64.h: 590)

epoll_ctl      
               (include/syscalls_x64.h: 473)

epoll_pwait    
               (include/syscalls_x64.h: 570)

epoll_wait     
               (include/syscalls_x64.h: 471)

eventfd        
               (include/syscalls_x64.h: 576)

eventfd2       
               (include/syscalls_x64.h: 588)

exit_group     
               (include/syscalls_x64.h: 469)

faccessat      
               (include/syscalls_x64.h: 546)

fadvise64      
               (include/syscalls_x64.h: 449)

fallocate      
               (include/syscalls_x64.h: 578)

fanotify_init  
               (include/syscalls_x64.h: 608)

fanotify_mark  
               (include/syscalls_x64.h: 610)

fchmod         
               (include/syscalls_x64.h: 187)

fchmodat       
               (include/syscalls_x64.h: 544)

fchown         
               (include/syscalls_x64.h: 191)

fchownat       
               (include/syscalls_x64.h: 528)

fcntl          
               (include/syscalls_x64.h: 149)

fdatasync      
               (include/syscalls_x64.h: 155)

fgetxattr      
               (include/syscalls_x64.h: 390)

finit_module   
               (include/syscalls_x64.h: 634)

flistxattr     
               (include/syscalls_x64.h: 396)

flock          
               (include/syscalls_x64.h: 151)

fprintfs       int fprintfs( FILE* F, char *fmt, ...);

               prints formatted to the stream F.only %s is recognized.no mini_buf needed, so using fprintfs instead of fprintf can save some sections / bytes.
               (src/fprintfs.c: 10)

fprints        #define fprints(F,str) write(fileno(F),str,strlen(str))

               print the string(s) supplied as arg(s) to stream
               (include/prints.h: 17)

fremovexattr   
               (include/syscalls_x64.h: 402)

fsetxattr      
               (include/syscalls_x64.h: 384)

fstat          
               (include/syscalls_x64.h: 15)

fstatfs        
               (include/syscalls_x64.h: 281)

fsync          
               (include/syscalls_x64.h: 153)

ftruncate      
               (include/syscalls_x64.h: 159)

futex          
               (include/syscalls_x64.h: 408)

futimesat      
               (include/syscalls_x64.h: 530)

fwrites        #define fwrites(fd,str) write(fd,str,sizeof(str))

               write the constant str to stdout. Computes length with sizeof(str) at compile time.
               (include/prints.h: 39)

get_mempolicy  
               (include/syscalls_x64.h: 486)

get_robust_list
               (include/syscalls_x64.h: 556)

getcpu         
               (include/syscalls_x64.h: 626)

getcwd         
               (include/syscalls_x64.h: 163)

getdents       
               (include/syscalls_x64.h: 161)

getdents64     
               (include/syscalls_x64.h: 441)

getitimer      
               (include/syscalls_x64.h: 77)

getpeername    
               (include/syscalls_x64.h: 109)

getpgid        
               (include/syscalls_x64.h: 247)

getppid        
               (include/syscalls_x64.h: 225)

getpriority    
               (include/syscalls_x64.h: 285)

getrandom      
               (include/syscalls_x64.h: 644)

getresgid      
               (include/syscalls_x64.h: 245)

getresuid      
               (include/syscalls_x64.h: 241)

getrlimit      
               (include/syscalls_x64.h: 199)

getrusage      
               (include/syscalls_x64.h: 201)

getsid         
               (include/syscalls_x64.h: 253)

getsockname    
               (include/syscalls_x64.h: 107)

getsockopt     
               (include/syscalls_x64.h: 115)

gettid         
               (include/syscalls_x64.h: 376)

gettimeofday   
               (include/syscalls_x64.h: 197)

getxattr       
               (include/syscalls_x64.h: 386)

init_module    
               (include/syscalls_x64.h: 355)

inotify_add_watch
               (include/syscalls_x64.h: 516)

inotify_init   
               (include/syscalls_x64.h: 514)

inotify_init1  
               (include/syscalls_x64.h: 596)

inotify_rm_watch
               (include/syscalls_x64.h: 518)

io_cancel      
               (include/syscalls_x64.h: 424)

io_destroy     
               (include/syscalls_x64.h: 418)

io_getevents   
               (include/syscalls_x64.h: 420)

io_setup       
               (include/syscalls_x64.h: 416)

io_submit      
               (include/syscalls_x64.h: 422)

ioctl          
               (include/syscalls_x64.h: 37)

ioperm         
               (include/syscalls_x64.h: 351)

iopl           
               (include/syscalls_x64.h: 349)

ioprio_get     
               (include/syscalls_x64.h: 512)

ioprio_set     
               (include/syscalls_x64.h: 510)

itobin         #define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )

               (src/itobin.c: 41)

itodec         int itodec(int i, char *buf, int prec, char limiter );

               (src/itodec.c: 121)

kcmp           
               (include/syscalls_x64.h: 632)

kexec_file_load
               (include/syscalls_x64.h: 648)

kexec_load     
               (include/syscalls_x64.h: 500)

keyctl         
               (include/syscalls_x64.h: 508)

kill           
               (include/syscalls_x64.h: 129)

lchown         
               (include/syscalls_x64.h: 193)

lgetxattr      
               (include/syscalls_x64.h: 388)

linkat         
               (include/syscalls_x64.h: 538)

listen         
               (include/syscalls_x64.h: 105)

listxattr      
               (include/syscalls_x64.h: 392)

llistxattr     
               (include/syscalls_x64.h: 394)

lookup_dcookie 
               (include/syscalls_x64.h: 429)

lremovexattr   
               (include/syscalls_x64.h: 400)

lsetxattr      
               (include/syscalls_x64.h: 382)

lstat          
               (include/syscalls_x64.h: 17)

madvise        
               (include/syscalls_x64.h: 61)

mbind          
               (include/syscalls_x64.h: 482)

memfd_create   
               (include/syscalls_x64.h: 646)

memfrob        void* memfrob(void* s, unsigned int len);

               (src/memfrob.c: 3)

migrate_pages  
               (include/syscalls_x64.h: 520)

mincore        
               (include/syscalls_x64.h: 59)

mkdirat        
               (include/syscalls_x64.h: 524)

mknod          
               (include/syscalls_x64.h: 271)

mknodat        
               (include/syscalls_x64.h: 526)

mlock          
               (include/syscalls_x64.h: 303)

mlockall       
               (include/syscalls_x64.h: 307)

mmap           
               (include/syscalls_x64.h: 23)

modify_ldt     
               (include/syscalls_x64.h: 313)

mount          
               (include/syscalls_x64.h: 335)

move_pages     
               (include/syscalls_x64.h: 566)

mprotect       
               (include/syscalls_x64.h: 25)

mq_getsetattr  
               (include/syscalls_x64.h: 498)

mq_notify      
               (include/syscalls_x64.h: 496)

mq_open        
               (include/syscalls_x64.h: 488)

mq_timedreceive
               (include/syscalls_x64.h: 494)

mq_timedsend   
               (include/syscalls_x64.h: 492)

mq_unlink      
               (include/syscalls_x64.h: 490)

mremap         
               (include/syscalls_x64.h: 55)

msgctl         
               (include/syscalls_x64.h: 147)

msgget         
               (include/syscalls_x64.h: 141)

msgrcv         
               (include/syscalls_x64.h: 145)

msgsnd         
               (include/syscalls_x64.h: 143)

msync          
               (include/syscalls_x64.h: 57)

munlock        
               (include/syscalls_x64.h: 305)

munlockall     
               (include/syscalls_x64.h: 309)

munmap         
               (include/syscalls_x64.h: 27)

name_to_handle_at
               (include/syscalls_x64.h: 614)

nanosleep      
               (include/syscalls_x64.h: 75)

newfstatat     
               (include/syscalls_x64.h: 532)

open_by_handle_at
               (include/syscalls_x64.h: 616)

openat         
               (include/syscalls_x64.h: 522)

perf_event_open
               (include/syscalls_x64.h: 604)

personality    
               (include/syscalls_x64.h: 275)

pipe2          
               (include/syscalls_x64.h: 594)

pivot_root     
               (include/syscalls_x64.h: 315)

poll           
               (include/syscalls_x64.h: 19)

ppoll          
               (include/syscalls_x64.h: 550)

prctl          
               (include/syscalls_x64.h: 319)

pread64        
               (include/syscalls_x64.h: 39)

preadv         
               (include/syscalls_x64.h: 598)

print          #define print(str) write(STDOUT_FILENO,str,strlen(str))

               write str to stdout. Needs strlen
               (include/prints.h: 29)

printl         #define printl() write(STDOUT_FILENO,"\n",1)

               write a newline to stdout
               (include/prints.h: 44)

prints         #define prints(...) _mprints(__VA_ARGS__,0)

               print the string(s) supplied as arg(s) to stdout
               (include/prints.h: 11)

printsl        #define printsl(...) _mprints(__VA_ARGS__,"\n",0)

               print the string(s) supplied as arg(s) and newline to stdout
               (include/prints.h: 25)

prlimit64      
               (include/syscalls_x64.h: 612)

process_vm_readv
               (include/syscalls_x64.h: 628)

process_vm_writev
               (include/syscalls_x64.h: 630)

pselect6       
               (include/syscalls_x64.h: 548)

ptrace         
               (include/syscalls_x64.h: 207)

pwrite64       
               (include/syscalls_x64.h: 41)

pwritev        
               (include/syscalls_x64.h: 600)

quotactl       
               (include/syscalls_x64.h: 363)

readahead      
               (include/syscalls_x64.h: 378)

readlink       
               (include/syscalls_x64.h: 183)

readlinkat     
               (include/syscalls_x64.h: 542)

readv          
               (include/syscalls_x64.h: 43)

reboot         
               (include/syscalls_x64.h: 343)

recvfrom       
               (include/syscalls_x64.h: 95)

recvmmsg       
               (include/syscalls_x64.h: 606)

recvmsg        
               (include/syscalls_x64.h: 99)

remap_file_pages
               (include/syscalls_x64.h: 439)

removexattr    
               (include/syscalls_x64.h: 398)

renameat       
               (include/syscalls_x64.h: 536)

renameat2      
               (include/syscalls_x64.h: 640)

request_key    
               (include/syscalls_x64.h: 506)

restart_syscall
               (include/syscalls_x64.h: 445)

rt_sigaction   
               (include/syscalls_x64.h: 31)

rt_sigpending  
               (include/syscalls_x64.h: 259)

rt_sigprocmask 
               (include/syscalls_x64.h: 33)

rt_sigqueueinfo
               (include/syscalls_x64.h: 263)

rt_sigreturn   
               (include/syscalls_x64.h: 35)

rt_sigsuspend  
               (include/syscalls_x64.h: 265)

rt_sigtimedwait
               (include/syscalls_x64.h: 261)

rt_tgsigqueueinfo
               (include/syscalls_x64.h: 602)

sched_get_priority_max
               (include/syscalls_x64.h: 297)

sched_get_priority_min
               (include/syscalls_x64.h: 299)

sched_getaffinity
               (include/syscalls_x64.h: 412)

sched_getattr  
               (include/syscalls_x64.h: 638)

sched_getparam 
               (include/syscalls_x64.h: 291)

sched_getscheduler
               (include/syscalls_x64.h: 295)

sched_rr_get_interval
               (include/syscalls_x64.h: 301)

sched_setaffinity
               (include/syscalls_x64.h: 410)

sched_setattr  
               (include/syscalls_x64.h: 636)

sched_setparam 
               (include/syscalls_x64.h: 289)

sched_setscheduler
               (include/syscalls_x64.h: 293)

sched_yield    
               (include/syscalls_x64.h: 53)

seccomp        
               (include/syscalls_x64.h: 642)

select         
               (include/syscalls_x64.h: 51)

semctl         
               (include/syscalls_x64.h: 137)

semget         
               (include/syscalls_x64.h: 133)

semop          
               (include/syscalls_x64.h: 135)

semtimedop     
               (include/syscalls_x64.h: 447)

sendfile       
               (include/syscalls_x64.h: 85)

sendmmsg       
               (include/syscalls_x64.h: 622)

sendmsg        
               (include/syscalls_x64.h: 97)

sendto         
               (include/syscalls_x64.h: 93)

set_mempolicy  
               (include/syscalls_x64.h: 484)

set_robust_list
               (include/syscalls_x64.h: 554)

set_tid_address
               (include/syscalls_x64.h: 443)

setdomainname  
               (include/syscalls_x64.h: 347)

setfsgid       
               (include/syscalls_x64.h: 251)

setfsuid       
               (include/syscalls_x64.h: 249)

setgroups      
               (include/syscalls_x64.h: 237)

sethostname    
               (include/syscalls_x64.h: 345)

setitimer      
               (include/syscalls_x64.h: 81)

setns          
               (include/syscalls_x64.h: 624)

setpriority    
               (include/syscalls_x64.h: 287)

setregid       
               (include/syscalls_x64.h: 233)

setresgid      
               (include/syscalls_x64.h: 243)

setresuid      
               (include/syscalls_x64.h: 239)

setreuid       
               (include/syscalls_x64.h: 231)

setrlimit      
               (include/syscalls_x64.h: 325)

setsockopt     
               (include/syscalls_x64.h: 113)

settimeofday   
               (include/syscalls_x64.h: 333)

setxattr       
               (include/syscalls_x64.h: 380)

shmat          
               (include/syscalls_x64.h: 65)

shmctl         
               (include/syscalls_x64.h: 67)

shmdt          
               (include/syscalls_x64.h: 139)

shmget         
               (include/syscalls_x64.h: 63)

shutdown       
               (include/syscalls_x64.h: 101)

sigaltstack    
               (include/syscalls_x64.h: 267)

signalfd       
               (include/syscalls_x64.h: 572)

signalfd4      
               (include/syscalls_x64.h: 586)

snprintf       int snprintf( char *buf, size_t size, const char *fmt, ... );

               (src/sprintf.c: 219)

socket         
               (include/syscalls_x64.h: 87)

socketpair     
               (include/syscalls_x64.h: 111)

splice         
               (include/syscalls_x64.h: 558)

stat           
               (include/syscalls_x64.h: 13)

swapoff        
               (include/syscalls_x64.h: 341)

swapon         
               (include/syscalls_x64.h: 339)

symlink        
               (include/syscalls_x64.h: 181)

symlinkat      
               (include/syscalls_x64.h: 540)

sync           
               (include/syscalls_x64.h: 329)

sync_file_range
               (include/syscalls_x64.h: 562)

syncfs         
               (include/syscalls_x64.h: 620)

sysfs          
               (include/syscalls_x64.h: 283)

sysinfo        
               (include/syscalls_x64.h: 203)

syslog         
               (include/syscalls_x64.h: 211)

tee            
               (include/syscalls_x64.h: 560)

tgkill         
               (include/syscalls_x64.h: 475)

timer_create   
               (include/syscalls_x64.h: 451)

timer_delete   
               (include/syscalls_x64.h: 459)

timer_getoverrun
               (include/syscalls_x64.h: 457)

timer_gettime  
               (include/syscalls_x64.h: 455)

timer_settime  
               (include/syscalls_x64.h: 453)

timerfd_create 
               (include/syscalls_x64.h: 574)

timerfd_gettime
               (include/syscalls_x64.h: 582)

timerfd_settime
               (include/syscalls_x64.h: 580)

times          
               (include/syscalls_x64.h: 205)

truncate       
               (include/syscalls_x64.h: 157)

uitodec        int uitodec(unsigned int i, char *buf, int prec, char limiter );

               (src/itodec.c: 8)

umask          
               (include/syscalls_x64.h: 195)

umount2        
               (include/syscalls_x64.h: 337)

uname          
               (include/syscalls_x64.h: 131)

unlinkat       
               (include/syscalls_x64.h: 534)

unshare        
               (include/syscalls_x64.h: 552)

ustat          
               (include/syscalls_x64.h: 277)

utime          
               (include/syscalls_x64.h: 269)

utimensat      
               (include/syscalls_x64.h: 568)

utimes         
               (include/syscalls_x64.h: 477)

vfork          
               (include/syscalls_x64.h: 121)

vhangup        
               (include/syscalls_x64.h: 311)

vmsplice       
               (include/syscalls_x64.h: 564)

vsnprintf      int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );

               (src/sprintf.c: 36)

wait4          
               (include/syscalls_x64.h: 127)

waitid         
               (include/syscalls_x64.h: 502)

writes         #define writes(str) write(STDOUT_FILENO,str,sizeof(str))

               write the constant str to stdout. Computes length with sizeof(str) at compile time.
               (include/prints.h: 34)

writev         
               (include/syscalls_x64.h: 45)



==========
stdio.h
==========

_itohex        int _itohex(int i,char* buf,int padding, int capitals);

               (src/itohex.c: 5)

clearerror     static inline void clearerror(FILE *f);

               (include/mini_fstream.h: 198)

fclose         static inline int __attribute__((always_inline)) fclose( FILE* f );

               (include/mini_fstream.h: 65)

feof           static inline int feof(FILE *f);

               (include/mini_fstream.h: 184)

ferror         static inline int ferror(FILE *f);

               (include/mini_fstream.h: 191)

fflush         static inline int __attribute__((always_inline)) fflush( FILE *F );

               This does nothing, since minilib doesn't provide buffered streams yet.in order to sync the stream, please use fsync
               (include/mini_fstream.h: 28)

fgetc          static inline int fgetc(FILE *F);

               (include/fgetc.h: 10)

fgetpos        static inline void fgetpos(FILE *f, long *pos );

               (include/mini_fstream.h: 127)

fileno         static inline int __attribute__((always_inline)) fileno( FILE *f );

               (include/mini_fstream.h: 55)

fopen          FILE *fopen(const char* filename, const char* mode);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 12)

fprint         #define fprint(...) fprintf(__VA_ARGS__)

               (include/mini_fstream.h: 95)

fprintf        #define fprintf(stream,...)	write(fileno(stream),ml.mbuf,sprintf(ml.mbuf,__VA_ARGS__))

               (src/sprintf.c: 244)

fputc          static inline int volatile fputc(int c, FILE* F);

               (include/fputc.h: 10)

fputs          static inline int volatile fputs(const char *c, FILE *F);

               (include/fputs.h: 14)

fread          static inline size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f);

               (include/mini_fstream.h: 162)

fseek          static inline int fseek(FILE *f, long offset, int whence );

               (include/mini_fstream.h: 146)

fsetpos        static inline int fsetpos(FILE *f, int pos );

               (include/mini_fstream.h: 133)

ftell          static inline long ftell(FILE *f);

               (include/mini_fstream.h: 121)

fwrite         static inline size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *f);

               (include/mini_fstream.h: 106)

getc           #define getc(F) fgetc(F)

               (include/fgetc.h: 18)

itoHEX         int itoHEX(int i,char* buf,int padding);

               (src/itohex.c: 55)

itohex         int itohex(int i,char* buf,int padding);

               (src/itohex.c: 48)

perror         void perror(char *msg);

               (src/strerror.c: 22)

printf         #define printf(...) fprintf(stdout,__VA_ARGS__)

               (include/mini_fstream.h: 91)

putc           #define putc(c,stream) fputc(c,stream)

               (include/fputc.h: 19)

putchar        #define putchar(c) fputc(c,stdout)

               (include/fputc.h: 16)

puts           #define puts(msg) ( print(msg) + printl() )

               write msg to stdout, append a newline. Needs strlen.
               (include/prints.h: 49)

rewind         static inline void rewind( FILE *f );

               (include/mini_fstream.h: 156)

setbuf         void setbuf(FILE *stream, char *buf);

               dummy functions.
              There is no buffering implemented for the streams yet.
               (include/mini_fstream.h: 206)

setvbuf        int setvbuf(FILE *stream, char *buf, int mode, size_t size);

               dummy
               (include/mini_fstream.h: 210)

sprintf        #define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)

               (src/sprintf.c: 26)

vfprintf       #define vfprintf(...) fprintf(__VA_ARGS__)

               (include/mini_fstream.h: 100)



==========
stdlib.h
==========

atoi           int atoi(char *c);

               (src/atoi.c: 6)

exit           
               (include/syscalls_x64.h: 125)

free           void volatile free(void* p);

               (src/malloc.c: 200)

getenv         char *getenv(const char* name);

               (src/getenv.c: 11)

malloc         void* volatile malloc(int size);

               (src/malloc.c: 150)

rand           unsigned int rand();

               (src/rand.c: 15)

srand          void srand( unsigned int i );

               (src/rand.c: 7)



==========
string.h
==========

memcmp         int memcmp(const void* c1,const void* c2,int len);

               (src/mstrcmp.c: 43)

memcpy         void *memcpy( void *d, const void *s, int n );

               (src/memcpy.c: 6)

memset         void *memset( void *s, int c, int n);

               (src/memset.c: 3)

strcat         char *strcat(char *dest, const char *src );

               (src/strcat.c: 7)

strcmp         int strcmp(const char*c1,const char*c2);

               (src/mstrcmp.c: 27)

strcpy         char *strcpy(char *dest, const char *src);

               (src/memcpy.c: 17)

strerror       char* strerror( int errnum );

               (src/strerror.c: 9)

strlen         int strlen(const char*str);

               (src/strlen.c: 7)

strncmp        int strncmp(const char*c1,const char*c2,int len);

               (src/mstrcmp.c: 34)

strncpy        char *strncpy(char *dest, const char *src, int n);

               (src/memcpy.c: 27)



==========
time.h
==========

time           
               (include/syscalls_x64.h: 406)



==========
unistd.h
==========

access         
               (include/syscalls_x64.h: 47)

alarm          
               (include/syscalls_x64.h: 79)

chdir          
               (include/syscalls_x64.h: 165)

chown          
               (include/syscalls_x64.h: 189)

chroot         
               (include/syscalls_x64.h: 327)

close          
               (include/syscalls_x64.h: 11)

dup            
               (include/syscalls_x64.h: 69)

dup2           
               (include/syscalls_x64.h: 71)

execve         
               (include/syscalls_x64.h: 123)

fchdir         
               (include/syscalls_x64.h: 167)

fork           
               (include/syscalls_x64.h: 119)

fsync          
               (include/syscalls_x64.h: 153)

ftruncate      
               (include/syscalls_x64.h: 159)

getegid        
               (include/syscalls_x64.h: 221)

geteuid        
               (include/syscalls_x64.h: 219)

getgid         
               (include/syscalls_x64.h: 213)

getgroups      
               (include/syscalls_x64.h: 235)

getpgrp        
               (include/syscalls_x64.h: 227)

getpid         
               (include/syscalls_x64.h: 83)

getuid         
               (include/syscalls_x64.h: 209)

link           
               (include/syscalls_x64.h: 177)

lseek          
               (include/syscalls_x64.h: 21)

mkdir          
               (include/syscalls_x64.h: 171)

open           
               (include/syscalls_x64.h: 9)

pause          
               (include/syscalls_x64.h: 73)

pipe           
               (include/syscalls_x64.h: 49)

read           
               (include/syscalls_x64.h: 5)

rename         
               (include/syscalls_x64.h: 169)

rmdir          
               (include/syscalls_x64.h: 173)

select         
               (include/syscalls_x64.h: 51)

setgid         
               (include/syscalls_x64.h: 217)

setpgid        
               (include/syscalls_x64.h: 223)

setsid         
               (include/syscalls_x64.h: 229)

setuid         
               (include/syscalls_x64.h: 215)

tcgetattr      static inline int __attribute__((always_inline)) tcgetattr(int fd, struct termios *io);

               (include/tcgetattr.h: 17)

tcsetattr      static inline int __attribute__((always_inline)) tcsetattr(int fd, int opt, const struct termios *io);

               (include/tcsetattr.h: 18)

unlink         
               (include/syscalls_x64.h: 179)

write          
               (include/syscalls_x64.h: 7)

