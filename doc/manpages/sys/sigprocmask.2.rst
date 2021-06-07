--------------

SIGPROCMASK(2) BSD System Calls Manual SIGPROCMASK(2)

**NAME**

**sigprocmask** — manipulate current signal mask

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <signal.h>**

*int*

**sigprocmask**\ (*int how*, *const sigset_t * restrict set*,
*sigset_t * restrict oset*);

**DESCRIPTION**

The **sigprocmask**\ () system call examines and/or changes the current
signal mask (those signals that are blocked from delivery). Signals are
blocked if they are members of the current signal mask set.

If *set* is not null, the action of **sigprocmask**\ () depends on the
value of the *how* argument. The signal mask is changed as a function of
the specified *set* and the current mask. The function is specified by
*how* using one of the following values from <*signal.h*>:

SIG_BLOCK

The new mask is the union of the current mask and the specified *set*.

SIG_UNBLOCK

The new mask is the intersection of the current mask and the complement
of the specified *set*.

SIG_SETMASK

The current mask is replaced by the specified *set*.

If *oset* is not null, it is set to the previous value of the signal
mask. When *set* is null, the value of *how* is insignificant and the
mask remains unset providing a way to examine the signal mask without
modification.

The system quietly disallows SIGKILL or SIGSTOP to be blocked.

In threaded applications, pthread_sigmask(3) must be used instead of
**sigprocmask**\ ().

**RETURN VALUES**

The **sigprocmask**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **sigprocmask**\ () system call will fail and the signal mask will
be unchanged if one of the following occurs:

[EINVAL]

The *how* argument has a value other than those listed here.

**SEE ALSO**

kill(2), sigaction(2), sigpending(2), sigsuspend(2), fpsetmask(3),
pthread_sigmask(3), sigsetops(3)

**STANDARDS**

The **sigprocmask**\ () system call is expected to conform to ISO/IEC
9945-1:1990 (‘‘POSIX.1’’).

BSD May 7, 2010 BSD

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

