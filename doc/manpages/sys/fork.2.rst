--------------

FORK(2) BSD System Calls Manual FORK(2)

**NAME**

**fork** — create a new process

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*pid_t*

**fork**\ (*void*);

**DESCRIPTION**

The **fork**\ () system call causes creation of a new process. The new
process (child process) is an exact copy of the calling process (parent
process) except for the following:

**•**

The child process has a unique process ID.

**•**

The child process has a different parent process ID (i.e., the process
ID of the parent process).

**•**

The child process has its own copy of the parent’s descriptors, except
for descriptors returned by kqueue(2), which are not inherited from the
parent process. These descriptors reference the same underlying objects,
so that, for instance, file pointers in file objects are shared between
the child and the parent, so that an lseek(2) on a descriptor in the
child process can affect a subsequent read(2) or write(2) by the parent.
This descriptor copying is also used by the shell to establish standard
input and output for newly created processes as well as to set up pipes.

**•**

The child process’ resource utilizations are set to 0; see setrlimit(2).

**•**

All interval timers are cleared; see setitimer(2).

**•**

The child process has only one thread, corresponding to the calling
thread in the parent process. If the process has more than one thread,
locks and other resources held by the other threads are not released and
therefore only async-signal-safe functions (see sigaction(2)) are
guaranteed to work in the child process until a call to execve(2) or a
similar function.

**RETURN VALUES**

Upon successful completion, **fork**\ () returns a value of 0 to the
child process and returns the process ID of the child process to the
parent process. Otherwise, a value of -1 is returned to the parent
process, no child process is created, and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **fork**\ () system call will fail and no child process will be
created if:

[EAGAIN]

The system-imposed limit on the total number of processes under
execution would be exceeded. The limit is given by the sysctl(3) MIB
variable KERN_MAXPROC. (The limit is actually ten less than this except
for the super user).

[EAGAIN]

The user is not the super user, and the system-imposed limit on the
total number of processes under execution by a single user would be
exceeded. The limit is given by the sysctl(3) MIB variable
KERN_MAXPROCPERUID.

[EAGAIN]

The user is not the super user, and the soft resource limit
corresponding to the *resource* argument RLIMIT_NPROC would be exceeded
(see getrlimit(2)).

[ENOMEM]

There is insufficient swap space for the new process.

**SEE ALSO**

execve(2), rfork(2), setitimer(2), setrlimit(2), sigaction(2), vfork(2),
wait(2)

**HISTORY**

The **fork**\ () function appeared in Version 1 AT&T UNIX.

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

