//+doc This macro expands to a return, and
// (when mini_errno is defined) returns -1 and sets errno,
// or returns the negative errno value.
//+def ret_errno
#ifdef mini_errno
#define ret_errno(e) { if ( e>0 ) errno = e; return(-1); }
#else
#define ret_errno(e) { return(-e); }
#endif

