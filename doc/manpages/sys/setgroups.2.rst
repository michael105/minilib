--------------

SETGROUPS(2) BSD System Calls Manual SETGROUPS(2)

**NAME**

**setgroups** — set group access list

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/param.h>
#include <unistd.h>**

*int*

**setgroups**\ (*int ngroups*, *const gid_t *gidset*);

**DESCRIPTION**

The **setgroups**\ () system call sets the group access list of the
current user process according to the array *gidset*. The *ngroups*
argument indicates the number of entries in the array and must be no
more than {NGROUPS_MAX}+1.

Only the super-user may set a new group list.

The first entry of the group array (*gidset[0]*) is used as the
effective group-ID for the process. This entry is over-written when a
setgid program is run. To avoid losing access to the privileges of the
*gidset[0]* entry, it should be duplicated later in the group array. By
convention, this happens because the group value indicated in the
password file also appears in */etc/group*. The group value in the
password file is placed in *gidset[0]* and that value then gets added a
second time when the */etc/group* file is scanned to create the group
set.

**RETURN VALUES**

The **setgroups**\ () function returns the value 0 if successful;
otherwise the value −1 is returned and the global variable *errno* is
set to indicate the error.

**ERRORS**

The **setgroups**\ () system call will fail if:

[EPERM]

The caller is not the super-user.

[EINVAL]

The number specified in the *ngroups* argument is larger than the
{NGROUPS_MAX}+1 limit.

[EFAULT]

The address specified for *gidset* is outside the process address space.

**SEE ALSO**

getgroups(2), initgroups(3)

**HISTORY**

The **setgroups**\ () system call appeared in 4.2BSD.

BSD January 19, 2018 BSD

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

