--------------

UNAME(3) BSD Library Functions Manual UNAME(3)

**NAME**

**uname** — get system identification

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/utsname.h>**

*int*

**uname**\ (*struct utsname *name*);

**DESCRIPTION**

The **uname**\ () function stores NUL-terminated strings of information
identifying the current system into the structure referenced by *name*.

The *utsname* structure is defined in the <*sys/utsname.h*> header file,
and contains the following members:

sysname

Name of the operating system implementation.

nodename

Network name of this machine.

release

Release level of the operating system.

version

Version level of the operating system.

machine

Machine hardware platform.

**RETURN VALUES**

The **uname**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

| **ENVIRONMENT**
| UNAME_s

If the environment variable UNAME_s is set, it will override the
*sysname* member.

UNAME_r

If the environment variable UNAME_r is set, it will override the
*release* member.

UNAME_v

If the environment variable UNAME_v is set, it will override the
*version* member.

UNAME_m

If the environment variable UNAME_m is set, it will override the
*machine* member.

**ERRORS**

The **uname**\ () function may fail and set *errno* for any of the
errors specified for the library functions sysctl(3).

**SEE ALSO**

uname(1), sysctl(3)

**STANDARDS**

The **uname**\ () function conforms to IEEE Std 1003.1-1988
(‘‘POSIX.1’’).

**HISTORY**

The **uname**\ () function first appeared in 4.4BSD.

BSD December 2, 2005 BSD

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

