--------------

CHROOT(2) BSD System Calls Manual CHROOT(2)

**NAME**

**chroot** — change root directory

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*int*

**chroot**\ (*const char *dirname*);

**DESCRIPTION**

The *dirname* argument is the address of the pathname of a directory,
terminated by an ASCII NUL. The **chroot**\ () system call causes
*dirname* to become the root directory, that is, the starting point for
path searches of pathnames beginning with ‘/’.

In order for a directory to become the root directory a process must
have execute (search) access for that directory.

It should be noted that **chroot**\ () has no effect on the process’s
current directory.

This call is restricted to the super-user.

Depending on the setting of the ‘kern.chroot_allow_open_directories’
sysctl variable, open filedescriptors which reference directories will
make the **chroot**\ () fail as follows:

If ‘kern.chroot_allow_open_directories’ is set to zero, **chroot**\ ()
will always fail with EPERM if there are any directories open.

If ‘kern.chroot_allow_open_directories’ is set to one (the default),
**chroot**\ () will fail with EPERM if there are any directories open
and the process is already subject to the **chroot**\ () system call.

Any other value for ‘kern.chroot_allow_open_directories’ will bypass the
check for open directories

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The **chroot**\ () system call will fail and the root directory will be
unchanged if:

[ENOTDIR]

A component of the path name is not a directory.

[EPERM]

The effective user ID is not the super-user, or one or more
filedescriptors are open directories.

[ENAMETOOLONG]

A component of a pathname exceeded 255 characters, or an entire path
name exceeded 1023 characters.

[ENOENT]

The named directory does not exist.

[EACCES]

Search permission is denied for any component of the path name.

[ELOOP]

Too many symbolic links were encountered in translating the pathname.

[EFAULT]

The *dirname* argument points outside the process’s allocated address
space.

[EIO]

An I/O error occurred while reading from or writing to the file system.

**SEE ALSO**

chdir(2), jail(2)

**HISTORY**

The **chroot**\ () system call appeared in 4.2BSD. It was marked as
‘‘legacy’’ in Version 2 of the Single UNIX Specification (‘‘SUSv2’’),
and was removed in subsequent standards.

**BUGS**

If the process is able to change its working directory to the target
directory, but another access control check fails (such as a check for
open directories, or a MAC check), it is possible that this system call
may return an error, with the working directory of the process left
changed.

**SECURITY CONSIDERATIONS**

The system have many hardcoded paths to files where it may load after
the process starts. It is generally recommended to drop privileges
immediately after a successful **chroot** call, and restrict write
access to a limited subtree of the **chroot** root, for instance, setup
the sandbox so that the sandboxed user will have no write access to any
well-known system directories.

BSD January 3, 2012 BSD

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

