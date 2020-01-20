--------------

CHDIR(2) BSD System Calls Manual CHDIR(2)

**NAME**

**chdir**, **fchdir** — change current working directory

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**chdir**\ (*const char *path*);

*int*

**fchdir**\ (*int fd*);

**DESCRIPTION**

The *path* argument points to the pathname of a directory. The
**chdir**\ () system call causes the named directory to become the
current working directory, that is, the starting point for path searches
of pathnames not beginning with a slash, ‘/’.

The **fchdir**\ () system call causes the directory referenced by *fd*
to become the current working directory, the starting point for path
searches of pathnames not beginning with a slash, ‘/’.

In order for a directory to become the current directory, a process must
have execute (search) access to the directory.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The **chdir**\ () system call will fail and the current working
directory will be unchanged if one or more of the following are true:

[ENOTDIR]

A component of the path prefix is not a directory.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[ENOENT]

The named directory does not exist.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[EACCES]

Search permission is denied for any component of the path name.

[EFAULT]

The *path* argument points outside the process’s allocated address
space.

[EIO]

An I/O error occurred while reading from or writing to the file system.

The **fchdir**\ () system call will fail and the current working
directory will be unchanged if one or more of the following are true:

[EACCES]

Search permission is denied for the directory referenced by the file
descriptor.

[ENOTDIR]

The file descriptor does not reference a directory.

[EBADF]

The argument *fd* is not a valid file descriptor.

**SEE ALSO**

chroot(2)

**STANDARDS**

The **chdir**\ () system call is expected to conform to ISO/IEC
9945-1:1990 (‘‘POSIX.1’’).

**HISTORY**

The **chdir**\ () system call appeared in Version 1 AT&T UNIX. The
**fchdir**\ () system call appeared in 4.2BSD.

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

