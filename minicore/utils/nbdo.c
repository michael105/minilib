#if 0
mini_start
mini_ewrites
mini_writes
mini_eprints
mini_exit_errno
mini_syscalls
mini_strcpy
mini_setuid
mini_setgid



INCLUDESRC
SHRINKELF
#LDSCRIPT text_and_bss

return
#endif

// sudo to drop privileges to nobody
// has to be installed with suid bit.
// the intention is to be able for users 
// to drop privileges and, e.g.,
// write with the dropped privileges
// to temporary files in /tmp.
//
// There is a known flaw, when
// an attacker knows, there is going to be written to /tmp
// he can make a link to another file, which will be overwritten
// then with the rights of the user writing to this file.

// this however relays on having an account nobody,
// which doesn't have any privileges in turn.

#define uid_nobody 65534
#define gid_nobody 65534



void usage(){
		writes("usage: nbdo [-h] command [arguments]\n"
						"Exec command with id and gid of nobody\n" );
		exit(1);
}

int main(int argc,	char **argv, char **envp ){

		gid_t group = gid_nobody;

		if (argc < 2 || (argv[1][0]=='-' && argv[1][1] == 'h' ) ){
				usage();
		}

		int ret;

#define IFFAIL(a,str) if ( (ret=a) ){ewrites(str); goto failed;}

		IFFAIL(sys_setgroups(1,&group),"setgroups()");
		IFFAIL(setgid(gid_nobody),"setgid()");
		IFFAIL(setuid(uid_nobody),"setuid()");


		for ( char *c = *argv++; c<(*envp-1); c++ ){
				if ( !*c )
						*c = ' ';
		}

		char* arg[] = { "sh", "-c", *argv };

		ret = execve("/bin/sh", arg, envp );

		ewrites("Executing /bin/sh");
failed:
		ewrites(" failed\n");
		exit_errno(ret);
}
