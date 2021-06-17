#ifdef mini_pwent
#ifndef mini_pwent_h
#define mini_pwent_h

//+doc define passwd and group structures
//+def pwent

typedef struct passwd {
	char   *pw_name;       /* username */
	char   *pw_passwd;     /* user password */
	uid_t   pw_uid;        /* user ID */
	gid_t   pw_gid;        /* group ID */
	char   *pw_gecos;      /* user information */
	char   *pw_dir;        /* home directory */
	char   *pw_shell;      /* shell program */
} _passwd;


typedef struct group {
	char   *gr_name;        /* group name */
	char   *gr_passwd;      /* group password */
	gid_t   gr_gid;         /* group ID */
	char  *gr_mem[MAX_GROUPMEMBERS];         /* NULL-terminated array of pointers
														 to names of group members */
}_group;

// the structure keeping the files
// passwd and group
typedef struct {
	char* file;
	char* p;
	char** p2;
	int size;
} userdb;


#endif
#endif
