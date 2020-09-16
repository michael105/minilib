#ifndef mini_getpwuid_d
#define mini_getpwuid_d

//+include

//+def
void setpwent(){
	mlgl->passwd_p = mlgl->passwdfile;
}

//+depends open userdb
//+def
struct passwd* getpwent(){
	if ( !mlgl->passwdfile ){
		if ( !passwdfile_open() ) 
			return(0);
	}
	// end of file
	if ( mlgl->passwd_p >= (mlgl->passwdfile+mlgl->passwdfilesize) )
		return(0);

	char *p = token_s(&mlgl->passwd_p);
	if ( *p == 0 )
		return(0);
	mlgl->pwent.pw_name = p;
	mlgl->pwent.pw_passwd = token_s(&mlgl->passwd_p);
	mlgl->pwent.pw_uid = token_i(&mlgl->passwd_p);
	mlgl->pwent.pw_gid = token_i(&mlgl->passwd_p);
	mlgl->pwent.pw_gecos = token_s(&mlgl->passwd_p);
	mlgl->pwent.pw_dir = token_s(&mlgl->passwd_p);
	mlgl->pwent.pw_shell = token_s(&mlgl->passwd_p);

	return(&mlgl->pwent);
}

//+def
void endpwent(){
	munmap( (void*)mlgl->passwdfile, mlgl->passwdfilesize );
	mlgl->passwdfile = 0;
}

//+doc get the passwd entry of the user with uid.
// the last result is cached, multiple calls with the same
// uid will return the cached result.
//+depends pwent mmap passwdfile_open ewrites open userdb
//+def
struct passwd *getpwuid(uid_t uid){
	if ( !mlgl->passwdfile ){
		if ( !passwdfile_open() ) 
			return(0);
	} else {
		// return "cached" entry 
	if ( ( mlgl->pwent.pw_name != 0 ) && (uid == mlgl->pwent.pw_uid ) )
		return( &mlgl->pwent );
	}

	char *p = mlgl->passwdfile;

	do {
		char *pw_name = token_s(&p);
		char *pw_passwd = token_s(&p);

		int euid = token_i(&p);

		//printf("euid: %d\n",euid);
		if ( euid == uid ){ // found
			mlgl->pwent.pw_name = pw_name;
			mlgl->pwent.pw_passwd = pw_passwd;
			mlgl->pwent.pw_uid = euid;
			mlgl->pwent.pw_gid = token_i(&p);
			mlgl->pwent.pw_gecos = token_s(&p);
			mlgl->pwent.pw_dir = token_s(&p);
			mlgl->pwent.pw_shell = token_s(&p);
			return(&mlgl->pwent);
		}

		for ( int a = 0; a<4; a++ )
			token_s(&p);

	} while ( p < (mlgl->passwdfile+mlgl->passwdfilesize) );

	return(0); // not found
}

//+doc get the passwd entry of the user "name".
// the last result is cached, multiple calls with the same
// name will return the cached result.
//+depends pwent mmap passwdfile_open ewrites open strcmp userdb
//+def
struct passwd *getpwnam(const char* name){
	if ( !mlgl->passwdfile ){
		if ( !passwdfile_open() ) 
			return(0);
	} else {
		// return "cached" entry 
	if ( strcmp( mlgl->pwent.pw_name, name) == 0 )
		return( &mlgl->pwent );
	}

	char *p = mlgl->passwdfile;

	do {
		char *pw_name = token_s(&p);

		//printf("euid: %d\n",euid);
		if ( strcmp( name, pw_name ) == 0 ){ // found
			mlgl->pwent.pw_name = pw_name;
			mlgl->pwent.pw_passwd = token_s(&p);
			mlgl->pwent.pw_uid = token_i(&p);
			mlgl->pwent.pw_gid = token_i(&p);
			mlgl->pwent.pw_gecos = token_s(&p);
			mlgl->pwent.pw_dir = token_s(&p);
			mlgl->pwent.pw_shell = token_s(&p);
			return(&mlgl->pwent);
		}

		for ( int a = 0; a<6; a++ )
			token_s(&p);

	} while ( p < (mlgl->passwdfile+mlgl->passwdfilesize) );

	return(0); // not found
}


/*
	 asm("loopin:");
	 while ( *puid>='0' && *puid <= '9' ){

	 euid = euid*10 + *puid-'0';
	 puid++;
	 }
	 asm("loopout:");


	 option -O2:
000000000804893c <loopin>:
804893c:       0f b6 45 02             movzbl 0x2(%rbp),%eax
8048940:       31 c9                   xor    %ecx,%ecx
8048942:       8d 50 d0                lea    -0x30(%rax),%edx
8048945:       80 fa 09                cmp    $0x9,%dl
8048948:       77 1f                   ja     8048969 <loopout>
804894a:       66 0f 1f 44 00 00       nopw   0x0(%rax,%rax,1)
8048950:       8d 14 89                lea    (%rcx,%rcx,4),%edx
8048953:       0f be c0                movsbl %al,%eax
8048956:       48 83 c3 01             add    $0x1,%rbx
804895a:       8d 4c 50 d0             lea    -0x30(%rax,%rdx,2),%ecx
804895e:       0f b6 03                movzbl (%rbx),%eax
8048961:       8d 50 d0                lea    -0x30(%rax),%edx
8048964:       80 fa 09                cmp    $0x9,%dl
8048967:       76 e7                   jbe    8048950 <loopin+0x14>

0000000008048969 <loopout>:



-Os:
00000000080487f2 <loopin>:
80487f2:       31 c9                   xor    %ecx,%ecx
80487f4:       8a 45 00                mov    0x0(%rbp),%al
80487f7:       8d 50 d0                lea    -0x30(%rax),%edx
80487fa:       80 fa 09                cmp    $0x9,%dl
80487fd:       77 0f                   ja     804880e <loopout>
80487ff:       6b c9 0a                imul   $0xa,%ecx,%ecx
8048802:       0f be c0                movsbl %al,%eax
8048805:       48 ff c5                inc    %rbp
8048808:       8d 4c 01 d0             lea    -0x30(%rcx,%rax,1),%ecx
804880c:       eb e6                   jmp    80487f4 <loopin+0x2>

000000000804880e <loopout>:


euid = (euid<<3) + (euid<<1) + (*puid-'0');
000000000804893c <loopin>:
804893c:       0f b6 45 02             movzbl 0x2(%rbp),%eax
8048940:       31 c9                   xor    %ecx,%ecx
8048942:       8d 50 d0                lea    -0x30(%rax),%edx
8048945:       80 fa 09                cmp    $0x9,%dl
8048948:       77 22                   ja     804896c <loopout>
804894a:       66 0f 1f 44 00 00       nopw   0x0(%rax,%rax,1)
8048950:       8d 14 09                lea    (%rcx,%rcx,1),%edx
8048953:       0f be c0                movsbl %al,%eax
8048956:       48 83 c3 01             add    $0x1,%rbx
804895a:       8d 14 ca                lea    (%rdx,%rcx,8),%edx
804895d:       8d 4c 02 d0             lea    -0x30(%rdx,%rax,1),%ecx
8048961:       0f b6 03                movzbl (%rbx),%eax
8048964:       8d 50 d0                lea    -0x30(%rax),%edx
8048967:       80 fa 09                cmp    $0x9,%dl
804896a:       76 e4                   jbe    8048950 <loopin+0x14>

000000000804896c <loopout>:

*/

#endif
