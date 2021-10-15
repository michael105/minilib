#
# Script, updated from "make header" / genheaders.pl
# The functions are callen from minilib.conf 
# (or another config file)
# The output of this script generates minilib.conf.h
# 

# empty, to enable parsing 'makefiles'
ifdef(){ 
	echo -n
}

globalregister(){
	if [ ! -z $1 ]; then 
		echo "#define mini_globalregister $1" 
	else 
		echo  '#define mini_globalregister "r15"'
	fi
}


mini_errno(){
	echo "#define mini_errno $1"
}

compile(){
	for f in `echo $* | tr ',' ' '`;
	do "mini_$f"
	done
}

COMPILE(){
	for f in `echo $* | tr ',' ' '`;
	do "mini_$f"  
	done
}

VERBOSE(){
	export VERBOSE="1"
}

mini_start(){
	echo "#define mini_start $1"
}
mini_exit(){
	echo "#define mini_exit $1"
}

mini_setjmp(){
	echo "#define mini_setjmp"
}

mini_longjmp(){
	mini_setjmp
}

LDSCRIPT(){
	export LDSCRIPT="$1" 
}

PICFLAG(){
	export PICFLAG="$1" 
}


shrinkelf(){
	export opt_shrinkelf=1
}

SHRINKELF(){
	export opt_shrinkelf=1
}

ARCH(){
	echo "#define MINILIB_ARCH $1"
	export MINI_ARCH=$1
}
OS(){
	echo "#define MINILIB_OS $1"
	export MINI_OS=$1
}
mini_buf(){
	echo "#define mini_buf $1"
}

mini_INCLUDESRC(){
	echo "#define INCLUDESRC"
}

OPTIMIZE(){
	echo "#define mini_OPTIMIZE"
}

BINARY(){
	export outputfile=$1
	export BINARY=$1
}

SOURCES(){
	export sources="$*"
	export SOURCES="$*"
}

DUMMYHEADER(){
	export DUMMYHEADER="1"
}

INCLUDESRC(){
	echo "#define INCLUDESRC"
}

mini_GETOPTS(){
	echo "#define mini_GETOPTS"
}

# The (optimization)-flag, gcc is callen with.
# Either leave it blank, or set it to e.g. '-Os'
# -O2 and higher optimizations seem to give trouble.
# -Os, -O0, -O1 passed all tests here and might be save.
OPTFLAG(){
	if [ -z "$OPTFLAG" ]; then
		export OPTFLAG=$1
	fi
}

# The stripflag (defaults to -s)
STRIPFLAG(){
	if [ -z "$STRIPFLAG" ]; then
		export STRIPFLAG=$1
	fi
}


# Generate debug symbols - don't optimize, don't strip
DEBUG(){
	export OPTFLAG='-Og -g'
	export STRIPFLAG=""
	export opt_shrinkelf=0
}


# Generate debug symbols, including minilib's source.
FULLDEBUG(){
	export opt_shrinkelf=0
	export fulldebug=1
}


# Generate debug symbols, including minilib itself
# A new outputfile ( sourcefilename.dbg.c ) containing the 
# used parts of the minilib source is generated
# and compiled to make this work

mini_HEADERGUARDS(){
	echo "#define HEADERGUARDS"
}


HEADERGUARDS(){
	echo "#define HEADERGUARDS"
}


mini_syscalls(){
	echo "#define mini_syscalls"
}

globals_on_stack(){
	echo "#define mini_globals_on_stack"
}

mini_globals(){
	echo "#define mini_globals"
}

define(){
	param=$1
	shift
	echo "#define" $param \"$*\"
}

DEFINE(){
	param=$1
	shift
	echo "#define" $param \"$*\"
	#echo "#define" $1 $2
}

embed(){
	export embed="$*"
}

mini_getopt(){
	echo "#define mini_getopt"
}

mini_getopt_long(){
	echo "#define mini_getopt_long"
}


mini_define(){
	if [ ! -z $2 ]; then 
		echo "#define mini_$1 $2" 
	else 
		echo  "#define mini_$1 $1"
	fi
}


# Everything below will be silently overwritten,
# when make header ist invoked

