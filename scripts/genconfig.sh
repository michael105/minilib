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
		export OPTFLAG='-O0 -g'
		export STRIPFLAG=""
		export opt_shrinkelf=0
}

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


# Everything below will be silently overwritten,
# when make header ist invoked

# --- define_functions-start: generate --- #
mini__mkdir(){ 
  echo "#define mini__mkdir $1" 
}
mini__madvise(){ 
  echo "#define mini__madvise $1" 
}
mini_sync(){ 
  echo "#define mini_sync $1" 
}
mini_itohex(){ 
  echo "#define mini_itohex $1" 
}
mini__mmap(){ 
  echo "#define mini__mmap $1" 
}
mini__vhangup(){ 
  echo "#define mini__vhangup $1" 
}
mini_vfork(){ 
  echo "#define mini_vfork $1" 
}
mini__vfork(){ 
  echo "#define mini__vfork $1" 
}
mini__epoll_create1(){ 
  echo "#define mini__epoll_create1 $1" 
}
mini_atexit(){ 
  echo "#define mini_atexit $1" 
}
mini__sigaltstack(){ 
  echo "#define mini__sigaltstack $1" 
}
mini__sched_yield(){ 
  echo "#define mini__sched_yield $1" 
}
mini__getppid(){ 
  echo "#define mini__getppid $1" 
}
mini__fstatfs(){ 
  echo "#define mini__fstatfs $1" 
}
mini__sendfile(){ 
  echo "#define mini__sendfile $1" 
}
mini_fexecveat(){ 
  echo "#define mini_fexecveat $1" 
}
mini__write(){ 
  echo "#define mini__write $1" 
}
mini__clock_nanosleep(){ 
  echo "#define mini__clock_nanosleep $1" 
}
mini__adjtimex(){ 
  echo "#define mini__adjtimex $1" 
}
mini__timerfd_create(){ 
  echo "#define mini__timerfd_create $1" 
}
mini__msgget(){ 
  echo "#define mini__msgget $1" 
}
mini__rename(){ 
  echo "#define mini__rename $1" 
}
mini__clock_gettime(){ 
  echo "#define mini__clock_gettime $1" 
}
mini__fchmodat(){ 
  echo "#define mini__fchmodat $1" 
}
mini__timerfd_gettime(){ 
  echo "#define mini__timerfd_gettime $1" 
}
mini_ferror(){ 
  echo "#define mini_ferror $1" 
}
mini__utimes(){ 
  echo "#define mini__utimes $1" 
}
mini_utime(){ 
  echo "#define mini_utime $1" 
}
mini__sync(){ 
  echo "#define mini__sync $1" 
}
mini_isatty(){ 
  echo "#define mini_isatty $1" 
}
mini__exit_group(){ 
  echo "#define mini__exit_group $1" 
}
mini_fgetc(){ 
  echo "#define mini_fgetc $1" 
}
mini__capget(){ 
  echo "#define mini__capget $1" 
}
mini_fchmod(){ 
  echo "#define mini_fchmod $1" 
}
mini_fclose(){ 
  echo "#define mini_fclose $1" 
}
mini_closedir(){ 
  echo "#define mini_closedir $1" 
}
mini__fgetxattr(){ 
  echo "#define mini__fgetxattr $1" 
}
mini__clone(){ 
  echo "#define mini__clone $1" 
}
mini__flistxattr(){ 
  echo "#define mini__flistxattr $1" 
}
mini__gettimeofday(){ 
  echo "#define mini__gettimeofday $1" 
}
mini__semctl(){ 
  echo "#define mini__semctl $1" 
}
mini_clearerror(){ 
  echo "#define mini_clearerror $1" 
}
mini__sched_setaffinity(){ 
  echo "#define mini__sched_setaffinity $1" 
}
mini_fprint(){ 
  echo "#define mini_fprint $1" 
}
mini_nanosleep(){ 
  echo "#define mini_nanosleep $1" 
}
mini__uname(){ 
  echo "#define mini__uname $1" 
}
mini__ioprio_get(){ 
  echo "#define mini__ioprio_get $1" 
}
mini__getrlimit(){ 
  echo "#define mini__getrlimit $1" 
}
mini_dtodec(){ 
  echo "#define mini_dtodec $1" 
}
mini__set_tid_address(){ 
  echo "#define mini__set_tid_address $1" 
}
mini__linkat(){ 
  echo "#define mini__linkat $1" 
}
mini_strcasecmp(){ 
  echo "#define mini_strcasecmp $1" 
}
mini__getdents64(){ 
  echo "#define mini__getdents64 $1" 
}
mini__open(){ 
  echo "#define mini__open $1" 
}
mini__shmget(){ 
  echo "#define mini__shmget $1" 
}
mini__itobin(){ 
  echo "#define mini__itobin $1" 
}
mini_sigprocmask(){ 
  echo "#define mini_sigprocmask $1" 
}
mini_eputs(){ 
  echo "#define mini_eputs $1" 
}
mini_strncpy(){ 
  echo "#define mini_strncpy $1" 
}
mini__prctl(){ 
  echo "#define mini__prctl $1" 
}
mini__truncate(){ 
  echo "#define mini__truncate $1" 
}
mini__execve(){ 
  echo "#define mini__execve $1" 
}
mini_access(){ 
  echo "#define mini_access $1" 
}
mini_dup(){ 
  echo "#define mini_dup $1" 
}
mini__ftruncate(){ 
  echo "#define mini__ftruncate $1" 
}
mini_getchar(){ 
  echo "#define mini_getchar $1" 
}
mini_getitimer(){ 
  echo "#define mini_getitimer $1" 
}
mini_verbose_errstr(){ 
  echo "#define mini_verbose_errstr $1" 
}
mini_ewrites(){ 
  echo "#define mini_ewrites $1" 
}
mini__getsockopt(){ 
  echo "#define mini__getsockopt $1" 
}
mini__pselect6(){ 
  echo "#define mini__pselect6 $1" 
}
mini__rt_sigreturn(){ 
  echo "#define mini__rt_sigreturn $1" 
}
mini__recvmmsg(){ 
  echo "#define mini__recvmmsg $1" 
}
mini_perror(){ 
  echo "#define mini_perror $1" 
}
mini__getpgrp(){ 
  echo "#define mini__getpgrp $1" 
}
mini_getuid(){ 
  echo "#define mini_getuid $1" 
}
mini__inotify_init(){ 
  echo "#define mini__inotify_init $1" 
}
mini_rt_sigreturn(){ 
  echo "#define mini_rt_sigreturn $1" 
}
mini__getgroups(){ 
  echo "#define mini__getgroups $1" 
}
mini_ltodec(){ 
  echo "#define mini_ltodec $1" 
}
mini_div(){ 
  echo "#define mini_div $1" 
}
mini__setgid(){ 
  echo "#define mini__setgid $1" 
}
mini__set_mempolicy(){ 
  echo "#define mini__set_mempolicy $1" 
}
mini_fsetpos(){ 
  echo "#define mini_fsetpos $1" 
}
mini_ptsname_r(){ 
  echo "#define mini_ptsname_r $1" 
}
mini__sched_get_priority_max(){ 
  echo "#define mini__sched_get_priority_max $1" 
}
mini__unshare(){ 
  echo "#define mini__unshare $1" 
}
mini__kexec_file_load(){ 
  echo "#define mini__kexec_file_load $1" 
}
mini__umask(){ 
  echo "#define mini__umask $1" 
}
mini_getenv(){ 
  echo "#define mini_getenv $1" 
}
mini_ungetc(){ 
  echo "#define mini_ungetc $1" 
}
mini__setfsuid(){ 
  echo "#define mini__setfsuid $1" 
}
mini__brk(){ 
  echo "#define mini__brk $1" 
}
mini__dup3(){ 
  echo "#define mini__dup3 $1" 
}
mini_execvpe(){ 
  echo "#define mini_execvpe $1" 
}
mini__munmap(){ 
  echo "#define mini__munmap $1" 
}
mini_mmap(){ 
  echo "#define mini_mmap $1" 
}
mini_fputc(){ 
  echo "#define mini_fputc $1" 
}
mini_feof(){ 
  echo "#define mini_feof $1" 
}
mini__sched_setparam(){ 
  echo "#define mini__sched_setparam $1" 
}
mini__process_vm_writev(){ 
  echo "#define mini__process_vm_writev $1" 
}
mini__timer_settime(){ 
  echo "#define mini__timer_settime $1" 
}
mini__gettid(){ 
  echo "#define mini__gettid $1" 
}
mini__alarm(){ 
  echo "#define mini__alarm $1" 
}
mini_sigaction(){ 
  echo "#define mini_sigaction $1" 
}
mini__sendmmsg(){ 
  echo "#define mini__sendmmsg $1" 
}
mini__readlink(){ 
  echo "#define mini__readlink $1" 
}
mini_getgid(){ 
  echo "#define mini_getgid $1" 
}
mini__poll(){ 
  echo "#define mini__poll $1" 
}
mini__connect(){ 
  echo "#define mini__connect $1" 
}
mini__mlockall(){ 
  echo "#define mini__mlockall $1" 
}
mini_fprintf(){ 
  echo "#define mini_fprintf $1" 
}
mini_execveat(){ 
  echo "#define mini_execveat $1" 
}
mini__rt_sigpending(){ 
  echo "#define mini__rt_sigpending $1" 
}
mini__quotactl(){ 
  echo "#define mini__quotactl $1" 
}
mini__name_to_handle_at(){ 
  echo "#define mini__name_to_handle_at $1" 
}
mini_stat(){ 
  echo "#define mini_stat $1" 
}
mini__syslog(){ 
  echo "#define mini__syslog $1" 
}
mini_def(){ 
  echo "#define mini_def $1" 
}
mini_getc(){ 
  echo "#define mini_getc $1" 
}
mini__ustat(){ 
  echo "#define mini__ustat $1" 
}
mini__clock_adjtime(){ 
  echo "#define mini__clock_adjtime $1" 
}
mini_time(){ 
  echo "#define mini_time $1" 
}
mini__rt_sigqueueinfo(){ 
  echo "#define mini__rt_sigqueueinfo $1" 
}
mini_itodec(){ 
  echo "#define mini_itodec $1" 
}
mini__strcasecmp(){ 
  echo "#define mini__strcasecmp $1" 
}
mini__fanotify_mark(){ 
  echo "#define mini__fanotify_mark $1" 
}
mini__getcwd(){ 
  echo "#define mini__getcwd $1" 
}
mini__openat(){ 
  echo "#define mini__openat $1" 
}
mini__mq_getsetattr(){ 
  echo "#define mini__mq_getsetattr $1" 
}
mini__link(){ 
  echo "#define mini__link $1" 
}
mini__seccomp(){ 
  echo "#define mini__seccomp $1" 
}
mini_brk(){ 
  echo "#define mini_brk $1" 
}
mini__sched_setattr(){ 
  echo "#define mini__sched_setattr $1" 
}
mini__timer_create(){ 
  echo "#define mini__timer_create $1" 
}
mini__shmctl(){ 
  echo "#define mini__shmctl $1" 
}
mini_fcntl(){ 
  echo "#define mini_fcntl $1" 
}
mini__fopen(){ 
  echo "#define mini__fopen $1" 
}
mini_dup3(){ 
  echo "#define mini_dup3 $1" 
}
mini_uname(){ 
  echo "#define mini_uname $1" 
}
mini_creat(){ 
  echo "#define mini_creat $1" 
}
mini__faccessat(){ 
  echo "#define mini__faccessat $1" 
}
mini__symlink(){ 
  echo "#define mini__symlink $1" 
}
mini__select(){ 
  echo "#define mini__select $1" 
}
mini__setuid(){ 
  echo "#define mini__setuid $1" 
}
mini__pipe(){ 
  echo "#define mini__pipe $1" 
}
mini_fchown(){ 
  echo "#define mini_fchown $1" 
}
mini_splice(){ 
  echo "#define mini_splice $1" 
}
mini__getresgid(){ 
  echo "#define mini__getresgid $1" 
}
mini_vsnprintf(){ 
  echo "#define mini_vsnprintf $1" 
}
mini__swapon(){ 
  echo "#define mini__swapon $1" 
}
mini_putc(){ 
  echo "#define mini_putc $1" 
}
mini__fadvise64(){ 
  echo "#define mini__fadvise64 $1" 
}
mini__pwrite64(){ 
  echo "#define mini__pwrite64 $1" 
}
mini_sigdelset(){ 
  echo "#define mini_sigdelset $1" 
}
mini_sigfillset(){ 
  echo "#define mini_sigfillset $1" 
}
mini__rt_sigprocmask(){ 
  echo "#define mini__rt_sigprocmask $1" 
}
mini__getcpu(){ 
  echo "#define mini__getcpu $1" 
}
mini__getpriority(){ 
  echo "#define mini__getpriority $1" 
}
mini__semget(){ 
  echo "#define mini__semget $1" 
}
mini__acct(){ 
  echo "#define mini__acct $1" 
}
mini_sleep(){ 
  echo "#define mini_sleep $1" 
}
mini_unlink(){ 
  echo "#define mini_unlink $1" 
}
mini_readdir(){ 
  echo "#define mini_readdir $1" 
}
mini_fread(){ 
  echo "#define mini_fread $1" 
}
mini__open_by_handle_at(){ 
  echo "#define mini__open_by_handle_at $1" 
}
mini__tkill(){ 
  echo "#define mini__tkill $1" 
}
mini__keyctl(){ 
  echo "#define mini__keyctl $1" 
}
mini__setxattr(){ 
  echo "#define mini__setxattr $1" 
}
mini__msgctl(){ 
  echo "#define mini__msgctl $1" 
}
mini__semtimedop(){ 
  echo "#define mini__semtimedop $1" 
}
mini__setitimer(){ 
  echo "#define mini__setitimer $1" 
}
mini__mq_timedreceive(){ 
  echo "#define mini__mq_timedreceive $1" 
}
mini_fflush(){ 
  echo "#define mini_fflush $1" 
}
mini__epoll_create(){ 
  echo "#define mini__epoll_create $1" 
}
mini_strchrnul(){ 
  echo "#define mini_strchrnul $1" 
}
mini_rand(){ 
  echo "#define mini_rand $1" 
}
mini_putchar(){ 
  echo "#define mini_putchar $1" 
}
mini__syncfs(){ 
  echo "#define mini__syncfs $1" 
}
mini__dup(){ 
  echo "#define mini__dup $1" 
}
mini__setsid(){ 
  echo "#define mini__setsid $1" 
}
mini_printsl(){ 
  echo "#define mini_printsl $1" 
}
mini__kill(){ 
  echo "#define mini__kill $1" 
}
mini__mknodat(){ 
  echo "#define mini__mknodat $1" 
}
mini__init_module(){ 
  echo "#define mini__init_module $1" 
}
mini__getpid(){ 
  echo "#define mini__getpid $1" 
}
mini__sched_setscheduler(){ 
  echo "#define mini__sched_setscheduler $1" 
}
mini__set_robust_list(){ 
  echo "#define mini__set_robust_list $1" 
}
mini__setpgid(){ 
  echo "#define mini__setpgid $1" 
}
mini_munmap(){ 
  echo "#define mini_munmap $1" 
}
mini_open(){ 
  echo "#define mini_open $1" 
}
mini_prints(){ 
  echo "#define mini_prints $1" 
}
mini_verbose_errstr2(){ 
  echo "#define mini_verbose_errstr2 $1" 
}
mini_sdbm_hash(){ 
  echo "#define mini_sdbm_hash $1" 
}
mini__lseek(){ 
  echo "#define mini__lseek $1" 
}
mini__io_cancel(){ 
  echo "#define mini__io_cancel $1" 
}
mini__sysfs(){ 
  echo "#define mini__sysfs $1" 
}
mini_strchr(){ 
  echo "#define mini_strchr $1" 
}
mini__finit_module(){ 
  echo "#define mini__finit_module $1" 
}
mini__dup2(){ 
  echo "#define mini__dup2 $1" 
}
mini__readv(){ 
  echo "#define mini__readv $1" 
}
mini__ioperm(){ 
  echo "#define mini__ioperm $1" 
}
mini_setvbuf(){ 
  echo "#define mini_setvbuf $1" 
}
mini__utime(){ 
  echo "#define mini__utime $1" 
}
mini_sprintf(){ 
  echo "#define mini_sprintf $1" 
}
mini__shmat(){ 
  echo "#define mini__shmat $1" 
}
mini_fprints(){ 
  echo "#define mini_fprints $1" 
}
mini__newfstatat(){ 
  echo "#define mini__newfstatat $1" 
}
mini_strlen(){ 
  echo "#define mini_strlen $1" 
}
mini__mq_timedsend(){ 
  echo "#define mini__mq_timedsend $1" 
}
mini__unlinkat(){ 
  echo "#define mini__unlinkat $1" 
}
mini_close(){ 
  echo "#define mini_close $1" 
}
mini__migrate_pages(){ 
  echo "#define mini__migrate_pages $1" 
}
mini__setfsgid(){ 
  echo "#define mini__setfsgid $1" 
}
mini_strncasecmp(){ 
  echo "#define mini_strncasecmp $1" 
}
mini_seekdir(){ 
  echo "#define mini_seekdir $1" 
}
mini_fstat(){ 
  echo "#define mini_fstat $1" 
}
mini_vhangup(){ 
  echo "#define mini_vhangup $1" 
}
mini__io_setup(){ 
  echo "#define mini__io_setup $1" 
}
mini__fchownat(){ 
  echo "#define mini__fchownat $1" 
}
mini_fileno(){ 
  echo "#define mini_fileno $1" 
}
mini_tcgetattr(){ 
  echo "#define mini_tcgetattr $1" 
}
mini_execl(){ 
  echo "#define mini_execl $1" 
}
mini__personality(){ 
  echo "#define mini__personality $1" 
}
mini__capset(){ 
  echo "#define mini__capset $1" 
}
mini__reboot(){ 
  echo "#define mini__reboot $1" 
}
mini__semop(){ 
  echo "#define mini__semop $1" 
}
mini__getrandom(){ 
  echo "#define mini__getrandom $1" 
}
mini__perf_event_open(){ 
  echo "#define mini__perf_event_open $1" 
}
mini__signalfd(){ 
  echo "#define mini__signalfd $1" 
}
mini_chroot(){ 
  echo "#define mini_chroot $1" 
}
mini__umount2(){ 
  echo "#define mini__umount2 $1" 
}
mini__rmdir(){ 
  echo "#define mini__rmdir $1" 
}
mini_dirname(){ 
  echo "#define mini_dirname $1" 
}
mini_free(){ 
  echo "#define mini_free $1" 
}
mini_chdir(){ 
  echo "#define mini_chdir $1" 
}
mini_sigemptyset(){ 
  echo "#define mini_sigemptyset $1" 
}
mini__request_key(){ 
  echo "#define mini__request_key $1" 
}
mini__inotify_init1(){ 
  echo "#define mini__inotify_init1 $1" 
}
mini_grantpt(){ 
  echo "#define mini_grantpt $1" 
}
mini__timer_delete(){ 
  echo "#define mini__timer_delete $1" 
}
mini__sched_rr_get_interval(){ 
  echo "#define mini__sched_rr_get_interval $1" 
}
mini_ftell(){ 
  echo "#define mini_ftell $1" 
}
mini_dirfd(){ 
  echo "#define mini_dirfd $1" 
}
mini__llistxattr(){ 
  echo "#define mini__llistxattr $1" 
}
mini__futimesat(){ 
  echo "#define mini__futimesat $1" 
}
mini__lgetxattr(){ 
  echo "#define mini__lgetxattr $1" 
}
mini_mkfifo(){ 
  echo "#define mini_mkfifo $1" 
}
mini_ioctl(){ 
  echo "#define mini_ioctl $1" 
}
mini__pwritev(){ 
  echo "#define mini__pwritev $1" 
}
mini__epoll_wait(){ 
  echo "#define mini__epoll_wait $1" 
}
mini_write(){ 
  echo "#define mini_write $1" 
}
mini_eprintfs(){ 
  echo "#define mini_eprintfs $1" 
}
mini__epoll_pwait(){ 
  echo "#define mini__epoll_pwait $1" 
}
mini_memfrob(){ 
  echo "#define mini_memfrob $1" 
}
mini_atoi(){ 
  echo "#define mini_atoi $1" 
}
mini_mknod(){ 
  echo "#define mini_mknod $1" 
}
mini_strcat(){ 
  echo "#define mini_strcat $1" 
}
mini_setsid(){ 
  echo "#define mini_setsid $1" 
}
mini__setdomainname(){ 
  echo "#define mini__setdomainname $1" 
}
mini__times(){ 
  echo "#define mini__times $1" 
}
mini__add_key(){ 
  echo "#define mini__add_key $1" 
}
mini__mremap(){ 
  echo "#define mini__mremap $1" 
}
mini_signal(){ 
  echo "#define mini_signal $1" 
}
mini_ptsname(){ 
  echo "#define mini_ptsname $1" 
}
mini_kill(){ 
  echo "#define mini_kill $1" 
}
mini__kcmp(){ 
  echo "#define mini__kcmp $1" 
}
mini_lseek(){ 
  echo "#define mini_lseek $1" 
}
mini__getresuid(){ 
  echo "#define mini__getresuid $1" 
}
mini_chmod(){ 
  echo "#define mini_chmod $1" 
}
mini__io_getevents(){ 
  echo "#define mini__io_getevents $1" 
}
mini__setns(){ 
  echo "#define mini__setns $1" 
}
mini__kexec_load(){ 
  echo "#define mini__kexec_load $1" 
}
mini_mkdir(){ 
  echo "#define mini_mkdir $1" 
}
mini_pivot_root(){ 
  echo "#define mini_pivot_root $1" 
}
mini__setpriority(){ 
  echo "#define mini__setpriority $1" 
}
mini_sys_brk(){ 
  echo "#define mini_sys_brk $1" 
}
mini_dprintf(){ 
  echo "#define mini_dprintf $1" 
}
mini_link(){ 
  echo "#define mini_link $1" 
}
mini_uitodec(){ 
  echo "#define mini_uitodec $1" 
}
mini__readahead(){ 
  echo "#define mini__readahead $1" 
}
mini__mprints(){ 
  echo "#define mini__mprints $1" 
}
mini__getuid(){ 
  echo "#define mini__getuid $1" 
}
mini__timer_getoverrun(){ 
  echo "#define mini__timer_getoverrun $1" 
}
mini_eprints(){ 
  echo "#define mini_eprints $1" 
}
mini__rt_tgsigqueueinfo(){ 
  echo "#define mini__rt_tgsigqueueinfo $1" 
}
mini__sched_getattr(){ 
  echo "#define mini__sched_getattr $1" 
}
mini__splice(){ 
  echo "#define mini__splice $1" 
}
mini__fstat(){ 
  echo "#define mini__fstat $1" 
}
mini__setresgid(){ 
  echo "#define mini__setresgid $1" 
}
mini__strcmp(){ 
  echo "#define mini__strcmp $1" 
}
mini_strtol(){ 
  echo "#define mini_strtol $1" 
}
mini__getpeername(){ 
  echo "#define mini__getpeername $1" 
}
mini__sethostname(){ 
  echo "#define mini__sethostname $1" 
}
mini_ldiv(){ 
  echo "#define mini_ldiv $1" 
}
mini_todo_putenv(){ 
  echo "#define mini_todo_putenv $1" 
}
mini__futex(){ 
  echo "#define mini__futex $1" 
}
mini__mlock(){ 
  echo "#define mini__mlock $1" 
}
mini__mincore(){ 
  echo "#define mini__mincore $1" 
}
mini__getsockname(){ 
  echo "#define mini__getsockname $1" 
}
mini__removexattr(){ 
  echo "#define mini__removexattr $1" 
}
mini__flock(){ 
  echo "#define mini__flock $1" 
}
mini_waitpid(){ 
  echo "#define mini_waitpid $1" 
}
mini_mremap(){ 
  echo "#define mini_mremap $1" 
}
mini__itohex(){ 
  echo "#define mini__itohex $1" 
}
mini_errno(){ 
  echo "#define mini_errno $1" 
}
mini_strcmp(){ 
  echo "#define mini_strcmp $1" 
}
mini_memset(){ 
  echo "#define mini_memset $1" 
}
mini_printfs(){ 
  echo "#define mini_printfs $1" 
}
mini_mount(){ 
  echo "#define mini_mount $1" 
}
mini_sigaddset(){ 
  echo "#define mini_sigaddset $1" 
}
mini__socket(){ 
  echo "#define mini__socket $1" 
}
mini__symlinkat(){ 
  echo "#define mini__symlinkat $1" 
}
mini_getdents(){ 
  echo "#define mini_getdents $1" 
}
mini__statfs(){ 
  echo "#define mini__statfs $1" 
}
mini__chdir(){ 
  echo "#define mini__chdir $1" 
}
mini__creat(){ 
  echo "#define mini__creat $1" 
}
mini__geteuid(){ 
  echo "#define mini__geteuid $1" 
}
mini__readlinkat(){ 
  echo "#define mini__readlinkat $1" 
}
mini_umask(){ 
  echo "#define mini_umask $1" 
}
mini_rename(){ 
  echo "#define mini_rename $1" 
}
mini__get_robust_list(){ 
  echo "#define mini__get_robust_list $1" 
}
mini_select(){ 
  echo "#define mini_select $1" 
}
mini__getpgid(){ 
  echo "#define mini__getpgid $1" 
}
mini_fprintfs(){ 
  echo "#define mini_fprintfs $1" 
}
mini__wait4(){ 
  echo "#define mini__wait4 $1" 
}
mini_fdopen(){ 
  echo "#define mini_fdopen $1" 
}
mini__fsync(){ 
  echo "#define mini__fsync $1" 
}
mini__lremovexattr(){ 
  echo "#define mini__lremovexattr $1" 
}
mini__msync(){ 
  echo "#define mini__msync $1" 
}
mini_setbuf(){ 
  echo "#define mini_setbuf $1" 
}
mini_strdup(){ 
  echo "#define mini_strdup $1" 
}
mini__getsid(){ 
  echo "#define mini__getsid $1" 
}
mini__fsetxattr(){ 
  echo "#define mini__fsetxattr $1" 
}
mini__mq_unlink(){ 
  echo "#define mini__mq_unlink $1" 
}
mini__memfd_create(){ 
  echo "#define mini__memfd_create $1" 
}
mini__sysinfo(){ 
  echo "#define mini__sysinfo $1" 
}
mini__setregid(){ 
  echo "#define mini__setregid $1" 
}
mini__sched_getscheduler(){ 
  echo "#define mini__sched_getscheduler $1" 
}
mini__getitimer(){ 
  echo "#define mini__getitimer $1" 
}
mini__socketpair(){ 
  echo "#define mini__socketpair $1" 
}
mini__chroot(){ 
  echo "#define mini__chroot $1" 
}
mini__getxattr(){ 
  echo "#define mini__getxattr $1" 
}
mini_labs(){ 
  echo "#define mini_labs $1" 
}
mini_exit(){ 
  echo "#define mini_exit $1" 
}
mini__renameat(){ 
  echo "#define mini__renameat $1" 
}
mini__fchmod(){ 
  echo "#define mini__fchmod $1" 
}
mini__tgkill(){ 
  echo "#define mini__tgkill $1" 
}
mini__access(){ 
  echo "#define mini__access $1" 
}
mini__fcntl(){ 
  echo "#define mini__fcntl $1" 
}
mini_rt_sigprocmask(){ 
  echo "#define mini_rt_sigprocmask $1" 
}
mini__rt_sigsuspend(){ 
  echo "#define mini__rt_sigsuspend $1" 
}
mini_readahead(){ 
  echo "#define mini_readahead $1" 
}
mini__chmod(){ 
  echo "#define mini__chmod $1" 
}
mini_raise(){ 
  echo "#define mini_raise $1" 
}
mini__close(){ 
  echo "#define mini__close $1" 
}
mini__lchown(){ 
  echo "#define mini__lchown $1" 
}
mini_strstr(){ 
  echo "#define mini_strstr $1" 
}
mini_basename(){ 
  echo "#define mini_basename $1" 
}
mini_gets(){ 
  echo "#define mini_gets $1" 
}
mini_djb2_hash(){ 
  echo "#define mini_djb2_hash $1" 
}
mini__getrusage(){ 
  echo "#define mini__getrusage $1" 
}
mini__io_submit(){ 
  echo "#define mini__io_submit $1" 
}
mini__mount(){ 
  echo "#define mini__mount $1" 
}
mini__io_destroy(){ 
  echo "#define mini__io_destroy $1" 
}
mini__fallocate(){ 
  echo "#define mini__fallocate $1" 
}
mini_fsync(){ 
  echo "#define mini_fsync $1" 
}
mini_umount2(){ 
  echo "#define mini_umount2 $1" 
}
mini_realloc(){ 
  echo "#define mini_realloc $1" 
}
mini_ftruncate(){ 
  echo "#define mini_ftruncate $1" 
}
mini__epoll_ctl(){ 
  echo "#define mini__epoll_ctl $1" 
}
mini_fexecve(){ 
  echo "#define mini_fexecve $1" 
}
mini_macro(){ 
  echo "#define mini_macro $1" 
}
mini__mknod(){ 
  echo "#define mini__mknod $1" 
}
mini_unlockpt(){ 
  echo "#define mini_unlockpt $1" 
}
mini_fopen(){ 
  echo "#define mini_fopen $1" 
}
mini__ppoll(){ 
  echo "#define mini__ppoll $1" 
}
mini__inotify_add_watch(){ 
  echo "#define mini__inotify_add_watch $1" 
}
mini_wait(){ 
  echo "#define mini_wait $1" 
}
mini__shutdown(){ 
  echo "#define mini__shutdown $1" 
}
mini__writev(){ 
  echo "#define mini__writev $1" 
}
mini__msgrcv(){ 
  echo "#define mini__msgrcv $1" 
}
mini__waitid(){ 
  echo "#define mini__waitid $1" 
}
mini_fwrite(){ 
  echo "#define mini_fwrite $1" 
}
mini__preadv(){ 
  echo "#define mini__preadv $1" 
}
mini__utimensat(){ 
  echo "#define mini__utimensat $1" 
}
mini_vfprintf(){ 
  echo "#define mini_vfprintf $1" 
}
mini_system(){ 
  echo "#define mini_system $1" 
}
mini__setresuid(){ 
  echo "#define mini__setresuid $1" 
}
mini_ultodec(){ 
  echo "#define mini_ultodec $1" 
}
mini_dup2(){ 
  echo "#define mini_dup2 $1" 
}
mini_environ(){ 
  echo "#define mini_environ $1" 
}
mini_setpgid(){ 
  echo "#define mini_setpgid $1" 
}
mini__inotify_rm_watch(){ 
  echo "#define mini__inotify_rm_watch $1" 
}
mini__delete_module(){ 
  echo "#define mini__delete_module $1" 
}
mini__iopl(){ 
  echo "#define mini__iopl $1" 
}
mini_rewind(){ 
  echo "#define mini_rewind $1" 
}
mini__fork(){ 
  echo "#define mini__fork $1" 
}
mini__renameat2(){ 
  echo "#define mini__renameat2 $1" 
}
mini_abort(){ 
  echo "#define mini_abort $1" 
}
mini_fork(){ 
  echo "#define mini_fork $1" 
}
mini_rt_sigaction(){ 
  echo "#define mini_rt_sigaction $1" 
}
mini_execv(){ 
  echo "#define mini_execv $1" 
}
mini__mbind(){ 
  echo "#define mini__mbind $1" 
}
mini__eventfd2(){ 
  echo "#define mini__eventfd2 $1" 
}
mini__signalfd4(){ 
  echo "#define mini__signalfd4 $1" 
}
mini_memcmp(){ 
  echo "#define mini_memcmp $1" 
}
mini__ioctl(){ 
  echo "#define mini__ioctl $1" 
}
mini__nanosleep(){ 
  echo "#define mini__nanosleep $1" 
}
mini__move_pages(){ 
  echo "#define mini__move_pages $1" 
}
mini_execve(){ 
  echo "#define mini_execve $1" 
}
mini_setitimer(){ 
  echo "#define mini_setitimer $1" 
}
mini__clock_getres(){ 
  echo "#define mini__clock_getres $1" 
}
mini_itobin(){ 
  echo "#define mini_itobin $1" 
}
mini_fgets(){ 
  echo "#define mini_fgets $1" 
}
mini_fwrites(){ 
  echo "#define mini_fwrites $1" 
}
mini__shmdt(){ 
  echo "#define mini__shmdt $1" 
}
mini__pivot_root(){ 
  echo "#define mini__pivot_root $1" 
}
mini__sched_get_priority_min(){ 
  echo "#define mini__sched_get_priority_min $1" 
}
mini__fchown(){ 
  echo "#define mini__fchown $1" 
}
mini_clearerr(){ 
  echo "#define mini_clearerr $1" 
}
mini__getdents(){ 
  echo "#define mini__getdents $1" 
}
mini_abs(){ 
  echo "#define mini_abs $1" 
}
mini_opendir(){ 
  echo "#define mini_opendir $1" 
}
mini_setuid(){ 
  echo "#define mini_setuid $1" 
}
mini__exit(){ 
  echo "#define mini__exit $1" 
}
mini__fanotify_init(){ 
  echo "#define mini__fanotify_init $1" 
}
mini_getcwd(){ 
  echo "#define mini_getcwd $1" 
}
mini__clock_settime(){ 
  echo "#define mini__clock_settime $1" 
}
mini_sbrk(){ 
  echo "#define mini_sbrk $1" 
}
mini_globals(){ 
  echo "#define mini_globals $1" 
}
mini__unlink(){ 
  echo "#define mini__unlink $1" 
}
mini_reboot(){ 
  echo "#define mini_reboot $1" 
}
mini__rt_sigtimedwait(){ 
  echo "#define mini__rt_sigtimedwait $1" 
}
mini_read(){ 
  echo "#define mini_read $1" 
}
mini__sendto(){ 
  echo "#define mini__sendto $1" 
}
mini__timerfd_settime(){ 
  echo "#define mini__timerfd_settime $1" 
}
mini__munlockall(){ 
  echo "#define mini__munlockall $1" 
}
mini__arch_prctl(){ 
  echo "#define mini__arch_prctl $1" 
}
mini__munlock(){ 
  echo "#define mini__munlock $1" 
}
mini__lookup_dcookie(){ 
  echo "#define mini__lookup_dcookie $1" 
}
mini_gettimeofday(){ 
  echo "#define mini_gettimeofday $1" 
}
mini__stat(){ 
  echo "#define mini__stat $1" 
}
mini__ioprio_set(){ 
  echo "#define mini__ioprio_set $1" 
}
mini_mprotect(){ 
  echo "#define mini_mprotect $1" 
}
mini_puts(){ 
  echo "#define mini_puts $1" 
}
mini_atol(){ 
  echo "#define mini_atol $1" 
}
mini_dprints(){ 
  echo "#define mini_dprints $1" 
}
mini__setreuid(){ 
  echo "#define mini__setreuid $1" 
}
mini_setgid(){ 
  echo "#define mini_setgid $1" 
}
mini__sched_getaffinity(){ 
  echo "#define mini__sched_getaffinity $1" 
}
mini__setrlimit(){ 
  echo "#define mini__setrlimit $1" 
}
mini__mprotect(){ 
  echo "#define mini__mprotect $1" 
}
mini_exit_errno(){ 
  echo "#define mini_exit_errno $1" 
}
mini_print(){ 
  echo "#define mini_print $1" 
}
mini_posix_openpt(){ 
  echo "#define mini_posix_openpt $1" 
}
mini__settimeofday(){ 
  echo "#define mini__settimeofday $1" 
}
mini_memcpy(){ 
  echo "#define mini_memcpy $1" 
}
mini_itoHEX(){ 
  echo "#define mini_itoHEX $1" 
}
mini_rmdir(){ 
  echo "#define mini_rmdir $1" 
}
mini__remap_file_pages(){ 
  echo "#define mini__remap_file_pages $1" 
}
mini__accept4(){ 
  echo "#define mini__accept4 $1" 
}
mini_pipe(){ 
  echo "#define mini_pipe $1" 
}
mini__accept(){ 
  echo "#define mini__accept $1" 
}
mini_tolower(){ 
  echo "#define mini_tolower $1" 
}
mini__rt_sigaction(){ 
  echo "#define mini__rt_sigaction $1" 
}
mini_freopen(){ 
  echo "#define mini_freopen $1" 
}
mini__listen(){ 
  echo "#define mini__listen $1" 
}
mini_strncmp(){ 
  echo "#define mini_strncmp $1" 
}
mini__swapoff(){ 
  echo "#define mini__swapoff $1" 
}
mini_printf(){ 
  echo "#define mini_printf $1" 
}
mini__listxattr(){ 
  echo "#define mini__listxattr $1" 
}
mini_errno_str(){ 
  echo "#define mini_errno_str $1" 
}
mini__modify_ldt(){ 
  echo "#define mini__modify_ldt $1" 
}
mini_fgetpos(){ 
  echo "#define mini_fgetpos $1" 
}
mini__get_mempolicy(){ 
  echo "#define mini__get_mempolicy $1" 
}
mini__getgid(){ 
  echo "#define mini__getgid $1" 
}
mini__pipe2(){ 
  echo "#define mini__pipe2 $1" 
}
mini__read(){ 
  echo "#define mini__read $1" 
}
mini_tcsetattr(){ 
  echo "#define mini_tcsetattr $1" 
}
mini__sync_file_range(){ 
  echo "#define mini__sync_file_range $1" 
}
mini__lstat(){ 
  echo "#define mini__lstat $1" 
}
mini__restart_syscall(){ 
  echo "#define mini__restart_syscall $1" 
}
mini__tee(){ 
  echo "#define mini__tee $1" 
}
mini_getpid(){ 
  echo "#define mini_getpid $1" 
}
mini__ptrace(){ 
  echo "#define mini__ptrace $1" 
}
mini__sched_getparam(){ 
  echo "#define mini__sched_getparam $1" 
}
mini_wait4(){ 
  echo "#define mini_wait4 $1" 
}
mini__setgroups(){ 
  echo "#define mini__setgroups $1" 
}
mini_chown(){ 
  echo "#define mini_chown $1" 
}
mini_strerror(){ 
  echo "#define mini_strerror $1" 
}
mini_getppid(){ 
  echo "#define mini_getppid $1" 
}
mini__mq_notify(){ 
  echo "#define mini__mq_notify $1" 
}
mini__timer_gettime(){ 
  echo "#define mini__timer_gettime $1" 
}
mini__bind(){ 
  echo "#define mini__bind $1" 
}
mini__fchdir(){ 
  echo "#define mini__fchdir $1" 
}
mini_sendfile(){ 
  echo "#define mini_sendfile $1" 
}
mini_memmove(){ 
  echo "#define mini_memmove $1" 
}
mini__setsockopt(){ 
  echo "#define mini__setsockopt $1" 
}
mini__prlimit64(){ 
  echo "#define mini__prlimit64 $1" 
}
mini_setgroups(){ 
  echo "#define mini_setgroups $1" 
}
mini__fdatasync(){ 
  echo "#define mini__fdatasync $1" 
}
mini_vexec(){ 
  echo "#define mini_vexec $1" 
}
mini_usleep(){ 
  echo "#define mini_usleep $1" 
}
mini_malloc(){ 
  echo "#define mini_malloc $1" 
}
mini__mkdirat(){ 
  echo "#define mini__mkdirat $1" 
}
mini__vmsplice(){ 
  echo "#define mini__vmsplice $1" 
}
mini__process_vm_readv(){ 
  echo "#define mini__process_vm_readv $1" 
}
mini_sigismember(){ 
  echo "#define mini_sigismember $1" 
}
mini__eventfd(){ 
  echo "#define mini__eventfd $1" 
}
mini__msgsnd(){ 
  echo "#define mini__msgsnd $1" 
}
mini__sendmsg(){ 
  echo "#define mini__sendmsg $1" 
}
mini_telldir(){ 
  echo "#define mini_telldir $1" 
}
mini_snprintf(){ 
  echo "#define mini_snprintf $1" 
}
mini__recvfrom(){ 
  echo "#define mini__recvfrom $1" 
}
mini_eprint(){ 
  echo "#define mini_eprint $1" 
}
mini_strcpy(){ 
  echo "#define mini_strcpy $1" 
}
mini__time(){ 
  echo "#define mini__time $1" 
}
mini__getegid(){ 
  echo "#define mini__getegid $1" 
}
mini_symlink(){ 
  echo "#define mini_symlink $1" 
}
mini__pread64(){ 
  echo "#define mini__pread64 $1" 
}
mini__fremovexattr(){ 
  echo "#define mini__fremovexattr $1" 
}
mini_memfd_create(){ 
  echo "#define mini_memfd_create $1" 
}
mini_fseek(){ 
  echo "#define mini_fseek $1" 
}
mini__recvmsg(){ 
  echo "#define mini__recvmsg $1" 
}
mini__pause(){ 
  echo "#define mini__pause $1" 
}
mini__lsetxattr(){ 
  echo "#define mini__lsetxattr $1" 
}
mini_getpgrp(){ 
  echo "#define mini_getpgrp $1" 
}
mini_printl(){ 
  echo "#define mini_printl $1" 
}
mini_eprintl(){ 
  echo "#define mini_eprintl $1" 
}
mini_fputs(){ 
  echo "#define mini_fputs $1" 
}
mini_srand(){ 
  echo "#define mini_srand $1" 
}
mini_writes(){ 
  echo "#define mini_writes $1" 
}
mini_execvp(){ 
  echo "#define mini_execvp $1" 
}
mini__mq_open(){ 
  echo "#define mini__mq_open $1" 
}
mini__chown(){ 
  echo "#define mini__chown $1" 
}
mini_rewinddir(){ 
  echo "#define mini_rewinddir $1" 
}
mini___sysctl(){ 
  echo "#define mini___sysctl $1" 
}
mini_strrchr(){ 
  echo "#define mini_strrchr $1" 
}
# --- define_functions-end: generate --- #

