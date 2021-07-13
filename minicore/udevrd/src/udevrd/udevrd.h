#ifndef udevrd_h
#define udevrd_h

#include "udevrd.conf.h"
#include "ino_dirs.h"


typedef struct _globals {
		dev* devices;
		conf *config;
		//watchdir_patterns* watchdirlist;
		notify_dirs *ino_dirs;
		char *configfile;
		char *argv0; // needed to load embedded config
		char *mapping;
		int embeddedconfig;
		int mappingsize;
		int configfd;
		int nfd;
} globals;



// set by the signal handler
// used to communicate with the main loop
enum _signalled { NOACTION, SIG_EXIT, SIG_RELOAD_CONFIG, SIG_LOAD_EMBEDDEDCONFIG } signalled;





#endif
