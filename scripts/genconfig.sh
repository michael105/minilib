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

mini_start(){
	echo "#define mini_start $1"
}
mini_exit(){
	echo "#define mini_exit $1"
}

LDSCRIPT(){
	export LDSCRIPT="$1" 
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
mini__epoll_create1(){ mini_define _epoll_create1 generate; }
mini_ldiv(){ mini_define ldiv generate; }
mini__sched_setscheduler(){ mini_define _sched_setscheduler generate; }
mini_execv(){ mini_define execv generate; }
mini_unlink(){ mini_define unlink generate; }
mini__rt_sigsuspend(){ mini_define _rt_sigsuspend generate; }
mini__setgid(){ mini_define _setgid generate; }
mini_die(){ mini_define die generate; }
mini__getuid(){ mini_define _getuid generate; }
mini_sleep(){ mini_define sleep generate; }
mini__accept(){ mini_define _accept generate; }
mini_tolower(){ mini_define tolower generate; }
mini_isatty(){ mini_define isatty generate; }
mini_malloc_brk(){ mini_define malloc_brk generate; }
mini_eprintf(){ mini_define eprintf generate; }
mini_atoi(){ mini_define atoi generate; }
mini__restart_syscall(){ mini_define _restart_syscall generate; }
mini__getsockname(){ mini_define _getsockname generate; }
mini__open_by_handle_at(){ mini_define _open_by_handle_at generate; }
mini__readlinkat(){ mini_define _readlinkat generate; }
mini_writes(){ mini_define writes generate; }
mini__swapoff(){ mini_define _swapoff generate; }
mini_uitoHEX(){ mini_define uitoHEX generate; }
mini__lseek(){ mini_define _lseek generate; }
mini_dprints(){ mini_define dprints generate; }
mini__nanosleep(){ mini_define _nanosleep generate; }
mini_setpgid(){ mini_define setpgid generate; }
mini_mkfifo(){ mini_define mkfifo generate; }
mini__finit_module(){ mini_define _finit_module generate; }
mini__fgetxattr(){ mini_define _fgetxattr generate; }
mini__timer_gettime(){ mini_define _timer_gettime generate; }
mini__getegid(){ mini_define _getegid generate; }
mini__setfsgid(){ mini_define _setfsgid generate; }
mini_fexecveat(){ mini_define fexecveat generate; }
mini_strcmp(){ mini_define strcmp generate; }
mini_malloc(){ mini_define malloc generate; }
mini_errno_str(){ mini_define errno_str generate; }
mini_uitohex(){ mini_define uitohex generate; }
mini_fileno(){ mini_define fileno generate; }
mini_stpcpy(){ mini_define stpcpy generate; }
mini_getchar(){ mini_define getchar generate; }
mini_setgrent(){ mini_define setgrent generate; }
mini__tee(){ mini_define _tee generate; }
mini__fdatasync(){ mini_define _fdatasync generate; }
mini_splice(){ mini_define splice generate; }
mini__getrandom(){ mini_define _getrandom generate; }
mini_where(){ mini_define where generate; }
mini__setns(){ mini_define _setns generate; }
mini__mq_notify(){ mini_define _mq_notify generate; }
mini__getgroups(){ mini_define _getgroups generate; }
mini__keyctl(){ mini_define _keyctl generate; }
mini__epoll_pwait(){ mini_define _epoll_pwait generate; }
mini__match_ext2(){ mini_define _match_ext2 generate; }
mini__sigaltstack(){ mini_define _sigaltstack generate; }
mini_print(){ mini_define print generate; }
mini_djb2_hash(){ mini_define djb2_hash generate; }
mini_printsl(){ mini_define printsl generate; }
mini__fstat(){ mini_define _fstat generate; }
mini__lremovexattr(){ mini_define _lremovexattr generate; }
mini_rt_sigreturn(){ mini_define rt_sigreturn generate; }
mini__write(){ mini_define _write generate; }
mini_chown(){ mini_define chown generate; }
mini_eprintfs(){ mini_define eprintfs generate; }
mini__sendmmsg(){ mini_define _sendmmsg generate; }
mini_grent(){ mini_define grent generate; }
mini_endpwent(){ mini_define endpwent generate; }
mini__socketpair(){ mini_define _socketpair generate; }
mini_sigaction(){ mini_define sigaction generate; }
mini_ntohs(){ mini_define ntohs generate; }
mini_getsockopt(){ mini_define getsockopt generate; }
mini__statfs(){ mini_define _statfs generate; }
mini__pwritev(){ mini_define _pwritev generate; }
mini__getsid(){ mini_define _getsid generate; }
mini__add_key(){ mini_define _add_key generate; }
mini_getuid(){ mini_define getuid generate; }
mini__lchown(){ mini_define _lchown generate; }
mini__request_key(){ mini_define _request_key generate; }
mini_execve(){ mini_define execve generate; }
mini_rand(){ mini_define rand generate; }
mini_htons(){ mini_define htons generate; }
mini__lookup_dcookie(){ mini_define _lookup_dcookie generate; }
mini_network(){ mini_define network generate; }
mini__poll(){ mini_define _poll generate; }
mini__sendmsg(){ mini_define _sendmsg generate; }
mini__inotify_add_watch(){ mini_define _inotify_add_watch generate; }
mini__renameat(){ mini_define _renameat generate; }
mini_ansicolors(){ mini_define ansicolors generate; }
mini_exit(){ mini_define exit generate; }
mini__tkill(){ mini_define _tkill generate; }
mini__dup2(){ mini_define _dup2 generate; }
mini_itooct(){ mini_define itooct generate; }
mini__setdomainname(){ mini_define _setdomainname generate; }
mini__getresuid(){ mini_define _getresuid generate; }
mini__openat(){ mini_define _openat generate; }
mini_fgetpos(){ mini_define fgetpos generate; }
mini_getitimer(){ mini_define getitimer generate; }
mini_fputs(){ mini_define fputs generate; }
mini_dief(){ mini_define dief generate; }
mini__getppid(){ mini_define _getppid generate; }
mini_ioctl(){ mini_define ioctl generate; }
mini__syslog(){ mini_define _syslog generate; }
mini__setpgid(){ mini_define _setpgid generate; }
mini__io_destroy(){ mini_define _io_destroy generate; }
mini__timer_getoverrun(){ mini_define _timer_getoverrun generate; }
mini__swapon(){ mini_define _swapon generate; }
mini_sendto(){ mini_define sendto generate; }
mini_dirbuf_malloc(){ mini_define dirbuf_malloc generate; }
mini_fgetsn(){ mini_define fgetsn generate; }
mini__flock(){ mini_define _flock generate; }
mini_vsprintf(){ mini_define vsprintf generate; }
mini__sched_getaffinity(){ mini_define _sched_getaffinity generate; }
mini_waitpid(){ mini_define waitpid generate; }
mini_perror(){ mini_define perror generate; }
mini__fanotify_init(){ mini_define _fanotify_init generate; }
mini__setpriority(){ mini_define _setpriority generate; }
mini_def(){ mini_define def generate; }
mini__open(){ mini_define _open generate; }
mini_setpwent(){ mini_define setpwent generate; }
mini_group_write(){ mini_define group_write generate; }
mini_short_errstr(){ mini_define short_errstr generate; }
mini_memfrob(){ mini_define memfrob generate; }
mini_getpgrp(){ mini_define getpgrp generate; }
mini_mknod(){ mini_define mknod generate; }
mini__gettimeofday(){ mini_define _gettimeofday generate; }
mini_match(){ mini_define match generate; }
mini_vhangup(){ mini_define vhangup generate; }
mini_strlcpy(){ mini_define strlcpy generate; }
mini_sigsuspend(){ mini_define sigsuspend generate; }
mini_clone_t(){ mini_define clone_t generate; }
mini__mincore(){ mini_define _mincore generate; }
mini__syncfs(){ mini_define _syncfs generate; }
mini_mremap(){ mini_define mremap generate; }
mini__shmdt(){ mini_define _shmdt generate; }
mini_itobin(){ mini_define itobin generate; }
mini_getgrgid(){ mini_define getgrgid generate; }
mini__rt_sigqueueinfo(){ mini_define _rt_sigqueueinfo generate; }
mini_endgrent(){ mini_define endgrent generate; }
mini__inotify_init1(){ mini_define _inotify_init1 generate; }
mini_djb_cksum(){ mini_define djb_cksum generate; }
mini__close(){ mini_define _close generate; }
mini_recvfrom(){ mini_define recvfrom generate; }
mini__sched_yield(){ mini_define _sched_yield generate; }
mini_err(){ mini_define err generate; }
mini__getdents64(){ mini_define _getdents64 generate; }
mini__mbind(){ mini_define _mbind generate; }
mini_strncpy(){ mini_define strncpy generate; }
mini__modify_ldt(){ mini_define _modify_ldt generate; }
mini__itohex(){ mini_define _itohex generate; }
mini__link(){ mini_define _link generate; }
mini_rt_sigsuspend(){ mini_define rt_sigsuspend generate; }
mini__capset(){ mini_define _capset generate; }
mini_memset(){ mini_define memset generate; }
mini__prctl(){ mini_define _prctl generate; }
mini__sched_get_priority_max(){ mini_define _sched_get_priority_max generate; }
mini__ioperm(){ mini_define _ioperm generate; }
mini_putc(){ mini_define putc generate; }
mini__pread64(){ mini_define _pread64 generate; }
mini_getusergroups(){ mini_define getusergroups generate; }
mini_pivot_root(){ mini_define pivot_root generate; }
mini__access(){ mini_define _access generate; }
mini_shortcolornames(){ mini_define shortcolornames generate; }
mini__kexec_load(){ mini_define _kexec_load generate; }
mini_sys_brk(){ mini_define sys_brk generate; }
mini__eventfd2(){ mini_define _eventfd2 generate; }
mini__fchmod(){ mini_define _fchmod generate; }
mini_setgid(){ mini_define setgid generate; }
mini__linkat(){ mini_define _linkat generate; }
mini__unshare(){ mini_define _unshare generate; }
mini__clock_getres(){ mini_define _clock_getres generate; }
mini__shutdown(){ mini_define _shutdown generate; }
mini__timer_create(){ mini_define _timer_create generate; }
mini__munlock(){ mini_define _munlock generate; }
mini__munlockall(){ mini_define _munlockall generate; }
mini_fchown(){ mini_define fchown generate; }
mini__fanotify_mark(){ mini_define _fanotify_mark generate; }
mini_errx(){ mini_define errx generate; }
mini__getxattr(){ mini_define _getxattr generate; }
mini_getpwnam(){ mini_define getpwnam generate; }
mini_execvp(){ mini_define execvp generate; }
mini_rt_sigaction(){ mini_define rt_sigaction generate; }
mini_dirfd(){ mini_define dirfd generate; }
mini_getc(){ mini_define getc generate; }
mini__mremap(){ mini_define _mremap generate; }
mini_fsync(){ mini_define fsync generate; }
mini__msgrcv(){ mini_define _msgrcv generate; }
mini_getpwent(){ mini_define getpwent generate; }
mini__setitimer(){ mini_define _setitimer generate; }
mini_closedir(){ mini_define closedir generate; }
mini_mprotect(){ mini_define mprotect generate; }
mini__mprotect(){ mini_define _mprotect generate; }
mini_reboot(){ mini_define reboot generate; }
mini_dup3(){ mini_define dup3 generate; }
mini_rewinddir(){ mini_define rewinddir generate; }
mini_rewind(){ mini_define rewind generate; }
mini_usleep(){ mini_define usleep generate; }
mini_opendir(){ mini_define opendir generate; }
mini_token_i(){ mini_define token_i generate; }
mini_prctl(){ mini_define prctl generate; }
mini_time(){ mini_define time generate; }
mini_execl(){ mini_define execl generate; }
mini_calloc(){ mini_define calloc generate; }
mini_vexec_q(){ mini_define vexec_q generate; }
mini_abort(){ mini_define abort generate; }
mini_fputc(){ mini_define fputc generate; }
mini__get_robust_list(){ mini_define _get_robust_list generate; }
mini_wait(){ mini_define wait generate; }
mini_mount(){ mini_define mount generate; }
mini__strcasecmp(){ mini_define _strcasecmp generate; }
mini_memcmp(){ mini_define memcmp generate; }
mini__umount2(){ mini_define _umount2 generate; }
mini_ftell(){ mini_define ftell generate; }
mini_setitimer(){ mini_define setitimer generate; }
mini_group_print(){ mini_define group_print generate; }
mini__name_to_handle_at(){ mini_define _name_to_handle_at generate; }
mini__vfork(){ mini_define _vfork generate; }
mini__mprints(){ mini_define _mprints generate; }
mini__shmget(){ mini_define _shmget generate; }
mini__sched_getparam(){ mini_define _sched_getparam generate; }
mini_unmap_protected(){ mini_define unmap_protected generate; }
mini__listen(){ mini_define _listen generate; }
mini__kexec_file_load(){ mini_define _kexec_file_load generate; }
mini_getgrouplist(){ mini_define getgrouplist generate; }
mini__recvmsg(){ mini_define _recvmsg generate; }
mini__fadvise64(){ mini_define _fadvise64 generate; }
mini__personality(){ mini_define _personality generate; }
mini__chdir(){ mini_define _chdir generate; }
mini__rt_sigprocmask(){ mini_define _rt_sigprocmask generate; }
mini__msgsnd(){ mini_define _msgsnd generate; }
mini__clock_nanosleep(){ mini_define _clock_nanosleep generate; }
mini_token_s(){ mini_define token_s generate; }
mini_strstr(){ mini_define strstr generate; }
mini_fseek(){ mini_define fseek generate; }
mini__move_pages(){ mini_define _move_pages generate; }
mini_environ(){ mini_define environ generate; }
mini_getgid(){ mini_define getgid generate; }
mini_scandir(){ mini_define scandir generate; }
mini_setsid(){ mini_define setsid generate; }
mini__getsockopt(){ mini_define _getsockopt generate; }
mini__lsetxattr(){ mini_define _lsetxattr generate; }
mini_socket(){ mini_define socket generate; }
mini_printl(){ mini_define printl generate; }
mini__recvmmsg(){ mini_define _recvmmsg generate; }
mini_eputs(){ mini_define eputs generate; }
mini__sendfile(){ mini_define _sendfile generate; }
mini__getresgid(){ mini_define _getresgid generate; }
mini__flistxattr(){ mini_define _flistxattr generate; }
mini__io_cancel(){ mini_define _io_cancel generate; }
mini_telldir(){ mini_define telldir generate; }
mini__prlimit64(){ mini_define _prlimit64 generate; }
mini__fchmodat(){ mini_define _fchmodat generate; }
mini__sched_getattr(){ mini_define _sched_getattr generate; }
mini__connect(){ mini_define _connect generate; }
mini_getppid(){ mini_define getppid generate; }
mini__io_setup(){ mini_define _io_setup generate; }
mini_OPTFENCE(){ mini_define OPTFENCE generate; }
mini_atexit(){ mini_define atexit generate; }
mini__adjtimex(){ mini_define _adjtimex generate; }
mini__socket(){ mini_define _socket generate; }
mini_getgrent(){ mini_define getgrent generate; }
mini_errno(){ mini_define errno generate; }
mini__getrlimit(){ mini_define _getrlimit generate; }
mini_select(){ mini_define select generate; }
mini__epoll_ctl(){ mini_define _epoll_ctl generate; }
mini__rt_tgsigqueueinfo(){ mini_define _rt_tgsigqueueinfo generate; }
mini__fchdir(){ mini_define _fchdir generate; }
mini_getgrnam(){ mini_define getgrnam generate; }
mini__truncate(){ mini_define _truncate generate; }
mini_brk(){ mini_define brk generate; }
mini_scandir_bufsize(){ mini_define scandir_bufsize generate; }
mini_tcgetattr(){ mini_define tcgetattr generate; }
mini_ungetc(){ mini_define ungetc generate; }
mini__utime(){ mini_define _utime generate; }
mini__sched_rr_get_interval(){ mini_define _sched_rr_get_interval generate; }
mini_ret_errno(){ mini_define ret_errno generate; }
mini_strchrnul(){ mini_define strchrnul generate; }
mini_fchmod(){ mini_define fchmod generate; }
mini_verbose_errstr(){ mini_define verbose_errstr generate; }
mini__sendto(){ mini_define _sendto generate; }
mini_dies_if(){ mini_define dies_if generate; }
mini__semget(){ mini_define _semget generate; }
mini__clock_settime(){ mini_define _clock_settime generate; }
mini__msgget(){ mini_define _msgget generate; }
mini_prints(){ mini_define prints generate; }
mini__mlock(){ mini_define _mlock generate; }
mini__fopen(){ mini_define _fopen generate; }
mini_qsort(){ mini_define qsort generate; }
mini__read(){ mini_define _read generate; }
mini_raise(){ mini_define raise generate; }
mini_fexecve(){ mini_define fexecve generate; }
mini__strcmp(){ mini_define _strcmp generate; }
mini__process_vm_writev(){ mini_define _process_vm_writev generate; }
mini_vsnprintf(){ mini_define vsnprintf generate; }
mini__timerfd_gettime(){ mini_define _timerfd_gettime generate; }
mini__mmap(){ mini_define _mmap generate; }
mini_userdb(){ mini_define userdb generate; }
mini_getcwd(){ mini_define getcwd generate; }
mini_fprintfs(){ mini_define fprintfs generate; }
mini_execveat(){ mini_define execveat generate; }
mini_inet_ntoa(){ mini_define inet_ntoa generate; }
mini_mmap(){ mini_define mmap generate; }
mini_chroot(){ mini_define chroot generate; }
mini_open(){ mini_define open generate; }
mini_vfork(){ mini_define vfork generate; }
mini__writev(){ mini_define _writev generate; }
mini__readahead(){ mini_define _readahead generate; }
mini__mq_unlink(){ mini_define _mq_unlink generate; }
mini_uname(){ mini_define uname generate; }
mini_fstat(){ mini_define fstat generate; }
mini_sigemptyset(){ mini_define sigemptyset generate; }
mini__getcpu(){ mini_define _getcpu generate; }
mini__utimes(){ mini_define _utimes generate; }
mini_strerror(){ mini_define strerror generate; }
mini__setfsuid(){ mini_define _setfsuid generate; }
mini_mkdir(){ mini_define mkdir generate; }
mini_free(){ mini_define free generate; }
mini_setuid(){ mini_define setuid generate; }
mini__rename(){ mini_define _rename generate; }
mini__mlockall(){ mini_define _mlockall generate; }
mini_posix_openpt(){ mini_define posix_openpt generate; }
mini_vexec(){ mini_define vexec generate; }
mini_labs(){ mini_define labs generate; }
mini_match_ext(){ mini_define match_ext generate; }
mini__get_mempolicy(){ mini_define _get_mempolicy generate; }
mini_sigprocmask(){ mini_define sigprocmask generate; }
mini__semtimedop(){ mini_define _semtimedop generate; }
mini_putchar(){ mini_define putchar generate; }
mini_setsockopt(){ mini_define setsockopt generate; }
mini__sysfs(){ mini_define _sysfs generate; }
mini_getpwuid(){ mini_define getpwuid generate; }
mini__geteuid(){ mini_define _geteuid generate; }
mini_fprintf(){ mini_define fprintf generate; }
mini_creat(){ mini_define creat generate; }
mini_feof(){ mini_define feof generate; }
mini__getrusage(){ mini_define _getrusage generate; }
mini_umask(){ mini_define umask generate; }
mini_sync(){ mini_define sync generate; }
mini_getdents(){ mini_define getdents generate; }
mini_writesl(){ mini_define writesl generate; }
mini_ALIGN(){ mini_define ALIGN generate; }
mini_write(){ mini_define write generate; }
mini_strlen(){ mini_define strlen generate; }
mini__listxattr(){ mini_define _listxattr generate; }
mini_access(){ mini_define access generate; }
mini_clone(){ mini_define clone generate; }
mini_snprintfs(){ mini_define snprintfs generate; }
mini_bind(){ mini_define bind generate; }
mini__futimesat(){ mini_define _futimesat generate; }
mini_optimization_fence(){ mini_define optimization_fence generate; }
mini__mount(){ mini_define _mount generate; }
mini_ltodec(){ mini_define ltodec generate; }
mini_fdopen(){ mini_define fdopen generate; }
mini_atol(){ mini_define atol generate; }
mini_eprintsl(){ mini_define eprintsl generate; }
mini__sched_getscheduler(){ mini_define _sched_getscheduler generate; }
mini__set_mempolicy(){ mini_define _set_mempolicy generate; }
mini__unlinkat(){ mini_define _unlinkat generate; }
mini_read(){ mini_define read generate; }
mini__setreuid(){ mini_define _setreuid generate; }
mini__tgkill(){ mini_define _tgkill generate; }
mini__ptrace(){ mini_define _ptrace generate; }
mini_strtoll(){ mini_define strtoll generate; }
mini__uname(){ mini_define _uname generate; }
mini_warn(){ mini_define warn generate; }
mini__eventfd(){ mini_define _eventfd generate; }
mini_gettimeofday(){ mini_define gettimeofday generate; }
mini_verbose_errstr2(){ mini_define verbose_errstr2 generate; }
mini_link(){ mini_define link generate; }
mini_inotify_init(){ mini_define inotify_init generate; }
mini__dup(){ mini_define _dup generate; }
mini_dup2(){ mini_define dup2 generate; }
mini_memfd_create(){ mini_define memfd_create generate; }
mini_bsd_cksumblock(){ mini_define bsd_cksumblock generate; }
mini__rt_sigpending(){ mini_define _rt_sigpending generate; }
mini__fsync(){ mini_define _fsync generate; }
mini_clearerror(){ mini_define clearerror generate; }
mini__timer_settime(){ mini_define _timer_settime generate; }
mini__rt_sigtimedwait(){ mini_define _rt_sigtimedwait generate; }
mini_dirbufsize (){ mini_define dirbufsize  generate; }
mini_match_ext2(){ mini_define match_ext2 generate; }
mini__die(){ mini_define _die generate; }
mini_fgets(){ mini_define fgets generate; }
mini_exit_errno(){ mini_define exit_errno generate; }
mini_getbrk(){ mini_define getbrk generate; }
mini_ewritesl(){ mini_define ewritesl generate; }
mini_freopen(){ mini_define freopen generate; }
mini_itodec(){ mini_define itodec generate; }
mini__mq_timedsend(){ mini_define _mq_timedsend generate; }
mini_pipe(){ mini_define pipe generate; }
mini__perf_event_open(){ mini_define _perf_event_open generate; }
mini__ustat(){ mini_define _ustat generate; }
mini__waitid(){ mini_define _waitid generate; }
mini__acct(){ mini_define _acct generate; }
mini__arch_prctl(){ mini_define _arch_prctl generate; }
mini__mknod(){ mini_define _mknod generate; }
mini_tcsetattr(){ mini_define tcsetattr generate; }
mini__chown(){ mini_define _chown generate; }
mini__mkdir(){ mini_define _mkdir generate; }
mini__msgctl(){ mini_define _msgctl generate; }
mini__shmat(){ mini_define _shmat generate; }
mini__pivot_root(){ mini_define _pivot_root generate; }
mini__ioctl(){ mini_define _ioctl generate; }
mini_nanosleep(){ mini_define nanosleep generate; }
mini__ioprio_set(){ mini_define _ioprio_set generate; }
mini__sync(){ mini_define _sync generate; }
mini__semctl(){ mini_define _semctl generate; }
mini_sigismember(){ mini_define sigismember generate; }
mini__ioprio_get(){ mini_define _ioprio_get generate; }
mini_cfmakeraw(){ mini_define cfmakeraw generate; }
mini__setrlimit(){ mini_define _setrlimit generate; }
mini__inotify_init(){ mini_define _inotify_init generate; }
mini_snprintf(){ mini_define snprintf generate; }
mini__init_module(){ mini_define _init_module generate; }
mini_die_if(){ mini_define die_if generate; }
mini_ferror(){ mini_define ferror generate; }
mini__preadv(){ mini_define _preadv generate; }
mini__setresgid(){ mini_define _setresgid generate; }
mini__sched_setaffinity(){ mini_define _sched_setaffinity generate; }
mini__recvfrom(){ mini_define _recvfrom generate; }
mini__creat(){ mini_define _creat generate; }
mini_htonl(){ mini_define htonl generate; }
mini__readv(){ mini_define _readv generate; }
mini_eprint(){ mini_define eprint generate; }
mini__set_tid_address(){ mini_define _set_tid_address generate; }
mini__ppoll(){ mini_define _ppoll generate; }
mini_printfs(){ mini_define printfs generate; }
mini__setsockopt(){ mini_define _setsockopt generate; }
mini_ewrites(){ mini_define ewrites generate; }
mini_div(){ mini_define div generate; }
mini__utimensat(){ mini_define _utimensat generate; }
mini__seccomp(){ mini_define _seccomp generate; }
mini_getenv(){ mini_define getenv generate; }
mini__fstatfs(){ mini_define _fstatfs generate; }
mini__lgetxattr(){ mini_define _lgetxattr generate; }
mini_clearerr(){ mini_define clearerr generate; }
mini__sysinfo(){ mini_define _sysinfo generate; }
mini_ntohl(){ mini_define ntohl generate; }
mini_timerfd_settime(){ mini_define timerfd_settime generate; }
mini_dies(){ mini_define dies generate; }
mini_umount2(){ mini_define umount2 generate; }
mini___sysctl(){ mini_define __sysctl generate; }
mini_basename(){ mini_define basename generate; }
mini_seterrno(){ mini_define seterrno generate; }
mini__clock_adjtime(){ mini_define _clock_adjtime generate; }
mini_wait4(){ mini_define wait4 generate; }
mini_symlink(){ mini_define symlink generate; }
mini_fcntl(){ mini_define fcntl generate; }
mini_initgroups(){ mini_define initgroups generate; }
mini__io_getevents(){ mini_define _io_getevents generate; }
mini__pipe2(){ mini_define _pipe2 generate; }
mini_sigaddset(){ mini_define sigaddset generate; }
mini__readlink(){ mini_define _readlink generate; }
mini_memcpy(){ mini_define memcpy generate; }
mini_getresuid(){ mini_define getresuid generate; }
mini__signalfd4(){ mini_define _signalfd4 generate; }
mini_inotify_init1(){ mini_define inotify_init1 generate; }
mini__stat(){ mini_define _stat generate; }
mini__getpeername(){ mini_define _getpeername generate; }
mini__wait4(){ mini_define _wait4 generate; }
mini__epoll_create(){ mini_define _epoll_create generate; }
mini__vmsplice(){ mini_define _vmsplice generate; }
mini_timerfd_gettime(){ mini_define timerfd_gettime generate; }
mini__chmod(){ mini_define _chmod generate; }
mini_itoHEX(){ mini_define itoHEX generate; }
mini_dprintf(){ mini_define dprintf generate; }
mini_abs(){ mini_define abs generate; }
mini_max_groupmembers(){ mini_define max_groupmembers generate; }
mini_globals(){ mini_define globals generate; }
mini__times(){ mini_define _times generate; }
mini_msync(){ mini_define msync generate; }
mini_eprints(){ mini_define eprints generate; }
mini_setreuid(){ mini_define setreuid generate; }
mini__fallocate(){ mini_define _fallocate generate; }
mini_readdir(){ mini_define readdir generate; }
mini_printf(){ mini_define printf generate; }
mini_puts(){ mini_define puts generate; }
mini__fchown(){ mini_define _fchown generate; }
mini_fork(){ mini_define fork generate; }
mini_ewrite(){ mini_define ewrite generate; }
mini_readahead(){ mini_define readahead generate; }
mini__execve(){ mini_define _execve generate; }
mini_chdir(){ mini_define chdir generate; }
mini__rmdir(){ mini_define _rmdir generate; }
mini_fread(){ mini_define fread generate; }
mini__newfstatat(){ mini_define _newfstatat generate; }
mini__sethostname(){ mini_define _sethostname generate; }
mini_alphasort(){ mini_define alphasort generate; }
mini__set_robust_list(){ mini_define _set_robust_list generate; }
mini__mq_open(){ mini_define _mq_open generate; }
mini_sprintf(){ mini_define sprintf generate; }
mini_rename(){ mini_define rename generate; }
mini__remap_file_pages(){ mini_define _remap_file_pages generate; }
mini_gethostname(){ mini_define gethostname generate; }
mini_grantpt(){ mini_define grantpt generate; }
mini__getitimer(){ mini_define _getitimer generate; }
mini__dup3(){ mini_define _dup3 generate; }
mini_itohex(){ mini_define itohex generate; }
mini_chmod(){ mini_define chmod generate; }
mini_getgroups(){ mini_define getgroups generate; }
mini_OPTIMIZATIONS(){ mini_define OPTIMIZATIONS generate; }
mini__fremovexattr(){ mini_define _fremovexattr generate; }
mini__lstat(){ mini_define _lstat generate; }
mini__semop(){ mini_define _semop generate; }
mini__process_vm_readv(){ mini_define _process_vm_readv generate; }
mini__setxattr(){ mini_define _setxattr generate; }
mini_inotify_rm_watch(){ mini_define inotify_rm_watch generate; }
mini__shmctl(){ mini_define _shmctl generate; }
mini_ftruncate(){ mini_define ftruncate generate; }
mini__kill(){ mini_define _kill generate; }
mini_memmove(){ mini_define memmove generate; }
mini__msync(){ mini_define _msync generate; }
mini__rt_sigreturn(){ mini_define _rt_sigreturn generate; }
mini_termio(){ mini_define termio generate; }
mini_sigdelset(){ mini_define sigdelset generate; }
mini_ptsname(){ mini_define ptsname generate; }
mini_gets(){ mini_define gets generate; }
mini_setresuid(){ mini_define setresuid generate; }
mini__kcmp(){ mini_define _kcmp generate; }
mini_error(){ mini_define error generate; }
mini__exit_group(){ mini_define _exit_group generate; }
mini__migrate_pages(){ mini_define _migrate_pages generate; }
mini_ultodec(){ mini_define ultodec generate; }
mini__bind(){ mini_define _bind generate; }
mini_inet_aton(){ mini_define inet_aton generate; }
mini_ptsname_r(){ mini_define ptsname_r generate; }
mini_fflush(){ mini_define fflush generate; }
mini__getcwd(){ mini_define _getcwd generate; }
mini_stplcpy(){ mini_define stplcpy generate; }
mini_dirbuf(){ mini_define dirbuf generate; }
mini_map_protected(){ mini_define map_protected generate; }
mini__umask(){ mini_define _umask generate; }
mini__sched_setparam(){ mini_define _sched_setparam generate; }
mini_close(){ mini_define close generate; }
mini__pselect6(){ mini_define _pselect6 generate; }
mini__signalfd(){ mini_define _signalfd generate; }
mini_setenv(){ mini_define setenv generate; }
mini_fprints(){ mini_define fprints generate; }
mini__time(){ mini_define _time generate; }
mini__sched_get_priority_min(){ mini_define _sched_get_priority_min generate; }
mini__rt_sigaction(){ mini_define _rt_sigaction generate; }
mini__munmap(){ mini_define _munmap generate; }
mini_fwrite(){ mini_define fwrite generate; }
mini_realloc(){ mini_define realloc generate; }
mini_fgetsp(){ mini_define fgetsp generate; }
mini__timerfd_settime(){ mini_define _timerfd_settime generate; }
mini__futex(){ mini_define _futex generate; }
mini_stpncpy(){ mini_define stpncpy generate; }
mini__capget(){ mini_define _capget generate; }
mini_unlockpt(){ mini_define unlockpt generate; }
mini_sbrk(){ mini_define sbrk generate; }
mini_lstat(){ mini_define lstat generate; }
mini__fchownat(){ mini_define _fchownat generate; }
mini_strrchr(){ mini_define strrchr generate; }
mini_kill(){ mini_define kill generate; }
mini_putenv(){ mini_define putenv generate; }
mini__mq_getsetattr(){ mini_define _mq_getsetattr generate; }
mini_dup(){ mini_define dup generate; }
mini__delete_module(){ mini_define _delete_module generate; }
mini__fork(){ mini_define _fork generate; }
mini_poll(){ mini_define poll generate; }
mini__select(){ mini_define _select generate; }
mini__settimeofday(){ mini_define _settimeofday generate; }
mini_setgroups(){ mini_define setgroups generate; }
mini__removexattr(){ mini_define _removexattr generate; }
mini_strncasecmp(){ mini_define strncasecmp generate; }
mini__accept4(){ mini_define _accept4 generate; }
mini__reboot(){ mini_define _reboot generate; }
mini__iopl(){ mini_define _iopl generate; }
mini__getpgid(){ mini_define _getpgid generate; }
mini_seekdir(){ mini_define seekdir generate; }
mini__getpriority(){ mini_define _getpriority generate; }
mini_inotify_add_watch(){ mini_define inotify_add_watch generate; }
mini_eprintl(){ mini_define eprintl generate; }
mini_fprint(){ mini_define fprint generate; }
mini_stat(){ mini_define stat generate; }
mini_flock(){ mini_define flock generate; }
mini_munmap(){ mini_define munmap generate; }
mini_fsetpos(){ mini_define fsetpos generate; }
mini_free_brk(){ mini_define free_brk generate; }
mini__setresuid(){ mini_define _setresuid generate; }
mini_fwrites(){ mini_define fwrites generate; }
mini_sigfillset(){ mini_define sigfillset generate; }
mini__inotify_rm_watch(){ mini_define _inotify_rm_watch generate; }
mini_fgetud(){ mini_define fgetud generate; }
mini_fgetul(){ mini_define fgetul generate; }
mini__itobin(){ mini_define _itobin generate; }
mini__gettid(){ mini_define _gettid generate; }
mini__memfd_create(){ mini_define _memfd_create generate; }
mini_bsd_cksum(){ mini_define bsd_cksum generate; }
mini_setbuf(){ mini_define setbuf generate; }
mini_swap(){ mini_define swap generate; }
mini__alarm(){ mini_define _alarm generate; }
mini_pwent(){ mini_define pwent generate; }
mini_dief_if(){ mini_define dief_if generate; }
mini__fcntl(){ mini_define _fcntl generate; }
mini__unlink(){ mini_define _unlink generate; }
mini__quotactl(){ mini_define _quotactl generate; }
mini_rt_sigprocmask(){ mini_define rt_sigprocmask generate; }
mini__timer_delete(){ mini_define _timer_delete generate; }
mini__faccessat(){ mini_define _faccessat generate; }
mini_execvpe(){ mini_define execvpe generate; }
mini__pause(){ mini_define _pause generate; }
mini__getdents(){ mini_define _getdents generate; }
mini__splice(){ mini_define _splice generate; }
mini__sched_setattr(){ mini_define _sched_setattr generate; }
mini_rmdir(){ mini_define rmdir generate; }
mini_fgetc(){ mini_define fgetc generate; }
mini_vfprintf(){ mini_define vfprintf generate; }
mini__setsid(){ mini_define _setsid generate; }
mini_dirname(){ mini_define dirname generate; }
mini_sdbm_hash(){ mini_define sdbm_hash generate; }
mini_sendfile(){ mini_define sendfile generate; }
mini_timerfd_create(){ mini_define timerfd_create generate; }
mini_fwritesl(){ mini_define fwritesl generate; }
mini_fclose(){ mini_define fclose generate; }
mini_strcpy(){ mini_define strcpy generate; }
mini__chroot(){ mini_define _chroot generate; }
mini__mq_timedreceive(){ mini_define _mq_timedreceive generate; }
mini__renameat2(){ mini_define _renameat2 generate; }
mini_dtodec(){ mini_define dtodec generate; }
mini__sync_file_range(){ mini_define _sync_file_range generate; }
mini_signal(){ mini_define signal generate; }
mini__setgroups(){ mini_define _setgroups generate; }
mini__clock_gettime(){ mini_define _clock_gettime generate; }
mini__clone(){ mini_define _clone generate; }
mini_config(){ mini_define config generate; }
mini_userdb_open(){ mini_define userdb_open generate; }
mini_fopen(){ mini_define fopen generate; }
mini_strtol(){ mini_define strtol generate; }
mini_setvbuf(){ mini_define setvbuf generate; }
mini__ftruncate(){ mini_define _ftruncate generate; }
mini__timerfd_create(){ mini_define _timerfd_create generate; }
mini__llistxattr(){ mini_define _llistxattr generate; }
mini_utime(){ mini_define utime generate; }
mini_system(){ mini_define system generate; }
mini_lseek(){ mini_define lseek generate; }
mini_uitodec(){ mini_define uitodec generate; }
mini__epoll_wait(){ mini_define _epoll_wait generate; }
mini__vhangup(){ mini_define _vhangup generate; }
mini__mknodat(){ mini_define _mknodat generate; }
mini__getpid(){ mini_define _getpid generate; }
mini__mkdirat(){ mini_define _mkdirat generate; }
mini_opendirp(){ mini_define opendirp generate; }
mini__setregid(){ mini_define _setregid generate; }
mini__fsetxattr(){ mini_define _fsetxattr generate; }
mini_passwdfile_open(){ mini_define passwdfile_open generate; }
mini_strncmp(){ mini_define strncmp generate; }
mini_strcat(){ mini_define strcat generate; }
mini_getpid(){ mini_define getpid generate; }
mini_strdup(){ mini_define strdup generate; }
mini_strchr(){ mini_define strchr generate; }
mini_strcasecmp(){ mini_define strcasecmp generate; }
mini__symlinkat(){ mini_define _symlinkat generate; }
mini_term_width(){ mini_define term_width generate; }
mini__match(){ mini_define _match generate; }
mini_setbrk(){ mini_define setbrk generate; }
mini__pipe(){ mini_define _pipe generate; }
mini__symlink(){ mini_define _symlink generate; }
mini__io_submit(){ mini_define _io_submit generate; }
mini__pwrite64(){ mini_define _pwrite64 generate; }
mini_group_printf(){ mini_define group_printf generate; }
mini_srand(){ mini_define srand generate; }
mini__madvise(){ mini_define _madvise generate; }
mini__setuid(){ mini_define _setuid generate; }
mini__getpgrp(){ mini_define _getpgrp generate; }
mini__getgid(){ mini_define _getgid generate; }
