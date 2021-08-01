#ifndef udevdrd_conf_h
#define udevdrd_conf_h

// header file defining the configuration structures for udevrd

#define MAGICINT *(int*)"/cfg"

#define DEVPATH "./test"
//#define CONFIGFILE compiledconfig
//#define CONFIGFILE "./udevrd.conf.bin"


// relative pointer. needed for mmaping
typedef unsigned int p_rel;
// could be also short. 
// Don't believe 2 bytes per pointer are worth the overhead
// (needed instructions might be xor, inc, and, shift, shift (branchless)



#define CONF_INTEGERS 5
typedef struct _conf {
		unsigned int loglevel;
		unsigned int kmsglog;
		unsigned int logfacility;
		unsigned int logcolor;
		unsigned int maxrecursion;
		p_rel p_logprefix;
		p_rel p_devpath;
		p_rel p_devices;
		//p_rel p_watchdirlist;
		// begin of string section
		char stringsstart;
} conf;

typedef struct _watchdir_patterns{
		p_rel p_next;
		unsigned int ignore;
		unsigned int recurse;
		p_rel p_match;
} watchdir_patterns;

//#define DEV_INTEGERS 8
#define DEV_INTEGERS 8
#define DEV_STRINGS 5
// struct containing the configuration for a device link.
typedef struct _dev {
		// relative pointer, 0 for end of list
		p_rel p_next;
		// unsigned integer values
		unsigned int matchmode;
		unsigned int owner;
		unsigned int group;
		unsigned int access;
		unsigned int exec_uid;
		unsigned int exec_gid;
		unsigned int exec_remove_uid;
		unsigned int exec_remove_gid;

		// strings. relative pointers.
		p_rel p_match;
		p_rel p_logmsg;
		p_rel p_link;
		p_rel p_exec;
		p_rel p_exec_remove;
		// begin of string data section
		char stringsstart;
} dev;

static inline char* _getstr( p_rel *i, p_rel addr ){ 
		return((char*)i + addr );
}

static inline p_rel _setaddr( p_rel *i, char *p ){ 
		return( *i = (p - (char*)i ));
}

// get a relative string
#define getstr( addr ) _getstr( &addr, addr )
// get a relative addr (analog to getstr)
#define getaddr( addr ) _getstr( &addr, addr )

#define setaddr( relative_p, pointer ) _setaddr( &relative_p, pointer )

static inline conf* getconfig(char* mapping){
		return((conf*) (mapping+sizeof(MAGICINT)));
}

static inline dev* nextdev( const dev* current ){ 
		return(  ((dev*)((char*)&current->p_next + current->p_next))->p_next ? 
						(dev*)((char*)&current->p_next + current->p_next) : 0 ); 
}

static inline dev* firstdev(char* mapping){
		return( (dev*) getaddr(getconfig(mapping)->p_devices) );
}

//#define nextdev( current ) 


#endif
