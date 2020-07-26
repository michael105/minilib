--------------

UMASK(2) BSD System Calls Manual UMASK(2)

**NAME**

**umask** — set file creation mode mask

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/stat.h>**

*mode_t*

**umask**\ (*mode_t numask*);

**DESCRIPTION**

The **umask**\ () routine sets the process’s file mode creation mask to
*numask* and returns the previous value of the mask. The 9 low-order
access permission bits of *numask* are used by system calls, including
open(2), mkdir(2), and mkfifo(2), to turn off corresponding bits
requested in file mode. (See chmod(2)). This clearing allows each user
to restrict the default access to his files.

The default mask value is S_IWGRP|S_IWOTH (022, write access for the
owner only). Child processes inherit the mask of the calling process.

**RETURN VALUES**

The previous value of the file mode mask is returned by the call.

**ERRORS**

The **umask**\ () system call is always successful.

**SEE ALSO**

chmod(2), mkfifo(2), mknod(2), open(2)

**STANDARDS**

The **umask**\ () system call is expected to conform to ISO/IEC
9945-1:1990 (‘‘POSIX.1’’).

**HISTORY**

The **umask**\ () function appeared in Version 7 AT&T UNIX.

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

