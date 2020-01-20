--------------

FSYNC(2) BSD System Calls Manual FSYNC(2)

**NAME**

**fdatasync**, **fsync** — synchronise changes to a file

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**fdatasync**\ (*int fd*);

*int*

**fsync**\ (*int fd*);

**DESCRIPTION**

The **fsync**\ () system call causes all modified data and attributes of
the file referenced by the file descriptor *fd* to be moved to a
permanent storage device. This normally results in all in-core modified
copies of buffers for the associated file to be written to a disk.

The **fdatasync**\ () system call causes all modified data of *fd* to be
moved to a permanent storage device. Unlike **fsync**\ (), the system
call does not guarantee that file attributes or metadata necessary to
access the file are committed to the permanent storage.

The **fsync**\ () system call should be used by programs that require a
file to be in a known state, for example, in building a simple
transaction facility. If the file metadata has already been committed,
using **fdatasync**\ () can be more efficient than **fsync**\ ().

Both **fdatasync**\ () and **fsync**\ () calls are cancellation points.

**RETURN VALUES**

The **fsync**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **fsync**\ () and **fdatasync**\ () calls fail if:

[EBADF]

The *fd* argument is not a valid descriptor.

[EINVAL]

The *fd* argument refers to a socket, not to a file.

[EIO]

An I/O error occurred while reading from or writing to the file system.

**SEE ALSO**

fsync(1), sync(2), syncer(4), sync(8)

**HISTORY**

The **fsync**\ () system call appeared in 4.2BSD. The **fdatasync**\ ()
system call appeared in FreeBSD 11.1.

**BUGS**

The **fdatasync**\ () system call currently does not guarantee that
enqueued aio(4) requests for the file referenced by *fd* are completed
before the syscall returns.

BSD February 6, 2018 BSD

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

