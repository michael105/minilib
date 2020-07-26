--------------

ATEXIT(3) BSD Library Functions Manual ATEXIT(3)

**NAME**

**atexit** — register a function to be called on exit

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*int*

**atexit**\ (*void (*function)(void)*);

*int*

**atexit_b**\ (*void (^function)(void)*);

**DESCRIPTION**

The **atexit**\ () function registers the given *function* to be called
at program exit, whether via exit(3) or via return from the program’s
**main**\ (). Functions so registered are called in reverse order; no
arguments are passed.

These functions must not call **exit**\ (); if it should be necessary to
terminate the process while in such a function, the \_exit(2) function
should be used. (Alternatively, the function may cause abnormal process
termination, for example by calling abort(3).)

At least 32 functions can always be registered, and more are allowed as
long as sufficient memory can be allocated.

The **atexit_b**\ () function behaves identically to **atexit**\ (),
except that it takes a block, rather than a function pointer.

**RETURN VALUES**

The **atexit**\ () function returns the value 0 if successful; otherwise
the value −1 is returned and the global variable *errno* is set to
indicate the error.

| **ERRORS**
| [ENOMEM]

No memory was available to add the function to the list. The existing
list of functions is unmodified.

[ENOSYS]

The **atexit_b**\ () function was called by a program that did not
supply a **\_Block_copy**\ () implementation.

**SEE ALSO**

at_quick_exit(3), exit(3)

**STANDARDS**

The **atexit**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).

BSD September 6, 2002 BSD

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

