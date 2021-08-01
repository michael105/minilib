










typedef long time_t;
typedef long suseconds_t;
typedef unsigned useconds_t;
struct timeval { time_t tv_sec; suseconds_t tv_usec; };







struct itimerval {
  struct timeval it_interval;
  struct timeval it_value;
};
typedef unsigned char uchar;






typedef int wchar_t;

typedef long double double_t;

typedef float float_t;

typedef struct { long long __ll; long double __ld; } max_align_t;


typedef struct { union { int __i[14]; volatile int __vi[14]; unsigned long __s[7]; } __u; } pthread_attr_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } pthread_mutex_t;

typedef struct { union { int __i[10]; volatile int __vi[10]; volatile void *volatile __p[5]; } __u; } mtx_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } pthread_cond_t;

typedef struct { union { int __i[12]; volatile int __vi[12]; void *__p[6]; } __u; } cnd_t;

typedef struct { union { int __i[14]; volatile int __vi[14]; void *__p[7]; } __u; } pthread_rwlock_t;

typedef struct { union { int __i[8]; volatile int __vi[8]; void *__p[4]; } __u; } pthread_barrier_t;




typedef unsigned long uintptr_t;

typedef long ptrdiff_t;

typedef long ssize_t;

typedef long intptr_t;

typedef long regoff_t;

typedef long register_t;

typedef signed char int8_t;

typedef signed short int16_t;

typedef signed int int32_t;

typedef signed long int64_t;

typedef signed long intmax_t;

typedef unsigned char uint8_t;

typedef unsigned short uint16_t;

typedef unsigned int uint32_t;

typedef unsigned long uint64_t;

typedef unsigned long u_int64_t;

typedef unsigned long uintmax_t;

typedef unsigned mode_t;

typedef unsigned long nlink_t;

typedef long off_t;

typedef unsigned long ino_t;

typedef unsigned long dev_t;

typedef long blksize_t;

typedef long blkcnt_t;

typedef unsigned long fsblkcnt_t;

typedef unsigned long fsfilcnt_t;

typedef unsigned wint_t;

typedef unsigned long wctype_t;

typedef void * timer_t;

typedef int clockid_t;

typedef long clock_t;



struct timespec { time_t tv_sec; long tv_nsec; };

typedef int pid_t;

typedef unsigned id_t;

typedef unsigned uid_t;

typedef unsigned gid_t;

typedef int key_t;





typedef struct __mbstate_t { unsigned __opaque1, __opaque2; } mbstate_t;

typedef struct __locale_struct * locale_t;




struct iovec { void *iov_base; long iov_len; };

typedef unsigned socklen_t;

typedef unsigned short sa_family_t;

typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned u_int32_t;
typedef char *caddr_t;
typedef unsigned char u_char;
typedef unsigned short u_short, ushort;
typedef unsigned u_int, uint;
typedef unsigned long u_long, ulong;
typedef long long quad_t;
typedef unsigned long long u_quad_t;
struct stat {
 dev_t st_dev;
 ino_t st_ino;
 nlink_t st_nlink;

 mode_t st_mode;
 uid_t st_uid;
 gid_t st_gid;
 unsigned int __pad0;
 dev_t st_rdev;
 off_t st_size;
 blksize_t st_blksize;
 blkcnt_t st_blocks;

 struct timespec st_atim;
 struct timespec st_mtim;
 struct timespec st_ctim;
 long __unused[3];
};














typedef unsigned char cc_t;
typedef unsigned int speed_t;
typedef unsigned int tcflag_t;




struct termios {
 tcflag_t c_iflag;
 tcflag_t c_oflag;
 tcflag_t c_cflag;
 tcflag_t c_lflag;
 cc_t c_line;
 cc_t c_cc[32];
 speed_t __c_ispeed;
 speed_t __c_ospeed;
};



struct termio
{
  unsigned short int c_iflag;
  unsigned short int c_oflag;
  unsigned short int c_cflag;
  unsigned short int c_lflag;
  unsigned char c_line;
  unsigned char c_cc[8];
};

speed_t cfgetospeed (const struct termios *);
speed_t cfgetispeed (const struct termios *);
int cfsetospeed (struct termios *, speed_t);
int cfsetispeed (struct termios *, speed_t);

static inline int tcgetattr (int, struct termios *);
static inline int tcsetattr (int, int, const struct termios *);

int tcsendbreak (int, int);
int tcdrain (int);
int tcflush (int, int);
int tcflow (int, int);

pid_t tcgetsid (int);
struct winsize {
 unsigned short ws_row;
 unsigned short ws_col;
 unsigned short ws_xpixel;
 unsigned short ws_ypixel;
};











int isalnum_l(int, locale_t);
int isalpha_l(int, locale_t);
int isblank_l(int, locale_t);
int iscntrl_l(int, locale_t);
int isdigit_l(int, locale_t);
int isgraph_l(int, locale_t);
int islower_l(int, locale_t);
int isprint_l(int, locale_t);
int ispunct_l(int, locale_t);
int isspace_l(int, locale_t);
int isupper_l(int, locale_t);
int isxdigit_l(int, locale_t);
int tolower_l(int, locale_t);
int toupper_l(int, locale_t);




typedef int8_t int_fast8_t;
typedef int64_t int_fast64_t;

typedef int8_t int_least8_t;
typedef int16_t int_least16_t;
typedef int32_t int_least32_t;
typedef int64_t int_least64_t;

typedef uint8_t uint_fast8_t;
typedef uint64_t uint_fast64_t;

typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;
typedef uint32_t uint_least32_t;
typedef uint64_t uint_least64_t;

typedef uint16_t Elf32_Half;
typedef uint16_t Elf64_Half;

typedef uint32_t Elf32_Word;
typedef int32_t Elf32_Sword;
typedef uint32_t Elf64_Word;
typedef int32_t Elf64_Sword;

typedef uint64_t Elf32_Xword;
typedef int64_t Elf32_Sxword;
typedef uint64_t Elf64_Xword;
typedef int64_t Elf64_Sxword;

typedef uint32_t Elf32_Addr;
typedef uint64_t Elf64_Addr;

typedef uint32_t Elf32_Off;
typedef uint64_t Elf64_Off;

typedef uint16_t Elf32_Section;
typedef uint16_t Elf64_Section;

typedef Elf32_Half Elf32_Versym;
typedef Elf64_Half Elf64_Versym;



typedef struct {
  unsigned char e_ident[(16)];
  Elf32_Half e_type;
  Elf32_Half e_machine;
  Elf32_Word e_version;
  Elf32_Addr e_entry;
  Elf32_Off e_phoff;
  Elf32_Off e_shoff;
  Elf32_Word e_flags;
  Elf32_Half e_ehsize;
  Elf32_Half e_phentsize;
  Elf32_Half e_phnum;
  Elf32_Half e_shentsize;
  Elf32_Half e_shnum;
  Elf32_Half e_shstrndx;
} Elf32_Ehdr;

