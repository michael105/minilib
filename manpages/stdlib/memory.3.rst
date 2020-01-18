--------------

MEMORY(3) BSD Library Functions Manual MEMORY(3)

**NAME**

**malloc**, **free**, **realloc**, **calloc**, **alloca**, **mmap** —
general memory allocation operations

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*void \**

**malloc**\ (*size_t size*);

*void*

**free**\ (*void *ptr*);

*void \**

**realloc**\ (*void *ptr*, *size_t size*);

*void \**

**calloc**\ (*size_t nelem*, *size_t elsize*);

*void \**

**alloca**\ (*size_t size*);

**#include <sys/types.h>
#include <sys/mman.h>**

*void \**

**mmap**\ (*void * addr*, *size_t len*, *int prot*, *int flags*,
*int fd*, *off_t offset*);

**DESCRIPTION**

These functions allocate and free memory for the calling process. They
are described in the individual manual pages.

**SEE ALSO**

mmap(2), alloca(3), calloc(3), free(3), malloc(3), realloc(3)

**STANDARDS**

These functions, with the exception of **alloca**\ () and **mmap**\ ()
conform to ISO/IEC 9899:1990 (‘‘ISO C90’’).

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

