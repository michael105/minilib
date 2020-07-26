--------------

SLEEP(3) BSD Library Functions Manual SLEEP(3)

**NAME**

**sleep** — suspend thread execution for an interval measured in seconds

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <unistd.h>**

*unsigned int*

**sleep**\ (*unsigned int seconds*);

**DESCRIPTION**

The **sleep**\ () function suspends execution of the calling thread
until either *seconds* seconds have elapsed or a signal is delivered to
the thread and its action is to invoke a signal-catching function or to
terminate the thread or process. System activity may lengthen the sleep
by an indeterminate amount.

This function is implemented using nanosleep(2) by pausing for *seconds*
seconds or until a signal occurs. Consequently, in this implementation,
sleeping has no effect on the state of process timers, and there is no
special handling for SIGALRM.

**RETURN VALUES**

If the **sleep**\ () function returns because the requested time has
elapsed, the value returned will be zero. If the **sleep**\ () function
returns due to the delivery of a signal, the value returned will be the
unslept amount (the requested time minus the time actually slept) in
seconds.

**SEE ALSO**

nanosleep(2), usleep(3)

**STANDARDS**

The **sleep**\ () function conforms to ISO/IEC 9945-1:1990
(‘‘POSIX.1’’).

**HISTORY**

A **sleep**\ () function appeared in Version 7 AT&T UNIX.

BSD February 13, 1998 BSD

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

