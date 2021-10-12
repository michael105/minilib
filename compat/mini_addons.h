/* This file is part of minilib, (c) 2012-2020 Michael Misc Myer.
misc.myer@zoho.com / www.github.com/michael105
Please see the files LICENSE and NOTICE for the exact conditions. 

The lines below are generated by 'make header'. 

*/


#ifndef included_mini_addons_h
#define included_mini_addons_h

#warning compat headers are instable.
#warning Better include minilib.h or use minimake, when possible


#ifndef mini_INCLUDESRC
#ifdef INCLUDESRC
#define mini_INCLUDESRC
#endif
#endif


#define mini_start
#define mini_exit

#ifndef mini_buf
#define mini_buf 1024
#endif



#ifdef X64
#define POINTER unsigned long int
#else
#define POINTER int
#endif

#ifndef uint32_t
#define uint32_t uint
#endif

#ifndef uint8_t
#define uint8_t uchar
#endif

#ifndef size_t
#define size_t long
#endif


#ifndef NULL
#define NULL 0
#endif

//#include "minilib/include/timeval.h"
#include "minilib/include/filemodes.h"

#include "minilib/headers/common/bits/alltypes.h"
#include "minilib/include/globaldefs.h"
#include "minilib/include/minilib_global.h"
#include "minilib/headers/common/dirent.h"
#include "minilib/headers/common/bits/signal.h"
#include "minilib/headers/common/bits/stat.h"
#include "minilib/headers/common/signal.h"
#include "minilib/headers/common/ctype.h"
#include "minilib/include/ctype.h"
#include "minilib/include/syscall.h"
#include "minilib/headers/linux_x64/sys/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/headers/common/sys/types.h"


#include "minilib/headers/common/allheaders.h"
#include "minilib/headers/linux_x64/allheaders.h"

#include "minilib/include/minilib_global.h"
#include "minilib/include/dirent.h"


#include "include/stdarg.h"
#include "include/syscall.h"
#include "include/syscall_stubs.h"

#include "include/exit.h"

#include "minilib/include/globaldefs.h"
#include "include/minilib_global.h"

#include "minilib/include/syscall.h"
#include "minilib/include/syscall_stubs.h"
#include "minilib/headers/common/sys/types.h"

#include "minilib/include/headerguards.h"

// file: minilib/include/config.h


// file: minilib/include/config.h


// file: minilib/include/dirent.h


// file: minilib/include/dirent.h
#ifndef mini_dirbufsize

// file: minilib/include/dirent.h
#ifndef mini_dirbuf_malloc

// file: minilib/include/fexecve.h
static inline int fexecve(int fd, char *const argv[], char *const envp[]);

// file: minilib/include/fexecveat.h
static inline int fexecveat(int fd, char *const argv[], char *const envp[]);

// file: minilib/include/globaldefs.h
#ifndef mini_max_groupmembers

// file: minilib/include/globaldefs.h
typedef int FILE;

// file: minilib/include/minilib_global.h
static void __attribute__((noipa,cold)) optimization_fence(void*p);

// file: minilib/include/poll.h
static inline int poll(struct pollfd *fds, nfds_t cnt, int timeout);

// file: minilib/include/prints.h
#define _mprints(...) dprints(STDOUT_FILENO, __VA_ARGS__)

// file: minilib/include/prints.h
#define prints(...) _mprints(__VA_ARGS__,0)

// file: minilib/include/prints.h
#define eprints(...) dprints(STDERR_FILENO,__VA_ARGS__,0)

// file: minilib/include/prints.h
#define fprints(F,...) dprints(fileno(F),__VA_ARGS__,0)

// file: minilib/include/prints.h
#define printsl(...) _mprints(__VA_ARGS__,"\n",0)

// file: minilib/include/prints.h
#define eprintsl(...) dprints(STDERR_FILENO,__VA_ARGS__,"\n",0)

// file: minilib/include/prints.h
#define print(str) write(STDOUT_FILENO,str,strlen(str))

// file: minilib/include/prints.h
#define eprint(str) write(STDERR_FILENO,str,strlen(str))

// file: minilib/include/prints.h
#define printl() write(STDOUT_FILENO,"\n",1)

// file: minilib/include/prints.h
#define eprintl() write(STDERR_FILENO,"\n",1)

// file: minilib/include/prints.h
#define eputs(msg) ( eprint(msg) + eprintl() )

// file: minilib/include/prints.h
#define writes(str) write(STDOUT_FILENO,str,sizeof(str))

