#ifndef mini_lseek_h
#define mini_lseek_h

//+header unistd.h
//+inc

#ifndef SEEK_SET
#define SEEK_SET        0       /* seek relative to beginning of file */
#define SEEK_CUR        1       /* seek relative to current file position */
#define SEEK_END        2       /* seek relative to end of file */
#define SEEK_MAX        SEEK_END
#endif

extern int sysret;
#ifndef mini_globalregister
extern int errno;
#endif

DEF_syscall(lseek,3,unsigned int a1, int a2, int a3 )

DEF_syscall(ftruncate,2,unsigned int a1, unsigned int a2 )
DEF_syscall(fsync,1,int a1 )




#endif

