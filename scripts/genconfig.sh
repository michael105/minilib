#
# Script, updated from "make header" / genheaders.pl
# The functions are callen from minilib.conf 
# (or another config file)
# The output of this script generates minilib.conf.h
# 

mini_errno(){
		#echo SET TESTING gghstd >&4
		#export TESTING=asodf
		echo "#define mini_errno $1"
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
}

SOURCES(){
	export sources="$*"
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
		export OPTFLAG=$1
}

# The stripflag (defaults to -s)
STRIPFLAG(){
		export STRIPFLAG=$1
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

# Everything below will be silently overwritten,
# when make header ist invoked

# --- define_functions-start: generate --- #
mini__shmdt(){ 
  if [ ! -z $1 ]; then echo "#define mini__shmdt $1" 
	else echo  "#define mini__shmdt _shmdt"
	fi
}
mini__eventfd(){ 
  if [ ! -z $1 ]; then echo "#define mini__eventfd $1" 
	else echo  "#define mini__eventfd _eventfd"
	fi
}
mini_ewrite(){ 
  if [ ! -z $1 ]; then echo "#define mini_ewrite $1" 
	else echo  "#define mini_ewrite ewrite"
	fi
}
mini_group_print(){ 
  if [ ! -z $1 ]; then echo "#define mini_group_print $1" 
	else echo  "#define mini_group_print group_print"
	fi
}
mini_exit(){ 
  if [ ! -z $1 ]; then echo "#define mini_exit $1" 
	else echo  "#define mini_exit exit"
	fi
}
mini_srand(){ 
  if [ ! -z $1 ]; then echo "#define mini_srand $1" 
	else echo  "#define mini_srand srand"
	fi
}
mini__mq_getsetattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__mq_getsetattr $1" 
	else echo  "#define mini__mq_getsetattr _mq_getsetattr"
	fi
}
mini__waitid(){ 
  if [ ! -z $1 ]; then echo "#define mini__waitid $1" 
	else echo  "#define mini__waitid _waitid"
	fi
}
mini__process_vm_writev(){ 
  if [ ! -z $1 ]; then echo "#define mini__process_vm_writev $1" 
	else echo  "#define mini__process_vm_writev _process_vm_writev"
	fi
}
mini__mq_open(){ 
  if [ ! -z $1 ]; then echo "#define mini__mq_open $1" 
	else echo  "#define mini__mq_open _mq_open"
	fi
}
mini_die_if(){ 
  if [ ! -z $1 ]; then echo "#define mini_die_if $1" 
	else echo  "#define mini_die_if die_if"
	fi
}
mini_strcmp(){ 
  if [ ! -z $1 ]; then echo "#define mini_strcmp $1" 
	else echo  "#define mini_strcmp strcmp"
	fi
}
mini__inotify_init1(){ 
  if [ ! -z $1 ]; then echo "#define mini__inotify_init1 $1" 
	else echo  "#define mini__inotify_init1 _inotify_init1"
	fi
}
mini__settimeofday(){ 
  if [ ! -z $1 ]; then echo "#define mini__settimeofday $1" 
	else echo  "#define mini__settimeofday _settimeofday"
	fi
}
mini_umount2(){ 
  if [ ! -z $1 ]; then echo "#define mini_umount2 $1" 
	else echo  "#define mini_umount2 umount2"
	fi
}
mini__getpgrp(){ 
  if [ ! -z $1 ]; then echo "#define mini__getpgrp $1" 
	else echo  "#define mini__getpgrp _getpgrp"
	fi
}
mini__perf_event_open(){ 
  if [ ! -z $1 ]; then echo "#define mini__perf_event_open $1" 
	else echo  "#define mini__perf_event_open _perf_event_open"
	fi
}
mini__mlockall(){ 
  if [ ! -z $1 ]; then echo "#define mini__mlockall $1" 
	else echo  "#define mini__mlockall _mlockall"
	fi
}
mini__sched_getparam(){ 
  if [ ! -z $1 ]; then echo "#define mini__sched_getparam $1" 
	else echo  "#define mini__sched_getparam _sched_getparam"
	fi
}
mini_sigdelset(){ 
  if [ ! -z $1 ]; then echo "#define mini_sigdelset $1" 
	else echo  "#define mini_sigdelset sigdelset"
	fi
}
mini_fgetul(){ 
  if [ ! -z $1 ]; then echo "#define mini_fgetul $1" 
	else echo  "#define mini_fgetul fgetul"
	fi
}
mini_sleep(){ 
  if [ ! -z $1 ]; then echo "#define mini_sleep $1" 
	else echo  "#define mini_sleep sleep"
	fi
}
mini__lremovexattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__lremovexattr $1" 
	else echo  "#define mini__lremovexattr _lremovexattr"
	fi
}
mini_opendirp(){ 
  if [ ! -z $1 ]; then echo "#define mini_opendirp $1" 
	else echo  "#define mini_opendirp opendirp"
	fi
}
mini__sched_getscheduler(){ 
  if [ ! -z $1 ]; then echo "#define mini__sched_getscheduler $1" 
	else echo  "#define mini__sched_getscheduler _sched_getscheduler"
	fi
}
mini__semget(){ 
  if [ ! -z $1 ]; then echo "#define mini__semget $1" 
	else echo  "#define mini__semget _semget"
	fi
}
mini_printl(){ 
  if [ ! -z $1 ]; then echo "#define mini_printl $1" 
	else echo  "#define mini_printl printl"
	fi
}
mini_setsockopt(){ 
  if [ ! -z $1 ]; then echo "#define mini_setsockopt $1" 
	else echo  "#define mini_setsockopt setsockopt"
	fi
}
mini_getusergroups(){ 
  if [ ! -z $1 ]; then echo "#define mini_getusergroups $1" 
	else echo  "#define mini_getusergroups getusergroups"
	fi
}
mini_term_width(){ 
  if [ ! -z $1 ]; then echo "#define mini_term_width $1" 
	else echo  "#define mini_term_width term_width"
	fi
}
mini_div(){ 
  if [ ! -z $1 ]; then echo "#define mini_div $1" 
	else echo  "#define mini_div div"
	fi
}
mini_djb2_hash(){ 
  if [ ! -z $1 ]; then echo "#define mini_djb2_hash $1" 
	else echo  "#define mini_djb2_hash djb2_hash"
	fi
}
mini__prlimit64(){ 
  if [ ! -z $1 ]; then echo "#define mini__prlimit64 $1" 
	else echo  "#define mini__prlimit64 _prlimit64"
	fi
}
mini__getgid(){ 
  if [ ! -z $1 ]; then echo "#define mini__getgid $1" 
	else echo  "#define mini__getgid _getgid"
	fi
}
mini__vhangup(){ 
  if [ ! -z $1 ]; then echo "#define mini__vhangup $1" 
	else echo  "#define mini__vhangup _vhangup"
	fi
}
mini_fstat(){ 
  if [ ! -z $1 ]; then echo "#define mini_fstat $1" 
	else echo  "#define mini_fstat fstat"
	fi
}
mini__sched_setaffinity(){ 
  if [ ! -z $1 ]; then echo "#define mini__sched_setaffinity $1" 
	else echo  "#define mini__sched_setaffinity _sched_setaffinity"
	fi
}
mini__tgkill(){ 
  if [ ! -z $1 ]; then echo "#define mini__tgkill $1" 
	else echo  "#define mini__tgkill _tgkill"
	fi
}
mini_strcpy(){ 
  if [ ! -z $1 ]; then echo "#define mini_strcpy $1" 
	else echo  "#define mini_strcpy strcpy"
	fi
}
mini__clock_adjtime(){ 
  if [ ! -z $1 ]; then echo "#define mini__clock_adjtime $1" 
	else echo  "#define mini__clock_adjtime _clock_adjtime"
	fi
}
mini__accept(){ 
  if [ ! -z $1 ]; then echo "#define mini__accept $1" 
	else echo  "#define mini__accept _accept"
	fi
}
mini_lstat(){ 
  if [ ! -z $1 ]; then echo "#define mini_lstat $1" 
	else echo  "#define mini_lstat lstat"
	fi
}
mini_fopen(){ 
  if [ ! -z $1 ]; then echo "#define mini_fopen $1" 
	else echo  "#define mini_fopen fopen"
	fi
}
mini__ioperm(){ 
  if [ ! -z $1 ]; then echo "#define mini__ioperm $1" 
	else echo  "#define mini__ioperm _ioperm"
	fi
}
mini_userdb_open(){ 
  if [ ! -z $1 ]; then echo "#define mini_userdb_open $1" 
	else echo  "#define mini_userdb_open userdb_open"
	fi
}
mini_memmove(){ 
  if [ ! -z $1 ]; then echo "#define mini_memmove $1" 
	else echo  "#define mini_memmove memmove"
	fi
}
mini__close(){ 
  if [ ! -z $1 ]; then echo "#define mini__close $1" 
	else echo  "#define mini__close _close"
	fi
}
mini_execl(){ 
  if [ ! -z $1 ]; then echo "#define mini_execl $1" 
	else echo  "#define mini_execl execl"
	fi
}
mini__times(){ 
  if [ ! -z $1 ]; then echo "#define mini__times $1" 
	else echo  "#define mini__times _times"
	fi
}
mini_fflush(){ 
  if [ ! -z $1 ]; then echo "#define mini_fflush $1" 
	else echo  "#define mini_fflush fflush"
	fi
}
mini_rewind(){ 
  if [ ! -z $1 ]; then echo "#define mini_rewind $1" 
	else echo  "#define mini_rewind rewind"
	fi
}
mini__eventfd2(){ 
  if [ ! -z $1 ]; then echo "#define mini__eventfd2 $1" 
	else echo  "#define mini__eventfd2 _eventfd2"
	fi
}
mini__signalfd(){ 
  if [ ! -z $1 ]; then echo "#define mini__signalfd $1" 
	else echo  "#define mini__signalfd _signalfd"
	fi
}
mini_eprintf(){ 
  if [ ! -z $1 ]; then echo "#define mini_eprintf $1" 
	else echo  "#define mini_eprintf eprintf"
	fi
}
mini_chdir(){ 
  if [ ! -z $1 ]; then echo "#define mini_chdir $1" 
	else echo  "#define mini_chdir chdir"
	fi
}
mini_mremap(){ 
  if [ ! -z $1 ]; then echo "#define mini_mremap $1" 
	else echo  "#define mini_mremap mremap"
	fi
}
mini_vexec(){ 
  if [ ! -z $1 ]; then echo "#define mini_vexec $1" 
	else echo  "#define mini_vexec vexec"
	fi
}
mini___sysctl(){ 
  if [ ! -z $1 ]; then echo "#define mini___sysctl $1" 
	else echo  "#define mini___sysctl __sysctl"
	fi
}
mini_sbrk(){ 
  if [ ! -z $1 ]; then echo "#define mini_sbrk $1" 
	else echo  "#define mini_sbrk sbrk"
	fi
}
mini_sigsuspend(){ 
  if [ ! -z $1 ]; then echo "#define mini_sigsuspend $1" 
	else echo  "#define mini_sigsuspend sigsuspend"
	fi
}
mini__read(){ 
  if [ ! -z $1 ]; then echo "#define mini__read $1" 
	else echo  "#define mini__read _read"
	fi
}
mini__setitimer(){ 
  if [ ! -z $1 ]; then echo "#define mini__setitimer $1" 
	else echo  "#define mini__setitimer _setitimer"
	fi
}
mini_vfork(){ 
  if [ ! -z $1 ]; then echo "#define mini_vfork $1" 
	else echo  "#define mini_vfork vfork"
	fi
}
mini_getgrouplist(){ 
  if [ ! -z $1 ]; then echo "#define mini_getgrouplist $1" 
	else echo  "#define mini_getgrouplist getgrouplist"
	fi
}
mini__ptrace(){ 
  if [ ! -z $1 ]; then echo "#define mini__ptrace $1" 
	else echo  "#define mini__ptrace _ptrace"
	fi
}
mini__readlink(){ 
  if [ ! -z $1 ]; then echo "#define mini__readlink $1" 
	else echo  "#define mini__readlink _readlink"
	fi
}
mini__getrlimit(){ 
  if [ ! -z $1 ]; then echo "#define mini__getrlimit $1" 
	else echo  "#define mini__getrlimit _getrlimit"
	fi
}
mini__clock_gettime(){ 
  if [ ! -z $1 ]; then echo "#define mini__clock_gettime $1" 
	else echo  "#define mini__clock_gettime _clock_gettime"
	fi
}
mini__unshare(){ 
  if [ ! -z $1 ]; then echo "#define mini__unshare $1" 
	else echo  "#define mini__unshare _unshare"
	fi
}
mini_verbose_errstr(){ 
  if [ ! -z $1 ]; then echo "#define mini_verbose_errstr $1" 
	else echo  "#define mini_verbose_errstr verbose_errstr"
	fi
}
mini_initgroups(){ 
  if [ ! -z $1 ]; then echo "#define mini_initgroups $1" 
	else echo  "#define mini_initgroups initgroups"
	fi
}
mini_getpwnam(){ 
  if [ ! -z $1 ]; then echo "#define mini_getpwnam $1" 
	else echo  "#define mini_getpwnam getpwnam"
	fi
}
mini_rewinddir(){ 
  if [ ! -z $1 ]; then echo "#define mini_rewinddir $1" 
	else echo  "#define mini_rewinddir rewinddir"
	fi
}
mini_setpwent(){ 
  if [ ! -z $1 ]; then echo "#define mini_setpwent $1" 
	else echo  "#define mini_setpwent setpwent"
	fi
}
mini__setpgid(){ 
  if [ ! -z $1 ]; then echo "#define mini__setpgid $1" 
	else echo  "#define mini__setpgid _setpgid"
	fi
}
mini_write(){ 
  if [ ! -z $1 ]; then echo "#define mini_write $1" 
	else echo  "#define mini_write write"
	fi
}
mini__vfork(){ 
  if [ ! -z $1 ]; then echo "#define mini__vfork $1" 
	else echo  "#define mini__vfork _vfork"
	fi
}
mini_dief_if(){ 
  if [ ! -z $1 ]; then echo "#define mini_dief_if $1" 
	else echo  "#define mini_dief_if dief_if"
	fi
}
mini__fchmodat(){ 
  if [ ! -z $1 ]; then echo "#define mini__fchmodat $1" 
	else echo  "#define mini__fchmodat _fchmodat"
	fi
}
mini_chown(){ 
  if [ ! -z $1 ]; then echo "#define mini_chown $1" 
	else echo  "#define mini_chown chown"
	fi
}
mini__timerfd_gettime(){ 
  if [ ! -z $1 ]; then echo "#define mini__timerfd_gettime $1" 
	else echo  "#define mini__timerfd_gettime _timerfd_gettime"
	fi
}
mini_itohex(){ 
  if [ ! -z $1 ]; then echo "#define mini_itohex $1" 
	else echo  "#define mini_itohex itohex"
	fi
}
mini_dprintf(){ 
  if [ ! -z $1 ]; then echo "#define mini_dprintf $1" 
	else echo  "#define mini_dprintf dprintf"
	fi
}
mini__getuid(){ 
  if [ ! -z $1 ]; then echo "#define mini__getuid $1" 
	else echo  "#define mini__getuid _getuid"
	fi
}
mini_eputs(){ 
  if [ ! -z $1 ]; then echo "#define mini_eputs $1" 
	else echo  "#define mini_eputs eputs"
	fi
}
mini_stat(){ 
  if [ ! -z $1 ]; then echo "#define mini_stat $1" 
	else echo  "#define mini_stat stat"
	fi
}
mini_atexit(){ 
  if [ ! -z $1 ]; then echo "#define mini_atexit $1" 
	else echo  "#define mini_atexit atexit"
	fi
}
mini__listen(){ 
  if [ ! -z $1 ]; then echo "#define mini__listen $1" 
	else echo  "#define mini__listen _listen"
	fi
}
mini__listxattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__listxattr $1" 
	else echo  "#define mini__listxattr _listxattr"
	fi
}
mini_atol(){ 
  if [ ! -z $1 ]; then echo "#define mini_atol $1" 
	else echo  "#define mini_atol atol"
	fi
}
mini__access(){ 
  if [ ! -z $1 ]; then echo "#define mini__access $1" 
	else echo  "#define mini__access _access"
	fi
}
mini_setpgid(){ 
  if [ ! -z $1 ]; then echo "#define mini_setpgid $1" 
	else echo  "#define mini_setpgid setpgid"
	fi
}
mini_scandir(){ 
  if [ ! -z $1 ]; then echo "#define mini_scandir $1" 
	else echo  "#define mini_scandir scandir"
	fi
}
mini__clock_settime(){ 
  if [ ! -z $1 ]; then echo "#define mini__clock_settime $1" 
	else echo  "#define mini__clock_settime _clock_settime"
	fi
}
mini_sys_brk(){ 
  if [ ! -z $1 ]; then echo "#define mini_sys_brk $1" 
	else echo  "#define mini_sys_brk sys_brk"
	fi
}
mini_qsort(){ 
  if [ ! -z $1 ]; then echo "#define mini_qsort $1" 
	else echo  "#define mini_qsort qsort"
	fi
}
mini_free(){ 
  if [ ! -z $1 ]; then echo "#define mini_free $1" 
	else echo  "#define mini_free free"
	fi
}
mini_kill(){ 
  if [ ! -z $1 ]; then echo "#define mini_kill $1" 
	else echo  "#define mini_kill kill"
	fi
}
mini_telldir(){ 
  if [ ! -z $1 ]; then echo "#define mini_telldir $1" 
	else echo  "#define mini_telldir telldir"
	fi
}
mini__die(){ 
  if [ ! -z $1 ]; then echo "#define mini__die $1" 
	else echo  "#define mini__die _die"
	fi
}
mini__getpriority(){ 
  if [ ! -z $1 ]; then echo "#define mini__getpriority $1" 
	else echo  "#define mini__getpriority _getpriority"
	fi
}
mini_prctl(){ 
  if [ ! -z $1 ]; then echo "#define mini_prctl $1" 
	else echo  "#define mini_prctl prctl"
	fi
}
mini_passwdfile_open(){ 
  if [ ! -z $1 ]; then echo "#define mini_passwdfile_open $1" 
	else echo  "#define mini_passwdfile_open passwdfile_open"
	fi
}
mini_execv(){ 
  if [ ! -z $1 ]; then echo "#define mini_execv $1" 
	else echo  "#define mini_execv execv"
	fi
}
mini_calloc(){ 
  if [ ! -z $1 ]; then echo "#define mini_calloc $1" 
	else echo  "#define mini_calloc calloc"
	fi
}
mini_ltodec(){ 
  if [ ! -z $1 ]; then echo "#define mini_ltodec $1" 
	else echo  "#define mini_ltodec ltodec"
	fi
}
mini_strtoll(){ 
  if [ ! -z $1 ]; then echo "#define mini_strtoll $1" 
	else echo  "#define mini_strtoll strtoll"
	fi
}
mini__process_vm_readv(){ 
  if [ ! -z $1 ]; then echo "#define mini__process_vm_readv $1" 
	else echo  "#define mini__process_vm_readv _process_vm_readv"
	fi
}
mini__getgroups(){ 
  if [ ! -z $1 ]; then echo "#define mini__getgroups $1" 
	else echo  "#define mini__getgroups _getgroups"
	fi
}
mini__sendmsg(){ 
  if [ ! -z $1 ]; then echo "#define mini__sendmsg $1" 
	else echo  "#define mini__sendmsg _sendmsg"
	fi
}
mini_isatty(){ 
  if [ ! -z $1 ]; then echo "#define mini_isatty $1" 
	else echo  "#define mini_isatty isatty"
	fi
}
mini_ewrites(){ 
  if [ ! -z $1 ]; then echo "#define mini_ewrites $1" 
	else echo  "#define mini_ewrites ewrites"
	fi
}
mini__epoll_ctl(){ 
  if [ ! -z $1 ]; then echo "#define mini__epoll_ctl $1" 
	else echo  "#define mini__epoll_ctl _epoll_ctl"
	fi
}
mini_mprotect(){ 
  if [ ! -z $1 ]; then echo "#define mini_mprotect $1" 
	else echo  "#define mini_mprotect mprotect"
	fi
}
mini_sigaction(){ 
  if [ ! -z $1 ]; then echo "#define mini_sigaction $1" 
	else echo  "#define mini_sigaction sigaction"
	fi
}
mini_posix_openpt(){ 
  if [ ! -z $1 ]; then echo "#define mini_posix_openpt $1" 
	else echo  "#define mini_posix_openpt posix_openpt"
	fi
}
mini_config(){ 
  if [ ! -z $1 ]; then echo "#define mini_config $1" 
	else echo  "#define mini_config config"
	fi
}
mini__ioprio_get(){ 
  if [ ! -z $1 ]; then echo "#define mini__ioprio_get $1" 
	else echo  "#define mini__ioprio_get _ioprio_get"
	fi
}
mini_mkdir(){ 
  if [ ! -z $1 ]; then echo "#define mini_mkdir $1" 
	else echo  "#define mini_mkdir mkdir"
	fi
}
mini__chown(){ 
  if [ ! -z $1 ]; then echo "#define mini__chown $1" 
	else echo  "#define mini__chown _chown"
	fi
}
mini_fwritesl(){ 
  if [ ! -z $1 ]; then echo "#define mini_fwritesl $1" 
	else echo  "#define mini_fwritesl fwritesl"
	fi
}
mini__mbind(){ 
  if [ ! -z $1 ]; then echo "#define mini__mbind $1" 
	else echo  "#define mini__mbind _mbind"
	fi
}
mini__symlink(){ 
  if [ ! -z $1 ]; then echo "#define mini__symlink $1" 
	else echo  "#define mini__symlink _symlink"
	fi
}
mini__splice(){ 
  if [ ! -z $1 ]; then echo "#define mini__splice $1" 
	else echo  "#define mini__splice _splice"
	fi
}
mini__fgetxattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__fgetxattr $1" 
	else echo  "#define mini__fgetxattr _fgetxattr"
	fi
}
mini__setresgid(){ 
  if [ ! -z $1 ]; then echo "#define mini__setresgid $1" 
	else echo  "#define mini__setresgid _setresgid"
	fi
}
mini__socket(){ 
  if [ ! -z $1 ]; then echo "#define mini__socket $1" 
	else echo  "#define mini__socket _socket"
	fi
}
mini_setenv(){ 
  if [ ! -z $1 ]; then echo "#define mini_setenv $1" 
	else echo  "#define mini_setenv setenv"
	fi
}
mini__sched_setparam(){ 
  if [ ! -z $1 ]; then echo "#define mini__sched_setparam $1" 
	else echo  "#define mini__sched_setparam _sched_setparam"
	fi
}
mini__keyctl(){ 
  if [ ! -z $1 ]; then echo "#define mini__keyctl $1" 
	else echo  "#define mini__keyctl _keyctl"
	fi
}
mini_read(){ 
  if [ ! -z $1 ]; then echo "#define mini_read $1" 
	else echo  "#define mini_read read"
	fi
}
mini_getuid(){ 
  if [ ! -z $1 ]; then echo "#define mini_getuid $1" 
	else echo  "#define mini_getuid getuid"
	fi
}
mini__msgget(){ 
  if [ ! -z $1 ]; then echo "#define mini__msgget $1" 
	else echo  "#define mini__msgget _msgget"
	fi
}
mini__mq_timedreceive(){ 
  if [ ! -z $1 ]; then echo "#define mini__mq_timedreceive $1" 
	else echo  "#define mini__mq_timedreceive _mq_timedreceive"
	fi
}
mini_putchar(){ 
  if [ ! -z $1 ]; then echo "#define mini_putchar $1" 
	else echo  "#define mini_putchar putchar"
	fi
}
mini_atoi(){ 
  if [ ! -z $1 ]; then echo "#define mini_atoi $1" 
	else echo  "#define mini_atoi atoi"
	fi
}
mini_inotify_rm_watch(){ 
  if [ ! -z $1 ]; then echo "#define mini_inotify_rm_watch $1" 
	else echo  "#define mini_inotify_rm_watch inotify_rm_watch"
	fi
}
mini_execveat(){ 
  if [ ! -z $1 ]; then echo "#define mini_execveat $1" 
	else echo  "#define mini_execveat execveat"
	fi
}
mini__mknod(){ 
  if [ ! -z $1 ]; then echo "#define mini__mknod $1" 
	else echo  "#define mini__mknod _mknod"
	fi
}
mini__shmget(){ 
  if [ ! -z $1 ]; then echo "#define mini__shmget $1" 
	else echo  "#define mini__shmget _shmget"
	fi
}
mini__sched_getaffinity(){ 
  if [ ! -z $1 ]; then echo "#define mini__sched_getaffinity $1" 
	else echo  "#define mini__sched_getaffinity _sched_getaffinity"
	fi
}
mini_uname(){ 
  if [ ! -z $1 ]; then echo "#define mini_uname $1" 
	else echo  "#define mini_uname uname"
	fi
}
mini__pread64(){ 
  if [ ! -z $1 ]; then echo "#define mini__pread64 $1" 
	else echo  "#define mini__pread64 _pread64"
	fi
}
mini__sethostname(){ 
  if [ ! -z $1 ]; then echo "#define mini__sethostname $1" 
	else echo  "#define mini__sethostname _sethostname"
	fi
}
mini_clone_t(){ 
  if [ ! -z $1 ]; then echo "#define mini_clone_t $1" 
	else echo  "#define mini_clone_t clone_t"
	fi
}
mini_mount(){ 
  if [ ! -z $1 ]; then echo "#define mini_mount $1" 
	else echo  "#define mini_mount mount"
	fi
}
mini__match_ext2(){ 
  if [ ! -z $1 ]; then echo "#define mini__match_ext2 $1" 
	else echo  "#define mini__match_ext2 _match_ext2"
	fi
}
mini_strtol(){ 
  if [ ! -z $1 ]; then echo "#define mini_strtol $1" 
	else echo  "#define mini_strtol strtol"
	fi
}
mini_setbuf(){ 
  if [ ! -z $1 ]; then echo "#define mini_setbuf $1" 
	else echo  "#define mini_setbuf setbuf"
	fi
}
mini_system(){ 
  if [ ! -z $1 ]; then echo "#define mini_system $1" 
	else echo  "#define mini_system system"
	fi
}
mini_environ(){ 
  if [ ! -z $1 ]; then echo "#define mini_environ $1" 
	else echo  "#define mini_environ environ"
	fi
}
mini_getbrk(){ 
  if [ ! -z $1 ]; then echo "#define mini_getbrk $1" 
	else echo  "#define mini_getbrk getbrk"
	fi
}
mini__ustat(){ 
  if [ ! -z $1 ]; then echo "#define mini__ustat $1" 
	else echo  "#define mini__ustat _ustat"
	fi
}
mini__socketpair(){ 
  if [ ! -z $1 ]; then echo "#define mini__socketpair $1" 
	else echo  "#define mini__socketpair _socketpair"
	fi
}
mini_freopen(){ 
  if [ ! -z $1 ]; then echo "#define mini_freopen $1" 
	else echo  "#define mini_freopen freopen"
	fi
}
mini__sched_yield(){ 
  if [ ! -z $1 ]; then echo "#define mini__sched_yield $1" 
	else echo  "#define mini__sched_yield _sched_yield"
	fi
}
mini__fchown(){ 
  if [ ! -z $1 ]; then echo "#define mini__fchown $1" 
	else echo  "#define mini__fchown _fchown"
	fi
}
mini__sched_setscheduler(){ 
  if [ ! -z $1 ]; then echo "#define mini__sched_setscheduler $1" 
	else echo  "#define mini__sched_setscheduler _sched_setscheduler"
	fi
}
mini_ftell(){ 
  if [ ! -z $1 ]; then echo "#define mini_ftell $1" 
	else echo  "#define mini_ftell ftell"
	fi
}
mini_getsockopt(){ 
  if [ ! -z $1 ]; then echo "#define mini_getsockopt $1" 
	else echo  "#define mini_getsockopt getsockopt"
	fi
}
mini_itodec(){ 
  if [ ! -z $1 ]; then echo "#define mini_itodec $1" 
	else echo  "#define mini_itodec itodec"
	fi
}
mini__kexec_file_load(){ 
  if [ ! -z $1 ]; then echo "#define mini__kexec_file_load $1" 
	else echo  "#define mini__kexec_file_load _kexec_file_load"
	fi
}
mini__mmap(){ 
  if [ ! -z $1 ]; then echo "#define mini__mmap $1" 
	else echo  "#define mini__mmap _mmap"
	fi
}
mini__llistxattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__llistxattr $1" 
	else echo  "#define mini__llistxattr _llistxattr"
	fi
}
mini_perror(){ 
  if [ ! -z $1 ]; then echo "#define mini_perror $1" 
	else echo  "#define mini_perror perror"
	fi
}
mini_swap(){ 
  if [ ! -z $1 ]; then echo "#define mini_swap $1" 
	else echo  "#define mini_swap swap"
	fi
}
mini_putc(){ 
  if [ ! -z $1 ]; then echo "#define mini_putc $1" 
	else echo  "#define mini_putc putc"
	fi
}
mini__kcmp(){ 
  if [ ! -z $1 ]; then echo "#define mini__kcmp $1" 
	else echo  "#define mini__kcmp _kcmp"
	fi
}
mini_umask(){ 
  if [ ! -z $1 ]; then echo "#define mini_umask $1" 
	else echo  "#define mini_umask umask"
	fi
}
mini_match(){ 
  if [ ! -z $1 ]; then echo "#define mini_match $1" 
	else echo  "#define mini_match match"
	fi
}
mini_itooct(){ 
  if [ ! -z $1 ]; then echo "#define mini_itooct $1" 
	else echo  "#define mini_itooct itooct"
	fi
}
mini__add_key(){ 
  if [ ! -z $1 ]; then echo "#define mini__add_key $1" 
	else echo  "#define mini__add_key _add_key"
	fi
}
mini__flock(){ 
  if [ ! -z $1 ]; then echo "#define mini__flock $1" 
	else echo  "#define mini__flock _flock"
	fi
}
mini_exit_errno(){ 
  if [ ! -z $1 ]; then echo "#define mini_exit_errno $1" 
	else echo  "#define mini_exit_errno exit_errno"
	fi
}
mini_unlockpt(){ 
  if [ ! -z $1 ]; then echo "#define mini_unlockpt $1" 
	else echo  "#define mini_unlockpt unlockpt"
	fi
}
mini__getresgid(){ 
  if [ ! -z $1 ]; then echo "#define mini__getresgid $1" 
	else echo  "#define mini__getresgid _getresgid"
	fi
}
mini_endpwent(){ 
  if [ ! -z $1 ]; then echo "#define mini_endpwent $1" 
	else echo  "#define mini_endpwent endpwent"
	fi
}
mini__sched_setattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__sched_setattr $1" 
	else echo  "#define mini__sched_setattr _sched_setattr"
	fi
}
mini_dirname(){ 
  if [ ! -z $1 ]; then echo "#define mini_dirname $1" 
	else echo  "#define mini_dirname dirname"
	fi
}
mini__setns(){ 
  if [ ! -z $1 ]; then echo "#define mini__setns $1" 
	else echo  "#define mini__setns _setns"
	fi
}
mini_fchmod(){ 
  if [ ! -z $1 ]; then echo "#define mini_fchmod $1" 
	else echo  "#define mini_fchmod fchmod"
	fi
}
mini_vsnprintf(){ 
  if [ ! -z $1 ]; then echo "#define mini_vsnprintf $1" 
	else echo  "#define mini_vsnprintf vsnprintf"
	fi
}
mini_link(){ 
  if [ ! -z $1 ]; then echo "#define mini_link $1" 
	else echo  "#define mini_link link"
	fi
}
mini_malloc_brk(){ 
  if [ ! -z $1 ]; then echo "#define mini_malloc_brk $1" 
	else echo  "#define mini_malloc_brk malloc_brk"
	fi
}
mini__sync(){ 
  if [ ! -z $1 ]; then echo "#define mini__sync $1" 
	else echo  "#define mini__sync _sync"
	fi
}
mini__swapon(){ 
  if [ ! -z $1 ]; then echo "#define mini__swapon $1" 
	else echo  "#define mini__swapon _swapon"
	fi
}
mini__msgctl(){ 
  if [ ! -z $1 ]; then echo "#define mini__msgctl $1" 
	else echo  "#define mini__msgctl _msgctl"
	fi
}
mini_basename(){ 
  if [ ! -z $1 ]; then echo "#define mini_basename $1" 
	else echo  "#define mini_basename basename"
	fi
}
mini_select(){ 
  if [ ! -z $1 ]; then echo "#define mini_select $1" 
	else echo  "#define mini_select select"
	fi
}
mini__fdatasync(){ 
  if [ ! -z $1 ]; then echo "#define mini__fdatasync $1" 
	else echo  "#define mini__fdatasync _fdatasync"
	fi
}
mini__capset(){ 
  if [ ! -z $1 ]; then echo "#define mini__capset $1" 
	else echo  "#define mini__capset _capset"
	fi
}
mini__request_key(){ 
  if [ ! -z $1 ]; then echo "#define mini__request_key $1" 
	else echo  "#define mini__request_key _request_key"
	fi
}
mini__newfstatat(){ 
  if [ ! -z $1 ]; then echo "#define mini__newfstatat $1" 
	else echo  "#define mini__newfstatat _newfstatat"
	fi
}
mini__bind(){ 
  if [ ! -z $1 ]; then echo "#define mini__bind $1" 
	else echo  "#define mini__bind _bind"
	fi
}
mini__getrusage(){ 
  if [ ! -z $1 ]; then echo "#define mini__getrusage $1" 
	else echo  "#define mini__getrusage _getrusage"
	fi
}
mini__nanosleep(){ 
  if [ ! -z $1 ]; then echo "#define mini__nanosleep $1" 
	else echo  "#define mini__nanosleep _nanosleep"
	fi
}
mini_flock(){ 
  if [ ! -z $1 ]; then echo "#define mini_flock $1" 
	else echo  "#define mini_flock flock"
	fi
}
mini_strstr(){ 
  if [ ! -z $1 ]; then echo "#define mini_strstr $1" 
	else echo  "#define mini_strstr strstr"
	fi
}
mini_raise(){ 
  if [ ! -z $1 ]; then echo "#define mini_raise $1" 
	else echo  "#define mini_raise raise"
	fi
}
mini__sigaltstack(){ 
  if [ ! -z $1 ]; then echo "#define mini__sigaltstack $1" 
	else echo  "#define mini__sigaltstack _sigaltstack"
	fi
}
mini__mq_notify(){ 
  if [ ! -z $1 ]; then echo "#define mini__mq_notify $1" 
	else echo  "#define mini__mq_notify _mq_notify"
	fi
}
mini__epoll_create1(){ 
  if [ ! -z $1 ]; then echo "#define mini__epoll_create1 $1" 
	else echo  "#define mini__epoll_create1 _epoll_create1"
	fi
}
mini__setdomainname(){ 
  if [ ! -z $1 ]; then echo "#define mini__setdomainname $1" 
	else echo  "#define mini__setdomainname _setdomainname"
	fi
}
mini__linkat(){ 
  if [ ! -z $1 ]; then echo "#define mini__linkat $1" 
	else echo  "#define mini__linkat _linkat"
	fi
}
mini__shmctl(){ 
  if [ ! -z $1 ]; then echo "#define mini__shmctl $1" 
	else echo  "#define mini__shmctl _shmctl"
	fi
}
mini_strrchr(){ 
  if [ ! -z $1 ]; then echo "#define mini_strrchr $1" 
	else echo  "#define mini_strrchr strrchr"
	fi
}
mini__fsync(){ 
  if [ ! -z $1 ]; then echo "#define mini__fsync $1" 
	else echo  "#define mini__fsync _fsync"
	fi
}
mini_closedir(){ 
  if [ ! -z $1 ]; then echo "#define mini_closedir $1" 
	else echo  "#define mini_closedir closedir"
	fi
}
mini_getpwent(){ 
  if [ ! -z $1 ]; then echo "#define mini_getpwent $1" 
	else echo  "#define mini_getpwent getpwent"
	fi
}
mini_scandir_bufsize(){ 
  if [ ! -z $1 ]; then echo "#define mini_scandir_bufsize $1" 
	else echo  "#define mini_scandir_bufsize scandir_bufsize"
	fi
}
mini_clearerr(){ 
  if [ ! -z $1 ]; then echo "#define mini_clearerr $1" 
	else echo  "#define mini_clearerr clearerr"
	fi
}
mini_dirbuf_malloc(){ 
  if [ ! -z $1 ]; then echo "#define mini_dirbuf_malloc $1" 
	else echo  "#define mini_dirbuf_malloc dirbuf_malloc"
	fi
}
mini_dtodec(){ 
  if [ ! -z $1 ]; then echo "#define mini_dtodec $1" 
	else echo  "#define mini_dtodec dtodec"
	fi
}
mini__setfsgid(){ 
  if [ ! -z $1 ]; then echo "#define mini__setfsgid $1" 
	else echo  "#define mini__setfsgid _setfsgid"
	fi
}
mini_strerror(){ 
  if [ ! -z $1 ]; then echo "#define mini_strerror $1" 
	else echo  "#define mini_strerror strerror"
	fi
}
mini_fwrites(){ 
  if [ ! -z $1 ]; then echo "#define mini_fwrites $1" 
	else echo  "#define mini_fwrites fwrites"
	fi
}
mini__setpriority(){ 
  if [ ! -z $1 ]; then echo "#define mini__setpriority $1" 
	else echo  "#define mini__setpriority _setpriority"
	fi
}
mini_strncpy(){ 
  if [ ! -z $1 ]; then echo "#define mini_strncpy $1" 
	else echo  "#define mini_strncpy strncpy"
	fi
}
mini__exit(){ 
  if [ ! -z $1 ]; then echo "#define mini__exit $1" 
	else echo  "#define mini__exit _exit"
	fi
}
mini_printfs(){ 
  if [ ! -z $1 ]; then echo "#define mini_printfs $1" 
	else echo  "#define mini_printfs printfs"
	fi
}
mini_memcmp(){ 
  if [ ! -z $1 ]; then echo "#define mini_memcmp $1" 
	else echo  "#define mini_memcmp memcmp"
	fi
}
mini_vfprintf(){ 
  if [ ! -z $1 ]; then echo "#define mini_vfprintf $1" 
	else echo  "#define mini_vfprintf vfprintf"
	fi
}
mini__getdents64(){ 
  if [ ! -z $1 ]; then echo "#define mini__getdents64 $1" 
	else echo  "#define mini__getdents64 _getdents64"
	fi
}
mini__rt_sigqueueinfo(){ 
  if [ ! -z $1 ]; then echo "#define mini__rt_sigqueueinfo $1" 
	else echo  "#define mini__rt_sigqueueinfo _rt_sigqueueinfo"
	fi
}
mini__move_pages(){ 
  if [ ! -z $1 ]; then echo "#define mini__move_pages $1" 
	else echo  "#define mini__move_pages _move_pages"
	fi
}
mini_htons(){ 
  if [ ! -z $1 ]; then echo "#define mini_htons $1" 
	else echo  "#define mini_htons htons"
	fi
}
mini__shmat(){ 
  if [ ! -z $1 ]; then echo "#define mini__shmat $1" 
	else echo  "#define mini__shmat _shmat"
	fi
}
mini_ewritesl(){ 
  if [ ! -z $1 ]; then echo "#define mini_ewritesl $1" 
	else echo  "#define mini_ewritesl ewritesl"
	fi
}
mini_shortcolornames(){ 
  if [ ! -z $1 ]; then echo "#define mini_shortcolornames $1" 
	else echo  "#define mini_shortcolornames shortcolornames"
	fi
}
mini_optimization_fence(){ 
  if [ ! -z $1 ]; then echo "#define mini_optimization_fence $1" 
	else echo  "#define mini_optimization_fence optimization_fence"
	fi
}
mini__futex(){ 
  if [ ! -z $1 ]; then echo "#define mini__futex $1" 
	else echo  "#define mini__futex _futex"
	fi
}
mini__epoll_wait(){ 
  if [ ! -z $1 ]; then echo "#define mini__epoll_wait $1" 
	else echo  "#define mini__epoll_wait _epoll_wait"
	fi
}
mini_rt_sigaction(){ 
  if [ ! -z $1 ]; then echo "#define mini_rt_sigaction $1" 
	else echo  "#define mini_rt_sigaction rt_sigaction"
	fi
}
mini_strcat(){ 
  if [ ! -z $1 ]; then echo "#define mini_strcat $1" 
	else echo  "#define mini_strcat strcat"
	fi
}
mini__msgrcv(){ 
  if [ ! -z $1 ]; then echo "#define mini__msgrcv $1" 
	else echo  "#define mini__msgrcv _msgrcv"
	fi
}
mini__match(){ 
  if [ ! -z $1 ]; then echo "#define mini__match $1" 
	else echo  "#define mini__match _match"
	fi
}
mini_bsd_cksumblock(){ 
  if [ ! -z $1 ]; then echo "#define mini_bsd_cksumblock $1" 
	else echo  "#define mini_bsd_cksumblock bsd_cksumblock"
	fi
}
mini__rt_sigreturn(){ 
  if [ ! -z $1 ]; then echo "#define mini__rt_sigreturn $1" 
	else echo  "#define mini__rt_sigreturn _rt_sigreturn"
	fi
}
mini__iopl(){ 
  if [ ! -z $1 ]; then echo "#define mini__iopl $1" 
	else echo  "#define mini__iopl _iopl"
	fi
}
mini_stplcpy(){ 
  if [ ! -z $1 ]; then echo "#define mini_stplcpy $1" 
	else echo  "#define mini_stplcpy stplcpy"
	fi
}
mini__unlinkat(){ 
  if [ ! -z $1 ]; then echo "#define mini__unlinkat $1" 
	else echo  "#define mini__unlinkat _unlinkat"
	fi
}
mini__select(){ 
  if [ ! -z $1 ]; then echo "#define mini__select $1" 
	else echo  "#define mini__select _select"
	fi
}
mini_unlink(){ 
  if [ ! -z $1 ]; then echo "#define mini_unlink $1" 
	else echo  "#define mini_unlink unlink"
	fi
}
mini__umount2(){ 
  if [ ! -z $1 ]; then echo "#define mini__umount2 $1" 
	else echo  "#define mini__umount2 _umount2"
	fi
}
mini__fanotify_init(){ 
  if [ ! -z $1 ]; then echo "#define mini__fanotify_init $1" 
	else echo  "#define mini__fanotify_init _fanotify_init"
	fi
}
mini__renameat(){ 
  if [ ! -z $1 ]; then echo "#define mini__renameat $1" 
	else echo  "#define mini__renameat _renameat"
	fi
}
mini_execve(){ 
  if [ ! -z $1 ]; then echo "#define mini_execve $1" 
	else echo  "#define mini_execve execve"
	fi
}
mini__utimes(){ 
  if [ ! -z $1 ]; then echo "#define mini__utimes $1" 
	else echo  "#define mini__utimes _utimes"
	fi
}
mini__renameat2(){ 
  if [ ! -z $1 ]; then echo "#define mini__renameat2 $1" 
	else echo  "#define mini__renameat2 _renameat2"
	fi
}
mini__mknodat(){ 
  if [ ! -z $1 ]; then echo "#define mini__mknodat $1" 
	else echo  "#define mini__mknodat _mknodat"
	fi
}
mini_alphasort(){ 
  if [ ! -z $1 ]; then echo "#define mini_alphasort $1" 
	else echo  "#define mini_alphasort alphasort"
	fi
}
mini_time(){ 
  if [ ! -z $1 ]; then echo "#define mini_time $1" 
	else echo  "#define mini_time time"
	fi
}
mini_pipe(){ 
  if [ ! -z $1 ]; then echo "#define mini_pipe $1" 
	else echo  "#define mini_pipe pipe"
	fi
}
mini_ansicolors(){ 
  if [ ! -z $1 ]; then echo "#define mini_ansicolors $1" 
	else echo  "#define mini_ansicolors ansicolors"
	fi
}
mini_sigfillset(){ 
  if [ ! -z $1 ]; then echo "#define mini_sigfillset $1" 
	else echo  "#define mini_sigfillset sigfillset"
	fi
}
mini__setgroups(){ 
  if [ ! -z $1 ]; then echo "#define mini__setgroups $1" 
	else echo  "#define mini__setgroups _setgroups"
	fi
}
mini_sprintf(){ 
  if [ ! -z $1 ]; then echo "#define mini_sprintf $1" 
	else echo  "#define mini_sprintf sprintf"
	fi
}
mini_group_write(){ 
  if [ ! -z $1 ]; then echo "#define mini_group_write $1" 
	else echo  "#define mini_group_write group_write"
	fi
}
mini_memcpy(){ 
  if [ ! -z $1 ]; then echo "#define mini_memcpy $1" 
	else echo  "#define mini_memcpy memcpy"
	fi
}
mini__munlock(){ 
  if [ ! -z $1 ]; then echo "#define mini__munlock $1" 
	else echo  "#define mini__munlock _munlock"
	fi
}
mini__kexec_load(){ 
  if [ ! -z $1 ]; then echo "#define mini__kexec_load $1" 
	else echo  "#define mini__kexec_load _kexec_load"
	fi
}
mini_where(){ 
  if [ ! -z $1 ]; then echo "#define mini_where $1" 
	else echo  "#define mini_where where"
	fi
}
mini_getpgrp(){ 
  if [ ! -z $1 ]; then echo "#define mini_getpgrp $1" 
	else echo  "#define mini_getpgrp getpgrp"
	fi
}
mini__mq_unlink(){ 
  if [ ! -z $1 ]; then echo "#define mini__mq_unlink $1" 
	else echo  "#define mini__mq_unlink _mq_unlink"
	fi
}
mini__msgsnd(){ 
  if [ ! -z $1 ]; then echo "#define mini__msgsnd $1" 
	else echo  "#define mini__msgsnd _msgsnd"
	fi
}
mini__setrlimit(){ 
  if [ ! -z $1 ]; then echo "#define mini__setrlimit $1" 
	else echo  "#define mini__setrlimit _setrlimit"
	fi
}
mini_sync(){ 
  if [ ! -z $1 ]; then echo "#define mini_sync $1" 
	else echo  "#define mini_sync sync"
	fi
}
mini__sysfs(){ 
  if [ ! -z $1 ]; then echo "#define mini__sysfs $1" 
	else echo  "#define mini__sysfs _sysfs"
	fi
}
mini_snprintf(){ 
  if [ ! -z $1 ]; then echo "#define mini_snprintf $1" 
	else echo  "#define mini_snprintf snprintf"
	fi
}
mini__getitimer(){ 
  if [ ! -z $1 ]; then echo "#define mini__getitimer $1" 
	else echo  "#define mini__getitimer _getitimer"
	fi
}
mini__setfsuid(){ 
  if [ ! -z $1 ]; then echo "#define mini__setfsuid $1" 
	else echo  "#define mini__setfsuid _setfsuid"
	fi
}
mini_fexecve(){ 
  if [ ! -z $1 ]; then echo "#define mini_fexecve $1" 
	else echo  "#define mini_fexecve fexecve"
	fi
}
mini_verbose_errstr2(){ 
  if [ ! -z $1 ]; then echo "#define mini_verbose_errstr2 $1" 
	else echo  "#define mini_verbose_errstr2 verbose_errstr2"
	fi
}
mini_puts(){ 
  if [ ! -z $1 ]; then echo "#define mini_puts $1" 
	else echo  "#define mini_puts puts"
	fi
}
mini__adjtimex(){ 
  if [ ! -z $1 ]; then echo "#define mini__adjtimex $1" 
	else echo  "#define mini__adjtimex _adjtimex"
	fi
}
mini_fputc(){ 
  if [ ! -z $1 ]; then echo "#define mini_fputc $1" 
	else echo  "#define mini_fputc fputc"
	fi
}
mini_inotify_add_watch(){ 
  if [ ! -z $1 ]; then echo "#define mini_inotify_add_watch $1" 
	else echo  "#define mini_inotify_add_watch inotify_add_watch"
	fi
}
mini__link(){ 
  if [ ! -z $1 ]; then echo "#define mini__link $1" 
	else echo  "#define mini__link _link"
	fi
}
mini_def(){ 
  if [ ! -z $1 ]; then echo "#define mini_def $1" 
	else echo  "#define mini_def def"
	fi
}
mini_execvp(){ 
  if [ ! -z $1 ]; then echo "#define mini_execvp $1" 
	else echo  "#define mini_execvp execvp"
	fi
}
mini__syncfs(){ 
  if [ ! -z $1 ]; then echo "#define mini__syncfs $1" 
	else echo  "#define mini__syncfs _syncfs"
	fi
}
mini_fputs(){ 
  if [ ! -z $1 ]; then echo "#define mini_fputs $1" 
	else echo  "#define mini_fputs fputs"
	fi
}
mini__prctl(){ 
  if [ ! -z $1 ]; then echo "#define mini__prctl $1" 
	else echo  "#define mini__prctl _prctl"
	fi
}
mini_brk(){ 
  if [ ! -z $1 ]; then echo "#define mini_brk $1" 
	else echo  "#define mini_brk brk"
	fi
}
mini__setuid(){ 
  if [ ! -z $1 ]; then echo "#define mini__setuid $1" 
	else echo  "#define mini__setuid _setuid"
	fi
}
mini_map_protected(){ 
  if [ ! -z $1 ]; then echo "#define mini_map_protected $1" 
	else echo  "#define mini_map_protected map_protected"
	fi
}
mini_opendir(){ 
  if [ ! -z $1 ]; then echo "#define mini_opendir $1" 
	else echo  "#define mini_opendir opendir"
	fi
}
mini__mlock(){ 
  if [ ! -z $1 ]; then echo "#define mini__mlock $1" 
	else echo  "#define mini__mlock _mlock"
	fi
}
mini__init_module(){ 
  if [ ! -z $1 ]; then echo "#define mini__init_module $1" 
	else echo  "#define mini__init_module _init_module"
	fi
}
mini_fprintf(){ 
  if [ ! -z $1 ]; then echo "#define mini_fprintf $1" 
	else echo  "#define mini_fprintf fprintf"
	fi
}
mini__getegid(){ 
  if [ ! -z $1 ]; then echo "#define mini__getegid $1" 
	else echo  "#define mini__getegid _getegid"
	fi
}
mini_rand(){ 
  if [ ! -z $1 ]; then echo "#define mini_rand $1" 
	else echo  "#define mini_rand rand"
	fi
}
mini_dies_if(){ 
  if [ ! -z $1 ]; then echo "#define mini_dies_if $1" 
	else echo  "#define mini_dies_if dies_if"
	fi
}
mini__getpgid(){ 
  if [ ! -z $1 ]; then echo "#define mini__getpgid $1" 
	else echo  "#define mini__getpgid _getpgid"
	fi
}
mini__lstat(){ 
  if [ ! -z $1 ]; then echo "#define mini__lstat $1" 
	else echo  "#define mini__lstat _lstat"
	fi
}
mini__rt_sigtimedwait(){ 
  if [ ! -z $1 ]; then echo "#define mini__rt_sigtimedwait $1" 
	else echo  "#define mini__rt_sigtimedwait _rt_sigtimedwait"
	fi
}
mini__timerfd_create(){ 
  if [ ! -z $1 ]; then echo "#define mini__timerfd_create $1" 
	else echo  "#define mini__timerfd_create _timerfd_create"
	fi
}
mini__ioctl(){ 
  if [ ! -z $1 ]; then echo "#define mini__ioctl $1" 
	else echo  "#define mini__ioctl _ioctl"
	fi
}
mini_fcntl(){ 
  if [ ! -z $1 ]; then echo "#define mini_fcntl $1" 
	else echo  "#define mini_fcntl fcntl"
	fi
}
mini_ptsname_r(){ 
  if [ ! -z $1 ]; then echo "#define mini_ptsname_r $1" 
	else echo  "#define mini_ptsname_r ptsname_r"
	fi
}
mini__itohex(){ 
  if [ ! -z $1 ]; then echo "#define mini__itohex $1" 
	else echo  "#define mini__itohex _itohex"
	fi
}
mini__sysinfo(){ 
  if [ ! -z $1 ]; then echo "#define mini__sysinfo $1" 
	else echo  "#define mini__sysinfo _sysinfo"
	fi
}
mini__semctl(){ 
  if [ ! -z $1 ]; then echo "#define mini__semctl $1" 
	else echo  "#define mini__semctl _semctl"
	fi
}
mini__gettimeofday(){ 
  if [ ! -z $1 ]; then echo "#define mini__gettimeofday $1" 
	else echo  "#define mini__gettimeofday _gettimeofday"
	fi
}
mini_malloc(){ 
  if [ ! -z $1 ]; then echo "#define mini_malloc $1" 
	else echo  "#define mini_malloc malloc"
	fi
}
mini__finit_module(){ 
  if [ ! -z $1 ]; then echo "#define mini__finit_module $1" 
	else echo  "#define mini__finit_module _finit_module"
	fi
}
mini_sigaddset(){ 
  if [ ! -z $1 ]; then echo "#define mini_sigaddset $1" 
	else echo  "#define mini_sigaddset sigaddset"
	fi
}
mini_vexec_q(){ 
  if [ ! -z $1 ]; then echo "#define mini_vexec_q $1" 
	else echo  "#define mini_vexec_q vexec_q"
	fi
}
mini_strcasecmp(){ 
  if [ ! -z $1 ]; then echo "#define mini_strcasecmp $1" 
	else echo  "#define mini_strcasecmp strcasecmp"
	fi
}
mini_strdup(){ 
  if [ ! -z $1 ]; then echo "#define mini_strdup $1" 
	else echo  "#define mini_strdup strdup"
	fi
}
mini_fork(){ 
  if [ ! -z $1 ]; then echo "#define mini_fork $1" 
	else echo  "#define mini_fork fork"
	fi
}
mini_rt_sigsuspend(){ 
  if [ ! -z $1 ]; then echo "#define mini_rt_sigsuspend $1" 
	else echo  "#define mini_rt_sigsuspend rt_sigsuspend"
	fi
}
mini__utime(){ 
  if [ ! -z $1 ]; then echo "#define mini__utime $1" 
	else echo  "#define mini__utime _utime"
	fi
}
mini_sdbm_hash(){ 
  if [ ! -z $1 ]; then echo "#define mini_sdbm_hash $1" 
	else echo  "#define mini_sdbm_hash sdbm_hash"
	fi
}
mini_tcsetattr(){ 
  if [ ! -z $1 ]; then echo "#define mini_tcsetattr $1" 
	else echo  "#define mini_tcsetattr tcsetattr"
	fi
}
mini_setbrk(){ 
  if [ ! -z $1 ]; then echo "#define mini_setbrk $1" 
	else echo  "#define mini_setbrk setbrk"
	fi
}
mini__sendto(){ 
  if [ ! -z $1 ]; then echo "#define mini__sendto $1" 
	else echo  "#define mini__sendto _sendto"
	fi
}
mini__inotify_rm_watch(){ 
  if [ ! -z $1 ]; then echo "#define mini__inotify_rm_watch $1" 
	else echo  "#define mini__inotify_rm_watch _inotify_rm_watch"
	fi
}
mini_sigismember(){ 
  if [ ! -z $1 ]; then echo "#define mini_sigismember $1" 
	else echo  "#define mini_sigismember sigismember"
	fi
}
mini__lsetxattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__lsetxattr $1" 
	else echo  "#define mini__lsetxattr _lsetxattr"
	fi
}
mini__truncate(){ 
  if [ ! -z $1 ]; then echo "#define mini__truncate $1" 
	else echo  "#define mini__truncate _truncate"
	fi
}
mini_fwrite(){ 
  if [ ! -z $1 ]; then echo "#define mini_fwrite $1" 
	else echo  "#define mini_fwrite fwrite"
	fi
}
mini_setuid(){ 
  if [ ! -z $1 ]; then echo "#define mini_setuid $1" 
	else echo  "#define mini_setuid setuid"
	fi
}
mini_print(){ 
  if [ ! -z $1 ]; then echo "#define mini_print $1" 
	else echo  "#define mini_print print"
	fi
}
mini_die(){ 
  if [ ! -z $1 ]; then echo "#define mini_die $1" 
	else echo  "#define mini_die die"
	fi
}
mini__setgid(){ 
  if [ ! -z $1 ]; then echo "#define mini__setgid $1" 
	else echo  "#define mini__setgid _setgid"
	fi
}
mini_ungetc(){ 
  if [ ! -z $1 ]; then echo "#define mini_ungetc $1" 
	else echo  "#define mini_ungetc ungetc"
	fi
}
mini_free_brk(){ 
  if [ ! -z $1 ]; then echo "#define mini_free_brk $1" 
	else echo  "#define mini_free_brk free_brk"
	fi
}
mini_getenv(){ 
  if [ ! -z $1 ]; then echo "#define mini_getenv $1" 
	else echo  "#define mini_getenv getenv"
	fi
}
mini__timerfd_settime(){ 
  if [ ! -z $1 ]; then echo "#define mini__timerfd_settime $1" 
	else echo  "#define mini__timerfd_settime _timerfd_settime"
	fi
}
mini_globals(){ 
  if [ ! -z $1 ]; then echo "#define mini_globals $1" 
	else echo  "#define mini_globals globals"
	fi
}
mini_feof(){ 
  if [ ! -z $1 ]; then echo "#define mini_feof $1" 
	else echo  "#define mini_feof feof"
	fi
}
mini_dup(){ 
  if [ ! -z $1 ]; then echo "#define mini_dup $1" 
	else echo  "#define mini_dup dup"
	fi
}
mini__sched_getattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__sched_getattr $1" 
	else echo  "#define mini__sched_getattr _sched_getattr"
	fi
}
mini__msync(){ 
  if [ ! -z $1 ]; then echo "#define mini__msync $1" 
	else echo  "#define mini__msync _msync"
	fi
}
mini_memset(){ 
  if [ ! -z $1 ]; then echo "#define mini_memset $1" 
	else echo  "#define mini_memset memset"
	fi
}
mini_printf(){ 
  if [ ! -z $1 ]; then echo "#define mini_printf $1" 
	else echo  "#define mini_printf printf"
	fi
}
mini__sendmmsg(){ 
  if [ ! -z $1 ]; then echo "#define mini__sendmmsg $1" 
	else echo  "#define mini__sendmmsg _sendmmsg"
	fi
}
mini_vhangup(){ 
  if [ ! -z $1 ]; then echo "#define mini_vhangup $1" 
	else echo  "#define mini_vhangup vhangup"
	fi
}
mini__modify_ldt(){ 
  if [ ! -z $1 ]; then echo "#define mini__modify_ldt $1" 
	else echo  "#define mini__modify_ldt _modify_ldt"
	fi
}
mini__io_destroy(){ 
  if [ ! -z $1 ]; then echo "#define mini__io_destroy $1" 
	else echo  "#define mini__io_destroy _io_destroy"
	fi
}
mini_uitohex(){ 
  if [ ! -z $1 ]; then echo "#define mini_uitohex $1" 
	else echo  "#define mini_uitohex uitohex"
	fi
}
mini_sendto(){ 
  if [ ! -z $1 ]; then echo "#define mini_sendto $1" 
	else echo  "#define mini_sendto sendto"
	fi
}
mini_getgid(){ 
  if [ ! -z $1 ]; then echo "#define mini_getgid $1" 
	else echo  "#define mini_getgid getgid"
	fi
}
mini__syslog(){ 
  if [ ! -z $1 ]; then echo "#define mini__syslog $1" 
	else echo  "#define mini__syslog _syslog"
	fi
}
mini__geteuid(){ 
  if [ ! -z $1 ]; then echo "#define mini__geteuid $1" 
	else echo  "#define mini__geteuid _geteuid"
	fi
}
mini_itobin(){ 
  if [ ! -z $1 ]; then echo "#define mini_itobin $1" 
	else echo  "#define mini_itobin itobin"
	fi
}
mini__setregid(){ 
  if [ ! -z $1 ]; then echo "#define mini__setregid $1" 
	else echo  "#define mini__setregid _setregid"
	fi
}
mini__tee(){ 
  if [ ! -z $1 ]; then echo "#define mini__tee $1" 
	else echo  "#define mini__tee _tee"
	fi
}
mini_bsd_cksum(){ 
  if [ ! -z $1 ]; then echo "#define mini_bsd_cksum $1" 
	else echo  "#define mini_bsd_cksum bsd_cksum"
	fi
}
mini_cfmakeraw(){ 
  if [ ! -z $1 ]; then echo "#define mini_cfmakeraw $1" 
	else echo  "#define mini_cfmakeraw cfmakeraw"
	fi
}
mini_fchown(){ 
  if [ ! -z $1 ]; then echo "#define mini_fchown $1" 
	else echo  "#define mini_fchown fchown"
	fi
}
mini__connect(){ 
  if [ ! -z $1 ]; then echo "#define mini__connect $1" 
	else echo  "#define mini__connect _connect"
	fi
}
mini_strncasecmp(){ 
  if [ ! -z $1 ]; then echo "#define mini_strncasecmp $1" 
	else echo  "#define mini_strncasecmp strncasecmp"
	fi
}
mini__flistxattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__flistxattr $1" 
	else echo  "#define mini__flistxattr _flistxattr"
	fi
}
mini_strlen(){ 
  if [ ! -z $1 ]; then echo "#define mini_strlen $1" 
	else echo  "#define mini_strlen strlen"
	fi
}
mini_strchr(){ 
  if [ ! -z $1 ]; then echo "#define mini_strchr $1" 
	else echo  "#define mini_strchr strchr"
	fi
}
mini__getppid(){ 
  if [ ! -z $1 ]; then echo "#define mini__getppid $1" 
	else echo  "#define mini__getppid _getppid"
	fi
}
mini__mount(){ 
  if [ ! -z $1 ]; then echo "#define mini__mount $1" 
	else echo  "#define mini__mount _mount"
	fi
}
mini__ftruncate(){ 
  if [ ! -z $1 ]; then echo "#define mini__ftruncate $1" 
	else echo  "#define mini__ftruncate _ftruncate"
	fi
}
mini__mprints(){ 
  if [ ! -z $1 ]; then echo "#define mini__mprints $1" 
	else echo  "#define mini__mprints _mprints"
	fi
}
mini_symlink(){ 
  if [ ! -z $1 ]; then echo "#define mini_symlink $1" 
	else echo  "#define mini_symlink symlink"
	fi
}
mini_abort(){ 
  if [ ! -z $1 ]; then echo "#define mini_abort $1" 
	else echo  "#define mini_abort abort"
	fi
}
mini_fgetsp(){ 
  if [ ! -z $1 ]; then echo "#define mini_fgetsp $1" 
	else echo  "#define mini_fgetsp fgetsp"
	fi
}
mini_clone(){ 
  if [ ! -z $1 ]; then echo "#define mini_clone $1" 
	else echo  "#define mini_clone clone"
	fi
}
mini__statfs(){ 
  if [ ! -z $1 ]; then echo "#define mini__statfs $1" 
	else echo  "#define mini__statfs _statfs"
	fi
}
mini__get_robust_list(){ 
  if [ ! -z $1 ]; then echo "#define mini__get_robust_list $1" 
	else echo  "#define mini__get_robust_list _get_robust_list"
	fi
}
mini_setgrent(){ 
  if [ ! -z $1 ]; then echo "#define mini_setgrent $1" 
	else echo  "#define mini_setgrent setgrent"
	fi
}
mini_getgrnam(){ 
  if [ ! -z $1 ]; then echo "#define mini_getgrnam $1" 
	else echo  "#define mini_getgrnam getgrnam"
	fi
}
mini_token_i(){ 
  if [ ! -z $1 ]; then echo "#define mini_token_i $1" 
	else echo  "#define mini_token_i token_i"
	fi
}
mini__getcpu(){ 
  if [ ! -z $1 ]; then echo "#define mini__getcpu $1" 
	else echo  "#define mini__getcpu _getcpu"
	fi
}
mini_userdb(){ 
  if [ ! -z $1 ]; then echo "#define mini_userdb $1" 
	else echo  "#define mini_userdb userdb"
	fi
}
mini__mincore(){ 
  if [ ! -z $1 ]; then echo "#define mini__mincore $1" 
	else echo  "#define mini__mincore _mincore"
	fi
}
mini__munmap(){ 
  if [ ! -z $1 ]; then echo "#define mini__munmap $1" 
	else echo  "#define mini__munmap _munmap"
	fi
}
mini__set_mempolicy(){ 
  if [ ! -z $1 ]; then echo "#define mini__set_mempolicy $1" 
	else echo  "#define mini__set_mempolicy _set_mempolicy"
	fi
}
mini__io_submit(){ 
  if [ ! -z $1 ]; then echo "#define mini__io_submit $1" 
	else echo  "#define mini__io_submit _io_submit"
	fi
}
mini__memfd_create(){ 
  if [ ! -z $1 ]; then echo "#define mini__memfd_create $1" 
	else echo  "#define mini__memfd_create _memfd_create"
	fi
}
mini_writesl(){ 
  if [ ! -z $1 ]; then echo "#define mini_writesl $1" 
	else echo  "#define mini_writesl writesl"
	fi
}
mini__seccomp(){ 
  if [ ! -z $1 ]; then echo "#define mini__seccomp $1" 
	else echo  "#define mini__seccomp _seccomp"
	fi
}
mini__io_getevents(){ 
  if [ ! -z $1 ]; then echo "#define mini__io_getevents $1" 
	else echo  "#define mini__io_getevents _io_getevents"
	fi
}
mini__openat(){ 
  if [ ! -z $1 ]; then echo "#define mini__openat $1" 
	else echo  "#define mini__openat _openat"
	fi
}
mini_chmod(){ 
  if [ ! -z $1 ]; then echo "#define mini_chmod $1" 
	else echo  "#define mini_chmod chmod"
	fi
}
mini_getgroups(){ 
  if [ ! -z $1 ]; then echo "#define mini_getgroups $1" 
	else echo  "#define mini_getgroups getgroups"
	fi
}
mini_writes(){ 
  if [ ! -z $1 ]; then echo "#define mini_writes $1" 
	else echo  "#define mini_writes writes"
	fi
}
mini_dprints(){ 
  if [ ! -z $1 ]; then echo "#define mini_dprints $1" 
	else echo  "#define mini_dprints dprints"
	fi
}
mini__gettid(){ 
  if [ ! -z $1 ]; then echo "#define mini__gettid $1" 
	else echo  "#define mini__gettid _gettid"
	fi
}
mini_msync(){ 
  if [ ! -z $1 ]; then echo "#define mini_msync $1" 
	else echo  "#define mini_msync msync"
	fi
}
mini__dup(){ 
  if [ ! -z $1 ]; then echo "#define mini__dup $1" 
	else echo  "#define mini__dup _dup"
	fi
}
mini_token_s(){ 
  if [ ! -z $1 ]; then echo "#define mini_token_s $1" 
	else echo  "#define mini_token_s token_s"
	fi
}
mini_getppid(){ 
  if [ ! -z $1 ]; then echo "#define mini_getppid $1" 
	else echo  "#define mini_getppid getppid"
	fi
}
mini__arch_prctl(){ 
  if [ ! -z $1 ]; then echo "#define mini__arch_prctl $1" 
	else echo  "#define mini__arch_prctl _arch_prctl"
	fi
}
mini__accept4(){ 
  if [ ! -z $1 ]; then echo "#define mini__accept4 $1" 
	else echo  "#define mini__accept4 _accept4"
	fi
}
mini__rt_sigpending(){ 
  if [ ! -z $1 ]; then echo "#define mini__rt_sigpending $1" 
	else echo  "#define mini__rt_sigpending _rt_sigpending"
	fi
}
mini__remap_file_pages(){ 
  if [ ! -z $1 ]; then echo "#define mini__remap_file_pages $1" 
	else echo  "#define mini__remap_file_pages _remap_file_pages"
	fi
}
mini_utime(){ 
  if [ ! -z $1 ]; then echo "#define mini_utime $1" 
	else echo  "#define mini_utime utime"
	fi
}
mini__fanotify_mark(){ 
  if [ ! -z $1 ]; then echo "#define mini__fanotify_mark $1" 
	else echo  "#define mini__fanotify_mark _fanotify_mark"
	fi
}
mini__kill(){ 
  if [ ! -z $1 ]; then echo "#define mini__kill $1" 
	else echo  "#define mini__kill _kill"
	fi
}
mini_ALIGN(){ 
  if [ ! -z $1 ]; then echo "#define mini_ALIGN $1" 
	else echo  "#define mini_ALIGN ALIGN"
	fi
}
mini__recvmmsg(){ 
  if [ ! -z $1 ]; then echo "#define mini__recvmmsg $1" 
	else echo  "#define mini__recvmmsg _recvmmsg"
	fi
}
mini_setitimer(){ 
  if [ ! -z $1 ]; then echo "#define mini_setitimer $1" 
	else echo  "#define mini_setitimer setitimer"
	fi
}
mini_wait(){ 
  if [ ! -z $1 ]; then echo "#define mini_wait $1" 
	else echo  "#define mini_wait wait"
	fi
}
mini_grent(){ 
  if [ ! -z $1 ]; then echo "#define mini_grent $1" 
	else echo  "#define mini_grent grent"
	fi
}
mini_match_ext2(){ 
  if [ ! -z $1 ]; then echo "#define mini_match_ext2 $1" 
	else echo  "#define mini_match_ext2 match_ext2"
	fi
}
mini_ferror(){ 
  if [ ! -z $1 ]; then echo "#define mini_ferror $1" 
	else echo  "#define mini_ferror ferror"
	fi
}
mini__quotactl(){ 
  if [ ! -z $1 ]; then echo "#define mini__quotactl $1" 
	else echo  "#define mini__quotactl _quotactl"
	fi
}
mini_getcwd(){ 
  if [ ! -z $1 ]; then echo "#define mini_getcwd $1" 
	else echo  "#define mini_getcwd getcwd"
	fi
}
mini__shutdown(){ 
  if [ ! -z $1 ]; then echo "#define mini__shutdown $1" 
	else echo  "#define mini__shutdown _shutdown"
	fi
}
mini__time(){ 
  if [ ! -z $1 ]; then echo "#define mini__time $1" 
	else echo  "#define mini__time _time"
	fi
}
mini__pipe(){ 
  if [ ! -z $1 ]; then echo "#define mini__pipe $1" 
	else echo  "#define mini__pipe _pipe"
	fi
}
mini_dirbufsize (){ 
  if [ ! -z $1 ]; then echo "#define mini_dirbufsize  $1" 
	else echo  "#define mini_dirbufsize  dirbufsize "
	fi
}
mini__setxattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__setxattr $1" 
	else echo  "#define mini__setxattr _setxattr"
	fi
}
mini__vmsplice(){ 
  if [ ! -z $1 ]; then echo "#define mini__vmsplice $1" 
	else echo  "#define mini__vmsplice _vmsplice"
	fi
}
mini__readv(){ 
  if [ ! -z $1 ]; then echo "#define mini__readv $1" 
	else echo  "#define mini__readv _readv"
	fi
}
mini_setvbuf(){ 
  if [ ! -z $1 ]; then echo "#define mini_setvbuf $1" 
	else echo  "#define mini_setvbuf setvbuf"
	fi
}
mini_eprints(){ 
  if [ ! -z $1 ]; then echo "#define mini_eprints $1" 
	else echo  "#define mini_eprints eprints"
	fi
}
mini__sched_get_priority_min(){ 
  if [ ! -z $1 ]; then echo "#define mini__sched_get_priority_min $1" 
	else echo  "#define mini__sched_get_priority_min _sched_get_priority_min"
	fi
}
mini__fchmod(){ 
  if [ ! -z $1 ]; then echo "#define mini__fchmod $1" 
	else echo  "#define mini__fchmod _fchmod"
	fi
}
mini__chdir(){ 
  if [ ! -z $1 ]; then echo "#define mini__chdir $1" 
	else echo  "#define mini__chdir _chdir"
	fi
}
mini_match_ext(){ 
  if [ ! -z $1 ]; then echo "#define mini_match_ext $1" 
	else echo  "#define mini_match_ext match_ext"
	fi
}
mini_OPTIMIZATIONS(){ 
  if [ ! -z $1 ]; then echo "#define mini_OPTIMIZATIONS $1" 
	else echo  "#define mini_OPTIMIZATIONS OPTIMIZATIONS"
	fi
}
mini_ret_errno(){ 
  if [ ! -z $1 ]; then echo "#define mini_ret_errno $1" 
	else echo  "#define mini_ret_errno ret_errno"
	fi
}
mini_lseek(){ 
  if [ ! -z $1 ]; then echo "#define mini_lseek $1" 
	else echo  "#define mini_lseek lseek"
	fi
}
mini__semtimedop(){ 
  if [ ! -z $1 ]; then echo "#define mini__semtimedop $1" 
	else echo  "#define mini__semtimedop _semtimedop"
	fi
}
mini_tolower(){ 
  if [ ! -z $1 ]; then echo "#define mini_tolower $1" 
	else echo  "#define mini_tolower tolower"
	fi
}
mini__lookup_dcookie(){ 
  if [ ! -z $1 ]; then echo "#define mini__lookup_dcookie $1" 
	else echo  "#define mini__lookup_dcookie _lookup_dcookie"
	fi
}
mini_fseek(){ 
  if [ ! -z $1 ]; then echo "#define mini_fseek $1" 
	else echo  "#define mini_fseek fseek"
	fi
}
mini__rt_sigprocmask(){ 
  if [ ! -z $1 ]; then echo "#define mini__rt_sigprocmask $1" 
	else echo  "#define mini__rt_sigprocmask _rt_sigprocmask"
	fi
}
mini__inotify_init(){ 
  if [ ! -z $1 ]; then echo "#define mini__inotify_init $1" 
	else echo  "#define mini__inotify_init _inotify_init"
	fi
}
mini__stat(){ 
  if [ ! -z $1 ]; then echo "#define mini__stat $1" 
	else echo  "#define mini__stat _stat"
	fi
}
mini_dup3(){ 
  if [ ! -z $1 ]; then echo "#define mini_dup3 $1" 
	else echo  "#define mini_dup3 dup3"
	fi
}
mini__clock_getres(){ 
  if [ ! -z $1 ]; then echo "#define mini__clock_getres $1" 
	else echo  "#define mini__clock_getres _clock_getres"
	fi
}
mini_getgrgid(){ 
  if [ ! -z $1 ]; then echo "#define mini_getgrgid $1" 
	else echo  "#define mini_getgrgid getgrgid"
	fi
}
mini__fallocate(){ 
  if [ ! -z $1 ]; then echo "#define mini__fallocate $1" 
	else echo  "#define mini__fallocate _fallocate"
	fi
}
mini_clearerror(){ 
  if [ ! -z $1 ]; then echo "#define mini_clearerror $1" 
	else echo  "#define mini_clearerror clearerror"
	fi
}
mini_inotify_init(){ 
  if [ ! -z $1 ]; then echo "#define mini_inotify_init $1" 
	else echo  "#define mini_inotify_init inotify_init"
	fi
}
mini_wait4(){ 
  if [ ! -z $1 ]; then echo "#define mini_wait4 $1" 
	else echo  "#define mini_wait4 wait4"
	fi
}
mini_usleep(){ 
  if [ ! -z $1 ]; then echo "#define mini_usleep $1" 
	else echo  "#define mini_usleep usleep"
	fi
}
mini_rename(){ 
  if [ ! -z $1 ]; then echo "#define mini_rename $1" 
	else echo  "#define mini_rename rename"
	fi
}
mini_abs(){ 
  if [ ! -z $1 ]; then echo "#define mini_abs $1" 
	else echo  "#define mini_abs abs"
	fi
}
mini__tkill(){ 
  if [ ! -z $1 ]; then echo "#define mini__tkill $1" 
	else echo  "#define mini__tkill _tkill"
	fi
}
mini__pwritev(){ 
  if [ ! -z $1 ]; then echo "#define mini__pwritev $1" 
	else echo  "#define mini__pwritev _pwritev"
	fi
}
mini__open(){ 
  if [ ! -z $1 ]; then echo "#define mini__open $1" 
	else echo  "#define mini__open _open"
	fi
}
mini__utimensat(){ 
  if [ ! -z $1 ]; then echo "#define mini__utimensat $1" 
	else echo  "#define mini__utimensat _utimensat"
	fi
}
mini__setsockopt(){ 
  if [ ! -z $1 ]; then echo "#define mini__setsockopt $1" 
	else echo  "#define mini__setsockopt _setsockopt"
	fi
}
mini__fstat(){ 
  if [ ! -z $1 ]; then echo "#define mini__fstat $1" 
	else echo  "#define mini__fstat _fstat"
	fi
}
mini_snprintfs(){ 
  if [ ! -z $1 ]; then echo "#define mini_snprintfs $1" 
	else echo  "#define mini_snprintfs snprintfs"
	fi
}
mini__pipe2(){ 
  if [ ! -z $1 ]; then echo "#define mini__pipe2 $1" 
	else echo  "#define mini__pipe2 _pipe2"
	fi
}
mini_memfd_create(){ 
  if [ ! -z $1 ]; then echo "#define mini_memfd_create $1" 
	else echo  "#define mini_memfd_create memfd_create"
	fi
}
mini_eprintl(){ 
  if [ ! -z $1 ]; then echo "#define mini_eprintl $1" 
	else echo  "#define mini_eprintl eprintl"
	fi
}
mini_readdir(){ 
  if [ ! -z $1 ]; then echo "#define mini_readdir $1" 
	else echo  "#define mini_readdir readdir"
	fi
}
mini_grantpt(){ 
  if [ ! -z $1 ]; then echo "#define mini_grantpt $1" 
	else echo  "#define mini_grantpt grantpt"
	fi
}
mini_chroot(){ 
  if [ ! -z $1 ]; then echo "#define mini_chroot $1" 
	else echo  "#define mini_chroot chroot"
	fi
}
mini_fileno(){ 
  if [ ! -z $1 ]; then echo "#define mini_fileno $1" 
	else echo  "#define mini_fileno fileno"
	fi
}
mini__dup2(){ 
  if [ ! -z $1 ]; then echo "#define mini__dup2 $1" 
	else echo  "#define mini__dup2 _dup2"
	fi
}
mini__getsid(){ 
  if [ ! -z $1 ]; then echo "#define mini__getsid $1" 
	else echo  "#define mini__getsid _getsid"
	fi
}
mini__timer_delete(){ 
  if [ ! -z $1 ]; then echo "#define mini__timer_delete $1" 
	else echo  "#define mini__timer_delete _timer_delete"
	fi
}
mini__fopen(){ 
  if [ ! -z $1 ]; then echo "#define mini__fopen $1" 
	else echo  "#define mini__fopen _fopen"
	fi
}
mini_fsetpos(){ 
  if [ ! -z $1 ]; then echo "#define mini_fsetpos $1" 
	else echo  "#define mini_fsetpos fsetpos"
	fi
}
mini_eprintfs(){ 
  if [ ! -z $1 ]; then echo "#define mini_eprintfs $1" 
	else echo  "#define mini_eprintfs eprintfs"
	fi
}
mini__fadvise64(){ 
  if [ ! -z $1 ]; then echo "#define mini__fadvise64 $1" 
	else echo  "#define mini__fadvise64 _fadvise64"
	fi
}
mini__getrandom(){ 
  if [ ! -z $1 ]; then echo "#define mini__getrandom $1" 
	else echo  "#define mini__getrandom _getrandom"
	fi
}
mini_strlcpy(){ 
  if [ ! -z $1 ]; then echo "#define mini_strlcpy $1" 
	else echo  "#define mini_strlcpy strlcpy"
	fi
}
mini_close(){ 
  if [ ! -z $1 ]; then echo "#define mini_close $1" 
	else echo  "#define mini_close close"
	fi
}
mini__fstatfs(){ 
  if [ ! -z $1 ]; then echo "#define mini__fstatfs $1" 
	else echo  "#define mini__fstatfs _fstatfs"
	fi
}
mini_uitoHEX(){ 
  if [ ! -z $1 ]; then echo "#define mini_uitoHEX $1" 
	else echo  "#define mini_uitoHEX uitoHEX"
	fi
}
mini__wait4(){ 
  if [ ! -z $1 ]; then echo "#define mini__wait4 $1" 
	else echo  "#define mini__wait4 _wait4"
	fi
}
mini__io_cancel(){ 
  if [ ! -z $1 ]; then echo "#define mini__io_cancel $1" 
	else echo  "#define mini__io_cancel _io_cancel"
	fi
}
mini__setreuid(){ 
  if [ ! -z $1 ]; then echo "#define mini__setreuid $1" 
	else echo  "#define mini__setreuid _setreuid"
	fi
}
mini_dies(){ 
  if [ ! -z $1 ]; then echo "#define mini_dies $1" 
	else echo  "#define mini_dies dies"
	fi
}
mini__alarm(){ 
  if [ ! -z $1 ]; then echo "#define mini__alarm $1" 
	else echo  "#define mini__alarm _alarm"
	fi
}
mini_gettimeofday(){ 
  if [ ! -z $1 ]; then echo "#define mini_gettimeofday $1" 
	else echo  "#define mini_gettimeofday gettimeofday"
	fi
}
mini__mkdir(){ 
  if [ ! -z $1 ]; then echo "#define mini__mkdir $1" 
	else echo  "#define mini__mkdir _mkdir"
	fi
}
mini_strncmp(){ 
  if [ ! -z $1 ]; then echo "#define mini_strncmp $1" 
	else echo  "#define mini_strncmp strncmp"
	fi
}
mini__rt_tgsigqueueinfo(){ 
  if [ ! -z $1 ]; then echo "#define mini__rt_tgsigqueueinfo $1" 
	else echo  "#define mini__rt_tgsigqueueinfo _rt_tgsigqueueinfo"
	fi
}
mini_getchar(){ 
  if [ ! -z $1 ]; then echo "#define mini_getchar $1" 
	else echo  "#define mini_getchar getchar"
	fi
}
mini_eprint(){ 
  if [ ! -z $1 ]; then echo "#define mini_eprint $1" 
	else echo  "#define mini_eprint eprint"
	fi
}
mini__setresuid(){ 
  if [ ! -z $1 ]; then echo "#define mini__setresuid $1" 
	else echo  "#define mini__setresuid _setresuid"
	fi
}
mini_group_printf(){ 
  if [ ! -z $1 ]; then echo "#define mini_group_printf $1" 
	else echo  "#define mini_group_printf group_printf"
	fi
}
mini_fclose(){ 
  if [ ! -z $1 ]; then echo "#define mini_fclose $1" 
	else echo  "#define mini_fclose fclose"
	fi
}
mini__rmdir(){ 
  if [ ! -z $1 ]; then echo "#define mini__rmdir $1" 
	else echo  "#define mini__rmdir _rmdir"
	fi
}
mini__inotify_add_watch(){ 
  if [ ! -z $1 ]; then echo "#define mini__inotify_add_watch $1" 
	else echo  "#define mini__inotify_add_watch _inotify_add_watch"
	fi
}
mini_munmap(){ 
  if [ ! -z $1 ]; then echo "#define mini_munmap $1" 
	else echo  "#define mini_munmap munmap"
	fi
}
mini_stpncpy(){ 
  if [ ! -z $1 ]; then echo "#define mini_stpncpy $1" 
	else echo  "#define mini_stpncpy stpncpy"
	fi
}
mini__open_by_handle_at(){ 
  if [ ! -z $1 ]; then echo "#define mini__open_by_handle_at $1" 
	else echo  "#define mini__open_by_handle_at _open_by_handle_at"
	fi
}
mini__sync_file_range(){ 
  if [ ! -z $1 ]; then echo "#define mini__sync_file_range $1" 
	else echo  "#define mini__sync_file_range _sync_file_range"
	fi
}
mini__pause(){ 
  if [ ! -z $1 ]; then echo "#define mini__pause $1" 
	else echo  "#define mini__pause _pause"
	fi
}
mini_inotify_init1(){ 
  if [ ! -z $1 ]; then echo "#define mini_inotify_init1 $1" 
	else echo  "#define mini_inotify_init1 inotify_init1"
	fi
}
mini_recvfrom(){ 
  if [ ! -z $1 ]; then echo "#define mini_recvfrom $1" 
	else echo  "#define mini_recvfrom recvfrom"
	fi
}
mini__recvfrom(){ 
  if [ ! -z $1 ]; then echo "#define mini__recvfrom $1" 
	else echo  "#define mini__recvfrom _recvfrom"
	fi
}
mini__mprotect(){ 
  if [ ! -z $1 ]; then echo "#define mini__mprotect $1" 
	else echo  "#define mini__mprotect _mprotect"
	fi
}
mini_waitpid(){ 
  if [ ! -z $1 ]; then echo "#define mini_waitpid $1" 
	else echo  "#define mini_waitpid waitpid"
	fi
}
mini__fsetxattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__fsetxattr $1" 
	else echo  "#define mini__fsetxattr _fsetxattr"
	fi
}
mini_realloc(){ 
  if [ ! -z $1 ]; then echo "#define mini_realloc $1" 
	else echo  "#define mini_realloc realloc"
	fi
}
mini__fchownat(){ 
  if [ ! -z $1 ]; then echo "#define mini__fchownat $1" 
	else echo  "#define mini__fchownat _fchownat"
	fi
}
mini_fread(){ 
  if [ ! -z $1 ]; then echo "#define mini_fread $1" 
	else echo  "#define mini_fread fread"
	fi
}
mini_ultodec(){ 
  if [ ! -z $1 ]; then echo "#define mini_ultodec $1" 
	else echo  "#define mini_ultodec ultodec"
	fi
}
mini_rt_sigreturn(){ 
  if [ ! -z $1 ]; then echo "#define mini_rt_sigreturn $1" 
	else echo  "#define mini_rt_sigreturn rt_sigreturn"
	fi
}
mini_inet_aton(){ 
  if [ ! -z $1 ]; then echo "#define mini_inet_aton $1" 
	else echo  "#define mini_inet_aton inet_aton"
	fi
}
mini_ldiv(){ 
  if [ ! -z $1 ]; then echo "#define mini_ldiv $1" 
	else echo  "#define mini_ldiv ldiv"
	fi
}
mini_strchrnul(){ 
  if [ ! -z $1 ]; then echo "#define mini_strchrnul $1" 
	else echo  "#define mini_strchrnul strchrnul"
	fi
}
mini__epoll_pwait(){ 
  if [ ! -z $1 ]; then echo "#define mini__epoll_pwait $1" 
	else echo  "#define mini__epoll_pwait _epoll_pwait"
	fi
}
mini__lseek(){ 
  if [ ! -z $1 ]; then echo "#define mini__lseek $1" 
	else echo  "#define mini__lseek _lseek"
	fi
}
mini_errno_str(){ 
  if [ ! -z $1 ]; then echo "#define mini_errno_str $1" 
	else echo  "#define mini_errno_str errno_str"
	fi
}
mini_pivot_root(){ 
  if [ ! -z $1 ]; then echo "#define mini_pivot_root $1" 
	else echo  "#define mini_pivot_root pivot_root"
	fi
}
mini_getc(){ 
  if [ ! -z $1 ]; then echo "#define mini_getc $1" 
	else echo  "#define mini_getc getc"
	fi
}
mini_sigemptyset(){ 
  if [ ! -z $1 ]; then echo "#define mini_sigemptyset $1" 
	else echo  "#define mini_sigemptyset sigemptyset"
	fi
}
mini__getresuid(){ 
  if [ ! -z $1 ]; then echo "#define mini__getresuid $1" 
	else echo  "#define mini__getresuid _getresuid"
	fi
}
mini_sigprocmask(){ 
  if [ ! -z $1 ]; then echo "#define mini_sigprocmask $1" 
	else echo  "#define mini_sigprocmask sigprocmask"
	fi
}
mini_dief(){ 
  if [ ! -z $1 ]; then echo "#define mini_dief $1" 
	else echo  "#define mini_dief dief"
	fi
}
mini_reboot(){ 
  if [ ! -z $1 ]; then echo "#define mini_reboot $1" 
	else echo  "#define mini_reboot reboot"
	fi
}
mini_getgrent(){ 
  if [ ! -z $1 ]; then echo "#define mini_getgrent $1" 
	else echo  "#define mini_getgrent getgrent"
	fi
}
mini__io_setup(){ 
  if [ ! -z $1 ]; then echo "#define mini__io_setup $1" 
	else echo  "#define mini__io_setup _io_setup"
	fi
}
mini_readahead(){ 
  if [ ! -z $1 ]; then echo "#define mini_readahead $1" 
	else echo  "#define mini_readahead readahead"
	fi
}
mini__clone(){ 
  if [ ! -z $1 ]; then echo "#define mini__clone $1" 
	else echo  "#define mini__clone _clone"
	fi
}
mini__sendfile(){ 
  if [ ! -z $1 ]; then echo "#define mini__sendfile $1" 
	else echo  "#define mini__sendfile _sendfile"
	fi
}
mini__migrate_pages(){ 
  if [ ! -z $1 ]; then echo "#define mini__migrate_pages $1" 
	else echo  "#define mini__migrate_pages _migrate_pages"
	fi
}
mini__itobin(){ 
  if [ ! -z $1 ]; then echo "#define mini__itobin $1" 
	else echo  "#define mini__itobin _itobin"
	fi
}
mini__madvise(){ 
  if [ ! -z $1 ]; then echo "#define mini__madvise $1" 
	else echo  "#define mini__madvise _madvise"
	fi
}
mini__futimesat(){ 
  if [ ! -z $1 ]; then echo "#define mini__futimesat $1" 
	else echo  "#define mini__futimesat _futimesat"
	fi
}
mini__mremap(){ 
  if [ ! -z $1 ]; then echo "#define mini__mremap $1" 
	else echo  "#define mini__mremap _mremap"
	fi
}
mini_fgets(){ 
  if [ ! -z $1 ]; then echo "#define mini_fgets $1" 
	else echo  "#define mini_fgets fgets"
	fi
}
mini_getpid(){ 
  if [ ! -z $1 ]; then echo "#define mini_getpid $1" 
	else echo  "#define mini_getpid getpid"
	fi
}
mini__munlockall(){ 
  if [ ! -z $1 ]; then echo "#define mini__munlockall $1" 
	else echo  "#define mini__munlockall _munlockall"
	fi
}
mini_fgetc(){ 
  if [ ! -z $1 ]; then echo "#define mini_fgetc $1" 
	else echo  "#define mini_fgetc fgetc"
	fi
}
mini_setgid(){ 
  if [ ! -z $1 ]; then echo "#define mini_setgid $1" 
	else echo  "#define mini_setgid setgid"
	fi
}
mini__pivot_root(){ 
  if [ ! -z $1 ]; then echo "#define mini__pivot_root $1" 
	else echo  "#define mini__pivot_root _pivot_root"
	fi
}
mini_fgetsn(){ 
  if [ ! -z $1 ]; then echo "#define mini_fgetsn $1" 
	else echo  "#define mini_fgetsn fgetsn"
	fi
}
mini_unmap_protected(){ 
  if [ ! -z $1 ]; then echo "#define mini_unmap_protected $1" 
	else echo  "#define mini_unmap_protected unmap_protected"
	fi
}
mini__personality(){ 
  if [ ! -z $1 ]; then echo "#define mini__personality $1" 
	else echo  "#define mini__personality _personality"
	fi
}
mini__creat(){ 
  if [ ! -z $1 ]; then echo "#define mini__creat $1" 
	else echo  "#define mini__creat _creat"
	fi
}
mini__execve(){ 
  if [ ! -z $1 ]; then echo "#define mini__execve $1" 
	else echo  "#define mini__execve _execve"
	fi
}
mini__rt_sigsuspend(){ 
  if [ ! -z $1 ]; then echo "#define mini__rt_sigsuspend $1" 
	else echo  "#define mini__rt_sigsuspend _rt_sigsuspend"
	fi
}
mini__pselect6(){ 
  if [ ! -z $1 ]; then echo "#define mini__pselect6 $1" 
	else echo  "#define mini__pselect6 _pselect6"
	fi
}
mini__fremovexattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__fremovexattr $1" 
	else echo  "#define mini__fremovexattr _fremovexattr"
	fi
}
mini__getdents(){ 
  if [ ! -z $1 ]; then echo "#define mini__getdents $1" 
	else echo  "#define mini__getdents _getdents"
	fi
}
mini_short_errstr(){ 
  if [ ! -z $1 ]; then echo "#define mini_short_errstr $1" 
	else echo  "#define mini_short_errstr short_errstr"
	fi
}
mini__strcmp(){ 
  if [ ! -z $1 ]; then echo "#define mini__strcmp $1" 
	else echo  "#define mini__strcmp _strcmp"
	fi
}
mini_fprint(){ 
  if [ ! -z $1 ]; then echo "#define mini_fprint $1" 
	else echo  "#define mini_fprint fprint"
	fi
}
mini_ptsname(){ 
  if [ ! -z $1 ]; then echo "#define mini_ptsname $1" 
	else echo  "#define mini_ptsname ptsname"
	fi
}
mini__recvmsg(){ 
  if [ ! -z $1 ]; then echo "#define mini__recvmsg $1" 
	else echo  "#define mini__recvmsg _recvmsg"
	fi
}
mini_OPTFENCE(){ 
  if [ ! -z $1 ]; then echo "#define mini_OPTFENCE $1" 
	else echo  "#define mini_OPTFENCE OPTFENCE"
	fi
}
mini_ftruncate(){ 
  if [ ! -z $1 ]; then echo "#define mini_ftruncate $1" 
	else echo  "#define mini_ftruncate ftruncate"
	fi
}
mini__write(){ 
  if [ ! -z $1 ]; then echo "#define mini__write $1" 
	else echo  "#define mini__write _write"
	fi
}
mini__sched_rr_get_interval(){ 
  if [ ! -z $1 ]; then echo "#define mini__sched_rr_get_interval $1" 
	else echo  "#define mini__sched_rr_get_interval _sched_rr_get_interval"
	fi
}
mini_getitimer(){ 
  if [ ! -z $1 ]; then echo "#define mini_getitimer $1" 
	else echo  "#define mini_getitimer getitimer"
	fi
}
mini_rmdir(){ 
  if [ ! -z $1 ]; then echo "#define mini_rmdir $1" 
	else echo  "#define mini_rmdir rmdir"
	fi
}
mini_itoHEX(){ 
  if [ ! -z $1 ]; then echo "#define mini_itoHEX $1" 
	else echo  "#define mini_itoHEX itoHEX"
	fi
}
mini__timer_gettime(){ 
  if [ ! -z $1 ]; then echo "#define mini__timer_gettime $1" 
	else echo  "#define mini__timer_gettime _timer_gettime"
	fi
}
mini_setsid(){ 
  if [ ! -z $1 ]; then echo "#define mini_setsid $1" 
	else echo  "#define mini_setsid setsid"
	fi
}
mini_endgrent(){ 
  if [ ! -z $1 ]; then echo "#define mini_endgrent $1" 
	else echo  "#define mini_endgrent endgrent"
	fi
}
mini__chroot(){ 
  if [ ! -z $1 ]; then echo "#define mini__chroot $1" 
	else echo  "#define mini__chroot _chroot"
	fi
}
mini__fork(){ 
  if [ ! -z $1 ]; then echo "#define mini__fork $1" 
	else echo  "#define mini__fork _fork"
	fi
}
mini__symlinkat(){ 
  if [ ! -z $1 ]; then echo "#define mini__symlinkat $1" 
	else echo  "#define mini__symlinkat _symlinkat"
	fi
}
mini__mq_timedsend(){ 
  if [ ! -z $1 ]; then echo "#define mini__mq_timedsend $1" 
	else echo  "#define mini__mq_timedsend _mq_timedsend"
	fi
}
mini_labs(){ 
  if [ ! -z $1 ]; then echo "#define mini_labs $1" 
	else echo  "#define mini_labs labs"
	fi
}
mini__writev(){ 
  if [ ! -z $1 ]; then echo "#define mini__writev $1" 
	else echo  "#define mini__writev _writev"
	fi
}
mini__fcntl(){ 
  if [ ! -z $1 ]; then echo "#define mini__fcntl $1" 
	else echo  "#define mini__fcntl _fcntl"
	fi
}
mini_fprintfs(){ 
  if [ ! -z $1 ]; then echo "#define mini_fprintfs $1" 
	else echo  "#define mini_fprintfs fprintfs"
	fi
}
mini_mmap(){ 
  if [ ! -z $1 ]; then echo "#define mini_mmap $1" 
	else echo  "#define mini_mmap mmap"
	fi
}
mini_fgetpos(){ 
  if [ ! -z $1 ]; then echo "#define mini_fgetpos $1" 
	else echo  "#define mini_fgetpos fgetpos"
	fi
}
mini__rename(){ 
  if [ ! -z $1 ]; then echo "#define mini__rename $1" 
	else echo  "#define mini__rename _rename"
	fi
}
mini_seterrno(){ 
  if [ ! -z $1 ]; then echo "#define mini_seterrno $1" 
	else echo  "#define mini_seterrno seterrno"
	fi
}
mini__rt_sigaction(){ 
  if [ ! -z $1 ]; then echo "#define mini__rt_sigaction $1" 
	else echo  "#define mini__rt_sigaction _rt_sigaction"
	fi
}
mini__getcwd(){ 
  if [ ! -z $1 ]; then echo "#define mini__getcwd $1" 
	else echo  "#define mini__getcwd _getcwd"
	fi
}
mini_uitodec(){ 
  if [ ! -z $1 ]; then echo "#define mini_uitodec $1" 
	else echo  "#define mini_uitodec uitodec"
	fi
}
mini__poll(){ 
  if [ ! -z $1 ]; then echo "#define mini__poll $1" 
	else echo  "#define mini__poll _poll"
	fi
}
mini__setsid(){ 
  if [ ! -z $1 ]; then echo "#define mini__setsid $1" 
	else echo  "#define mini__setsid _setsid"
	fi
}
mini_setgroups(){ 
  if [ ! -z $1 ]; then echo "#define mini_setgroups $1" 
	else echo  "#define mini_setgroups setgroups"
	fi
}
mini__unlink(){ 
  if [ ! -z $1 ]; then echo "#define mini__unlink $1" 
	else echo  "#define mini__unlink _unlink"
	fi
}
mini_fdopen(){ 
  if [ ! -z $1 ]; then echo "#define mini_fdopen $1" 
	else echo  "#define mini_fdopen fdopen"
	fi
}
mini__ioprio_set(){ 
  if [ ! -z $1 ]; then echo "#define mini__ioprio_set $1" 
	else echo  "#define mini__ioprio_set _ioprio_set"
	fi
}
mini__removexattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__removexattr $1" 
	else echo  "#define mini__removexattr _removexattr"
	fi
}
mini__delete_module(){ 
  if [ ! -z $1 ]; then echo "#define mini__delete_module $1" 
	else echo  "#define mini__delete_module _delete_module"
	fi
}
mini__semop(){ 
  if [ ! -z $1 ]; then echo "#define mini__semop $1" 
	else echo  "#define mini__semop _semop"
	fi
}
mini_socket(){ 
  if [ ! -z $1 ]; then echo "#define mini_socket $1" 
	else echo  "#define mini_socket socket"
	fi
}
mini_getpwuid(){ 
  if [ ! -z $1 ]; then echo "#define mini_getpwuid $1" 
	else echo  "#define mini_getpwuid getpwuid"
	fi
}
mini__set_tid_address(){ 
  if [ ! -z $1 ]; then echo "#define mini__set_tid_address $1" 
	else echo  "#define mini__set_tid_address _set_tid_address"
	fi
}
mini__restart_syscall(){ 
  if [ ! -z $1 ]; then echo "#define mini__restart_syscall $1" 
	else echo  "#define mini__restart_syscall _restart_syscall"
	fi
}
mini__getsockopt(){ 
  if [ ! -z $1 ]; then echo "#define mini__getsockopt $1" 
	else echo  "#define mini__getsockopt _getsockopt"
	fi
}
mini__mkdirat(){ 
  if [ ! -z $1 ]; then echo "#define mini__mkdirat $1" 
	else echo  "#define mini__mkdirat _mkdirat"
	fi
}
mini__readahead(){ 
  if [ ! -z $1 ]; then echo "#define mini__readahead $1" 
	else echo  "#define mini__readahead _readahead"
	fi
}
mini__chmod(){ 
  if [ ! -z $1 ]; then echo "#define mini__chmod $1" 
	else echo  "#define mini__chmod _chmod"
	fi
}
mini_mkfifo(){ 
  if [ ! -z $1 ]; then echo "#define mini_mkfifo $1" 
	else echo  "#define mini_mkfifo mkfifo"
	fi
}
mini_eprintsl(){ 
  if [ ! -z $1 ]; then echo "#define mini_eprintsl $1" 
	else echo  "#define mini_eprintsl eprintsl"
	fi
}
mini_fsync(){ 
  if [ ! -z $1 ]; then echo "#define mini_fsync $1" 
	else echo  "#define mini_fsync fsync"
	fi
}
mini__readlinkat(){ 
  if [ ! -z $1 ]; then echo "#define mini__readlinkat $1" 
	else echo  "#define mini__readlinkat _readlinkat"
	fi
}
mini_ioctl(){ 
  if [ ! -z $1 ]; then echo "#define mini_ioctl $1" 
	else echo  "#define mini_ioctl ioctl"
	fi
}
mini__timer_getoverrun(){ 
  if [ ! -z $1 ]; then echo "#define mini__timer_getoverrun $1" 
	else echo  "#define mini__timer_getoverrun _timer_getoverrun"
	fi
}
mini__acct(){ 
  if [ ! -z $1 ]; then echo "#define mini__acct $1" 
	else echo  "#define mini__acct _acct"
	fi
}
mini_mknod(){ 
  if [ ! -z $1 ]; then echo "#define mini_mknod $1" 
	else echo  "#define mini_mknod mknod"
	fi
}
mini_fprints(){ 
  if [ ! -z $1 ]; then echo "#define mini_fprints $1" 
	else echo  "#define mini_fprints fprints"
	fi
}
mini_nanosleep(){ 
  if [ ! -z $1 ]; then echo "#define mini_nanosleep $1" 
	else echo  "#define mini_nanosleep nanosleep"
	fi
}
mini__timer_create(){ 
  if [ ! -z $1 ]; then echo "#define mini__timer_create $1" 
	else echo  "#define mini__timer_create _timer_create"
	fi
}
mini_bind(){ 
  if [ ! -z $1 ]; then echo "#define mini_bind $1" 
	else echo  "#define mini_bind bind"
	fi
}
mini_fexecveat(){ 
  if [ ! -z $1 ]; then echo "#define mini_fexecveat $1" 
	else echo  "#define mini_fexecveat fexecveat"
	fi
}
mini__umask(){ 
  if [ ! -z $1 ]; then echo "#define mini__umask $1" 
	else echo  "#define mini__umask _umask"
	fi
}
mini_splice(){ 
  if [ ! -z $1 ]; then echo "#define mini_splice $1" 
	else echo  "#define mini_splice splice"
	fi
}
mini_gets(){ 
  if [ ! -z $1 ]; then echo "#define mini_gets $1" 
	else echo  "#define mini_gets gets"
	fi
}
mini_access(){ 
  if [ ! -z $1 ]; then echo "#define mini_access $1" 
	else echo  "#define mini_access access"
	fi
}
mini_stpcpy(){ 
  if [ ! -z $1 ]; then echo "#define mini_stpcpy $1" 
	else echo  "#define mini_stpcpy stpcpy"
	fi
}
mini__timer_settime(){ 
  if [ ! -z $1 ]; then echo "#define mini__timer_settime $1" 
	else echo  "#define mini__timer_settime _timer_settime"
	fi
}
mini_sendfile(){ 
  if [ ! -z $1 ]; then echo "#define mini_sendfile $1" 
	else echo  "#define mini_sendfile sendfile"
	fi
}
mini__getpeername(){ 
  if [ ! -z $1 ]; then echo "#define mini__getpeername $1" 
	else echo  "#define mini__getpeername _getpeername"
	fi
}
mini__clock_nanosleep(){ 
  if [ ! -z $1 ]; then echo "#define mini__clock_nanosleep $1" 
	else echo  "#define mini__clock_nanosleep _clock_nanosleep"
	fi
}
mini__epoll_create(){ 
  if [ ! -z $1 ]; then echo "#define mini__epoll_create $1" 
	else echo  "#define mini__epoll_create _epoll_create"
	fi
}
mini__getsockname(){ 
  if [ ! -z $1 ]; then echo "#define mini__getsockname $1" 
	else echo  "#define mini__getsockname _getsockname"
	fi
}
mini__getxattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__getxattr $1" 
	else echo  "#define mini__getxattr _getxattr"
	fi
}
mini__capget(){ 
  if [ ! -z $1 ]; then echo "#define mini__capget $1" 
	else echo  "#define mini__capget _capget"
	fi
}
mini_signal(){ 
  if [ ! -z $1 ]; then echo "#define mini_signal $1" 
	else echo  "#define mini_signal signal"
	fi
}
mini_printsl(){ 
  if [ ! -z $1 ]; then echo "#define mini_printsl $1" 
	else echo  "#define mini_printsl printsl"
	fi
}
mini_max_groupmembers(){ 
  if [ ! -z $1 ]; then echo "#define mini_max_groupmembers $1" 
	else echo  "#define mini_max_groupmembers max_groupmembers"
	fi
}
mini_open(){ 
  if [ ! -z $1 ]; then echo "#define mini_open $1" 
	else echo  "#define mini_open open"
	fi
}
mini_vsprintf(){ 
  if [ ! -z $1 ]; then echo "#define mini_vsprintf $1" 
	else echo  "#define mini_vsprintf vsprintf"
	fi
}
mini__reboot(){ 
  if [ ! -z $1 ]; then echo "#define mini__reboot $1" 
	else echo  "#define mini__reboot _reboot"
	fi
}
mini_execvpe(){ 
  if [ ! -z $1 ]; then echo "#define mini_execvpe $1" 
	else echo  "#define mini_execvpe execvpe"
	fi
}
mini__faccessat(){ 
  if [ ! -z $1 ]; then echo "#define mini__faccessat $1" 
	else echo  "#define mini__faccessat _faccessat"
	fi
}
mini__pwrite64(){ 
  if [ ! -z $1 ]; then echo "#define mini__pwrite64 $1" 
	else echo  "#define mini__pwrite64 _pwrite64"
	fi
}
mini_creat(){ 
  if [ ! -z $1 ]; then echo "#define mini_creat $1" 
	else echo  "#define mini_creat creat"
	fi
}
mini__uname(){ 
  if [ ! -z $1 ]; then echo "#define mini__uname $1" 
	else echo  "#define mini__uname _uname"
	fi
}
mini__getpid(){ 
  if [ ! -z $1 ]; then echo "#define mini__getpid $1" 
	else echo  "#define mini__getpid _getpid"
	fi
}
mini_prints(){ 
  if [ ! -z $1 ]; then echo "#define mini_prints $1" 
	else echo  "#define mini_prints prints"
	fi
}
mini_fgetud(){ 
  if [ ! -z $1 ]; then echo "#define mini_fgetud $1" 
	else echo  "#define mini_fgetud fgetud"
	fi
}
mini__fchdir(){ 
  if [ ! -z $1 ]; then echo "#define mini__fchdir $1" 
	else echo  "#define mini__fchdir _fchdir"
	fi
}
mini__name_to_handle_at(){ 
  if [ ! -z $1 ]; then echo "#define mini__name_to_handle_at $1" 
	else echo  "#define mini__name_to_handle_at _name_to_handle_at"
	fi
}
mini__swapoff(){ 
  if [ ! -z $1 ]; then echo "#define mini__swapoff $1" 
	else echo  "#define mini__swapoff _swapoff"
	fi
}
mini_dup2(){ 
  if [ ! -z $1 ]; then echo "#define mini_dup2 $1" 
	else echo  "#define mini_dup2 dup2"
	fi
}
mini__lgetxattr(){ 
  if [ ! -z $1 ]; then echo "#define mini__lgetxattr $1" 
	else echo  "#define mini__lgetxattr _lgetxattr"
	fi
}
mini_djb_cksum(){ 
  if [ ! -z $1 ]; then echo "#define mini_djb_cksum $1" 
	else echo  "#define mini_djb_cksum djb_cksum"
	fi
}
mini__preadv(){ 
  if [ ! -z $1 ]; then echo "#define mini__preadv $1" 
	else echo  "#define mini__preadv _preadv"
	fi
}
mini_pwent(){ 
  if [ ! -z $1 ]; then echo "#define mini_pwent $1" 
	else echo  "#define mini_pwent pwent"
	fi
}
mini__sched_get_priority_max(){ 
  if [ ! -z $1 ]; then echo "#define mini__sched_get_priority_max $1" 
	else echo  "#define mini__sched_get_priority_max _sched_get_priority_max"
	fi
}
mini_errno(){ 
  if [ ! -z $1 ]; then echo "#define mini_errno $1" 
	else echo  "#define mini_errno errno"
	fi
}
mini_putenv(){ 
  if [ ! -z $1 ]; then echo "#define mini_putenv $1" 
	else echo  "#define mini_putenv putenv"
	fi
}
mini__ppoll(){ 
  if [ ! -z $1 ]; then echo "#define mini__ppoll $1" 
	else echo  "#define mini__ppoll _ppoll"
	fi
}
mini_tcgetattr(){ 
  if [ ! -z $1 ]; then echo "#define mini_tcgetattr $1" 
	else echo  "#define mini_tcgetattr tcgetattr"
	fi
}
mini_dirfd(){ 
  if [ ! -z $1 ]; then echo "#define mini_dirfd $1" 
	else echo  "#define mini_dirfd dirfd"
	fi
}
mini__get_mempolicy(){ 
  if [ ! -z $1 ]; then echo "#define mini__get_mempolicy $1" 
	else echo  "#define mini__get_mempolicy _get_mempolicy"
	fi
}
mini__lchown(){ 
  if [ ! -z $1 ]; then echo "#define mini__lchown $1" 
	else echo  "#define mini__lchown _lchown"
	fi
}
mini__signalfd4(){ 
  if [ ! -z $1 ]; then echo "#define mini__signalfd4 $1" 
	else echo  "#define mini__signalfd4 _signalfd4"
	fi
}
mini__exit_group(){ 
  if [ ! -z $1 ]; then echo "#define mini__exit_group $1" 
	else echo  "#define mini__exit_group _exit_group"
	fi
}
mini_dirbuf(){ 
  if [ ! -z $1 ]; then echo "#define mini_dirbuf $1" 
	else echo  "#define mini_dirbuf dirbuf"
	fi
}
mini__strcasecmp(){ 
  if [ ! -z $1 ]; then echo "#define mini__strcasecmp $1" 
	else echo  "#define mini__strcasecmp _strcasecmp"
	fi
}
mini_memfrob(){ 
  if [ ! -z $1 ]; then echo "#define mini_memfrob $1" 
	else echo  "#define mini_memfrob memfrob"
	fi
}
mini_rt_sigprocmask(){ 
  if [ ! -z $1 ]; then echo "#define mini_rt_sigprocmask $1" 
	else echo  "#define mini_rt_sigprocmask rt_sigprocmask"
	fi
}
mini__dup3(){ 
  if [ ! -z $1 ]; then echo "#define mini__dup3 $1" 
	else echo  "#define mini__dup3 _dup3"
	fi
}
mini_seekdir(){ 
  if [ ! -z $1 ]; then echo "#define mini_seekdir $1" 
	else echo  "#define mini_seekdir seekdir"
	fi
}
mini_getdents(){ 
  if [ ! -z $1 ]; then echo "#define mini_getdents $1" 
	else echo  "#define mini_getdents getdents"
	fi
}
mini__set_robust_list(){ 
  if [ ! -z $1 ]; then echo "#define mini__set_robust_list $1" 
	else echo  "#define mini__set_robust_list _set_robust_list"
	fi
}
# --- define_functions-end: generate --- #

