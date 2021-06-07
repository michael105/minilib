--------------

UNGETC(3) BSD Library Functions Manual UNGETC(3)

**NAME**

**ungetc** — un-get character from input stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*int*

**ungetc**\ (*int c*, *FILE *stream*);

**DESCRIPTION**

The **ungetc**\ () function pushes the character *c* (converted to an
unsigned char) back onto the input stream pointed to by *stream*. The
pushed-back characters will be returned by subsequent reads on the
stream (in reverse order). A successful intervening call, using the same
stream, to one of the file positioning functions (fseek(3), fsetpos(3),
or rewind(3)) will discard the pushed back characters.

One character of push-back is guaranteed, but as long as there is
sufficient memory, an effectively infinite amount of pushback is
allowed.

If a character is successfully pushed-back, the end-of-file indicator
for the stream is cleared. The file-position indicator is decremented by
each successful call to **ungetc**\ (); if its value was 0 before a
call, its value is unspecified after the call.

**RETURN VALUES**

The **ungetc**\ () function returns the character pushed-back after the
conversion, or EOF if the operation fails. If the value of the argument
*c* character equals EOF, the operation will fail and the stream will
remain unchanged.

**SEE ALSO**

fseek(3), getc(3), setvbuf(3), ungetwc(3)

**STANDARDS**

The **ungetc**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

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

