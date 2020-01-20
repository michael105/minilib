--------------

FFLUSH(3) BSD Library Functions Manual FFLUSH(3)

**NAME**

**fflush**, **fpurge** — flush a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*int*

**fflush**\ (*FILE *stream*);

*int*

**fpurge**\ (*FILE *stream*);

**DESCRIPTION**

The function **fflush**\ () forces a write of all buffered data for the
given output or update *stream* via the stream’s underlying write
function. The open status of the stream is unaffected.

If the *stream* argument is NULL, **fflush**\ () flushes *all* open
output streams.

The function **fpurge**\ () erases any input or output buffered in the
given *stream*. For output streams this discards any unwritten output.
For input streams this discards any input read from the underlying
object but not yet obtained via getc(3); this includes any text pushed
back via ungetc(3).

**RETURN VALUES**

Upon successful completion 0 is returned. Otherwise, EOF is returned and
the global variable *errno* is set to indicate the error.

| **ERRORS**
| [EBADF]

The *stream* argument is not an open stream.

The function **fflush**\ () may also fail and set *errno* for any of the
errors specified for the routine write(2), except that in case of
*stream* being a read-only descriptor, **fflush**\ () returns 0.

**SEE ALSO**

write(2), fclose(3), fopen(3), setbuf(3)

**STANDARDS**

The **fflush**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

BSD December 25, 2017 BSD

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

