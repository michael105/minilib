--------------

SIGACTION(2) BSD System Calls Manual SIGACTION(2)

**NAME**

**sigaction** — software signal facilities

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

| struct sigaction {
| void (*sa_handler)(int);
| void (*sa_sigaction)(int, siginfo_t \*, void \*);
| int sa_flags; /\* see signal options below \*/
| sigset_t sa_mask; /\* signal mask to apply \*/
| };

*int*

**sigaction**\ (*int sig*, *const struct sigaction * restrict act*,
*struct sigaction * restrict oact*);

**DESCRIPTION**

The system defines a set of signals that may be delivered to a process.
Signal delivery resembles the occurrence of a hardware interrupt: the
signal is normally blocked from further occurrence, the current thread
context is saved, and a new one is built. A process may specify a
*handler* to which a signal is delivered, or specify that a signal is to
be *ignored*. A process may also specify that a default action is to be
taken by the system when a signal occurs. A signal may also be *blocked*
for a thread, in which case it will not be delivered to that thread
until it is *unblocked*. The action to be taken on delivery is
determined at the time of delivery. Normally, signal handlers execute on
the current stack of the thread. This may be changed, on a per-handler
basis, so that signals are taken on a special *signal stack*.

Signal routines normally execute with the signal that caused their
invocation *blocked*, but other signals may yet occur. A global *signal
mask* defines the set of signals currently blocked from delivery to a
thread. The signal mask for a thread is initialized from that of its
parent (normally empty). It may be changed with a sigprocmask(2) or
pthread_sigmask(3) call, or when a signal is delivered to the thread.

When a signal condition arises for a process or thread, the signal is
added to a set of signals pending for the process or thread. Whether the
signal is directed at the process in general or at a specific thread
depends on how it is generated. For signals directed at a specific
thread, if the signal is not currently *blocked* by the thread then it
is delivered to the thread. For signals directed at the process, if the
signal is not currently *blocked* by all threads then it is delivered to
one thread that does not have it blocked (the selection of which is
unspecified). Signals may be delivered any time a thread enters the
operating system (e.g., during a system call, page fault or trap, or
clock interrupt). If multiple signals are ready to be delivered at the
same time, any signals that could be caused by traps are delivered
first. Additional signals may be processed at the same time, with each
appearing to interrupt the handlers for the previous signals before
their first instructions. The set of pending signals is returned by the
sigpending(2) system call. When a caught signal is delivered, the
current state of the thread is saved, a new signal mask is calculated
(as described below), and the signal handler is invoked. The call to the
handler is arranged so that if the signal handling routine returns
normally the thread will resume execution in the context from before the
signal’s delivery. If the thread wishes to resume in a different
context, then it must arrange to restore the previous context itself.

When a signal is delivered to a thread a new signal mask is installed
for the duration of the process’ signal handler (or until a
sigprocmask(2) system call is made). This mask is formed by taking the
union of the current signal mask set, the signal to be delivered, and
the signal mask associated with the handler to be invoked.

The **sigaction**\ () system call assigns an action for a signal
specified by *sig*. If *act* is non-NULL, it specifies an action
(SIG_DFL, SIG_IGN, or a handler routine) and mask to be used when
delivering the specified signal. If *oact* is non-NULL, the previous
handling information for the signal is returned to the user.

The above declaration of *struct sigaction* is not literal. It is
provided only to list the accessible members. See <*sys/signal.h*> for
the actual definition. In particular, the storage occupied by
*sa_handler* and *sa_sigaction* overlaps, and it is nonsensical for an
application to attempt to use both simultaneously.

Once a signal handler is installed, it normally remains installed until
another **sigaction**\ () system call is made, or an execve(2) is
performed. A signal-specific default action may be reset by setting
*sa_handler* to SIG_DFL. The defaults are process termination, possibly
with core dump; no action; stopping the process; or continuing the
process. See the signal list below for each signal’s default action. If
*sa_handler* is SIG_DFL, the default action for the signal is to discard
the signal, and if a signal is pending, the pending signal is discarded
even if the signal is masked. If *sa_handler* is set to SIG_IGN current
and pending instances of the signal are ignored and discarded.

Options may be specified by setting *sa_flags*. The meaning of the
various bits is as follows:

SA_NOCLDSTOP

If this bit is set when installing a catching function for the SIGCHLD
signal, the SIGCHLD signal will be generated only when a child process
exits, not when a child process stops.

SA_NOCLDWAIT

If this bit is set when calling **sigaction**\ () for the SIGCHLD
signal, the system will not create zombie processes when children of the
calling process exit. If the calling process subsequently issues a
wait(2) (or equivalent), it blocks until all of the calling process’s
child processes terminate, and then returns a value of −1 with *errno*
set to ECHILD. The same effect of avoiding zombie creation can also be
achieved by setting *sa_handler* for SIGCHLD to SIG_IGN.

