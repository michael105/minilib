--------------

FERROR(3) BSD Library Functions Manual FERROR(3)

**NAME**

**clearerr**, **clearerr_unlocked**, **feof**, **feof_unlocked**,
**ferror**, **ferror_unlocked**, **fileno**, **fileno_unlocked** — check
and reset stream status

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*void*

**clearerr**\ (*FILE *stream*);

*void*

**clearerr_unlocked**\ (*FILE *stream*);

*int*

**feof**\ (*FILE *stream*);

*int*

**feof_unlocked**\ (*FILE *stream*);

*int*

**ferror**\ (*FILE *stream*);

*int*

**ferror_unlocked**\ (*FILE *stream*);

*int*

**fileno**\ (*FILE *stream*);

*int*

**fileno_unlocked**\ (*FILE *stream*);

**DESCRIPTION**

The function **clearerr**\ () clears the end-of-file and error
indicators for the stream pointed to by *stream*.

The function **feof**\ () tests the end-of-file indicator for the stream
pointed to by *stream*, returning non-zero if it is set. The end-of-file
indicator may be cleared by explicitly calling **clearerr**\ (), or as a
side-effect of other operations, e.g. **fseek**\ ().

The function **ferror**\ () tests the error indicator for the stream
pointed to by *stream*, returning non-zero if it is set.

The function **fileno**\ () examines the argument *stream* and returns
its integer descriptor.

The **clearerr_unlocked**\ (), **feof_unlocked**\ (),
**ferror_unlocked**\ (), and **fileno_unlocked**\ () functions are
equivalent to **clearerr**\ (), **feof**\ (), **ferror**\ (), and
**fileno**\ () respectively, except that the caller is responsible for
locking the stream with flockfile(3) before calling them. These
functions may be used to avoid the overhead of locking the stream and to
prevent races when multiple threads are operating on the same stream.

**ERRORS**

These functions should not fail and do not set the external variable
*errno*.

**SEE ALSO**

open(2), fdopen(3), flockfile(3), stdio(3)

**STANDARDS**

The functions **clearerr**\ (), **feof**\ (), and **ferror**\ () conform
to ISO/IEC 9899:1990 (‘‘ISO C90’’).

BSD January 28, 2009 BSD

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

