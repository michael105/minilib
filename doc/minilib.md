

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



==========
dirent.h
==========

closedir       int closedir(DIR *dir);

               (src/dirent/closedir.c: 6)

opendir        DIR *opendir(const char *name);

               (src/dirent/opendir.c: 10)

readdir        struct dirent *readdir(DIR *dir);

               (src/dirent/readdir.c: 9)



==========
fcntl.h
==========

creat          int volatile creat( const char *s, int mode );

               (src/open.c: 30)

mkfifo         static int mkfifo( const char* path, mode_t mode );

               (include/mkfifo.h: 4)



==========
ioctl.h
==========

ioctl          int ioctl( int fd, unsigned long int request, ... );

               (src/ioctl.c: 11)



==========
mini_addons.h
==========

_itobin        int _itobin(int i, char*buf, int prec, int groups );

               (src/itobin.c: 8)

_mprints       #define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)

               (src/prints.c: 68)

basename       char *basename(char *path);

               (src/basename.c: 29)

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

               (src/sprintf.c: 202)

dtodec         int dtodec(double d, char* buf, int precision);

               (src/dtodec.c: 10)

fprintfs       int fprintfs( FILE* F, char *fmt, ...);

               prints formatted to the stream F.only %s is recognized.no mini_buf needed, so using fprintfs instead of fprintf can save some sections / bytes.
               (src/fprintfs.c: 10)

fprints        #define fprints(F,str) write(fileno(F),str,strlen(str))

               print the string(s) supplied as arg(s) to stream
               (include/prints.h: 17)

fwrites        #define fwrites(fd,str) write(fd,str,sizeof(str))

               write the constant str to stdout. Computes length with sizeof(str) at compile time.
               (include/prints.h: 39)

grantpt        int grantpt(int fd);

               (src/pty.c: 13)

itobin         #define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )

               (src/itobin.c: 41)

itodec         int itodec(int i, char *buf, int prec, char limiter );

               (src/itodec.c: 121)

ltodec         int ltodec(long i, char *buf, int prec, char limiter );

               (src/ltodec.c: 14)

memfrob        void* memfrob(void* s, unsigned int len);

               (src/memfrob.c: 3)

posix_openpt   int posix_openpt(int flags);

               (src/pty.c: 8)

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

ptsname        char *ptsname(int fd);

               (src/pty.c: 40)

ptsname_r      int ptsname_r(int fd, char *buf, size_t len);

               (src/pty.c: 27)

sdbm_hash      unsigned long sdbm_hash(const unsigned char *str);

               (src/hashes.c: 21)

snprintf       int snprintf( char *buf, size_t size, const char *fmt, ... );

               (src/sprintf.c: 219)

uitodec        int uitodec(unsigned int i, char *buf, int prec, char limiter );

               (src/itodec.c: 8)

ultodec        int ultodec(unsigned long i, char *buf, int prec, char limiter );

               (src/ltodec.c: 3)

unlockpt       int unlockpt(int fd);

               (src/pty.c: 20)

verbose_errstr const char* verbose_errstr(int num);

               verbose error (errno) string. 
              this adds about 3.5kB to the compiled binary(!)
               (include/errstr.h: 4)

vsnprintf      int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );

               (src/sprintf.c: 36)

writes         #define writes(str) write(STDOUT_FILENO,str,sizeof(str))

               write the constant str to stdout. Computes length with sizeof(str) at compile time.
               (include/prints.h: 34)



==========
signal.h
==========

sigaction      int volatile sigaction(int sig, const struct sigaction *act, struct sigaction *oact);

               (src/sigaction.c: 22)

sigaddset      int sigaddset(sigset_t *set, int sig);

               (src/sigaddset.c: 3)

sigemptyset    static int sigemptyset(sigset_t *set);

               (src/sigemptyset.c: 8)

signal         sighandler_t signal(int sig, sighandler_t func );

               (src/signal.c: 9)



==========
stdio.h
==========

_fopen         FILE *_fopen(int fd, const char* filename, const char* mode, FILE *f);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 12)

_itohex        int _itohex(int i,char* buf,int padding, int capitals);

               (src/itohex.c: 6)

clearerr       static inline void clearerr(FILE *f);

               (include/mini_fstream.h: 199)

clearerror     static inline void clearerror(FILE *f);

               (include/mini_fstream.h: 204)

fclose         static inline int __attribute__((always_inline)) fclose( FILE* f );

               (include/mini_fstream.h: 66)

fdopen         FILE *fdopen(int fd, const char* mode);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 87)

feof           static inline int feof(FILE *f);

               (include/mini_fstream.h: 185)

ferror         static inline int ferror(FILE *f);

               (include/mini_fstream.h: 192)

fflush         static inline int __attribute__((always_inline)) fflush( FILE *F );

               This does nothing, since minilib doesn't provide buffered streams yet.in order to sync the stream, please use fsync
               (include/mini_fstream.h: 28)

fgetc          static inline int fgetc(FILE *F);

               (include/fgetc.h: 11)

fgetpos        static inline void fgetpos(FILE *f, long *pos );

               (include/mini_fstream.h: 128)

