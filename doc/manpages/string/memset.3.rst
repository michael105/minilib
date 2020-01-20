--------------

MEMSET(3) BSD Library Functions Manual MEMSET(3)

**NAME**

**memset** — write a byte to byte string

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <string.h>**

*void \**

**memset**\ (*void *dest*, *int c*, *size_t len*);

**#define \__STDC_WANT_LIB_EXT1_\_ 1**

*errno_t*

**memset_s**\ (*void *dest*, *rsize_t destsz*, *int c*, *rsize_t len*);

**DESCRIPTION**

The **memset**\ () function writes *len* bytes of value *c* (converted
to an *unsigned char*) to the string *dest*. Undefined behaviour from
**memset**\ (), resulting from storage overflow, will occur if *len* is
greater than the the length of buffer *dest*. The behaviour is also
undefined if *dest* is an invalid pointer.

The **memset_s**\ () function behaves the same as **memset**\ () except
that an error is returned and the currently registered
runtime-constraint handler is called if *dest* is a null pointer,
*destsz* or *len* is greater than RSIZE_MAX, or *len* is greater than
*destsz* (buffer overflow would occur). The runtime-constraint handler
is called first and may not return. If it does return, an error is
returned to the caller. Like explicit_bzero(3), **memset_s**\ () is not
removed through Dead Store Elimination (DSE), making it useful for
clearing sensitive data. In contrast **memset**\ () function may be
optimized away if the object modified by the function is not accessed
again. To clear memory that will not subsequently be accessed it is
advised to use **memset_s**\ () instead of **memset**\ (). For instance,
a buffer containing a password should be cleared with **memset_s**\ ()
before free(3).

**RETURN VALUES**

The **memset**\ () function returns its first argument. The
**memset_s**\ () function returns zero on success, non-zero on error.

**SEE ALSO**

bzero(3), explicit_bzero(3), set_constraint_handler_s(3), swab(3),
wmemset(3)

**STANDARDS**

The **memset**\ () function conforms to ISO/IEC 9899:1990 (‘‘ISO C90’’).
**memset_s**\ () conforms to ISO/IEC 9899:2011 (‘‘ISO C11’’) K.3.7.4.1.

BSD August 19, 2018 BSD

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

