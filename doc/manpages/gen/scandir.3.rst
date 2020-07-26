--------------

SCANDIR(3) BSD Library Functions Manual SCANDIR(3)

**NAME**

**scandir**, **alphasort** — scan a directory

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <dirent.h>**

*int*

**scandir**\ (*const char *dirname*, *struct dirent ***namelist*,
*int *\ (*\*select*)(\ *const struct dirent \**),
*int *\ (*\*compar*)(\ *const struct dirent **, const struct dirent *\**));

*int*

**scandir_b**\ (*const char *dirname*, *struct dirent ***namelist*,
*int *\ (*\*select(rp*\ (*const struct dirent \**),
*int *\ (*^compar*)(\ *const struct dirent **, const struct dirent *\**));

*int*

**alphasort**\ (*const struct dirent **d1*, *const struct dirent **d2*);

**DESCRIPTION**

The **scandir**\ () function reads the directory *dirname* and builds an
array of pointers to directory entries using malloc(3). It returns the
number of entries in the array. A pointer to the array of directory
entries is stored in the location referenced by *namelist*.

The *select* argument is a pointer to a user supplied subroutine which
is called by **scandir**\ () to select which entries are to be included
in the array. The select routine is passed a pointer to a directory
entry and should return a non-zero value if the directory entry is to be
included in the array. If *select* is null, then all the directory
entries will be included.

The *compar* argument is a pointer to a user supplied subroutine which
is passed to qsort(3) to sort the completed array. If this pointer is
null, the array is not sorted.

The **alphasort**\ () function is a routine which can be used for the
*compar* argument to sort the array alphabetically using strcoll(3).

The memory allocated for the array can be deallocated with free(3), by
freeing each pointer in the array and then the array itself.

The **scandir_b**\ () function behaves in the same way as
**scandir**\ (), but takes blocks as arguments instead of function
pointers and calls **qsort_b**\ () rather than **qsort**\ ().

**DIAGNOSTICS**

Returns −1 if the directory cannot be opened for reading or if malloc(3)
cannot allocate enough memory to hold all the data structures.

**SEE ALSO**

directory(3), malloc(3), qsort(3), strcoll(3), dir(5)

**HISTORY**

The **scandir**\ () and **alphasort**\ () functions appeared in 4.2BSD.

BSD January 3, 2010 BSD

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

