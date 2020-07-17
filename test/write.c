#if 0
mini_start
#mini_errno
#globals_on_stack
mini_INCLUDESRC
#STRIPFLAG
OPTFLAG -Os
LDSCRIPT onlytext
#LDSCRIPT textandbss
#SHRINKELF
return
#endif

#include "minilib/minilib.h"


int main( int argc, char *argv[] ){
		int ret = write(1,"X\n",2);

		return(ret);
}
