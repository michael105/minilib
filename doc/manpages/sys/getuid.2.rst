--------------

GETUID(2) BSD System Calls Manual GETUID(2)

**NAME**

**getuid**, **geteuid** — get user identification

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*uid_t*

**getuid**\ (*void*);

*uid_t*

**geteuid**\ (*void*);

**DESCRIPTION**

The **getuid**\ () system call returns the real user ID of the calling
process. The **geteuid**\ () system call returns the effective user ID
of the calling process.

The real user ID is that of the user who has invoked the program. As the
effective user ID gives the process additional permissions during
execution of ‘‘\ *set-user-ID*\ ’’ mode processes, **getuid**\ () is
used to determine the real-user-id of the calling process.

**ERRORS**

The **getuid**\ () and **geteuid**\ () system calls are always
successful, and no return value is reserved to indicate an error.

**SEE ALSO**

getgid(2), issetugid(2), setgid(2), setreuid(2), setuid(2)

**STANDARDS**

The **geteuid**\ () and **getuid**\ () system calls are expected to
conform to ISO/IEC 9945-1:1990 (‘‘POSIX.1’’).

**HISTORY**

The **getuid**\ () function appeared in Version 1 AT&T UNIX. The
**geteuid**\ () function appeared in Version 4 AT&T UNIX.

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