// file: minilib/include/prints.h
#define ewrites(str) write(STDERR_FILENO,str,sizeof(str))

// file: minilib/include/prints.h
#define writesl(str) write(STDOUT_FILENO,str "\n",sizeof(str)+1)

// file: minilib/include/prints.h
#define ewritesl(str) write(STDERR_FILENO,str"\n",sizeof(str)+1)

// file: minilib/include/prints.h
#define fwrites(fd,str) write(fd,str,sizeof(str))

// file: minilib/include/prints.h
#define fwritesl(fd,str) write(fd,str"\n",sizeof(str)+1)

// file: minilib/include/prints.h
#define printfs(fmt,...) fprintfs(stdout, fmt, __VA_ARGS__)

// file: minilib/include/prints.h
#define eprintfs(fmt,...) fprintfs(stderr, fmt, __VA_ARGS__)

// file: minilib/include/prints.h
#define eprintf(fmt,...) fprintf(stderr, fmt, __VA_ARGS__)

// file: minilib/include/pwent.h


// file: minilib/include/ret_errno.h
#ifdef mini_errno

// file: minilib/include/seterrno.h
#ifdef mini_errno

// file: minilib/include/syscall.h
#ifndef __clang__

// file: minilib/include/termio.h


// file: minilib/macros/defgroups.h


// file: minilib/macros/defgroups.h


// file: minilib/macros/defgroups.h
//

// file: minilib/src/network/macros.h
#define ntohs(i) htons(i)

// file: minilib/src/network/ntohl.h
#define ntohl(i) htonl(i)

// file: minilib/src/process/error.h
#define error( status, errnum, fmt ... ) { fprintf(stderr,fmt ); if (errnum) fprints(stderr,":",strerror(errnum)); if ( status ) exit(status); }

// file: minilib/src/process/error.h
#define err( status, fmt ... ) { fprintf(stderr,fmt ); fprints(stderr,":",strerror(errno)); exit(status); }

// file: minilib/src/process/error.h
#define errx( status, fmt ... ) { fprintf(stderr,fmt); exit(status); }

// file: minilib/src/process/error.h
#define warn( fmt ... ) { fprintf(stderr,fmt ); }

// file: minilib/src/process/signames.h
const char* sys_signame[] = ;

// file: minilib/src/conversions/dtodec.c
int dtodec(double d, char* buf, int precision);

// file: minilib/src/conversions/itobin.c
int _itobin(int i, char*buf, int prec, int groups );

// file: minilib/src/conversions/itobin.c
#define itobin(A,B,...) _itobin(A,B,VARARG(SHIFT(__VA_ARGS__),0), VARARG(SHIFT(ARG( __VA_ARGS__ )),32) )

// file: minilib/src/conversions/itodec.c
int ATTR_OPT("Os")uitodec(unsigned int i, char *buf, int prec, char limiter, char pad );

// file: minilib/src/conversions/itodec.c
int itodec(int i, char *buf, int prec, char limiter, char pad );

// file: minilib/src/conversions/itooct.c
int itooct(int i, char *buf);

// file: minilib/src/conversions/ltodec.c
int ltodec(long i, char *buf, int prec, char limiter );

// file: minilib/src/conversions/ultodec.c
int ultodec(unsigned long ui, char *buf, int prec, char limiter );

// file: minilib/src/directories/alphasort.c
int alphasort( const struct dirent** de1, const struct dirent** de2 );

// file: minilib/src/directories/basename.c
char *basename(char *path);

// file: minilib/src/directories/dirfd.c
int dirfd(DIR *d);

// file: minilib/src/directories/dirname.c
char *dirname(char *s);

// file: minilib/src/directories/opendirp.c
static DIR *opendirp(const char *name, DIR *dir);

// file: minilib/src/directories/scandir_bufsize.c


// file: minilib/src/exec/vexec.c
int vexec( const char* path, char* const* argv, char* const* envp );

// file: minilib/src/exec/vexec_q.c
int vexec_q( const char* path, char* const* argv, char* const* envp );

// file: minilib/src/exec/where.c
int where(const char *file,char *buf);

// file: minilib/src/file/cksum.c
unsigned int djb_cksum( const char* p, unsigned int len );

// file: minilib/src/file/cksum.c
unsigned int bsd_cksumblock( unsigned int hash, const char* p, unsigned int len );

// file: minilib/src/file/cksum.c
unsigned int bsd_cksum( const char* p, unsigned int len );

