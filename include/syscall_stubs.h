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
//#include "syscall.h"
//#include "sys/types.h"
//#include "sys/syscall.h"

extern int sysret;
extern int errno;

struct stat;
struct timeval;
struct timezone;


DEF_syscall(gettimeofday,2, struct timeval *a1, struct timezone *a2)

DEF_syscall(getpid,0 )

DEF_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3 )

DEF_syscall(close, 1, int fd )
DEF_syscall(read, 3, int fd, POINTER *buf, int len )

DEF_syscall(uname,1,struct old_utsname *name )

DEF_syscall(getdents, 3, unsigned int fd, struct dirent *direntry, unsigned int count )

DEF_syscall(write,3,int fd,const void *buf, int len )
//rename a1=oldpath a2=newpath

DEF_syscall(rename,2, const char* a1, const char* a2 )		
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
/* minilib/include/syscall_stubs.h, line: 48 */
REAL_define_syscall(stat,2,const char* a1, struct stat* a2) 		

/* minilib/include/syscall_stubs.h, line: 47 */
REAL_define_syscall(fstat,2,int a1, struct stat* a2) 		

/* minilib/include/syscall_stubs.h, line: 41 */
REAL_define_syscall(write,3,int a1, const void *a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 59 */
REAL_define_syscall(time,1,unsigned int *a1) 

/* minilib/include/syscall_stubs.h, line: 30 */
REAL_define_syscall(getpid,0 )

/* minilib/include/syscall_stubs.h, line: 32 */
REAL_define_syscallret(mprotect, *a1, 3, POINTER *a1, POINTER a2, int a3)

/* minilib/include/syscall_stubs.h, line: 51 */
REAL_define_syscall(dup,1,int a1) 		

/* minilib/include/syscall_stubs.h, line: 49 */
REAL_define_syscall(chdir,1,const char* a1) 		

/* minilib/include/lseek.h, line: 19 */
REAL_define_syscall(ftruncate,2,unsigned int a1,  unsigned int a2) 

/* minilib/include/syscall_stubs.h, line: 37 */
REAL_define_syscall(uname,1,struct old_utsname *a1) 

/* minilib/include/syscall_stubs.h, line: 39 */
REAL_define_syscall(getdents, 3, unsigned int a1,  struct dirent *a2,  unsigned int a3) 

/* minilib/include/syscall_stubs.h, line: 53 */
REAL_define_syscall(dup3,3,int a1,  int a2,  int a3) 		

/* minilib/include/syscall_stubs.h, line: 44 */
REAL_define_syscall(rename,2, const char* a1,  const char* a2) 		

/* minilib/include/syscall_stubs.h, line: 55 */
REAL_define_syscall(getcwd,2,char *a1, long a2) 		

/* minilib/include/syscall_stubs.h, line: 35 */
REAL_define_syscall(read, 3, int a1,  POINTER *a2,  int a3) 

/* minilib/include/lseek.h, line: 20 */
REAL_define_syscall(fsync,1,int a1) 

/* minilib/include/lseek.h, line: 17 */
REAL_define_syscall(lseek,3,unsigned int a1,  int a2,  int a3) 

/* minilib/include/syscall_stubs.h, line: 28 */
REAL_define_syscall(gettimeofday,2, struct timeval *a1,  struct timezone *a2) 

/* minilib/include/syscall_stubs.h, line: 52 */
REAL_define_syscall(dup2,2,int a1,  int a2) 		

/* minilib/include/syscall_stubs.h, line: 34 */
REAL_define_syscall(close, 1, int a1) 

/* minilib/include/syscall_stubs.h, line: 45 */
REAL_define_syscall(unlink,1, const char* a1) 		

/* --- generated-macros-end: syscalldefs --- */


#endif
