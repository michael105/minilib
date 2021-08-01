#if 0
mini_start
mini_writes
mini_prints
mini_fwrites
mini_write
mini_mount
mini_open
mini_errno

#mini_printf
#mini_printfs
#mini_strlen
#mini_itodec
#mini_buf 256
#mini_atoi
LDSCRIPT text_and_bss
shrinkelf
INCLUDESRC
OPTFLAG -Os
return
#endif

//+doc convert errno to str, with 3 chars length
// ending the string (located on the stack (!) 
// with two \0\0, when errno<100
const char *errno_str(int err){
		char *e="100\0";
		char *p = e;
		if ( err>99 ){
				err-=100;
		} else {
				p++;
		}
		e[1]+=err/10;
		e[2]+=err%10;

		return(p);
}


void usage(){
		writes("mount [-h|r|m|s|e|B|M] [-t type] [-o options] source mountpoint\n");
		exit(0);
}


int main(int argc, char *argv[]){
	  long flags = 0;
		char *type = 0;
		char *options = 0;
		char *source = 0;
		char *target = 0;
		
		if ( argc == 1 ){
				int fd = open( "/proc/mounts", O_RDONLY );
				if ( fd<0 ){
						int err = errno;
						fwrites(STDERR_FILENO, "Error reading /proc/mounts, errno: ");
						write(STDERR_FILENO,errno_str(err),3);
						return(-1);
				}
				char buf[64];
				int r = 0;
				while ( (r = read(fd,&buf,64 )) ){
						write(STDOUT_FILENO, buf, r );
				}
				return(0);
		}

		for ( *argv++; *argv; *argv++ ){
				if ( **argv == '-' ){
						for ( char *p = &argv[0][1]; *p!=0; p++ ){
								switch (*p){
										case 'h':
												usage();
												break;
										case 'r':
												flags |= MS_RDONLY;
												break;
										case 'm':
												flags |= MS_REMOUNT;
												break;
										case 's':
												flags |= MS_NOSUID;
												break;
										case 'e':
												flags |= MS_NOEXEC;
												break;
										case 'B':
												flags |= MS_BIND;
												break;
										case 'M':
												flags |= MS_MOVE;
												break;
										case 'S':
												flags |= MS_SYNCHRONOUS;
												break;

										case 't':
												*argv++;
												type = *argv;
												break;
												
										/* only options, the according filesystem itself recognizes
										 * may be passed. 
										 * that's another behaviour than that of gnu mount */
										case 'o':
												*argv++;
												options = *argv;
												break; 
										default:
												fwrites(STDERR_FILENO,"Unknown option: -");
												write(STDERR_FILENO,p,1);
												write(STDERR_FILENO,"\n",1);
												exit(-1);

								}
						}
				} else {
						if ( source )
								target = *argv;
						else 
								source = *argv;
				}

		}


		if ( !source || !target )
				usage();

		//printf("mount -t %s %s %s  %d\n", type, source, target,flags);
		if ( mount( source, target, type, flags, options ) ){
						int err = errno;
						fwrites(STDERR_FILENO, "Error: ");
						write(STDERR_FILENO,errno_str(err),3);
						return(-1);
		}

		return(0);
}
