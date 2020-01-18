--------------

RAND(3) BSD Library Functions Manual RAND(3)

**NAME**

**rand**, **srand**, **sranddev**, **rand_r** — bad random number
generator

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <stdlib.h>**

*void*

**srand**\ (*unsigned seed*);

*void*

**sranddev**\ (*void*);

*int*

**rand**\ (*void*);

*int*

**rand_r**\ (*unsigned *ctx*);

**DESCRIPTION**

**The functions described in this manual page are not cryptographically
secure. Cryptographic applications should use** arc4random(\ **3**)
**instead.**

These interfaces are obsoleted by random(3).

The **rand**\ () function computes a sequence of pseudo-random integers
in the range of 0 to RAND_MAX (as defined by the header file
<*stdlib.h*>).

The **srand**\ () function sets its argument *seed* as the seed for a
new sequence of pseudo-random numbers to be returned by **rand**\ ().
These sequences are repeatable by calling **srand**\ () with the same
seed value.

If no *seed* value is provided, the functions are automatically seeded
with a value of 1.

The **sranddev**\ () function initializes a seed using pseudo-random
numbers obtained from the kernel.

The **rand_r**\ () function provides the same functionality as
**rand**\ (). A pointer to the context value *ctx* must be supplied by
the caller.

For better generator quality, use random(3) or lrand48(3).

**SEE ALSO**

arc4random(3), lrand48(3), random(3), random(4)

**STANDARDS**

The **rand**\ () and **srand**\ () functions conform to ISO/IEC
9899:1990 (‘‘ISO C90’’).

The **rand_r**\ () function is as proposed in the POSIX.4a Draft #6
document.

BSD April 2, 2013 BSD

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

