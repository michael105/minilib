#if 0
mini_start
mini_atoi
mini_execl
mini_ewrites
mini_eprints
mini_errno
mini_exec_errno


INCLUDESRC
SHRINKELF
LDSCRIPT text_and_bss

return
#endif


// this isn't secure.
// possibility for an user, to enter a setgid shell.
// might be tolerable, when only privileged users
// (being in the same group as this wrapper)
// are allowed to execute the wrapper.
// (chmod o-rx)
// Finally, it might also be possible 
// to start a gtk program, and fork then into a shell.
//
// And the reason for this wrapper is to drop privileges.
// I'm not satisfied. But this damned gtk restriction
// of not allowing setgid'd programs to run
// forces to such a stupid wrapper.
//
// The gtk developers got a real misconception.
// They seem to know only about suid root.
// The concept of suid user_with_dropped_privileges
// is sadly prevented, too.
// Since this problem is known, and some other people
// already pointed to it - without success -
// I'm not going to try changing the gtk sources
// and get this into upstream.
//
// There would be the possibility to do a sudo -g group.
// but this would have other disadvantages.
//
// exec the wrapped binary directly would principially work,
// but there are enviromental variables missing.
// I'm just fed up.
//
// I leave this as it is for now.
//
// misc (2020)


// the executable. should be an absolute path
#define EXEC "/bin/ls -lh"

#define GID 1002

#define MAXARGLEN 1024

int main(int argc,	char **argv, char **envp ){
//		setenv("HOME","/home/micha",1);

		if(setgid(GID)){
				ewrites("setgid() failed\n");
				//exit(1);
		};
/*		if(setuid(UID)){
				write(fileno(stderr),"setuid() failed\n",16);
				exit(1);
		};*/

		char arg[MAXARGLEN]=EXEC;
		int p = sizeof(EXEC)-1;

		for ( int c=1; argv[c] && ( p<MAXARGLEN-1 ); c++ ){
				arg[p++]=' ';
				int i = 0;
				while( argv[c][i] && ( p<MAXARGLEN-1 ) ){
					 arg[p++]=argv[c][i++];
				}
		}
		arg[p]=0;

		//printf("arg: %s\n",arg);

		int ret = execl("/sbin/sh", "sh", "-c", arg, 0 );

		eprints("Couldn't execute ",argv[1],"\n");
		exec_errno(errno);
}
