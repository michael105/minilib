--------------

RMDIR(2) BSD System Calls Manual RMDIR(2)

**NAME**

**rmdir** — remove a directory file

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**rmdir**\ (*const char *path*);

**DESCRIPTION**

The **rmdir**\ () system call removes a directory file whose name is
given by *path*. The directory must not have any entries other than ‘.’
and ‘..’.

**RETURN VALUES**

The **rmdir**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The named file is removed unless:

[ENOTDIR]

A component of the path is not a directory.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[ENOENT]

The named directory does not exist.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[ENOTEMPTY]

The named directory contains files other than ‘.’ and ‘..’ in it.

[EACCES]

Search permission is denied for a component of the path prefix.

[EACCES]

Write permission is denied on the directory containing the link to be
removed.

[EPERM]

The directory to be removed has its immutable, undeletable or
append-only flag set, see the chflags(2) manual page for more
information.

[EPERM]

The parent directory of the directory to be removed has its immutable or
append-only flag set.

[EPERM]

The directory containing the directory to be removed is marked sticky,
and neither the containing directory nor the directory to be removed are
owned by the effective user ID.

[EINVAL]

The last component of the path is ‘.’ or ‘..’.

[EBUSY]

The directory to be removed is the mount point for a mounted file
system.

[EIO]

An I/O error occurred while deleting the directory entry or deallocating
the inode.

[EROFS]

The directory entry to be removed resides on a read-only file system.

[EFAULT]

The *path* argument points outside the process’s allocated address
space.

**SEE ALSO**

mkdir(2), unlink(2)

**HISTORY**

The **rmdir**\ () system call appeared in 4.2BSD.

BSD December 9, 2006 BSD

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

