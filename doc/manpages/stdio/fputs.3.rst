--------------

FPUTS(3) BSD Library Functions Manual FPUTS(3)

**NAME**

**fputs**, **puts** — output a line to a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*int*

**fputs**\ (*const char *str*, *FILE *stream*);

*int*

**puts**\ (*const char *str*);

**DESCRIPTION**

The function **fputs**\ () writes the string pointed to by *str* to the
stream pointed to by *stream*.

The function **puts**\ () writes the string *str*, and a terminating
newline character, to the stream stdout.

**RETURN VALUES**

The functions **fputs**\ () and **puts**\ () return a nonnegative
integer on success and EOF on error.

| **ERRORS**
| [EBADF]

The *stream* argument is not a writable stream.

The functions **fputs**\ () and **puts**\ () may also fail and set
*errno* for any of the errors specified for the routines write(2).

**SEE ALSO**

ferror(3), fputws(3), putc(3), stdio(3)

**STANDARDS**

The functions **fputs**\ () and **puts**\ () conform to ISO/IEC
9899:1990 (‘‘ISO C90’’).

BSD June 4, 1993 BSD

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

