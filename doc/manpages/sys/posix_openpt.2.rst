--------------

POSIX_OPENPT(2) BSD System Calls Manual POSIX_OPENPT(2)

**NAME**

**posix_openpt** — open a pseudo-terminal device

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <fcntl.h>
#include <stdlib.h>**

*int*

**posix_openpt**\ (*int oflag*);

**DESCRIPTION**

The **posix_openpt**\ () function allocates a new pseudo-terminal and
establishes a connection with its master device. A slave device shall be
created in */dev/pts*. After the pseudo-terminal has been allocated, the
slave device should have the proper permissions before it can be used
(see grantpt(3)). The name of the slave device can be determined by
calling ptsname(3).

The file status flags and file access modes of the open file description
shall be set according to the value of *oflag*. Values for *oflag* are
constructed by a bitwise-inclusive OR of flags from the following list,
defined in <*fcntl.h*>:

O_RDWR

Open for reading and writing.

O_NOCTTY

If set **posix_openpt**\ () shall not cause the terminal device to
become the controlling terminal for the process.

O_CLOEXEC

Set the close-on-exec flag for the new file descriptor.

The **posix_openpt**\ () function shall fail when *oflag* contains other
values.

**RETURN VALUES**

Upon successful completion, the **posix_openpt**\ () function shall
allocate a new pseudo-terminal device and return a non-negative integer
representing a file descriptor, which is connected to its master device.
Otherwise, -1 shall be returned and errno set to indicate the error.

**ERRORS**

The **posix_openpt**\ () function shall fail if:

[ENFILE]

The system file table is full.

[EINVAL]

The value of *oflag* is not valid.

[EAGAIN]

Out of pseudo-terminal resources.

**SEE ALSO**

ptsname(3), pts(4), tty(4)

**STANDARDS**

The **posix_openpt**\ () function conforms to IEEE Std 1003.1-2001
(‘‘POSIX.1’’). The ability to use O_CLOEXEC is an extension to the
standard.

**HISTORY**

The **posix_openpt**\ () function appeared in FreeBSD 5.0. In
FreeBSD 8.0, this function was changed to a system call.

**NOTES**

The flag O_NOCTTY is included for compatibility; in FreeBSD, opening a
terminal does not cause it to become a process’s controlling terminal.

**AUTHORS**

Ed Schouten <*ed@FreeBSD.org*>

BSD September 21, 2016 BSD

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

