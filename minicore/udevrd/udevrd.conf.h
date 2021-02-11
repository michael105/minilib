// header file defining the configuration structures for udevrd

#define MAGICBYTES "udevdcfg"

#define CONF_INTEGERS 3
typedef struct _conf {
		char logprefix[32];
		int loglevel;
		int logfacility;
		int logcolor;
} conf;

#define DEV_INTEGERS 8
#define DEV_STRINGS 4
// struct containing the configuraion for a device link.
typedef struct _dev {
		// relative pointer, 0 for end of list
		int p_next;
		// integer values
		int owner;
		int group;
		int access;
		int link; // create link? bool.
		int link_owner;
		int link_group;
		int exec_uid;
		int exec_gid;
		// strings. relative pointers.
		int p_match;
		int p_logmsg;
		int p_link;
		int p_exec;
		// begin of string data section
		char stringsstart;
} dev;


