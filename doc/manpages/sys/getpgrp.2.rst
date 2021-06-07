--------------

GETPGRP(2) BSD System Calls Manual GETPGRP(2)

**NAME**

**getpgrp** — get process group

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*pid_t*

**getpgrp**\ (*void*);

*pid_t*

**getpgid**\ (*pid_t pid*);

**DESCRIPTION**

The process group of the current process is returned by **getpgrp**\ ().
The process group of the process identified by *pid* is returned by
**getpgid**\ (). If *pid* is zero, **getpgid**\ () returns the process
group of the current process.

Process groups are used for distribution of signals, and by terminals to
arbitrate requests for their input: processes that have the same process
group as the terminal are foreground and may read, while others will
block with a signal if they attempt to read.

This system call is thus used by programs such as csh(1) to create
process groups in implementing job control. The **tcgetpgrp**\ () and
**tcsetpgrp**\ () calls are used to get/set the process group of the
control terminal.

**RETURN VALUES**

The **getpgrp**\ () system call always succeeds. Upon successful
completion, the **getpgid**\ () system call returns the process group of
the specified process; otherwise, it returns a value of −1 and sets
*errno* to indicate the error.

**COMPATIBILITY**

This version of **getpgrp**\ () differs from past Berkeley versions by
not taking a *pid_t pid* argument. This incompatibility is required by
ISO/IEC 9945-1:1990 (‘‘POSIX.1’’).

From the ISO/IEC 9945-1:1990 (‘‘POSIX.1’’) Rationale:

4.3BSD provides a **getpgrp**\ () system call that returns the process
group ID for a specified process. Although this function is used to
support job control, all known job-control shells always specify the
calling process with this function. Thus, the simpler AT&T System V UNIX
**getpgrp**\ () suffices, and the added complexity of the 4.3BSD
**getpgrp**\ () has been omitted from POSIX.1. The old functionality is
available from the **getpgid**\ () system call.

**ERRORS**

The **getpgid**\ () system call will succeed unless:

[ESRCH]

there is no process whose process ID equals *pid*

**SEE ALSO**

getsid(2), setpgid(2), termios(4)

**STANDARDS**

The **getpgrp**\ () system call is expected to conform to ISO/IEC
9945-1:1990 (‘‘POSIX.1’’).

**HISTORY**

The **getpgrp**\ () system call appeared in 4.0BSD. The **getpgid**\ ()
system call is derived from its usage in AT&T System V Release 4 UNIX.

BSD June 4, 1993 BSD

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

