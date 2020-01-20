--------------

STRERROR(3) BSD Library Functions Manual STRERROR(3)

**NAME**

**perror**, **strerror**, **strerror_r**, **sys_errlist**, **sys_nerr**
— system error messages

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdio.h>**

*void*

**perror**\ (*const char *string*);

*extern const char \* const sys_errlist[]*; *
extern const int sys_nerr*;

**#include <string.h>**

*char \**

**strerror**\ (*int errnum*);

*int*

**strerror_r**\ (*int errnum*, *char *strerrbuf*, *size_t buflen*);

**DESCRIPTION**

The **strerror**\ (), **strerror_r**\ () and **perror**\ () functions
look up the error message string corresponding to an error number.

The **strerror**\ () function accepts an error number argument *errnum*
and returns a pointer to the corresponding message string.

The **strerror_r**\ () function renders the same result into *strerrbuf*
for a maximum of *buflen* characters and returns 0 upon success.

The **perror**\ () function finds the error message corresponding to the
current value of the global variable *errno* (intro(2)) and writes it,
followed by a newline, to the standard error file descriptor. If the
argument *string* is non-NULL and does not point to the null character,
this string is prepended to the message string and separated from it by
a colon and space (‘‘: ’’); otherwise, only the error message string is
printed.

If the error number is not recognized, these functions return an error
message string containing ‘‘Unknown error: ’’ followed by the error
number in decimal. The **strerror**\ () and **strerror_r**\ () functions
return EINVAL as a warning. Error numbers recognized by this
implementation fall in the range 0 < *errnum* < *sys_nerr*. The number 0
is also recognized, although applications that take advantage of this
are likely to use unspecified values of *errno*.

If insufficient storage is provided in *strerrbuf* (as specified in
*buflen*) to contain the error string, **strerror_r**\ () returns ERANGE
and *strerrbuf* will contain an error message that has been truncated
and NUL terminated to fit the length specified by *buflen*.

The message strings can be accessed directly using the external array
*sys_errlist*. The external value *sys_nerr* contains a count of the
messages in *sys_errlist*. The use of these variables is deprecated;
**strerror**\ () or **strerror_r**\ () should be used instead.

**SEE ALSO**

intro(2), err(3), psignal(3)

**STANDARDS**

The **perror**\ () and **strerror**\ () functions conform to ISO/IEC
9899:1999 (‘‘ISO C99’’). The **strerror_r**\ () function conforms to
IEEE Std 1003.1-2001 (‘‘POSIX.1’’).

**HISTORY**

The **strerror**\ () and **perror**\ () functions first appeared in
4.4BSD. The **strerror_r**\ () function was implemented in FreeBSD 4.4
by Wes Peters <*wes@FreeBSD.org*>.

**BUGS**

The **strerror**\ () function returns its result in a static buffer
which will be overwritten by subsequent calls.

The return type for **strerror**\ () is missing a type-qualifier; it
should actually be *const char \**.

Programs that use the deprecated *sys_errlist* variable often fail to
compile because they declare it inconsistently.

BSD April 5, 2011 BSD

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

