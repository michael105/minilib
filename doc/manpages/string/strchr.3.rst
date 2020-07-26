--------------

STRCHR(3) BSD Library Functions Manual STRCHR(3)

**NAME**

**strchr**, **strrchr**, **strchrnul** — locate character in string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*char \**

**strchr**\ (*const char *s*, *int c*);

*char \**

**strrchr**\ (*const char *s*, *int c*);

*char \**

**strchrnul**\ (*const char *s*, *int c*);

**DESCRIPTION**

The **strchr**\ () function locates the first occurrence of *c*
(converted to a *char*) in the string pointed to by *s*. The terminating
null character is considered part of the string; therefore if *c* is
‘\0’, the functions locate the terminating ‘\0’.

The **strrchr**\ () function is identical to **strchr**\ () except it
locates the last occurrence of *c*.

The **strchrnul**\ () function is identical to **strchr**\ () except
that if *c* is not found in *s* a pointer to the terminating ‘\0’ is
returned.

**RETURN VALUES**

The functions **strchr**\ () and **strrchr**\ () return a pointer to the
located character, or NULL if the character does not appear in the
string.

**strchrnul**\ () returns a pointer to the terminating ‘\0’ if the
character does not appear in the string.

**SEE ALSO**

memchr(3), memmem(3), strcspn(3), strpbrk(3), strsep(3), strspn(3),
strstr(3), strtok(3), wcschr(3)

**STANDARDS**

The functions **strchr**\ () and **strrchr**\ () conform to ISO/IEC
9899:1990 (‘‘ISO C90’’). The function **strchrnul**\ () is a GNU
extension.

**HISTORY**

The **strchrnul**\ () function first appeared in glibc 2.1.1 and was
added in FreeBSD 10.0.

BSD February 13, 2013 BSD

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