// file: minilib/src/file/creat.c
int volatile creat( const char *s, int mode );

// file: minilib/src/match/match.c
int match(char *text, const char *re, text_match *st_match);

// file: minilib/src/match/match.c
int _match(char *text, const char *re, text_match *st_match);

// file: minilib/src/match/match_ext.c
int match_ext(char *text, const char *re, void(*p_match)(int number, char *pos,int len, void *userdata), int(*p_match_char)(int number, char *match_char, void *userdata), tmatch_ext *st_match, void *userdata);

// file: minilib/src/match/match_ext2.c
int match_ext2(char *text, char *re, void(*p_matched_cb)(int number, char *pos,int len), int(*p_wildcard_cb)(int number, char *match_char),text_match *st_match);

// file: minilib/src/match/match_ext2.c
char* _match_ext2(char *text, char *re, void(*p_matched_cb)(int number, char *pos,int len), int(*p_wildcard_cb)(int number, char *match_char), text_match *st_match);

// file: minilib/src/math/hashes.c
unsigned long djb2_hash(const unsigned char *str);

// file: minilib/src/math/sdbm_hash.c
unsigned long sdbm_hash(const unsigned char *str);

// file: minilib/src/memory/brk.c
static int brk( const void* addr );

// file: minilib/src/memory/freebrk.c
int free_brk();

// file: minilib/src/memory/getbrk.c
static long getbrk();

// file: minilib/src/memory/malloc_brk.c
void* malloc_brk(int size);

// file: minilib/src/memory/map_protected.c
void* map_protected(int len);

// file: minilib/src/memory/map_protected.c
int unmap_protected(void *p, int len);

// file: minilib/src/memory/memfrob.c
void* memfrob(void* s, unsigned int len);

// file: minilib/src/memory/mmap.c
static void* ATTR_OPT("O0") mmap(void* addr,  size_t len,  int prot,  int flags,  int fd,  off_t off);

// file: minilib/src/memory/sbrk.c
static void* sbrk(long incr);

// file: minilib/src/memory/setbrk.c
static int setbrk(long addr);

// file: minilib/src/memory/sys_brk.c
static long sys_brk(unsigned long addr);

// file: minilib/src/network/ether_ntoa.c
char* ether_ntoa( const struct ether_addr *e );

// file: minilib/src/network/htonl.c
static uint32_t htonl(uint32_t i);

// file: minilib/src/network/htons.c
static uint16_t htons(uint16_t i);

// file: minilib/src/network/inet_aton.c
int inet_aton(const char* s, struct in_addr *addr);

// file: minilib/src/network/inet_ntoa.c
char* inet_ntoa( struct in_addr in);

// file: minilib/src/network/recv.c
int recv(int sockfd, void *buf, size_t len, int flags);

// file: minilib/src/output/dprintf.c
int dprintf( int fd, const char *fmt, ... );

// file: minilib/src/output/dprints.c
int dprints(int fd, const char *msg,...);

// file: minilib/src/output/fprintfs.c
int fprintfs( FILE* F, char *fmt, ...);

// file: minilib/src/output/snprintf.c
int snprintf( char *buf, size_t size, const char *fmt, ... );

// file: minilib/src/output/snprintfs.c
int snprintfs( char* buf, int size, char *fmt, ...);

// file: minilib/src/output/vsnprintf.c
int vsnprintf(char *buf, size_t size, const char* fmt, va_list args );

// file: minilib/src/process/clone.c
int clone_t(int flags);

// file: minilib/src/process/die.c
#define die(errnum,msg) {ewritesl(msg);exit_errno(errnum);}

// file: minilib/src/process/die.c
#define dief(errnum,fmt,...) {fprintf(stderr,fmt,__VA_ARGS__);exit_errno(errnum);}

// file: minilib/src/process/die.c
#define dies(errnum,...) {eprintsl(__VA_ARGS__);exit_errno(errnum);}

// file: minilib/src/process/die.c
void _die();

// file: minilib/src/process/die.c
#define die_if( when, errnum, msg ) if( when ) die( errnum, msg )

// file: minilib/src/process/die.c
#define dief_if( when, errnum, fmt,... ) if( when ) dief( errnum, fmt, __VA_ARGS__ )

// file: minilib/src/process/die.c
#define dies_if( when, errnum, ... ) if( when ) dies( errnum, __VA_ARGS__ )

// file: minilib/src/process/errno_str.c
static char *errno_str(int err);

// file: minilib/src/process/exit_errno.c
void exit_errno( int errnum );

