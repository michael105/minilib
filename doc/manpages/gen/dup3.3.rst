--------------

DUP3(3) BSD Library Functions Manual DUP3(3)

**NAME**

**dup3** — duplicate an existing file descriptor

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <fcntl.h>
#include <unistd.h>**

*int*

**dup3**\ (*int oldd*, *int newd*, *int flags*);

**DESCRIPTION**

The **dup3**\ () function duplicates an existing object descriptor while
allowing the value of the new descriptor to be specified.

The close-on-exec flag on the new file descriptor is determined by the
O_CLOEXEC bit in *flags*.

If *oldd* ≠ *newd* and *flags* == 0, the behavior is identical to
dup2(oldd, newd).

If *oldd* == *newd*, then **dup3**\ () fails, unlike dup2(2).

**RETURN VALUES**

The value -1 is returned if an error occurs. The external variable
*errno* indicates the cause of the error.

**ERRORS**

The **dup3**\ () function fails if:

[EBADF]

The *oldd* argument is not a valid active descriptor or the *newd*
argument is negative or exceeds the maximum allowable descriptor number

[EINVAL]

The *oldd* argument is equal to the *newd* argument.

[EINVAL]

The *flags* argument has bits set other than O_CLOEXEC.

**SEE ALSO**

accept(2), close(2), dup2(2), fcntl(2), getdtablesize(2), open(2),
pipe(2), socket(2), socketpair(2)

**STANDARDS**

The **dup3**\ () function does not conform to any standard.

**HISTORY**

The **dup3**\ () function appeared in FreeBSD 10.0.

BSD August 16, 2013 BSD

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

