--------------

STRLEN(3) BSD Library Functions Manual STRLEN(3)

**NAME**

**strlen**, **strnlen** — find length of string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*size_t*

**strlen**\ (*const char *s*);

*size_t*

**strnlen**\ (*const char *s*, *size_t maxlen*);

**DESCRIPTION**

The **strlen**\ () function computes the length of the string *s*. The
**strnlen**\ () function attempts to compute the length of *s*, but
never scans beyond the first *maxlen* bytes of *s*.

**RETURN VALUES**

The **strlen**\ () function returns the number of characters that
precede the terminating NUL character. The **strnlen**\ () function
returns either the same result as **strlen**\ () or *maxlen*, whichever
is smaller.

**SEE ALSO**

string(3), wcslen(3), wcswidth(3)

**STANDARDS**

The **strlen**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).
The **strnlen**\ () function conforms to IEEE Std 1003.1-2008
(‘‘POSIX.1’’).

BSD February 28, 2009 BSD

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

