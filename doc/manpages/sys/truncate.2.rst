--------------

TRUNCATE(2) BSD System Calls Manual TRUNCATE(2)

**NAME**

**truncate**, **ftruncate** — truncate or extend a file to a specified
length

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**truncate**\ (*const char *path*, *off_t length*);

*int*

**ftruncate**\ (*int fd*, *off_t length*);

**DESCRIPTION**

The **truncate**\ () system call causes the file named by *path* or
referenced by *fd* to be truncated or extended to *length* bytes in
size. If the file was larger than this size, the extra data is lost. If
the file was smaller than this size, it will be extended as if by
writing bytes with the value zero.

The **ftruncate**\ () system call causes the file or shared memory
object backing the file descriptor *fd* to be truncated or extended to
*length* bytes in size. The file descriptor must be a valid file
descriptor open for writing. The file position pointer associated with
the file descriptor *fd* will not be modified.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error. If the file to be modified is not a directory or a regular
file, the **truncate**\ () call has no effect and returns the value 0.

**ERRORS**

The **truncate**\ () system call succeeds unless:

[ENOTDIR]

A component of the path prefix is not a directory.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[ENOENT]

The named file does not exist.

[EACCES]

Search permission is denied for a component of the path prefix.

[EACCES]

The named file is not writable by the user.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[EPERM]

The named file has its immutable or append-only flag set, see the
chflags(2) manual page for more information.

[EISDIR]

The named file is a directory.

[EROFS]

The named file resides on a read-only file system.

[ETXTBSY]

The file is a pure procedure (shared text) file that is being executed.

[EFBIG]

The *length* argument was greater than the maximum file size.

[EINVAL]

The *length* argument was less than 0.

[EIO]

An I/O error occurred updating the inode.

[EFAULT]

The *path* argument points outside the process’s allocated address
space.

The **ftruncate**\ () system call succeeds unless:

[EBADF]

The *fd* argument is not a valid descriptor.

[EINVAL]

The *fd* argument references a file descriptor that is not a regular
file or shared memory object.

[EINVAL]

The *fd* descriptor is not open for writing.

**SEE ALSO**

chflags(2), open(2), shm_open(2)

**HISTORY**

The **truncate**\ () and **ftruncate**\ () system calls appeared in
4.2BSD.

**BUGS**

These calls should be generalized to allow ranges of bytes in a file to
be discarded.

Use of **truncate**\ () to extend a file is not portable.

BSD May 4, 2015 BSD

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

