#if 0
mini_start
mini_writes
mini_fwrites
mini_umount2
mini_errno
mini_errno_str

LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
return
#endif

// misc 2020/06
// BSD license

void usage(){
		writes("Usage: umount [-h|f|d|e|n] mountpoint\n");
		exit(-1);
}

int main(int argc, char *argv[]){
		char *m = 0;
		int flags = 0;

		if (argc < 2) {
				usage();
		}

		for ( *argv++; *argv; *argv++ ){
				if ( **argv == '-' ){
						for ( char *p = &argv[0][1]; *p!=0; p++ ){
								switch (*p){
										case 'h':
												usage();
												break;
										case 'f': 
												flags |= MNT_FORCE;
												break;
										case 'd':
												flags |= MNT_DETACH;
												break;
										case 'e':
												flags |= MNT_EXPIRE;
												break;
										case 'n':
												flags |= UMOUNT_NOFOLLOW;
												break;
										default:
												fwrites(STDERR_FILENO,"Unknown option: -");
												write(STDERR_FILENO,p,1);
												write(STDERR_FILENO,"\n",1);
												exit(-1);

								}
						}
				} else {
						m = *argv;
				}
		}

		if ( !m )
				usage();

		if ( umount2( m, flags ) ){
				int err = errno;
				fwrites(STDERR_FILENO, "Error: ");
				write(STDERR_FILENO,errno_str(err),3);
				return(-1);
		}


		return(0);
}

