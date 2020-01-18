--------------

GETCWD(3) BSD Library Functions Manual GETCWD(3)

**NAME**

**getcwd**, **getwd** — get working directory pathname

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*char \**

**getcwd**\ (*char *buf*, *size_t size*);

*char \**

**getwd**\ (*char *buf*);

**DESCRIPTION**

The **getcwd**\ () function copies the absolute pathname of the current
working directory into the memory referenced by *buf* and returns a
pointer to *buf*. The *size* argument is the size, in bytes, of the
array referenced by *buf*.

If *buf* is NULL, space is allocated as necessary to store the pathname.
This space may later be free(3)’d.

The function **getwd**\ () is a compatibility routine which calls
**getcwd**\ () with its *buf* argument and a size of MAXPATHLEN (as
defined in the include file <*sys/param.h*>). Obviously, *buf* should be
at least MAXPATHLEN bytes in length.

These routines have traditionally been used by programs to save the name
of a working directory for the purpose of returning to it. A much faster
and less error-prone method of accomplishing this is to open the current
directory (‘.’) and use the fchdir(2) function to return.

**RETURN VALUES**

Upon successful completion, a pointer to the pathname is returned.
Otherwise a NULL pointer is returned and the global variable *errno* is
set to indicate the error. In addition, **getwd**\ () copies the error
message associated with *errno* into the memory referenced by *buf*.

**ERRORS**

The **getcwd**\ () function will fail if:

[EINVAL]

The *size* argument is zero.

[ENOENT]

A component of the pathname no longer exists.

[ENOMEM]

Insufficient memory is available.

[ERANGE]

The *size* argument is greater than zero but smaller than the length of
the pathname plus 1.

The **getcwd**\ () function may fail if:

[EACCES]

Read or search permission was denied for a component of the pathname.
This is only checked in limited cases, depending on implementation
details.

**SEE ALSO**

chdir(2), fchdir(2), malloc(3), strerror(3)

**STANDARDS**

The **getcwd**\ () function conforms to ISO/IEC 9945-1:1990
(‘‘POSIX.1’’). The ability to specify a NULL pointer and have
**getcwd**\ () allocate memory as necessary is an extension.

**HISTORY**

The **getwd**\ () function appeared in 4.0BSD.

**BUGS**

The **getwd**\ () function does not do sufficient error checking and is
not able to return very long, but valid, paths. It is provided for
compatibility.

BSD April 17, 2010 BSD

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