SA_ONSTACK

If this bit is set, the system will deliver the signal to the process on
a *signal stack*, specified by each thread with sigaltstack(2).

SA_NODEFER

If this bit is set, further occurrences of the delivered signal are not
masked during the execution of the handler.

SA_RESETHAND

If this bit is set, the handler is reset back to SIG_DFL at the moment
the signal is delivered.

SA_RESTART

See paragraph below.

SA_SIGINFO

If this bit is set, the handler function is assumed to be pointed to by
the *sa_sigaction* member of *struct sigaction* and should match the
prototype shown above or as below in *EXAMPLES*. This bit should not be
set when assigning SIG_DFL or SIG_IGN.

If a signal is caught during the system calls listed below, the call may
be forced to terminate with the error EINTR, the call may return with a
data transfer shorter than requested, or the call may be restarted.
Restart of pending calls is requested by setting the SA_RESTART bit in
*sa_flags*. The affected system calls include open(2), read(2),
write(2), sendto(2), recvfrom(2), sendmsg(2) and recvmsg(2) on a
communications channel or a slow device (such as a terminal, but not a
regular file) and during a wait(2) or ioctl(2). However, calls that have
already committed are not restarted, but instead return a partial
success (for example, a short read count).

After a pthread_create(3) the signal mask is inherited by the new thread
and the set of pending signals and the signal stack for the new thread
are empty.

After a fork(2) or vfork(2) all signals, the signal mask, the signal
stack, and the restart/interrupt flags are inherited by the child.

The execve(2) system call reinstates the default action for all signals
which were caught and resets all signals to be caught on the user stack.
Ignored signals remain ignored; the signal mask remains the same;
signals that restart pending system calls continue to do so.

The following is a list of all signals with names as in the include file
<*signal.h*>:

| **NAME Default Action Description**
| SIGHUP terminate process terminal line hangup
| SIGINT terminate process interrupt program
| SIGQUIT create core image quit program
| SIGILL create core image illegal instruction
| SIGTRAP create core image trace trap
| SIGABRT create core image abort(3) call (formerly SIGIOT)
| SIGEMT create core image emulate instruction executed
| SIGFPE create core image floating-point exception
| SIGKILL terminate process kill program
| SIGBUS create core image bus error
| SIGSEGV create core image segmentation violation
| SIGSYS create core image non-existent system call invoked
| SIGPIPE terminate process write on a pipe with no reader
| SIGALRM terminate process real-time timer expired
| SIGTERM terminate process software termination signal
| SIGURG discard signal urgent condition present on socket
| SIGSTOP stop process stop (cannot be caught or ignored)
| SIGTSTP stop process stop signal generated from keyboard
| SIGCONT discard signal continue after stop
| SIGCHLD discard signal child status has changed
| SIGTTIN stop process background read attempted from control terminal
| SIGTTOU stop process background write attempted to control terminal
| SIGIO discard signal I/O is possible on a descriptor (see fcntl(2))
| SIGXCPU terminate process cpu time limit exceeded (see setrlimit(2))
| SIGXFSZ terminate process file size limit exceeded (see setrlimit(2))
| SIGVTALRM terminate process virtual time alarm (see setitimer(2))
| SIGPROF terminate process profiling timer alarm (see setitimer(2))
| SIGWINCH discard signal window size change
| SIGINFO discard signal status request from keyboard
| SIGUSR1 terminate process user defined signal 1
| SIGUSR2 terminate process user defined signal 2

**NOTE**

The *sa_mask* field specified in *act* is not allowed to block SIGKILL
or SIGSTOP. Any attempt to do so will be silently ignored.

The following functions are either reentrant or not interruptible by
signals and are async-signal safe. Therefore applications may invoke
them, without restriction, from signal-catching functions or from a
child process after calling fork(2) in a multi-threaded process:

Base Interfaces:

