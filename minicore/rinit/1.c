#if 0

mini_start
mini_writes
mini_prints
mini_printfs
mini_printsl


mini_scandir
mini_match
mini_alphasort
#mini_malloc
mini_vexec
mini_strcpy

mini_errno
mini_buf 256
mini_errno_str
STRIPFLAG

mini_ansicolors

INCLUDESRC
#SHRINKELF
#LDSCRIPT textandbss

return
#endif

//#define RC_BOOT "/etc/rinit/boot"
#define RC_BOOT "./test/"

#define PATHMAX 256

#include "common.c"

static char re[8];

int de_select(const struct dirent* de){
		return(! match(de->d_name,re));
}



int main( int argc, char **argv, char **envp ){
		log("Start stage 1");

		strcpy(re,"S*");

		struct dirent **list;
		char path[PATHMAX];
		strncpy(path,RC_BOOT,PATHMAX);
		
		int count = scandir( RC_BOOT, &list, de_select, alphasort );

		while( count-->0 ){
				printsl( (*list)->d_name );
				strncpy(&path[sizeof(RC_BOOT)-1],(*list)->d_name,PATHMAX-sizeof(RC_BOOT));

				int ret = vexec(path,argv,envp);
				if ( errno ){
						error("Couldn't execute ",path,errno);
						errno=0;
				}
				if ( ret ){
						error(path, " returned with error.", ret );
				}

				*list++;
		}


		return(0);
}
