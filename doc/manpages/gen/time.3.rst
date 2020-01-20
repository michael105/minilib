--------------

TIME(3) BSD Library Functions Manual TIME(3)

**NAME**

**time** — get time of day

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <time.h>**

*time_t*

**time**\ (*time_t *tloc*);

**DESCRIPTION**

The **time**\ () function returns the value of time in seconds since 0
hours, 0 minutes, 0 seconds, January 1, 1970, Coordinated Universal
Time. If an error occurs, **time**\ () returns the value (

*time_t* )−1.

The return value is also stored in \*\ *tloc*, provided that *tloc* is
non-null.

**ERRORS**

The **time**\ () function may fail for any of the reasons described in
gettimeofday(2).

**SEE ALSO**

clock_gettime(2), gettimeofday(2), ctime(3)

**STANDARDS**

The **time** function conforms to IEEE Std 1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

A **time**\ () function appeared in Version 6 AT&T UNIX.

**BUGS**

Neither ISO/IEC 9899:1999 (‘‘ISO C99’’) nor IEEE Std 1003.1-2001
(‘‘POSIX.1’’) requires **time**\ () to set *errno* on failure; thus, it
is impossible for an application to distinguish the valid time value −1
(representing the last UTC second of 1969) from the error return value.

Systems conforming to earlier versions of the C and POSIX standards
(including older versions of FreeBSD) did not set \*\ *tloc* in the
error case.

BSD July 18, 2003 BSD

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

