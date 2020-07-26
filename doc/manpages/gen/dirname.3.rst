--------------

DIRNAME(3) BSD Library Functions Manual DIRNAME(3)

**NAME**

**dirname** — extract the directory part of a pathname

**SYNOPSIS**

**#include <libgen.h>**

*char \**

**dirname**\ (*char *path*);

**DESCRIPTION**

The **dirname**\ () function is the converse of basename(3); it returns
a pointer to the parent directory of the pathname pointed to by *path*.
Any trailing ‘/’ characters are not counted as part of the directory
name.

**IMPLEMENTATION NOTES**

This implementation of **dirname**\ () uses the buffer provided by the
caller to store the resulting parent directory. Other vendor
implementations may return a pointer to internal storage space instead.
The advantage of the former approach is that it ensures thread-safety,
while also placing no upper limit on the supported length of the
pathname.

**RETURN VALUES**

If *path* is a null pointer, the empty string, or contains no ‘/’
characters, **dirname**\ () returns a pointer to the string ".",
signifying the current directory. Otherwise, it returns a pointer to the
parent directory of *path*.

**SEE ALSO**

basename(1), dirname(1), basename(3)

**STANDARDS**

The **dirname**\ () function conforms to X/Open Portability Guide
Issue 4, Version 2 (‘‘XPG4.2’’).

**HISTORY**

The **dirname**\ () function first appeared in OpenBSD 2.2 and
FreeBSD 4.2.

In FreeBSD 12.0, this function was reimplemented to store its result in
the provided input buffer.

**AUTHORS**

Nuxi, the Netherlands

BSD September 5, 2016 BSD

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

