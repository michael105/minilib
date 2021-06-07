--------------

KILL(2) BSD System Calls Manual KILL(2)

**NAME**

**kill** — send signal to a process

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/types.h>
#include <signal.h>**

*int*

**kill**\ (*pid_t pid*, *int sig*);

**DESCRIPTION**

The **kill**\ () system call sends the signal given by *sig* to *pid*, a
process or a group of processes. The *sig* argument may be one of the
signals specified in sigaction(2) or it may be 0, in which case error
checking is performed but no signal is actually sent. This can be used
to check the validity of *pid*.

For a process to have permission to send a signal to a process
designated by *pid*, the user must be the super-user, or the real or
saved user ID of the receiving process must match the real or effective
user ID of the sending process. A single exception is the signal
SIGCONT, which may always be sent to any process with the same session
ID as the sender. In addition, if the
*security.bsd.conservative_signals* sysctl(9) is set to 1, the user is
not a super-user, and the receiver is set-uid, then only job control and
terminal control signals may be sent (in particular, only SIGKILL,
SIGINT, SIGTERM, SIGALRM, SIGSTOP, SIGTTIN, SIGTTOU, SIGTSTP, SIGHUP,
SIGUSR1, SIGUSR2).

If *pid* is greater than zero:

The *sig* signal is sent to the process whose ID is equal to *pid*.

If *pid* is zero:

The *sig* signal is sent to all processes whose group ID is equal to the
process group ID of the sender, and for which the process has
permission; this is a variant of killpg(2).

If *pid* is -1:

If the user has super-user privileges, the signal is sent to all
processes excluding system processes (with P_SYSTEM flag set), process
with ID 1 (usually init(8)), and the process sending the signal. If the
user is not the super user, the signal is sent to all processes with the
same uid as the user excluding the process sending the signal. No error
is returned if any process could be signaled.

For compatibility with System V, if the process number is negative but
not -1, the signal is sent to all processes whose process group ID is
equal to the absolute value of the process number. This is a variant of
killpg(2).

**RETURN VALUES**

The **kill**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **kill**\ () system call will fail and no signal will be sent if:

[EINVAL]

The *sig* argument is not a valid signal number.

[ESRCH]

No process or process group can be found corresponding to that specified
by *pid*.

[EPERM]

The sending process does not have permission to send *sig* to the
receiving process.

**SEE ALSO**

getpgrp(2), getpid(2), killpg(2), sigaction(2), sigqueue(2), raise(3),
init(8)

**STANDARDS**

The **kill**\ () system call is expected to conform to ISO/IEC
9945-1:1990 (‘‘POSIX.1’’).

**HISTORY**

A version of the **kill**\ () function appeared in Version 3 AT&T UNIX.
The signal number was added to the **kill**\ () function in Version 4
AT&T UNIX.

BSD December 1, 2017 BSD

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

