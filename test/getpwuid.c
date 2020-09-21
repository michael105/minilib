#if 0
mini_buf 256
#globals_on_stack
mini_errno
mini_start
mini_printf
mini_prints
mini_itodec
mini_atoi
mini_getenv
mini_writes
mini_environ
mini_getpwuid
mini_getpwnam

mini_getpwent
mini_endpwent

define PASSWDFILE \"./data/passwd\"

mini_INCLUDESRC
STRIPFLAG
OPTFLAG -Os
LDSCRIPT text_and_bss
return
#endif

int main( int argc, char *argv[], char *envp[] ){
		printsl(argv[0]);

		struct passwd* pwent = getpwuid(394);

		printsl("found: ", pwent->pw_name," - gec: ",pwent->pw_gecos," - ",pwent->pw_dir, " - ", pwent->pw_shell);

pwent = getpwuid(1000);
		printsl("found: ", pwent->pw_name," - gec: ",pwent->pw_gecos," - ",pwent->pw_dir, " - ", pwent->pw_shell);
pwent = getpwuid(30000);
if ( pwent )
		printsl("found: ", pwent->pw_name," - gec: ",pwent->pw_gecos," - ",pwent->pw_dir, " - ", pwent->pw_shell);


		struct passwd* p;
		while( (p = getpwent()) ){
			printsl("> ",p->pw_name," - ",p->pw_shell);
		}
		setpwent();
		while( (p = getpwent()) ){
			printsl("> ",p->pw_name," - ",p->pw_shell);
		}

		endpwent();

		pwent = getpwnam("micha");
if ( pwent )
		printf("found: %s - %d:%d - gec: %s - shell: %s\n", pwent->pw_name,pwent->pw_uid,pwent->pw_gid,pwent->pw_gecos,pwent->pw_shell);

		pwent = getpwnam("priv");
if ( pwent )
		printf("found: %s - %d:%d - gec: %s - shell: %s\n", pwent->pw_name,pwent->pw_uid,pwent->pw_gid,pwent->pw_gecos,pwent->pw_shell);

		pwent = getpwnam("privoxy");
		pwent = getpwnam("privoxy");
if ( pwent )
		printf("found: %s - %d:%d - gec: %s - shell: %s\n", pwent->pw_name,pwent->pw_uid,pwent->pw_gid,pwent->pw_gecos,pwent->pw_shell);



		return(0);
}
