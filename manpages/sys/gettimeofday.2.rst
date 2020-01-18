--------------

GETTIMEOFDAY(2) BSD System Calls Manual GETTIMEOFDAY(2)

**NAME**

**gettimeofday**, **settimeofday** — get/set date and time

**LIBRARY**

Standard C Library (libc, −lc)

**SYNOPSIS**

**#include <sys/time.h>**

*int*

**gettimeofday**\ (*struct timeval *tp*, *struct timezone *tzp*);

*int*

**settimeofday**\ (*const struct timeval *tp*,
*const struct timezone *tzp*);

**DESCRIPTION**

The system’s notion of the current Greenwich time and the current time
zone is obtained with the **gettimeofday**\ () system call, and set with
the **settimeofday**\ () system call. The time is expressed in seconds
and microseconds since midnight (0 hour), January 1, 1970. The
resolution of the system clock is hardware dependent, and the time may
be updated continuously or in ‘‘ticks’’. If *tp* or *tzp* is NULL, the
associated time information will not be returned or set.

The structures pointed to by *tp* and *tzp* are defined in
<*sys/time.h*> as:

struct timeval {

+---------+---------+---------+---------+---------+---------+---------+
|         | time_t  |         | tv_sec; |         | /\*     |         |
|         |         |         |         |         | seconds |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+
|         | susecon |         | tv_usec |         | /\* and |         |
|         | ds_t    |         | ;       |         | microse |         |
|         |         |         |         |         | conds   |         |
|         |         |         |         |         | \*/     |         |
+---------+---------+---------+---------+---------+---------+---------+

};

struct timezone {

+-----------+-----------+-----------+-----------+-----------+-----------+
|           | int       | tz_minute |           |           |           |
|           |           | swest;    |           |           |           |
|           |           | /\*       |           |           |           |
|           |           | minutes   |           |           |           |
|           |           | west of   |           |           |           |
|           |           | Greenwich |           |           |           |
|           |           | \*/       |           |           |           |
+-----------+-----------+-----------+-----------+-----------+-----------+
|           | int       | tz_dsttim |           | /\* type  |           |
|           |           | e;        |           | of dst    |           |
|           |           |           |           | correctio |           |
|           |           |           |           | n         |           |
|           |           |           |           | \*/       |           |
+-----------+-----------+-----------+-----------+-----------+-----------+

};

The *timezone* structure indicates the local time zone (measured in
minutes of time westward from Greenwich), and a flag that, if nonzero,
indicates that Daylight Saving time applies locally during the
appropriate part of the year. The kernel generally does not track these
values and they are usually returned as zero. Use localtime(3) to find
the offset for the currently active timezone.

Only the super-user may set the time of day or time zone. If the system
is running at securelevel >= 2 (see init(8)), the time may only be
advanced or retarded by a maximum of one second. This limitation is
imposed to prevent a malicious super-user from setting arbitrary time
stamps on files. The system time can be adjusted backwards without
restriction using the adjtime(2) system call even when the system is
secure.

**RETURN VALUES**

Upon successful completion, the value 0 is returned; otherwise the
value −1 is returned and the global variable *errno* is set to indicate
the error.

**ERRORS**

The following error codes may be set in *errno*:

[EINVAL]

The supplied *timeval* value is invalid.

[EPERM]

A user other than the super-user attempted to set the time.

**SEE ALSO**

date(1), adjtime(2), clock_gettime(2), ctime(3), timeradd(3), clocks(7),
timed(8)

**HISTORY**

The **gettimeofday**\ () system call appeared in 4.2BSD.

BSD October 27, 2018 BSD

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