typedef struct {
  unsigned char e_ident[(16)];
  Elf64_Half e_type;
  Elf64_Half e_machine;
  Elf64_Word e_version;
  Elf64_Addr e_entry;
  Elf64_Off e_phoff;
  Elf64_Off e_shoff;
  Elf64_Word e_flags;
  Elf64_Half e_ehsize;
  Elf64_Half e_phentsize;
  Elf64_Half e_phnum;
  Elf64_Half e_shentsize;
  Elf64_Half e_shnum;
  Elf64_Half e_shstrndx;
} Elf64_Ehdr;
typedef struct {
  Elf32_Word sh_name;
  Elf32_Word sh_type;
  Elf32_Word sh_flags;
  Elf32_Addr sh_addr;
  Elf32_Off sh_offset;
  Elf32_Word sh_size;
  Elf32_Word sh_link;
  Elf32_Word sh_info;
  Elf32_Word sh_addralign;
  Elf32_Word sh_entsize;
} Elf32_Shdr;

typedef struct {
  Elf64_Word sh_name;
  Elf64_Word sh_type;
  Elf64_Xword sh_flags;
  Elf64_Addr sh_addr;
  Elf64_Off sh_offset;
  Elf64_Xword sh_size;
  Elf64_Word sh_link;
  Elf64_Word sh_info;
  Elf64_Xword sh_addralign;
  Elf64_Xword sh_entsize;
} Elf64_Shdr;
typedef struct {
  Elf32_Word ch_type;
  Elf32_Word ch_size;
  Elf32_Word ch_addralign;
} Elf32_Chdr;

typedef struct {
  Elf64_Word ch_type;
  Elf64_Word ch_reserved;
  Elf64_Xword ch_size;
  Elf64_Xword ch_addralign;
} Elf64_Chdr;
typedef struct {
  Elf32_Word st_name;
  Elf32_Addr st_value;
  Elf32_Word st_size;
  unsigned char st_info;
  unsigned char st_other;
  Elf32_Section st_shndx;
} Elf32_Sym;

typedef struct {
  Elf64_Word st_name;
  unsigned char st_info;
  unsigned char st_other;
  Elf64_Section st_shndx;
  Elf64_Addr st_value;
  Elf64_Xword st_size;
} Elf64_Sym;

typedef struct {
  Elf32_Half si_boundto;
  Elf32_Half si_flags;
} Elf32_Syminfo;

typedef struct {
  Elf64_Half si_boundto;
  Elf64_Half si_flags;
} Elf64_Syminfo;
typedef struct {
  Elf32_Addr r_offset;
  Elf32_Word r_info;
} Elf32_Rel;

typedef struct {
  Elf64_Addr r_offset;
  Elf64_Xword r_info;
} Elf64_Rel;



typedef struct {
  Elf32_Addr r_offset;
  Elf32_Word r_info;
  Elf32_Sword r_addend;
} Elf32_Rela;

typedef struct {
  Elf64_Addr r_offset;
  Elf64_Xword r_info;
  Elf64_Sxword r_addend;
} Elf64_Rela;
typedef struct {
  Elf32_Word p_type;
  Elf32_Off p_offset;
  Elf32_Addr p_vaddr;
  Elf32_Addr p_paddr;
  Elf32_Word p_filesz;
  Elf32_Word p_memsz;
  Elf32_Word p_flags;
  Elf32_Word p_align;
} Elf32_Phdr;

typedef struct {
  Elf64_Word p_type;
  Elf64_Word p_flags;
  Elf64_Off p_offset;
  Elf64_Addr p_vaddr;
  Elf64_Addr p_paddr;
  Elf64_Xword p_filesz;
  Elf64_Xword p_memsz;
  Elf64_Xword p_align;
} Elf64_Phdr;
typedef struct {
  Elf32_Sword d_tag;
  union {
      Elf32_Word d_val;
      Elf32_Addr d_ptr;
  } d_un;
} Elf32_Dyn;

typedef struct {
  Elf64_Sxword d_tag;
  union {
      Elf64_Xword d_val;
      Elf64_Addr d_ptr;
  } d_un;
} Elf64_Dyn;
typedef struct {
  Elf32_Half vd_version;
  Elf32_Half vd_flags;
  Elf32_Half vd_ndx;
  Elf32_Half vd_cnt;
  Elf32_Word vd_hash;
  Elf32_Word vd_aux;
  Elf32_Word vd_next;
} Elf32_Verdef;

typedef struct {
  Elf64_Half vd_version;
  Elf64_Half vd_flags;
  Elf64_Half vd_ndx;
  Elf64_Half vd_cnt;
  Elf64_Word vd_hash;
  Elf64_Word vd_aux;
  Elf64_Word vd_next;
} Elf64_Verdef;
typedef struct {
  Elf32_Word vda_name;
  Elf32_Word vda_next;
} Elf32_Verdaux;

typedef struct {
  Elf64_Word vda_name;
  Elf64_Word vda_next;
} Elf64_Verdaux;




typedef struct {
  Elf32_Half vn_version;
  Elf32_Half vn_cnt;
  Elf32_Word vn_file;
  Elf32_Word vn_aux;
  Elf32_Word vn_next;
} Elf32_Verneed;

typedef struct {
  Elf64_Half vn_version;
  Elf64_Half vn_cnt;
  Elf64_Word vn_file;
  Elf64_Word vn_aux;
  Elf64_Word vn_next;
} Elf64_Verneed;
typedef struct {
  Elf32_Word vna_hash;
  Elf32_Half vna_flags;
  Elf32_Half vna_other;
  Elf32_Word vna_name;
  Elf32_Word vna_next;
} Elf32_Vernaux;

typedef struct {
  Elf64_Word vna_hash;
  Elf64_Half vna_flags;
  Elf64_Half vna_other;
  Elf64_Word vna_name;
  Elf64_Word vna_next;
} Elf64_Vernaux;







typedef struct {
  uint32_t a_type;
  union {
      uint32_t a_val;
  } a_un;
} Elf32_auxv_t;

typedef struct {
  uint64_t a_type;
  union {
      uint64_t a_val;
  } a_un;
} Elf64_auxv_t;
typedef struct {
  Elf32_Word n_namesz;
  Elf32_Word n_descsz;
  Elf32_Word n_type;
} Elf32_Nhdr;

typedef struct {
  Elf64_Word n_namesz;
  Elf64_Word n_descsz;
  Elf64_Word n_type;
} Elf64_Nhdr;
typedef struct {
  Elf32_Xword m_value;
  Elf32_Word m_info;
  Elf32_Word m_poffset;
  Elf32_Half m_repeat;
  Elf32_Half m_stride;
} Elf32_Move;

