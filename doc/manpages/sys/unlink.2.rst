--------------

UNLINK(2) BSD System Calls Manual UNLINK(2)

**NAME**

**unlink**, **unlinkat** — remove directory entry

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**unlink**\ (*const char *path*);

*int*

**unlinkat**\ (*int fd*, *const char *path*, *int flag*);

**DESCRIPTION**

The **unlink**\ () system call removes the link named by *path* from its
directory and decrements the link count of the file which was referenced
by the link. If that decrement reduces the link count of the file to
zero, and no process has the file open, then all resources associated
with the file are reclaimed. If one or more process have the file open
when the last link is removed, the link is removed, but the removal of
the file is delayed until all references to it have been closed. The
*path* argument may not be a directory.

The **unlinkat**\ () system call is equivalent to **unlink**\ () or
**rmdir**\ () except in the case where *path* specifies a relative path.
In this case the directory entry to be removed is determined relative to
the directory associated with the file descriptor *fd* instead of the
current working directory.

The values for *flag* are constructed by a bitwise-inclusive OR of flags
from the following list, defined in <*fcntl.h*>:

AT_REMOVEDIR

Remove the directory entry specified by *fd* and *path* as a directory,
not a normal file.

AT_BENEATH

Only unlink files and directories which are beneath of the topping
directory. See the description of the O_BENEATH flag in the open(2)
manual page.

If **unlinkat**\ () is passed the special value AT_FDCWD in the *fd*
parameter, the current working directory is used and the behavior is
identical to a call to *unlink* or *rmdir* respectively, depending on
whether or not the AT_REMOVEDIR bit is set in flag.

**RETURN VALUES**

The **unlink**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

**ERRORS**

The **unlink**\ () succeeds unless:

[ENOTDIR]

A component of the path prefix is not a directory.

[EISDIR]

The named file is a directory.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[ENOENT]

The named file does not exist.

[EACCES]

Search permission is denied for a component of the path prefix.

[EACCES]

Write permission is denied on the directory containing the link to be
removed.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[EPERM]

The named file is a directory.

[EPERM]

The named file has its immutable, undeletable or append-only flag set,
see the chflags(2) manual page for more information.

[EPERM]

The parent directory of the named file has its immutable or append-only
flag set.

[EPERM]

The directory containing the file is marked sticky, and neither the
containing directory nor the file to be removed are owned by the
effective user ID.

[EIO]

An I/O error occurred while deleting the directory entry or deallocating
the inode.

[EROFS]

The named file resides on a read-only file system.

[EFAULT]

The *path* argument points outside the process’s allocated address
space.

[ENOSPC]

On file systems supporting copy-on-write or snapshots, there was not
enough free space to record metadata for the delete operation of the
file.

In addition to the errors returned by the **unlink**\ (), the
**unlinkat**\ () may fail if:

[EBADF]

The *path* argument does not specify an absolute path and the *fd*
argument is neither AT_FDCWD nor a valid file descriptor open for
searching.

[ENOTEMPTY]

The *flag* parameter has the AT_REMOVEDIR bit set and the *path*
argument names a directory that is not an empty directory, or there are
hard links to the directory other than dot or a single entry in dot-dot.

[ENOTDIR]

The *flag* parameter has the AT_REMOVEDIR bit set and *path* does not
name a directory.

[EINVAL]

The value of the *flag* argument is not valid.

[ENOTDIR]

The *path* argument is not an absolute path and *fd* is neither AT_FDCWD
nor a file descriptor associated with a directory.

[ENOTCAPABLE]

*path* is an absolute path, or contained a ".." component leading to a
directory outside of the directory hierarchy specified by *fd*, and the
process is in capability mode.

[ENOTCAPABLE]

The AT_BENEATH flag was provided to **unlinkat**\ (), and the absolute
*path* does not have its tail fully contained under the topping
directory, or the relative *path* escapes it.

**SEE ALSO**

chflags(2), close(2), link(2), rmdir(2), symlink(7)

**STANDARDS**

The **unlinkat**\ () system call follows The Open Group Extended API Set
2 specification.

**HISTORY**

The **unlink**\ () function appeared in Version 1 AT&T UNIX. The
**unlinkat**\ () system call appeared in FreeBSD 8.0.

The **unlink**\ () system call traditionally allows the super-user to
unlink directories which can damage the file system integrity. This
implementation no longer permits it.

BSD November 11, 2018 BSD

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