fgets          char* fgets(char *buf, int size, FILE* F);

               (src/fgets.c: 6)

fileno         static inline int __attribute__((always_inline)) fileno( FILE *f );

               Return the fd nummber of stdin,-out,-err. 
               (include/mini_fstream.h: 56)

fopen          FILE *fopen(const char* filename, const char* mode);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 77)

fprint         #define fprint(...) fprintf(__VA_ARGS__)

               (include/mini_fstream.h: 96)

fprintf        #define fprintf(stream,...)	write(fileno(stream),ml.mbuf,sprintf(ml.mbuf,__VA_ARGS__))

               (src/sprintf.c: 244)

fputc          static inline int volatile fputc(int c, FILE* F);

               (include/fputc.h: 10)

fputs          static inline int volatile fputs(const char *c, FILE *F);

               (include/fputs.h: 20)

fread          static inline size_t fread(void *ptr, size_t size, size_t nmemb, FILE *f);

               (include/mini_fstream.h: 163)

freopen        FILE *freopen(const char* filename, const char* mode, FILE *F);

               modes implemented: r, r+, w, w+, a, a+
               (src/fopen.c: 97)

fseek          static inline int fseek(FILE *f, long offset, int whence );

               (include/mini_fstream.h: 147)

fsetpos        static inline int fsetpos(FILE *f, int pos );

               (include/mini_fstream.h: 134)

ftell          static inline long ftell(FILE *f);

               (include/mini_fstream.h: 122)

fwrite         static inline size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *f);

               (include/mini_fstream.h: 107)

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

               (src/strerror.c: 26)

printf         #define printf(...) fprintf(stdout,__VA_ARGS__)

               (include/mini_fstream.h: 92)

putc           #define putc(c,stream) fputc(c,stream)

               (include/fputc.h: 19)

putchar        #define putchar(c) fputc(c,stdout)

               (include/fputc.h: 16)

puts           #define puts(msg) ( print(msg) + printl() )

               write msg to stdout, append a newline. Needs strlen.
               (include/prints.h: 49)

rewind         static inline void rewind( FILE *f );

               (include/mini_fstream.h: 157)

setbuf         static void setbuf(FILE *stream, char *buf);

               dummy functions.
              There is no buffering implemented for the streams yet.
               (include/mini_fstream.h: 212)

setvbuf        static int setvbuf(FILE *stream, char *buf, int mode, size_t size);

               dummy
               (include/mini_fstream.h: 217)

sprintf        #define sprintf(str,...) snprintf( str, 4096,  __VA_ARGS__)

               (src/sprintf.c: 26)

ungetc         static int ungetc(int c, FILE *F);

               (include/fgetc.h: 36)

vfprintf       #define vfprintf(...) fprintf(__VA_ARGS__)

               (include/mini_fstream.h: 101)



==========
stdlib.h
==========

atoi           int atoi(const char *c);

               (src/atoi.c: 6)

free           void volatile free(void* p);

               (src/malloc.c: 216)

getenv         char* getenv(const char* name);

               (src/getenv.c: 8)

malloc         void* volatile malloc(int size);

               (src/malloc.c: 166)

rand           unsigned int rand();

               (src/rand.c: 15)

realloc        void* realloc(void *p, int size);

               (src/malloc.c: 155)

srand          void srand( unsigned int i );

               (src/rand.c: 7)

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

memcmp         int memcmp(const void* c1,const void* c2,int len);

               (src/strcmp.c: 85)

memcpy         void *memcpy( void *d, const void *s, int n );

               (src/memcpy.c: 6)

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

               (src/execvp.c: 7)

execvp         static inline int execvp(const char *file, char *const argv[]);

               (src/execvp.c: 28)

execvpe        static inline int execvpe(const char *file, char *const argv[], char *const envp[]);

               doesn't search the path env (todo)
               (src/execvp.c: 20)

fexecveat      static inline int fexecveat(int fd, char *const argv[], char *const envp[]);

               (src/execvp.c: 12)

isatty         int isatty(int fd);

               (src/isatty.c: 7)

open           int volatile open( const char *s, int flags, ... );

               (src/open.c: 13)

select         static inline int volatile __attribute__((always_inline)) select(int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait);

               (include/select.h: 10)

sleep          unsigned int sleep(unsigned int seconds);

               nonconformant sleep
              TODO: ignore blocked signals, sigchld
               (src/sleep.c: 10)

tcgetattr      static inline int __attribute__((always_inline)) tcgetattr(int fd, struct termios *io);

               (include/tcgetattr.h: 21)

tcsetattr      static inline int __attribute__((always_inline)) tcsetattr(int fd, int opt, const struct termios *io);

               (include/tcsetattr.h: 20)

usleep         unsigned int usleep(unsigned int useconds);

               nonconformant usleep. 
              Sleep useconds, one usecond equals 1.024 microseconds.
              I just hope, noone relies on an exact sleep time.
              which isn't possible without a real time os, anyways.
              When for whatever reason you'd need nanoseconds exact times,
              best shot might be a spinloop, and looking for cpu ticks.
             
              TODO: ignore blocked signals, sigchld
               (src/sleep.c: 31)

