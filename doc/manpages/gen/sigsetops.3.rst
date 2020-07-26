--------------

SIGSETOPS(3) BSD Library Functions Manual SIGSETOPS(3)

**NAME**

**sigemptyset**, **sigfillset**, **sigaddset**, **sigdelset**,
**sigismember** — manipulate signal sets

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*int*

**sigemptyset**\ (*sigset_t *set*);

*int*

**sigfillset**\ (*sigset_t *set*);

*int*

**sigaddset**\ (*sigset_t *set*, *int signo*);

*int*

**sigdelset**\ (*sigset_t *set*, *int signo*);

*int*

**sigismember**\ (*const sigset_t *set*, *int signo*);

**DESCRIPTION**

These functions manipulate signal sets stored in a *sigset_t*. Either
**sigemptyset**\ () or **sigfillset**\ () must be called for every
object of type *sigset_t* before any other use of the object.

The **sigemptyset**\ () function initializes a signal set to be empty.

The **sigfillset**\ () function initializes a signal set to contain all
signals.

The **sigaddset**\ () function adds the specified signal *signo* to the
signal set.

The **sigdelset**\ () function deletes the specified signal *signo* from
the signal set.

The **sigismember**\ () function returns whether a specified signal
*signo* is contained in the signal set.

**RETURN VALUES**

The **sigismember**\ () function returns 1 if the signal is a member of
the set, 0 otherwise. The other functions return 0 upon success. A −1
return value indicates an error occurred and the global variable *errno*
is set to indicate the reason.

**ERRORS**

These functions could fail if one of the following occurs:

[EINVAL]

*signo* has an invalid value.

**SEE ALSO**

kill(2), sigaction(2), sigpending(2), sigprocmask(2), sigsuspend(2)

**STANDARDS**

These functions are defined by IEEE Std 1003.1-1988 (‘‘POSIX.1’’).

BSD December 16, 2004 BSD

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