**\_Exit**\ (), **\_exit**\ (), **accept**\ (), **access**\ (),
**alarm**\ (), **bind**\ (), **cfgetispeed**\ (), **cfgetospeed**\ (),
**cfsetispeed**\ (), **cfsetospeed**\ (), **chdir**\ (), **chmod**\ (),
**chown**\ (), **close**\ (), **connect**\ (), **creat**\ (),
**dup**\ (), **dup2**\ (), **execl**\ (), **execle**\ (), **execv**\ (),
**execve**\ (), **faccessat**\ (), **fchdir**\ (), **fchmod**\ (),
**fchmodat**\ (), **fchown**\ (), **fchownat**\ (), **fcntl**\ (),
**fork**\ (), **fstat**\ (), **fstatat**\ (), **fsync**\ (),
**ftruncate**\ (), **getegid**\ (), **geteuid**\ (), **getgid**\ (),
**getgroups**\ (), **getpeername**\ (), **getpgrp**\ (), **getpid**\ (),
**getppid**\ (), **getsockname**\ (), **getsockopt**\ (),
**getuid**\ (), **kill**\ (), **link**\ (), **linkat**\ (),
**listen**\ (), **lseek**\ (), **lstat**\ (), **mkdir**\ (),
**mkdirat**\ (), **mkfifo**\ (), **mkfifoat**\ (), **mknod**\ (),
**mknodat**\ (), **open**\ (), **openat**\ (), **pause**\ (),
**pipe**\ (), **poll**\ (), **pselect**\ (), **pthread_sigmask**\ (),
**raise**\ (), **read**\ (), **readlink**\ (), **readlinkat**\ (),
**recv**\ (), **recvfrom**\ (), **recvmsg**\ (), **rename**\ (),
**renameat**\ (), **rmdir**\ (), **select**\ (), **send**\ (),
**sendmsg**\ (), **sendto**\ (), **setgid**\ (), **setpgid**\ (),
**setsid**\ (), **setsockopt**\ (), **setuid**\ (), **shutdown**\ (),
**sigaction**\ (), **sigaddset**\ (), **sigdelset**\ (),
**sigemptyset**\ (), **sigfillset**\ (), **sigismember**\ (),
**signal**\ (), **sigpending**\ (), **sigprocmask**\ (),
**sigsuspend**\ (), **sleep**\ (), **sockatmark**\ (), **socket**\ (),
**socketpair**\ (), **stat**\ (), **symlink**\ (), **symlinkat**\ (),
**tcdrain**\ (), **tcflow**\ (), **tcflush**\ (), **tcgetattr**\ (),
**tcgetpgrp**\ (), **tcsendbreak**\ (), **tcsetattr**\ (),
**tcsetpgrp**\ (), **time**\ (), **times**\ (), **umask**\ (),
**uname**\ (), **unlink**\ (), **unlinkat**\ (), **utime**\ (),
**wait**\ (), **waitpid**\ (), **write**\ ().

X/Open Systems Interfaces:

**sigpause**\ (), **sigset**\ (), **utimes**\ ().

Realtime Interfaces:

**aio_error**\ (), **clock_gettime**\ (), **timer_getoverrun**\ (),
**aio_return**\ (), **fdatasync**\ (), **sigqueue**\ (),
**timer_gettime**\ (), **aio_suspend**\ (), **sem_post**\ (),
**timer_settime**\ ().

Base Interfaces not specified as async-signal safe by POSIX:

**fpathconf**\ (), **pathconf**\ (), **sysconf**\ ().

Base Interfaces not specified as async-signal safe by POSIX, but planned
to be:

**ffs**\ (), **htonl**\ (), **htons**\ (), **memccpy**\ (),
**memchr**\ (), **memcmp**\ (), **memcpy**\ (), **memmove**\ (),
**memset**\ (), **ntohl**\ (), **ntohs**\ (), **stpcpy**\ (),
**stpncpy**\ (), **strcat**\ (), **strchr**\ (), **strcmp**\ (),
**strcpy**\ (), **strcspn**\ (), **strlen**\ (), **strncat**\ (),
**strncmp**\ (), **strncpy**\ (), **strnlen**\ (), **strpbrk**\ (),
**strrchr**\ (), **strspn**\ (), **strstr**\ (), **strtok_r**\ (),
**wcpcpy**\ (), **wcpncpy**\ (), **wcscat**\ (), **wcschr**\ (),
**wcscmp**\ (), **wcscpy**\ (), **wcscspn**\ (), **wcslen**\ (),
**wcsncat**\ (), **wcsncmp**\ (), **wcsncpy**\ (), **wcsnlen**\ (),
**wcspbrk**\ (), **wcsrchr**\ (), **wcsspn**\ (), **wcsstr**\ (),
**wcstok**\ (), **wmemchr**\ (), **wmemcmp**\ (), **wmemcpy**\ (),
**wmemmove**\ (), **wmemset**\ ().

Extension Interfaces:

**accept4**\ (), **bindat**\ (), **closefrom**\ (), **connectat**\ (),
**eaccess**\ (), **ffsl**\ (), **ffsll**\ (), **flock**\ (),
**fls**\ (), **flsl**\ (), **flsll**\ (), **futimesat**\ (),
**pipe2**\ (), **strlcat**\ (). **strlcpy**\ (), **strsep**\ ().

In addition, reading or writing *errno* is async-signal safe.

