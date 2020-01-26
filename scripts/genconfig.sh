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
mini_mq_open(){ 
  echo "#define mini_mq_open generate" 
}
mini_migrate_pages(){ 
  echo "#define mini_migrate_pages generate" 
}
mini_sysfs(){ 
  echo "#define mini_sysfs generate" 
}
mini_inotify_rm_watch(){ 
  echo "#define mini_inotify_rm_watch generate" 
}
mini_mount(){ 
  echo "#define mini_mount generate" 
}
mini_capget(){ 
  echo "#define mini_capget generate" 
}
mini_getegid(){ 
  echo "#define mini_getegid generate" 
}
mini_renameat(){ 
  echo "#define mini_renameat generate" 
}
mini_srand(){ 
  echo "#define mini_srand generate" 
}
mini_strncpy(){ 
  echo "#define mini_strncpy generate" 
}
mini_unlink(){ 
  echo "#define mini_unlink generate" 
}
mini_io_setup(){ 
  echo "#define mini_io_setup generate" 
}
mini_kill(){ 
  echo "#define mini_kill generate" 
}
mini_listxattr(){ 
  echo "#define mini_listxattr generate" 
}
mini_uitodec(){ 
  echo "#define mini_uitodec generate" 
}
mini_snprintf(){ 
  echo "#define mini_snprintf generate" 
}
mini_waitid(){ 
  echo "#define mini_waitid generate" 
}
mini_seccomp(){ 
  echo "#define mini_seccomp generate" 
}
mini_poll(){ 
  echo "#define mini_poll generate" 
}
mini_getxattr(){ 
  echo "#define mini_getxattr generate" 
}
mini_fopen(){ 
  echo "#define mini_fopen generate" 
}
mini_connect(){ 
  echo "#define mini_connect generate" 
}
mini_setreuid(){ 
  echo "#define mini_setreuid generate" 
}
mini_clock_settime(){ 
  echo "#define mini_clock_settime generate" 
}
mini_dprints(){ 
  echo "#define mini_dprints generate" 
}
mini_munlock(){ 
  echo "#define mini_munlock generate" 
}
mini_fflush(){ 
  echo "#define mini_fflush generate" 
}
mini_swapon(){ 
  echo "#define mini_swapon generate" 
}
mini_signalfd(){ 
  echo "#define mini_signalfd generate" 
}
mini_ftruncate(){ 
  echo "#define mini_ftruncate generate" 
}
mini_sprintf(){ 
  echo "#define mini_sprintf generate" 
}
mini_sysinfo(){ 
  echo "#define mini_sysinfo generate" 
}
mini_setpgid(){ 
  echo "#define mini_setpgid generate" 
}
mini_mremap(){ 
  echo "#define mini_mremap generate" 
}
mini_semtimedop(){ 
  echo "#define mini_semtimedop generate" 
}
mini_dup3(){ 
  echo "#define mini_dup3 generate" 
}
mini_pipe(){ 
  echo "#define mini_pipe generate" 
}
mini_sendfile(){ 
  echo "#define mini_sendfile generate" 
}
mini_perf_event_open(){ 
  echo "#define mini_perf_event_open generate" 
}
mini_setdomainname(){ 
  echo "#define mini_setdomainname generate" 
}
mini_ppoll(){ 
  echo "#define mini_ppoll generate" 
}
mini_timer_settime(){ 
  echo "#define mini_timer_settime generate" 
}
mini_fread(){ 
  echo "#define mini_fread generate" 
}
mini__itohex(){ 
  echo "#define mini__itohex generate" 
}
mini_fchown(){ 
  echo "#define mini_fchown generate" 
}
mini_adjtimex(){ 
  echo "#define mini_adjtimex generate" 
}
mini_ioctl(){ 
  echo "#define mini_ioctl generate" 
}
mini_fputc(){ 
  echo "#define mini_fputc generate" 
}
mini_removexattr(){ 
  echo "#define mini_removexattr generate" 
}
mini_wait4(){ 
  echo "#define mini_wait4 generate" 
}
mini_strlen(){ 
  echo "#define mini_strlen generate" 
}
mini_shmdt(){ 
  echo "#define mini_shmdt generate" 
}
mini_msgctl(){ 
  echo "#define mini_msgctl generate" 
}
mini_sendmsg(){ 
  echo "#define mini_sendmsg generate" 
}
mini_execve(){ 
  echo "#define mini_execve generate" 
}
mini_memfrob(){ 
  echo "#define mini_memfrob generate" 
}
mini_getpgrp(){ 
  echo "#define mini_getpgrp generate" 
}
mini_fchmodat(){ 
  echo "#define mini_fchmodat generate" 
}
mini_isspace(){ 
  echo "#define mini_isspace generate" 
}
mini_epoll_wait(){ 
  echo "#define mini_epoll_wait generate" 
}
mini_msgget(){ 
  echo "#define mini_msgget generate" 
}
mini_munmap(){ 
  echo "#define mini_munmap generate" 
}
mini_timer_gettime(){ 
  echo "#define mini_timer_gettime generate" 
}
mini_rt_sigpending(){ 
  echo "#define mini_rt_sigpending generate" 
}
mini_memcpy(){ 
  echo "#define mini_memcpy generate" 
}
mini_utimensat(){ 
  echo "#define mini_utimensat generate" 
}
mini_free(){ 
  echo "#define mini_free generate" 
}
mini_malloc(){ 
  echo "#define mini_malloc generate" 
}
mini_sched_rr_get_interval(){ 
  echo "#define mini_sched_rr_get_interval generate" 
}
mini_getpriority(){ 
  echo "#define mini_getpriority generate" 
}
mini_getpid(){ 
  echo "#define mini_getpid generate" 
}
mini_write(){ 
  echo "#define mini_write generate" 
}
mini_access(){ 
  echo "#define mini_access generate" 
}
mini_0(){ 
  echo "#define mini_0 generate" 
}
mini_fanotify_init(){ 
  echo "#define mini_fanotify_init generate" 
}
mini_flistxattr(){ 
  echo "#define mini_flistxattr generate" 
}
mini_times(){ 
  echo "#define mini_times generate" 
}
mini_memset(){ 
  echo "#define mini_memset generate" 
}
mini_fchdir(){ 
  echo "#define mini_fchdir generate" 
}
mini_getsockopt(){ 
  echo "#define mini_getsockopt generate" 
}
mini_rt_sigsuspend(){ 
  echo "#define mini_rt_sigsuspend generate" 
}
mini_fcntl(){ 
  echo "#define mini_fcntl generate" 
}
mini_get_robust_list(){ 
  echo "#define mini_get_robust_list generate" 
}
mini_bind(){ 
  echo "#define mini_bind generate" 
}
mini_readlink(){ 
  echo "#define mini_readlink generate" 
}
mini_nanosleep(){ 
  echo "#define mini_nanosleep generate" 
}
mini_strcmp(){ 
  echo "#define mini_strcmp generate" 
}
mini_quotactl(){ 
  echo "#define mini_quotactl generate" 
}
mini_process_vm_writev(){ 
  echo "#define mini_process_vm_writev generate" 
}
mini_mq_notify(){ 
  echo "#define mini_mq_notify generate" 
}
mini_process_vm_readv(){ 
  echo "#define mini_process_vm_readv generate" 
}
mini_flock(){ 
  echo "#define mini_flock generate" 
}
mini_clock_gettime(){ 
  echo "#define mini_clock_gettime generate" 
}
mini_getsockname(){ 
  echo "#define mini_getsockname generate" 
}
mini_basename(){ 
  echo "#define mini_basename generate" 
}
mini_geteuid(){ 
  echo "#define mini_geteuid generate" 
}
mini_sethostname(){ 
  echo "#define mini_sethostname generate" 
}
mini_getenv(){ 
  echo "#define mini_getenv generate" 
}
mini_futex(){ 
  echo "#define mini_futex generate" 
}
mini_ioperm(){ 
  echo "#define mini_ioperm generate" 
}
mini_capset(){ 
  echo "#define mini_capset generate" 
}
mini_iopl(){ 
  echo "#define mini_iopl generate" 
}
mini_strncmp(){ 
  echo "#define mini_strncmp generate" 
}
mini_socketpair(){ 
  echo "#define mini_socketpair generate" 
}
mini_io_getevents(){ 
  echo "#define mini_io_getevents generate" 
}
mini_gettid(){ 
  echo "#define mini_gettid generate" 
}
mini_sigaltstack(){ 
  echo "#define mini_sigaltstack generate" 
}
mini_set_tid_address(){ 
  echo "#define mini_set_tid_address generate" 
}
mini_pause(){ 
  echo "#define mini_pause generate" 
}
mini_renameat2(){ 
  echo "#define mini_renameat2 generate" 
}
mini_openat(){ 
  echo "#define mini_openat generate" 
}
mini_setresgid(){ 
  echo "#define mini_setresgid generate" 
}
mini_mq_timedreceive(){ 
  echo "#define mini_mq_timedreceive generate" 
}
mini_fseek(){ 
  echo "#define mini_fseek generate" 
}
mini_statfs(){ 
  echo "#define mini_statfs generate" 
}
mini_setregid(){ 
  echo "#define mini_setregid generate" 
}
mini_open_by_handle_at(){ 
  echo "#define mini_open_by_handle_at generate" 
}
mini_io_destroy(){ 
  echo "#define mini_io_destroy generate" 
}
mini_truncate(){ 
  echo "#define mini_truncate generate" 
}
mini_gettimeofday(){ 
  echo "#define mini_gettimeofday generate" 
}
mini_readahead(){ 
  echo "#define mini_readahead generate" 
}
mini_mq_timedsend(){ 
  echo "#define mini_mq_timedsend generate" 
}
mini_set_mempolicy(){ 
  echo "#define mini_set_mempolicy generate" 
}
mini_sched_yield(){ 
  echo "#define mini_sched_yield generate" 
}
mini_link(){ 
  echo "#define mini_link generate" 
}
mini_getrusage(){ 
  echo "#define mini_getrusage generate" 
}
mini_lseek(){ 
  echo "#define mini_lseek generate" 
}
mini_eventfd(){ 
  echo "#define mini_eventfd generate" 
}
mini_puts(){ 
  echo "#define mini_puts generate" 
}
mini_ioprio_set(){ 
  echo "#define mini_ioprio_set generate" 
}
mini_setsid(){ 
  echo "#define mini_setsid generate" 
}
mini_io_submit(){ 
  echo "#define mini_io_submit generate" 
}
mini_add_key(){ 
  echo "#define mini_add_key generate" 
}
mini_reboot(){ 
  echo "#define mini_reboot generate" 
}
mini_sched_setscheduler(){ 
  echo "#define mini_sched_setscheduler generate" 
}
mini_init_module(){ 
  echo "#define mini_init_module generate" 
}
mini_pselect6(){ 
  echo "#define mini_pselect6 generate" 
}
mini_setresuid(){ 
  echo "#define mini_setresuid generate" 
}
mini_delete_module(){ 
  echo "#define mini_delete_module generate" 
}
mini_setgroups(){ 
  echo "#define mini_setgroups generate" 
}
mini_utimes(){ 
  echo "#define mini_utimes generate" 
}
mini_clearerror(){ 
  echo "#define mini_clearerror generate" 
}
mini_kexec_load(){ 
  echo "#define mini_kexec_load generate" 
}
mini_clone(){ 
  echo "#define mini_clone generate" 
}
mini_atoi(){ 
  echo "#define mini_atoi generate" 
}
mini_print(){ 
  echo "#define mini_print generate" 
}
mini_kcmp(){ 
  echo "#define mini_kcmp generate" 
}
mini_getppid(){ 
  echo "#define mini_getppid generate" 
}
mini_mq_getsetattr(){ 
  echo "#define mini_mq_getsetattr generate" 
}
mini_fstatfs(){ 
  echo "#define mini_fstatfs generate" 
}
mini_select(){ 
  echo "#define mini_select generate" 
}
mini_chdir(){ 
  echo "#define mini_chdir generate" 
}
mini_fprintfs(){ 
  echo "#define mini_fprintfs generate" 
}
mini_putchar(){ 
  echo "#define mini_putchar generate" 
}
mini_writev(){ 
  echo "#define mini_writev generate" 
}
mini_shmget(){ 
  echo "#define mini_shmget generate" 
}
mini_llistxattr(){ 
  echo "#define mini_llistxattr generate" 
}
mini_tgkill(){ 
  echo "#define mini_tgkill generate" 
}
mini_chroot(){ 
  echo "#define mini_chroot generate" 
}
mini_pipe2(){ 
  echo "#define mini_pipe2 generate" 
}
mini_readv(){ 
  echo "#define mini_readv generate" 
}
mini_exit_group(){ 
  echo "#define mini_exit_group generate" 
}
mini_signalfd4(){ 
  echo "#define mini_signalfd4 generate" 
}
mini_shmctl(){ 
  echo "#define mini_shmctl generate" 
}
mini_dup(){ 
  echo "#define mini_dup generate" 
}
mini_sync(){ 
  echo "#define mini_sync generate" 
}
mini_tee(){ 
  echo "#define mini_tee generate" 
}
mini_recvfrom(){ 
  echo "#define mini_recvfrom generate" 
}
mini_futimesat(){ 
  echo "#define mini_futimesat generate" 
}
mini_timer_getoverrun(){ 
  echo "#define mini_timer_getoverrun generate" 
}
mini_newfstatat(){ 
  echo "#define mini_newfstatat generate" 
}
mini_getuid(){ 
  echo "#define mini_getuid generate" 
}
mini_restart_syscall(){ 
  echo "#define mini_restart_syscall generate" 
}
mini_accept4(){ 
  echo "#define mini_accept4 generate" 
}
mini_isprint(){ 
  echo "#define mini_isprint generate" 
}
mini_getrandom(){ 
  echo "#define mini_getrandom generate" 
}
mini_umount2(){ 
  echo "#define mini_umount2 generate" 
}
mini_lchown(){ 
  echo "#define mini_lchown generate" 
}
mini_symlinkat(){ 
  echo "#define mini_symlinkat generate" 
}
mini_setvbuf(){ 
  echo "#define mini_setvbuf generate" 
}
mini_sched_getscheduler(){ 
  echo "#define mini_sched_getscheduler generate" 
}
mini_recvmmsg(){ 
  echo "#define mini_recvmmsg generate" 
}
mini_swapoff(){ 
  echo "#define mini_swapoff generate" 
}
mini_preadv(){ 
  echo "#define mini_preadv generate" 
}
mini_rt_sigtimedwait(){ 
  echo "#define mini_rt_sigtimedwait generate" 
}
mini_fprint(){ 
  echo "#define mini_fprint generate" 
}
mini_fputs(){ 
  echo "#define mini_fputs generate" 
}
mini_strcat(){ 
  echo "#define mini_strcat generate" 
}
mini_tcsetattr(){ 
  echo "#define mini_tcsetattr generate" 
}
mini_move_pages(){ 
  echo "#define mini_move_pages generate" 
}
mini_getrlimit(){ 
  echo "#define mini_getrlimit generate" 
}
mini_clock_adjtime(){ 
  echo "#define mini_clock_adjtime generate" 
}
mini_fdatasync(){ 
  echo "#define mini_fdatasync generate" 
}
mini_mlock(){ 
  echo "#define mini_mlock generate" 
}
mini_setgid(){ 
  echo "#define mini_setgid generate" 
}
mini_setitimer(){ 
  echo "#define mini_setitimer generate" 
}
mini_fprints(){ 
  echo "#define mini_fprints generate" 
}
mini_syncfs(){ 
  echo "#define mini_syncfs generate" 
}
mini_fileno(){ 
  echo "#define mini_fileno generate" 
}
mini_sched_setattr(){ 
  echo "#define mini_sched_setattr generate" 
}
mini_fchmod(){ 
  echo "#define mini_fchmod generate" 
}
mini_creat(){ 
  echo "#define mini_creat generate" 
}
mini_timerfd_settime(){ 
  echo "#define mini_timerfd_settime generate" 
}
mini_itodec(){ 
  echo "#define mini_itodec generate" 
}
mini_syslog(){ 
  echo "#define mini_syslog generate" 
}
mini_itohex(){ 
  echo "#define mini_itohex generate" 
}
mini_mq_unlink(){ 
  echo "#define mini_mq_unlink generate" 
}
mini_setns(){ 
  echo "#define mini_setns generate" 
}
mini_fchownat(){ 
  echo "#define mini_fchownat generate" 
}
mini_chmod(){ 
  echo "#define mini_chmod generate" 
}
mini_pivot_root(){ 
  echo "#define mini_pivot_root generate" 
}
mini_fork(){ 
  echo "#define mini_fork generate" 
}
mini_remap_file_pages(){ 
  echo "#define mini_remap_file_pages generate" 
}
mini_setuid(){ 
  echo "#define mini_setuid generate" 
}
mini_close(){ 
  echo "#define mini_close generate" 
}
mini_fsetpos(){ 
  echo "#define mini_fsetpos generate" 
}
mini_fremovexattr(){ 
  echo "#define mini_fremovexattr generate" 
}
mini_fsync(){ 
  echo "#define mini_fsync generate" 
}
mini_ustat(){ 
  echo "#define mini_ustat generate" 
}
mini_pread64(){ 
  echo "#define mini_pread64 generate" 
}
mini_rand(){ 
  echo "#define mini_rand generate" 
}
mini_pwritev(){ 
  echo "#define mini_pwritev generate" 
}
mini_vhangup(){ 
  echo "#define mini_vhangup generate" 
}
mini_mlockall(){ 
  echo "#define mini_mlockall generate" 
}
mini_prctl(){ 
  echo "#define mini_prctl generate" 
}
mini_shutdown(){ 
  echo "#define mini_shutdown generate" 
}
mini_unlinkat(){ 
  echo "#define mini_unlinkat generate" 
}
mini_rename(){ 
  echo "#define mini_rename generate" 
}
mini_umask(){ 
  echo "#define mini_umask generate" 
}
mini__strcmp(){ 
  echo "#define mini__strcmp generate" 
}
mini_setrlimit(){ 
  echo "#define mini_setrlimit generate" 
}
mini_semget(){ 
  echo "#define mini_semget generate" 
}
mini_sendmmsg(){ 
  echo "#define mini_sendmmsg generate" 
}
mini_clock_nanosleep(){ 
  echo "#define mini_clock_nanosleep generate" 
}
mini_sched_setaffinity(){ 
  echo "#define mini_sched_setaffinity generate" 
}
mini_fallocate(){ 
  echo "#define mini_fallocate generate" 
}
mini_getgid(){ 
  echo "#define mini_getgid generate" 
}
mini_prlimit64(){ 
  echo "#define mini_prlimit64 generate" 
}
mini_getitimer(){ 
  echo "#define mini_getitimer generate" 
}
mini_lsetxattr(){ 
  echo "#define mini_lsetxattr generate" 
}
mini_get_mempolicy(){ 
  echo "#define mini_get_mempolicy generate" 
}
mini_mknod(){ 
  echo "#define mini_mknod generate" 
}
mini_semctl(){ 
  echo "#define mini_semctl generate" 
}
mini_mincore(){ 
  echo "#define mini_mincore generate" 
}
mini_readdir(){ 
  echo "#define mini_readdir generate" 
}
mini_sched_getaffinity(){ 
  echo "#define mini_sched_getaffinity generate" 
}
mini_arch_prctl(){ 
  echo "#define mini_arch_prctl generate" 
}
mini_prints(){ 
  echo "#define mini_prints generate" 
}
mini_msgsnd(){ 
  echo "#define mini_msgsnd generate" 
}
mini_settimeofday(){ 
  echo "#define mini_settimeofday generate" 
}
mini_itobin(){ 
  echo "#define mini_itobin generate" 
}
mini_utime(){ 
  echo "#define mini_utime generate" 
}
mini_symlink(){ 
  echo "#define mini_symlink generate" 
}
mini_perror(){ 
  echo "#define mini_perror generate" 
}
mini_putc(){ 
  echo "#define mini_putc generate" 
}
mini_mprotect(){ 
  echo "#define mini_mprotect generate" 
}
mini_getresuid(){ 
  echo "#define mini_getresuid generate" 
}
mini_ftell(){ 
  echo "#define mini_ftell generate" 
}
mini_getdents64(){ 
  echo "#define mini_getdents64 generate" 
}
mini_getgroups(){ 
  echo "#define mini_getgroups generate" 
}
mini_sched_get_priority_max(){ 
  echo "#define mini_sched_get_priority_max generate" 
}
mini_dprintf(){ 
  echo "#define mini_dprintf generate" 
}
mini_fgetc(){ 
  echo "#define mini_fgetc generate" 
}
mini_open(){ 
  echo "#define mini_open generate" 
}
mini_inotify_init1(){ 
  echo "#define mini_inotify_init1 generate" 
}
mini_alarm(){ 
  echo "#define mini_alarm generate" 
}
mini_mkdirat(){ 
  echo "#define mini_mkdirat generate" 
}
mini_lgetxattr(){ 
  echo "#define mini_lgetxattr generate" 
}
mini_shmat(){ 
  echo "#define mini_shmat generate" 
}
mini_getsid(){ 
  echo "#define mini_getsid generate" 
}
mini_getc(){ 
  echo "#define mini_getc generate" 
}
mini_uname(){ 
  echo "#define mini_uname generate" 
}
mini_lstat(){ 
  echo "#define mini_lstat generate" 
}
mini_vfprintf(){ 
  echo "#define mini_vfprintf generate" 
}
mini_mkdir(){ 
  echo "#define mini_mkdir generate" 
}
mini_socket(){ 
  echo "#define mini_socket generate" 
}
mini_printl(){ 
  echo "#define mini_printl generate" 
}
mini_exit(){ 
  echo "#define mini_exit generate" 
}
mini_fwrites(){ 
  echo "#define mini_fwrites generate" 
}
mini_inotify_init(){ 
  echo "#define mini_inotify_init generate" 
}
mini_munlockall(){ 
  echo "#define mini_munlockall generate" 
}
mini_madvise(){ 
  echo "#define mini_madvise generate" 
}
mini_ferror(){ 
  echo "#define mini_ferror generate" 
}
mini_itoHEX(){ 
  echo "#define mini_itoHEX generate" 
}
mini_semop(){ 
  echo "#define mini_semop generate" 
}
mini_bpf(){ 
  echo "#define mini_bpf generate" 
}
mini_getpeername(){ 
  echo "#define mini_getpeername generate" 
}
mini_sched_getattr(){ 
  echo "#define mini_sched_getattr generate" 
}
mini_rt_sigqueueinfo(){ 
  echo "#define mini_rt_sigqueueinfo generate" 
}
mini_rt_sigreturn(){ 
  echo "#define mini_rt_sigreturn generate" 
}
mini_vfork(){ 
  echo "#define mini_vfork generate" 
}
mini_fgetpos(){ 
  echo "#define mini_fgetpos generate" 
}
mini_fwrite(){ 
  echo "#define mini_fwrite generate" 
}
mini_mknodat(){ 
  echo "#define mini_mknodat generate" 
}
mini_name_to_handle_at(){ 
  echo "#define mini_name_to_handle_at generate" 
}
mini_epoll_create1(){ 
  echo "#define mini_epoll_create1 generate" 
}
mini_io_cancel(){ 
  echo "#define mini_io_cancel generate" 
}
mini_closedir(){ 
  echo "#define mini_closedir generate" 
}
mini_setpriority(){ 
  echo "#define mini_setpriority generate" 
}
mini_setbuf(){ 
  echo "#define mini_setbuf generate" 
}
mini_faccessat(){ 
  echo "#define mini_faccessat generate" 
}
mini_mmap(){ 
  echo "#define mini_mmap generate" 
}
mini_kexec_file_load(){ 
  echo "#define mini_kexec_file_load generate" 
}
mini_readlinkat(){ 
  echo "#define mini_readlinkat generate" 
}
mini_time(){ 
  echo "#define mini_time generate" 
}
mini_memfd_create(){ 
  echo "#define mini_memfd_create generate" 
}
mini_printf(){ 
  echo "#define mini_printf generate" 
}
mini_fadvise64(){ 
  echo "#define mini_fadvise64 generate" 
}
mini_fanotify_mark(){ 
  echo "#define mini_fanotify_mark generate" 
}
mini_fstat(){ 
  echo "#define mini_fstat generate" 
}
mini_modify_ldt(){ 
  echo "#define mini_modify_ldt generate" 
}
mini_timerfd_gettime(){ 
  echo "#define mini_timerfd_gettime generate" 
}
mini_splice(){ 
  echo "#define mini_splice generate" 
}
mini_pwrite64(){ 
  echo "#define mini_pwrite64 generate" 
}
mini_mbind(){ 
  echo "#define mini_mbind generate" 
}
mini_epoll_ctl(){ 
  echo "#define mini_epoll_ctl generate" 
}
mini_getcpu(){ 
  echo "#define mini_getcpu generate" 
}
mini_timer_create(){ 
  echo "#define mini_timer_create generate" 
}
mini_clock_getres(){ 
  echo "#define mini_clock_getres generate" 
}
mini_epoll_pwait(){ 
  echo "#define mini_epoll_pwait generate" 
}
mini_sendto(){ 
  echo "#define mini_sendto generate" 
}
mini_setsockopt(){ 
  echo "#define mini_setsockopt generate" 
}
mini_keyctl(){ 
  echo "#define mini_keyctl generate" 
}
mini_feof(){ 
  echo "#define mini_feof generate" 
}
mini_set_robust_list(){ 
  echo "#define mini_set_robust_list generate" 
}
mini_getdents(){ 
  echo "#define mini_getdents generate" 
}
mini_def(){ 
  echo "#define mini_def generate" 
}
mini_acct(){ 
  echo "#define mini_acct generate" 
}
mini_lookup_dcookie(){ 
  echo "#define mini_lookup_dcookie generate" 
}
mini_writes(){ 
  echo "#define mini_writes generate" 
}
mini_ioprio_get(){ 
  echo "#define mini_ioprio_get generate" 
}
mini_sched_getparam(){ 
  echo "#define mini_sched_getparam generate" 
}
mini_setfsgid(){ 
  echo "#define mini_setfsgid generate" 
}
mini_tkill(){ 
  echo "#define mini_tkill generate" 
}
mini_linkat(){ 
  echo "#define mini_linkat generate" 
}
mini_chown(){ 
  echo "#define mini_chown generate" 
}
mini_epoll_create(){ 
  echo "#define mini_epoll_create generate" 
}
mini_rt_tgsigqueueinfo(){ 
  echo "#define mini_rt_tgsigqueueinfo generate" 
}
mini__mprints(){ 
  echo "#define mini__mprints generate" 
}
mini_stat(){ 
  echo "#define mini_stat generate" 
}
mini_vsnprintf(){ 
  echo "#define mini_vsnprintf generate" 
}
mini_getresgid(){ 
  echo "#define mini_getresgid generate" 
}
mini_fgetxattr(){ 
  echo "#define mini_fgetxattr generate" 
}
mini_msync(){ 
  echo "#define mini_msync generate" 
}
mini_timerfd_create(){ 
  echo "#define mini_timerfd_create generate" 
}
mini_fprintf(){ 
  echo "#define mini_fprintf generate" 
}
mini_listen(){ 
  echo "#define mini_listen generate" 
}
mini_memcmp(){ 
  echo "#define mini_memcmp generate" 
}
mini_sched_get_priority_min(){ 
  echo "#define mini_sched_get_priority_min generate" 
}
mini_strerror(){ 
  echo "#define mini_strerror generate" 
}
mini_dtodec(){ 
  echo "#define mini_dtodec generate" 
}
mini_sync_file_range(){ 
  echo "#define mini_sync_file_range generate" 
}
mini_rewind(){ 
  echo "#define mini_rewind generate" 
}
mini_tcgetattr(){ 
  echo "#define mini_tcgetattr generate" 
}
mini_personality(){ 
  echo "#define mini_personality generate" 
}
mini_dup2(){ 
  echo "#define mini_dup2 generate" 
}
mini_setfsuid(){ 
  echo "#define mini_setfsuid generate" 
}
mini_rmdir(){ 
  echo "#define mini_rmdir generate" 
}
mini_strcpy(){ 
  echo "#define mini_strcpy generate" 
}
mini_finit_module(){ 
  echo "#define mini_finit_module generate" 
}
mini_getcwd(){ 
  echo "#define mini_getcwd generate" 
}
mini_fsetxattr(){ 
  echo "#define mini_fsetxattr generate" 
}
mini_sched_setparam(){ 
  echo "#define mini_sched_setparam generate" 
}
mini_setxattr(){ 
  echo "#define mini_setxattr generate" 
}
mini_brk(){ 
  echo "#define mini_brk generate" 
}
mini_printsl(){ 
  echo "#define mini_printsl generate" 
}
mini_eventfd2(){ 
  echo "#define mini_eventfd2 generate" 
}
mini_recvmsg(){ 
  echo "#define mini_recvmsg generate" 
}
mini_rt_sigprocmask(){ 
  echo "#define mini_rt_sigprocmask generate" 
}
mini_unshare(){ 
  echo "#define mini_unshare generate" 
}
mini_opendir(){ 
  echo "#define mini_opendir generate" 
}
mini_timer_delete(){ 
  echo "#define mini_timer_delete generate" 
}
mini_msgrcv(){ 
  echo "#define mini_msgrcv generate" 
}
mini__itobin(){ 
  echo "#define mini__itobin generate" 
}
mini_request_key(){ 
  echo "#define mini_request_key generate" 
}
mini_getpgid(){ 
  echo "#define mini_getpgid generate" 
}
mini_inotify_add_watch(){ 
  echo "#define mini_inotify_add_watch generate" 
}
mini_accept(){ 
  echo "#define mini_accept generate" 
}
mini_vmsplice(){ 
  echo "#define mini_vmsplice generate" 
}
mini_lremovexattr(){ 
  echo "#define mini_lremovexattr generate" 
}
mini__sysctl(){ 
  echo "#define mini__sysctl generate" 
}
mini_read(){ 
  echo "#define mini_read generate" 
}
mini_fclose(){ 
  echo "#define mini_fclose generate" 
}
mini_ptrace(){ 
  echo "#define mini_ptrace generate" 
}
mini_rt_sigaction(){ 
  echo "#define mini_rt_sigaction generate" 
}
# --- define_functions-end: generate --- #

