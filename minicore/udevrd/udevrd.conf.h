// header file defining the configuration structures for udevrd

#define MAGICBYTES "udevdcfg"

#define DEVPATH "./test"
#define CONFIGFILE "./udevrd.conf.bin"

typedef unsigned int p_rel;

#define CONF_INTEGERS 3
typedef struct _conf {
		uint loglevel;
		uint logfacility;
		uint logcolor;
		p_rel p_logprefix;
		p_rel p_devpath;
		p_rel p_devices;
		// begin of string section
		char stringsstart;
} conf;

#define DEV_INTEGERS 6
#define DEV_STRINGS 4
// struct containing the configuration for a device link.
typedef struct _dev {
		// relative pointer, 0 for end of list
		uint p_next;
		// uinteger values
		uint owner;
		uint group;
		uint access;
		uint link; // create link? bool.
		uint exec_uid;
		uint exec_gid;
		// strings. relative pointers.
		p_rel p_match;
		p_rel p_logmsg;
		p_rel p_link;
		p_rel p_exec;
		// begin of string data section
		char stringsstart;
} dev;

static inline char* _getstr( p_rel *i, p_rel addr ){ 
		return((char*)i + addr );
}

// get a relative string
#define getstr( addr ) _getstr( &addr, addr )
// get a relative addr (analog to getstr)
#define getaddr( addr ) _getstr( &addr, addr )

static inline dev* nextdev( const dev* current ){ 
		return(  ((dev*)((char*)&current->p_next + current->p_next))->p_next ? (dev*)((char*)&current->p_next + current->p_next):0 ); 
}

static inline conf* getconfig(char* mapping){
		return((conf*) (mapping+sizeof(MAGICBYTES)));
}

static inline dev* firstdev(char* mapping){
		return( (dev*) getaddr(getconfig(mapping)->p_devices) );
}

//#define nextdev( current ) 