All functions not in the above lists are considered to be unsafe with
respect to signals. That is to say, the behaviour of such functions is
undefined when they are called from a signal handler that interrupted an
unsafe function. In general though, signal handlers should do little
more than set a flag; most other actions are not safe.

Also, it is good practice to make a copy of the global variable *errno*
and restore it before returning from the signal handler. This protects
against the side effect of *errno* being set by functions called from
inside the signal handler.

**RETURN VALUES**

The **sigaction**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**EXAMPLES**

There are three possible prototypes the handler may match:

ANSI C:

*void* **handler**\ (*int*);

Traditional BSD style:

*void* **handler**\ (*int*, *int code*, *struct sigcontext \*scp*);

POSIX SA_SIGINFO:

*void* **handler**\ (*int*, *siginfo_t \*info*, *ucontext_t \*uap*);

The handler function should match the SA_SIGINFO prototype if the
SA_SIGINFO bit is set in *sa_flags*. It then should be pointed to by the
*sa_sigaction* member of *struct sigaction*. Note that you should not
assign SIG_DFL or SIG_IGN this way.

If the SA_SIGINFO flag is not set, the handler function should match
either the ANSI C or traditional BSD prototype and be pointed to by the
*sa_handler* member of *struct sigaction*. In practice, FreeBSD always
sends the three arguments of the latter and since the ANSI C prototype
is a subset, both will work. The *sa_handler* member declaration in
FreeBSD include files is that of ANSI C (as required by POSIX), so a
function pointer of a BSD-style function needs to be casted to compile
without warning. The traditional BSD style is not portable and since its
capabilities are a full subset of a SA_SIGINFO handler, its use is
deprecated.

The *sig* argument is the signal number, one of the SIG... values from
<*signal.h*>.

The *code* argument of the BSD-style handler and the *si_code* member of
the *info* argument to a SA_SIGINFO handler contain a numeric code
explaining the cause of the signal, usually one of the SI_... values
from <*sys/signal.h*> or codes specific to a signal, i.e., one of the
FPE_... values for SIGFPE.

The *scp* argument to a BSD-style handler points to an instance of
*struct sigcontext*.

The *uap* argument to a POSIX SA_SIGINFO handler points to an instance
of ucontext_t.

**ERRORS**

The **sigaction**\ () system call will fail and no new signal handler
will be installed if one of the following occurs:

[EINVAL]

The *sig* argument is not a valid signal number.

[EINVAL]

An attempt is made to ignore or supply a handler for SIGKILL or SIGSTOP.

**SEE ALSO**

kill(1), kill(2), ptrace(2), setitimer(2), setrlimit(2), sigaltstack(2),
sigpending(2), sigprocmask(2), sigsuspend(2), wait(2), fpsetmask(3),
setjmp(3), siginfo(3), siginterrupt(3), sigsetops(3), ucontext(3),
tty(4)

**STANDARDS**

The **sigaction**\ () system call is expected to conform to ISO/IEC
9945-1:1990 (‘‘POSIX.1’’). The SA_ONSTACK and SA_RESTART flags are
Berkeley extensions, as are the signals, SIGTRAP, SIGEMT, SIGBUS,
SIGSYS, SIGURG, SIGIO, SIGXCPU, SIGXFSZ, SIGVTALRM, SIGPROF, SIGWINCH,
and SIGINFO. Those signals are available on most BSD−derived systems.
The SA_NODEFER and SA_RESETHAND flags are intended for backwards
compatibility with other operating systems. The SA_NOCLDSTOP, and
SA_NOCLDWAIT flags are featuring options commonly found in other
operating systems. The flags are approved by Version 2 of the Single
UNIX Specification (‘‘SUSv2’’), along with the option to avoid zombie
creation by ignoring SIGCHLD.

BSD June 28, 2018 BSD

--------------

.. Copyright (c) 1990, 1991, 1993
..	The Regents of the University of California.  All rights reserved.
..
.. This code is derived from software contributed to Berkeley by
.. Chris Torek and the American National Standards Committee X3,
.. on Information Processing Systems.
..
.. Redistribution and use in source and binary forms, with or without
.. modification, are permitted provided that the following conditions
.. are met:
.. 1. Redistributions of source code must retain the above copyright
..    notice, this list of conditions and the following disclaimer.
.. 2. Redistributions in binary form must reproduce the above copyright
..    notice, this list of conditions and the following disclaimer in the
..    documentation and/or other materials provided with the distribution.
.. 3. Neither the name of the University nor the names of its contributors
..    may be used to endorse or promote products derived from this software
..    without specific prior written permission.
..
.. THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
.. ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
.. IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
.. ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
.. FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
.. DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
.. OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
.. HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
.. LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
.. OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
.. SUCH DAMAGE.

