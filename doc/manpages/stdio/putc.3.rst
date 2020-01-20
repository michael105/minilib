--------------

PUTC(3) BSD Library Functions Manual PUTC(3)

**NAME**

**fputc**, **putc**, **putc_unlocked**, **putchar**,
**putchar_unlocked**, **putw** — output a character or word to a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*int*

**fputc**\ (*int c*, *FILE *stream*);

*int*

**putc**\ (*int c*, *FILE *stream*);

*int*

**putc_unlocked**\ (*int c*, *FILE *stream*);

*int*

**putchar**\ (*int c*);

*int*

**putchar_unlocked**\ (*int c*);

*int*

**putw**\ (*int w*, *FILE *stream*);

**DESCRIPTION**

The **fputc**\ () function writes the character *c* (converted to an
‘‘unsigned char’’) to the output stream pointed to by *stream*.

The **putc**\ () macro acts essentially identically to **fputc**\ (),
but is a macro that expands in-line. It may evaluate *stream* more than
once, so arguments given to **putc**\ () should not be expressions with
potential side effects.

The **putchar**\ () function is identical to **putc**\ () with an output
stream of stdout.

The **putw**\ () function writes the specified *int* to the named output
*stream*.

The **putc_unlocked**\ () and **putchar_unlocked**\ () functions are
equivalent to **putc**\ () and **putchar**\ () respectively, except that
the caller is responsible for locking the stream with flockfile(3)
before calling them. These functions may be used to avoid the overhead
of locking the stream for each character, and to avoid output being
interspersed from multiple threads writing to the same stream.

**RETURN VALUES**

The functions, **fputc**\ (), **putc**\ (), **putchar**\ (),
**putc_unlocked**\ () and **putchar_unlocked**\ () return the character
written. If an error occurs, the value EOF is returned. The **putw**\ ()
function returns 0 on success; EOF is returned if a write error occurs,
or if an attempt is made to write a read-only stream.

**SEE ALSO**

ferror(3), flockfile(3), fopen(3), getc(3), putwc(3), stdio(3)

**STANDARDS**

The functions **fputc**\ (), **putc**\ (), and **putchar**\ (), conform
to ISO/IEC 9899:1990 (‘‘ISO C90’’). The **putc_unlocked**\ () and
**putchar_unlocked**\ () functions conform to IEEE Std 1003.1-2001
(‘‘POSIX.1’’). A function **putw**\ () function appeared in Version 6
AT&T UNIX.

**BUGS**

The size and byte order of an *int* varies from one machine to another,
and **putw**\ () is not recommended for portable applications.

BSD January 10, 2003 BSD

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