# --- define_functions-start: generate --- #
mini_feof(){ mini_define feof $1; }
mini__utime(){ mini_define _utime $1; }
mini__mq_open(){ mini_define _mq_open $1; }
mini_isatty(){ mini_define isatty $1; }
mini__setxattr(){ mini_define _setxattr $1; }
mini__semtimedop(){ mini_define _semtimedop $1; }
mini_map_protected(){ mini_define map_protected $1; }
mini__times(){ mini_define _times $1; }
mini__ftruncate(){ mini_define _ftruncate $1; }
mini_sys_brk(){ mini_define sys_brk $1; }
mini_fputs(){ mini_define fputs $1; }
mini__getdents(){ mini_define _getdents $1; }
mini__uname(){ mini_define _uname $1; }
mini__epoll_ctl(){ mini_define _epoll_ctl $1; }
mini_getpid(){ mini_define getpid $1; }
mini_match_ext2(){ mini_define match_ext2 $1; }
mini_lseek(){ mini_define lseek $1; }
mini_execv(){ mini_define execv $1; }
mini_passwdfile_open(){ mini_define passwdfile_open $1; }
mini_ldiv(){ mini_define ldiv $1; }
mini_mknod(){ mini_define mknod $1; }
mini__quotactl(){ mini_define _quotactl $1; }
mini__setfsgid(){ mini_define _setfsgid $1; }
mini__setpgid(){ mini_define _setpgid $1; }
mini__mlock(){ mini_define _mlock $1; }
mini_umount2(){ mini_define umount2 $1; }
mini_dies(){ mini_define dies $1; }
mini_getrusage(){ mini_define getrusage $1; }
mini_short_errstr(){ mini_define short_errstr $1; }
mini_fgetpos(){ mini_define fgetpos $1; }
mini_getc(){ mini_define getc $1; }
mini__ustat(){ mini_define _ustat $1; }
mini_splice(){ mini_define splice $1; }
mini_rename(){ mini_define rename $1; }
mini__eventfd2(){ mini_define _eventfd2 $1; }
mini_getgrent(){ mini_define getgrent $1; }
mini_ALIGN(){ mini_define ALIGN $1; }
mini__semget(){ mini_define _semget $1; }
mini__msgsnd(){ mini_define _msgsnd $1; }
mini_errno_str(){ mini_define errno_str $1; }
mini_setpwent(){ mini_define setpwent $1; }
mini_termio(){ mini_define termio $1; }
mini_error(){ mini_define error $1; }
mini__umask(){ mini_define _umask $1; }
mini__inotify_init1(){ mini_define _inotify_init1 $1; }
mini__capget(){ mini_define _capget $1; }
mini_grantpt(){ mini_define grantpt $1; }
mini_getchar(){ mini_define getchar $1; }
mini_listen(){ mini_define listen $1; }
mini__chdir(){ mini_define _chdir $1; }
mini__inotify_init(){ mini_define _inotify_init $1; }
mini__getxattr(){ mini_define _getxattr $1; }
mini__ioperm(){ mini_define _ioperm $1; }
mini_raise(){ mini_define raise $1; }
mini_unsetenv(){ mini_define unsetenv $1; }
mini__setdomainname(){ mini_define _setdomainname $1; }
mini__process_vm_writev(){ mini_define _process_vm_writev $1; }
mini__fstat(){ mini_define _fstat $1; }
mini_sigaction(){ mini_define sigaction $1; }
mini__msgget(){ mini_define _msgget $1; }
mini_sbrk(){ mini_define sbrk $1; }
mini_bsearch(){ mini_define bsearch $1; }
mini_fdopen(){ mini_define fdopen $1; }
mini__mq_timedreceive(){ mini_define _mq_timedreceive $1; }
mini__process_vm_readv(){ mini_define _process_vm_readv $1; }
mini_itohex(){ mini_define itohex $1; }
mini__ioprio_get(){ mini_define _ioprio_get $1; }
mini_vfprintf(){ mini_define vfprintf $1; }
mini__rt_sigreturn(){ mini_define _rt_sigreturn $1; }
mini__access(){ mini_define _access $1; }
mini_fsetpos(){ mini_define fsetpos $1; }
mini__tgkill(){ mini_define _tgkill $1; }
mini_fexecveat(){ mini_define fexecveat $1; }
mini_fork(){ mini_define fork $1; }
mini_def(){ mini_define def $1; }
mini__getpgid(){ mini_define _getpgid $1; }
mini__inotify_add_watch(){ mini_define _inotify_add_watch $1; }
mini__io_cancel(){ mini_define _io_cancel $1; }
mini_readdir(){ mini_define readdir $1; }
mini_inet_aton(){ mini_define inet_aton $1; }
mini_open(){ mini_define open $1; }
mini_token_i(){ mini_define token_i $1; }
mini__ppoll(){ mini_define _ppoll $1; }
mini_htonl(){ mini_define htonl $1; }
mini_strncasecmp(){ mini_define strncasecmp $1; }
mini__flistxattr(){ mini_define _flistxattr $1; }
mini_term_width(){ mini_define term_width $1; }
mini__flock(){ mini_define _flock $1; }
mini_pwent(){ mini_define pwent $1; }
mini_getsid(){ mini_define getsid $1; }
mini_eputs(){ mini_define eputs $1; }
mini_uitoHEX(){ mini_define uitoHEX $1; }
mini_vhangup(){ mini_define vhangup $1; }
mini__request_key(){ mini_define _request_key $1; }
mini__sched_setaffinity(){ mini_define _sched_setaffinity $1; }
mini_rt_sigprocmask(){ mini_define rt_sigprocmask $1; }
mini_setrlimit(){ mini_define setrlimit $1; }
mini__io_getevents(){ mini_define _io_getevents $1; }
mini__futimesat(){ mini_define _futimesat $1; }
mini_access(){ mini_define access $1; }
mini_setgroups(){ mini_define setgroups $1; }
mini__ioprio_set(){ mini_define _ioprio_set $1; }
mini__perf_event_open(){ mini_define _perf_event_open $1; }
mini__sethostname(){ mini_define _sethostname $1; }
mini_sigprocmask(){ mini_define sigprocmask $1; }
mini_alphasort(){ mini_define alphasort $1; }
mini_sendto(){ mini_define sendto $1; }
mini__readahead(){ mini_define _readahead $1; }
mini_atol(){ mini_define atol $1; }
mini__setgid(){ mini_define _setgid $1; }
mini__kcmp(){ mini_define _kcmp $1; }
mini__stat(){ mini_define _stat $1; }
mini__sched_setscheduler(){ mini_define _sched_setscheduler $1; }
mini_strcspn(){ mini_define strcspn $1; }
mini_fchmod(){ mini_define fchmod $1; }
mini__settimeofday(){ mini_define _settimeofday $1; }
mini__fstatfs(){ mini_define _fstatfs $1; }
mini__io_submit(){ mini_define _io_submit $1; }
mini_itobin(){ mini_define itobin $1; }
mini_setgid(){ mini_define setgid $1; }
mini_uitodec(){ mini_define uitodec $1; }
mini_match_ext(){ mini_define match_ext $1; }
mini_clearerr(){ mini_define clearerr $1; }
mini__futex(){ mini_define _futex $1; }
mini__rt_sigprocmask(){ mini_define _rt_sigprocmask $1; }
mini__pause(){ mini_define _pause $1; }
mini_setpgid(){ mini_define setpgid $1; }
mini__write(){ mini_define _write $1; }
mini__mbind(){ mini_define _mbind $1; }
mini_fexecve(){ mini_define fexecve $1; }
mini_memfrob(){ mini_define memfrob $1; }
mini_creat(){ mini_define creat $1; }
mini_getegid(){ mini_define getegid $1; }
mini_userdb(){ mini_define userdb $1; }
mini_group_print(){ mini_define group_print $1; }
mini_inotify_rm_watch(){ mini_define inotify_rm_watch $1; }
mini_getgrnam(){ mini_define getgrnam $1; }
mini__prlimit64(){ mini_define _prlimit64 $1; }
mini_snprintf(){ mini_define snprintf $1; }
mini_free_brk(){ mini_define free_brk $1; }
mini__mq_getsetattr(){ mini_define _mq_getsetattr $1; }
mini_time(){ mini_define time $1; }
mini_calloc(){ mini_define calloc $1; }
mini_die_if(){ mini_define die_if $1; }
mini__match_ext2(){ mini_define _match_ext2 $1; }
mini__getcpu(){ mini_define _getcpu $1; }
mini_putenv(){ mini_define putenv $1; }
mini_dirbuf_malloc(){ mini_define dirbuf_malloc $1; }
mini__recvmmsg(){ mini_define _recvmmsg $1; }
mini_wait(){ mini_define wait $1; }
mini_setresuid(){ mini_define setresuid $1; }
mini__syncfs(){ mini_define _syncfs $1; }
mini_prctl(){ mini_define prctl $1; }
mini_poll(){ mini_define poll $1; }
mini__tee(){ mini_define _tee $1; }
mini__mprints(){ mini_define _mprints $1; }
mini__epoll_create1(){ mini_define _epoll_create1 $1; }
mini_perror(){ mini_define perror $1; }
mini_ntohs(){ mini_define ntohs $1; }
mini_tcsetattr(){ mini_define tcsetattr $1; }
mini__itohex(){ mini_define _itohex $1; }
mini__getgid(){ mini_define _getgid $1; }
mini_setsockopt(){ mini_define setsockopt $1; }
mini__pipe(){ mini_define _pipe $1; }
mini_sync(){ mini_define sync $1; }
mini_fread(){ mini_define fread $1; }
mini_fseek(){ mini_define fseek $1; }
mini__lchown(){ mini_define _lchown $1; }
mini__gettimeofday(){ mini_define _gettimeofday $1; }
mini_bsd_definitions(){ mini_define bsd_definitions $1; }
mini__restart_syscall(){ mini_define _restart_syscall $1; }
mini_match(){ mini_define match $1; }
mini_globals(){ mini_define globals $1; }
mini_scandir_bufsize(){ mini_define scandir_bufsize $1; }
mini__epoll_create(){ mini_define _epoll_create $1; }
mini_sigismember(){ mini_define sigismember $1; }
mini_fgetc(){ mini_define fgetc $1; }
mini__rt_sigpending(){ mini_define _rt_sigpending $1; }
mini_getbrk(){ mini_define getbrk $1; }
mini_ftell(){ mini_define ftell $1; }
mini__swapoff(){ mini_define _swapoff $1; }
mini__pwritev(){ mini_define _pwritev $1; }
mini_strpbrk(){ mini_define strpbrk $1; }
mini_chown(){ mini_define chown $1; }
mini__epoll_pwait(){ mini_define _epoll_pwait $1; }
mini_fopen(){ mini_define fopen $1; }
mini__mq_timedsend(){ mini_define _mq_timedsend $1; }
mini__umount2(){ mini_define _umount2 $1; }
mini__modify_ldt(){ mini_define _modify_ldt $1; }
mini_ferror(){ mini_define ferror $1; }
mini_fflush(){ mini_define fflush $1; }
mini_usleep(){ mini_define usleep $1; }
mini_ewrites(){ mini_define ewrites $1; }
mini_setuid(){ mini_define setuid $1; }
mini__dup2(){ mini_define _dup2 $1; }
mini_mount(){ mini_define mount $1; }
mini__pselect6(){ mini_define _pselect6 $1; }
mini_setenv(){ mini_define setenv $1; }
mini__timer_create(){ mini_define _timer_create $1; }
mini_mkfifo(){ mini_define mkfifo $1; }
mini_chroot(){ mini_define chroot $1; }
mini_flock(){ mini_define flock $1; }
mini_eprint(){ mini_define eprint $1; }
mini_posix_openpt(){ mini_define posix_openpt $1; }
mini_fchown(){ mini_define fchown $1; }
mini_snprintfs(){ mini_define snprintfs $1; }
mini_memcmp(){ mini_define memcmp $1; }
mini_waitpid(){ mini_define waitpid $1; }
mini__getegid(){ mini_define _getegid $1; }
mini_strncpy(){ mini_define strncpy $1; }
mini__prctl(){ mini_define _prctl $1; }
mini_fputc(){ mini_define fputc $1; }
mini_fprintf(){ mini_define fprintf $1; }
mini__capset(){ mini_define _capset $1; }
mini_ewritesl(){ mini_define ewritesl $1; }
mini_ansicolors(){ mini_define ansicolors $1; }
mini_atoi(){ mini_define atoi $1; }
mini_pivot_root(){ mini_define pivot_root $1; }
mini_atexit(){ mini_define atexit $1; }
mini__sched_getattr(){ mini_define _sched_getattr $1; }
mini__fchmodat(){ mini_define _fchmodat $1; }
mini_inotify_init(){ mini_define inotify_init $1; }
mini__pivot_root(){ mini_define _pivot_root $1; }
mini__setresuid(){ mini_define _setresuid $1; }
mini_writesl(){ mini_define writesl $1; }
mini__signalfd4(){ mini_define _signalfd4 $1; }
mini_socket(){ mini_define socket $1; }
mini__strcmp(){ mini_define _strcmp $1; }
mini_strnlen(){ mini_define strnlen $1; }
mini_memchr(){ mini_define memchr $1; }
mini__rt_tgsigqueueinfo(){ mini_define _rt_tgsigqueueinfo $1; }
mini_strlcpy(){ mini_define strlcpy $1; }
mini_ret_errno(){ mini_define ret_errno $1; }
mini_strcasecmp(){ mini_define strcasecmp $1; }
mini_ftruncate(){ mini_define ftruncate $1; }
mini_tcsetpgrp(){ mini_define tcsetpgrp $1; }
mini_endpwent(){ mini_define endpwent $1; }
mini_system(){ mini_define system $1; }
mini_vfork(){ mini_define vfork $1; }
mini_eprintf(){ mini_define eprintf $1; }
mini__kexec_file_load(){ mini_define _kexec_file_load $1; }
mini_fwritesl(){ mini_define fwritesl $1; }
mini__timerfd_settime(){ mini_define _timerfd_settime $1; }
mini__clock_adjtime(){ mini_define _clock_adjtime $1; }
mini__syslog(){ mini_define _syslog $1; }
mini__chroot(){ mini_define _chroot $1; }
mini_stat(){ mini_define stat $1; }
mini__rt_sigaction(){ mini_define _rt_sigaction $1; }
mini__epoll_wait(){ mini_define _epoll_wait $1; }
mini__kexec_load(){ mini_define _kexec_load $1; }
mini__readv(){ mini_define _readv $1; }
mini__socket(){ mini_define _socket $1; }
mini__sendmmsg(){ mini_define _sendmmsg $1; }
mini__lremovexattr(){ mini_define _lremovexattr $1; }
mini__clock_gettime(){ mini_define _clock_gettime $1; }
mini_dirbuf(){ mini_define dirbuf $1; }
mini__itobin(){ mini_define _itobin $1; }
mini_strrchr(){ mini_define strrchr $1; }
mini_sigemptyset(){ mini_define sigemptyset $1; }
mini_fprint(){ mini_define fprint $1; }
mini_strtoll(){ mini_define strtoll $1; }
mini__removexattr(){ mini_define _removexattr $1; }
mini_fwrites(){ mini_define fwrites $1; }
mini__mkdirat(){ mini_define _mkdirat $1; }
mini_rt_sigaction(){ mini_define rt_sigaction $1; }
mini__getresuid(){ mini_define _getresuid $1; }
mini_unlink(){ mini_define unlink $1; }
mini_strtok_r(){ mini_define strtok_r $1; }
mini__fsetxattr(){ mini_define _fsetxattr $1; }
mini__munlock(){ mini_define _munlock $1; }
mini_bind(){ mini_define bind $1; }
mini__symlinkat(){ mini_define _symlinkat $1; }
mini_gethostname(){ mini_define gethostname $1; }
mini_mprotect(){ mini_define mprotect $1; }
mini_reboot(){ mini_define reboot $1; }
mini__sched_get_priority_min(){ mini_define _sched_get_priority_min $1; }
mini_puts(){ mini_define puts $1; }
mini_grent(){ mini_define grent $1; }
mini_fileno(){ mini_define fileno $1; }
mini_strtok(){ mini_define strtok $1; }
mini__mkdir(){ mini_define _mkdir $1; }
mini_sleep(){ mini_define sleep $1; }
mini__sched_getparam(){ mini_define _sched_getparam $1; }
mini__init_module(){ mini_define _init_module $1; }
mini_strndup(){ mini_define strndup $1; }
mini__readlinkat(){ mini_define _readlinkat $1; }
mini_printfs(){ mini_define printfs $1; }
mini__writev(){ mini_define _writev $1; }
mini__poll(){ mini_define _poll $1; }
mini_pipe(){ mini_define pipe $1; }
mini__close(){ mini_define _close $1; }
mini__setgroups(){ mini_define _setgroups $1; }
mini__readlink(){ mini_define _readlink $1; }
mini__gettid(){ mini_define _gettid $1; }
mini_sdbm_hash(){ mini_define sdbm_hash $1; }
mini_mmap(){ mini_define mmap $1; }
mini_djb_cksum(){ mini_define djb_cksum $1; }
mini_malloc(){ mini_define malloc $1; }
mini_memset(){ mini_define memset $1; }
mini__seccomp(){ mini_define _seccomp $1; }
mini__io_destroy(){ mini_define _io_destroy $1; }
mini__clock_getres(){ mini_define _clock_getres $1; }
mini_sigaddset(){ mini_define sigaddset $1; }
mini__msync(){ mini_define _msync $1; }
mini__setregid(){ mini_define _setregid $1; }
mini_fprintfs(){ mini_define fprintfs $1; }
mini__pipe2(){ mini_define _pipe2 $1; }
mini_prints(){ mini_define prints $1; }
mini_ctype_functions(){ mini_define ctype_functions $1; }
mini_die(){ mini_define die $1; }
mini_getcwd(){ mini_define getcwd $1; }
mini_freopen(){ mini_define freopen $1; }
mini__socketpair(){ mini_define _socketpair $1; }
mini_seterrno(){ mini_define seterrno $1; }
mini__fchdir(){ mini_define _fchdir $1; }
mini__getsid(){ mini_define _getsid $1; }
mini__lgetxattr(){ mini_define _lgetxattr $1; }
mini__getpid(){ mini_define _getpid $1; }
mini_rand(){ mini_define rand $1; }
mini_utime(){ mini_define utime $1; }
mini_clone_t(){ mini_define clone_t $1; }
mini_signal(){ mini_define signal $1; }
mini__remap_file_pages(){ mini_define _remap_file_pages $1; }
mini_dprintf(){ mini_define dprintf $1; }
mini__mremap(){ mini_define _mremap $1; }
mini_eprintfs(){ mini_define eprintfs $1; }
mini_abort(){ mini_define abort $1; }
mini_getdents(){ mini_define getdents $1; }
mini_free(){ mini_define free $1; }
mini_setitimer(){ mini_define setitimer $1; }
mini_kill(){ mini_define kill $1; }
mini_rewinddir(){ mini_define rewinddir $1; }
mini__acct(){ mini_define _acct $1; }
mini__select(){ mini_define _select $1; }
mini_fgets(){ mini_define fgets $1; }
mini_write(){ mini_define write $1; }
mini_accept(){ mini_define accept $1; }
mini_fsync(){ mini_define fsync $1; }
mini__getgroups(){ mini_define _getgroups $1; }
mini__shmget(){ mini_define _shmget $1; }
mini_config(){ mini_define config $1; }
mini__munlockall(){ mini_define _munlockall $1; }
mini_strncat(){ mini_define strncat $1; }
mini__clock_nanosleep(){ mini_define _clock_nanosleep $1; }
mini_strtoimax(){ mini_define strtoimax $1; }
mini_OPTIMIZATIONS(){ mini_define OPTIMIZATIONS $1; }
mini_dup3(){ mini_define dup3 $1; }
mini_readlink(){ mini_define readlink $1; }
mini_strcpy(){ mini_define strcpy $1; }
mini_token_s(){ mini_define token_s $1; }
mini__sendto(){ mini_define _sendto $1; }
mini__arch_prctl(){ mini_define _arch_prctl $1; }
mini_setbuf(){ mini_define setbuf $1; }
mini_dies_if(){ mini_define dies_if $1; }
mini__fchmod(){ mini_define _fchmod $1; }
mini__add_key(){ mini_define _add_key $1; }
mini__timer_gettime(){ mini_define _timer_gettime $1; }
mini__wait4(){ mini_define _wait4 $1; }
mini__setsid(){ mini_define _setsid $1; }
mini_bsd_timespec(){ mini_define bsd_timespec $1; }
mini__fsync(){ mini_define _fsync $1; }
mini_sigfillset(){ mini_define sigfillset $1; }
mini_exit_errno(){ mini_define exit_errno $1; }
mini_strerror(){ mini_define strerror $1; }
mini__sysinfo(){ mini_define _sysinfo $1; }
mini_initgroups(){ mini_define initgroups $1; }
mini_closedir(){ mini_define closedir $1; }
mini__get_mempolicy(){ mini_define _get_mempolicy $1; }
mini_sendfile(){ mini_define sendfile $1; }
mini_printf(){ mini_define printf $1; }
mini__dup3(){ mini_define _dup3 $1; }
mini_stpncpy(){ mini_define stpncpy $1; }
mini__link(){ mini_define _link $1; }
mini__rmdir(){ mini_define _rmdir $1; }
mini__setitimer(){ mini_define _setitimer $1; }
mini__ioctl(){ mini_define _ioctl $1; }
mini_getpwnam(){ mini_define getpwnam $1; }
mini_lstat(){ mini_define lstat $1; }
mini__kill(){ mini_define _kill $1; }
mini_uitohex(){ mini_define uitohex $1; }
mini__clone(){ mini_define _clone $1; }
mini__sched_getscheduler(){ mini_define _sched_getscheduler $1; }
mini__shmat(){ mini_define _shmat $1; }
mini_setreuid(){ mini_define setreuid $1; }
mini_dprints(){ mini_define dprints $1; }
mini_dtodec(){ mini_define dtodec $1; }
mini_clone(){ mini_define clone $1; }
mini_verbose_errstr2(){ mini_define verbose_errstr2 $1; }
mini_vexec(){ mini_define vexec $1; }
mini_dief(){ mini_define dief $1; }
mini_stplcpy(){ mini_define stplcpy $1; }
mini__linkat(){ mini_define _linkat $1; }
mini_ptsname_r(){ mini_define ptsname_r $1; }
mini_sprintf(){ mini_define sprintf $1; }
mini_timerfd_gettime(){ mini_define timerfd_gettime $1; }
mini__get_robust_list(){ mini_define _get_robust_list $1; }
mini_getgroups(){ mini_define getgroups $1; }
mini_errx(){ mini_define errx $1; }
mini_execvpe(){ mini_define execvpe $1; }
mini_getgid(){ mini_define getgid $1; }
mini__fcntl(){ mini_define _fcntl $1; }
mini__mknodat(){ mini_define _mknodat $1; }
mini__shmctl(){ mini_define _shmctl $1; }
mini_ltodec(){ mini_define ltodec $1; }
mini__setresgid(){ mini_define _setresgid $1; }
mini_printsl(){ mini_define printsl $1; }
mini_OPTFENCE(){ mini_define OPTFENCE $1; }
mini__fchown(){ mini_define _fchown $1; }
mini_inet_ntoa(){ mini_define inet_ntoa $1; }
mini__set_mempolicy(){ mini_define _set_mempolicy $1; }
mini__finit_module(){ mini_define _finit_module $1; }
mini_setbrk(){ mini_define setbrk $1; }
mini_shortcolornames(){ mini_define shortcolornames $1; }
mini_fgetsp(){ mini_define fgetsp $1; }
mini_inotify_add_watch(){ mini_define inotify_add_watch $1; }
mini__getitimer(){ mini_define _getitimer $1; }
mini_optimization_fence(){ mini_define optimization_fence $1; }
mini_timerfd_create(){ mini_define timerfd_create $1; }
mini__listxattr(){ mini_define _listxattr $1; }
mini__waitid(){ mini_define _waitid $1; }
mini_wait4(){ mini_define wait4 $1; }
mini__creat(){ mini_define _creat $1; }
mini_sys_signame(){ mini_define sys_signame $1; }
mini_locale_dummies(){ mini_define locale_dummies $1; }
mini__set_robust_list(){ mini_define _set_robust_list $1; }
mini_munmap(){ mini_define munmap $1; }
mini_getresuid(){ mini_define getresuid $1; }
mini_djb2_hash(){ mini_define djb2_hash $1; }
mini__name_to_handle_at(){ mini_define _name_to_handle_at $1; }
mini__sched_yield(){ mini_define _sched_yield $1; }
mini__unshare(){ mini_define _unshare $1; }
mini_getsockopt(){ mini_define getsockopt $1; }
mini__signalfd(){ mini_define _signalfd $1; }
mini__getresgid(){ mini_define _getresgid $1; }
mini_nanosleep(){ mini_define nanosleep $1; }
mini__getdents64(){ mini_define _getdents64 $1; }
mini__nanosleep(){ mini_define _nanosleep $1; }
mini_strcat(){ mini_define strcat $1; }
mini__fanotify_init(){ mini_define _fanotify_init $1; }
mini_err(){ mini_define err $1; }
mini_getpwuid(){ mini_define getpwuid $1; }
mini__read(){ mini_define _read $1; }
mini_bsd_cksumblock(){ mini_define bsd_cksumblock $1; }
mini__fchownat(){ mini_define _fchownat $1; }
mini_uname(){ mini_define uname $1; }
mini_strdup(){ mini_define strdup $1; }
mini_close(){ mini_define close $1; }
mini_div(){ mini_define div $1; }
mini__listen(){ mini_define _listen $1; }
mini_strchrnul(){ mini_define strchrnul $1; }
mini_tcgetattr(){ mini_define tcgetattr $1; }
mini__strcasecmp(){ mini_define _strcasecmp $1; }
mini__openat(){ mini_define _openat $1; }
mini_brk(){ mini_define brk $1; }
mini__accept(){ mini_define _accept $1; }
mini_gets(){ mini_define gets $1; }
mini_getpwent(){ mini_define getpwent $1; }
mini_basename(){ mini_define basename $1; }
mini_ewrite(){ mini_define ewrite $1; }
mini_eprints(){ mini_define eprints $1; }
mini_setgrent(){ mini_define setgrent $1; }
mini__timerfd_gettime(){ mini_define _timerfd_gettime $1; }
mini_memmove(){ mini_define memmove $1; }
mini_dup2(){ mini_define dup2 $1; }
mini_eprintl(){ mini_define eprintl $1; }
mini__madvise(){ mini_define _madvise $1; }
mini_srand(){ mini_define srand $1; }
mini__getuid(){ mini_define _getuid $1; }
mini__msgrcv(){ mini_define _msgrcv $1; }
mini__newfstatat(){ mini_define _newfstatat $1; }
mini_vsnprintf(){ mini_define vsnprintf $1; }
mini_writes(){ mini_define writes $1; }
mini__recvmsg(){ mini_define _recvmsg $1; }
mini_dirname(){ mini_define dirname $1; }
mini_qsort(){ mini_define qsort $1; }
mini__open(){ mini_define _open $1; }
mini_rt_sigsuspend(){ mini_define rt_sigsuspend $1; }
mini__geteuid(){ mini_define _geteuid $1; }
mini___sysctl(){ mini_define __sysctl $1; }
mini__setreuid(){ mini_define _setreuid $1; }
mini__setpriority(){ mini_define _setpriority $1; }
mini_strspn(){ mini_define strspn $1; }
mini_eprintsl(){ mini_define eprintsl $1; }
mini__mq_notify(){ mini_define _mq_notify $1; }
mini__recvfrom(){ mini_define _recvfrom $1; }
mini_fstat(){ mini_define fstat $1; }
mini__faccessat(){ mini_define _faccessat $1; }
mini_inotify_init1(){ mini_define inotify_init1 $1; }
mini__chmod(){ mini_define _chmod $1; }
mini__io_setup(){ mini_define _io_setup $1; }
mini_killpg(){ mini_define killpg $1; }
mini_chdir(){ mini_define chdir $1; }
mini_bsd_cksum(){ mini_define bsd_cksum $1; }
mini__lstat(){ mini_define _lstat $1; }
mini_setvbuf(){ mini_define setvbuf $1; }
mini_stpcpy(){ mini_define stpcpy $1; }
mini_recv(){ mini_define recv $1; }
mini__accept4(){ mini_define _accept4 $1; }
mini__pwrite64(){ mini_define _pwrite64 $1; }
mini_opendir(){ mini_define opendir $1; }
mini__connect(){ mini_define _connect $1; }
mini_getrlimit(){ mini_define getrlimit $1; }
mini__fopen(){ mini_define _fopen $1; }
mini__mknod(){ mini_define _mknod $1; }
mini_itoHEX(){ mini_define itoHEX $1; }
mini_read(){ mini_define read $1; }
mini__mq_unlink(){ mini_define _mq_unlink $1; }
mini_setsid(){ mini_define setsid $1; }
mini_geteuid(){ mini_define geteuid $1; }
mini_print(){ mini_define print $1; }
mini__shmdt(){ mini_define _shmdt $1; }
mini_execl(){ mini_define execl $1; }
mini_printl(){ mini_define printl $1; }
mini_opendirp(){ mini_define opendirp $1; }
mini_msync(){ mini_define msync $1; }
mini__move_pages(){ mini_define _move_pages $1; }
mini__personality(){ mini_define _personality $1; }
mini__setuid(){ mini_define _setuid $1; }
mini__mprotect(){ mini_define _mprotect $1; }
mini__llistxattr(){ mini_define _llistxattr $1; }
mini_fprints(){ mini_define fprints $1; }
mini_link(){ mini_define link $1; }
mini__rt_sigqueueinfo(){ mini_define _rt_sigqueueinfo $1; }
mini_timerfd_settime(){ mini_define timerfd_settime $1; }
mini__sched_getaffinity(){ mini_define _sched_getaffinity $1; }
mini_strtol(){ mini_define strtol $1; }
mini_vsprintf(){ mini_define vsprintf $1; }
mini__getpriority(){ mini_define _getpriority $1; }
mini_dirbufsize (){ mini_define dirbufsize  $1; }
mini__getrandom(){ mini_define _getrandom $1; }
mini_fgetul(){ mini_define fgetul $1; }
mini_ether_ntoa(){ mini_define ether_ntoa $1; }
mini_fwrite(){ mini_define fwrite $1; }
mini__execve(){ mini_define _execve $1; }
mini__sched_setparam(){ mini_define _sched_setparam $1; }
mini__getpeername(){ mini_define _getpeername $1; }
mini__renameat2(){ mini_define _renameat2 $1; }
mini__setfsuid(){ mini_define _setfsuid $1; }
mini__open_by_handle_at(){ mini_define _open_by_handle_at $1; }
mini__mount(){ mini_define _mount $1; }
mini_fgetsn(){ mini_define fgetsn $1; }
mini_max_groupmembers(){ mini_define max_groupmembers $1; }
mini_times(){ mini_define times $1; }
mini__timer_getoverrun(){ mini_define _timer_getoverrun $1; }
mini__mlockall(){ mini_define _mlockall $1; }
mini_malloc_brk(){ mini_define malloc_brk $1; }
mini_telldir(){ mini_define telldir $1; }
mini__truncate(){ mini_define _truncate $1; }
mini__rt_sigtimedwait(){ mini_define _rt_sigtimedwait $1; }
mini_labs(){ mini_define labs $1; }
mini__sync_file_range(){ mini_define _sync_file_range $1; }
mini_tcgetpgrp(){ mini_define tcgetpgrp $1; }
mini__pread64(){ mini_define _pread64 $1; }
mini_realloc(){ mini_define realloc $1; }
mini__getcwd(){ mini_define _getcwd $1; }
mini__mmap(){ mini_define _mmap $1; }
mini__migrate_pages(){ mini_define _migrate_pages $1; }
mini__fdatasync(){ mini_define _fdatasync $1; }
mini__unlink(){ mini_define _unlink $1; }
mini_ioctl(){ mini_define ioctl $1; }
mini_select(){ mini_define select $1; }
mini__dup(){ mini_define _dup $1; }
mini_fcntl(){ mini_define fcntl $1; }
mini_memfd_create(){ mini_define memfd_create $1; }
mini__fgetxattr(){ mini_define _fgetxattr $1; }
mini__sendfile(){ mini_define _sendfile $1; }
mini_environ(){ mini_define environ $1; }
mini_putc(){ mini_define putc $1; }
mini_rmdir(){ mini_define rmdir $1; }
mini__eventfd(){ mini_define _eventfd $1; }
mini__setns(){ mini_define _setns $1; }
mini__rt_sigsuspend(){ mini_define _rt_sigsuspend $1; }
mini__sysfs(){ mini_define _sysfs $1; }
mini_ntohl(){ mini_define ntohl $1; }
mini_group_printf(){ mini_define group_printf $1; }
mini_fgetud(){ mini_define fgetud $1; }
mini_abs(){ mini_define abs $1; }
mini__tkill(){ mini_define _tkill $1; }
mini_memcpy(){ mini_define memcpy $1; }
mini_sigdelset(){ mini_define sigdelset $1; }
mini__rename(){ mini_define _rename $1; }
mini__sendmsg(){ mini_define _sendmsg $1; }
mini__preadv(){ mini_define _preadv $1; }
mini_chmod(){ mini_define chmod $1; }
mini__chown(){ mini_define _chown $1; }
mini__sched_rr_get_interval(){ mini_define _sched_rr_get_interval $1; }
mini_rt_sigreturn(){ mini_define rt_sigreturn $1; }
mini__inotify_rm_watch(){ mini_define _inotify_rm_watch $1; }
mini__getppid(){ mini_define _getppid $1; }
mini__fanotify_mark(){ mini_define _fanotify_mark $1; }
mini_putchar(){ mini_define putchar $1; }
mini__shutdown(){ mini_define _shutdown $1; }
mini__vfork(){ mini_define _vfork $1; }
mini__bind(){ mini_define _bind $1; }
mini_tolower(){ mini_define tolower $1; }
mini_exit(){ mini_define exit $1; }
mini__iopl(){ mini_define _iopl $1; }
mini_network(){ mini_define network $1; }
mini_getitimer(){ mini_define getitimer $1; }
mini_where(){ mini_define where $1; }
mini__timer_settime(){ mini_define _timer_settime $1; }
mini_itooct(){ mini_define itooct $1; }
mini__timerfd_create(){ mini_define _timerfd_create $1; }
mini_getppid(){ mini_define getppid $1; }
mini_recvfrom(){ mini_define recvfrom $1; }
mini_dirfd(){ mini_define dirfd $1; }
mini__exit_group(){ mini_define _exit_group $1; }
mini_execveat(){ mini_define execveat $1; }
mini_strlen(){ mini_define strlen $1; }
mini_seekdir(){ mini_define seekdir $1; }
mini__lseek(){ mini_define _lseek $1; }
mini_verbose_errstr(){ mini_define verbose_errstr $1; }
mini__vmsplice(){ mini_define _vmsplice $1; }
mini__time(){ mini_define _time $1; }
mini__fallocate(){ mini_define _fallocate $1; }
mini__set_tid_address(){ mini_define _set_tid_address $1; }
mini_group_write(){ mini_define group_write $1; }
mini__ptrace(){ mini_define _ptrace $1; }
mini__keyctl(){ mini_define _keyctl $1; }
mini__swapon(){ mini_define _swapon $1; }
mini_execvp(){ mini_define execvp $1; }
mini__setsockopt(){ mini_define _setsockopt $1; }
mini_unlockpt(){ mini_define unlockpt $1; }
mini__getrlimit(){ mini_define _getrlimit $1; }
mini__renameat(){ mini_define _renameat $1; }
mini__sync(){ mini_define _sync $1; }
mini__memfd_create(){ mini_define _memfd_create $1; }
mini_itodec(){ mini_define itodec $1; }
mini_userdb_open(){ mini_define userdb_open $1; }
mini__sched_get_priority_max(){ mini_define _sched_get_priority_max $1; }
mini__utimes(){ mini_define _utimes $1; }
mini_scandir(){ mini_define scandir $1; }
mini__mincore(){ mini_define _mincore $1; }
mini_strchr(){ mini_define strchr $1; }
mini__sigaltstack(){ mini_define _sigaltstack $1; }
mini_execve(){ mini_define execve $1; }
mini_umask(){ mini_define umask $1; }
mini_unmap_protected(){ mini_define unmap_protected $1; }
mini__adjtimex(){ mini_define _adjtimex $1; }
mini__getpgrp(){ mini_define _getpgrp $1; }
mini__sched_setattr(){ mini_define _sched_setattr $1; }
mini_cfmakeraw(){ mini_define cfmakeraw $1; }
mini_getenv(){ mini_define getenv $1; }
mini__fadvise64(){ mini_define _fadvise64 $1; }
mini_getuid(){ mini_define getuid $1; }
mini_errno(){ mini_define errno $1; }
mini_getgrgid(){ mini_define getgrgid $1; }
mini_readahead(){ mini_define readahead $1; }
mini__alarm(){ mini_define _alarm $1; }
mini__semop(){ mini_define _semop $1; }
mini_getpgrp(){ mini_define getpgrp $1; }
mini__msgctl(){ mini_define _msgctl $1; }
mini__vhangup(){ mini_define _vhangup $1; }
mini_vexec_q(){ mini_define vexec_q $1; }
mini_warn(){ mini_define warn $1; }
mini_ultodec(){ mini_define ultodec $1; }
mini_strcmp(){ mini_define strcmp $1; }
mini__munmap(){ mini_define _munmap $1; }
mini_strncmp(){ mini_define strncmp $1; }
mini_mremap(){ mini_define mremap $1; }
mini_swap(){ mini_define swap $1; }
mini_fclose(){ mini_define fclose $1; }
mini__fremovexattr(){ mini_define _fremovexattr $1; }
mini_ptsname(){ mini_define ptsname $1; }
mini__setrlimit(){ mini_define _setrlimit $1; }
mini__getsockopt(){ mini_define _getsockopt $1; }
mini__getrusage(){ mini_define _getrusage $1; }
mini__fork(){ mini_define _fork $1; }
mini__getsockname(){ mini_define _getsockname $1; }
mini__lookup_dcookie(){ mini_define _lookup_dcookie $1; }
mini__timer_delete(){ mini_define _timer_delete $1; }
mini__utimensat(){ mini_define _utimensat $1; }
mini_dief_if(){ mini_define dief_if $1; }
mini__splice(){ mini_define _splice $1; }
mini__reboot(){ mini_define _reboot $1; }
mini__match(){ mini_define _match $1; }
mini__statfs(){ mini_define _statfs $1; }
mini__semctl(){ mini_define _semctl $1; }
mini_clearerror(){ mini_define clearerror $1; }
mini_symlink(){ mini_define symlink $1; }
mini_assert(){ mini_define assert $1; }
mini_dup(){ mini_define dup $1; }
mini_sigsuspend(){ mini_define sigsuspend $1; }
mini_getgrouplist(){ mini_define getgrouplist $1; }
mini_htons(){ mini_define htons $1; }
mini_strstr(){ mini_define strstr $1; }
mini_endgrent(){ mini_define endgrent $1; }
mini__die(){ mini_define _die $1; }
mini__unlinkat(){ mini_define _unlinkat $1; }
mini__clock_settime(){ mini_define _clock_settime $1; }
mini__lsetxattr(){ mini_define _lsetxattr $1; }
mini_mkdir(){ mini_define mkdir $1; }
mini__symlink(){ mini_define _symlink $1; }
mini__delete_module(){ mini_define _delete_module $1; }
mini_getusergroups(){ mini_define getusergroups $1; }
mini_gettimeofday(){ mini_define gettimeofday $1; }
mini_ungetc(){ mini_define ungetc $1; }
mini_rewind(){ mini_define rewind $1; }
