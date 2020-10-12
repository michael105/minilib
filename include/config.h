//+doc configuration settings, to be compiled statically.
// System specific paths, maximums, etc go here.
// Other values are within globaldefs.h;
// architecture specific values are within the folder headers.
//+def config

#define PATH_MAX 4096

#define FOPEN_MAX 16

#ifndef PASSWDFILE
#define PASSWDFILE "/etc/passwd"
#endif

#ifndef GROUPFILE
#define GROUPFILE "/etc/group"
#endif

#define LOGIN_NAME_MAX 256
#define HOST_NAME_MAX 64

// max number of grups a user can be in.
#define MAXGROUPS 128

// max open streams
#define mini_FOPEN_MAX 16

//+doc enable some optimizations,
// with a slitghtly bigger memory footprint.
// defaults to off
// (yet only calloc is optimized. todo)
//+def OPTIMIZATIONS

