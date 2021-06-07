--------------

ATOL(3) BSD Library Functions Manual ATOL(3)

**NAME**

**atol**, **atoll** — convert ASCII string to *long* or *long long*
integer

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*long*

**atol**\ (*const char *nptr*);

*long long*

**atoll**\ (*const char *nptr*);

**DESCRIPTION**

The **atol**\ () function converts the initial portion of the string
pointed to by *nptr* to *long* integer representation.

It is equivalent to:

strtol(nptr, (char \**)NULL, 10);

The **atoll**\ () function converts the initial portion of the string
pointed to by *nptr* to *long long* integer representation.

It is equivalent to:

strtoll(nptr, (char \**)NULL, 10);

**COMPATIBILITY**

The FreeBSD implementations of the **atol**\ () and **atoll**\ ()
functions are thin wrappers around **strtol**\ () and **strtoll**\ ()
respectively, so these functions will affect the value of *errno* in the
same way that the **strtol**\ () and **strtoll**\ () functions are able
to. This behavior of **atol**\ () and **atoll**\ () is not required by
ISO/IEC 9899:1990 (‘‘ISO C90’’) or ISO/IEC 9899:1999 (‘‘ISO C99’’), but
it is allowed by all of ISO/IEC 9899:1990 (‘‘ISO C90’’), ISO/IEC
9899:1999 (‘‘ISO C99’’) and IEEE Std 1003.1-2001 (‘‘POSIX.1’’).

**ERRORS**

The functions **atol**\ () and **atoll**\ () may affect the value of
*errno* on an error.

**SEE ALSO**

atof(3), atoi(3), strtod(3), strtol(3), strtoul(3)

**STANDARDS**

The **atol**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).
The **atoll**\ () function conforms to ISO/IEC 9899:1999 (‘‘ISO C99’’).

BSD May 14, 2013 BSD

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

