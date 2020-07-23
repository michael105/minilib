//+doc set errno, but only when errno is defined.
//+def errno
#ifdef mini_errno
#define seterrno(e) { if ( e>0 ) errno = e; else errno=-e; }
#else
#define seterrno(e) {}
#endif

