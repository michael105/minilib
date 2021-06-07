--------------

STRDUP(3) BSD Library Functions Manual STRDUP(3)

**NAME**

**strdup**, **strndup** — save a copy of a string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*char \**

**strdup**\ (*const char *str*);

*char \**

**strndup**\ (*const char *str*, *size_t len*);

**DESCRIPTION**

The **strdup**\ () function allocates sufficient memory for a copy of
the string *str*, does the copy, and returns a pointer to it. The
pointer may subsequently be used as an argument to the function free(3).

If insufficient memory is available, NULL is returned and *errno* is set
to ENOMEM.

The **strndup**\ () function copies at most *len* characters from the
string *str* always NUL terminating the copied string.

**SEE ALSO**

free(3), malloc(3), wcsdup(3)

**STANDARDS**

The **strdup**\ () function is specified by IEEE Std 1003.1-2001
(‘‘POSIX.1’’). The **strndup**\ () function is specified by IEEE Std
1003.1-2008 (‘‘POSIX.1’’).

**HISTORY**

The **strdup**\ () function first appeared in 4.4BSD. The
**strndup**\ () function was added in FreeBSD 7.2.

BSD June 6, 2018 BSD

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

