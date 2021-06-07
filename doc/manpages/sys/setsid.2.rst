--------------

SETSID(2) BSD System Calls Manual SETSID(2)

**NAME**

**setsid** — create session and set process group ID

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*pid_t*

**setsid**\ (*void*);

**DESCRIPTION**

The **setsid**\ () system call creates a new session. The calling
process is the session leader of the new session, is the process group
leader of a new process group and has no controlling terminal. The
calling process is the only process in either the session or the process
group.

**RETURN VALUES**

Upon successful completion, the **setsid**\ () system call returns the
value of the process group ID of the new process group, which is the
same as the process ID of the calling process. If an error occurs,
**setsid**\ () returns -1 and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **setsid**\ () system call will fail if:

[EPERM]

The calling process is already a process group leader, or the process
group ID of a process other than the calling process matches the process
ID of the calling process.

**SEE ALSO**

setpgid(2), tcgetpgrp(3), tcsetpgrp(3)

**STANDARDS**

The **setsid**\ () system call is expected to be compliant with the
ISO/IEC 9945-1:1990 (‘‘POSIX.1’’) specification.

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

