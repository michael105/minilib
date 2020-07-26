--------------

UTIME(3) BSD Library Functions Manual UTIME(3)

**NAME**

**utime** — set file times

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <utime.h>**

*int*

**utime**\ (*const char *file*, *const struct utimbuf *timep*);

**DESCRIPTION**

**This interface is obsoleted by** utimensat(\ **2**) **because it is
not accurate to fractions of a second.**

The **utime**\ () function sets the access and modification times of the
named file from the *actime* and *modtime* fields of the *struct
utimbuf* pointed at by *timep*.

If the times are specified (the *timep* argument is non-NULL) the caller
must be the owner of the file or be the super-user.

If the times are not specified (the *timep* argument is NULL) the caller
must be the owner of the file, have permission to write the file, or be
the super-user.

**ERRORS**

The **utime**\ () function may fail and set *errno* for any of the
errors specified for the library function utimes(2).

**SEE ALSO**

stat(2), utimensat(2), utimes(2)

**STANDARDS**

The **utime**\ () function conforms to IEEE Std 1003.1-1988
(‘‘POSIX.1’’).

**HISTORY**

A **utime**\ () function appeared in Version 7 AT&T UNIX.

BSD June 9, 2016 BSD

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

