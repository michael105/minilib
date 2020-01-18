--------------

FCLOSE(3) BSD Library Functions Manual FCLOSE(3)

**NAME**

**fclose**, **fdclose**, **fcloseall** — close a stream

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*int*

**fclose**\ (*FILE *stream*);

*int*

**fdclose**\ (*FILE *stream*, *int *fdp*);

*void*

**fcloseall**\ (*void*);

**DESCRIPTION**

The **fclose**\ () function dissociates the named *stream* from its
underlying file or set of functions. If the stream was being used for
output, any buffered data is written first, using fflush(3).

The **fdclose**\ () function is equivalent to **fclose**\ () except that
it does not close the underlying file descriptor. If *fdp* is not NULL,
the file descriptor will be written to it. If the *fdp* argument will be
different then NULL the file descriptor will be returned in it, If the
stream does not have an associated file descriptor, *fdp* will be set to
-1. This type of stream is created with functions such as fmemopen(3),
funopen(3), or open_memstream(3).

The **fcloseall**\ () function calls **fclose**\ () on all open streams.

**RETURN VALUES**

**fcloseall**\ () does not return a value.

Upon successful completion the **fclose**\ () and **fdclose**\ ()
functions return 0. Otherwise, EOF is returned and the global variable
*errno* is set to indicate the error.

**ERRORS**

**fdclose**\ () fails if:

[EOPNOTSUPP]

The stream does not have an associated file descriptor.

The **fclose**\ () and **fdclose**\ () functions may also fail and set
*errno* for any of the errors specified for fflush(3).

The **fclose**\ () function may also fail and set errno for any of the
errors specified for close(2).

**NOTES**

The **fclose**\ () and **fdclose**\ () functions do not handle NULL
arguments in the *stream* variable; this will result in a segmentation
violation. This is intentional. It makes it easier to make sure programs
written under FreeBSD are bug free. This behaviour is an implementation
detail, and programs should not rely upon it.

**SEE ALSO**

close(2), fflush(3), fopen(3), setbuf(3)

**STANDARDS**

The **fclose**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

**HISTORY**

The **fcloseall**\ () function first appeared in FreeBSD 7.0.

The **fdclose**\ () function first appeared in FreeBSD 11.0.

BSD July 4, 2015 BSD

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

