//+doc configuration,
// paths, maximums, etc go here.
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