// file: minilib/src/process/killpg.c
static int killpg( int pid, int signal );

// file: minilib/src/sort/swap.c
static inline void swap(void* a, void* b,int size);

// file: minilib/src/streams/fgetsn.c
int fgetsn(char *buf, int size, FILE* F);

// file: minilib/src/streams/fgetsp.c
char* fgetsp(char *buf, int size, FILE* F);

// file: minilib/src/streams/fgetud.c
unsigned int fgetud(FILE* F);

// file: minilib/src/streams/fgetul.c
unsigned long int fgetul(FILE* F);

// file: minilib/src/string/stpcpy.c
char *stpcpy(char *dest, const char *src);

// file: minilib/src/string/stplcpy.c
char *stplcpy(char *dest, const char *src, int size);

// file: minilib/src/string/stpncpy.c
char *stpncpy(char *dest, const char *src, int size);

// file: minilib/src/string/strchrnul.c
char *strchrnul(const char *s, int c);

// file: minilib/src/string/strlcpy.c
char *strlcpy(char *dest, const char *src, int n);

// file: minilib/src/string/strtoimax.c
int strtoimax(const char *c, const char **endp, int base);

// file: minilib/src/string/strtok_r.c
char* strtok_r(char *s, const char *delim, char **last);

// file: minilib/src/string/strtoll.c
long long int strtoll(const char *c, const char **endp, int base);

// file: minilib/src/system/putenv.c
int putenv( char *string );

// file: minilib/src/system/setenv.c
int setenv( const char *name, const char *value, int overwrite );

// file: minilib/src/system/unsetenv.c
int unsetenv( char *name);

// file: minilib/src/termios/cfmakeraw.c
void cfmakeraw(struct termios *tp);

// file: minilib/src/termios/pty.c
int posix_openpt(int flags);

// file: minilib/src/termios/pty.c
int unlockpt(int fd);

// file: minilib/src/termios/pty.c
int ptsname_r(int fd, char *buf, size_t len);

// file: minilib/src/termios/pty.c
char *ptsname(int fd);

// file: minilib/src/termios/pty.c
int grantpt(int fd);

// file: minilib/src/termios/tcgetattr.c
int tcgetattr(int fd, struct termios *io);

// file: minilib/src/termios/tcsetattr.c
int tcsetattr(int fd, int opt, const struct termios *io);

// file: minilib/src/termios/term_width.c
int term_width();

// file: minilib/src/userdb/endgrent.c
void endgrent();

// file: minilib/src/userdb/endpwent.c
void endpwent();

// file: minilib/src/userdb/getgrent.c
struct group* getgrent();

// file: minilib/src/userdb/getgrgid.c
struct group *getgrgid(gid_t gid);

// file: minilib/src/userdb/getgrnam.c
struct group *getgrnam(const char* name);

// file: minilib/src/userdb/getgrouplist.c
int getgrouplist(const char* user, gid_t group, gid_t *groups, int *ngroups);

// file: minilib/src/userdb/getpwent.c
struct passwd* getpwent();

// file: minilib/src/userdb/getpwnam.c
struct passwd *getpwnam(const char* name);

// file: minilib/src/userdb/getpwuid.c
struct passwd *getpwuid(uid_t uid);

// file: minilib/src/userdb/getusergroups.c
int getusergroups(const char* user, int maxgroups, int *list);

// file: minilib/src/userdb/initgroups.c
int initgroups(const char* user, gid_t group);

// file: minilib/src/userdb/setgrent.c
void setgrent();

// file: minilib/src/userdb/setpwent.c
void setpwent();

// file: minilib/src/userdb/userdb_open.c
int userdb_open(userdb *udb, const char* file);



#include "include/minilib_global.h"


#ifdef mini_INCLUDESRC

