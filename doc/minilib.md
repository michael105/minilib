

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

creat          inline int volatile __attribute__((always_inline)) creat( const char *s, int mode );

               (src/open.c: 29)



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

               (src/prints.c: 66)

_strcmp        int _strcmp(const char*c1,const char*c2,int len);

               (src/mstrcmp.c: 11)

basename       char *basename(char *path);

               (src/basename.c: 29)

def            #define SETOPT_short( opts, option ) (;

               Set a option flag(s) (bit(s))  manually.
             		param options: e.g. just a, or ( a+h+l) to check for several flags at once
               (macros/getoptm.h: 52)

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

itobin         #define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )

               (src/itobin.c: 41)

itodec         int itodec(int i, char *buf, int prec, char limiter );

               (src/itodec.c: 121)

memfrob        void* memfrob(void* s, unsigned int len);

               (src/memfrob.c: 3)

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

snprintf       int snprintf( char *buf, size_t size, const char *fmt, ... );

               (src/sprintf.c: 219)

uitodec        int uitodec(unsigned int i, char *buf, int prec, char limiter );

               (src/itodec.c: 8)

vsnprintf      int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );

               (src/sprintf.c: 36)

writes         #define writes(str) write(STDOUT_FILENO,str,sizeof(str))

               write the constant str to stdout. Computes length with sizeof(str) at compile time.
               (include/prints.h: 34)



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



==========
unistd.h
==========

open           int volatile open( const char *s, int flags, ... );

               (src/open.c: 12)

select         static inline int volatile __attribute__((always_inline)) select(int fd, volatile fd_set* readfd, volatile fd_set *writefd, volatile fd_set *exceptfd, volatile struct timeval *wait);

               (include/select.h: 10)

tcgetattr      static inline int __attribute__((always_inline)) tcgetattr(int fd, struct termios *io);

               (include/tcgetattr.h: 17)

tcsetattr      static inline int __attribute__((always_inline)) tcsetattr(int fd, int opt, const struct termios *io);

               (include/tcsetattr.h: 18)