typedef struct {
  Elf64_Xword m_value;
  Elf64_Xword m_info;
  Elf64_Xword m_poffset;
  Elf64_Half m_repeat;
  Elf64_Half m_stride;
} Elf64_Move;
typedef union {
  struct {
      Elf32_Word gt_current_g_value;
      Elf32_Word gt_unused;
  } gt_header;
  struct {
      Elf32_Word gt_g_value;
      Elf32_Word gt_bytes;
  } gt_entry;
} Elf32_gptab;



typedef struct {
  Elf32_Word ri_gprmask;
  Elf32_Word ri_cprmask[4];
  Elf32_Sword ri_gp_value;
} Elf32_RegInfo;



typedef struct {
  unsigned char kind;

  unsigned char size;
  Elf32_Section section;

  Elf32_Word info;
} Elf_Options;
typedef struct {
  Elf32_Word hwp_flags1;
  Elf32_Word hwp_flags2;
} Elf_Options_Hw;




typedef struct {
  Elf32_Word l_name;
  Elf32_Word l_time_stamp;
  Elf32_Word l_checksum;
  Elf32_Word l_version;
  Elf32_Word l_flags;
} Elf32_Lib;

typedef struct {
  Elf64_Word l_name;
  Elf64_Word l_time_stamp;
  Elf64_Word l_checksum;
  Elf64_Word l_version;
  Elf64_Word l_flags;
} Elf64_Lib;
typedef Elf32_Addr Elf32_Conflict;







typedef long __band_t;

typedef union sigval {
  int sival_int;
  void *sival_ptr;
} sigval_t;


typedef struct siginfo {
  int32_t si_signo;
  int32_t si_errno;
  int32_t si_code;
  union {
    char __pad[128 - 2*sizeof(int) - sizeof(long)];

    struct {
      pid_t _pid;
      uid_t _uid;
    } _kill;

    struct {
      uint32_t _timer1;
      uint32_t _timer2;
    } _timer;

    struct {
      pid_t _pid;
      uid_t _uid;
      sigval_t _sigval;
    } _rt;

    struct {
      pid_t _pid;
      uid_t _uid;
      int32_t _status;
      clock_t _utime;
      clock_t _stime;
    } _sigchld;

    struct {
      void *_addr;
    } _sigfault;

    struct {
      __band_t _band;
      int32_t _fd;
    } _sigpoll;
  } _sifields;
} siginfo_t;


typedef struct __sigset_t { unsigned long sig; } sigset_t;


struct sigaction {
  void (*sa_handler)(int);
  unsigned long sa_flags;
  void (*restorer)(void);
  sigset_t sa_mask;
};








struct oldold_utsname {
        char sysname[9];
        char nodename[9];
        char release[9];
        char version[9];
        char machine[9];
};



struct old_utsname {
        char sysname[65];
        char nodename[65];
        char release[65];
        char version[65];
        char machine[65];
};

struct new_utsname {
        char sysname[64 + 1];
        char nodename[64 + 1];
        char release[64 + 1];
        char version[64 + 1];
        char machine[64 + 1];
        char domainname[64 + 1];
};
struct prctl_mm_map {
 uint64_t start_code;
 uint64_t end_code;
 uint64_t start_data;
 uint64_t end_data;
 uint64_t start_brk;
 uint64_t brk;
 uint64_t start_stack;
 uint64_t arg_start;
 uint64_t arg_end;
 uint64_t env_start;
 uint64_t env_end;
 uint64_t *auxv;
 uint32_t auxv_size;
 uint32_t exe_fd;
};

struct inotify_event {
 int wd;
 uint32_t mask, cookie, len;
 char name[];
};



typedef unsigned long __u64;
typedef unsigned int __u32;
typedef signed long __s64;
typedef signed int __s32;

typedef unsigned short __u16;
typedef signed short __s16;
enum fsconfig_command {
 FSCONFIG_SET_FLAG = 0,
 FSCONFIG_SET_STRING = 1,
 FSCONFIG_SET_BINARY = 2,
 FSCONFIG_SET_PATH = 3,
 FSCONFIG_SET_PATH_EMPTY = 4,
 FSCONFIG_SET_FD = 5,
 FSCONFIG_CMD_CREATE = 6,
 FSCONFIG_CMD_RECONFIGURE = 7,
};
struct seccomp_data {
 int nr;
 __u32 arch;
 __u64 instruction_pointer;
 __u64 args[6];
};

struct seccomp_notif_sizes {
 __u16 seccomp_notif;
 __u16 seccomp_notif_resp;
 __u16 seccomp_data;
};

struct seccomp_notif {
 __u64 id;
 __u32 pid;
 __u32 flags;
 struct seccomp_data data;
};

struct seccomp_notif_resp {
 __u64 id;
 __s64 val;
 __s32 error;
 __u32 flags;
};

typedef struct _text_match { char *pos; int len; } text_match;
struct utimbuf{
  time_t actime;
  time_t modtime;
};
typedef int FILE;
typedef union { FILE *F; int i, fd;} mfl_union;

typedef struct { int quot; int rem; } div_t;
typedef struct { long int quot; long int rem; } ldiv_t;

typedef void (*sighandler_t)(int);

typedef void (functionp)(void);
  typedef unsigned long fd_mask;

  typedef struct
  {
      unsigned long fds_bits[1024 / 8 / sizeof(long)];
  } fd_set;




typedef struct passwd {
 char *pw_name;
 char *pw_passwd;
 uid_t pw_uid;
 gid_t pw_gid;
 char *pw_gecos;
 char *pw_dir;
 char *pw_shell;
} _passwd;


typedef struct group {
 char *gr_name;
 char *gr_passwd;
 gid_t gr_gid;
 char *gr_mem[64];

}_group;
typedef struct {
 char* file;
 char* p;
 char** p2;
 int size;
} userdb;

typedef struct {
  int errno;
  int sysret;
  int srand;
  int pstream;
  int mbufsize;
  int align[1];
  char **environ;
  unsigned long brk;
  unsigned long malloc_start;



  void *appdata;





  int stream[16];
  union {
    int ibuf[(0>>2)];
    char mbuf[0];
  };
} minilib_globals;
static void __attribute__((noipa,cold)) optimization_fence(void*p){}
extern minilib_globals*__restrict__ mlgl;
extern minilib_globals __mlgl;


extern int errno;
struct __dirstream{
 off_t tell;
 int fd;
 int buf_pos;
 int buf_end;

 int align;



 char buf[0];
};

typedef struct __dirstream DIR;


struct dirent {
 ino_t d_ino;
 off_t d_off;
 unsigned short d_reclen;


 char d_name[];
};
extern int errno;
static void __attribute__((noipa,cold,naked)) opt_fence(void*p,...){}
extern int errno;



struct stat;
struct timeval;
struct timezone;





typedef unsigned long u64;

