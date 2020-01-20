--------------

MPROTECT(2) BSD System Calls Manual MPROTECT(2)

**NAME**

**mprotect** — control the protection of pages

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/mman.h>**

*int*

**mprotect**\ (*void *addr*, *size_t len*, *int prot*);

**DESCRIPTION**

The **mprotect**\ () system call changes the specified pages to have
protection *prot*. Not all implementations will guarantee protection on
a page basis; the granularity of protection changes may be as large as
an entire region. A region is the virtual address space defined by the
start and end addresses of a *struct vm_map_entry*.

Currently these protection bits are known, which can be combined, OR’d
together:

PROT_NONE

No permissions at all.

PROT_READ

The pages can be read.

PROT_WRITE

The pages can be written.

PROT_EXEC

The pages can be executed.

**RETURN VALUES**

The **mprotect**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **mprotect**\ () system call will fail if:

[EINVAL]

The virtual address range specified by the *addr* and *len* arguments is
not valid.

[EACCES]

The calling process was not allowed to change the protection to the
value specified by the *prot* argument.

**SEE ALSO**

madvise(2), mincore(2), msync(2), munmap(2)

**HISTORY**

The **mprotect**\ () system call first appeared in 4.4BSD.

BSD August 3, 2016 BSD

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

