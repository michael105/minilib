// functions, common to all three stages.

#define PATHMAX 256

// log a message
static void log(const char *msg){
	printfs( AC_CYAN "---" AC_NORM " %s\n", msg );
}


static void error(const char *msg1, const char *msg2, int n_errno){
	printfs( AC_RED "Error:" AC_NORM " %s %s \nReturn: %s\n", msg1, msg2, errno_str(n_errno));
}


static char glname_start;

static int de_select(const struct dirent* de){
	return(de->d_name[0]==glname_start);
	//return(match(de->d_name,re,0));
}


// execute all executables within dir, matching regex (simple regex)
static int rundir(const char *dir, const char namestart,char **argv, char **envp){
	struct dirent **list;
	char path[PATHMAX];
	int len = strlen(dir);

	glname_start=namestart;

	strncpy(path,dir,PATHMAX);

	if ( path[len-1] != '/' ){
		path[len] = '/';
		path[++len] = 0;
	}

	int count = scandir( dir, &list, de_select, alphasort );
	int ret = 0;

	while( count-->0 ){
		printsl( (*list)->d_name );
		strncpy(&path[len],(*list)->d_name,PATHMAX-len);

		int r = vexec(path,argv,envp);
		if ( errno ){
			error("Couldn't execute ",path,errno);
			ret=errno;
			errno=0;
		}
		if ( r ){
			error(path, " returned with error.", r );
			ret=r;
		}

		*list++;
	}

	// could in the curent usecases be spared.
	// or should be replaced with getbrk before scandir,
	// and brk(addr) here.
	free_brk();

	return(ret);
}


