--------------

TTYNAME(3) BSD Library Functions Manual TTYNAME(3)

**NAME**

**ttyname**, **ttyname_r**, **isatty** — get name of associated terminal
(tty) from file descriptor

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*char \**

**ttyname**\ (*int fd*);

*int*

**ttyname_r**\ (*int fd*, *char *buf*, *size_t len*);

*int*

**isatty**\ (*int fd*);

**DESCRIPTION**

These functions operate on file descriptors for terminal type devices.

The **isatty**\ () function determines if the file descriptor *fd*
refers to a valid terminal type device.

The **ttyname**\ () function gets the related device name of a file
descriptor for which **isatty**\ () is true.

The **ttyname**\ () function returns the name stored in a static buffer
which will be overwritten on subsequent calls. The **ttyname_r**\ ()
function takes a buffer and length as arguments to avoid this problem.

**RETURN VALUES**

The **isatty**\ () function returns 1 if *fd* refers to a terminal type
device; otherwise, it returns 0 and may set *errno* to indicate the
error. The **ttyname**\ () function returns the null terminated name if
the device is found and **isatty**\ () is true; otherwise a NULL pointer
is returned. The **ttyname_r**\ () function returns 0 if successful.
Otherwise an error number is returned.

**ERRORS**

These functions may fail if:

[EBADF]

The *fd* argument is not a valid file descriptor.

[ENOTTY]

The file associated with *fd* is not a terminal.

Additionally, **ttyname_r**\ () may fail if:

[ERANGE]

The *bufsize* argument is smaller than the length of the string to be
returned.

**SEE ALSO**

fdevname(3), ptsname(3), tcgetattr(3), tty(4)

**HISTORY**

The **isatty**\ () and **ttyname**\ () functions appeared in Version 7
AT&T UNIX. The **ttyname_r**\ () function appeared in FreeBSD 6.0.

BSD July 18, 2014 BSD

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

