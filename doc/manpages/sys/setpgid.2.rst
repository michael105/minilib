--------------

SETPGID(2) BSD System Calls Manual SETPGID(2)

**NAME**

**setpgid**, **setpgrp** — set process group

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**setpgid**\ (*pid_t pid*, *pid_t pgrp*);

*int*

**setpgrp**\ (*pid_t pid*, *pid_t pgrp*);

**DESCRIPTION**

The **setpgid**\ () system call sets the process group of the specified
process *pid* to the specified *pgrp*. If *pid* is zero, then the call
applies to the current process. If *pgrp* is zero, then the process id
of the process specified by *pid* is used instead.

If the affected process is not the invoking process, then it must be a
child of the invoking process, it must not have performed an exec(3)
operation, and both processes must be in the same session. The requested
process group ID must already exist in the session of the caller, or it
must be equal to the target process ID.

**RETURN VALUES**

The **setpgid**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**COMPATIBILITY**

The **setpgrp**\ () system call is identical to **setpgid**\ (), and is
retained for calling convention compatibility with historical versions
of BSD.

**ERRORS**

The **setpgid**\ () system call will fail and the process group will not
be altered if:

[EINVAL]

The requested process group ID is not legal.

[ESRCH]

The requested process does not exist.

[ESRCH]

The target process is not the calling process or a child of the calling
process.

[EACCES]

The requested process is a child of the calling process, but it has
performed an exec(3) operation.

[EPERM]

The target process is a session leader.

[EPERM]

The requested process group ID is not in the session of the caller, and
it is not equal to the process ID of the target process.

**SEE ALSO**

getpgrp(2)

**STANDARDS**

The **setpgid**\ () system call is expected to conform to ISO/IEC
9945-1:1990 (‘‘POSIX.1’’).

BSD February 8, 2004 BSD

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