typedef unsigned int u32;


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








































































;






















































inline int volatile __attribute__((always_inline)) getpgrp( ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((111 | 0 ) | 0 ) ) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


int volatile splice( int a1, loff_t *a2, int a3, loff_t *a4, long a5, unsigned int a6 ){ int sysret; register long int r10 asm("r10")= a4; register long int r8 asm("r8")= a5 ; register long int r9 asm("r9")=a6; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((275 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) , "r" (r8) : "memory","rcx", "r11" ); asm( "jmp " "OPTFENCE_""0" ); opt_fence(r10,r8,r9); asm( "OPTFENCE_" "0" ":" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) mkdir( const char *a1, int a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((83 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) write( int a1, const void *a2, int a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((1 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) nanosleep( struct timespec *a1, struct timespec *a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((35 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) vfork( ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((58 | 0 ) | 0 ) ) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) rt_sigreturn( unsigned long a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((15 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


int volatile prctl( int a1, unsigned long a2, unsigned long a3, unsigned long a4, unsigned long a5 ){ int sysret; register long int r10 asm("r10")= a4; register long int r8 asm("r8")= a5 ; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((157 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) , "r" (r8) : "memory","rcx", "r11" ); asm( "jmp " "OPTFENCE_""1" ); opt_fence(r10,r8); asm( "OPTFENCE_" "1" ":" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


int volatile reboot( int a1, int a2, unsigned int a3, void *a4 ){ int sysret; register long int r10 asm("r10")= a4; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((169 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) , "r" (r10) : "memory","rcx", "r11" ); asm( "jmp " "OPTFENCE_""2" ); opt_fence(r10); asm( "OPTFENCE_" "2" ":" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) symlink( const char *a1, const char *a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((88 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


int volatile mount( char *a1, char *a2, char *a3, unsigned long a4, void *a5 ){ int sysret; register long int r10 asm("r10")= a4; register long int r8 asm("r8")= a5 ; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((165 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) , "r" (r8) : "memory","rcx", "r11" ); asm( "jmp " "OPTFENCE_""3" ); opt_fence(r10,r8); asm( "OPTFENCE_" "3" ":" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) fchmod( unsigned int a1, mode_t a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((91 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) uname( struct old_utsname *a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((63 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) pivot_root( const char *a1, const char *a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((155 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) inotify_add_watch( int a1, const char *a2, u32 a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((254 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) setgroups( int a1, gid_t *a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((116 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) fchown( unsigned int a1, uid_t a2, gid_t a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((93 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) memfd_create( const char *a1, unsigned int a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((319 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) inotify_init1( int a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((294 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) umask( int a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((95 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) getdents( unsigned int a1, struct dirent *a2, unsigned int a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((78 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) inotify_rm_watch( int a1, __s32 a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((255 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) munmap( void* a1, long a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((11 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) fstat( int a1, struct stat* a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((5 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


int volatile rt_sigaction( int a1, const struct sigaction *a2, struct sigaction *a3, long a4 ){ int sysret; register long int r10 asm("r10")= a4; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((13 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) , "r" (r10) : "memory","rcx", "r11" ); asm( "jmp " "OPTFENCE_""4" ); opt_fence(r10); asm( "OPTFENCE_" "4" ":" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) ftruncate( unsigned int a1, unsigned int a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((77 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) rename( const char* a1, const char* a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((82 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) read( int a1, void *a2, int a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((0 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) fcntl( unsigned int a1, unsigned int a2, unsigned long a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((72 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) kill( pid_t a1, int a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((62 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) rmdir( const char *a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((84 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) setitimer( int a1, struct itimerval *a2, struct itimerval *a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((38 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) chown( const char *a1, uid_t a2, gid_t a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((92 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) mprotect( unsigned long int *a1, unsigned long int a2, int a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( (10 | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0 ){ errno = -sysret; return(-1);} return(*a1); }


inline int volatile __attribute__((always_inline)) chdir( const char* a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((80 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) inotify_init( ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((253 | 0 ) | 0 ) ) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) sync( ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((162 | 0 ) | 0 ) ) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) setsid( ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((112 | 0 ) | 0 ) ) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) getitimer( int a1, struct itimerval *a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((36 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) pipe( int *a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((22 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) execve( const char *a1, char* const* a2, char* const* a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((59 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) lseek( unsigned int a1, int a2, int a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((8 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) close( int a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((3 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) unlink( const char* a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((87 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) getppid( ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((110 | 0 ) | 0 ) ) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) readahead( int a1, loff_t a2, long a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((187 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) fsync( int a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((74 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) setpgid( pid_t a1, pid_t a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((109 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) umount2( const char *a1, int a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((166 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


int volatile wait4( pid_t a1, int *a2, int a3, struct rusage *a4 ){ int sysret; register long int r10 asm("r10")= a4; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((61 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) , "r" (r10) : "memory","rcx", "r11" ); asm( "jmp " "OPTFENCE_""5" ); opt_fence(r10); asm( "OPTFENCE_" "5" ":" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) setuid( uid_t a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((105 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) rt_sigsuspend( const sigset_t *a1, long a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((130 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); } ;


inline int volatile __attribute__((always_inline)) stat( const char* a1, struct stat* a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((4 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) chroot( const char *a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((161 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) dup3( int a1, int a2, int a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((292 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) fork( ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((57 | 0 ) | 0 ) ) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) getcwd( char *a1, unsigned long a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((79 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) getuid( ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((102 | 0 ) | 0 ) ) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) getpid( ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((39 | 0 ) | 0 ) ) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) utime( const char *a1, struct utimbuf *a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((132 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) time( unsigned int *a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((201 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


int volatile sendfile( int a1, int a2, off_t *a3, long a4 ){ int sysret; register long int r10 asm("r10")= a4; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((40 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) , "r" (r10) : "memory","rcx", "r11" ); asm( "jmp " "OPTFENCE_""6" ); opt_fence(r10); asm( "OPTFENCE_" "6" ":" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) mknod( const char *a1, umode_t a2, unsigned a3 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((133 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) setgid( gid_t a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((106 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) link( const char *a1, const char *a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((86 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


int volatile rt_sigprocmask( int a1, sigset_t *a2, sigset_t *a3, long a4 ){ int sysret; register long int r10 asm("r10")= a4; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((14 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) , "r" (r10) : "memory","rcx", "r11" ); asm( "jmp " "OPTFENCE_""7" ); opt_fence(r10); asm( "OPTFENCE_" "7" ":" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) dup( int a1 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((32 | 0 ) | 0 ) ) , "D" (a1) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) chmod( const char *a1, mode_t a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((90 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


int volatile clone( int a1, unsigned long a2, void *a3, void *a4 ){ int sysret; register long int r10 asm("r10")= a4; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((56 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) , "r" (r10) : "memory","rcx", "r11" ); asm( "jmp " "OPTFENCE_""8" ); opt_fence(r10); asm( "OPTFENCE_" "8" ":" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) access( const char *a1, int a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((21 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) dup2( int a1, int a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((33 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) gettimeofday( struct timeval *a1, struct timezone *a2 ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((96 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) getgid( ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((104 | 0 ) | 0 ) ) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


inline int volatile __attribute__((always_inline)) vhangup( ){ int sysret; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((153 | 0 ) | 0 ) ) : "memory","rcx", "r11" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }


int volatile execveat( int a1, const char *a2, char* const* a3, char* const* a4, int a5 ){ int sysret; register long int r10 asm("r10")= a4; register long int r8 asm("r8")= a5 ; asm volatile ("syscall" : "=a" (sysret) : "a" ( ((322 | 0 ) | 0 ) ) , "D" (a1) , "S" (a2) , "d" (a3) , "r" (r8) : "memory","rcx", "r11" ); asm( "jmp " "OPTFENCE_""9" ); opt_fence(r10,r8); asm( "OPTFENCE_" "9" ":" ); if ( sysret<0){ errno = -sysret; return(-1);} return(sysret); }



typedef __builtin_va_list va_list;









struct udiv_t { unsigned int quot, rem; };
extern int errno;
int fprintfs( FILE* F, char *fmt, ...);
static char *errno_str(int err);
int __attribute__((optimize("Os")))uitodec(unsigned int i, char *buf, int prec, char limiter, char pad );
int dprints(int fd, const char *msg,...);
int ltodec(long i, char *buf, int prec, char limiter );




int strlen(const char*str);
int itoHEX(int i,char* buf,int padding);
int dprintf( int fd, const char *fmt, ... );
char* _match_ext2(char *text, char *re, void(*p_matched_cb)(int number, char *pos,int len), int(*p_wildcard_cb)(int number, char *match_char), text_match *st_match);
int volatile open( const char *s, int flags, ... );
int itohex(int i,char* buf,int padding);



static inline int __attribute__((always_inline)) fflush( FILE *F ){
  return(0);
}
static int fileno( FILE *F ){
  if ( F==(int*)0 )
    return ( 0 );
  if ( F==(int*)1 )
    return(1);
  if ( F==(int*)2 )
     return(2);
  asm("jmp __exit"::"D"(-1));
  return(-1);
}
int atoi(const char *c);




int strlen(const char*str);


static int fileno(FILE*);





static inline int volatile fputs(const char *c, FILE *F){
  return(write(fileno(F), c, strlen(c)));
}




static void* __attribute__((optimize("O0"))) mmap(void* addr, long len, int prot, int flags, int fd, off_t off);
void exit_errno( int errnum );



extern int dprints(int fd, const char *msg,...);
int snprintf( char *buf, long size, const char *fmt, ... );
int vsnprintf(char *buf, long size, const char* fmt, va_list args );
int _itohex(int i,char* buf,int padding, int capitals);
void _die();




int itodec(int i, char *buf, int prec, char limiter, char pad );
int match_ext2(char *text, char *re, void(*p_matched_cb)(int number, char *pos,int len), int(*p_wildcard_cb)(int number, char *match_char),text_match *st_match);

void volatile _start(){
__asm__ volatile("#.global _start\n#_start:\n xorl %ebp, %ebp\n	popq %rdi\n	movq %rsp,%rsi\n	leaq  8(%rsi,%rdi,8),%rdx\n"







 "call _startup\n"



 "movq %rax, %rdi\n.global __exit\n__exit:\n	movq $60, %rax\n	syscall\n"




 );

};
minilib_globals __mlgl;
minilib_globals * __restrict__ mlgl = &__mlgl;



int errno;






int dprints(int fd, const char *msg,...){
  va_list args;
  __builtin_va_start(args,msg);
  int a;
  int ret = 0;

  do {
    a = 0;
    while (msg[a] != 0 ){
      a++;
    }
    ret += write(fd,msg,a);
    msg = __builtin_va_arg(args,char*);
  } while ( msg != 0 );
  __builtin_va_end(args);
  return(ret);
}




int errno;

int sysret;









int main();

int _startup(int argc, char **argv, char **envp ){
errno = 0;
 mlgl->brk=0;
 mlgl->malloc_start=0;


 int ret = main(argc,argv,envp);
 asm("jmp __exit"::"D"(ret));
 asm( "jmp " "OPTFENCE_""10" ); opt_fence((void*)mlgl); asm( "OPTFENCE_" "10" ":" );


 return(ret);
}
int errno;

int sysret;








int volatile open( const char *s, int flags, ... ){
  int ret;
  va_list args;
  __builtin_va_start(args,flags);
  int mode = __builtin_va_arg(args,int);
  __builtin_va_end(args);
  asm volatile ("syscall" : "=a" (ret) : "a" ( (2 | 0 ) ) , "D" ((unsigned long int)s), "S" (flags), "d" (mode) : "memory","rcx", "r11" );

  if ( ret<0 )
    errno = -ret;

  return(ret);
}




int volatile creat( const char *s, int mode ){
  return(open( s, 00000100|00000001|00001000, mode) );
}







int vsnprintf(char *buf, long size, const char* fmt, va_list args ){



  int a = 0;
  int b = 0;
  int overflow = 0;
  int end, padding, c,groups=0;
  char sep,pad;
  char tmp[16];
  char *s;
  int mod;


  while ( fmt[a] != 0){
    if ( fmt[a] == '%' ){
      end=0;
      padding = 0;
      sep = 0;
      groups=0;
      mod = 0;
      pad = ' ';
      do {
        a++;
        if ( fmt[a] == '0' ){
         a++;
         pad = '0';
        }

        while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
            padding*=10;
            padding+=fmt[a]-48;
            a++;
        }
        switch (fmt[a]){
          case '%':
            buf[b] = '%';
            end=1;
            b++;
            if ( b>= size ){ overflow=1; goto msprintfout;};
            break;

          case 'u':


            if ( mod == 0 ){
            if ( b+13>= size ){ overflow=1; goto msprintfout;};
            b = b + uitodec(__builtin_va_arg(args,unsigned int),&buf[b],(padding?padding:1),sep,pad);

            }
            end=1;
            break;
          case 'd':

            if ( mod == 0 ){
             if ( b+13>= size ){ overflow=1; goto msprintfout;};
             b = b + itodec(__builtin_va_arg(args,int),&buf[b],padding,sep,pad);

            }


            if ( mod == 1 ){
             if ( b+27>= size ){ overflow=1; goto msprintfout;};
             b = b + ltodec(__builtin_va_arg(args,long),&buf[b],(padding?padding:1),sep);

            }


            end=1;
            break;

          case 'f':







            end=1;
            break;
          case 'l':
            mod = 1;
            break;

          case 39:
            sep = '.';
            break;
          case 'x':

            if ( b+8>= size ){ overflow=1; goto msprintfout;};
            b = b + itohex(__builtin_va_arg(args,int),&buf[b],padding);

            end=1;
            break;
          case 'X':

            if ( b+8>= size ){ overflow=1; goto msprintfout;};
            b = b + itoHEX(__builtin_va_arg(args,int),&buf[b],padding);

            end=1;
            break;

          case 'o':




            end=1;
            break;

          case 'b':





            end=1;
            break;
          case '(':
            a++;
            if ( (fmt[a] > 47 ) && (fmt[a] < 58 ) ){
              c = 0;
              do {
                tmp[c] = fmt[a];
                a++;
                c++;
              } while ( (fmt[a] > 47 ) && (fmt[a] < 58 ) );
              a--;
              tmp[c] = 0;

              groups = atoi(tmp);

            }
            break;
          case 's':
            s = __builtin_va_arg(args,char*);
            if ( padding ){
             int l=strlen(s);
             while ( padding > l ){
              buf[b] = ' ';
              b++;l++;
             }
            }
            c=0;
            while(s[c] != 0){
              buf[b] = s[c];
              c++;
              b++;
              if ( b>= size ){ overflow=1; goto msprintfout;};
            }
            end=1;
            break;
          case 'c':
            buf[b] = __builtin_va_arg(args,int);
            b++;
            end=1;
            if ( b>= size ){ overflow=1; goto msprintfout;};
            break;

        }

      } while ((end==0) && (fmt[a+1] != 0 ));

    } else {
      buf[b] = fmt[a];
      b++;
      if ( b>= size ){ overflow=1; goto msprintfout;};
    }
    a++;
  }
msprintfout:
  buf[b] = 0;
  __builtin_va_end(args);



  if ( overflow )
    return(-b);
  else
    return(b);

}
void _die(){

 int errnum=errno;







 if ( errnum )
  exit_errno(errnum);

 asm("jmp __exit"::"D"(-1));
}





int _itohex(int i,char* buf,int padding, int capitals){

  if ( capitals>0 )
    capitals = 55;
  else
    capitals = 87;

  padding = padding - 8;
  if ( padding < -7 )
    padding = -7;

  union { int n; char c[4]; } conv[2];
  conv[0].n = (( i & 0xf0f0f0f0 ) >> 4);
  conv[1].n = ( i & 0x0f0f0f0f );
  int p = 0;
  int a,b;

  for ( a=3; a>=0; a-- ){
    for ( b=0; b <=1; b++ ){
      if ( padding != 0 ){
        if ( conv[b].c[a] != 0 ){
          padding = 0;
        }
      }
      if ( padding == 0 ){
        char c = conv[b].c[a];
        if ( c < 0xa )
          c = c + 48;
        else
          c = c + capitals;
        buf[p] = c;
        p++;
      } else
        padding++;
    }
  }
  buf[p] = 0 ;
  return(p);
}
int itohex(int i,char* buf,int padding){
  return(_itohex(i,buf,padding,0));
}
int itoHEX(int i,char* buf,int padding){
  return(_itohex(i,buf,padding,1));
}
int __attribute__((optimize("Os")))uitodec(unsigned int i, char *buf, int prec, char limiter, char pad ){
  int p = 0;
  int a;
  int t1,t2,t3,dec;

  char n;
  char trail=' ';
  if ( pad )
   trail = pad;

  prec = prec - 10;


  if ( i==0 ){
    buf[0] = '0';


  }

  int trailing = 1;

 const int div[13] = {0, 100000000, 10000000, 1000000, 0, 100000, 10000, 1000, 0, 100, 10, 1};

 if ( i >= 1000000000){

   p=1;
   prec=0;
   if ( i>=2000000000 ){
     i-=2000000000;
    if ( i>=1000000000 ){
      if ( i>=2000000000 ){
        buf[0] = '4';
        i-=2000000000;
      } else {
        buf[0] = '3';
        i-=1000000000;
      }
     } else {
      buf[0] = '2';

     }
   } else {
     buf[0] = '1';
     i-=1000000000;
   }
 trailing = 0;
 } else {
   if ( prec == 0 ){
     buf[0] = ' ';
     p++;
   } else
     prec++;
 }


 for (a=0;a<12;a++){
   if ( div[a] == 0 ){
     if ( (limiter != 0 ) && (prec==0) ){
       buf[p] = limiter;
       p++;
     }
   } else {
   n = '0';

   if ( (t1=(i - div[a])) >= 0 ){
     prec = 0;
     trailing = 0;
     n = '1';
     if ( (t2=(t1-(dec=(div[a]<<2)))) >= 0){
       if ( (t3=t2-dec) >= 0 ){
         n = '9';
         i = t3;
         goto write;
       } else {
         n = '5';
         t1 = t2;
       }
     }
     if ( (t2=(t1-(div[a]<<1) ) ) >=0 ){
       t1=t2;
       n += 2;
     }
     if ( (t2=(t1-(div[a]) ) ) >=0 ){
       t1=t2;
       n += 1;
     }
     i = t1;
   }

   if ( prec == 0 ){
   write:
     if ( trailing )
       buf[p] = trail;
     else
       buf[p] = n;
     p++;
   } else
     prec++;


   }
 }
 if ( p==0 ){
   buf[0]='0';
   p=1;
 }
 buf[p] = 0;

 return(p);
}




int itodec(int i, char *buf, int prec, char limiter, char pad ){
 if ( i < 0 ){
   buf[0]='-';
   i = -i;
   return(uitodec((unsigned int)i,&buf[1],prec,limiter,pad) + 1);
 }
 return(uitodec((unsigned int)i,buf,prec,limiter,pad) );
}







static void* __attribute__((optimize("O0"))) mmap(void* addr, long len, int prot, int flags, int fd, off_t off){
  long ret;
  if ( fd <0 )
    fd=0;
  register long int r10 asm ("r10") = flags ; register long int r8 asm ("r8") = fd ; register long int r9 asm ("r9") = off; asm volatile ("syscall" : "=a" (ret) : "a" ( (( 9 | 0 ) | 0 ) ) , "D" (addr), "S" (len), "d" (prot), "r" (r10), "r" (r8), "r" (r9) : "memory","rcx", "r11" );

  if (ret<0 ){
    errno = -ret;
    ret=-1;
  }

  return((void*)ret);
}
int match_ext2(char *text, char *re, void(*p_matched_cb)(int number, char *pos,int len), int(*p_wildcard_cb)(int number, char *match_char),text_match *st_match){


  int r = 1;
  char *ret = 0;

  if ( ( *re == '*' && *(re+1)=='@' && ( r=2 ) ) ||
      ( *re=='@' ) ){
    if ( _match_ext2( text, (re+r), p_matched_cb, p_wildcard_cb, st_match ) > (long)0 )
      return( 1 );
  }
  if ( (ret = _match_ext2( text, re, p_matched_cb, p_wildcard_cb, st_match )) > 0 )
    return( 1 );

  return ( (int)(long)ret );

}



char* _match_ext2(char *text, char *re, void(*p_matched_cb)(int number, char *pos,int len), int(*p_wildcard_cb)(int number, char *match_char), text_match *st_match){
  int n_match=0;
  char *matchpos = 0;
  int neg = 0;
  char *rematch = (char*)1;


  if ( st_match )
    st_match->len=0;

  char *matchstarpos = 0;





  while ( *text!=0 ){

    int match_char = 0;
    neg = 0;
    int count = 1;

    switch (*re){
      case '!':
      neg=1;
      case ',':
      re++;
    }

    if ( *re == ')' ){

      re++;
      if ( ( text =_match_ext2(text,re,p_matched_cb,p_wildcard_cb,st_match ) ) <=0 )
        return( 0 );
      return( text );

    }

    if ( *re == '}' ){
      write(1,"  == closing }",sizeof("  == closing }"));write(1,"\n",1);
      return( text );
    }

    if ( *re == '{' ){
      re++;
      char *ret = text;
      char *r2;
      int c = 0;

      switch ( *re ){
        case '+':
          re++;
          if ( (ret = _match_ext2(text,re,
                  p_matched_cb,p_wildcard_cb,st_match ) ) <=0 )
            return(0);
          c = -1;
          break;
        case '*':
          c = -1;
          re++;
          break;
        default:
          while ( (0 ? 1 : ((unsigned)(*re)-'0') < 10) ){
            c += (c*10) + (*re-'0');
            re++;
          }
      }

      r2 = ret;
      while ( c!=0 && ((r2=_match_ext2(ret,re,
              p_matched_cb,p_wildcard_cb,st_match ) ) >0 ) ){
        write(1,r2,10);
        write(1,"\n",1);
        write(1,re,4);
        ret=r2;
        c--;
        write(fileno((int*)1),mlgl->mbuf,snprintf( mlgl->mbuf, 4096, " -- while, c: %d\n",c));
      }
      if ( c > 0 )
        return(0);

      for ( ;*re != '}'; re++ )
        if ( !*re )
          return( 0 );
      re++;

      return(_match_ext2(ret,re,p_matched_cb,p_wildcard_cb,st_match ));
    }

    char *pos = re;
    while ( count --> 0 ){
      re=pos;
      switch ( *re ){
        case '?':
          if ( neg )
            return(0);
          break;
        case '@':

          if ( *text == '\n' ){
            if ( neg ) return( 0 );
            break;
          }
          if ( neg ) break;
          return( 0 );
        case '[':
          for ( re++; *re && *re!=*text; re++ )
            if ( *re==']' )
              return(neg?text:0);
          while ( *re && *re != ']' )
            re++;
          if ( !*re )
            return( 0 );
          if ( neg )
            return( 0 );
          break;
        case '(':
          re++;
          char *bpos = re;
          char *mpos = text;
          while ( *re && *re!=')' )
            re++;
          if ( !*re )
            return(0);

          text=_match_ext2(text,bpos,p_matched_cb,p_wildcard_cb,st_match);

          if ( text<=(long)0 )
            return(0);


          write(fileno((int*)1),mlgl->mbuf,snprintf( mlgl->mbuf, 4096, "bracket match: %lx - %lx - rematch: %lx\n",mpos,text,rematch));
          write(1,mpos,text-mpos);
          write(1,"\n==========",sizeof("\n=========="));write(1,"\n",1);
          if ( ! count ){
            write(1,"retc",sizeof("retc"));write(1,"\n",1);
           return(text);
          }
          break;

        case '#':
          if ( ((*text==' ')||(*text=='\t')||(*text=='\n')||(*text=='\f')||(*text=='\r')||(*text=='\v'))){
            if ( neg ) return( 0 );
            break;
          }
          if ( neg ) break;
          return( 0 );
        case '$':
          if ( *text=='\n'){
            if ( neg ) return( 0 );
            break;
          }
          if ( neg ) break;
          return( 0 );


        case '&':
          match_char = 1;
        case '%':
          if ( re[1]!=0 && re[1] >='0' && re[1] <= '9' ){
            n_match = re[1]-'0';
            *re++;
          }

          if ( match_char ){


            if ( p_wildcard_cb ){
              int m = p_wildcard_cb(n_match,text);
              if ( m==0 ){
                if ( neg ) break;
                return( 0 );
              }
              if ( m==-1 ){

                return(neg?0:text);
              }

              text=text+m;

            }

            if ( neg ) return( 0 );
            break;
          }

          matchpos=text;
        case '+':
          text++;
          if ( !*text ) return(neg?text:0);
        case '*':
          re++;
          if ( *re == 0){
            if ( matchpos && ( p_matched_cb || st_match ) ){
              while ( *text )
                text++;
              if ( p_matched_cb )
                p_matched_cb(n_match, matchpos,text-matchpos);
              if ( st_match ){
                st_match->pos = matchpos;
                st_match->len = text-matchpos;
              }
            }
            if ( !count ){
              write(fileno((int*)1),mlgl->mbuf,snprintf( mlgl->mbuf, 4096, "starmatch, count: %d rematch: %lx\n",count,rematch));
              return(text);
            }
            else break;

          }

          char *pos;
          while ( (rematch=_match_ext2(text,re,p_matched_cb,p_wildcard_cb,st_match)) == 0 ){
            text++;
            if ( !*text ){

              if ( (*re == '#' || *re == '$') )
                goto __MATCHEND;
              return(0);
            }
          }
__MATCHEND:

          if ( matchpos ){
            if ( p_matched_cb )
              p_matched_cb(n_match,matchpos,text-matchpos);
            if ( st_match ){
              st_match->pos = matchpos;
              st_match->len = text-matchpos;
            }
          }

          if ( !count )
            return(rematch);
          else break;
          return(neg?0:text);

        case '\\':
          re++;





          if ( *re == 'n' ){ if ( neg ^ (*text=='\n') ) break; else return(0);};
          if ( *re == 't' ){ if ( neg ^ (*text=='\t') ) break; else return(0);};

          if ( *re == 'd' ){ if ( neg ^ ((0 ? 1 : ((unsigned)(*text)-'0') < 10)) ) break; else return(0);};
          if ( *re == 'D' ){ if ( neg ^ (!(0 ? 1 : ((unsigned)(*text)-'0') < 10)) ) break; else return(0);};
          if ( *re == 's' ){ if ( neg ^ (((*text==' ')||(*text=='\t')||(*text=='\n')||(*text=='\f')||(*text=='\r')||(*text=='\v'))) ) break; else return(0);};
          if ( *re == 'S' ){ if ( neg ^ (!((*text==' ')||(*text=='\t')||(*text=='\n')||(*text=='\f')||(*text=='\r')||(*text=='\v'))) ) break; else return(0);};
          if ( *re == 'w' ){ if ( neg ^ ((*text>=32 && *text <= 126 ) || ( *text>=160 )) ) break; else return(0);};
          if ( *re == 'W' ){ if ( neg ^ ((*text<32 ) || (( *text > 126 ) && ( *text<160 ))) ) break; else return(0);};
          if ( *re == 'x' ){ if ( neg ^ ((0 ? 1 : ((unsigned)(*text)-'0') < 10) || ('a'<=*text && *text<='f') || ('A'<=*text && *text<='F')) ) break; else return(0);}

                                          ;
        default:
          if ( *re==0 )
            return(0);
          if ( neg ^ (*re!=*text) ){
            return(0);
          }
      }
      text++;
    }
    re++;
  }




  if ( *re == ',' )
    re++;
  if ( ( *re=='#' ) || ( *re=='$') ){

    dprints(1, "re_match end","\n",0);
    return(text);
  }

  if ( *re==0 || ( *re=='*' && re[1]==0 ) ){

      return(text);

  }

  return(0);


}




int fprintfs( FILE* F, char *fmt, ...){
  va_list args;
  __builtin_va_start(args,fmt);
  char *msg;
  int fd = fileno(F);
  int a;
  int p=0;
  int ret = 0;

  a = 0;
  while (fmt[a] != 0 ){
    if ( fmt[a] == '%' ){
      a++;
      if (fmt[a] == 's'){
        ret += write(fd,&fmt[p],a-1-p);
        p=a+1;
        msg = __builtin_va_arg(args,char*);
        ret += fputs( msg, F );
      }
      if (fmt[a] == 'c'){
        ret += write(fd,&fmt[p],a-1-p);
        p=a+1;
        char c = __builtin_va_arg(args,int);
        ret += write( fd,&c,1 );
      }

    }
    a++;
  }
  ret += write(fd,&fmt[p],a-p);

  __builtin_va_end(args);
  return(ret);

}






static char *errno_str(int err){
  static char e[5];


  char *p = e;
  if ( err<0 )
    err=-err;
  if ( err>99 ){
    err-=100;
  } else {
    p++;
  }
  e[0] = '1';
  e[1]=(err/10)+'0';
  e[2]=(err%10)+'0';
  e[3]=0;
  e[4]=0;

  return(p);
}


int atoi(const char *c){
  int t,a=0;
   int ret=0;
  int dez = 1;

  while( c[a] != 0 ){
    a++;
  }
  while ( a>0 ){
    a--;
    if ( (c[a] > 48 ) && ( c[a] < 58 ) ){
      t = c[a] - 48;
      if ( t & 1 )
        ret += dez;
      dez <<= 1;
      if ( t & 2 )
        ret += dez;
      dez <<= 1;
      if ( t & 4 )
        ret += dez;
      dez <<= 1;
      if ( t & 8 )
        ret += dez;
    } else {
      dez <<= 3;
    }
    dez += (dez >> 2);
  }
  if ( c[0] == '-' )
    ret = -ret;
  return(ret);
}




int dprintf( int fd, const char *fmt, ... ){
  va_list args;
  __builtin_va_start(args,fmt);
  int r = vsnprintf(mlgl->mbuf, mlgl->mbufsize, fmt, args);
  if ( r<0 ){
    write(2,"Buffer Overrun.\n",16);
    asm("jmp __exit"::"D"(1));
  }
  write( fd, mlgl->mbuf, r );
  __builtin_va_end(args);
  return(r);
}




int snprintf( char *buf, long size, const char *fmt, ... ){
  va_list args;
  __builtin_va_start(args,fmt);
  int r = vsnprintf(buf, size, fmt, args);
  __builtin_va_end(args);
  return(r);
}
void exit_errno( int errnum ){
  if ( errnum < 0 )
    errnum = -errnum;
  char *args[3];
  args[0] = "errno";
  args[1] = (char*)errno_str( errnum );
  args[2] = 0;
  execve("/bin/errno",args,0);



  write(2,"Error, errno: ",sizeof("Error, errno: "));
  write(2, args[1], 3 );
  write(2,"\n",sizeof("\n"));
  asm("jmp __exit"::"D"(errnum));
}



int strlen(const char*str){
  int a = 0;
  while ( str[a] != 0 ){
    a++;
  }
  return (a);
}









int ultodec(unsigned long ui, char *buf, int prec, char limiter ){
 long l;
 l= (long)1000000000000000000;
 int p = 19;
 int a = 0;
 int c = 0;

 if ( ui>=((unsigned long)1000000000000000000*10) ){
   a=1;
   ui-=((unsigned long)1000000000000000000*10);
   *buf='1';
   buf++;
   c=1;
 } else {
   if ( prec >=20 ){
     a=1;
     *buf='0';
     buf++;
     c=1;
   }
 }

 while ( p>0 ){
   if ( p<=prec )
     a=1;
   if ( a || ( (long)(ui-l) >= (long)0) ){
     a=1;
     int b=0;
     while ( ui>=l ){
       b++;
       ui-=l;
     }
     if ( limiter ){
       if ( p%3 == 0 ){
         *buf=limiter;
         buf++;
         c++;
       }
     }

     *buf='0'+b;
     buf++;
     c++;
   }
   p--;
   l=l/10;
 }
 *buf=0;
 return(c);
}
int ltodec(long i, char *buf, int prec, char limiter ){
 if ( i < 0 ){
   buf[0]='-';
   i = -i;
   return(ultodec((unsigned long)i,&buf[1],prec,limiter) + 1 );
 }
 return(ultodec((unsigned long)i,buf,prec,limiter) );
}


int main( int argc, char *argv[], char *envp[] ){
  if ( argc < 2 ){
    write(1,"usage: rgrep pattern [file[...]]",sizeof("usage: rgrep pattern [file[...]]"));
    asm("jmp __exit"::"D"(1));
  }
  char *pattern = argv[1];
  struct stat ststat;
  dprints(1, pattern,"\n",0);

  while ( argc-->2 ){
    text_match stm;
      int fd = open(argv[argc],00000000);
     int r = fstat(fd,&ststat);
     if( r ) {write(2,"Couldn't stat",sizeof("Couldn't stat"));write(2,"\n",1);exit_errno(r);};
      char *f = mmap(0,ststat.st_size, 1, 0x02, fd,0);


     if ( match_ext2( f, pattern, 0,0, &stm ) > 0){
       write(1,"MATCH\n",sizeof("MATCH\n"));
       write(1,stm.pos,stm.len);
       write(1,"\n2\n",3);
     }
       write(1,stm.pos,stm.len);
       write(1,"\n1\n",3);


    munmap(f, ststat.st_size);
    close(fd);
  }
  return(0);
}
