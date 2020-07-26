--------------

PTSNAME(3) BSD Library Functions Manual PTSNAME(3)

**NAME**

**grantpt**, **ptsname**, **unlockpt** — pseudo-terminal access
functions

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**grantpt**\ (*int fildes*);

*char \**

**ptsname**\ (*int fildes*);

*int*

**unlockpt**\ (*int fildes*);

**DESCRIPTION**

The **grantpt**\ (), **ptsname**\ (), and **unlockpt**\ () functions
allow access to pseudo-terminal devices. These three functions accept a
file descriptor that references the master half of a pseudo-terminal
pair. This file descriptor is created with posix_openpt(2).

The **grantpt**\ () function is used to establish ownership and
permissions of the slave device counterpart to the master device
specified with *fildes*. The slave device’s ownership is set to the real
user ID of the calling process, and the permissions are set to user
readable-writable and group writable. The group owner of the slave
device is also set to the group ‘‘tty’’.

The **ptsname**\ () function returns the full pathname of the slave
device counterpart to the master device specified with *fildes*. This
value can be used to subsequently open the appropriate slave after
posix_openpt(2) and **grantpt**\ () have been called.

The **unlockpt**\ () function clears the lock held on the
pseudo-terminal pair for the master device specified with *fildes*.

**RETURN VALUES**

The **grantpt**\ () and **unlockpt**\ () functions return the value 0 if
successful; otherwise the value −1 is returned and the global variable
*errno* is set to indicate the error.

The **ptsname**\ () function returns a pointer to the name of the slave
device on success; otherwise a NULL pointer is returned.

**ERRORS**

The **grantpt**\ (), **ptsname**\ () and **unlockpt**\ () functions may
fail and set *errno* to:

[EBADF]

*fildes* is not a valid open file descriptor.

[EINVAL]

*fildes* is not a master pseudo-terminal device.

In addition, the **grantpt**\ () function may set *errno* to:

[EACCES]

The slave pseudo-terminal device could not be accessed.

**SEE ALSO**

posix_openpt(2), pts(4), tty(4)

**STANDARDS**

The **ptsname**\ () function conforms to IEEE Std 1003.1-2008
(‘‘POSIX.1’’).

This implementation of **grantpt**\ () and **unlockpt**\ () does not
conform to IEEE Std 1003.1-2008 (‘‘POSIX.1’’), because it depends on
posix_openpt(2) to create the pseudo-terminal device with proper
permissions in place. It only validates whether *fildes* is a valid
pseudo-terminal master device. Future revisions of the specification
will likely allow this behaviour, as stated by the Austin Group.

**HISTORY**

The **grantpt**\ (), **ptsname**\ () and **unlockpt**\ () functions
appeared in FreeBSD 5.0.

BSD August 20, 2008 BSD

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

