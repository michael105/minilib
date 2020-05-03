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
		export LDSCRIPT="ld_script_$1" 
}

shrinkelf(){
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

mini_HEADERGUARDS(){
		echo "#define HEADERGUARDS"
}


HEADERGUARDS(){
		echo "#define HEADERGUARDS"
}



# Everything below will be silently overwritten,
# when make header ist invoked

# --- define_functions-start: generate --- #
mini_itoHEX(){ 
  echo "#define mini_itoHEX generate" 
}
mini_getcwd(){ 
  echo "#define mini_getcwd generate" 
}
mini_read(){ 
  echo "#define mini_read generate" 
}
mini__timerfd_settime(){ 
  echo "#define mini__timerfd_settime generate" 
}
mini_getpid(){ 
  echo "#define mini_getpid generate" 
}
mini__setfsgid(){ 
  echo "#define mini__setfsgid generate" 
}
mini__tee(){ 
  echo "#define mini__tee generate" 
}
mini_atoi(){ 
  echo "#define mini_atoi generate" 
}
mini__mkdir(){ 
  echo "#define mini__mkdir generate" 
}
mini__delete_module(){ 
  echo "#define mini__delete_module generate" 
}
mini__acct(){ 
  echo "#define mini__acct generate" 
}
mini__shmat(){ 
  echo "#define mini__shmat generate" 
}
mini_time(){ 
  echo "#define mini_time generate" 
}
mini__geteuid(){ 
  echo "#define mini__geteuid generate" 
}
mini_unlink(){ 
  echo "#define mini_unlink generate" 
}
mini__signalfd4(){ 
  echo "#define mini__signalfd4 generate" 
}
mini__syncfs(){ 
  echo "#define mini__syncfs generate" 
}
mini__mremap(){ 
  echo "#define mini__mremap generate" 
}
mini__sendfile(){ 
  echo "#define mini__sendfile generate" 
}
mini_itodec(){ 
  echo "#define mini_itodec generate" 
}
mini__setpriority(){ 
  echo "#define mini__setpriority generate" 
}
mini__rt_sigtimedwait(){ 
  echo "#define mini__rt_sigtimedwait generate" 
}
mini__sched_getaffinity(){ 
  echo "#define mini__sched_getaffinity generate" 
}
mini_open(){ 
  echo "#define mini_open generate" 
}
mini_rand(){ 
  echo "#define mini_rand generate" 
}
mini__recvfrom(){ 
  echo "#define mini__recvfrom generate" 
}
mini__set_robust_list(){ 
  echo "#define mini__set_robust_list generate" 
}
mini__iopl(){ 
  echo "#define mini__iopl generate" 
}
mini__inotify_rm_watch(){ 
  echo "#define mini__inotify_rm_watch generate" 
}
mini__inotify_init(){ 
  echo "#define mini__inotify_init generate" 
}
mini__vmsplice(){ 
  echo "#define mini__vmsplice generate" 
}
mini__pipe2(){ 
  echo "#define mini__pipe2 generate" 
}
mini__fanotify_mark(){ 
  echo "#define mini__fanotify_mark generate" 
}
mini__sethostname(){ 
  echo "#define mini__sethostname generate" 
}
mini__accept(){ 
  echo "#define mini__accept generate" 
}
mini__sched_getparam(){ 
  echo "#define mini__sched_getparam generate" 
}
mini__mmap(){ 
  echo "#define mini__mmap generate" 
}
mini__socket(){ 
  echo "#define mini__socket generate" 
}
mini__io_destroy(){ 
  echo "#define mini__io_destroy generate" 
}
mini__getsockname(){ 
  echo "#define mini__getsockname generate" 
}
mini__fchmodat(){ 
  echo "#define mini__fchmodat generate" 
}
mini__nanosleep(){ 
  echo "#define mini__nanosleep generate" 
}
mini__setsid(){ 
  echo "#define mini__setsid generate" 
}
mini_basename(){ 
  echo "#define mini_basename generate" 
}
mini__setresuid(){ 
  echo "#define mini__setresuid generate" 
}
mini__epoll_wait(){ 
  echo "#define mini__epoll_wait generate" 
}
mini_strncpy(){ 
  echo "#define mini_strncpy generate" 
}
mini__getcpu(){ 
  echo "#define mini__getcpu generate" 
}
mini_creat(){ 
  echo "#define mini_creat generate" 
}
mini__preadv(){ 
  echo "#define mini__preadv generate" 
}
mini_write(){ 
  echo "#define mini_write generate" 
}
mini__mincore(){ 
  echo "#define mini__mincore generate" 
}
mini__getresgid(){ 
  echo "#define mini__getresgid generate" 
}
mini__adjtimex(){ 
  echo "#define mini__adjtimex generate" 
}
mini__timer_create(){ 
  echo "#define mini__timer_create generate" 
}
mini__mbind(){ 
  echo "#define mini__mbind generate" 
}
mini__ftruncate(){ 
  echo "#define mini__ftruncate generate" 
}
mini__swapon(){ 
  echo "#define mini__swapon generate" 
}
mini__kexec_file_load(){ 
  echo "#define mini__kexec_file_load generate" 
}
mini__shutdown(){ 
  echo "#define mini__shutdown generate" 
}
mini___sysctl(){ 
  echo "#define mini___sysctl generate" 
}
mini__setgid(){ 
  echo "#define mini__setgid generate" 
}
mini__fsetxattr(){ 
  echo "#define mini__fsetxattr generate" 
}
mini__ioprio_set(){ 
  echo "#define mini__ioprio_set generate" 
}
mini__alarm(){ 
  echo "#define mini__alarm generate" 
}
mini__sched_rr_get_interval(){ 
  echo "#define mini__sched_rr_get_interval generate" 
}
mini__migrate_pages(){ 
  echo "#define mini__migrate_pages generate" 
}
mini_close(){ 
  echo "#define mini_close generate" 
}
mini__clone(){ 
  echo "#define mini__clone generate" 
}
mini__prctl(){ 
  echo "#define mini__prctl generate" 
}
mini__execve(){ 
  echo "#define mini__execve generate" 
}
mini__settimeofday(){ 
  echo "#define mini__settimeofday generate" 
}
mini__setreuid(){ 
  echo "#define mini__setreuid generate" 
}
mini__recvmmsg(){ 
  echo "#define mini__recvmmsg generate" 
}
mini_fgetc(){ 
  echo "#define mini_fgetc generate" 
}
mini__clock_getres(){ 
  echo "#define mini__clock_getres generate" 
}
mini_rewind(){ 
  echo "#define mini_rewind generate" 
}
mini__timer_delete(){ 
  echo "#define mini__timer_delete generate" 
}
mini__readlinkat(){ 
  echo "#define mini__readlinkat generate" 
}
mini_strcat(){ 
  echo "#define mini_strcat generate" 
}
mini_memcmp(){ 
  echo "#define mini_memcmp generate" 
}
mini__renameat(){ 
  echo "#define mini__renameat generate" 
}
mini__chmod(){ 
  echo "#define mini__chmod generate" 
}
mini__reboot(){ 
  echo "#define mini__reboot generate" 
}
mini__unshare(){ 
  echo "#define mini__unshare generate" 
}
mini_gettimeofday(){ 
  echo "#define mini_gettimeofday generate" 
}
mini__rmdir(){ 
  echo "#define mini__rmdir generate" 
}
mini__mknodat(){ 
  echo "#define mini__mknodat generate" 
}
mini_memcpy(){ 
  echo "#define mini_memcpy generate" 
}
mini_fputs(){ 
  echo "#define mini_fputs generate" 
}
mini__faccessat(){ 
  echo "#define mini__faccessat generate" 
}
mini_select(){ 
  echo "#define mini_select generate" 
}
mini__ustat(){ 
  echo "#define mini__ustat generate" 
}
mini__lremovexattr(){ 
  echo "#define mini__lremovexattr generate" 
}
mini_strncmp(){ 
  echo "#define mini_strncmp generate" 
}
mini__lseek(){ 
  echo "#define mini__lseek generate" 
}
mini__semop(){ 
  echo "#define mini__semop generate" 
}
mini__sched_getscheduler(){ 
  echo "#define mini__sched_getscheduler generate" 
}
mini__fcntl(){ 
  echo "#define mini__fcntl generate" 
}
mini__modify_ldt(){ 
  echo "#define mini__modify_ldt generate" 
}
mini_putchar(){ 
  echo "#define mini_putchar generate" 
}
mini_opendir(){ 
  echo "#define mini_opendir generate" 
}
mini__exit_group(){ 
  echo "#define mini__exit_group generate" 
}
mini__setpgid(){ 
  echo "#define mini__setpgid generate" 
}
mini__fanotify_init(){ 
  echo "#define mini__fanotify_init generate" 
}
mini__perf_event_open(){ 
  echo "#define mini__perf_event_open generate" 
}
mini__inotify_init1(){ 
  echo "#define mini__inotify_init1 generate" 
}
mini_fgetpos(){ 
  echo "#define mini_fgetpos generate" 
}
mini_closedir(){ 
  echo "#define mini_closedir generate" 
}
mini__poll(){ 
  echo "#define mini__poll generate" 
}
mini__link(){ 
  echo "#define mini__link generate" 
}
mini__chdir(){ 
  echo "#define mini__chdir generate" 
}
mini__access(){ 
  echo "#define mini__access generate" 
}
mini__epoll_ctl(){ 
  echo "#define mini__epoll_ctl generate" 
}
mini__msgctl(){ 
  echo "#define mini__msgctl generate" 
}
mini__sched_yield(){ 
  echo "#define mini__sched_yield generate" 
}
mini__setdomainname(){ 
  echo "#define mini__setdomainname generate" 
}
mini_ftruncate(){ 
  echo "#define mini_ftruncate generate" 
}
mini__truncate(){ 
  echo "#define mini__truncate generate" 
}
mini_ftell(){ 
  echo "#define mini_ftell generate" 
}
mini__finit_module(){ 
  echo "#define mini__finit_module generate" 
}
mini_readdir(){ 
  echo "#define mini_readdir generate" 
}
mini__tgkill(){ 
  echo "#define mini__tgkill generate" 
}
mini__fdatasync(){ 
  echo "#define mini__fdatasync generate" 
}
mini__rt_sigreturn(){ 
  echo "#define mini__rt_sigreturn generate" 
}
mini__shmdt(){ 
  echo "#define mini__shmdt generate" 
}
mini__fstatfs(){ 
  echo "#define mini__fstatfs generate" 
}
mini__arch_prctl(){ 
  echo "#define mini__arch_prctl generate" 
}
mini_writes(){ 
  echo "#define mini_writes generate" 
}
mini__syslog(){ 
  echo "#define mini__syslog generate" 
}
mini__getitimer(){ 
  echo "#define mini__getitimer generate" 
}
mini__fstat(){ 
  echo "#define mini__fstat generate" 
}
mini__getsockopt(){ 
  echo "#define mini__getsockopt generate" 
}
mini__prlimit64(){ 
  echo "#define mini__prlimit64 generate" 
}
mini__fallocate(){ 
  echo "#define mini__fallocate generate" 
}
mini__eventfd(){ 
  echo "#define mini__eventfd generate" 
}
mini_puts(){ 
  echo "#define mini_puts generate" 
}
mini__madvise(){ 
  echo "#define mini__madvise generate" 
}
mini__pipe(){ 
  echo "#define mini__pipe generate" 
}
mini__remap_file_pages(){ 
  echo "#define mini__remap_file_pages generate" 
}
mini__exit(){ 
  echo "#define mini__exit generate" 
}
mini__shmget(){ 
  echo "#define mini__shmget generate" 
}
mini__sched_get_priority_min(){ 
  echo "#define mini__sched_get_priority_min generate" 
}
mini__pwritev(){ 
  echo "#define mini__pwritev generate" 
}
mini__io_submit(){ 
  echo "#define mini__io_submit generate" 
}
mini__renameat2(){ 
  echo "#define mini__renameat2 generate" 
}
mini__utimensat(){ 
  echo "#define mini__utimensat generate" 
}
mini__keyctl(){ 
  echo "#define mini__keyctl generate" 
}
mini__sched_setattr(){ 
  echo "#define mini__sched_setattr generate" 
}
mini__lchown(){ 
  echo "#define mini__lchown generate" 
}
mini_itohex(){ 
  echo "#define mini_itohex generate" 
}
mini__getpgrp(){ 
  echo "#define mini__getpgrp generate" 
}
mini__wait4(){ 
  echo "#define mini__wait4 generate" 
}
mini__dup2(){ 
  echo "#define mini__dup2 generate" 
}
mini__signalfd(){ 
  echo "#define mini__signalfd generate" 
}
mini__getxattr(){ 
  echo "#define mini__getxattr generate" 
}
mini__itohex(){ 
  echo "#define mini__itohex generate" 
}
mini__setgroups(){ 
  echo "#define mini__setgroups generate" 
}
mini__mq_open(){ 
  echo "#define mini__mq_open generate" 
}
mini_dprints(){ 
  echo "#define mini_dprints generate" 
}
mini__creat(){ 
  echo "#define mini__creat generate" 
}
mini_fprints(){ 
  echo "#define mini_fprints generate" 
}
mini__statfs(){ 
  echo "#define mini__statfs generate" 
}
mini__fchdir(){ 
  echo "#define mini__fchdir generate" 
}
mini__flistxattr(){ 
  echo "#define mini__flistxattr generate" 
}
mini__munlock(){ 
  echo "#define mini__munlock generate" 
}
mini_tcgetattr(){ 
  echo "#define mini_tcgetattr generate" 
}
mini_printf(){ 
  echo "#define mini_printf generate" 
}
mini__lgetxattr(){ 
  echo "#define mini__lgetxattr generate" 
}
mini__sendmmsg(){ 
  echo "#define mini__sendmmsg generate" 
}
mini_dtodec(){ 
  echo "#define mini_dtodec generate" 
}
mini__unlinkat(){ 
  echo "#define mini__unlinkat generate" 
}
mini__ptrace(){ 
  echo "#define mini__ptrace generate" 
}
mini_uname(){ 
  echo "#define mini_uname generate" 
}
mini_getc(){ 
  echo "#define mini_getc generate" 
}
mini__accept4(){ 
  echo "#define mini__accept4 generate" 
}
mini__get_mempolicy(){ 
  echo "#define mini__get_mempolicy generate" 
}
mini__mq_notify(){ 
  echo "#define mini__mq_notify generate" 
}
mini__kexec_load(){ 
  echo "#define mini__kexec_load generate" 
}
mini_memset(){ 
  echo "#define mini_memset generate" 
}
mini__itobin(){ 
  echo "#define mini__itobin generate" 
}
mini__vfork(){ 
  echo "#define mini__vfork generate" 
}
mini_clearerror(){ 
  echo "#define mini_clearerror generate" 
}
mini__openat(){ 
  echo "#define mini__openat generate" 
}
mini__sync_file_range(){ 
  echo "#define mini__sync_file_range generate" 
}
mini__clock_nanosleep(){ 
  echo "#define mini__clock_nanosleep generate" 
}
mini_dprintf(){ 
  echo "#define mini_dprintf generate" 
}
mini_fprintf(){ 
  echo "#define mini_fprintf generate" 
}
mini__io_cancel(){ 
  echo "#define mini__io_cancel generate" 
}
mini__fchownat(){ 
  echo "#define mini__fchownat generate" 
}
mini__getuid(){ 
  echo "#define mini__getuid generate" 
}
mini__semget(){ 
  echo "#define mini__semget generate" 
}
mini__pselect6(){ 
  echo "#define mini__pselect6 generate" 
}
mini__open_by_handle_at(){ 
  echo "#define mini__open_by_handle_at generate" 
}
mini__set_tid_address(){ 
  echo "#define mini__set_tid_address generate" 
}
mini__readlink(){ 
  echo "#define mini__readlink generate" 
}
mini__process_vm_readv(){ 
  echo "#define mini__process_vm_readv generate" 
}
mini__timer_gettime(){ 
  echo "#define mini__timer_gettime generate" 
}
mini_fprint(){ 
  echo "#define mini_fprint generate" 
}
mini__rt_sigqueueinfo(){ 
  echo "#define mini__rt_sigqueueinfo generate" 
}
mini__semtimedop(){ 
  echo "#define mini__semtimedop generate" 
}
mini__futimesat(){ 
  echo "#define mini__futimesat generate" 
}
mini__clock_gettime(){ 
  echo "#define mini__clock_gettime generate" 
}
mini_fprintfs(){ 
  echo "#define mini_fprintfs generate" 
}
mini__getrlimit(){ 
  echo "#define mini__getrlimit generate" 
}
mini__newfstatat(){ 
  echo "#define mini__newfstatat generate" 
}
mini__rt_sigaction(){ 
  echo "#define mini__rt_sigaction generate" 
}
mini__get_robust_list(){ 
  echo "#define mini__get_robust_list generate" 
}
mini__readahead(){ 
  echo "#define mini__readahead generate" 
}
mini__getpriority(){ 
  echo "#define mini__getpriority generate" 
}
mini__getcwd(){ 
  echo "#define mini__getcwd generate" 
}
mini__mlock(){ 
  echo "#define mini__mlock generate" 
}
mini_printsl(){ 
  echo "#define mini_printsl generate" 
}
mini__setns(){ 
  echo "#define mini__setns generate" 
}
mini_malloc(){ 
  echo "#define mini_malloc generate" 
}
mini_getdents(){ 
  echo "#define mini_getdents generate" 
}
mini__sendto(){ 
  echo "#define mini__sendto generate" 
}
mini_mprotect(){ 
  echo "#define mini_mprotect generate" 
}
mini__flock(){ 
  echo "#define mini__flock generate" 
}
mini__clock_settime(){ 
  echo "#define mini__clock_settime generate" 
}
mini__readv(){ 
  echo "#define mini__readv generate" 
}
mini_tcsetattr(){ 
  echo "#define mini_tcsetattr generate" 
}
mini__personality(){ 
  echo "#define mini__personality generate" 
}
mini_itobin(){ 
  echo "#define mini_itobin generate" 
}
mini__lsetxattr(){ 
  echo "#define mini__lsetxattr generate" 
}
mini__munmap(){ 
  echo "#define mini__munmap generate" 
}
mini__mq_unlink(){ 
  echo "#define mini__mq_unlink generate" 
}
mini__sched_get_priority_max(){ 
  echo "#define mini__sched_get_priority_max generate" 
}
mini__fadvise64(){ 
  echo "#define mini__fadvise64 generate" 
}
mini__brk(){ 
  echo "#define mini__brk generate" 
}
mini__move_pages(){ 
  echo "#define mini__move_pages generate" 
}
mini__timer_getoverrun(){ 
  echo "#define mini__timer_getoverrun generate" 
}
mini__timer_settime(){ 
  echo "#define mini__timer_settime generate" 
}
mini__rt_sigsuspend(){ 
  echo "#define mini__rt_sigsuspend generate" 
}
mini__getdents(){ 
  echo "#define mini__getdents generate" 
}
mini__getresuid(){ 
  echo "#define mini__getresuid generate" 
}
mini__strcmp(){ 
  echo "#define mini__strcmp generate" 
}
mini__semctl(){ 
  echo "#define mini__semctl generate" 
}
mini__socketpair(){ 
  echo "#define mini__socketpair generate" 
}
mini__fchmod(){ 
  echo "#define mini__fchmod generate" 
}
mini_rename(){ 
  echo "#define mini_rename generate" 
}
mini__vhangup(){ 
  echo "#define mini__vhangup generate" 
}
mini__close(){ 
  echo "#define mini__close generate" 
}
mini__getrandom(){ 
  echo "#define mini__getrandom generate" 
}
mini_fclose(){ 
  echo "#define mini_fclose generate" 
}
mini__waitid(){ 
  echo "#define mini__waitid generate" 
}
mini__getsid(){ 
  echo "#define mini__getsid generate" 
}
mini__fremovexattr(){ 
  echo "#define mini__fremovexattr generate" 
}
mini__listxattr(){ 
  echo "#define mini__listxattr generate" 
}
mini__quotactl(){ 
  echo "#define mini__quotactl generate" 
}
mini_memfrob(){ 
  echo "#define mini_memfrob generate" 
}
mini__lookup_dcookie(){ 
  echo "#define mini__lookup_dcookie generate" 
}
mini_strlen(){ 
  echo "#define mini_strlen generate" 
}
mini__setregid(){ 
  echo "#define mini__setregid generate" 
}
mini__mount(){ 
  echo "#define mini__mount generate" 
}
mini__rt_tgsigqueueinfo(){ 
  echo "#define mini__rt_tgsigqueueinfo generate" 
}
mini__stat(){ 
  echo "#define mini__stat generate" 
}
mini_fstat(){ 
  echo "#define mini_fstat generate" 
}
mini__getegid(){ 
  echo "#define mini__getegid generate" 
}
mini_srand(){ 
  echo "#define mini_srand generate" 
}
mini__select(){ 
  echo "#define mini__select generate" 
}
mini__getpeername(){ 
  echo "#define mini__getpeername generate" 
}
mini__getgid(){ 
  echo "#define mini__getgid generate" 
}
mini_dup3(){ 
  echo "#define mini_dup3 generate" 
}
mini__add_key(){ 
  echo "#define mini__add_key generate" 
}
mini__symlink(){ 
  echo "#define mini__symlink generate" 
}
mini__epoll_pwait(){ 
  echo "#define mini__epoll_pwait generate" 
}
mini__epoll_create1(){ 
  echo "#define mini__epoll_create1 generate" 
}
mini__restart_syscall(){ 
  echo "#define mini__restart_syscall generate" 
}
mini__setresgid(){ 
  echo "#define mini__setresgid generate" 
}
mini__setfsuid(){ 
  echo "#define mini__setfsuid generate" 
}
mini__rt_sigpending(){ 
  echo "#define mini__rt_sigpending generate" 
}
mini__mlockall(){ 
  echo "#define mini__mlockall generate" 
}
mini__sched_getattr(){ 
  echo "#define mini__sched_getattr generate" 
}
mini__mprotect(){ 
  echo "#define mini__mprotect generate" 
}
mini__msgget(){ 
  echo "#define mini__msgget generate" 
}
mini__futex(){ 
  echo "#define mini__futex generate" 
}
mini_strerror(){ 
  echo "#define mini_strerror generate" 
}
mini__msgsnd(){ 
  echo "#define mini__msgsnd generate" 
}
mini__fork(){ 
  echo "#define mini__fork generate" 
}
mini__gettid(){ 
  echo "#define mini__gettid generate" 
}
mini_fread(){ 
  echo "#define mini_fread generate" 
}
mini__sendmsg(){ 
  echo "#define mini__sendmsg generate" 
}
mini__read(){ 
  echo "#define mini__read generate" 
}
mini__mq_timedsend(){ 
  echo "#define mini__mq_timedsend generate" 
}
mini__shmctl(){ 
  echo "#define mini__shmctl generate" 
}
mini__seccomp(){ 
  echo "#define mini__seccomp generate" 
}
mini__memfd_create(){ 
  echo "#define mini__memfd_create generate" 
}
mini__connect(){ 
  echo "#define mini__connect generate" 
}
mini__sysinfo(){ 
  echo "#define mini__sysinfo generate" 
}
mini__times(){ 
  echo "#define mini__times generate" 
}
mini__process_vm_writev(){ 
  echo "#define mini__process_vm_writev generate" 
}
mini__pivot_root(){ 
  echo "#define mini__pivot_root generate" 
}
mini__writev(){ 
  echo "#define mini__writev generate" 
}
mini__io_getevents(){ 
  echo "#define mini__io_getevents generate" 
}
mini__chroot(){ 
  echo "#define mini__chroot generate" 
}
mini__gettimeofday(){ 
  echo "#define mini__gettimeofday generate" 
}
mini__rename(){ 
  echo "#define mini__rename generate" 
}
mini_fseek(){ 
  echo "#define mini_fseek generate" 
}
mini_sprintf(){ 
  echo "#define mini_sprintf generate" 
}
mini_chdir(){ 
  echo "#define mini_chdir generate" 
}
mini_print(){ 
  echo "#define mini_print generate" 
}
mini__fgetxattr(){ 
  echo "#define mini__fgetxattr generate" 
}
mini__mkdirat(){ 
  echo "#define mini__mkdirat generate" 
}
mini_getenv(){ 
  echo "#define mini_getenv generate" 
}
mini__timerfd_create(){ 
  echo "#define mini__timerfd_create generate" 
}
mini_strcpy(){ 
  echo "#define mini_strcpy generate" 
}
mini__sysfs(){ 
  echo "#define mini__sysfs generate" 
}
mini__umask(){ 
  echo "#define mini__umask generate" 
}
mini_fwrite(){ 
  echo "#define mini_fwrite generate" 
}
mini_fileno(){ 
  echo "#define mini_fileno generate" 
}
mini__write(){ 
  echo "#define mini__write generate" 
}
mini__capset(){ 
  echo "#define mini__capset generate" 
}
mini__llistxattr(){ 
  echo "#define mini__llistxattr generate" 
}
mini__request_key(){ 
  echo "#define mini__request_key generate" 
}
mini__chown(){ 
  echo "#define mini__chown generate" 
}
mini__getrusage(){ 
  echo "#define mini__getrusage generate" 
}
mini__timerfd_gettime(){ 
  echo "#define mini__timerfd_gettime generate" 
}
mini_fputc(){ 
  echo "#define mini_fputc generate" 
}
mini__time(){ 
  echo "#define mini__time generate" 
}
mini__symlinkat(){ 
  echo "#define mini__symlinkat generate" 
}
mini__mprints(){ 
  echo "#define mini__mprints generate" 
}
mini__open(){ 
  echo "#define mini__open generate" 
}
mini_fsetpos(){ 
  echo "#define mini_fsetpos generate" 
}
mini__sync(){ 
  echo "#define mini__sync generate" 
}
mini_fsync(){ 
  echo "#define mini_fsync generate" 
}
mini__sched_setscheduler(){ 
  echo "#define mini__sched_setscheduler generate" 
}
mini_fopen(){ 
  echo "#define mini_fopen generate" 
}
mini__getpgid(){ 
  echo "#define mini__getpgid generate" 
}
mini_strcmp(){ 
  echo "#define mini_strcmp generate" 
}
mini_0(){ 
  echo "#define mini_0 generate" 
}
mini__swapoff(){ 
  echo "#define mini__swapoff generate" 
}
mini_prints(){ 
  echo "#define mini_prints generate" 
}
mini_vfprintf(){ 
  echo "#define mini_vfprintf generate" 
}
mini_perror(){ 
  echo "#define mini_perror generate" 
}
mini__getgroups(){ 
  echo "#define mini__getgroups generate" 
}
mini_snprintf(){ 
  echo "#define mini_snprintf generate" 
}
mini__setxattr(){ 
  echo "#define mini__setxattr generate" 
}
mini_free(){ 
  echo "#define mini_free generate" 
}
mini_ferror(){ 
  echo "#define mini_ferror generate" 
}
mini__munlockall(){ 
  echo "#define mini__munlockall generate" 
}
mini_vsnprintf(){ 
  echo "#define mini_vsnprintf generate" 
}
mini__getdents64(){ 
  echo "#define mini__getdents64 generate" 
}
mini__kill(){ 
  echo "#define mini__kill generate" 
}
mini__setitimer(){ 
  echo "#define mini__setitimer generate" 
}
mini__pwrite64(){ 
  echo "#define mini__pwrite64 generate" 
}
mini__pread64(){ 
  echo "#define mini__pread64 generate" 
}
mini__setsockopt(){ 
  echo "#define mini__setsockopt generate" 
}
mini__ppoll(){ 
  echo "#define mini__ppoll generate" 
}
mini__uname(){ 
  echo "#define mini__uname generate" 
}
mini__pause(){ 
  echo "#define mini__pause generate" 
}
mini_fwrites(){ 
  echo "#define mini_fwrites generate" 
}
mini__init_module(){ 
  echo "#define mini__init_module generate" 
}
mini_ioctl(){ 
  echo "#define mini_ioctl generate" 
}
mini__sched_setparam(){ 
  echo "#define mini__sched_setparam generate" 
}
mini__removexattr(){ 
  echo "#define mini__removexattr generate" 
}
mini__set_mempolicy(){ 
  echo "#define mini__set_mempolicy generate" 
}
mini_setbuf(){ 
  echo "#define mini_setbuf generate" 
}
mini__umount2(){ 
  echo "#define mini__umount2 generate" 
}
mini__ioprio_get(){ 
  echo "#define mini__ioprio_get generate" 
}
mini__bpf(){ 
  echo "#define mini__bpf generate" 
}
mini__unlink(){ 
  echo "#define mini__unlink generate" 
}
mini_fflush(){ 
  echo "#define mini_fflush generate" 
}
mini_isprint(){ 
  echo "#define mini_isprint generate" 
}
mini_lseek(){ 
  echo "#define mini_lseek generate" 
}
mini__msgrcv(){ 
  echo "#define mini__msgrcv generate" 
}
mini__recvmsg(){ 
  echo "#define mini__recvmsg generate" 
}
mini__io_setup(){ 
  echo "#define mini__io_setup generate" 
}
mini_putc(){ 
  echo "#define mini_putc generate" 
}
mini__rt_sigprocmask(){ 
  echo "#define mini__rt_sigprocmask generate" 
}
mini__inotify_add_watch(){ 
  echo "#define mini__inotify_add_watch generate" 
}
mini__clock_adjtime(){ 
  echo "#define mini__clock_adjtime generate" 
}
mini__dup3(){ 
  echo "#define mini__dup3 generate" 
}
mini__kcmp(){ 
  echo "#define mini__kcmp generate" 
}
mini__mq_timedreceive(){ 
  echo "#define mini__mq_timedreceive generate" 
}
mini__sigaltstack(){ 
  echo "#define mini__sigaltstack generate" 
}
mini__ioctl(){ 
  echo "#define mini__ioctl generate" 
}
mini_uitodec(){ 
  echo "#define mini_uitodec generate" 
}
mini__utimes(){ 
  echo "#define mini__utimes generate" 
}
mini__getppid(){ 
  echo "#define mini__getppid generate" 
}
mini__listen(){ 
  echo "#define mini__listen generate" 
}
mini__msync(){ 
  echo "#define mini__msync generate" 
}
mini__setrlimit(){ 
  echo "#define mini__setrlimit generate" 
}
mini__lstat(){ 
  echo "#define mini__lstat generate" 
}
mini__fsync(){ 
  echo "#define mini__fsync generate" 
}
mini_dup(){ 
  echo "#define mini_dup generate" 
}
mini__getpid(){ 
  echo "#define mini__getpid generate" 
}
mini__splice(){ 
  echo "#define mini__splice generate" 
}
mini__utime(){ 
  echo "#define mini__utime generate" 
}
mini_isspace(){ 
  echo "#define mini_isspace generate" 
}
mini_stat(){ 
  echo "#define mini_stat generate" 
}
mini__capget(){ 
  echo "#define mini__capget generate" 
}
mini__name_to_handle_at(){ 
  echo "#define mini__name_to_handle_at generate" 
}
mini__dup(){ 
  echo "#define mini__dup generate" 
}
mini__setuid(){ 
  echo "#define mini__setuid generate" 
}
mini__tkill(){ 
  echo "#define mini__tkill generate" 
}
mini__sched_setaffinity(){ 
  echo "#define mini__sched_setaffinity generate" 
}
mini_printl(){ 
  echo "#define mini_printl generate" 
}
mini_dup2(){ 
  echo "#define mini_dup2 generate" 
}
mini_feof(){ 
  echo "#define mini_feof generate" 
}
mini__mq_getsetattr(){ 
  echo "#define mini__mq_getsetattr generate" 
}
mini_setvbuf(){ 
  echo "#define mini_setvbuf generate" 
}
mini__fchown(){ 
  echo "#define mini__fchown generate" 
}
mini__epoll_create(){ 
  echo "#define mini__epoll_create generate" 
}
mini__bind(){ 
  echo "#define mini__bind generate" 
}
mini__mknod(){ 
  echo "#define mini__mknod generate" 
}
mini_def(){ 
  echo "#define mini_def generate" 
}
mini__eventfd2(){ 
  echo "#define mini__eventfd2 generate" 
}
mini__ioperm(){ 
  echo "#define mini__ioperm generate" 
}
mini__linkat(){ 
  echo "#define mini__linkat generate" 
}
# --- define_functions-end: generate --- #

