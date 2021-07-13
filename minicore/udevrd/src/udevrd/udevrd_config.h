
#ifndef udevrd_config_h
#define udevrd_config_h

#include "../minilib/syntaxcheck.h"
#include "udevrd.h"

// return 0 on success
int load_config( globals *gl );

// return 1, when reloading the config gives an error
int reload_config( globals *global );




#endif
