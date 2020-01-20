--------------

BASENAME(3) BSD Library Functions Manual BASENAME(3)

**NAME**

**basename** — extract the base portion of a pathname

**SYNOPSIS**

**#include <libgen.h>**

*char \**

**basename**\ (*char *path*);

**DESCRIPTION**

The **basename**\ () function returns the last component from the
pathname pointed to by *path*, deleting any trailing ‘/’ characters.

**IMPLEMENTATION NOTES**

This implementation of **basename**\ () uses the buffer provided by the
caller to store the resulting pathname component. Other vendor
implementations may return a pointer to internal storage space instead.
The advantage of the former approach is that it ensures thread-safety,
while also placing no upper limit on the supported length of the
pathname.

**RETURN VALUES**

If *path* consists entirely of ‘/’ characters, a pointer to the string
"/" is returned. If *path* is a null pointer or the empty string, a
pointer to the string "." is returned. Otherwise, it returns a pointer
to the last component of *path*.

**SEE ALSO**

basename(1), dirname(1), dirname(3)

**STANDARDS**

The **basename**\ () function conforms to X/Open Portability Guide
Issue 4, Version 2 (‘‘XPG4.2’’).

**HISTORY**

The **basename**\ () function first appeared in OpenBSD 2.2 and
FreeBSD 4.2.

In FreeBSD 12.0, this function was reimplemented to store its result in
the provided input buffer. There is no longer any need to use the
**basename_r**\ () function.

**AUTHORS**

Nuxi, the Netherlands

BSD May 22, 2017 BSD

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

