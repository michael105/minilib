//+doc get the passwd entry of the user with uid.
// the last result is cached, multiple calls with the same
// uid will return the cached result.
//+cat userdb
//+depends pwent mmap passwdfile_open ewrites open token_s  token_i setpwent
//+def
struct passwd *getpwuid(uid_t uid){
	if ( !mlgl->passwdfile.file ){
		if ( !userdb_open(&mlgl->passwdfile,PASSWDFILE) ) 
			return(0);
	} else {
		// return "cached" entry 
	if ( ( mlgl->pwent.pw_name != 0 ) && (uid == mlgl->pwent.pw_uid ) )
		return( &mlgl->pwent );
	}

	char *p = mlgl->passwdfile.file;

	do {
		char *pw_name = token_s( &mlgl->passwdfile,&p);
		char *pw_passwd = token_s( &mlgl->passwdfile,&p);

		int euid = token_i( &mlgl->passwdfile,&p);

		//printf("euid: %d\n",euid);
		if ( euid == uid ){ // found
			mlgl->pwent.pw_name = pw_name;
			mlgl->pwent.pw_passwd = pw_passwd;
			mlgl->pwent.pw_uid = euid;
			mlgl->pwent.pw_gid = token_i( &mlgl->passwdfile,&p);
			mlgl->pwent.pw_gecos = token_s( &mlgl->passwdfile,&p);
			mlgl->pwent.pw_dir = token_s( &mlgl->passwdfile,&p);
			mlgl->pwent.pw_shell = token_s( &mlgl->passwdfile,&p);
			return(&mlgl->pwent);
		}

		for ( int a = 0; a<4; a++ )
			token_s( &mlgl->passwdfile,&p);

	} while ( p < (mlgl->passwdfile.file+mlgl->passwdfile.size) );

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