#include "minilib/src/process/killpg.c"
#include "minilib/src/userdb/getgrgid.c"
#include "minilib/src/userdb/getgrouplist.c"
#include "minilib/src/userdb/getpwent.c"
#include "minilib/macros/defgroups.h"
#include "minilib/src/network/ntohl.h"
#include "minilib/src/output/fprintfs.c"
#include "minilib/src/file/cksum.c"
#include "minilib/src/system/unsetenv.c"
#include "minilib/src/userdb/endgrent.c"
#include "minilib/include/minilib_global.h"
#include "minilib/src/network/macros.h"
#include "minilib/include/prints.h"
#include "minilib/include/pwent.h"
#include "minilib/src/streams/fgetsp.c"
#include "minilib/src/exec/vexec_q.c"
#include "minilib/src/userdb/getgrent.c"
#include "minilib/src/conversions/itooct.c"
#include "minilib/src/directories/alphasort.c"
#include "minilib/src/streams/fgetud.c"
#include "minilib/src/network/inet_ntoa.c"
#include "minilib/src/string/strlcpy.c"
#include "minilib/src/memory/sys_brk.c"
#include "minilib/src/output/dprintf.c"
#include "minilib/src/userdb/setpwent.c"
#include "minilib/src/network/ether_ntoa.c"
#include "minilib/include/syscall.h"
#include "minilib/include/dirent.h"
#include "minilib/src/network/inet_aton.c"
#include "minilib/src/memory/map_protected.c"
#include "minilib/include/ret_errno.h"
#include "minilib/include/poll.h"
#include "minilib/src/system/putenv.c"
#include "minilib/src/directories/dirfd.c"
#include "minilib/src/sort/swap.c"
#include "minilib/src/userdb/setgrent.c"
#include "minilib/src/math/hashes.c"
#include "minilib/src/memory/sbrk.c"
#include "minilib/src/system/setenv.c"
#include "minilib/src/memory/brk.c"
#include "minilib/src/network/recv.c"
#include "minilib/src/memory/malloc_brk.c"
#include "minilib/include/fexecve.h"
#include "minilib/src/termios/pty.c"
#include "minilib/src/file/creat.c"
#include "minilib/src/streams/fgetul.c"
#include "minilib/src/directories/opendirp.c"
#include "minilib/src/conversions/itobin.c"
#include "minilib/src/userdb/initgroups.c"
#include "minilib/src/memory/setbrk.c"
#include "minilib/src/streams/fgetsn.c"
#include "minilib/src/userdb/getpwuid.c"
#include "minilib/src/network/htonl.c"
#include "minilib/src/memory/freebrk.c"
#include "minilib/src/match/match_ext2.c"
#include "minilib/src/userdb/userdb_open.c"
#include "minilib/src/memory/getbrk.c"
#include "minilib/src/conversions/dtodec.c"
#include "minilib/include/config.h"
#include "minilib/src/directories/basename.c"
#include "minilib/src/process/clone.c"
#include "minilib/src/string/strtoimax.c"
#include "minilib/src/match/match.c"
#include "minilib/include/fexecveat.h"
#include "minilib/src/userdb/endpwent.c"
#include "minilib/src/string/strtok_r.c"
#include "minilib/src/output/vsnprintf.c"
#include "minilib/src/termios/tcsetattr.c"
#include "minilib/src/exec/vexec.c"
#include "minilib/src/termios/term_width.c"
#include "minilib/src/conversions/ultodec.c"
#include "minilib/src/output/dprints.c"
#include "minilib/src/process/die.c"
#include "minilib/src/directories/dirname.c"
#include "minilib/src/termios/cfmakeraw.c"
#include "minilib/include/termio.h"
#include "minilib/src/process/error.h"
#include "minilib/src/string/strchrnul.c"
#include "minilib/src/conversions/itodec.c"
#include "minilib/src/output/snprintf.c"
#include "minilib/src/userdb/getusergroups.c"
#include "minilib/src/string/stplcpy.c"
#include "minilib/include/seterrno.h"
#include "minilib/src/userdb/getpwnam.c"
#include "minilib/src/process/signames.h"
#include "minilib/src/termios/tcgetattr.c"
#include "minilib/src/string/stpncpy.c"
#include "minilib/src/output/snprintfs.c"
#include "minilib/src/process/errno_str.c"
#include "minilib/src/memory/mmap.c"
#include "minilib/src/match/match_ext.c"
#include "minilib/src/exec/where.c"
#include "minilib/src/conversions/ltodec.c"
#include "minilib/src/process/exit_errno.c"
#include "minilib/src/network/htons.c"
#include "minilib/src/memory/memfrob.c"
#include "minilib/src/math/sdbm_hash.c"
#include "minilib/src/string/strtoll.c"
#include "minilib/include/globaldefs.h"
#include "minilib/src/userdb/getgrnam.c"
#include "minilib/src/directories/scandir_bufsize.c"
#include "minilib/src/string/stpcpy.c"

// Need global included. Doesn't matter by which file.
#include "src/minilib_global.c"

// Need start.c included. Doesn't matter by which file.
#include "asm/start.c"

#endif

#endif
