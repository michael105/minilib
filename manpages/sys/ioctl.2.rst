--------------

IOCTL(2) BSD System Calls Manual IOCTL(2)

**NAME**

**ioctl** — control device

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/ioctl.h>**

*int*

**ioctl**\ (*int fd*, *unsigned long request*, *...*);

**DESCRIPTION**

The **ioctl**\ () system call manipulates the underlying device
parameters of special files. In particular, many operating
characteristics of character special files (e.g. terminals) may be
controlled with **ioctl**\ () requests. The argument *fd* must be an
open file descriptor.

The third argument to **ioctl**\ () is traditionally named *char
\*argp*. Most uses of **ioctl**\ (), however, require the third argument
to be a *caddr_t* or an *int*.

An **ioctl**\ () *request* has encoded in it whether the argument is an
‘‘in’’ argument or ‘‘out’’ argument, and the size of the argument *argp*
in bytes. Macros and defines used in specifying an ioctl *request* are
located in the file <*sys/ioctl.h*>.

**GENERIC IOCTLS**

Some generic ioctls are not implemented for all types of file
descriptors. These include:

FIONREAD int

Get the number of bytes that are immediately available for reading.

FIONWRITE int

Get the number of bytes in the descriptor’s send queue. These bytes are
data which has been written to the descriptor but which are being held
by the kernel for further processing. The nature of the required
processing depends on the underlying device. For TCP sockets, these
bytes have not yet been acknowledged by the other side of the
connection.

FIONSPACE int

Get the free space in the descriptor’s send queue. This value is the
size of the send queue minus the number of bytes being held in the
queue. Note: while this value represents the number of bytes that may be
added to the queue, other resource limitations may cause a write not
larger than the send queue’s space to be blocked. One such limitation
would be a lack of network buffers for a write to a network connection.

**RETURN VALUES**

If an error has occurred, a value of -1 is returned and *errno* is set
to indicate the error.

**ERRORS**

The **ioctl**\ () system call will fail if:

[EBADF]

The *fd* argument is not a valid descriptor.

[ENOTTY]

The *fd* argument is not associated with a character special device.

[ENOTTY]

The specified request does not apply to the kind of object that the
descriptor *fd* references.

[EINVAL]

The *request* or *argp* argument is not valid.

[EFAULT]

The *argp* argument points outside the process’s allocated address
space.

**SEE ALSO**

execve(2), fcntl(2), intro(4), tty(4)

**HISTORY**

The **ioctl**\ () function appeared in Version 7 AT&T UNIX.

BSD September 11, 2013 BSD

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

